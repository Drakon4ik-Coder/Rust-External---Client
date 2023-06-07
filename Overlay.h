#pragma once
#include <dwmapi.h>
#include <memory>
#include <string>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui_internal.h"
#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment( lib, "dwmapi.lib" )
#include <array>
constexpr auto OverlayCaption = L"AMDJ23";
constexpr auto OverlayClassName = L"NVIDIA_AMD";
extern ImFont* tab;
extern ImFont* ico;
extern ImFont* ico_default;
extern ImFont* pop;


#define TRACE(str, ...) printf(str, __VA_ARGS__); putchar('\n')

typedef struct
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;
}RGBA;

namespace OverlayData
{
	inline ImFont* fontTitle;
	inline ImFont* fontMenu;
	inline ImFont* playerName;
	inline ImFont* weaponName;
	inline ImFont* menuIcon;
}




enum TextLayout : std::uint32_t
{
	TextLeft = 0x00,
	TextRight = 0x01,
	TextCenterV = 0x02,
	TextCenterH = 0x04,
	TextCenter = (TextCenterV | TextCenterH),
};

class COverlayProxy
{
public:
	void LineCross(const ImVec2& begin, const ImVec2& end, const ImColor& color);
	void Line(int x1, int y1, int x2, int y2, RGBA* color, int thickness);
	void RectFilled(int x, int y, int w, int h, RGBA* color);
	void Rect(int x, int y, int w, int h, RGBA* color, int thickness);
	void Text(int x, int y, RGBA* color, const char* str);
	void TextS(int x, int y, RGBA* color, std::string str);
	void Circle(int x, int y, int radius, RGBA* color, int segments);
	void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness);
	void drawHealthBar(float x, float y, float w, float h, float val, float max, RGBA* color);
	void HPRectFilled(int x, int y, int w, int h, RGBA* color);
	void DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA* color);
	void FlyIndicator(float x, float y, float w, float h, float val, float max, RGBA* color);
	void CircleFilled(int x, int y, int radius, RGBA* color);
	void CrossLine(const ImVec2& begin, const ImVec2& end, const ImColor& color);
	void DrawFilledRectImGui(int x, int y, int w, int h, ImVec4 color);
	ImDrawList* GetDrawList()
	{
		return this->m_render_context;
	}
protected:
	void RenderText(const ImVec2& location, const std::uint32_t layout, const ImColor& color, const char* text);
	ImDrawList* m_render_context = nullptr;
};


class Overlay : public COverlayProxy
{
public:
	using Shared = std::shared_ptr< Overlay >;
	using Dimension = std::array< std::int32_t, 4 >;
	using UpdateProcedureFn = void(*)();
	using RenderProcedureFn = void(*)(Overlay* pOverlay);
	std::int32_t m_width = 640;
	std::int32_t m_height = 480;
public:
	Overlay();
	Overlay(const std::wstring& target_class_name);

public:
	~Overlay();

public:
	bool Create(const std::wstring& target_class_name);
	void Destroy();

public:
	IDirect3DDevice9Ex* GetDevice() const;
	HWND GetTargetWindow() const;

public:
	bool Render();

	void SetUpdateProcedure(const UpdateProcedureFn update_procedure);
	void SetRenderProcedure(const RenderProcedureFn render_procedure);

protected:
	void Scale();

public:
	bool m_bGuiVisible = false;
protected:


protected:
	bool CreateInternal();
	void DestroyInternal();

	bool CreateD3D11();
	void DestroyD3D11();
public:
	bool CreateRenderTarget();
	void DestroyRenderTarget();
protected:
	static LRESULT WINAPI Procedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam);

protected:
	HWND m_window_target = nullptr;
	HWND m_window_overlay = nullptr;

	std::wstring m_overlay_caption = OverlayCaption;
	std::wstring m_overlay_class_name = OverlayClassName;

	IDirect3D9Ex* IDirect3D9 = NULL;
	IDirect3DDevice9Ex* pDevice = NULL;
	D3DPRESENT_PARAMETERS pParameters = { NULL };

	UpdateProcedureFn m_update_procedure = nullptr;
	RenderProcedureFn m_render_procedure = nullptr;
	//ImDrawList* m_render_context = nullptr;
};

extern Overlay::Shared pOverlay;
