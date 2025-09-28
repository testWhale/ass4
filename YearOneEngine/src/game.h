#pragma once
typedef struct {
	int id;
	CP_Vector centerPos;
	float rotation;
	CP_BOOL isPlayer;
} GameEntity;

void Game_Init(void);

void Game_Update(void);

void Game_Exit(void);