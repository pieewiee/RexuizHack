#pragma once
#include <Windows.h>
#include "pch.h"
#include "geom.h"
#include "proc.h"





class LocalPlayerClass
{
public:
	char pad_0000[12]; //0x0000
	class LocalPlayer  (*LocalPlayer); //0x000C
	char pad_0010[2084]; //0x0010
}; //Size: 0x0834

class LocalPlayer
{
public:
	char pad_0000[40]; //0x0000
	vec3 Angle; //0x0028
	char pad_0034[24]; //0x0034
	vec3 position; //0x004C
	char pad_0058[21456]; //0x0058
	int32_t health; //0x5428
	char pad_542C[12]; //0x542C
	int32_t armor; //0x5438
	char pad_543C[4]; //0x543C
	int32_t shotgun; //0x5440
	int32_t machinegun; //0x5444
	int32_t rocket; //0x5448
	int32_t laser; //0x544C
	char pad_5450[2976]; //0x5450
}; //Size: 0x5FF0


class Player
{
public:
	char name[46]; //0x0000
	char pad_0004[86]; //0x0004
	int32_t status; //0x0084
	char pad_0088[1288]; //0x0088
	int32_t ingame; //0x0590
	char pad_0594[148]; //0x059
}; //Size: 0x0628


class Players
{
public:
	class Player  (*Player)[1]; //0x0000
	//char pad_0004[4128]; //0x0004
}; //Size: 0x1024


class ScreenResolution
{
public:
	char pad_0000[204]; //0x0000
	int32_t width; //0x00CC
	int32_t height; //0x00D0
	char pad_00D4[812]; //0x00D4
}; //Size: 0x0400

class FieldOfView
{
public:
	char pad_0000[4]; //0x0000
	float fieldOfView; //0x0004
	char pad_0008[252]; //0x0008
}; //Size: 0x0104


class Viewmatrix
{
public:
	char pad_0000[320]; //0x0000
	vec3 left; //0x0140
	char pad_014C[4]; //0x014C
	vec3 up; //0x0150
	char pad_015C[4]; //0x015C
	vec3 forward; //0x0160
	char pad_016C[1712]; //0x016C
}; //Size: 0x081C




class PlayersPos
{
public:
	class PlayerPos(*PlayerPos)[1]; //0x0000
}; //Size: 0x0004

class PlayerPos
{
public:
	char pad_0000[948]; //0x0000
	vec3 Position; //0x03B4
	char pad_03C0[224]; //0x03C0
}; //Size: 0x04A0


class Viewangle
{
public:
	vec3 viewangle; //0x0000
}; //Size: 0x004C


class ClientConnect
{
public:
	int32_t connected; //0x001C
}; //Size: 0x0040x0004
