#include "Player.h"

void InitialisePlayer(Player* player, int x, int y, int width, int height, int playerSpeed, int playerJumpVelocity)
{
	player->baseObject.objectPositionX = x;
	player->baseObject.objectPositionY = y;
	player->baseObject.objectWidth = width;
	player->baseObject.objectHeight = height;


	player->baseObject.velocityX = 0;
	player->baseObject.velocityY = 0;
	player->baseObject.gravity = 1;
	player->grounded = 0;
	player->isJumping = 0;
	player->leftRight = 0;

	player->playerSpeed = playerSpeed;
	player->playerJumpVelocity = playerJumpVelocity;

	player->baseObject.gameObjectRect.x = x;
	player->baseObject.gameObjectRect.y = y;
	player->baseObject.gameObjectRect.w = width;
	player->baseObject.gameObjectRect.h = height;

	player->update = UpdatePlayer;
	player->baseObject.update = UpdateGameObject;
	player->baseObject.render = RenderGameObject;
}

void UpdatePlayer(Player* player, float deltaTime)
{
	//printf("Before Update - VelocityX: %f, VelocityY: %f\n", player->baseObject.velocityX, player->baseObject.velocityY);
	player->baseObject.update(&player->baseObject, deltaTime);
	//printf("After Update - VelocityX: %f, VelocityY: %f\n", player->baseObject.velocityX, player->baseObject.velocityY);

}