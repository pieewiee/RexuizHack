#include "pch.h"
#include "esp.h"
#include "aimbot.h"

bool ESP::IsValidEnt(PlayerPos* PlayerPos)
{
	if (PlayerPos->Position.x != 0 and PlayerPos->Position.y != 0)
	{
		return true;
	}
	return false;
}


void  ESP::DrawESPBox(Player* player, PlayerPos* playerPos, vec3 screen, GL::Font& font)
{
	const GLubyte* color = nullptr;



	//localPlayer->LocalPlayer->postition.Distance(e->pos);
	float dist = localPlayer->LocalPlayer->position.Distance(playerPos->Position);
	if (dist > 75.0f)
	{
		float scale = (GAME_UNIT_MAGIC / dist) * (viewport[2] / viewport[2]);
		float x = screen.x - scale;
		float y = screen.y - scale * PLAYER_ASPECT_RATIO;
		float width = scale * 2;
		float height = scale * PLAYER_ASPECT_RATIO * 2;

		GL::DrawOutline(x, y, width, height, 2.0f, rgb::red);


		float textX = font.centerText(x, width, strlen(player->name) * ESP_FONT_WIDTH);
		float textY = y - ESP_FONT_HEIGHT / 2;
		font.Print(textX, textY, rgb::red, "%s", player->name);

		vec3 angle = CalcAngle(localPlayer->LocalPlayer->position, playerPos->Position);

	}



}

void ESP::Draw(GL::Font& font)
{
	glGetIntegerv(GL_VIEWPORT, viewport);


	for (int i = 0; i < (numOfPlayers); i++)
	{

			Player* player = players->Player[i];
			PlayerPos* playerPos = playersPos->PlayerPos[i];

			if (IsValidEnt(playerPos))
			{
				vec3 center = localPlayer->LocalPlayer->position;
				center.z = center.z - EYE_HEIGHT + PLAYER_HEIGHT / 2;

				vec3 screenCoords;


				//if (WorldToScreen(center, screenCoords, matrix, viewport[2], viewport[3]))
				if (WorldToScreen(center, playerPos->Position, screenCoords, fieldOfView->fieldOfView, fieldOfView->fieldOfView + 36, screenResolution->width, screenResolution->height, viewmatrix->left, viewmatrix->up, viewmatrix->forward))
				{
					DrawESPBox(player, playerPos, screenCoords, font);

				}
				
			}
	}
}
