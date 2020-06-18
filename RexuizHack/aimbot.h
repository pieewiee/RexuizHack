#pragma once
#include <algorithm>
#include "geom.h"
#include "rexuiz.h"
#define PI 3.1415927f



const float PLAYER_HEIGHTaimbot = 40.0f;

const float EYE_HEIGHTaimbot = 34.979f;


vec3 CalcAngle(vec3 src, vec3 dst);


class Aimbot
{
public:
	int numOfPlayers = 64;


	LocalPlayerClass* localPlayer = (LocalPlayerClass*)(moduleBase() + 0x3249C);


	Players* players = (Players*)(moduleBase() + 0x010E65A8);
	PlayersPos* playersPos = (PlayersPos*)(moduleBase() + 0x78d470);
	Viewangle* viewangle = *(Viewangle**)(moduleBase() + 0x2C44);


	bool IsValidEnt(PlayerPos* PlayerPos);
	vec3 GetBestTarget();
	void aim();

};