#include "Overlay.h"
#include "Value.h"
#include <chrono>
#include "AnimationVector.h"
#include <chrono>
#include "xorstr.h"
#include "color.hpp"
float slider_speed = 10.0f;
static int width = 840;
static int height = 620;
static int mastergui = 1;
bool theme = true;
bool checkbox_0 = false, checkbox_1 = false, checkbox_2 = false;
bool checkbox_3 = false, checkbox_4 = false, checkbox_5 = false, checkbox_6 = false;
bool particle = true;

bool active_tab = false;
float accent_color[4] = { 0.80f, 0.80f, 0.80f, 0.80f };
float accent_text[4] = { 26 / 255.f, 28 / 255.f, 30 / 255.f, 255 / 255.f };
int slider_int = 1;
int tab_menu = 0;
int general = tab_menu;
int animation_tab = 255;
int key0, key1;
Config* CFG = new Config(("C:\\BloodyHack.cfg"));

static const char* KeyNames[] = {
    "OFF",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};

void ImGui::Hotkey(int* k, const ImVec2& size_arg)
{
    static bool waitingforkey = false;
    if (waitingforkey == false) {
        if (ImGui::Button(KeyNames[*(int*)k], size_arg))
            waitingforkey = true;
    }
    else if (waitingforkey == true) {
        ImGui::Button("...", size_arg);
        Sleep(20);
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState(Key)) {
                *(int*)k = Key;
                waitingforkey = false;
            }
        }
    }
}

//void InitStyle()
//{
//    ImGuiIO& io = ImGui::GetIO();
//    if (io.Fonts->AddFontFromFileTTF("C:/Users/Professional/Desktop/Fonts/Inter-Medium.ttf", 10.0f) == NULL)
//    {
//        std::cout << "Font error" << std::endl;
//    }
//    std::cout << "Test" << std::endl;
//}

