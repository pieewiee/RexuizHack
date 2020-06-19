#pragma once
#pragma comment(lib, "OpenGL32.lib")
#include <Windows.h>
#include <stdio.h>
#include <gl\GL.h>
#include "mem.h"

//https://guidedhacking.com/threads/opengl-hooking-drawing-text-rendering.14460/

struct vec3text { float x, y, z; };

namespace GL
{
	class Font
	{
	public:
		bool bBuilt = false;
		unsigned int base;
		HDC hdc = nullptr;
		int height;
		int width;

		void Build(int height);
		void Print(float x, float y, const unsigned char color[3], const char* format, ...);

		vec3text centerText(float x, float y, float width, float height, float textWidth, float textHeight);
		float centerText(float x, float width, float textWidth);
	};
}