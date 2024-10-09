#include "GameObject.h"

void InitialiseGameObject(GameObject* obj, int x, int y, int width, int height)
{
    obj->objectPositionX = x;
    obj->objectPositionY = y;
    obj->objectWidth = width;
    obj->objectHeight = height;
    obj->velocityX = 0;
    obj->velocityY = 0;
    obj->gravity = 0;

    obj->gameObjectRect.x = x;
    obj->gameObjectRect.y = y;
    obj->gameObjectRect.w = width;
    obj->gameObjectRect.h = height;

    obj->update = UpdateGameObject;
    obj->render = RenderGameObject;
}

void UpdateGameObject(GameObject* obj, float deltaTime)
{
    obj->objectPositionX += (int)obj->velocityX * deltaTime;
    obj->objectPositionY += (int)obj->velocityY * deltaTime;

    obj->gameObjectRect.x = obj->objectPositionX;
    obj->gameObjectRect.y = obj->objectPositionY;
}

void RenderGameObject(GameObject* obj, SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    obj->gameObjectRect.x = obj->objectPositionX;
    obj->gameObjectRect.y = obj->objectPositionY;
    obj->gameObjectRect.w = obj->objectWidth;
    obj->gameObjectRect.h = obj->objectHeight;
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderFillRect(renderer, &obj->gameObjectRect);
}
