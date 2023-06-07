#pragma once

#include <windows.h>
#include <winternl.h>
#include <fstream>
#include <string>
#include <vector>
#include <tlhelp32.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "ntdll.lib")




extern IDirect3D9Ex* pObject;
extern IDirect3DDevice9Ex* pDevice;


void ClearD3D();

