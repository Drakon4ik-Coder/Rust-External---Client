#pragma once
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

extern RGBA;
using namespace std;
float Range = 200;
float recoilvalYaw = 0;
float recoilvalPitch = 0;
float fatbulletSize = 1.5;
bool CrossHair = false;
bool CustomTime = false;
int FlyHackButon = 0;
bool FlyOn = false;
float TimeFloat = 12;
float gravityFly = 0;
float light = 1;
bool WaterMark = true;
namespace Value {
    float posx = 1670;
    float posy = 0;
    float NeckWidgth = 0.f;
    float NeckLength = 0.f;
    float NeckWeigth = 0.f;
    float FlyMax = 0.f;
    bool EU = true;
    bool RU = false;
    int max = 2;
    float menux = 0;
    float menuy = 0;
    namespace bools {
        namespace Aim {
            bool reloadcooldown = false;
            bool Enable, VisibleCheck, IgnoreTeam, TargetLine, Fov, Smooth, IgnoreSleepers, RCS, range, FovFilled, teamignoree, Selection;
            bool PSilent, ignoreNpc;
            int AimKey = 0x58;
            int aimbotHitbox = 0;
            const char* listbox_items[] = { "Head", "Neck", "Pevlis", "Foot", "Penis"};
        }
        namespace Player {
            bool MapHard = false;
            bool CustomFov;
            bool Zoom = false;
            bool Longhand = false;
            bool SuperEoka = false;
            bool CullingDebugEsp = false;
            namespace PlayerWalk {
                bool Spiderman, FakeAdmin, ChangeGravity, InfinityJump, MinicopterFire, Chams, DebugCamera, FakeLag, SpinBot;//DebugBypass AntiAim InfinityJump
                float FlyMax = 0.f;
                bool jumpshoot;
                float FastBulletSpeed = 1.4775f;
                bool NightMode = false;
               
            }
            namespace PlayerModel {
            }
        }

        namespace Visuals {
            namespace PlayerPanel {
                bool Enable, Name, HP, Weapons;
              
            }
            namespace ESP {
                bool Enable, Player, NPC, IgnoreSleeper, Corpse, Backpack, IgnoreBot, Line, PlayerInfo;
                bool Name, Box, Distance, SteamID, Health, Weapon, BoxRect, CornerBox, Skeleton;
                int ToDistance = 200;
            }
            namespace World {
                namespace Items {

