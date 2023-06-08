#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>  
#include "Process/Process.h"
#include <Windows.h>
#include <string>
#include <cassert>
#include <emmintrin.h>
#include <tlhelp32.h>
#include <winternl.h>
#include <signal.h>
#include "XorStr.hpp"
#include "Menu.h"
#include "Driver/driver.h"
#include "Driver.hpp"
#include "kdmapper/intel_driver.hpp"
#include "kdmapper/mapper.hpp"
#include "VMPSDK.h"
#include "DriverBytes.h"

#include "utils.hpp"
#include "auth.hpp"
ProcCBACAPC NtConvertBetweenAuxiliaryCounterAndPerformanceCounter = 0x0;
#define COLOUR(x) x/255



typedef struct _UncStr
{
	char stub[0x10];
	int len;
	wchar_t str2[100];
	wchar_t str;
} *pUncStr;


std::string get_random_string(int len)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);
	for (int i = 0; i < len; ++i)
	{
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return tmp_s;
}

using namespace std;



long long firstentry = 0;
UINT64 TodCycle = 0;
UINT64 val1;



inline int wLeft, wTop;

#define CHECK_VALID( _v ) 0
#define Assert( _exp ) ((void)0)

#define FastSqrt(x)			(sqrt)(x)

#define M_PI 3.14159265358979323846264338327950288419716939937510

#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include "xorstr.h"

#pragma once
#include <Windows.h>



IDirect3D9Ex* pObject = NULL;
IDirect3DDevice9Ex* pDevice = NULL;


int Width = GetSystemMetrics(SM_CXSCREEN);
int Height = GetSystemMetrics(SM_CYSCREEN);
const MARGINS Margin = { -1 };

bool ShowMenu = false;
bool Initialised = false;

void ClearD3D()
{
	if (pDevice != NULL)
	{
		pDevice->EndScene();
		pDevice->Release();
	}
	if (pObject != NULL)
	{
		pObject->Release();
	}
}

#define safe_read(Addr, Type) Driver.Read<Type>(Addr)
#define safe_write(Addr, Data, Type) Driver.Write<Type>(Addr, Data)
#define safe_read_chain(Addr, Chain, Type) ReadChain<Type>(Addr, Chain) 



float cloud_size = 5.f;
int length(uintptr_t addr) { return safe_read(addr + 0x10, int); }

std::string readstring(uintptr_t addr) {
	try {
		static char buff[128] = { 0 };
		buff[length(addr)] = '\0';

		for (int i = 0; i < length(addr); ++i) {
			if (buff[i] < 128) {
				buff[i] = safe_read(addr + 0x14 + (i * 2), char);
			}
			else {
				buff[i] = '?';
				if (buff[i] >= 0xD800 && buff[i] <= 0xD8FF)
					i++;
			}
		}
		return std::string(&buff[0], &buff[length(addr)]);
	}
	catch (const std::exception& exc) {}
	return "Error";
}
struct monostr
{
	char buffer[128];
};



#include "Of.h"

#include "Main.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_internal.h"
#include "Overlay.h"



bool CreateConsole = true;

#include "Value.h"
#include "SDK/Math.h"
#include "SDK/BaseProjectile.h"
#include "SDK/BasePlayer.h"
#include "SDK/Misc.h"
#include "SDK/Aim.h"


BasePlayer* AimEntity = nullptr;
BasePlayer localclass;
BasePlayer currentent;
BasePlayer currentplayer;
BaseProjectile wep;
//bool OnServer;

#include <mutex>
inline std::mutex          entity_mutex;
inline std::vector<BasePlayer*> otherplayers;
inline std::vector<Vector3> Stash;
inline std::vector<Vector3> hemp;
inline std::vector<Vector3> backpack;
inline std::vector<Vector3> corpse;
inline std::vector<Vector3> vehicles;
inline std::vector<Vector3> DroppedItem;
inline std::vector<Vector3> Airdrop;
inline std::vector<Vector3> patrol_heli;
inline std::vector<Vector3> hackable_crate;
inline std::vector<Vector3> high_tier_crates;
inline std::vector<Vector3> low_tier_crates;
inline std::vector<Vector3> SulfurNodes;
inline std::vector<Vector3> StoneNodes;
inline std::vector<Vector3> MetalNodes;


inline std::vector<Vector3> Cupboard;
inline std::vector<Vector3> guntrap;
inline std::vector<Vector3> bradley_crate;
inline std::vector<Vector3> crate_basic;
inline std::vector<Vector3> crate_winter;
inline std::vector<Vector3> workbench1;
inline std::vector<Vector3> workbench2;
inline std::vector<Vector3> workbench3;
inline std::vector<Vector3> crate_elite;
inline std::vector<Vector3> _CrateTools;
inline std::vector<Vector3> autoturret;
inline std::vector<Vector3> fuel_storage_scrapheli;
inline std::vector<Vector3> beartrap;
inline std::vector<Vector3> crate_normal;
inline std::vector<Vector3> crate_normal2;
inline std::vector<Vector3> horse;
inline std::vector<Vector3> bear;
inline std::vector<Vector3> boar;
inline std::vector<Vector3> Diesel;


void WeaponFix(BaseProjectile* weapon)
{
	
	int ItemID = 0;
	if (weapon)
		ItemID = weapon->GetItemID();
	if (!ItemID) return;

	for (DWORD64 val : semiautomatic) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->SAutomatic();
			weapon->FBullet();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			weapon->ShotGunSpread();
			weapon->NoSway();
			if (ItemID == 1443579727) {
				weapon->FastBow();
			}
			return;
		}
	}
	for (DWORD64 val : sniper) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->FBullet();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			weapon->ShotGunSpread();
			weapon->NoSway();

			return;
		}
	}
	for (DWORD64 val : shootgun) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->fastSwitch();
			weapon->FBullet();
			weapon->ShotGunSpread();
			weapon->NoSway();

			return;
		}
	}

	for (DWORD64 val : automatic) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->FBullet();
			weapon->Spread();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			weapon->ShotGunSpread();
			weapon->NoSway();
			return;
		}
	}

	if (ItemID == -75944661)
	{
		weapon->Recoil();
		weapon->SuperEoka();
		weapon->fastSwitch();
		weapon->Spread();
		weapon->ShotGunSpread();
		weapon->NoSway();
		return;
	}
	for (DWORD64 val : bow) {
		if (ItemID == val)
		{
			weapon->FastBow();
		}
	}


	for (DWORD64 val : meele) {
		if (ItemID == val) {
			weapon->LongHand();
			return;
		}
	}
	
}

void Draw()
{
	if (Value::bools::Aim::Fov) {
		RGBA FovColor = { Value::Colors::Aim::Fov[0] * 255, Value::Colors::Aim::Fov[1] * 255 , Value::Colors::Aim::Fov[2] * 255, Value::Colors::Aim::Fov[3] * 255 };
		pOverlay->Circle(Value::floats::Screen::W / 2, Value::floats::Screen::H / 2, Value::floats::Aim::Fov, &FovColor, 50);

	}
}



