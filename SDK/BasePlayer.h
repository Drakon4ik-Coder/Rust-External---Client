#pragma once
#include <xmmintrin.h>
#include <emmintrin.h>
#include "..\SpinBot.h"
#include "xorstr.h"
unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

unsigned RANDOMVECTOR()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}



enum BonesList : int
{
	r_foot1 = 3,
	l_knee1 = 2,
	l_hip1 = 1,
	pelvis1 = 6,
	l_foot1 = 15,
	r_knee1 = 14,
	r_hip1 = 13,
	spine11 = 18,
	neck1 = 46,
	head1 = 47,
	l_upperarm1 = 24,
	l_forearm1 = 25,
	l_hand1 = 26,
	r_upperarm1 = 55,
	r_forearm1 = 56,
	r_hand1 = 57
};

enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};

typedef struct Str
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *str;

enum PlayerFlags : int
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
	DebugCamera = 260
};
namespace Mounted {
	static enum Flags1 : int
	{
		Ducked = 1,
		Jumped = 2,
		OnGround = 4,
		Sprinting = 16,
		OnLadder = 32,
		Flying = 64,
		Prone = 256,
		Mounted = 512,
		OnPhone = 2048,
		Crawling = 4096
	};
}
class BasePlayer
{
public:
	std::string playername;
	std::string prefabname;
	uintptr_t transform;
	int networkid;
	uintptr_t baseentity;
	uintptr_t PlayerWalkMovement;
	uintptr_t Items;
	int playerflags;
	uintptr_t input;
	Vector3 position;
	BaseProjectile* weapon;
	/*Player Info*/

	UINT_PTR GetName() {
		auto player_name = safe_read((uintptr_t)this + oPlayerName, UINT_PTR);
		return player_name;
	}

	UINT64 SteamID()
	{
		return safe_read((const uintptr_t)(const uintptr_t)this + oSteamID, UINT64);
	}

