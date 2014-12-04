//Downloaded MSys to use Unix commands

// Referred to http://lemonlauncher.sourceforge.net/mingw for steps to install SDL 1.2 and SDL_gfx

// Referred to http://stackoverflow.com/questions/15570768/sdl-gfx-2-0-24-dll-is-not-build-using-mingw to fix make error involving SDL_gfxPrimitives.h

// Encountered lots of errors with SDL 1.2 and decided to change to 2.0

// Copied all files in C:\Compilers\MSys\1.0\home\src\SDL2-2.0.3\i686-w64-mingw32 to C:\Compilers\MinGW

// Referred to http://stackoverflow.com/questions/22446008/winapifamily-h-no-such-file-or-directory-when-compiling-sdl-in-codeblocks to fix make error involving SDL_platform

// Added the ff includes:
#include "SDL2/SDL.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <cstddef>
#include <iostream>

// Compile using the ff command: g++ main.cpp -lmingw32 -lSDL_gfx -lSDL2main -lSDL2 -o main -std=c++11

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Run this", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	
	SDL_Surface *sur = SDL_CreateRGBSurface(0, 100, 100, 100, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, sur);
	
	bool running = true;

	while (running) {
		SDL_Event ev;
		while(SDL_PollEvent(&ev) != 0) {
			if(ev.type == SDL_QUIT) running = false;
		}
		SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
		SDL_RenderClear(ren);
		
		roundedBoxColor(sur, 40, 40, 240, 240, 10, 0xFABCA0FF);
		
		SDL_RenderPresent(ren);
		SDL_Delay(100);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}