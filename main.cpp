#include <iostream>
#include <SDL.h>
#include <gfx/SDL2_gfxPrimitives.h>
//http://wiki.libsdl.org/APIByCategory
//whatever man just redirect to the /include and /lib paths.....

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Run this", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 720, 720, SDL_WINDOW_SHOWN);
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

	/*SDL_Texture *tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STATIC, 720, 720);
	if (tex == nullptr){
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}*/

	SDL_Surface *background = SDL_LoadBMP("potato.bmp");
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, background);
	SDL_FreeSurface(background);

	bool running = true;

	float s = 0;
	float t = 0;
	int x = 240;

	while (running) {
		SDL_Event ev;
		while(SDL_PollEvent(&ev) != 0) {
			if(ev.type == SDL_QUIT) running = false;
		}
		SDL_RenderClear(ren);

		SDL_Rect rect = {s,s,x,x};

		SDL_RenderCopy(ren, tex, NULL, &rect);

		//roundedBoxColor(ren, t, t, x, x, 10, 0xFABCA0FF);
	
		roundedBoxColor(ren, 40, 40, 240, 240, 10, 0xFABCA0FF);
		




		//to keep the bg black
		roundedBoxColor(ren, 0, 0, 1, 1, 0, 0x00000000);
		
		SDL_RenderPresent(ren);
		//SDL_Delay(2000);
		
		s+=0.5;
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
