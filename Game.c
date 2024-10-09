#include "Game.h"

void NewGame(Game* game)
{
	game->window = NULL;
	game->renderer = NULL;
	game->EventHandler = NULL;

	game->isRunning = 1;
	game->windowHeight = 800;
	game->windowWidth = 600;


	InitialisePlayer(&game->player, 100, 100, 50, 70, 200, 500);
	//game->player.baseObject.gravity = 5;

	InitialiseGameObject(&game->ground, 0, game->windowHeight - 250, game->windowWidth + 1000, 50);

	game->EventHandler = EventHandler;
	game->Update = Update;
	game->Render = Render;
}

int Initialise(Game* game, char* gameName)
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		game->isRunning = 0;
		return 0;
	}

	// Create window
	game->window = SDL_CreateWindow(gameName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->windowHeight, game->windowWidth, SDL_WINDOW_SHOWN);
	if (game->window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		game->isRunning = 0;
		return 0;
	}

	// Create renderer
	game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (game->renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		game->isRunning = 0;
		return 0;
	}
	SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	game->isRunning = 1;

	game->timeLastFrame = SDL_GetTicks();
	game->keyStates = SDL_GetKeyboardState(NULL);

	return 1;
}

void EventHandler(Game* game)
{
	SDL_PollEvent(&game->event);

	//Player player = game->player;

	if (game->event.type == SDL_QUIT || game->keyStates[SDL_SCANCODE_ESCAPE])
	{
		game->isRunning = 0;
	}

	if (game->keyStates[SDL_SCANCODE_SPACE])
	{
		if (game->player.isJumping == 0 && game->player.grounded == 1)
		{
			game->player.isJumping = 1;
		}
	}
	if (game->keyStates[SDL_SCANCODE_A] || game->keyStates[SDL_SCANCODE_LEFT])
	{
		game->player.leftRight = -1;
	}
	else if (game->keyStates[SDL_SCANCODE_D] || game->keyStates[SDL_SCANCODE_RIGHT])
	{
		game->player.leftRight = 1;
	}
	else
	{
		game->player.leftRight = 0;
	}

}

void Update(Game* game)
{
	Uint32 currentTime = SDL_GetTicks();
	Uint32 deltaTimeMs = currentTime - game->timeLastFrame;
	float deltaTime = deltaTimeMs / 1000.0f; // Convert to seconds
	game->timeLastFrame = currentTime;

	//printf("player.baseobject.velocityY %i\n",game->player.baseObject.velocityY);

	game->player.baseObject.velocityX = game->player.playerSpeed * game->player.leftRight;


	//printf("player.isjumping %i\n", game->player.isJumping);
	if (game->player.isJumping == 1)//issue with jump being possible to do forever
	{
		//printf("player.jumpvelocity %i\n", game->player.playerJumpVelocity);
		game->player.grounded = 0;
		game->player.baseObject.velocityY = game->player.playerJumpVelocity;
		game->player.isJumping = 0;
		printf("at end of jump Player.velocity Y %i\n", game->player.baseObject.velocityY);
	}
	if (game->player.baseObject.objectPositionY + game->player.baseObject.objectHeight / 2 <= game->ground.objectPositionY)
	{
		game->player.baseObject.velocityY += game->player.baseObject.gravity * deltaTime;
		game->player.grounded = 1;
		game->player.baseObject.velocityY = 0;
		game->player.baseObject.objectPositionY = game->ground.objectPositionY - game->player.baseObject.objectHeight;
		game->player.isJumping = 0;
		printf("if in air Player.velocity Y %i\n", game->player.baseObject.velocityY);
	}
	else
	{
		game->player.grounded = 0;
	}


	printf("at end of update Player.velocity Y %i\n", game->player.baseObject.velocityY);
	game->player.update(&game->player, deltaTime);

	game->ground.update(&game->ground, deltaTime);
}

void Render(Game* game)
{
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255, 255);
	SDL_RenderClear(game->renderer);

	game->player.baseObject.render(&game->player.baseObject, game->renderer, 0, 0, 255, 255);

	game->ground.render(&game->ground, game->renderer, 0, 255, 0, 255);

	SDL_RenderPresent(game->renderer);
}

void CloseGame(Game* game)
{
	SDL_DestroyRenderer(&game->renderer);
	SDL_DestroyWindow(&game->window);
	SDL_Quit();
}
