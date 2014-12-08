#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---
Insert documentation here

Using eclipse kepler on mac OSX

1.) Download SDL framework from http://www.libsdl.org/download-2.0.php then copy paste the SDL framework in your Library/Frameworks
2.) make a new C++ project with executable Hello World C++ Project and name it main.cpp
3.) right click your project then click properties->c/c++ Build->Settings->Tool Settings tab->Miscellaneous and this to the linker flags "-framework SDL2 -framework Cocoa" without the quotes
4.) Copy Paste the Main.cpp from github and modify it to look like this:

#include <SDL2/SDL.h>
#include <iostream>
#include "SDL2_gfxPrimitives.h"
int main() {

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

	bool running = true;

	while (running) {
		SDL_Event ev;
		while(SDL_PollEvent(&ev) != 0) {
			if(ev.type == SDL_QUIT) running = false;
		}
		SDL_RenderClear(ren);

		roundedBoxColor(ren, 40, 40, 240, 240, 10, 0xFABCA0FF);

		SDL_RenderPresent(ren);
		SDL_Delay(2000);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

where you add those 3 headers at the top and comment/delete the SDL_DestroyTexture(tex); at the bottom 

5.) Download SDL2_gfx from http://cms.ferzkopp.net/index.php/software/13-sdl-gfx
6.) unzip your SDL2_gfx and add these files to where your project directory is
    SDL2_gfxPrimitives.h
    SDL2_gfxPrimitives.c
    SDL2_gfxPrimitives_font.h
    SDL2_rotozoom.c
    SDL2_rotozoom.h
    
7.) change SDL2_gfxPrimitives.h and SDL2_rotozoom.h's line where it says #include "SDL.h" to
#include "SDL2/SDL.h"
8.) Build and run it