void RadarPlayer(BasePlayer* player)
{
	if (LocalPlayer.BasePlayer && Value::bools::Visuals::Radar::Enable)
	{
		if (!player->Dead() && player->Health() >= 0.2f)
		{
			const Vector3 LocalPos = LocalPlayer.BasePlayer->GetBoneByID();
			const Vector3 PlayerPos = player->GetBoneByID();
			const float Distance = (int)Math::Calc3D_Dist(LocalPos, PlayerPos);
			const float y = LocalPos.x - PlayerPos.x;
			const float x = LocalPos.z - PlayerPos.z;
			Vector3 LocalEulerAngles = LocalPlayer.BasePlayer->GetBoneByID();

			const float num = atan2(y, x) * 57.29578f - 270.f - LocalEulerAngles.y;
			float PointPos_X = Distance * cos(num * 0.0174532924f);
			float PointPos_Y = Distance * sin(num * 0.0174532924f);
			PointPos_X = (PointPos_X * ((Value::floats::Visuals::Radar::Radius * 2) / Value::floats::Visuals::Radar::Distance)) / 2.f;
			PointPos_Y = (PointPos_Y * ((Value::floats::Visuals::Radar::Radius * 2) / Value::floats::Visuals::Radar::Distance)) / 2.f;
			if (!player->Flags(16))
			{
				if (Distance <= Value::floats::Visuals::Radar::Distance)
				{
					RGBA Red = { 255, 0, 0, 255 };
					pOverlay->Circle(Value::floats::Screen::W - Value::floats::Visuals::Radar::Radius + PointPos_X, Value::floats::Visuals::Radar::Radius + PointPos_Y, 2, &Red, 10);
				}
			}
			else
				if (player->Flags(16) && Value::bools::Visuals::Radar::Sleeper)
				{
					if (Distance <= Value::floats::Visuals::Radar::Distance)
					{

						RGBA Green = { 0, 255, 0, 255 };
						pOverlay->Circle(Value::floats::Screen::W - Value::floats::Visuals::Radar::Radius + PointPos_X, Value::floats::Visuals::Radar::Radius + PointPos_Y, 2, &Green, 10);

					}
				}
		}
	}
}

bool cunter = false;
//void InitPlayer()
//{
//	long long i = 0;
//	const auto camera_manager_offset = safe_read(unity_player + 0x1A74500, UINT64);
//	const auto camera_manager = safe_read(camera_manager_offset, UINT64);
//	const auto camera = safe_read(camera_manager, UINT64);
//	const auto camera_object = safe_read(camera + 0x30, UINT64);
//	const auto object_class = safe_read(camera_object + 0x30, UINT64);
//	const auto entity = safe_read(object_class + 0x18, UINT64);
//	LocalPlayer.pViewMatrix = (Matrix4x4*)(entity + 0x2E4);
//	/*Matrix4x4* pViewMatrix = LocalPlayer.pViewMatrix;
//	std::cout << "\n" << safe_read((ULONG64)&pViewMatrix->_11, float) << " " << safe_read((ULONG64)&pViewMatrix->_12, float) << " " << safe_read((ULONG64)&pViewMatrix->_13, float) << " " << safe_read((ULONG64)&pViewMatrix->_14, float) << "\n";
//	std::cout << safe_read((ULONG64)&pViewMatrix->_21, float) << " " << safe_read((ULONG64)&pViewMatrix->_22, float) << " " << safe_read((ULONG64)&pViewMatrix->_23, float) << " " << safe_read((ULONG64)&pViewMatrix->_24, float) << "\n";
//	std::cout << safe_read((ULONG64)&pViewMatrix->_31, float) << " " << safe_read((ULONG64)&pViewMatrix->_32, float) << " " << safe_read((ULONG64)&pViewMatrix->_33, float) << " " << safe_read((ULONG64)&pViewMatrix->_34, float) << "\n";
//	std::cout << safe_read((ULONG64)&pViewMatrix->_41, float) << " " << safe_read((ULONG64)&pViewMatrix->_42, float) << " " << safe_read((ULONG64)&pViewMatrix->_43, float) << " " << safe_read((ULONG64)&pViewMatrix->_44, float) << "\n";	
//	*/
//	cunter = true;
//
//}
void InitPlayer()
{
	const auto main_camera = safe_read(game_assembly + oMainCamera, UINT64);
	LocalPlayer.pViewMatrix = (Matrix4x4*)(ReadChain<UINT64>(main_camera, { 0xB8 , 0x0 , 0x10 }) + 0x2E4);
	Matrix4x4* pViewMatrix = LocalPlayer.pViewMatrix;
	//std::cout << "\n" << safe_read((ULONG64)&pViewMatrix->_11, float) << " " << safe_read((ULONG64)&pViewMatrix->_12, float) << " " << safe_read((ULONG64)&pViewMatrix->_13, float) << " " << safe_read((ULONG64)&pViewMatrix->_14, float) << "\n";
	//std::cout << safe_read((ULONG64)&pViewMatrix->_21, float) << " " << safe_read((ULONG64)&pViewMatrix->_22, float) << " " << safe_read((ULONG64)&pViewMatrix->_23, float) << " " << safe_read((ULONG64)&pViewMatrix->_24, float) << "\n";
	//std::cout << safe_read((ULONG64)&pViewMatrix->_31, float) << " " << safe_read((ULONG64)&pViewMatrix->_32, float) << " " << safe_read((ULONG64)&pViewMatrix->_33, float) << " " << safe_read((ULONG64)&pViewMatrix->_34, float) << "\n";
	//std::cout << safe_read((ULONG64)&pViewMatrix->_41, float) << " " << safe_read((ULONG64)&pViewMatrix->_42, float) << " " << safe_read((ULONG64)&pViewMatrix->_43, float) << " " << safe_read((ULONG64)&pViewMatrix->_44, float) << "\n";
	cunter = true;

}



#include <comdef.h>
Vector2 Penis;




