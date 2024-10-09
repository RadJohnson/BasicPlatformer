#include <stdio.h>
#include <SDL.h>
#include <SDL_Timer.h>

#include "Game.h"; 

const int FRAME_DELAY = 1000 / 60;

int main(int argc, char* args[])
{
	Game game;

	NewGame(&game);

	if (!Initialise(&game, "BasicPlatformer"))
	{
		printf("Failed To Initialise Game");
		return 0;
	}

	while (game.isRunning == 1)
	{
		game.EventHandler(&game);
		game.Update(&game);

		game.Render(&game);
		SDL_Delay(FRAME_DELAY);

	}
	CloseGame(&game);

	return 0;
}