                    bool Stash, Hemp, AirDrop, CH47, Minicopter, Patrol, Cupboard, guntrap, bradley_crate, crate_basic, crate_normal2, horse, Bear, Boar, DroppedItem = true, Diesel, Winter;
                    bool Workbench1, Workbench2, Workbench3, crate_elite, CrateTools, scrapheli, BearTrap, autoturret, crate_normal;
                    namespace Ore {
                        bool Stone, Iron, Sulfur;
                    }
                }
                bool AlwaysDay, NightModeup, FixAmbient;

            }
            namespace Radar {
                bool Enable, Sleeper;
            }
        }
        namespace Misc {

            
            bool Kastryla = false;
            bool DebugCamera = true;
            bool killhack = false;
            bool chams = false;
            bool shootinair = false;
            bool Crosshair = false;
            int killhackkey = 0;
            int FlyHackkey = 0;
            bool WalkOnWater = false;
            bool alwayshoot = false;
            bool FixCamera = false;
            bool FlyHack = true;
            int thirdPers = 0;
            bool Person = false;
            bool PatchDebug = false;
            bool rapidFire = false;
            float rapid = 0;
            bool fastSwitch = false;
            bool instantCompound = false;
            bool crosshairScoped = false;
            int CrosshairLength = 17;
            int CrosshairGap = 6;
            int CrosshairThickness = 1;
            bool SpeedHack = false;
           
        }
        namespace Weapon {
            bool IsAutomatic, NoSpread, NoSway, NoRecoil, FatBullet, SuperBow, NoSpreadShootgun, RecoilValue;
        }
    }
    namespace floats {
        float Time = 12;
        bool TimeOn = false;
        namespace Aim {
            int Distance = 400;
            int Fov = 50;
            float Smooth = 5;
        }
        namespace Screen {
            float H;
            float W;
            int CrosshairLength = 17;
            int CrosshairGap = 6;
            int CrosshairThickness = 1;

        }
        namespace Player {
            bool Timer = false;
            float CustomFov = 90;
            float CustomAspect = 90;
            float Gravity = 2;
            float Zoomvalue = 20.f;
            int zoomKey = 0;
            int RCSyaw = 0;
            bool LongNeck = false;
            bool Lefts = false;
            int hangingg = 0;
            float timervalue = 2.1;
            bool Rigts = false;
            int LongNeckKey = 0;
            int Left = 0;
            int Right = 0;
            int RCSpitch = 0;
            int DebugKey = 0;

           
        }
        namespace Visuals {
            namespace World {
                int LimitDistance = 100;
                int LimitDistance2 = 2000;
                int Time = 9;
            }
            namespace Radar {
                int Radius = 100;
                int Distance = 100;
            }
        }
    }
    namespace Colors {
        namespace Aim {
            float Fov[] = { 0.7, 0.7, 0.7, 1 };
            float TargetLine[] = { 0.7, 0.7, 0.7, 1 };
        }
        namespace Visuals {
            namespace ESP {
                float CornerBox[] = { 0.7, 0.7, 0.7, 1 };
                float Weapon[] = { 0.7, 0.7, 0.7, 1 };
                float Box[] = { 0.7, 0.7, 0.7, 1 };
                float BoxRect[] = { 0.7, 0.7, 0.7, 1 };
                float Name[] = { 0.7, 0.7, 0.7, 1 };
                float Health[] = { 0.7, 0.7, 0.7, 1 };
                float Distance[] = { 0.7, 0.7, 0.7, 1 };
                float Skeleton[] = { 0.7, 0.7, 0.7, 1 };
                float ColorRed[] = { 1, 0 , 0, 1 };
            }
            namespace World {
                float Stash[] = { 0, 0.25 , 1, 1 };
                float Hemp[] = { 0, 1 , 0, 1 };
                float AirDrop[] = { 0.4, 0 ,1, 1 };
                float WaterMark[] = { 255, 255 ,255, 255 };
                float RectMark[] = { 0.4, 0 ,1, 1 };
                float CH47[] = { 1, 0 , 0, 1 };
                float Minicopter[] = { 0.45, 1 ,0, 1 };
                float Patrol[] = { 0, 1 ,1, 1 };
                float Corpse[] = { 0.45, 1 ,0, 1 };
                float Backpack[] = { 0, 1 ,1, 1 };
                float Cupboard[] = { 0.7, 0.7, 0.7, 1 };
                float Diesel[] = { 0.7, 0.7, 0.7, 1 };
                float guntrap[] = { 0.7, 0.7, 0.7, 1 };
                float bradley_crate[] = { 0.7, 0.7, 0.7, 1 };
                float crate_basic[] = { 0.7, 0.7, 0.7, 1 };
                float crate_winter[] = { 0.7, 0.7, 0.7, 1 };
                float Workbench1[] = { 0.7, 0.7, 0.7, 1 };
                float Workbench2[] = { 0.7, 0.7, 0.7, 1 };
                float Workbench3[] = { 0.7, 0.7, 0.7, 1 };
                float BearTrap[] = { 0.7, 0.7, 0.7, 1 };
                float crate_elite[] = { 0.7, 0.7, 0.7, 1 };
                float CrateTools[] = { 0.7, 0.7, 0.7, 1 };
                float scrapheli[] = { 0.7, 0.7, 0.7, 1 };
                float autoturret[] = { 0.7, 0.7, 0.7, 1 };
                float crate_normal[] = { 0.7, 0.7, 0.7, 1 };
                float crate_normal2[] = { 0.7, 0.7, 0.7, 1 };
                float horse[] = { 0.7, 0.7, 0.7, 1 };
                float Bear[] = { 0.7, 0.7, 0.7, 1 };
                float Boar[] = { 0.7, 0.7, 0.7, 1 };
                float drawColor_crosshair[] = { 0.7, 0.7, 0.7, 1 };
                namespace Ore {
                    float Stone[] = { 0.86, 0.86 , 0.86, 1 };
                    float Iron[] = { 0.86, 0.86 , 0.86, 1 };
                    float Sulfur[] = { 1, 1 , 0, 1 };
                }
            }
        }
    }
}

using namespace Value::bools::Aim;
using namespace Value::bools::Player;
using namespace Value::bools::Visuals;
using namespace Value::bools::Visuals::World;
using namespace Value::bools::Visuals::ESP;

