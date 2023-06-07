#pragma once

void Misc()
{
	if (Value::bools::Player::PlayerWalk::Spiderman)
		LocalPlayer.BasePlayer->SpiderMan();

	if (Value::bools::Player::PlayerWalk::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin();

	if (Value::floats::Player::LongNeck) 
		LocalPlayer.BasePlayer->LongNeck();

	if (Value::floats::Player::Timer)
		LocalPlayer.BasePlayer->Timer();
	
	if (Value::bools::Player::PlayerWalk::MinicopterFire) 
		LocalPlayer.BasePlayer->MinicopterShooting();

	if (Value::bools::Misc::PatchDebug)
		LocalPlayer.BasePlayer->PatchDebug();

	if (Value::bools::Misc::killhack && GetAsyncKeyState(Value::bools::Misc::killhackkey))
		LocalPlayer.BasePlayer->KillHack();

	if (Value::bools::Player::PlayerWalk::jumpshoot)
		LocalPlayer.BasePlayer->ShootinJump();

	if (GetAsyncKeyState(Value::bools::Misc::thirdPers))
		LocalPlayer.BasePlayer->thirdperson();

	if (Value::bools::Player::PlayerWalk::FakeLag)
		LocalPlayer.BasePlayer->FakeLag();

	if (Value::bools::Misc::WalkOnWater)
		LocalPlayer.BasePlayer->WalkWater();

	if (Value::bools::Misc::Kastryla)
		LocalPlayer.BasePlayer->NoBlockAiming();

	if (Value::bools::Player::PlayerWalk::ChangeGravity)
		LocalPlayer.BasePlayer->GravituMod();

	if (Value::bools::Player::PlayerWalk::InfinityJump)
		LocalPlayer.BasePlayer->InfinityJump();

	if (Value::bools::Player::PlayerWalk::SpinBot)
		LocalPlayer.BasePlayer->SpinBot();

	if (Value::bools::Player::CustomFov)
		LocalPlayer.BasePlayer->SetFov();

	if (Value::bools::Player::Zoom)
		LocalPlayer.BasePlayer->Zoom();

	if (Value::bools::Player::PlayerWalk::DebugCamera)
		LocalPlayer.BasePlayer->DebugCamera();

	if (FlyOn)
		LocalPlayer.BasePlayer->FlyHack();

}