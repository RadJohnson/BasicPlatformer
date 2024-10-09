#ifndef Game_H
#define Game_H

#include <SDL.h>
#include <SDL_timer.h>
#include "Player.h"
#include "GameObject.h"


typedef struct Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	int isRunning;
	int windowHeight;
	int windowWidth;

	Uint32 timeLastFrame;
	const Uint8* keyStates;

	Player player;
	GameObject ground;

	void (*EventHandler)(struct Game* game);
	void (*Update)();
	void (*Render)(struct Game* game);
}Game;

void NewGame(Game* game);
int Initialise(Game *game, char* gameName);
void EventHandler(Game *game);
void Update(Game* game);
void Render(Game *game);
void CloseGame(Game *game);

#endif