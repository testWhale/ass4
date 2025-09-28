#include "cprocessing.h"
#include "game.h"
#include "utils.h"

GameEntity player[2] = { {0,{100.0f , 100.0f}, 0, 1}, {1,{100.0f , 100.0f}, 0, 0} };
GameEntity* player_ptr = &player;
float diameter = 50;
float horiz = 100.0f;
CP_Vector point1 = {0.0,0.0};
CP_Vector point2 = { 100.0f , 100.0f };
CP_Vector point3 = { 100.0f , 100.0f };

//Select Player Code
int i = 0;
CP_BOOL Player = 0;
//
void Game_Init(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(170, 170, 170, 255));
}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(170, 170, 170, 255));
	// for loop through all circles and render.
	for (i = 0; i < 2; i++){
		if (player[i].isPlayer == 1) {
			// Clear the background
			if (CP_Input_KeyDown(KEY_W))
			{
				player[i].centerPos.y -= 10.0f;
				player[i].rotation = 90.0;
			}
			if (CP_Input_KeyDown(KEY_A))
			{
				player[i].centerPos.x -= 10.0f;
				player[i].rotation = 0;
			}
			if (CP_Input_KeyDown(KEY_S))
			{
				player[i].centerPos.y += 10.0f;
				player[i].rotation = 270.0;
			}
			if (CP_Input_KeyDown(KEY_D))
			{
				player[i].centerPos.x += 10.0f;
				player[i].rotation = 180.0;
			}
		}
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Graphics_DrawCircle(player[i].centerPos.x, player[i].centerPos.y, diameter);
		float x = (diameter / 2);
		float y = (diameter / 2);
		float offset = 10.0f;
		point1.x = player[i].centerPos.x - x + 5;
		point1.y = player[i].centerPos.y;
		CP_Vector point2 = { player[i].centerPos.x + x - offset, player[i].centerPos.y + y - offset };
		CP_Vector point3 = { player[i].centerPos.x + x - offset, player[i].centerPos.y - y + offset };
		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Graphics_DrawTriangleAdvanced(point1.x, point1.y, point2.x, point2.y, point3.x, point3.y, player[i].rotation);
		
		if (CP_Input_MouseClicked() == TRUE) {
			CP_BOOL Check = IsCircleClicked(player[i].centerPos.x, player[i].centerPos.y, diameter, CP_Input_GetMouseX(), CP_Input_GetMouseY());
			if (Check == 1) {
				//if player is not selected alr, select them
				if (player[i].isPlayer == 0 ) {
					//check if selcted player is 0 or 1
					//deselct the other player FIX THIS
					player[i].isPlayer = 1;
					if (i == 0) {
						player[1].isPlayer = 0;
					}
					if (i == 1) {
						player[0].isPlayer = 0;
					}
				}
			}

		}
	}
	//exit forloop
	
	// for the player object, check the input
		
	
	
	

}

void Game_Exit(void)
{

}