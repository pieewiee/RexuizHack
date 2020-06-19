#include "pch.h"
#include <iostream>
#include "mem.h"
#include "hook.h"
#include "glDraw.h"
#include "gltext.h"
#include "esp.h"
#include "aimbot.h"


//https://guidedhacking.com/threads/opengl-hooking-drawing-text-rendering.14460/


bool conf_esp = false, conf_aimbot = false;

typedef BOOL(__stdcall* twglSwapBuffers) (HDC hDc);

twglSwapBuffers owglSwapBuffers;
twglSwapBuffers wglSwapBuffersGateway;

GL::Font glFont;


ESP esp;
Aimbot aimbot;




void Draw()
{
	HDC currentHDC = wglGetCurrentDC();

	if (!glFont.bBuilt || currentHDC != glFont.hdc)
	{
		glFont.Build(ESP_FONT_HEIGHT);
	}

		GL::SetupOrtho();
		esp.Draw(glFont);
		GL::RestoreGL();
	
}


BOOL __stdcall hkwglSwapBuffers(HDC hDc)
{


	ClientConnect* clientConnect = (ClientConnect*)(moduleBase() + 0x78C06c);

	if (GetAsyncKeyState(VK_LBUTTON) && conf_aimbot)
	{
		aimbot.aim();
	}


	if (GetAsyncKeyState(VK_RBUTTON) && conf_aimbot)
	{
		aimbot.aim();
	}

	if (GetAsyncKeyState(VK_PRIOR) & 1) //disable ESP
	{
		conf_esp = !conf_esp;
		std::cout << "conf_esp: " << conf_esp << "\n";
	}

	if (GetAsyncKeyState(VK_NEXT) & 1) //disable Aimbot
	{
		conf_aimbot = !conf_aimbot;
		std::cout << "conf_aimbot: " << conf_aimbot << "\n";
	}
	
	if (clientConnect->connected == 1 && conf_esp)
	{
		Draw();
	}

	return wglSwapBuffersGateway(hDc);
}

DWORD WINAPI HackThread(HMODULE hModule)
{
	//Create Console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "Rexuiz Hack\n";

	// Hook
	Hook SwapBuffersHook("wglSwapBuffers", "opengl32.dll", (BYTE*)hkwglSwapBuffers, (BYTE*)&wglSwapBuffersGateway, 5);
	SwapBuffersHook.Enable();
	

	while (true) {

		if (GetAsyncKeyState(VK_END))
		{
			std::cout << "Hack end\n";
			SwapBuffersHook.Disable();
			break;
		}
	}
	

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}