namespace GUI
{
    DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollWithMouse;
	void DrawMenu()
	{
		if (!pOverlay->m_bGuiVisible)
			return;

        //ImGuiStyle& style = ImGui::GetStyle();

		


        ImGui::SetNextWindowSize(ImVec2(867, 608));
		ImGui::Begin(("  "), (bool*)true, window_flags);
        {

            ImVec2 P1, P2;
            ImDrawList* pDrawList;
            const auto& Pos = ImGui::GetWindowPos();
            const auto& pWindowDrawList = ImGui::GetWindowDrawList();
            const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();

            const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();
            auto window_size = ImGui::GetWindowSize();
            pForegroundDrawList->AddText(pop, 35.f, ImVec2(31 + Pos.x, 17 + Pos.y), ImColor(255, 255,255,255), "BloodyHack");


            /*
            if (active_tab) {
                if (animation_tab < 255) {
                    animation_tab += 12 / ImGui::GetIO().Framerate * 90.f;
                }
                else {
                    active_tab = false;
                    general = tab_menu;
                }
            }
            else {
                if (animation_tab > 0) animation_tab -= 12 / ImGui::GetIO().Framerate * 50.f;
            }*/
               
            animation_tab = -4;

            ImGui::SetCursorPos(ImVec2(30, 70));

            ImGui::BeginGroup();
            {
                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 2));

                ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0, 0));
                
               
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tAimbot"), ImVec2(120, 30))) {
                        if (tab_menu != 0) {
                            active_tab = true;
                            tab_menu = 0;
                        }
                    };
                }
               
               

                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tVisual"), ImVec2(120, 30))) {
                        if (tab_menu != 1) {
                            active_tab = true;
                            tab_menu = 1;
                        }
                    };
                }
                
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tMisc Visual"), ImVec2(120, 30))) {
                        if (tab_menu != 3) {
                            active_tab = true;
                            tab_menu = 3;
                        }
                    };
                }
               

               
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tMisc"), ImVec2(120, 30))) {
                        if (tab_menu != 2) {
                            active_tab = true;
                            tab_menu = 2;
                        }
                    };
                }
               
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tWeapon"), ImVec2(120, 30))) {
                        if (tab_menu != 4) {
                            active_tab = true;
                            tab_menu = 4;
                        }
                    };
                }
               
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tConfig"), ImVec2(120, 30))) {
                        if (tab_menu != 5) {
                            active_tab = true;
                            tab_menu = 5;
                        }
                    };
                }

               
                
                ImGui::SetCursorPos(ImVec2(30, 520));
                if (Value::EU) {
                    if (ImGui::Button(xorstr_("\tExit"), ImVec2(120, 30))) {
                        exitBool = true;
                    };
                }
              

                ImGui::PopStyleVar(2);

            }
            ImGui::EndGroup();

            ImGui::SetCursorPos(ImVec2(210, 95 + animation_tab / 8));
            switch (tab_menu) {

            case 0:

                ImGui::BeginChild(xorstr_("Main"), ImVec2(305, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 70));
                    ImGui::BeginGroup(); {
                        ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Enable Aimbot"), &Value::bools::Aim::Enable);
                        ImGui::Checkbox(xorstr_("Psilent"), &Value::bools::Aim::PSilent);
                        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                        ImGui::Checkbox(xorstr_("Enable Fov"), &Value::bools::Aim::Fov);  ImGui::SameLine(200);  ImGui::ColorEdit3("Fov", (float*)&Value::Colors::Aim::Fov, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::PopStyleVar(1);
                        ImGui::Checkbox(xorstr_("Smooth"), &Value::bools::Aim::Smooth);
                        ImGui::Checkbox(xorstr_("Range"), &Value::bools::Aim::range);
                        //ImGui::Checkbox(xorstr_("Ignore Sleepers"), &Value::bools::Aim::IgnoreSleepers);
                        ImGui::Checkbox(xorstr_("Ignore Npc"), &Value::bools::Aim::ignoreNpc);
                        ImGui::Checkbox(xorstr_("Visible Check"), &Value::bools::Aim::VisibleCheck);
                    }
                    ImGui::EndGroup();
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 95 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("Settings"), ImVec2(305, 290), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::PushItemWidth(150);
                        if (Value::bools::Aim::Fov) {
                            ImGui::SliderInt(xorstr_("Aimbot FOV"), &Value::floats::Aim::Fov, 1, 360, xorstr_("%.2f"));
                        }
                        ImGui::Text("");
                        if (Value::bools::Aim::Smooth) {
                            ImGui::SliderFloat(xorstr_("Smooth"), &Value::floats::Aim::Smooth, 1.f, 10, xorstr_("%.2f"));
                        }
                        ImGui::Text("");
                        if (Value::bools::Aim::range)
                        {
                            ImGui::SliderFloat(xorstr_("Range"), &Range, 1, 300, xorstr_("%.2f"));
                        }
                        ImGui::Text("");


                    }
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 405 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("Binds"), ImVec2(305, 170), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                
                    if (Value::bools::Aim::Enable) {
                        if (Value::EU) {

                            ImGui::Hotkey(&Value::bools::Aim::AimKey, ImVec2(100, 20));
                            ImGui::SameLine(150);
                            ImGui::Text("AimKey");
                        }
                      
                    }

                }
                ImGui::EndChild();

                break;

            case 1:

                ImGui::BeginChild(xorstr_("Ma1n"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::Checkbox(xorstr_("Enable Visuals"), &Value::bools::Visuals::ESP::Enable);
                        if (Value::bools::Visuals::ESP::Enable) {
                            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                            ImGui::Checkbox(xorstr_("Name"), &Value::bools::Visuals::ESP::Name);  ImGui::SameLine(150);  ImGui::ColorEdit3("Name", (float*)&Value::Colors::Visuals::ESP::Name, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Box"), &Value::bools::Visuals::ESP::Box);  ImGui::SameLine(150);  ImGui::ColorEdit3("Box", (float*)&Value::Colors::Visuals::ESP::Box, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            //ImGui::Checkbox(xorstr_("BoxFilled"), &Value::bools::Visuals::ESP::BoxRect);  ImGui::SameLine(150);  ImGui::ColorEdit3("BoxRect", (float*)&Value::Colors::Visuals::ESP::BoxRect, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Corner Box"), &Value::bools::Visuals::ESP::CornerBox);  ImGui::SameLine(150);  ImGui::ColorEdit3("BoxCorner", (float*)&Value::Colors::Visuals::ESP::CornerBox, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            //ImGui::Checkbox(xorstr_("Skeleton"), &Value::bools::Visuals::ESP::Skeleton);  ImGui::SameLine(150);  ImGui::ColorEdit3("Skeleton", (float*)&Value::Colors::Visuals::ESP::Skeleton, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Health"), &Value::bools::Visuals::ESP::Health);  ImGui::SameLine(150);  ImGui::ColorEdit3("Health", (float*)&Value::Colors::Visuals::ESP::Health, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Distance"), &Value::bools::Visuals::ESP::Distance); ImGui::SameLine(150); ImGui::ColorEdit3("Distance", (float*)&Value::Colors::Visuals::ESP::Distance, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Weapon"), &Value::bools::Visuals::ESP::Weapon);  ImGui::SameLine(150);  ImGui::ColorEdit3("Weapon", (float*)&Value::Colors::Visuals::ESP::Weapon, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Backpack"), &Value::bools::Visuals::ESP::Backpack); ImGui::SameLine(150); ImGui::ColorEdit3("Backpack", (float*)&Value::Colors::Visuals::World::Backpack, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Checkbox(xorstr_("Corpse"), &Value::bools::Visuals::ESP::Corpse); ImGui::SameLine(150); ImGui::ColorEdit3("Corpse", (float*)&Value::Colors::Visuals::World::Corpse, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                            ImGui::Text("");
                            ImGui::PushItemWidth(150);
                            ImGui::PopStyleVar(1);
                            ImGui::PopItemWidth();
                        }
                    }
                    break;
                
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 95 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("Radar"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::Checkbox(xorstr_("Enable Radar"), &Value::bools::Visuals::Radar::Enable); if (Value::bools::Visuals::Radar::Enable) { ImGui::Checkbox(xorstr_("Ignore Sleepers(Radar)"), &Value::bools::Visuals::Radar::Sleeper); }
                        if (Value::bools::Visuals::ESP::Enable) {
                            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                            ImGui::PushItemWidth(150);
                            ImGui::Text("");
                            if (Value::bools::Visuals::Radar::Enable) {
                                ImGui::SliderInt(xorstr_("Distance"), &Value::floats::Visuals::Radar::Distance, 1.f, 300, xorstr_("%.2f"));
                            }
                            ImGui::Text("");
                            if (Value::bools::Visuals::Radar::Enable)
                            {
                                ImGui::SliderInt(xorstr_("Radius"), &Value::floats::Visuals::Radar::Radius, 1, 300, xorstr_("%.2f"));
                            }
                            ImGui::Spacing();

                            ImGui::PushItemWidth(150);

                            ImGui::PopStyleVar(1);
                            ImGui::PopItemWidth();
                        }
                    }
                    break;
                
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 385 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("Settings Visual"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        if (Value::bools::Visuals::ESP::Enable) {
                            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                            ImGui::Checkbox(xorstr_("Ignore Sleepers"), &Value::bools::Visuals::ESP::IgnoreSleeper);
                            ImGui::Checkbox(xorstr_("Ignore Npc"), &Value::bools::Visuals::ESP::IgnoreBot);
                            ImGui::Text("");
                            ImGui::PushItemWidth(150);
                            ImGui::SliderInt(xorstr_("Visual Distance"), &Value::bools::Visuals::ESP::ToDistance, 1.f, 350, xorstr_("%.2f"));
                            ImGui::PopStyleVar(1);
                            ImGui::PopItemWidth();
                        }
                    }
                }
                ImGui::EndChild();

                break;

            case 2:

                ImGui::BeginChild(xorstr_("M1sc"), ImVec2(305, 495), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    
                    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                    //ImGui::Checkbox(xorstr_("SpinBot"), &Value::bools::Player::PlayerWalk::SpinBot);
                    //ImGui::Checkbox(xorstr_("FakeLag"), &Value::bools::Player::PlayerWalk::FakeLag);
                    /*ImGui::Checkbox(xorstr_("FlyHack"), &FlyOn);*/
                    if (FlyOn)
                    {
                        ImGui::PushItemWidth(150);
                        ImGui::SameLine(110);
                        ImGui::Hotkey(&FlyHackButon, ImVec2(100, 20));
                        ImGui::SameLine(250);
                        ImGui::Text("Fly Key");
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::SliderFloat(xorstr_("Fly Speed"), &gravityFly, -1.f, 3, xorstr_("%.2f"));
                        ImGui::PopItemWidth();
                    }
                    ImGui::Checkbox(xorstr_("Spider"), &Value::bools::Player::PlayerWalk::Spiderman);
                    ImGui::Checkbox(xorstr_("InfinityJump"), &Value::bools::Player::PlayerWalk::InfinityJump);
                    //ImGui::Checkbox(xorstr_("PatchDebug"), &Value::bools::Misc::PatchDebug);
                    ImGui::Checkbox(xorstr_("WalkOnWater"), &Value::bools::Misc::WalkOnWater);
                    if (Value::bools::Misc::WalkOnWater) {
                        Value::bools::Player::PlayerWalk::ChangeGravity = false;
                        Value::bools::Player::PlayerWalk::Spiderman = false;
                    }
                    ImGui::Checkbox(xorstr_("DebugCamera"), &Value::bools::Player::PlayerWalk::DebugCamera);
                    ImGui::Checkbox(xorstr_("AntiKastryla"), &Value::bools::Misc::Kastryla);
                    //ImGui::Checkbox(xorstr_("FakeAdmin"), &Value::bools::Player::PlayerWalk::FakeAdmin);
                    //ImGui::Checkbox(xorstr_("FastSwitch"), &Value::bools::Misc::fastSwitch);
                    //ImGui::Checkbox(xorstr_("MapHardcor"), &Value::bools::Player::MapHard);





                    ImGui::PopStyleVar(1);

                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 95 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("World"), ImVec2(305, 495), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::Checkbox(xorstr_("LongNeck"), &Value::floats::Player::LongNeck);
                    if (Value::floats::Player::LongNeck) {
                        ImGui::SameLine(110);
                        ImGui::Hotkey(&Value::floats::Player::LongNeckKey, ImVec2(100, 20));
                        ImGui::SameLine(250);
                        ImGui::Text("LongNeckKey");
                        ImGui::Checkbox(xorstr_("Left"), &Value::floats::Player::Lefts);
                        if (Value::floats::Player::Lefts) {
                            ImGui::SameLine(250);
                            ImGui::Hotkey(&Value::floats::Player::Left, ImVec2(100, 20));
                            ImGui::SameLine(250);
                            ImGui::Text("LeftKey");

                        }
                        ImGui::Checkbox(xorstr_("Right"), &Value::floats::Player::Rigts);
                        if (Value::floats::Player::Rigts) {
                            ImGui::SameLine(250);
                            ImGui::Hotkey(&Value::floats::Player::Right, ImVec2(100, 20));
                            ImGui::SameLine(250);
                            ImGui::Text("RightKey");
                        }
                    }

                    ImGui::Checkbox(xorstr_("CustomFov"), &Value::bools::Player::CustomFov);
                    if (Value::bools::Player::CustomFov) {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::PushItemWidth(150);
                        ImGui::SliderFloat(xorstr_("Custom Fov"), &Value::floats::Player::CustomFov, 70, 150, xorstr_("%.2f"));

                        ImGui::PopItemWidth();
                    }
                    ImGui::Checkbox(xorstr_("Zoom"), &Value::bools::Player::Zoom);
                    if (Value::bools::Player::Zoom) {
                        ImGui::SameLine(103);
                        ImGui::Hotkey(&Value::floats::Player::zoomKey, ImVec2(100, 20));
                        ImGui::SameLine(250);
                        ImGui::Text("zoomKey");
                        ImGui::Spacing();
                    }

                    ImGui::Checkbox(xorstr_("MinicopterFire"), &Value::bools::Player::PlayerWalk::MinicopterFire);
                    ImGui::Checkbox(xorstr_("Jump Shoot"), &Value::bools::Player::PlayerWalk::jumpshoot);
                   
                    //ImGui::Checkbox(xorstr_("High Jump"), &Value::bools::Player::PlayerWalk::ChangeGravity);
                    ImGui::Checkbox(xorstr_("FastKill"), &Value::bools::Misc::killhack);
                    if (Value::bools::Misc::killhack) {
                        ImGui::SameLine(103);
                        ImGui::Hotkey(&Value::bools::Misc::killhackkey, ImVec2(100, 20));
                        ImGui::SameLine(150);
                        ImGui::Text("killhackkey");
                        ImGui::Spacing();
                    }
                   
                    ImGui::Checkbox(xorstr_("Custom Time"), &CustomTime);
                    if (CustomTime)
                    {
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::PushItemWidth(150);
                        ImGui::SliderFloat(xorstr_("Custom Time"), &TimeFloat, 0, 24, xorstr_("%.2f"));
                        ImGui::PopItemWidth();
                    }
                }
                ImGui::EndChild();





                break;

            case 3:

                ImGui::BeginChild(xorstr_("Misc"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::Checkbox(xorstr_("Stash"), &Value::bools::Visuals::World::Items::Stash); ImGui::SameLine(150); ImGui::ColorEdit3("Stash", (float*)&Value::Colors::Visuals::World::Stash, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Hemp"), &Value::bools::Visuals::World::Items::Hemp); ImGui::SameLine(150); ImGui::ColorEdit3("Hemp", (float*)&Value::Colors::Visuals::World::Hemp, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("AirDrop"), &Value::bools::Visuals::World::Items::AirDrop); ImGui::SameLine(150); ImGui::ColorEdit3("AirDrop", (float*)&Value::Colors::Visuals::World::AirDrop, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Stone"), &Value::bools::Visuals::World::Items::Ore::Stone); ImGui::SameLine(150); ImGui::ColorEdit3("Stone", (float*)&Value::Colors::Visuals::World::Ore::Stone, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Sulfure"), &Value::bools::Visuals::World::Items::Ore::Sulfur); ImGui::SameLine(150); ImGui::ColorEdit3("Sulfur", (float*)&Value::Colors::Visuals::World::Ore::Sulfur, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Iron"), &Value::bools::Visuals::World::Items::Ore::Iron); ImGui::SameLine(150); ImGui::ColorEdit3("Iron", (float*)&Value::Colors::Visuals::World::Ore::Iron, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Mini Copter"), &Value::bools::Visuals::World::Items::Minicopter); ImGui::SameLine(150); ImGui::ColorEdit3("Minicopter", (float*)&Value::Colors::Visuals::World::Minicopter, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Patrol"), &Value::bools::Visuals::World::Items::Patrol); ImGui::SameLine(150); ImGui::ColorEdit3("Patrol", (float*)&Value::Colors::Visuals::World::Patrol, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("CH47"), &Value::bools::Visuals::World::Items::CH47); ImGui::SameLine(150); ImGui::ColorEdit3("CH47", (float*)&Value::Colors::Visuals::World::CH47, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("ScrapHeli"), &Value::bools::Visuals::World::Items::scrapheli); ImGui::SameLine(150); ImGui::ColorEdit3("ScrapHeli", (float*)&Value::Colors::Visuals::World::scrapheli, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Horse"), &Value::bools::Visuals::World::Items::horse); ImGui::SameLine(150); ImGui::ColorEdit3("Horse", (float*)&Value::Colors::Visuals::World::horse, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Bear"), &Value::bools::Visuals::World::Items::Bear); ImGui::SameLine(150); ImGui::ColorEdit3("Bear", (float*)&Value::Colors::Visuals::World::Bear, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Boar"), &Value::bools::Visuals::World::Items::Boar); ImGui::SameLine(150); ImGui::ColorEdit3("Boar", (float*)&Value::Colors::Visuals::World::Boar, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Diesel"), &Value::bools::Visuals::World::Items::Diesel); ImGui::SameLine(150); ImGui::ColorEdit3("Diesel", (float*)&Value::Colors::Visuals::World::Diesel, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::PushItemWidth(150);
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::Spacing();
                        ImGui::SliderInt(xorstr_("World Distance"), &Value::floats::Visuals::World::LimitDistance, 0, 400, xorstr_("%.2f"));
                        ImGui::PopStyleVar(1);
                        ImGui::PopItemWidth();
                    }

                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2(535, 95 + animation_tab / 8));

                ImGui::BeginChild(xorstr_("Settings"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::Checkbox(xorstr_("Cupboard"), &Value::bools::Visuals::World::Items::Cupboard); ImGui::SameLine(150); ImGui::ColorEdit3("Cupboard", (float*)&Value::Colors::Visuals::World::Cupboard, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Bear Trap"), &Value::bools::Visuals::World::Items::BearTrap); ImGui::SameLine(150); ImGui::ColorEdit3("Bear Trap", (float*)&Value::Colors::Visuals::World::BearTrap, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Auto Turret"), &Value::bools::Visuals::World::Items::autoturret); ImGui::SameLine(150); ImGui::ColorEdit3("Auto Turret", (float*)&Value::Colors::Visuals::World::autoturret, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Guntrap"), &Value::bools::Visuals::World::Items::guntrap); ImGui::SameLine(150); ImGui::ColorEdit3("Guntrap", (float*)&Value::Colors::Visuals::World::guntrap, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Crate Basic"), &Value::bools::Visuals::World::Items::crate_basic); ImGui::SameLine(150); ImGui::ColorEdit3("Crate Basic", (float*)&Value::Colors::Visuals::World::crate_basic, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Crate Military"), &Value::bools::Visuals::World::Items::crate_normal); ImGui::SameLine(150); ImGui::ColorEdit3("Crate Military", (float*)&Value::Colors::Visuals::World::crate_normal, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Crate Tools"), &Value::bools::Visuals::World::Items::CrateTools); ImGui::SameLine(150); ImGui::ColorEdit3("Crate Tools", (float*)&Value::Colors::Visuals::World::CrateTools, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Crate Normal"), &Value::bools::Visuals::World::Items::crate_normal2); ImGui::SameLine(150); ImGui::ColorEdit3("Crate Normal", (float*)&Value::Colors::Visuals::World::crate_normal2, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Crate Bradley"), &Value::bools::Visuals::World::Items::bradley_crate); ImGui::SameLine(150); ImGui::ColorEdit3("Bradley Crate", (float*)&Value::Colors::Visuals::World::bradley_crate, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Crate Elite"), &Value::bools::Visuals::World::Items::crate_elite); ImGui::SameLine(150); ImGui::ColorEdit3("Crate Elite", (float*)&Value::Colors::Visuals::World::crate_elite, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Workbench 1"), &Value::bools::Visuals::World::Items::Workbench1); ImGui::SameLine(150); ImGui::ColorEdit3("Wb1 Color", (float*)&Value::Colors::Visuals::World::Workbench1, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Workbench 2"), &Value::bools::Visuals::World::Items::Workbench2); ImGui::SameLine(150); ImGui::ColorEdit3("Wb2 Color", (float*)&Value::Colors::Visuals::World::Workbench2, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        ImGui::Checkbox(xorstr_("Workbench 3"), &Value::bools::Visuals::World::Items::Workbench3); ImGui::SameLine(150); ImGui::ColorEdit3("Wb3 Color", (float*)&Value::Colors::Visuals::World::Workbench3, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                        //ImGui::Checkbox(xorstr_("Advend Calendar"), &Value::bools::Visuals::World::Items::Winter); ImGui::SameLine(150); ImGui::ColorEdit3("Winter", (float*)&Value::Colors::Visuals::World::crate_winter, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel); ImGui::Spacing();
                    }
                }
                ImGui::EndChild();

                break;

            case 4:

                ImGui::BeginChild(xorstr_("Weapon"), ImVec2(290, 480), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 60));
                    ImGui::BeginGroup(); {
                        ImGui::Checkbox(xorstr_("Automatic"), &Value::bools::Weapon::IsAutomatic);
                        ImGui::Checkbox(xorstr_("FatBullet"), &Value::bools::Weapon::FatBullet);
                        ImGui::Checkbox(xorstr_("Super Eoka"), &Value::bools::Player::SuperEoka);
                        ImGui::Checkbox(xorstr_("InstantCompound"), &Value::bools::Misc::instantCompound);
                        ImGui::Checkbox(xorstr_("RapidFire"), &Value::bools::Misc::rapidFire);
                        if (Value::bools::Misc::rapidFire)
                        {
                            ImGui::PushItemWidth(150);
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::SliderFloat(xorstr_("Value"), &Value::bools::Misc::rapid, 0, 0.15, xorstr_("%.2f"));
                            ImGui::Spacing();

                        }

                        ImGui::Checkbox(xorstr_("NoSway"), &Value::bools::Weapon::NoSway);
                        ImGui::Checkbox(xorstr_("NoSpread"), &Value::bools::Weapon::NoSpread);
                        ImGui::Checkbox(xorstr_("NoSpreadShootgun"), &Value::bools::Weapon::NoSpreadShootgun);
                        ImGui::Checkbox(xorstr_("FastBow"), &Value::bools::Weapon::SuperBow);
                        ImGui::Checkbox(xorstr_("NoRecoil"), &Value::bools::Weapon::NoRecoil);
                        if (Value::bools::Weapon::NoRecoil)
                        {
                            ImGui::PushItemWidth(150);
                            ImGui::Spacing();
                            ImGui::Spacing();
                            ImGui::SliderFloat(xorstr_("Y"), &recoilvalPitch, 0, 10, xorstr_("%.2f"));
                            ImGui::Text("");
                            ImGui::SliderFloat(xorstr_("X"), &recoilvalYaw, 0, 10, xorstr_("%.2f"));

                            ImGui::PopItemWidth();
                            ImGui::Spacing();
                        }
                        //ImGui::Checkbox(xorstr_("Longhand"), &Value::bools::Player::Longhand);
                    }

                    break;
                }
                ImGui::EndChild();


                break;

            case 5:

                ImGui::BeginChild(xorstr_("Configuration"), ImVec2(290, 467), true, ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::SetCursorPos(ImVec2(20, 80));
                    ImGui::BeginGroup(); {
                        if (ImGui::ButtonEx(xorstr_("Create Configuration"), ImVec2(250, 35))) {
                            set_config(CFG);
                        }


                        ImGui::Spacing();
                        ImGui::Text("");
                        if (ImGui::ButtonEx(xorstr_("Load Configuration"), ImVec2(250, 35))) {
                            read_config(CFG);
                        }


                        ImGui::Spacing();
                        ImGui::Text("");
                        if (ImGui::ButtonEx(xorstr_("Open config location"), ImVec2(250, 35))) {
                            system("start C:\\");
                        }

                        break;
                    }
                }


                break;

            }
        }


	}
}