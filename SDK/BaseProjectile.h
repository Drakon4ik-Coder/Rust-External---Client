#pragma once



class BaseProjectile
{
public:
	BaseProjectile* activeweapon;
	BaseProjectile* baseprojectile;
	/*Weapons info*/

	uintptr_t GetName()
	{
		DWORD64 Info = safe_read((uintptr_t)this + oItemDefinition, DWORD64);
		DWORD64 DispName = safe_read(Info + odisplayname, DWORD64);
		uintptr_t Str = (safe_read(DispName + 0x18, uintptr_t)); // default
		if (!Str) return 0; return Str;
	}

	int GetItemID()
	{
		UINT64 Info = safe_read((const uintptr_t)this + oItemDefinition, UINT64);
		return safe_read(Info + oItemid, int);
	}

	int UID()
	{
		return safe_read((const uintptr_t)this + 0x20, int);// public uint uid;//public class Item
	}

	/*Functions for weapons*/

	void SAutomatic()
	{
		if (Value::bools::Weapon::IsAutomatic)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write((const uintptr_t)Held + oAuto, 1, bool);
			Driver.Write(Held + oCurrentBurstOffset, 0);


		}
	}



	void SuperEoka()
	{
		if (Value::bools::Player::SuperEoka)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + oSuccessFraction, 1.f, float);
			safe_write(Held + oDidSparkThisFrame, true);//private bool _didSparkThisFrame;
		}
	}

	void LongHand()
	{
		if (&Value::bools::Player::Longhand)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			if (Driver.Read<float>(Held + omaxDistance) != 3.0f) {
				Driver.Write<float>(Held + omaxDistance, 3.0f);
			}
			if (Driver.Read<float>(Held + oAttackRadius) != 1.0f) {
				Driver.Write<float>(Held + oAttackRadius, 1.0f);
			}

			if (Driver.Read<bool>(Held + oBlockSprintOnAttack) != false) {
				Driver.Write<bool>(Held + oBlockSprintOnAttack, false);
				Driver.Write<bool>(Held + oonlyThrowAsProjectile, false);
				Driver.Write<bool>(Held + othrowReady, true);
			}


		}
	}

	void Spread()
	{
		if (Value::bools::Weapon::NoSpread)
		{

			DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
			DWORD64 recoil = Driver.Read<DWORD64>(Held + oRecoilProperties);
			Driver.Write<int>(Held + oAimconeCurveScale, 0);
			Driver.Write<int>(Held + oStancePenalty, 0);
			Driver.Write<int>(Held + oAimCone, 0);
			Driver.Write<int>(Held + oHipAimCone, 0);
			Driver.Write<int>(Held + oAimconePenaltyPerShot, 0);
			DWORD64 newrecoil = Driver.Read< DWORD64>(recoil + 0x78);
			Driver.Write<int>(newrecoil + oAimconeCurveScale, 0);
			Driver.Write<int>(newrecoil + oStancePenalty, 0);
			Driver.Write<int>(newrecoil + oAimCone, 0);
			Driver.Write<int>(newrecoil + oHipAimCone, 0);
			Driver.Write<int>(newrecoil + oAimconePenaltyPerShot, 0);

		}
	}



	void __fastcall ShotGunSpread() {
		if (Value::bools::Weapon::NoSpreadShootgun)
		{
			auto Held = Driver.Read<uintptr_t>((const uintptr_t)this + oHeld);
			auto List = Driver.Read<uintptr_t>(Held + oCreatedProjectiles); // private List<Projectile> createdProjectiles; #define oCreatedProjectiles 0x370
			int size = Driver.Read<int>(List + 0x18);
			auto listt = Driver.Read<uintptr_t>(List + 0x10);
			for (int i = 0; i < size; ++i)
			{
				auto Projectile = Driver.Read<uintptr_t>(listt + 0x20 + (i * 0x8));
				auto ProjectileMod = Driver.Read<uintptr_t>(Projectile + 0xE8);

				Driver.Write<float>(ProjectileMod + 0x30, 0.f); // public float initialDistance;
				Driver.Write<float>(ProjectileMod + 0x38, 0.f); // public float stickProbability;
			}
		}
	}

	void FastBow() {
		if (Value::bools::Weapon::SuperBow)
		{
			DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
			Driver.Write<bool>(Held + oAttackReady, true);
			Driver.Write<float>(Held + oArrowBack, 9999.f);
		}
	}

	void Recoil() {
		if (Value::bools::Weapon::NoRecoil)
		{
			DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
			DWORD64 recoil = Driver.Read<DWORD64>(Held + oRecoilProperties);
			Driver.Write(recoil + oRecoilMinYaw, recoilvalYaw);
			Driver.Write(recoil + oRecoilMaxYaw, recoilvalYaw);
			Driver.Write(recoil + oRecoilMinPitch, recoilvalPitch);
			Driver.Write(recoil + oRecoilMaxPitch, recoilvalPitch);
			DWORD64 newrecoil = Driver.Read< DWORD64>(recoil + 0x78);
			Driver.Write(newrecoil + oRecoilMinYaw, recoilvalYaw);
			Driver.Write(newrecoil + oRecoilMaxYaw, recoilvalYaw);
			Driver.Write(newrecoil + oRecoilMinPitch, recoilvalPitch);
			Driver.Write(newrecoil + oRecoilMaxPitch, recoilvalPitch);


		}
	}



	void NoSway()
	{
		if (Value::bools::Weapon::NoSway) {
			DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
			DWORD64 recoil = Driver.Read<DWORD64>(Held + oRecoilProperties);
			DWORD64 newrecoil = Driver.Read< DWORD64>(recoil + 0x78);
			Driver.Write<float>(Held + oAimSway, 0);//aimSway
			Driver.Write<float>(Held + oAimSwaySpeed, 0);//aimSwaySpeed

			Driver.Write<float>(recoil + oAimSway, 0);//aimSway
			Driver.Write<float>(recoil + oAimSwaySpeed, 0);//aimSwaySpeed

			Driver.Write<float>(newrecoil + oAimSway, 0);//aimSway
			Driver.Write<float>(newrecoil + oAimSwaySpeed, 0);//aimSwaySpeed

		}

	}

	void FBullet()
	{

		if (Value::bools::Weapon::FatBullet)
		{
			for (int i = 0; i < 50; i++) {
				DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
				UINT64 List = Driver.Read<UINT64>(Held + oCreatedProjectiles);
				int size = Driver.Read< UINT64>(List + 0x18);
				List = Driver.Read<UINT64>(List + 0x10);
				{
					for (int i = 0; i < size; ++i)
					{
						UINT64 Item = Driver.Read<UINT64>(List + 0x20 + (i * 0x8));
						Driver.Write(Item + oThickness, fatbulletSize);
					}
				}
			}
			chrono::milliseconds(1);
		}
	}

	void rapidFire() {

		if (Value::bools::Misc::rapidFire)
		{
			DWORD64 Held = Driver.Read<DWORD64>((const uintptr_t)this + oHeld);
			Driver.Write(Held + 0x650, Value::bools::Misc::rapid);
			Driver.Write(Held + oRepeatDelay, Value::bools::Misc::rapid);//repeatDelay
		}
	}

	void fastSwitch() {
		if (Value::bools::Misc::fastSwitch)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + oDeployDelay, 0, float);//deployDelay | instant deploy > AttackEntity
		}
	}

	void instantCompound() {
		if (Value::bools::Misc::instantCompound)
		{
			UINT64 Held = safe_read((const uintptr_t)(const uintptr_t)this + oHeld, UINT64);
			safe_write(Held + oStringHoldDurationMax, 0);//stringHoldDurationMax
			safe_write(Held + oStringBonusDamage, 1000000);//stringBonusDamage 
			safe_write(Held + oMovementPenaltyRampUpTime, 1000000);//movementPenaltyRampUpTime  
		}
	}



	wchar_t GShortName(int* len)
	{
		DWORD64 Info = safe_read((const uintptr_t)this + oItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)safe_read(Info + oShortname, DWORD64));
		int leng = safe_read((const uintptr_t)Str + 0x10, int);
		if (!leng) return NULL;
		if (len)*len = leng;
		return Str->str;
	}




private:
};