	float __fastcall Health()
	{
		auto health = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerHealth, float);
		return health;
	}

	bool __fastcall Flags(int Flg)
	{
		return safe_read((const uintptr_t)(const uintptr_t)this + oPlayerFlags, int) & Flg;
	}






	bool __fastcall Dead()
	{
		if (!(const uintptr_t)this) return true;
		return safe_read((const uintptr_t)(const uintptr_t)this + oLifestate, bool);
	}

	bool __fastcall IsNpcss()
	{
		if (!(const uintptr_t)this) return true;
		auto PlayerModel = Driver.Read<uintptr_t>((const uintptr_t)(const uintptr_t)this + oPlayerModel); //	public PlayerModel playerModel;
		return Driver.Read<bool>(PlayerModel + 0x2C8);//private bool <IsNpc>k__BackingField; // 0x320
	}



	bool IsValid(bool LPlayer = false)
	{
		//std::cout << "ISvalid " <<Flags(16) << "  " << Dead() << " " << Health() << std::endl;
		if (!this) return false;
		float health = Health();
		UINT64 steam = SteamID();
		auto steamx = steam;
		//std::cout << health << " " << steam;
		if (health > 150.f || health < 0.8f) return false;


		int nums = 0;
		do {
			nums++;
			steam /= 10;
		} while (steam > 0);
		if (nums != 7 /*bot*/ && nums != 17 /*player*/) return false;
		/*if (nums == 8)
		{
			std::cout << "Bot found " << steamx <<std::endl;
		}
		else if (nums == 17)
		{
			std::cout << "Player found " << steamx << std::endl;
		}*/
		return (((LPlayer || Value::bools::Visuals::ESP::IgnoreSleeper) ? !Flags(16) : true) && !Dead());
	}


	/*Vector*/

	Vector2 __fastcall GVA()
	{
		UINT64 Input = safe_read((const uintptr_t)this + oPlayerInput, UINT64);
		return safe_read(Input + oBodyAngles, Vector2);
	}

	Vector2 __fastcall GetRA() {
		UINT64 Input = Driver.Read<UINT64>((const uintptr_t)this + oPlayerInput);
		return Driver.Read<Vector2>(Input + 0x64);
	}


	void setGrounded(float grounded)
	{
		return Driver.Write<float>((const uintptr_t)this + 0x4C, grounded);
	}



	Vector3 GVelocity()
	{
		UINT64 PlayerModel = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
		return safe_read(PlayerModel + 0x1DC, Vector3); // 	private Vector3 newVelocity;

	}

	Vector3 __fastcall GBoneByID2(BoneList BoneID) {
		return GetBone(GetTransform(BoneID));//GetBone
	}

	Vector3 __fastcall GBoneByID21(BonesList BoneID) {
		return GetBone(GetTransform(BoneID));//GetBone
	}

	Vector3 __fastcall GetBoneByID()
	{
		return GetBone(GetTransform(BoneList(neck)));
	}

	bool __fastcall IsVisible() {
		if (Value::bools::Aim::VisibleCheck) {
			UINT64 PlayerModel = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
			return safe_read(PlayerModel + oVisible, bool);
		}
		else return true;
	}


	void __fastcall PatchDebug()
	{
		auto klass = Driver.Read<uintptr_t>(game_assembly + oDebugfix);
		auto static_fields = Driver.Read<uintptr_t>(klass + 0xB8);
		Driver.Write<float>(static_fields + oCamspeed, 1.f); // camspeed
		Driver.Write<float>(static_fields + oCamlerp, 1.f); // camlerp
	}



	void __fastcall SetVA(const Vector2& VA)
	{
		UINT64 Input = safe_read((const uintptr_t)this + oPlayerInput, UINT64);
		safe_write(Input + oBodyAngles, VA, Vector2);
	}

	void __fastcall FakeAdmin()
	{
		UINT64 Movement = safe_read((const uintptr_t)this + oPlayerMovement, UINT64);
		int Flags = safe_read((const uintptr_t)this + oPlayerFlags, int);
		safe_write((const uintptr_t)this + oPlayerFlags, (Flags |= 4), int);

	}

	void __fastcall thirdperson()
	{
		int Flags = Driver.Read<int>((const uintptr_t)this + oPlayerFlags);
		Driver.Write<int>((const uintptr_t)this + oPlayerFlags, (Flags |= ThirdPersonViewmode));
	}



	void __fastcall NoBlockAiming()
	{
		safe_write((const uintptr_t)this + oClothingBlocksAiming, false, bool);
		safe_write((const uintptr_t)this + 0x764, false, bool);
	}


	void __fastcall InfinityJump()
	{
		auto PlayerWalkMovement = safe_read((const uintptr_t)this + oPlayerMovement, uintptr_t);
		safe_write(PlayerWalkMovement + oJumpTime, 0, float); //private float jumpTime;
		safe_write(PlayerWalkMovement + oLandTime, 0, float); //private float landTime;
		safe_write(PlayerWalkMovement + oGroundTime, 10000, float); //private float groundTime;
	}




	void __fastcall GravituMod()
	{
		UINT64 Movement = safe_read((const uintptr_t)this + oPlayerMovement, UINT64);
		float Gravity = 2.5f;
		if (GetKeyState(VK_MBUTTON))
		{
			safe_write(Movement + oGravityMultiplier, Gravity / Value::floats::Player::Gravity, float);
		}
		else
		{
			safe_write(Movement + oGravityMultiplier, Gravity, float);
		}
	}

	void __fastcall SetFov()
	{
		auto Class = safe_read(game_assembly + oConVar, DWORD64);
		auto Field = safe_read(Class + 0xB8, DWORD64);
		safe_write(Field + 0x18, Value::floats::Player::CustomFov, float);


	}
	void __fastcall WalkWater()
	{

		UINT64 modelState = safe_read((const uintptr_t)(const uintptr_t)this + oModelState, UINT64); // public ModelState modelState;
		UINT64 playerMovement = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerMovement, UINT64); // public BaseMovement movement;

		static bool x130 = safe_read(playerMovement + oGrounded, bool);
		static float xB8 = safe_read(playerMovement + oGroundAngleNew, float);
		static float x74 = safe_read(playerMovement + oGravityMultiplier, float);
		static float x78 = safe_read(playerMovement + oGravityMultiplierSwimming, float);
		DWORD64 model = safe_read(oPlayerModel, DWORD64);
		int onLoader = safe_read(modelState + 0x2C, int);
		if (GBoneByID2(l_foot).y <= 1.0f)
		{
			safe_write(playerMovement + oGrounded, true, bool);
			safe_write(playerMovement + oGroundAngleNew, 0.f, float);
			safe_write(playerMovement + oGravityMultiplier, 0.f, float);
			safe_write(playerMovement + oGravityMultiplierSwimming, 0.f, float);
		}
		else
		{
			safe_write(playerMovement + oGrounded, x130, bool);
			safe_write(playerMovement + oGroundAngleNew, xB8, float);
			safe_write(playerMovement + oGravityMultiplier, x74, float);
			safe_write(playerMovement + oGravityMultiplierSwimming, x78, float);
		}



	}



	void __fastcall Chams()
	{
		if (Value::bools::Misc::chams) {
			auto player_model = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerModel, UINT64);
			auto player_skin_type = Driver.Read<uintptr_t>(player_model + oSkinType);
			auto player_skin_component = Driver.Read<uintptr_t>(player_model + 0x360 + ((int)player_skin_type * 0x8));
			auto skin = Driver.Read<uintptr_t>(player_skin_component + 0x18);
			auto skin_sz = Driver.Read<uintptr_t>(skin + 0x18);

			for (int i = NULL; i <= (int)skin_sz; i++)
			{
				auto current_skin = Driver.Read<uintptr_t>(skin + 0x20 + (i * 0x8));

				Driver.Write<uintptr_t>(current_skin + 0x68, NULL);
				Driver.Write<uintptr_t>(current_skin + 0x70, NULL);
				Driver.Write<uintptr_t>(current_skin + 0x78, NULL);
			}


			auto SKY_C = Driver.Read<uintptr_t>(game_assembly + oTOD_Sky_c); // TOD_Sky_TypeInfo
			auto SKYINSTANCE = Driver.Read<uintptr_t>(SKY_C + 0xB8);
			auto SKYINSTANCELIST = Driver.Read<uintptr_t>(SKYINSTANCE + 0x0);
			auto INSTANCES = Driver.Read<uintptr_t>(SKYINSTANCELIST + 0x10);
			auto Dome = Driver.Read<uintptr_t>(INSTANCES + 0x20);

			auto skin_set = Driver.Read<uintptr_t>(player_model + oSkinSetCollection + ((int)player_skin_type * 0x8));

			if (skin_set != NULL)
			{
				auto skins = Driver.Read<uintptr_t>(skin_set + 0x18);



				auto skins_sz = Driver.Read<int32_t>(skins + 0x18);



				for (int itr = NULL; itr <= skins_sz; itr++)
				{
					auto skin = Driver.Read<uintptr_t>(skins + 0x20 + (itr * 0x8));
					if (!skin)
						continue;

					auto components = Driver.Read<uintptr_t>(Dome + 0xA8); // private TOD_Components <Components>k__BackingField;
					if (!components)
						continue;

					auto scattering = Driver.Read<uintptr_t>(components + 0x1A0); // private TOD_Scattering <Scattering>k__BackingField;
					if (!scattering)
						continue;

					auto material = Driver.Read<uintptr_t>(scattering + 0x78); // private Material scatteringMaterial;
					if (!material)
						continue;

					// class SkinSet 
					Driver.Write<uintptr_t>(skin + 0x68, material); // public Material HeadMaterial;	
					Driver.Write<uintptr_t>(skin + 0x70, material); // public Material BodyMaterial;
					Driver.Write<uintptr_t>(skin + 0x78, material); // public Material EyeMaterial;
				}
			}
		}
	}



	void SpinBot()
	{
		auto aPlayerInput = Driver.Read<uintptr_t>((const uintptr_t)this + oPlayerInput);
		Driver.Write<SpinBot::Vector4>(aPlayerInput + bodyRotation, SpinBot::Vector4(16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput + bodyRotation, SpinBot::Vector4(-16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		auto aPlayerInput1 = Driver.Read<uintptr_t>((const uintptr_t)this + oPlayerInput);
		Driver.Write<SpinBot::Vector4>(aPlayerInput1 + headRotation, SpinBot::Vector4(-5.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput1 + headRotation, SpinBot::Vector4(22.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput + bodyRotation, SpinBot::Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput + bodyRotation, SpinBot::Vector4(60.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput + headRotation, SpinBot::Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		Driver.Write<SpinBot::Vector4>(aPlayerInput + headRotation, SpinBot::Vector4(30.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
	}

	void __fastcall MinicopterShooting() {
		if (Value::bools::Player::PlayerWalk::MinicopterFire) {
			UINT64 Mounted = Driver.Read<UINT64>((const uintptr_t)this + 0x648);
			Driver.Write<bool>(Mounted + 0x2B8, true);
		}
		else {
			UINT64 Mounted = Driver.Read<UINT64>((const uintptr_t)this + 0x648);
			Driver.Write<bool>(Mounted + 0x2B8, false);
		}

	}

	void disallow_server_commands()
	{
		/*for (int x = 0; x < 500; x++)
		{
			auto ConsoleSystemCommand5 = Driver.Read<uintptr_t>(game_assembly + 48899056);
			auto ConsoleSystemCommand2 = Driver.Read<uintptr_t>(ConsoleSystemCommand5 + 0xB8);
			uintptr_t ConsoleSystemCommands = Driver.Read<uintptr_t>(48899056 + 0x10);
			if (!ConsoleSystemCommands) return;
			uintptr_t ConsoleSystemCommand = Driver.Read<uintptr_t>(ConsoleSystemCommands + 0x20 + (x * 0x8));
			if (!ConsoleSystemCommand) continue;

			uintptr_t Name = Driver.Read<uintptr_t>(ConsoleSystemCommand + 0x10);
			if (!Name) continue;

			wchar_t command_name[36] = { '\0' };
			Driver.ReadArr(Name + 0x14, &command_name, sizeof(command_name));

			if (!wcscmp(command_name, L"noclip"))
			{
				Driver.Write<bool>(ConsoleSystemCommand + 0x57, 0);
			}
		}*/
	}

	void ShootinJump()
	{
		UINT64 modelState = safe_read((const uintptr_t)(const uintptr_t)this + oModelState, UINT64); // public ModelState modelState;
		UINT64 playerMovement = safe_read((const uintptr_t)(const uintptr_t)this + oPlayerMovement, UINT64); // public BaseMovement movement;
		auto mov_flag = Driver.Read<uintptr_t>(playerMovement + oModelState);
		Driver.Write<uintptr_t>(mov_flag, oFlagOnGround);
		Driver.Write<float>(playerMovement + oGroundAngle, 1.f);
		Driver.Write<float>(playerMovement + oGroundAngleNew, 1.f);
	}




	void AntiFlash()
	{
		uintptr_t flash_instance = ReadChain<uint64_t>(game_assembly, { 49828904 , 0xB8 , 0x0 }); //FlashbangOverlay_c*
		Driver.Write<float>(flash_instance + 0x40, 0.f); //flashlength

	}

	void FakeLag()
	{
		Driver.Write<float>((const uintptr_t)this + 0x6AC, 0.8f); // public float serverTickInterval; // 0x658
		Driver.Write<float>((const uintptr_t)this + 0x6B0, 0.5f); // public float clientTickInterval; // 0x658
	}

	void __fastcall LongNeck() {
		UINT64 eyes = Driver.Read<UINT64>((const uintptr_t)this + oPlayerEyes); // public PlayerEyes eyes;
		if (GetAsyncKeyState(Value::floats::Player::LongNeckKey)) {
			Driver.Write<Vector3>(eyes + 0x38, Vector3(0, 1.58f, 0));
		}
		if (GetAsyncKeyState(Value::floats::Player::Left)) {
			Driver.Write<Vector3>(eyes + 0x38, Vector3(-1.58, 0, 0));
		}
		if (GetAsyncKeyState(Value::floats::Player::Right)) {
			Driver.Write<Vector3>(eyes + 0x38, Vector3(1.58, 0, 0));
		}
	}

	void Timer()
	{

		auto time = Driver.Read<uintptr_t>(unity_player + 0x17C1CD0 + 7 * 8);
		if (time) {
			if (GetAsyncKeyState(Value::floats::Player::hangingg))
			{
				Driver.Write<float>(time + 0xFC, Value::floats::Player::timervalue);
			}
			else {
				Driver.Write<float>(time + 0xFC, 1.f);
			}
		}

	}

	void __fastcall DebugCamera()
	{
		UINT64 eyes = Driver.Read<UINT64>((const uintptr_t)this + oPlayerEyes); // public PlayerEyes eyes;
		Driver.Write<Vector3>(eyes + 0x38, Vector3(Value::NeckWeigth, Value::NeckLength, Value::NeckWidgth));

		if (GetAsyncKeyState(VK_PRIOR) & 1)
		{
			Value::NeckLength++;
		}
		if (GetAsyncKeyState(VK_NEXT) & 1)
		{
			Value::NeckLength--;
		}

		if (GetAsyncKeyState(VK_LEFT) & 1)
		{
			Value::NeckWeigth--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 1)
		{
			Value::NeckWeigth++;
		}
		if (GetAsyncKeyState(VK_UP) & 1)
		{
			Value::NeckWidgth++;
		}
		if (GetAsyncKeyState(VK_DOWN) & 1)
		{
			Value::NeckWidgth--;
		}
		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			Value::NeckLength = 0.f;
			Value::NeckWeigth = 0.f;
			Value::NeckWidgth = 0.f;
		}

	}


	void __fastcall FlyHack() {

		UINT64 Movement = Driver.Read<UINT64>((const uintptr_t)this + oMovement);//public BaseMovement movement;
		if (GetAsyncKeyState(FlyHackButon))
		{
			Driver.Write<float>(Movement + groundAngle, gravityFly);//groundAngle
			Driver.Write<float>(Movement + groundAngleNew, gravityFly);//groundAngleNew
			Driver.Write<float>(Movement + oGravityMultiplier, gravityFly);//gravityMultiplier

		}
		else
		{
			if (Driver.Read<float>(Movement + oGravityMultiplier) != 2.5f) {
				Driver.Write<float>(Movement + oGravityMultiplier, 2.5f);//gravityMultiplier
			}
		}

	}


	void __fastcall KillHack() {
		UINT64 Movement = Driver.Read<UINT64>((const uintptr_t)this + oMovement);//public BaseMovement movement; // 0x4F8 #define oMovement 0x4F8
		Driver.Write<bool>(Movement + oWasFalling, true);//private bool wasFalling; // 0x148 #define oWasFalling 0x148
		Driver.Write<Vector3>(Movement + oPreviousVelocity, Vector3(0, -20, 0));//private Vector3 previousVelocity; // 0xE4 #define oPreviousVelocity 0xE4
		Driver.Write<float>(Movement + oGroundTime, 0.f);//private float groundTime; // 0xCC #define oGroundTime 0xCC

	}


	void __fastcall Zoom()
	{
		if (GetAsyncKeyState(Value::floats::Player::zoomKey))//0x5A
		{

			auto klass = safe_read(game_assembly + oConVar, DWORD64);
			auto static_fields = safe_read(klass + 0xB8, DWORD64);
			safe_write(static_fields + 0x18, Value::floats::Player::Zoomvalue, float);
		}
		else
		{
			auto klass = safe_read(game_assembly + oConVar, DWORD64);
			auto static_fields = safe_read(klass + 0xB8, DWORD64);
			safe_write(static_fields + 0x18, Value::floats::Player::CustomFov, float);
		}
	}



	void __fastcall SpiderMan()
	{
		UINT64 Movement = safe_read((const uintptr_t)this + oPlayerMovement, UINT64);
		safe_write(Movement + oGroundAngleNew, 0.f, float);
	}



	/*Weapon Info*/
	BaseProjectile* WeaponInfo(int Id)
	{
		UINT64 Inventory = safe_read((const uintptr_t)this + oPlayerInventory, UINT64);
		UINT64 Belt = safe_read(Inventory + 0x28, UINT64);
		UINT64 ItemList = safe_read(Belt + 0x40, UINT64);
		UINT64 Items = safe_read(ItemList + 0x10, UINT64);
		return (BaseProjectile*)safe_read(Items + 0x20 + (Id * 0x8), UINT64);
	}

	BaseProjectile* ActiveWeapon()
	{
		int ActUID = safe_read((uintptr_t)this + oActiveUID, int);
		if (!ActUID) return nullptr;
		BaseProjectile* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = WeaponInfo(i))->UID()) {
				return ActiveWeapon;
			}
		return nullptr;
	}



	/*Local-Player*/





	std::string __fastcall GetHealth() {
		return readstring(this->Health());
	}

	std::string __fastcall GetNamecChars() {
		return readstring(this->GetName());
	}

	std::string __fastcall GetActiveWeaponcChars() {
		BaseProjectile* ActWeapon = this->ActiveWeapon();
		string ActiveWeaponName;
		if (!ActWeapon)
		{
			ActiveWeaponName = xorstr_("Empty");

		}
		else
		{
			ActiveWeaponName = readstring(ActWeapon->GetName());
		}
		return ActiveWeaponName;
	}

	uintptr_t __fastcall GetItemsList() {
		auto Inventory = Driver.Read<uintptr_t>((const uintptr_t)this + oPlayerInventory);
		auto Belt = Driver.Read <uintptr_t>(Inventory + 0x28);
		auto ItemList = Driver.Read<uintptr_t>(Belt + 0x38);
		return Driver.Read<uintptr_t>(ItemList + 0x10);
	}



	std::string __fastcall GetBeltItems(uintptr_t ItemsList, int Slot) {
		uintptr_t SlotItem;
		if (Slot == 1) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x20);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 2) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x28);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 3) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x30);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 4) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x38);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 5) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x40);
			if (!SlotItem) {
				return ("");
			}
		}
		else if (Slot == 6) {
			SlotItem = Driver.Read<uintptr_t>(ItemsList + 0x48);
			if (!SlotItem) {
				return ("");
			}
		}

		auto Item1Info = Driver.Read<uintptr_t>(SlotItem + 0x20);
		if (!Item1Info) {
			return ("");
		}

		auto ItemDisplayName = Driver.Read<uintptr_t>(Item1Info + 0x28);
		if (!ItemDisplayName) {
			return ("");
		}

		auto ItemDisplayEnglish = Driver.Read<uintptr_t>(ItemDisplayName + 0x18);
		if (!ItemDisplayEnglish) {
			return ("");
		}

		auto NameTest = Driver.Read<uintptr_t>(ItemDisplayEnglish + 0x14);

		if (!NameTest) {
			return ("");
		}

		std::wstring Name = read_wstring(ItemDisplayEnglish + 0x14, 1024);

		std::string output(Name.begin(), Name.end());


		return output;
	}


	struct TransformAccessReadOnly
	{
		uint64_t pTransformData;
	};

	struct TransformData
	{
		uint64_t pTransformArray;
		uint64_t pTransformIndices;
	};

	struct Matrix34
	{
		Vector4 vec0;
		Vector4 vec1;
		Vector4 vec2;
	};



	Vector3 __fastcall GetBone(ULONG_PTR pTransform)
	{
		__m128 result;

		const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
		const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
		const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

		TransformAccessReadOnly pTransformAccessReadOnly = safe_read(pTransform + 0x38, TransformAccessReadOnly);
		unsigned int index = safe_read(pTransform + 0x40, unsigned int);
		TransformData transformData = safe_read(pTransformAccessReadOnly.pTransformData + 0x18, TransformData);

		if (transformData.pTransformArray && transformData.pTransformIndices)
		{
			result = safe_read(transformData.pTransformArray + 0x30 * index, __m128);
			int transformIndex = safe_read(transformData.pTransformIndices + 0x4 * index, int);
			int pSafe = 0;
			while (transformIndex >= 0 && pSafe++ < 200)
			{
				Matrix34 matrix34 = safe_read(transformData.pTransformArray + 0x30 * transformIndex, Matrix34);

				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));	// xxxx
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));	// yyyy
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));	// zwxy
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));	// wzyw
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));	// zzzz
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));	// yxwy
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

				result = _mm_add_ps(
					_mm_add_ps(
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
							tmp7)), *(__m128*)(&matrix34.vec0));

				transformIndex = safe_read(transformData.pTransformIndices + 0x4 * transformIndex, int);
			}
		}

		return Vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
	}

	DWORD64 __fastcall GetTransform(int bone)
	{
		DWORD64 model = safe_read((const uintptr_t)this + 0xB8, DWORD64);// public Model model;\\public class BaseEntity : BaseNetworkable, IProvider, ILerpTarget, IPrefabPreProcess // TypeDefIndex: 8714
		DWORD64 boneTransforms = safe_read(model + 0x48, DWORD64);//public Transform[] boneTransforms;
		DWORD64 BoneValue = safe_read((boneTransforms + (0x20 + (bone * 0x8))), DWORD64);
		return safe_read(BoneValue + 0x10, DWORD64);

	}

	Vector3 __fastcall GetBonePosition(int bone)
	{
		uintptr_t playerModel = Driver.Read<uintptr_t>((const uintptr_t)this + 0xB8); //BaseEntity -> public Model model;
		uintptr_t boneTransforms = Driver.Read<uintptr_t>(playerModel + 0x48);
		uintptr_t entityBone = Driver.Read<uintptr_t>(boneTransforms + (0x20 + (bone * 0x8)));
		return GetBone(Driver.Read<uintptr_t>(entityBone + 0x10));
	}

};


