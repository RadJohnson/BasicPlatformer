#include <stdio.h>
#include <SDL.h>
#include <SDL_Timer.h>

#include "Game.h"; 


//// Define constants
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//const int PLAYER_WIDTH = 50;
//const int PLAYER_HEIGHT = 50;
//const int PLAYER_SPEED = 200;
////const float PLAYER_DRAG = 0.5;
//const int GRAVITY = 5;
//const int JUMP_VELOCITY = -500;
//const int GROUND_LEVEL = 600 - 50 - 50;//this should and will be changed
//
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
		//printf("Before Update - Ground Position - X: %d, Y: %d\n", game.player.baseObject.objectPositionX, game.player.baseObject.objectPositionY);
		game.Update(&game);
		//printf("Ground Position during Update - X: %d, Y: %d\n", game.player.baseObject.objectPositionX, game.player.baseObject.objectPositionY);

		game.Render(&game);
		SDL_Delay(FRAME_DELAY);

	}

	//printf("returns from loop prematurely");

	CloseGame(&game);



	/*

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create window
	SDL_Window* window = SDL_CreateWindow("Basic Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Main game loop
	int quit = 0;
	SDL_Event event;

	// Player properties
	int playerX = 100;
	int playerY = 100;
	int playerGrounded = 0;
	int velocityX = 0;
	int velocityY = 0;
	int isJumping = 0;

	int leftRight = 0;//when value is positive will allow for right velocity and if necgative will allow for left velocity

	Uint32 timeLastFrame = SDL_GetTicks();
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	while (!quit)
	{

		// Calculate delta time
		Uint32 currentTime = SDL_GetTicks();
		Uint32 deltaTimeMs = currentTime - timeLastFrame;
		float deltaTime = deltaTimeMs / 1000.0f; // Convert to seconds
		timeLastFrame = currentTime;

		leftRight = 0;
		// Event handling
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = 1;
			}

			if (keystates[SDL_SCANCODE_SPACE])
			{
				if (isJumping == 0 && playerGrounded == 1)
				{
					isJumping = 1;
				}
			}
			if (keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_LEFT])
			{
				leftRight = -1;
			}
			else if (keystates[SDL_SCANCODE_D] || keystates[SDL_SCANCODE_RIGHT])
			{
				leftRight = 1;
			}
			else
			{
				leftRight = 0;
			}
		}



		velocityX = PLAYER_SPEED * leftRight;

		if (isJumping == 1)//issue with jump being possible to do forever
		{
			playerGrounded = 0;
			velocityY += JUMP_VELOCITY;
			isJumping = 0;
		}
		// Apply gravity
		if (playerY <= GROUND_LEVEL)
		{
			velocityY += GRAVITY;
		}
		else
		{
			playerGrounded = 1;
			velocityY = 0;
			playerY = GROUND_LEVEL;
			isJumping = 0;
		}

		// Update player position
		playerY += (int)velocityY * deltaTime;
		playerX += (int)velocityX * deltaTime;

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Draw player (a simple rectangle for now)
		SDL_Rect playerRect = { playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT };
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &playerRect);

		// Draw ground
		SDL_Rect groundRect = { 0, GROUND_LEVEL + PLAYER_HEIGHT, SCREEN_WIDTH, 50 };
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, &groundRect);

		// Update screen
		SDL_RenderPresent(renderer);

		// Delay to control frame rate
		SDL_Delay(FRAME_DELAY);
	}

	// Clean up
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	*/

	return 0;
}



