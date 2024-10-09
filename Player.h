#ifndef Player_H
#define Player_H

#include "GameObject.h"

typedef struct Player {
	GameObject baseObject;
	int isJumping;
	int grounded;
	int leftRight;

	int playerSpeed;
	int playerJumpVelocity;

	void (*update)(struct GameObject*, float deltaTime);
} Player;

void InitialisePlayer(Player* player, int x, int y, int width, int height, int playerSpeed, int playerJumpVelocity);
void UpdatePlayer(Player* player, float deltaTime);
//void RenderPlayer(Player* player, SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

#endif