class Config {

public:
    Config(std::string name) {
        this->path = name; 
        this->input = std::ifstream(this->path); 
    }

    void open() {
        this->outputstream = std::ofstream(this->path); 
    }

    void close() {
        this->outputstream.close(); 
    }

    template <typename tp>
    tp set(std::string name, tp value) {
        outputstream << name << " " << value << std::endl; 
        return true;
    }
    
   

   float setint(std::string name, float peremannaya) {
        outputstream << name << " " << peremannaya << std::endl;
        return peremannaya;
   }


    template <class tg>
    tg get(std::string name) {
        this->input.close(); //Close Input
        this->input = std::ifstream(this->path); 
        std::vector<std::string>stack;
        std::string buffer;
        while (this->input >> buffer) {
            stack.push_back(buffer); 
        }
        for (int i = 0; i < stack.size(); i++) {
            if (stack.at(i) == name) {

                return atof(stack.at(i + 1).c_str()); 
            }
        }
    }
    std::string path;
    std::ifstream input;
    std::ofstream outputstream;
};




void set_config(Config* config) {
    config->open();
    //Aim
    config->set<bool>(xorstr_("AimBot"), Value::bools::Aim::Enable);
    config->set<bool>(xorstr_("Psilent"), PSilent);
    config->set<bool>(xorstr_("FovAim"), Fov);
    config->set<bool>(xorstr_("Smoothbool"), Smooth);
    config->set<bool>(xorstr_("Range"), range);
    config->set<bool>(xorstr_("SleepIgnore"), IgnoreSleepers);
    config->set<bool>(xorstr_("NpcIgnore"), ignoreNpc);
    config->set<bool>(xorstr_("VisibleCheck"), VisibleCheck);
    config->set<bool>(xorstr_("Selection"), Selection);
    //ESP
    config->set<bool>(xorstr_("Viual"), Value::bools::Visuals::ESP::Enable);
    config->set<bool>(xorstr_("Name"), Name);
    config->set<bool>(xorstr_("Box"), Box);
    config->set<bool>(xorstr_("BoxRect"), BoxRect);
    config->set<bool>(xorstr_("CornerBox"), CornerBox);
    config->set<bool>(xorstr_("Health"), Health);
    config->set<bool>(xorstr_("Distance"), Distance);
    config->set<bool>(xorstr_("IgnoreSleeperEsp"), Value::bools::Visuals::ESP::IgnoreSleeper);
    config->set<bool>(xorstr_("IgnoreBotEsp"), Value::bools::Visuals::ESP::IgnoreBot);
    config->set<bool>(xorstr_("Weapon"), Value::bools::Visuals::ESP::Weapon);
    config->set<bool>(xorstr_("Skeleton"), Value::bools::Visuals::ESP::Skeleton);
    config->set<bool>(xorstr_("BackPack"), Backpack);
    config->set<bool>(xorstr_("Corpse"), Corpse);
    //MiscEsp
    config->set<bool>(xorstr_("Stash"), Value::bools::Visuals::World::Items::Stash);
    config->set<bool>(xorstr_("Hemp"), Value::bools::Visuals::World::Items::Hemp);
    config->set<bool>(xorstr_("AirDrop"), Value::bools::Visuals::World::Items::AirDrop);
    config->set<bool>(xorstr_("Stone"), Value::bools::Visuals::World::Items::Ore::Stone);
    config->set<bool>(xorstr_("Sulfure"), Value::bools::Visuals::World::Items::Ore::Sulfur);
    config->set<bool>(xorstr_("Iron"), Value::bools::Visuals::World::Items::Ore::Iron);
    config->set<bool>(xorstr_("MiniCopter"), Value::bools::Visuals::World::Items::Minicopter);
    config->set<bool>(xorstr_("Patrol"), Value::bools::Visuals::World::Items::Patrol);
    config->set<bool>(xorstr_("CH47"), Value::bools::Visuals::World::Items::CH47);
    config->set<bool>(xorstr_("ScrapHeli"), Value::bools::Visuals::World::Items::scrapheli);
    config->set<bool>(xorstr_("Horse"), Value::bools::Visuals::World::Items::horse);
    config->set<bool>(xorstr_("Bear"), Value::bools::Visuals::World::Items::Bear);
    config->set<bool>(xorstr_("Boar"), Value::bools::Visuals::World::Items::Boar);
    config->set<bool>(xorstr_("CupBoard"), Value::bools::Visuals::World::Items::Cupboard);
    config->set<bool>(xorstr_("BearTrap"), Value::bools::Visuals::World::Items::BearTrap);
    config->set<bool>(xorstr_("AutoTurret"), Value::bools::Visuals::World::Items::autoturret);
    config->set<bool>(xorstr_("Guntrap"), Value::bools::Visuals::World::Items::guntrap);
    config->set<bool>(xorstr_("CreateBasic"), Value::bools::Visuals::World::Items::crate_basic);
    config->set<bool>(xorstr_("CreateMilitary"), Value::bools::Visuals::World::Items::crate_normal);
    config->set<bool>(xorstr_("CrateTools"), Value::bools::Visuals::World::Items::CrateTools);
    config->set<bool>(xorstr_("CrateNormal"), Value::bools::Visuals::World::Items::crate_normal2);
    config->set<bool>(xorstr_("CrateBradley"), Value::bools::Visuals::World::Items::bradley_crate);
    config->set<bool>(xorstr_("CrateElite"), Value::bools::Visuals::World::Items::crate_elite);
    config->set<bool>(xorstr_("Workbench1"), Value::bools::Visuals::World::Items::Workbench1);
    config->set<bool>(xorstr_("Workbench2"), Value::bools::Visuals::World::Items::Workbench2);
    config->set<bool>(xorstr_("Workbench3"), Value::bools::Visuals::World::Items::Workbench3);
    //Misc
    config->set<bool>(xorstr_("Zoom"), Value::bools::Player::Zoom);
    config->set<bool>(xorstr_("CustomFov"), Value::bools::Player::CustomFov);
    config->set<bool>(xorstr_("Spider"), Value::bools::Player::PlayerWalk::Spiderman);
    config->set<bool>(xorstr_("jumpshoot"), Value::bools::Player::PlayerWalk::jumpshoot);
    config->set<bool>(xorstr_("FakeAdmin"), Value::bools::Player::PlayerWalk::FakeAdmin);
    config->set<bool>(xorstr_("FakeLag"), Value::bools::Player::PlayerWalk::FakeLag);
    config->set<bool>(xorstr_("ChangeGravity"), Value::bools::Player::PlayerWalk::ChangeGravity);
    config->set<bool>(xorstr_("SpinBot"), Value::bools::Player::PlayerWalk::SpinBot);
    config->set<bool>(xorstr_("Crosshair"), Value::bools::Misc::Crosshair);
    config->set<bool>(xorstr_("fastSwitch"), Value::bools::Misc::fastSwitch);
    config->set<bool>(xorstr_("FlyHack"), FlyOn);
    config->set<bool>(xorstr_("killhack"), Value::bools::Misc::killhack);
    config->set<bool>(xorstr_("WalkOnWater"), Value::bools::Misc::WalkOnWater);
    config->set<bool>(xorstr_("PatchDebug"), Value::bools::Misc::PatchDebug);
    config->set<bool>(xorstr_("FlyHack"), Value::bools::Misc::FlyHack);
    config->set<bool>(xorstr_("Kastryla"), Value::bools::Misc::Kastryla);
    config->set<bool>(xorstr_("InfinityJump"), Value::bools::Player::PlayerWalk::InfinityJump);
    config->set<bool>(xorstr_("CustomTime"), CustomTime);
    config->set<bool>(xorstr_("LongNeck"), Value::floats::Player::LongNeck);
    config->set<bool>(xorstr_("Left"), Value::floats::Player::Lefts);
    config->set<bool>(xorstr_("Right"), Value::floats::Player::Rigts);
    //Weapon
    config->set<bool>(xorstr_("Norecoil"), Value::bools::Weapon::NoRecoil);
    config->set<bool>(xorstr_("NoSpread"), Value::bools::Weapon::NoSpread);
    config->set<bool>(xorstr_("NoSway"), Value::bools::Weapon::NoSway);
    config->set<bool>(xorstr_("Automatic"), Value::bools::Weapon::IsAutomatic);
    config->set<bool>(xorstr_("FatBullet"), Value::bools::Weapon::FatBullet);
    config->set<bool>(xorstr_("RapidFire"), Value::bools::Misc::rapidFire);
    config->set<bool>(xorstr_("InstantCompound"), Value::bools::Misc::instantCompound);
    config->set<bool>(xorstr_("SuperEoka"), Value::bools::Player::SuperEoka);
    config->set<bool>(xorstr_("SuperBow"), Value::bools::Weapon::SuperBow);
    config->set<bool>(xorstr_("LongHand"), Value::bools ::Player::Longhand);
    //Int & Value 
    config->setint(xorstr_("AimBotFov"), Value::floats::Aim::Fov);
    config->setint(xorstr_("HitBox"), Value::bools::Aim::aimbotHitbox);
    config->setint(xorstr_("AimKey"), Value::bools::Aim::AimKey);
    config->setint(xorstr_("AimSmooth"), Value::floats::Aim::Smooth);
    config->setint(xorstr_("AimRange"), Range);
    config->setint(xorstr_("VisualDistance"), Value::bools::Visuals::ESP::ToDistance);
    config->setint(xorstr_("FlyHackButon"), FlyHackButon);
    config->setint(xorstr_("gravityFly"), gravityFly);
    config->setint(xorstr_("CrosshairGap"), Value::floats::Screen::CrosshairGap);
    config->setint(xorstr_("LongNeckKey"), Value::floats::Player::LongNeckKey);
    config->setint(xorstr_("RightKey"), Value::floats::Player::Right);
    config->setint(xorstr_("LeftKey"), Value::floats::Player::Left); 
    config->setint(xorstr_("FloatCustom"), Value::floats::Player::CustomFov);
    config->setint(xorstr_("zoomKey"), Value::floats::Player::zoomKey); 
    config->setint(xorstr_("killhackkey"), Value::bools::Misc::killhackkey);
    config->setint(xorstr_("TimeFloat"), TimeFloat);
    config->setint(xorstr_("LimitDistance"), Value::floats::Visuals::World::LimitDistance);
    config->setint(xorstr_("rapidfloat"), Value::bools::Misc::rapid);
    config->setint(xorstr_("recoilvalPitch"), recoilvalPitch);
    config->setint(xorstr_("recoilvalYaw"), recoilvalYaw);
    config->close();
}

