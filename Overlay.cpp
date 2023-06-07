#include "Overlay.h"
#include "logo.h"
ImFont* icons = nullptr;
ImFont* dewi_extended_bold_font = nullptr;
ImFont* dewi_expanded_ub_font = nullptr;
ImFont* dewi_semibold_font = nullptr;
ImFont* expand_font = nullptr;
ImFont* tab2 = nullptr;
ImFont* ico = nullptr;
ImFont* ico_tabs = nullptr;
ImFont* ico_default = nullptr;
ImFont* tab = nullptr;
ImFont* pop = nullptr;
ImFont* mi1 = nullptr;

std::string string_To_UTF8(const std::string& str) {
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);
	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
	std::string retStr(pBuf);
	delete[]pwBuf;
	delete[]pBuf;
	pwBuf = NULL;
	pBuf = NULL;
	return retStr;
}

void COverlayProxy::Line(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4()), thickness);
}

void COverlayProxy::CrossLine(const ImVec2& begin, const ImVec2& end, const ImColor& color)
{
	ImGui::GetForegroundDrawList()->AddLine(begin, end, color);
}



void COverlayProxy::RectFilled(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}

void COverlayProxy::DrawFilledRectImGui(int x, int y, int w, int h, ImVec4 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}

void COverlayProxy::Rect(int x, int y, int w, int h, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
}



void COverlayProxy::DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA* color) {
	pOverlay->RectFilled(x + borderPx, y, w / 3, borderPx, color);
	pOverlay->RectFilled(x + w - w / 3 + borderPx, y, w / 3, borderPx, color);
	pOverlay->RectFilled(x, y, borderPx, h / 3, color);
	pOverlay->RectFilled(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color);
	pOverlay->RectFilled(x + borderPx, y + h + borderPx, w / 3, borderPx, color);
	pOverlay->RectFilled(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, color);
	pOverlay->RectFilled(x + w + borderPx, y, borderPx, h / 3, color);
	pOverlay->RectFilled(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color);

}

void COverlayProxy::HPRectFilled(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R, color->G, color->B, color->A)), 0, 0);
}

void COverlayProxy::FlyIndicator(float x, float y, float w, float h, float val, float max, RGBA* color) {
	RGBA Color = { 0.7, 0.7, 0.7, 1 };
	pOverlay->Rect(x, y, w, h, &Color, 2);
	RectFilled(x + 1, y + 1, w - 1, val / max * h, color);
}


