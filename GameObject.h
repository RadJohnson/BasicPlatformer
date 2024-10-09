#ifndef GameObject_H
#define GameObject_H

#include <SDL.h>

typedef struct GameObject
{
	SDL_Rect gameObjectRect;
	int velocityX;
	int velocityY;
	int objectPositionX;
	int objectPositionY;
	int objectWidth;
	int objectHeight;

	int gravity;
	
	void (*update)(struct GameObject*, float deltaTime);
	void (*render)(struct GameObject*, SDL_Renderer*, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

}GameObject;

void InitialiseGameObject(GameObject* obj, int x, int y, int width, int height);
void UpdateGameObject(GameObject* obj, float deltaTime);
void RenderGameObject(GameObject* obj, SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

#endif