void ESPThread(BasePlayer* BP, BasePlayer* LP) {
	if (Value::bools::Visuals::ESP::Enable) {
		Vector2 tempFeetR, tempFeetL;
		//std::cout << "\n{1} ";
		if (LocalPlayer.WorldToScreen(BP->GBoneByID2(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(BP->GBoneByID2(penis), Penis) && LocalPlayer.WorldToScreen(BP->GBoneByID2(l_foot), tempFeetL)) {
			//std::cout << " {2} ";
			Vector2 tempHead;
			if (LocalPlayer.WorldToScreen(BP->GBoneByID2(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
			{
				//std::cout << " {3} ";

				Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
				float Entity_h = tempHead.y - tempFeet.y;
				float w = Entity_h / 4;
				float Entity_x = tempFeet.x - w;
				float Entity_y = tempFeet.y;
				float Entity_w = Entity_h / 2;
				const Vector3 LocalPos = LocalPlayer.BasePlayer->GetBoneByID();
				const Vector3 PlayerPos = BP->GetBoneByID();
				float height = (tempHead.y - tempFeet.y);
				float width = height / 4.0f;
				float Entity_xh = tempFeet.x - width;
				float Entity_y2 = tempFeet.y;
				float flBoxes = std::ceil(BP->Health() / 10.f);
				float flX = Entity_x + 4; float flY = Entity_y;
				float flHeight = height / 10.f;
				bool PlayerWounded = BP->Flags(64);
				bool PlayerSleeping = BP->Flags(16);
				bool Npc = BP->IsNpcss();
				const float Distance = (int)Math::Calc3D_Dist(LocalPos, PlayerPos);


				if (PlayerSleeping && Value::bools::Visuals::ESP::IgnoreSleeper)
					return;
				if (Npc && Value::bools::Visuals::ESP::IgnoreBot)
					return;


				RGBA White = { 255, 0,255,255 };
				RGBA Bot = { 0, 0,0,255 };
				static float screenW = GetSystemMetrics(SM_CXSCREEN);
				static float screenH = GetSystemMetrics(SM_CYSCREEN);
				RGBA ColorRed = { Value::Colors::Visuals::ESP::ColorRed[0] * 255, Value::Colors::Visuals::ESP::ColorRed[1] * 255 , Value::Colors::Visuals::ESP::ColorRed[2] * 255, Value::Colors::Visuals::ESP::ColorRed[3] * 255 };
				if (Distance <= Value::bools::Visuals::ESP::ToDistance)
				{
					/*if (Value::bools::Visuals::ESP::Skeleton)
					{
						RGBA Color = { Value::Colors::Visuals::ESP::Skeleton[0] * 255, Value::Colors::Visuals::ESP::Skeleton[1] * 255 , Value::Colors::Visuals::ESP::Skeleton[2] * 255, Value::Colors::Visuals::ESP::Skeleton[3] * 255 };
						std::array<BonesList, 15> Bones = {
						r_foot1, l_knee1, l_hip1,
						l_foot1, r_knee1, r_hip1,
						spine11, neck1, head1,
						l_upperarm1, l_forearm1, l_hand1,
						r_upperarm1, r_forearm1, r_hand1
						}; std::array<Vector2, Bones.size()> BonesPos;

						for (int i = 0; i < BonesPos.size(); ++i) {
							if (!(LocalPlayer.WorldToScreen(BP->GetBonePosition(Bones[i]), BonesPos.at(i)))) continue;
						}
						for (int j = 0; j < BonesPos.size(); j += 3)
						{
							pOverlay->DrawLine(BonesPos[j].x, BonesPos[j].y, BonesPos[j + 1].x, BonesPos[j + 1].y, &Color, 1.5);
							pOverlay->DrawLine(BonesPos[j + 1].x, BonesPos[j + 1].y, BonesPos[j + 2].x, BonesPos[j + 2].y, &Color, 1.5);

						}

						pOverlay->DrawLine(BonesPos[2].x, BonesPos[2].y, BonesPos[6].x, BonesPos[6].y, &Color, 1.5);
						pOverlay->DrawLine(BonesPos[5].x, BonesPos[5].y, BonesPos[6].x, BonesPos[6].y, &Color, 1.5);
						pOverlay->DrawLine(BonesPos[9].x, BonesPos[9].y, BonesPos[7].x, BonesPos[7].y, &Color, 1.5);
						pOverlay->DrawLine(BonesPos[12].x, BonesPos[12].y, BonesPos[7].x, BonesPos[7].y, &Color, 1.5);

					}*/
					if (Value::bools::Visuals::ESP::Health) {
						RGBA Colorhp = { Value::Colors::Visuals::ESP::Health[0] * 255, Value::Colors::Visuals::ESP::Health[1] * 255 , Value::Colors::Visuals::ESP::Health[2] * 255, Value::Colors::Visuals::ESP::Health[3] * 255 };
						RGBA Color = { Value::Colors::Visuals::ESP::Health[0] * 255, Value::Colors::Visuals::ESP::Health[1] * 255 , Value::Colors::Visuals::ESP::Health[2] * 255, Value::Colors::Visuals::ESP::Health[3] * 255 };
						char Health[64];
						sprintf(Health, xorstr_("%0.f HP"), BP->Health());
						pOverlay->Text(Entity_x + 13, Entity_y - 15, &Color, Health);
						pOverlay->drawHealthBar(Entity_x, Entity_y, Entity_w, Entity_h, BP->Health(), 100, &Colorhp);

					}

					if (Value::bools::Visuals::ESP::Box && !PlayerSleeping && !PlayerWounded) {
						RGBA Color = { Value::Colors::Visuals::ESP::Box[0] * 255, Value::Colors::Visuals::ESP::Box[1] * 255 , Value::Colors::Visuals::ESP::Box[2] * 255, Value::Colors::Visuals::ESP::Box[3] * 255 };
						pOverlay->Rect(Entity_x, Entity_y, Entity_w, Entity_h, &Color, 2);
						if (!BP->IsVisible())
						{
							pOverlay->Rect(Entity_x, Entity_y, Entity_w, Entity_h, &ColorRed, 2.1);
						}
					}
					if (Value::bools::Visuals::ESP::CornerBox && !PlayerSleeping && !PlayerWounded) {
						RGBA Color = { Value::Colors::Visuals::ESP::CornerBox[0] * 255, Value::Colors::Visuals::ESP::CornerBox[1] * 255 , Value::Colors::Visuals::ESP::CornerBox[2] * 255, Value::Colors::Visuals::ESP::CornerBox[3] * 255 };
						pOverlay->DrawCornerBox(Entity_x, Entity_y, Entity_w, Entity_h, 1.5, &Color);
						if (!BP->IsVisible())
						{
							pOverlay->DrawCornerBox(Entity_x, Entity_y, Entity_w, Entity_h, 1.6, &ColorRed);
						}
					}
					if (Value::bools::Visuals::ESP::BoxRect && !PlayerSleeping && !PlayerWounded) {
						RGBA Color = { Value::Colors::Visuals::ESP::BoxRect[0] * 255, Value::Colors::Visuals::ESP::BoxRect[1] * 255 , Value::Colors::Visuals::ESP::BoxRect[2] * 255, Value::Colors::Visuals::ESP::BoxRect[3] * 255 };
						pOverlay->DrawFilledRectImGui(tempFeet.x - (Entity_w / 2), tempFeet.y, Entity_w, Entity_h, ImVec4(COLOUR(0.0f), COLOUR(0.0f), COLOUR(0.0f), COLOUR(100.0f)));
					}
					if (Value::bools::Visuals::ESP::Distance) {
						RGBA Color = { Value::Colors::Visuals::ESP::Distance[0] * 255, Value::Colors::Visuals::ESP::Distance[1] * 255 , Value::Colors::Visuals::ESP::Distance[2] * 255, Value::Colors::Visuals::ESP::Distance[3] * 255 };
						char Distance[64];
						sprintf(Distance, xorstr_("%d M"), (int)Math::Calc3D_Dist(LP->GBoneByID2(head), BP->GBoneByID2(head)));
						pOverlay->Text(Entity_x + 13, Entity_y, &Color, Distance);
					}
					if (Value::bools::Visuals::ESP::Name) {
						RGBA Color = { Value::Colors::Visuals::ESP::Name[0] * 255, Value::Colors::Visuals::ESP::Name[1] * 255 , Value::Colors::Visuals::ESP::Name[2] * 255, Value::Colors::Visuals::ESP::Name[3] * 255 };
						pOverlay->TextS(Entity_x + 15, Entity_y - 45, &Color, BP->GetNamecChars().c_str());
					}
					if (Value::bools::Visuals::ESP::Weapon) {
						RGBA Color = { Value::Colors::Visuals::ESP::Weapon[0] * 255, Value::Colors::Visuals::ESP::Weapon[1] * 255 , Value::Colors::Visuals::ESP::Weapon[2] * 255, Value::Colors::Visuals::ESP::Weapon[3] * 255 };
						pOverlay->Text(Entity_x + 15, Entity_y - 30, &Color, BP->GetActiveWeaponcChars().c_str());
					}
					if (Value::bools::Visuals::ESP::Line)
					{
						RGBA Color = { Value::Colors::Aim::TargetLine[0] * 255, Value::Colors::Aim::TargetLine[1] * 255 , Value::Colors::Aim::TargetLine[2] * 255, Value::Colors::Aim::TargetLine[3] * 255 };
						pOverlay->DrawLine(Value::floats::Screen::W / 2, Value::floats::Screen::H / 2, Penis.x, Penis.y, &Color, 1);
					}
				}
			}
		}
	}
}
float W = 200.f, H = 140;;


float FOV = 1000000.f;
int EntityCount;
int RenderedEntityCount;
int RenderedPlayerCount;
void entity_esp_thread() {

	RenderedEntityCount = NULL; RenderedEntityCount = NULL;


	if (Value::bools::Visuals::World::Items::Stash) {
		for (Vector3 Pos : Stash) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Stash [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Stash[0] * 255, Value::Colors::Visuals::World::Stash[1] * 255 , Value::Colors::Visuals::World::Stash[2] * 255, Value::Colors::Visuals::World::Stash[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Hemp) {
		for (Vector3 Pos : hemp) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Hemp [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Hemp[0] * 255, Value::Colors::Visuals::World::Hemp[1] * 255 , Value::Colors::Visuals::World::Hemp[2] * 255, Value::Colors::Visuals::World::Hemp[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::AirDrop) {
		for (Vector3 Pos : Airdrop) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("AirDrop [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance2) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::AirDrop[0] * 255, Value::Colors::Visuals::World::AirDrop[1] * 255 , Value::Colors::Visuals::World::AirDrop[2] * 255, Value::Colors::Visuals::World::AirDrop[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::CH47) {
		for (Vector3 Pos : hackable_crate) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("CH47 [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance2) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::CH47[0] * 255, Value::Colors::Visuals::World::CH47[1] * 255 , Value::Colors::Visuals::World::CH47[2] * 255, Value::Colors::Visuals::World::CH47[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Minicopter) {
		for (Vector3 Pos : vehicles) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				if (distation <= Value::floats::Visuals::World::LimitDistance2) {
					RenderedEntityCount++;
					sprintf(text, xorstr_("Minicopter [%d m]"), distation);
					RGBA Color = { Value::Colors::Visuals::World::Patrol[0] * 255, Value::Colors::Visuals::World::Patrol[1] * 255 , Value::Colors::Visuals::World::Patrol[2] * 255, Value::Colors::Visuals::World::Patrol[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Patrol) {
		for (Vector3 Pos : patrol_heli) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				if (distation <= Value::floats::Visuals::World::LimitDistance2) {
					RenderedEntityCount++;
					sprintf(text, xorstr_("Patrol [%d m]"), distation);
					RGBA Color = { Value::Colors::Visuals::World::Patrol[0] * 255, Value::Colors::Visuals::World::Patrol[1] * 255 , Value::Colors::Visuals::World::Patrol[2] * 255, Value::Colors::Visuals::World::Patrol[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Ore::Stone) {
		for (Vector3 Pos : StoneNodes) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Stone [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Ore::Stone[0] * 255, Value::Colors::Visuals::World::Ore::Stone[1] * 255 , Value::Colors::Visuals::World::Ore::Stone[2] * 255, Value::Colors::Visuals::World::Ore::Stone[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Ore::Iron) {
		for (Vector3 Pos : MetalNodes) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Iron [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Ore::Iron[0] * 255, Value::Colors::Visuals::World::Ore::Iron[1] * 255 , Value::Colors::Visuals::World::Ore::Iron[2] * 255, Value::Colors::Visuals::World::Ore::Iron[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Ore::Sulfur) {
		for (Vector3 Pos : SulfurNodes) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Sulfur [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Ore::Sulfur[0] * 255, Value::Colors::Visuals::World::Ore::Sulfur[1] * 255 , Value::Colors::Visuals::World::Ore::Sulfur[2] * 255, Value::Colors::Visuals::World::Ore::Sulfur[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::ESP::Corpse) {
		for (Vector3 Pos : corpse) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Corpse [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Corpse[0] * 255, Value::Colors::Visuals::World::Corpse[1] * 255 , Value::Colors::Visuals::World::Corpse[2] * 255, Value::Colors::Visuals::World::Corpse[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}


	if (Value::bools::Visuals::ESP::Backpack) {
		for (Vector3 Pos : backpack) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Backpack [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Backpack[0] * 255, Value::Colors::Visuals::World::Backpack[1] * 255 , Value::Colors::Visuals::World::Backpack[2] * 255, Value::Colors::Visuals::World::Backpack[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::Cupboard) {
		for (Vector3 Pos : Cupboard) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Cupboard [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Cupboard[0] * 255, Value::Colors::Visuals::World::Cupboard[1] * 255 , Value::Colors::Visuals::World::Cupboard[2] * 255, Value::Colors::Visuals::World::Cupboard[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::Diesel) {
		for (Vector3 Pos : Diesel) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Diesel [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Diesel[0] * 255, Value::Colors::Visuals::World::Diesel[1] * 255 , Value::Colors::Visuals::World::Diesel[2] * 255, Value::Colors::Visuals::World::Diesel[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::guntrap) {
		for (Vector3 Pos : guntrap) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Guntrap [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::guntrap[0] * 255, Value::Colors::Visuals::World::guntrap[1] * 255 , Value::Colors::Visuals::World::guntrap[2] * 255, Value::Colors::Visuals::World::guntrap[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::crate_elite) {
		for (Vector3 Pos : crate_elite) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Elite [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::crate_elite[0] * 255, Value::Colors::Visuals::World::crate_elite[1] * 255 , Value::Colors::Visuals::World::crate_elite[2] * 255, Value::Colors::Visuals::World::crate_elite[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::crate_basic) {
		for (Vector3 Pos : crate_basic) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Basic [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::crate_basic[0] * 255, Value::Colors::Visuals::World::crate_basic[1] * 255 , Value::Colors::Visuals::World::crate_basic[2] * 255, Value::Colors::Visuals::World::crate_basic[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::Winter) {
		for (Vector3 Pos : crate_winter) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Adventer Calendar [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::crate_winter[0] * 255, Value::Colors::Visuals::World::crate_winter[1] * 255 , Value::Colors::Visuals::World::crate_winter[2] * 255, Value::Colors::Visuals::World::crate_winter[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::bradley_crate) {
		for (Vector3 Pos : bradley_crate) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Bradley [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::bradley_crate[0] * 255, Value::Colors::Visuals::World::bradley_crate[1] * 255 , Value::Colors::Visuals::World::bradley_crate[2] * 255, Value::Colors::Visuals::World::bradley_crate[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}

	if (Value::bools::Visuals::World::Items::scrapheli) {
		for (Vector3 Pos : fuel_storage_scrapheli) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("ScrapHeli [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::scrapheli[0] * 255, Value::Colors::Visuals::World::scrapheli[1] * 255 , Value::Colors::Visuals::World::scrapheli[2] * 255, Value::Colors::Visuals::World::scrapheli[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}


	if (Value::bools::Visuals::World::Items::CrateTools) {
		for (Vector3 Pos : _CrateTools) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Tools [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::CrateTools[0] * 255, Value::Colors::Visuals::World::CrateTools[1] * 255 , Value::Colors::Visuals::World::CrateTools[2] * 255, Value::Colors::Visuals::World::CrateTools[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Workbench1) {
		for (Vector3 Pos : workbench1) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Workbench 1 [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Workbench1[0] * 255, Value::Colors::Visuals::World::Workbench1[1] * 255 , Value::Colors::Visuals::World::Workbench1[2] * 255, Value::Colors::Visuals::World::Workbench1[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Workbench2) {
		for (Vector3 Pos : workbench2) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Workbench 2 [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Workbench2[0] * 255, Value::Colors::Visuals::World::Workbench2[1] * 255 , Value::Colors::Visuals::World::Workbench2[2] * 255, Value::Colors::Visuals::World::Workbench2[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Workbench3) {
		for (Vector3 Pos : workbench3) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Workbench 3 [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Workbench3[0] * 255, Value::Colors::Visuals::World::Workbench3[1] * 255 , Value::Colors::Visuals::World::Workbench3[2] * 255, Value::Colors::Visuals::World::Workbench3[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::BearTrap) {
		for (Vector3 Pos : beartrap) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Bear Trap [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::BearTrap[0] * 255, Value::Colors::Visuals::World::BearTrap[1] * 255 , Value::Colors::Visuals::World::BearTrap[2] * 255, Value::Colors::Visuals::World::BearTrap[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::autoturret) {
		for (Vector3 Pos : autoturret) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Auto Turret [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::autoturret[0] * 255, Value::Colors::Visuals::World::autoturret[1] * 255 , Value::Colors::Visuals::World::autoturret[2] * 255, Value::Colors::Visuals::World::autoturret[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::crate_normal) {
		for (Vector3 Pos : crate_normal) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Military [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::crate_normal[0] * 255, Value::Colors::Visuals::World::crate_normal[1] * 255 , Value::Colors::Visuals::World::crate_normal[2] * 255, Value::Colors::Visuals::World::crate_normal[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::crate_normal2) {
		for (Vector3 Pos : crate_normal2) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Crate Normal [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::crate_normal2[0] * 255, Value::Colors::Visuals::World::crate_normal2[1] * 255 , Value::Colors::Visuals::World::crate_normal2[2] * 255, Value::Colors::Visuals::World::crate_normal2[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::horse) {
		for (Vector3 Pos : horse) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Horse [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::horse[0] * 255, Value::Colors::Visuals::World::horse[1] * 255 , Value::Colors::Visuals::World::horse[2] * 255, Value::Colors::Visuals::World::horse[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Bear) {
		for (Vector3 Pos : bear) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Bear [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Bear[0] * 255, Value::Colors::Visuals::World::Bear[1] * 255 , Value::Colors::Visuals::World::Bear[2] * 255, Value::Colors::Visuals::World::Bear[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}
	if (Value::bools::Visuals::World::Items::Boar) {
		for (Vector3 Pos : boar) {
			Vector2 pos;
			if (LocalPlayer.WorldToScreen(Pos, pos)) {
				int distation = (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GBoneByID2(head), Pos);
				char text[0x100];
				sprintf(text, xorstr_("Boar [%d m]"), distation);
				if (distation <= Value::floats::Visuals::World::LimitDistance) {
					RenderedEntityCount++;
					RGBA Color = { Value::Colors::Visuals::World::Bear[0] * 255, Value::Colors::Visuals::World::Boar[1] * 255 , Value::Colors::Visuals::World::Boar[2] * 255, Value::Colors::Visuals::World::Boar[3] * 255 };
					pOverlay->Text(pos.x, pos.y, &Color, text);
				}
			}
		}
	}



	if (Value::bools::Visuals::ESP::Enable) {
		Vector2 ScreenPos;
		for (BasePlayer* Player : otherplayers) {
			if (!Player->IsValid())
			{
				//std::cout << "Not valid";
				continue;
			}

			if (/*Value::bools::Aim::IgnoreSleepers && */Player->Flags(16) || Player->Flags(64))
				continue;
			if (Value::bools::Aim::ignoreNpc && Player->IsNpcss())
				continue;

			ESPThread(Player, LocalPlayer.BasePlayer);
			RadarPlayer(Player);

			if (Player->IsVisible() && (AimFov(Player, head) < Value::floats::Aim::Fov))
			{
				AimEntity = Player;
				Aim(AimEntity);
			}
		}
		//std::cout << "\t";
	}
}





#include <vector>
#include <string>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string.h>

std::vector<BasePlayer*> local_players;
std::vector<Vector3> local_Stash;
std::vector<Vector3> local_hemp;
std::vector<Vector3> local_corpse;
std::vector<Vector3> local_backpack;
std::vector<Vector3> local_vehicles;
std::vector<Vector3> local_Airdrop;
std::vector<Vector3> local_patrol_heli;
std::vector<Vector3> local_hackable_crate;
std::vector<Vector3> local_high_tier_crates;
std::vector<Vector3> local_low_tier_crates;
std::vector<Vector3> local_DroppedItem;
std::vector<Vector3> local_SulfurNodes;
std::vector<Vector3> local_StoneNodes;
std::vector<Vector3> local_MetalNodes;

std::vector<Vector3> local_beartrap;
std::vector<Vector3> local_Cupboard;
std::vector<Vector3> local_Diesel;
std::vector<Vector3> local_winter;
std::vector<Vector3> local_guntrap;
std::vector<Vector3> local_bradley_crate;
std::vector<Vector3> local_crate_basic;
std::vector<Vector3> local_workbench1;
std::vector<Vector3> local_workbench2;
std::vector<Vector3> local_workbench3;
std::vector<Vector3> local_crate_elite;
std::vector<Vector3> local_CrateTools;
std::vector<Vector3> local_fuel_storage_scrapheli;
std::vector<Vector3> local_autoturret;
std::vector<Vector3> local_crate_normal;
std::vector<Vector3> local_crate_normal_2;
std::vector<Vector3> local_horse;
std::vector<Vector3> local_bear;
std::vector<Vector3> local_boar;

DWORD __fastcall WINAPI EntityT1(LPVOID lpParameter) {
	while (true) {

		auto vals = Driver.Read<uintptr_t>(Driver.Read<uintptr_t>(game_assembly + BaseGameMode) + 0xB8); //System_Collections_Generic_List_BaseGameMode__c
		auto entity_realm_client = Driver.Read<uintptr_t>(vals + 0x10);
		auto client_entities = Driver.Read<uintptr_t>(Driver.Read<uintptr_t>(entity_realm_client + 0x10) + 0x28);
		int EntityCount1 = safe_read(client_entities + 0x10, int);
		UINT64 EntityBuffer1 = safe_read(client_entities + 0x18, UINT64);
		for (int i = 0; i <= EntityCount1; i++)
		{
			DWORD64 Entity = safe_read(EntityBuffer1 + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = safe_read(Entity + 0x10, DWORD64);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = safe_read(Object + 0x30, DWORD64);
			string name = ReadNative(ObjectClass + 0x60);

			static char BNname[110] = { '\0' };
			if (name.find(xorstr_("LocalPlayer")) != std::string::npos)
			{
				auto Player = (BasePlayer*)safe_read(Object + 0x28, DWORD64);
				if (!safe_read((uintptr_t)Player + oPlayerModel, DWORD64)) continue; // public PlayerModel playerModel;??? 0x4B0
				LocalPlayer.BasePlayer = Player;
			}
			else
				if (name.find(xorstr_("small_stash_deployed.prefab")) != std::string::npos) {
					DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
					//float burriedOffset = safe_read(gameObject + 0x488, float);
					//std::cout << burriedOffset << std::endl;
					DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
					DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
					Vector3 pos = safe_read(Vec + 0x90, Vector3);
					local_Stash.push_back(pos);
				}
				else
					if (name.find(xorstr_("hemp-collectable.prefab")) != std::string::npos) {
						DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
						DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
						DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
						Vector3 pos = safe_read(Vec + 0x90, Vector3);
						local_hemp.push_back(pos);
					}
					else
						if (name.find(xorstr_("supply_drop.prefab")) != std::string::npos) {
							DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
							DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
							DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
							Vector3 pos = safe_read(Vec + 0x90, Vector3);

							local_Airdrop.push_back(pos);
						}
						else
							if (name.find(xorstr_("codelockedhackablecrate.prefab")) != std::string::npos) {
								DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
								DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
								DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
								Vector3 pos = safe_read(Vec + 0x90, Vector3);

								local_hackable_crate.push_back(pos);
							}
							else
								if (name.find(xorstr_("player_corpse.prefab")) != std::string::npos) {
									DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
									DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
									DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
									Vector3 pos = safe_read(Vec + 0x90, Vector3);

									local_corpse.push_back(pos);
								}
								else

									if (name.find(xorstr_("item_drop_backpack.prefab")) != std::string::npos) {
										DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
										DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
										DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
										Vector3 pos = safe_read(Vec + 0x90, Vector3);

										local_backpack.push_back(pos);
									}
									else
										if (name.find(xorstr_("minicopter.entity.prefab")) != std::string::npos) {
											DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
											DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
											DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
											Vector3 pos = safe_read(Vec + 0x90, Vector3);

											local_vehicles.push_back(pos);
										}
										else
											if (name.find(xorstr_("patrolhelicopter.prefab")) != std::string::npos) {
												DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
												DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
												DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
												Vector3 pos = safe_read(Vec + 0x90, Vector3);

												local_patrol_heli.push_back(pos);
											}
											else
												if (name.find(xorstr_("stone-ore.prefab")) != std::string::npos) {
													DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
													DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
													DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
													Vector3 pos = safe_read(Vec + 0x90, Vector3);

													local_StoneNodes.push_back(pos);
												}
												else
													if (name.find(xorstr_("sulfur-ore.prefab")) != std::string::npos) {
														DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
														DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
														DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
														Vector3 pos = safe_read(Vec + 0x90, Vector3);

														local_SulfurNodes.push_back(pos);
													}
													else
													if (name.find(xorstr_("metal-ore.prefab")) != std::string::npos) {
														DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
														DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
														DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
														Vector3 pos = safe_read(Vec + 0x90, Vector3);

														local_MetalNodes.push_back(pos);
													}
												else
													if (name.find(xorstr_("bear.prefab")) != std::string::npos) {
														DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
														DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
														DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
														Vector3 pos = safe_read(Vec + 0x90, Vector3);

														local_bear.push_back(pos);
													}
													else
														if (name.find(xorstr_("horse.prefab")) != std::string::npos) {
															DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
															DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
															DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
															Vector3 pos = safe_read(Vec + 0x90, Vector3);

															local_horse.push_back(pos);
														}

														else
														if (name.find(xorstr_("boar.prefab")) != std::string::npos) {
															DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
															DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
															DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
															Vector3 pos = safe_read(Vec + 0x90, Vector3);

															local_boar.push_back(pos);
														}
														else
														if (name.find(xorstr_("cupboard.tool.deployed.prefab")) != std::string::npos) {
															DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
															DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
															DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
															Vector3 pos = safe_read(Vec + 0x90, Vector3);

															local_Cupboard.push_back(pos);
														}
														else
														if (name.find(xorstr_("crate_normal.prefab")) != std::string::npos) {
															DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //crate_normal_2.prefab
															DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
															DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
															Vector3 pos = safe_read(Vec + 0x90, Vector3);

															local_crate_normal.push_back(pos);
														}
														else
															if (name.find(xorstr_("crate_normal_2.prefab")) != std::string::npos) {
																DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //crate_normal_2.prefab
																DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																Vector3 pos = safe_read(Vec + 0x90, Vector3);

																local_crate_normal_2.push_back(pos);
															}
															else
																if (name.find(xorstr_("bradley_crate.prefab")) != std::string::npos) {
																	DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																	DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																	DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																	Vector3 pos = safe_read(Vec + 0x90, Vector3);

																	local_bradley_crate.push_back(pos);
																}
																else
																	if (name.find(xorstr_("crate_basic.prefab")) != std::string::npos) {
																		DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																		DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																		DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																		Vector3 pos = safe_read(Vec + 0x90, Vector3);

																		local_crate_basic.push_back(pos);
																	}

																	else
																		if (name.find(xorstr_("workbench3.deployed")) != std::string::npos) {
																			DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																			DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																			DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																			Vector3 pos = safe_read(Vec + 0x90, Vector3);

																			local_workbench3.push_back(pos);
																		}
																		else
																			if (name.find(xorstr_("crate_elite.prefab")) != std::string::npos) {
																				DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																				DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																				DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																				Vector3 pos = safe_read(Vec + 0x90, Vector3);

																				local_crate_elite.push_back(pos);
																			}
																			else
																				if (name.find(xorstr_("workbench1.deployed")) != std::string::npos) {
																					DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																					DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																					DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																					Vector3 pos = safe_read(Vec + 0x90, Vector3);

																					local_workbench1.push_back(pos);
																				}
																				else
																					if (name.find(xorstr_("workbench2.deployed")) != std::string::npos) {
																						DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																						DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																						DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																						Vector3 pos = safe_read(Vec + 0x90, Vector3);

																						local_workbench2.push_back(pos);
																					}
																					else
																						if (name.find(xorstr_("beartrap.prefab"))) {//beartrap
																							DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																							DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																							DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																							Vector3 pos = safe_read(Vec + 0x90, Vector3);

																							local_beartrap.push_back(pos);
																						}
																						else
																							if (name.find(xorstr_("crate_tools.prefab")) != std::string::npos) {
																								DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																								DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																								DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																								Vector3 pos = safe_read(Vec + 0x90, Vector3);

																								local_CrateTools.push_back(pos);
																							}
																							else
																								if (name.find(xorstr_("assets/prefabs/npc/autoturret/autoturret_deployed.prefab")) != std::string::npos) {
																									DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																									DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																									DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																									Vector3 pos = safe_read(Vec + 0x90, Vector3);

																									local_autoturret.push_back(pos);
																								}
																								else
																									if (name.find(xorstr_("fuel_storage_scrapheli.prefab")) != std::string::npos) {
																										DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //crate_normal.prefab
																										DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																										DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																										Vector3 pos = safe_read(Vec + 0x90, Vector3);

																										local_fuel_storage_scrapheli.push_back(pos);
																									}
																									else
																										if (name.find(xorstr_("crate_normal.prefab")) != std::string::npos) {
																											DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //crate_normal.prefab
																											DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																											DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																											Vector3 pos = safe_read(Vec + 0x90, Vector3);

																											local_crate_normal.push_back(pos);
																										}
																												else
																													if (name.find(xorstr_("fuel_storage_scrapheli.prefab")) != std::string::npos) {
																														DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																														DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																														DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																														Vector3 pos = safe_read(Vec + 0x90, Vector3);

																														local_patrol_heli.push_back(pos);
																													}
																													else
																														if (name.find(xorstr_("guntrap.deployed.prefab")) != std::string::npos) {
																															DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																															DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																															DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																															Vector3 pos = safe_read(Vec + 0x90, Vector3);

																															local_guntrap.push_back(pos);
																														}
																														else
																																	if (name.find(xorstr_("diesel_collectable.prefab")) != std::string::npos) {
																																			DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																																			DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																																			DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																																			Vector3 pos = safe_read(Vec + 0x90, Vector3);
																																			local_Diesel.push_back(pos);
																																	}
																																		else
																																			if (name.find(xorstr_("advendcalendar.deployed.prefab")) != std::string::npos) {
																																				DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64); //Tag 449
																																				DWORD64 Trans = safe_read(gameObject + 0x8, DWORD64);
																																				DWORD64 Vec = safe_read(Trans + 0x38, DWORD64);
																																				Vector3 pos = safe_read(Vec + 0x90, Vector3);
																																				local_winter.push_back(pos);
																																			}

																																				



		}
		std::this_thread::sleep_for(std::chrono::milliseconds(600));
		std::lock_guard<std::mutex>lk(entity_mutex);
		Stash = std::move(local_Stash);
		corpse = std::move(local_corpse);
		vehicles = std::move(local_vehicles);
		DroppedItem = std::move(local_DroppedItem);
		SulfurNodes = std::move(local_SulfurNodes);
		StoneNodes = std::move(local_StoneNodes);
		MetalNodes = std::move(local_MetalNodes);
		Airdrop = std::move(local_Airdrop);
		patrol_heli = std::move(local_patrol_heli);
		hackable_crate = std::move(local_hackable_crate);
		hemp = std::move(local_hemp);
		backpack = std::move(local_backpack);
		high_tier_crates = std::move(local_high_tier_crates);
		low_tier_crates = std::move(local_low_tier_crates);
		beartrap = std::move(local_beartrap);
		Cupboard = std::move(local_Cupboard);
		guntrap = std::move(local_guntrap);
		bradley_crate = std::move(local_bradley_crate);
		crate_basic = std::move(local_crate_basic);
		workbench1 = std::move(local_workbench1);
		workbench2 = std::move(local_workbench2);
		workbench3 = std::move(local_workbench3);
		crate_elite = std::move(local_crate_elite);
		crate_winter = std::move(local_winter);
		_CrateTools = std::move(local_CrateTools);
		autoturret = std::move(local_autoturret);
		fuel_storage_scrapheli = std::move(local_fuel_storage_scrapheli);
		crate_normal = std::move(local_crate_normal);
		crate_normal2 = std::move(local_crate_normal_2);
		horse = std::move(local_horse);
		bear = std::move(local_bear);
		boar = std::move(local_boar);
		Diesel = std::move(local_Diesel);
	}
}




bool recover = false;

DWORD __fastcall WINAPI EntityT(LPVOID lpParameter) {
	while (true) {

		auto val = Driver.Read<uintptr_t>(Driver.Read<uintptr_t>(game_assembly + BaseGameMode) + 0xB8); //System_Collections_Generic_List_BaseGameMode__c
		auto entity_realm_client1 = Driver.Read<uintptr_t>(val + 0x10);
		auto client_entities1 = Driver.Read<uintptr_t>(Driver.Read<uintptr_t>(entity_realm_client1 + 0x10) + 0x28);
		int EntityCount11 = safe_read(client_entities1 + 0x10, int);
		UINT64 EntityBuffer11 = safe_read(client_entities1 + 0x18, UINT64);

		for (int i = 0; i < EntityCount11; i++)
		{
			DWORD64 Entity = safe_read(EntityBuffer11 + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = safe_read(Entity + 0x10, DWORD64); //BaseObject
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = safe_read(Object + 0x30, DWORD64); //Object
			string name = ReadNative(ObjectClass + 0x60);


			if (name.find(xorstr_("player.prefab")) != std::string::npos || name.find(xorstr_("scientist")) != std::string::npos)
			{
				BasePlayer* Player = (BasePlayer*)safe_read(Object + 0x28, DWORD64); //bpulic ulong playerID; //0x28
				if (!safe_read((uintptr_t)Player + oPlayerModel, DWORD64)) continue;// 0x4A8 public PlayerModel playerModel;
				if (!Player->IsValid()) continue;
				local_players.push_back(Player);

			}


		}
		//std::cout << "[" << local_players.size() << "]" << std::endl;
		InitPlayer();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::lock_guard<std::mutex>lk(entity_mutex);
		otherplayers = std::move(local_players);
		chrono::microseconds(1);

		auto klass2 = Driver.Read<uintptr_t>(game_assembly + oConVar_Admin_c); // convar_admin_c*
		auto static_fields2 = Driver.Read<uintptr_t>(klass2 + 0xB8);
		if (CustomTime)
		{
			Driver.Write<float>(static_fields2 + 0x0, TimeFloat);  // public static float admintime;
			recover = true;
		}
		else if(recover)
		{
			Driver.Write<float>(static_fields2 + 0x0, -1.0f);
			recover = false;
		}
		



	}
}

#include <TlHelp32.h>
#include "lazy.h"


void __fastcall Loop()
{

	bool valid = LocalPlayer.BasePlayer->IsValid(true);
	if (LocalPlayer.BasePlayer && valid) {
		std::lock_guard<std::mutex>lk(entity_mutex);
		entity_esp_thread();
		Misc();
		int WeaponId = 0;
		int last = -1;
		auto* active = LocalPlayer.BasePlayer->ActiveWeapon();
		if (active) {
			if (active->UID() != 0)
			{
				if (WeaponId != active->GetItemID())
				{
					WeaponId = active->GetItemID();
				}
				last = active->UID();
				if (last)
				{
					WeaponFix(active);
				}
			}
			else if (!last)
				last = active->UID();
		}
		
	}
	else
		if (!LocalPlayer.BasePlayer)
			InitPlayer();

}


HWND hwndRust;
HWND hwnd1;
bool mappDrv = false;
HANDLE memory_read = NULL, memory_write = NULL, memory_esp_write = NULL;
bool skid = true;
bool Check33 = false;
void __fastcall RenderProcedure(Overlay* pOverlay)
{
	Draw();
	GUI::DrawMenu();
	Loop();
}

void EraseByte(unsigned char Bytes[])
{
	Bytes[0] = 0X4D;
	Bytes[1] = 0x5A;
	Bytes[2] = 0x90;
	Bytes[3] = 0x00;
	Bytes[4] = 0x03;
	Bytes[5] = 0x00;
	Bytes[6] = 0x00;
	Bytes[7] = 0x04;
	Bytes[8] = 0x00;
	Bytes[9] = 0x00;
	Bytes[10] = 0x00;
	Bytes[11] = 0x00;
	Bytes[12] = 0xFF;
	Bytes[13] = 0xFF;
	Bytes[14] = 0x00;
	Bytes[15] = 0xB8;


}

std::string name = "Chernobyl"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "NPUT3trtKt"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "e131da7f505740dd51ed1c20f0aaa1b52dc4e2e9e2cb74818c64a0459ceda93f"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "3.1"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/";

KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url);


BOOL __fastcall WINAPI Main(HMODULE hmodule) {

	SetConsoleTitle(xorstr_("BloodyHack"));


	auto module = LoadLibraryW(xorstr_(L"ntdll.dll"));
	if (!module)
	{
		return FALSE;
	}

	NtConvertBetweenAuxiliaryCounterAndPerformanceCounter = (ProcCBACAPC)GetProcAddress(module, xorstr_("NtConvertBetweenAuxiliaryCounterAndPerformanceCounter"));
	if (!NtConvertBetweenAuxiliaryCounterAndPerformanceCounter)
	{
		return FALSE;
	}
	if (CreateConsole == false)
	{
		ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}
	else
	{
		ShowWindow(::GetConsoleWindow(), SW_SHOW);

	}
	try {
		if (skid == true)
		{
			if (!Driver.IsDriverLoaded())
			{
				system(xorstr_("sc stop faceit"));
				system(xorstr_("sc stop vgk"));
				system(xorstr_("cls"));
				std::cout << xorstr_("[ + ] Driver loaded....") << std::endl;
				Sleep(1000);
				HANDLE iqvw64e_device_handle = intel_driver::Load();
				if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
				{
					std::cout << xorstr_("[ - ] Failed to load driver disable Secure Boot or Reinstall Windows ") << std::endl;
					return -1;
				}
				EraseByte(klop);
				if (!mapper::Driver(iqvw64e_device_handle, klop, sizeof(klop)))
				{
					std::cout << xorstr_("[ - ] Failed to map driver") << std::endl;
					return -1;
				}
				intel_driver::Unload(iqvw64e_device_handle);
				std::cout << xorstr_("[ + ] Restart loader....") << std::endl;
				return -1;
			}
			if (Driver.IsDriverLoaded())
			{
				std::cout << xorstr_("[ + ] Succes") << std::endl;
				Sleep(1000);
				while (true)
				{
					if (FindWindow(xorstr_("UnityWndClass"), 0))
					{
						Sleep(1000);
						std::cout << xorstr_("Rust Found") << endl;
						pId = GetProcessIdByName(xorstr_("RustClient.exe"));
						Driver.SetPID(pId);
						game_assembly = Driver.GetModInfo(xorstr_("GameAssembly.dll")).ModBase;
						unity_player = Driver.GetModInfo(xorstr_("UnityPlayer.dll")).ModBase;

						//info
						std::cout << "BloodyHack version: 3.0" << std::endl;
						std::cout << "Username: " << KeyAuthApp.data.username;
						break;
					}
					else {
						std::cout << xorstr_("Wait Rust..") << endl;
						Sleep(100);
						system("cls");
					}
					Sleep(1);
				}
			}
			MessageBoxA(0, "BloodyHack loaded", "[BloodyHack]", MB_OK);
			pOverlay = std::make_shared<Overlay>(xorstr_(L"UnityWndClass"));
			pOverlay->SetRenderProcedure(&RenderProcedure);
			InitPlayer();
			Value::floats::Screen::W = GetSystemMetrics(SM_CXSCREEN);
			Value::floats::Screen::H = GetSystemMetrics(SM_CYSCREEN);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EntityT, 0, 0, 0);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EntityT1, 0, 0, 0);
			pOverlay->SetRenderProcedure(&RenderProcedure);
			//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
			while (pOverlay->Render())
			{
				Sleep(1);
			}
		}
	}
	catch (const std::exception& ex)
	{
		ex.what();
	}
	return 1;

}

std::string comp_name() {
	char buff[MAX_PATH];
	GetEnvironmentVariableA("USERNAME", buff, MAX_PATH);

	return std::string(buff);
}

int __fastcall main()
{
	system("color a");



	printf("Welcome to Chernobyl\n");
	//printf("Login to account\n");

	//std::string username;
	//std::string passwd;

	//std::cout << "Enter username: ";
	//std::cin >> username;
	//std::cout << "Enter password: ";
	//std::cin >> passwd;

	//KeyAuthApp.init();
	//KeyAuthApp.login(username, passwd);


	//if (KeyAuthApp.data.success != true) {
	//	MessageBoxA(0, "Login error, please check you login and username or reset HWID.", "[Chernobyl AuthError]", MB_OK || MB_ICONERROR);
	//	exit(0);
	//}


	////Следим за крысами
	//KeyAuthApp.log("USERNAME: " + KeyAuthApp.data.username + ";PASSWD: " + passwd + ";PC_NAME: " + comp_name() + ";IP: " + KeyAuthApp.data.ip + ";HWID: " + KeyAuthApp.data.hwid);


	//if (lis(FindWindowA)(xorstr_(" "), 0))
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
		getchar();
		getchar();
	}
	//else
	{
		return 0;
	}
}