class LPlayerBase
{
public:
	BasePlayer* BasePlayer = nullptr;
	Matrix4x4* pViewMatrix = nullptr;
	bool __fastcall WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
	{
		/*std::cout << "\n" << safe_read((ULONG64)&pViewMatrix->_11, float) << " " << safe_read((ULONG64)&pViewMatrix->_12, float) << " " << safe_read((ULONG64)&pViewMatrix->_13, float) << " " << safe_read((ULONG64)&pViewMatrix->_14, float) << "\n";
		std::cout << safe_read((ULONG64)&pViewMatrix->_21, float) << " " << safe_read((ULONG64)&pViewMatrix->_22, float) << " " << safe_read((ULONG64)&pViewMatrix->_23, float) << " " << safe_read((ULONG64)&pViewMatrix->_24, float) << "\n";
		std::cout << safe_read((ULONG64)&pViewMatrix->_31, float) << " " << safe_read((ULONG64)&pViewMatrix->_32, float) << " " << safe_read((ULONG64)&pViewMatrix->_33, float) << " " << safe_read((ULONG64)&pViewMatrix->_34, float) << "\n";
		std::cout << safe_read((ULONG64)&pViewMatrix->_41, float) << " " << safe_read((ULONG64)&pViewMatrix->_42, float) << " " << safe_read((ULONG64)&pViewMatrix->_43, float) << " " << safe_read((ULONG64)&pViewMatrix->_44, float) << "\n";
		*/
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(safe_read((ULONG64)&pViewMatrix->_14, float), safe_read((ULONG64)&pViewMatrix->_24, float), safe_read((ULONG64)&pViewMatrix->_34, float));
		Vector3 RightVec = Vector3(safe_read((ULONG64)&pViewMatrix->_11, float), safe_read((ULONG64)&pViewMatrix->_21, float), safe_read((ULONG64)&pViewMatrix->_31, float));
		Vector3 UpVec = Vector3(safe_read((ULONG64)&pViewMatrix->_12, float), safe_read((ULONG64)&pViewMatrix->_22, float), safe_read((ULONG64)&pViewMatrix->_32, float));
		float w = Math::Dot(TransVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_44, float);
		//std::cout << "| " << w << " |" << std::endl;
		if (w < 0.098f) return false;
		float y = Math::Dot(UpVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_42, float);
		float x = Math::Dot(RightVec, EntityPos) + safe_read((ULONG64)&pViewMatrix->_41, float);
		ScreenPos = Vector2((Value::floats::Screen::W / 2) * (1.f + x / w), (Value::floats::Screen::H / 2) * (1.f - y / w));
		return true;
	}

};

LPlayerBase LocalPlayer;