void read_config(Config* config) {
    //Aim
    if (config->get<bool>(xorstr_("AimBot"))) {
        Value::bools::Aim::Enable = true;
        Value::bools::Aim::AimKey = config->get<int>(xorstr_("AimKey"));
        Value::bools::Aim::aimbotHitbox = config->get<int>(xorstr_("HitBox"));
    }
    if (config->get<bool>(xorstr_("Psilent")))
        PSilent = true;
    if (config->get<bool>(xorstr_("FovAim"))) {
        Fov = true;
        Value::floats::Aim::Fov = config->get<int>(xorstr_("AimBotFov"));
    }
    if (config->get<bool>(xorstr_("Smoothbool"))) {
        Smooth = true;
        Value::floats::Aim::Smooth = config->get<int>(xorstr_("AimSmooth"));
    }
    if (config->get<bool>(xorstr_("Range"))) {
        range = true;
        Range = config->get<int>(xorstr_("AimRange"));
    }
    if (config->get<bool>(xorstr_("SleepIgnore")))
        IgnoreSleepers = true;
    if (config->get<bool>(xorstr_("NpcIgnore")))
        ignoreNpc = true;
    if (config->get<bool>(xorstr_("VisibleCheck")))
        VisibleCheck = true;
    if (config->get<bool>(xorstr_("Selection")))
        Selection = true;
    //ESP 
    if (config->get<bool>(xorstr_("Viual"))) {
        Value::bools::Visuals::ESP::Enable = true;
        Value::bools::Visuals::ESP::ToDistance = config->get<int>(xorstr_("VisualDistance"));
        Value::floats::Visuals::World::LimitDistance = config->get<int>(xorstr_("LimitDistance"));
    }
    if (config->get<bool>(xorstr_("Name")))
        Name = true;
    if (config->get<bool>(xorstr_("Box")))
        Box = true;
    if (config->get<bool>(xorstr_("BoxRect")))
        BoxRect = true;
    if (config->get<bool>(xorstr_("CornerBox")))
        CornerBox = true;
    if (config->get<bool>(xorstr_("Health")))
        Health = true;
    if (config->get<bool>(xorstr_("Distance")))
        Distance = true;
    if (config->get<bool>(xorstr_("IgnoreSleeperEsp")))
        Value::bools::Visuals::ESP::IgnoreSleeper = true;
    if (config->get<bool>(xorstr_("IgnoreBotEsp")))
        Value::bools::Visuals::ESP::IgnoreBot = true;
    if (config->get<bool>(xorstr_("Weapon")))
        Value::bools::Visuals::ESP::Weapon = true;
    if (config->get<bool>(xorstr_("Skeleton")))
        Value::bools::Visuals::ESP::Skeleton = true;
    if (config->get<bool>(xorstr_("BackPack")))
        Backpack = true;
    if (config->get<bool>(xorstr_("Corpse")))
        Corpse = true;
    //MiscEsp
    if (config->get<bool>(xorstr_("Stash")))
        Value::bools::Visuals::World::Items::Stash = true;
    if (config->get<bool>(xorstr_("Hemp")))
        Value::bools::Visuals::World::Items::Hemp = true;
    if (config->get<bool>(xorstr_("AirDrop")))
        Value::bools::Visuals::World::Items::AirDrop = true;
    if (config->get<bool>(xorstr_("Stone")))
        Value::bools::Visuals::World::Items::Ore::Stone = true;
    if (config->get<bool>(xorstr_("Sulfure")))
        Value::bools::Visuals::World::Items::Ore::Sulfur = true;
    if (config->get<bool>(xorstr_("Iron")))
        Value::bools::Visuals::World::Items::Ore::Iron = true;
    if (config->get<bool>(xorstr_("MiniCopter")))
        Value::bools::Visuals::World::Items::Minicopter = true;
    if (config->get<bool>(xorstr_("Patrol")))
        Value::bools::Visuals::World::Items::Patrol = true;
    if (config->get<bool>(xorstr_("CH47")))
        Value::bools::Visuals::World::Items::CH47 = true;
    if (config->get<bool>(xorstr_("ScrapHeli")))
        Value::bools::Visuals::World::Items::scrapheli = true;
    if (config->get<bool>(xorstr_("Horse")))
        Value::bools::Visuals::World::Items::horse = true;
    if (config->get<bool>(xorstr_("Bear")))
        Value::bools::Visuals::World::Items::Bear = true;
    if (config->get<bool>(xorstr_("Boar")))
        Value::bools::Visuals::World::Items::Boar = true;
    if (config->get<bool>(xorstr_("CupBoard")))
        Value::bools::Visuals::World::Items::Cupboard = true;
    if (config->get<bool>(xorstr_("BearTrap")))
        Value::bools::Visuals::World::Items::BearTrap = true;
    if (config->get<bool>(xorstr_("AutoTurret")))
        Value::bools::Visuals::World::Items::autoturret = true;
    if (config->get<bool>(xorstr_("Guntrap")))
        Value::bools::Visuals::World::Items::guntrap = true;
    if (config->get<bool>(xorstr_("CreateBasic")))
        Value::bools::Visuals::World::Items::crate_basic = true;
    if (config->get<bool>(xorstr_("CreateMilitary")))
        Value::bools::Visuals::World::Items::crate_normal = true;
    if (config->get<bool>(xorstr_("CrateTools")))
        Value::bools::Visuals::World::Items::CrateTools = true;
    if (config->get<bool>(xorstr_("CrateNormal")))
        Value::bools::Visuals::World::Items::crate_normal2 = true;
    if (config->get<bool>(xorstr_("CrateBradley")))
        Value::bools::Visuals::World::Items::bradley_crate = true;
    if (config->get<bool>(xorstr_("CrateElite")))
        Value::bools::Visuals::World::Items::crate_elite = true;
    if (config->get<bool>(xorstr_("Workbench1")))
        Value::bools::Visuals::World::Items::Workbench1 = true;
    if (config->get<bool>(xorstr_("Workbench2")))
        Value::bools::Visuals::World::Items::Workbench2 = true;
    if (config->get<bool>(xorstr_("Workbench3")))
        Value::bools::Visuals::World::Items::Workbench3 = true;
    //Misc
    if (config->get<bool>(xorstr_("Zoom"))) {
        Value::bools::Player::Zoom = true;
        Value::floats::Player::zoomKey = config->get<int>(xorstr_("zoomKey"));
    }
    if (config->get<bool>(xorstr_("CustomFov"))) {
        Value::bools::Player::CustomFov = true;
        Value::floats::Player::CustomFov = config->get<int>(xorstr_("FloatCustom"));
    }
    if (config->get<bool>(xorstr_("Spider")))
        Value::bools::Player::PlayerWalk::Spiderman = true;
    if (config->get<bool>(xorstr_("jumpshoot")))
        Value::bools::Player::PlayerWalk::jumpshoot = true;
    if (config->get<bool>(xorstr_("FakeAdmin")))
        Value::bools::Player::PlayerWalk::FakeAdmin = true;
    if (config->get<bool>(xorstr_("FakeLag")))
        Value::bools::Player::PlayerWalk::FakeLag = true;
    if (config->get<bool>(xorstr_("ChangeGravity")))
        Value::bools::Player::PlayerWalk::ChangeGravity = true;
    if (config->get<bool>(xorstr_("SpinBot")))
        Value::bools::Player::PlayerWalk::SpinBot = true;
    if (config->get<bool>(xorstr_("Crosshair"))) {
        Value::bools::Misc::Crosshair = true;
        Value::floats::Screen::CrosshairGap = config->get<int>(xorstr_("CrosshairGap"));
    }
    if (config->get<bool>(xorstr_("fastSwitch")))
        Value::bools::Misc::fastSwitch = true;
    if (config->get<bool>(xorstr_("FlyHack"))) {
        FlyOn = true;
        FlyHackButon = config->get<int>(xorstr_("FlyHackButon"));
        gravityFly = config->get<int>(xorstr_("gravityFly"));
    }
    if (config->get<bool>(xorstr_("killhack"))) {
        Value::bools::Misc::killhack = true;
        Value::bools::Misc::killhackkey = config->get<int>(xorstr_("killhackkey"));
    }
    if (config->get<bool>(xorstr_("Kastryla")))
        Value::bools::Misc::Kastryla = true;
    if (config->get<bool>(xorstr_("InfinityJump")))
        Value::bools::Player::PlayerWalk::InfinityJump = true;
    if (config->get<bool>(xorstr_("CustomTime"))) {
        CustomTime = true;
        TimeFloat = config->get<int>(xorstr_("TimeFloat"));
    }
    if (config->get<bool>(xorstr_("LongNeck"))) {
        Value::floats::Player::LongNeck = true;
        Value::floats::Player::LongNeckKey = config->get<int>(xorstr_("LongNeckKey"));
    }
    if (config->get<bool>(xorstr_("Left"))) {
        Value::floats::Player::Lefts = true;
        Value::floats::Player::Left = config->get<int>(xorstr_("LeftKey"));
    }
    if (config->get<bool>(xorstr_("Right"))) {
        Value::floats::Player::Rigts = true;
        Value::floats::Player::Right = config->get<int>(xorstr_("RightKey"));
    }
    //Weapon

    if (config->get<bool>(xorstr_("Norecoil"))) {
        Value::bools::Weapon::NoRecoil = true;
        recoilvalPitch = config->get<int>(xorstr_("recoilvalPitch"));
        recoilvalYaw = config->get<int>(xorstr_("recoilvalYaw"));
    }
    if (config->get<bool>(xorstr_("NoSpread")))
        Value::bools::Weapon::NoSpread = true;
    if (config->get<bool>(xorstr_("NoSway")))
        Value::bools::Weapon::NoSway = true;
    if (config->get<bool>(xorstr_("Automatic")))
        Value::bools::Weapon::IsAutomatic = true;
    if (config->get<bool>(xorstr_("FatBullet")))
        Value::bools::Weapon::FatBullet = true;
    if (config->get<bool>(xorstr_("RapidFire"))) {
        Value::bools::Misc::rapidFire = true;
        Value::bools::Misc::rapid = config->get<int>(xorstr_("rapidfloat"));
    }
    if (config->get<bool>(xorstr_("InstantCompound")))
        Value::bools::Misc::instantCompound = true;
    if (config->get<bool>(xorstr_("SuperEoka")))
        Value::bools::Player::SuperEoka = true;
    if (config->get<bool>(xorstr_("SuperBow")))
        Value::bools::Weapon::SuperBow = true;
    if (config->get<bool>(xorstr_("LongHand")))
        Value::bools::Player::Longhand = true;

    

   
}

void DeleteConfig()
{
    remove(xorstr_("C:\\Chernobyl.cfg"));
}