void COverlayProxy::drawHealthBar(float x, float y, float w, float h, float val, float max, RGBA* color) {
	pOverlay->Rect(x + 3, y, 4.5, h, color, 1.2);
	if (val >= 80)
	{
		RGBA Color = { 0, 1 , 0, 1 };
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
	else if (val >= 60)
	{
		RGBA Color = { 255, 148 ,0, 255 };;
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
	else if (val >= 50)
	{
		RGBA Color = { 255, 148 ,0, 255 };;
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
	else if (val >= 40)
	{
		RGBA Color = { 1, 0.58 ,0, 1 };;
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
	else if (val >= 20)
	{
		RGBA Color = { 1, 0.58 ,0, 1 };;
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
	else if (val <= 30)
	{
		RGBA Color = { 1, 0.58 ,0, 1 };;
		pOverlay->HPRectFilled(x + 3, y + 1, 4.5, val / max * h, &Color);
	}
}

void COverlayProxy::DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness) {
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}


void COverlayProxy::LineCross(const ImVec2& begin, const ImVec2& end, const ImColor& color)
{
	ImGui::GetForegroundDrawList()->AddLine(begin, end, color);
}

void COverlayProxy::Text(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	/*ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());*/
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void COverlayProxy::TextS(int x, int y, RGBA* color, std::string str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	//ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	//ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str(), utf_8_2.c_str()+8);
}



void COverlayProxy::Circle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}

void COverlayProxy::CircleFilled(int x, int y, int radius, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}

void COverlayProxy::RenderText(const ImVec2& location, const std::uint32_t layout, const ImColor& color, const char* text)
{
	auto text_size = ImGui::CalcTextSize(text);
	auto text_location = location;

	if (layout & TextRight)
		text_location.x -= text_size.x;
	else if (layout & TextCenterH)
		text_location.x -= text_size.x / 2.f;

	if (layout & TextCenterV)
		text_location.y -= text_size.y / 2.f;

	auto text_shadow = ImVec2(text_location.x + 1.f, text_location.y + 1.f);

	ImGui::GetForegroundDrawList()->AddText(text_shadow, ImColor{ 0.01f, 0.01f, 0.01f, color.Value.w }, text);
	ImGui::GetForegroundDrawList()->AddText(text_location, color, text);
}

Overlay::Dimension GetWindowDimension(HWND window)
{
	Overlay::Dimension dimension = { };

	if (window)
	{
		RECT rect_client = { };
		GetClientRect(window, &rect_client);

		dimension[2] = rect_client.right;
		dimension[3] = rect_client.bottom;

		RECT rect_window = { };
		GetWindowRect(window, &rect_window);

		POINT distance = { 0, 0 };
		ClientToScreen(window, &distance);

		dimension[0] = rect_window.left + (distance.x - rect_window.left);
		dimension[1] = rect_window.top + (distance.y - rect_window.top);
	}

	return dimension;
}

Overlay::Overlay()
	: m_overlay_caption(OverlayCaption)
	, m_overlay_class_name(OverlayClassName)
	, m_width(640)
	, m_height(480)
{ }

Overlay::Overlay(const std::wstring& target_class_name)
	: Overlay()
{
	if (!Create(target_class_name))
	{
		//TRACE("%s: Create() error!", __FUNCTION__);
		//system("pause");
	}
}

Overlay::~Overlay()
{
	Destroy();
}

bool Overlay::Create(const std::wstring& target_class_name)
{
	if (target_class_name.empty())
	{
		TRACE("%s: target_class_name is empty!", __FUNCTION__);
		return false;
	}

	m_window_target = FindWindowW(target_class_name.c_str(), nullptr);

	if (!m_window_target)
	{
		//TRACE("%s: FindWindowW() error! (0x%08X)", __FUNCTION__, GetLastError());
		//return false;
	}

	if (!CreateInternal())
	{
		TRACE("%s: CreateInternal() error!", __FUNCTION__);
		return false;
	}

	if (!CreateD3D11())
	{
		TRACE("%s: CreateD3D11() error!", __FUNCTION__);
		return false;
	}

	if (!CreateRenderTarget())
	{
		TRACE("%s: CreateRenderTarget() error!", __FUNCTION__);
		return false;
	}

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImFont* m_pFont = io.Fonts->AddFontFromFileTTF(("C:\\Windows\\Fonts\\ariblk.ttf"), 16, nullptr, io.Fonts->GetGlyphRangesCyrillic());

	ImGui::StyleColorsDark();

	if (!ImGui_ImplWin32_Init(m_window_overlay))
	{
		TRACE("%s: ImGui_ImplWin32_Init() error!", __FUNCTION__);
		return false;
	}

	if (!ImGui_ImplDX9_Init(pDevice))
	{
		TRACE("%s: ImGui_ImplDX11_Init() error!", __FUNCTION__);
		return false;
	}
	IDirect3D9->Release();
	m_render_context = ImGui::GetForegroundDrawList();

	return true;
}

void Overlay::Destroy()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyRenderTarget();
	DestroyD3D11();
	DestroyInternal();

	m_window_target = nullptr;
	m_window_overlay = nullptr;
	m_overlay_caption.clear();
	m_overlay_class_name.clear();
	pDevice = 0;

}

IDirect3DDevice9Ex* Overlay::GetDevice() const
{
	return pDevice;
}

inline HWND Overlay::GetTargetWindow() const
{
	return m_window_target;
}

void ChangeTopWindow(HWND NewWnd, HWND OldWhd)
{
	DWORD OldThreadId = GetWindowThreadProcessId(OldWhd, nullptr);
	DWORD MyThreadId = GetCurrentThreadId();
	if (OldThreadId != MyThreadId)
	{
		AttachThreadInput(OldThreadId, MyThreadId, true);
		BringWindowToTop(NewWnd);
		ShowWindow(NewWnd, SW_SHOW);
		//AttachThreadInput(MyThreadId, OldThreadId, true);
		//AttachThreadInput(foreThread, appThread, false);
	}
	else
	{
		//AttachThreadInput(OldThreadId, MyThreadId, true);
		BringWindowToTop(NewWnd);
		ShowWindow(NewWnd, SW_SHOW);
	}
}

void InputHandler()
{
	for (int i = 0; i < 5; i++)
	{
		ImGui::GetIO().MouseDown[i] = false;
	}

	int Button = -1;
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		Button = 0;
	}

	if (Button != -1)
	{
		ImGui::GetIO().MouseDown[Button] = true;
	}
}

bool Overlay::Render()
{
	static const ImVec4 color_clear = { 0, 0.f, 0.0f, 1 };

	const float clear_color_with_alpha[4] = { color_clear.x * color_clear.w, color_clear.y * color_clear.w, color_clear.z * color_clear.w, color_clear.w };

	static RECT OldRect = {};

	if (m_update_procedure)
		m_update_procedure();

	//if (GetAsyncKeyState(VK_INSERT) & 0x1)
	//{
	//	if (!this->m_bGuiVisible)
	//	{
	//		ChangeTopWindow(this->m_window_overlay, this->m_window_target);
	//	}
	//		//ChangeTopWindow(this->m_window_overlay, true);
	//}

	MSG msg = { };

	if (PeekMessageW(&msg, this->m_window_overlay, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	HWND ForegroundWindow = GetForegroundWindow();
	if (ForegroundWindow == this->m_window_target)
	{
		HWND TempProcessHwnd = GetWindow(ForegroundWindow, GW_HWNDPREV);
		SetWindowPos(this->m_window_overlay, TempProcessHwnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}

	RECT TempRect;
	POINT TempPoint;
	ZeroMemory(&TempRect, sizeof(RECT));
	ZeroMemory(&TempPoint, sizeof(POINT));

	GetClientRect(this->m_window_target, &TempRect);
	ClientToScreen(this->m_window_target, &TempPoint);

	TempRect.left = TempPoint.x;
	TempRect.top = TempPoint.y;
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontDefault();
	//system("C:\\USERS\\ILLIA\\APPDATA\\LOCAL\\MICROSOFT\\WINDOWS\\FONTS\\INTER-REGULAR.TTF");
	/*ImFont* mainfont = io.Fonts->AddFontFromFileTTF("C:\\USERS\\ILLIA\\APPDATA\\LOCAL\\MICROSOFT\\WINDOWS\\FONTS\\INTER-REGULAR.TTF", 18.5f);
	if (mainfont == NULL)
	{
		std::cout << "Error font" << std::endl;
		Sleep(10000);
	}
	IM_ASSERT(mainfont != NULL);
	ImGui::PushFont(mainfont);*/

	ImGuiStyle& style = ImGui::GetStyle();
	//styles
	style.ScrollbarSize = 16.f; //ItemSpacing(ImVec2(7.f));
	style.GrabMinSize = 8.f; //ItemSpacing(ImVec2(7.f));
	style.WindowBorderSize = 2.f; //ItemSpacing(ImVec2(7.f));
	style.FrameBorderSize = 1.f; //ItemSpacing(ImVec2(7.f));
	style.WindowRounding = 5.f; //ItemSpacing(ImVec2(7.f));
	style.FrameRounding = 5.f; //ItemSpacing(ImVec2(7.f));
	style.Alpha = 1.0f;
	style.FrameRounding = 3.0f;
	style.Colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.000f, 0.543f, 0.983f, 1.000f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.000f, 0.000f, 0.000f, 55.895f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.184f, 0.878f, 0.000f, 0.500f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.160f, 0.160f, 0.160f, 0.315f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.160f, 0.160f, 0.160f, 0.315f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.210f, 0.210f, 0.210f, 0.670f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.026f, 0.597f, 0.000f, 1.000f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.099f, 0.315f, 0.000f, 0.000f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.026f, 0.597f, 0.000f, 1.000f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.801f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.238f, 0.238f, 0.238f, 1.000f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.238f, 0.238f, 0.238f, 1.000f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.004f, 0.381f, 0.000f, 1.000f);
	//style.Colors[ImGuiCol_ComboBg] = ImVec4(0.86f, 0.86f, 0.86f, 0.99f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.009f, 0.845f, 0.000f, 1.000f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.139f, 0.508f, 0.000f, 1.000f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.139f, 0.508f, 0.000f, 1.000f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.000f, 0.000f, 0.000f, 0.400f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.000f, 0.619f, 0.014f, 1.000f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.06f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.000f, 1.000f, 0.221f, 0.597f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//style.Colors[ImGuiCol_CloseButton] = ImVec4(0.59f, 0.59f, 0.59f, 0.50f);
	//style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	//style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	style.ItemSpacing = ImVec2(10, 8); //ItemSpacing(ImVec2(7.f));
	style.FramePadding = ImVec2(6, 4); //ItemSpacing(ImVec2(7.f));
	style.ItemInnerSpacing = ImVec2(5, 4); //ItemSpacing(ImVec2(7.f));

	io.ImeWindowHandle = this->m_window_target;

	if (TempRect.left != OldRect.left || TempRect.right != OldRect.right || TempRect.top != OldRect.top || TempRect.bottom != OldRect.bottom)
	{
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
		pOverlay->m_bGuiVisible = !pOverlay->m_bGuiVisible;
	// Scale();

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (m_render_procedure)
		m_render_procedure(this);



	if (pOverlay->m_bGuiVisible)
	{
		InputHandler();
		//	SetLayeredWindowAttributes(pOverlay->m_window_overlay, RGB(255, 255, 255), 0, ULW_COLORKEY | LWA_ALPHA);
		UpdateWindow(pOverlay->m_window_overlay);
		SetWindowLongPtrA(pOverlay->m_window_overlay, GWL_EXSTYLE, WS_EX_TOOLWINDOW);

		UpdateWindow(pOverlay->m_window_overlay);
		SetFocus(pOverlay->m_window_overlay);
	}
	else
	{
		//SetLayeredWindowAttributes(pOverlay->m_window_overlay, RGB(0, 0, 0), 255, ULW_COLORKEY | LWA_ALPHA);
		SetWindowLongPtrA(pOverlay->m_window_overlay, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
		UpdateWindow(pOverlay->m_window_overlay);
	}

	ImGui::EndFrame();

	pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	if (pDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		pDevice->EndScene();
	}

	HRESULT result = pDevice->Present(NULL, NULL, NULL, NULL);
	if (result == D3DERR_DEVICELOST && pDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		pDevice->Reset(&pParameters);
		ImGui_ImplDX9_CreateDeviceObjects();
	}

	//ImGui::Render();
	//m_device_context->OMSetRenderTargets(1, &m_render_target_view, nullptr);
	//m_device_context->ClearRenderTargetView(m_render_target_view, reinterpret_cast<const FLOAT*>(&color_clear));
	//
	//ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	//
	//auto result = m_swap_chain->Present(1, 0); // VSYNC

	//if (FAILED(result))
	//{
	//	TRACE("%s: m_swap_chain->Present() error! (0x%08X)", __FUNCTION__, result);
	//	return false;
	//}

	return true;
}

void Overlay::SetUpdateProcedure(const UpdateProcedureFn update_procedure)
{
	if (!update_procedure)
		return;

	m_update_procedure = update_procedure;
}

void Overlay::SetRenderProcedure(const RenderProcedureFn render_procedure)
{
	if (!render_procedure)
		return;

	m_render_procedure = render_procedure;
}

void Overlay::Scale()
{
	auto scale = [](std::int32_t& input, std::int32_t& output)
	{
		if (input == 0)
		{
			input--;
			output++;
		}
	};

	auto dimension = GetWindowDimension(m_window_target);

	m_width = dimension[2];
	m_height = dimension[3];

	scale(dimension[0], m_width);
	scale(dimension[1], m_height);

	MoveWindow(m_window_overlay, dimension[0], dimension[1], m_width, m_height, TRUE);
}

bool Overlay::CreateInternal()
{
	WNDCLASSEXW window_class =
	{
		sizeof(WNDCLASSEXW),
		0,
		Procedure,
		0,
		0,
		nullptr,
		LoadIconA(nullptr, IDI_APPLICATION),
		LoadCursorA(nullptr, IDC_ARROW),
		nullptr,
		nullptr,
		m_overlay_class_name.c_str(),
		LoadIconA(nullptr, IDI_APPLICATION),
	};

	if (!RegisterClassExW(&window_class))
	{
		TRACE("%s: RegisterClassEx() error! (0x%08X)", __FUNCTION__, GetLastError());
		//return false;
	}


	/*WNDCLASSEXW wndClass;

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.cbClsExtra = NULL;
	wndClass.cbWndExtra = NULL;
	wndClass.hCursor = LoadCursor(0, IDC_ARROW);
	wndClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	wndClass.hInstance = nullptr;
	wndClass.lpfnWndProc = Procedure;
	wndClass.lpszClassName = m_overlay_class_name.c_str();
	wndClass.lpszMenuName = m_overlay_class_name.c_str();
	wndClass.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassExW(&wndClass))
	{
		TRACE("%s: RegisterClassEx() error! (0x%08X)", __FUNCTION__, GetLastError());
		return false;
	}*/

	m_window_overlay = CreateWindowExW(0, m_overlay_class_name.c_str(), m_overlay_caption.c_str(), WS_POPUP | WS_VISIBLE, 0, 0, 640, 480, nullptr, nullptr, nullptr, nullptr);

	if (!m_window_overlay)
	{
		TRACE("%s: CreateWindowExW() error! (0x%08X)", __FUNCTION__, GetLastError());
		//return false;
	}

	/*if (!SetLayeredWindowAttributes(m_window_overlay, RGB(0, 0, 0), 255, ULW_COLORKEY | LWA_ALPHA))
	{
		TRACE("%s: SetLayeredWindowAttributes() error! (0x%08X)", __FUNCTION__, GetLastError());
		return false;
	}*/

	Overlay::Dimension dimension = GetWindowDimension(m_window_target);

	const auto result = DwmExtendFrameIntoClientArea(m_window_overlay, reinterpret_cast<const MARGINS*>(&dimension));

	if (FAILED(result))
	{
		TRACE("%s: DwmExtendFrameIntoClientArea() error! (0x%08X)", __FUNCTION__, result);
		//return false;
	}
	SetWindowLongPtrA(m_window_overlay, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	ShowWindow(m_window_overlay, SW_SHOW);

	if (!UpdateWindow(m_window_overlay))
	{
		TRACE("%s: UpdateWindow() error! (0x%08X)", __FUNCTION__, GetLastError());
		//return false;
	}

	Scale();
	return true;
}

void Overlay::DestroyInternal()
{
	UnregisterClassW(m_overlay_class_name.c_str(), nullptr);

	if (m_window_overlay)
		DestroyWindow(m_window_overlay);
}

bool Overlay::CreateD3D11()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &IDirect3D9)))
	{
		return false;
	}

	D3DPRESENT_PARAMETERS Params = { 0 };
	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.hDeviceWindow = this->m_window_overlay;
	Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	Params.BackBufferWidth = this->m_width;
	Params.BackBufferHeight = this->m_height;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	if (FAILED(IDirect3D9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_window_overlay, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, 0, &pDevice)))
	{
		IDirect3D9->Release();
		return false;
	}

	//DirectX9.IDirect3D9->Release();
	return true;
}

void Overlay::DestroyD3D11()
{
	/*if (m_device_context)
		m_device_context->Release();

	if (m_device)
		m_device->Release();

	if (m_swap_chain)
		m_swap_chain->Release();*/
}

bool Overlay::CreateRenderTarget()
{
	//ID3D11Texture2D* texture2d = nullptr;

	//auto result = m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&texture2d));

	//if (FAILED(result))
	//{
	//	TRACE("%s: m_swap_chain->GetBuffer() error! (0x%08X)", __FUNCTION__, result);
	//	return false;
	//}

	//result = m_device->CreateRenderTargetView(texture2d, nullptr, &m_render_target_view);

	//texture2d->Release();

	//if (FAILED(result))
	//{
	//	TRACE("%s: m_device->CreateRenderTargetView() error! (0x%08X)", __FUNCTION__, result);
	//	return false;
	//}

	return true;
}

void Overlay::DestroyRenderTarget()
{
	/*if (m_render_target_view)
		m_render_target_view->Release();*/
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void clip(HWND hWnd)
{
	int a;
	RECT _clip;
	HWND _window = hWnd;

	//Get the window's handle
	///_window = FindWindow(NULL, title);

	//Create a RECT out of the window
	GetWindowRect(_window, &_clip);

	//Modify the rect slightly, so the frame doesn't get clipped with
	_clip.left += 5;
	_clip.top += 30;
	_clip.right -= 5;
	_clip.bottom -= 5;
	//Clip the RECT
	ClipCursor(&_clip);
	//ShowCursor(FALSE);

}

/* Makes the whole screen accessable again by using ClipCursor
 * on the complete screensize
 */
void unclip()
{
	int a;

	RECT _screen;

	//Build a RECT with the size of the complete window (Note: GetSystemMetrics only covers the main monitor, this won't work in a multi-monitor setup)
	_screen.left = 0;
	_screen.top = 0;
	_screen.right = GetSystemMetrics(SM_CXSCREEN);
	_screen.bottom = GetSystemMetrics(SM_CYSCREEN);

	//Unclip everything by using ClipCursor on the complete screen
	ClipCursor(&_screen);
	//ShowCursor(TRUE);
}

LRESULT Overlay::Procedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	/*if (ImGui_ImplWin32_WndProcHandler(window, message, wparam, lparam))
		return true;*/

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		return 0;
	case WM_KEYDOWN:
		return 0;
	case WM_ERASEBKGND:
		SendMessage(window, WM_PAINT, 0, 0);
		return TRUE;
	case WM_PAINT:
		//		pOverlay->Render();
		//		printf("WM_PAINT!\n");
		return 0;
	case WM_SIZE:
		if (pOverlay && pOverlay->pDevice != NULL && wparam != SIZE_MINIMIZED) {
			ImGui_ImplDX9_InvalidateDeviceObjects();
			pOverlay->pParameters.BackBufferWidth = LOWORD(lparam);
			pOverlay->pParameters.BackBufferHeight = HIWORD(lparam);
			HRESULT hr = pOverlay->pDevice->Reset(&pOverlay->pParameters);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	default:
		break;
	}

	//if (pOverlay)
	//{
	//	if (wparam == VK_INSERT)
	//	{
	//		//pOverlay->m_bGuiVisible = !pOverlay->m_bGuiVisible;

	//		/*
	//		WINDOWINFO WndInfo = {};
	//		WndInfo.cbSize = sizeof(WINDOWINFO);
	//		GetWindowInfo(pOverlay->m_window_target, &WndInfo);
	//		WndInfo.dwExStyle;
	//		*/
	//		if (pOverlay->m_bGuiVisible)
	//		{
	//			
	//			//SetLayeredWindowAttributes(pOverlay->m_window_overlay, RGB(255, 255, 255), 255, ULW_COLORKEY | LWA_ALPHA);
	//		//	clip(pOverlay->m_window_overlay);
	//			SetWindowLongPtrA(pOverlay->m_window_overlay, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED);
	//		//	clip(pOverlay->m_window_overlay);
	//		}
	//		else
	//		{
	//		//	SetWindowLongPtrA(pOverlay->m_window_overlay, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_LAYERED);
	//			SetLayeredWindowAttributes(pOverlay->m_window_overlay, RGB(0, 0, 0), 255, ULW_COLORKEY | LWA_ALPHA);
	//			//ShowWindow(pOverlay->m_window_overlay, SW_SHOWDEFAULT);
	//			//ChangeTopWindow(pOverlay->m_window_target, pOverlay->m_window_overlay);
	//			//ShowWindow(pOverlay->m_window_target, SW_SHOWDEFAULT);
	//		//	unclip();
	//		}
	//	}
	//}
	ImGui_ImplWin32_WndProcHandler(window, message, wparam, lparam);
	//printf("WndProc called!\n");

	return DefWindowProcW(window, message, wparam, lparam);
}

Overlay::Shared pOverlay = nullptr;