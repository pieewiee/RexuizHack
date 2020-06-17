#pragma once
#include "rexuiz.h"
#include "glDraw.h"
#include "gltext.h"

//Scaling
const int VIRTUAL_SCREEN_WIDTH = 1920;
const int GAME_UNIT_MAGIC = 8000;

const float PLAYER_HEIGHT = 40.0f;
const float PLAYER_WIDTH = 15.0f;
const float EYE_HEIGHT = 34.979f;
const float PLAYER_ASPECT_RATIO = PLAYER_HEIGHT / PLAYER_WIDTH;

const int ESP_FONT_HEIGHT = 15;
const int ESP_FONT_WIDTH = 9;

class ESP
{
public:

	int numOfPlayers = 64;



	LocalPlayerClass* localPlayer = (LocalPlayerClass*)(moduleBase() + 0x3249C);

	Viewmatrix* viewmatrix = *(Viewmatrix**)(moduleBase() + 0x3A3A4);
	FieldOfView* fieldOfView = *(FieldOfView**)(moduleBase() + 0x60448);
	ScreenResolution* screenResolution = *(ScreenResolution**)(moduleBase() + 0x3decc);

	Players* players = (Players*)(moduleBase() + 0x010E65A8);
	PlayersPos* playersPos = (PlayersPos*)(moduleBase() + 0x78d470);
	Viewangle* viewangle = *(Viewangle**)(moduleBase() + 0x2C44);



	int viewport[4];

	//bool IsTeamGame();
	//bool IsEnemy(ent* e);

	bool IsValidEnt(PlayerPos* PlayerPos);
	void DrawESPBox(Player* players, PlayerPos* playersPos,  vec3 screen, GL::Font& font);
	void Draw(GL::Font& font);
};