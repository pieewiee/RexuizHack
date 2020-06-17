#pragma once
#include <vector>
#include <windows.h>
#include <TlHelp32.h>
//https://guidedhacking.com/threads/opengl-hooking-drawing-text-rendering.14460/

DWORD GetProcId(const wchar_t* procName);
uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);
uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
uintptr_t moduleBase();