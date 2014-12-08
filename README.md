#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---
Steps in setting up SDL2 in VS2010 

1. Download the SDL2 Libary
	-> Go to the SDL website: https://www.libsdl.org/download-2.0.php
	-> Download the latest SDL2 development library entitled: SDL2-devel-2.0.3-VC.zip
2. Extract the contents of the Library on your desktop.
3. Within the Extract contents find the include folder.
	-> Copy everything inside the include folder.
	-> Navigate to C:\Program Files\Microsoft Visual Studio 10.0\VC\include
	-> Create a new folder in the said directory and name it SDL2
	-> Paste everything that was copied earlier from the extracted include folder 
4. Within the Extracted SDL2 library find the lib folder.
	-> Go to the x86 folder and copy SDL2.lib and SDL2main.lib
	-> Navigate to C:\Program Files\Microsoft Visual Studio 10.0\VC\lib
	-> Create a new folder in the said directory and name it SDL2
	-> Paste SDL2.lib and SDL2main.lib here.
5. Within the extracted SDL2 library find the lib folder again
	-> Go to the x86 folder and copy the SDL2.dll file
	-> Go to Windows\System32 and paste the SDL2.dll file there.
6. Create an empty project in Visual Studio 10 under VC++
	-> Go to Project -> Properties.
	-> Click on Linker->General->Additional Libraries
	-> on Additional Library Directories type in: C:\Program Files\Microsoft Visual Studio 10.0\VC\lib\SDL2
	-> Click on Linker -> Input -> Additional Dependencies
	-> on Additional Dependencies type in: SDL2.lib; SDL2main.lib;
	-> Click on Linker -> System -> Subsystem and choose Console;
	-> Click on the Apply bottom at the lower right corner of the Properties Screen.
	-> Take a look at the Solution Explorer.
	-> Right Click on Source Files: Add -> New Item
	-> Add a C++ file and name it as main.cpp
	-> In main.cpp in order to test if the library is working successfuly try the ff code:
	
	Code:
	
	#include <SDL2\SDL.h>
	#include <iostream>


	using namespace std;

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	int main(int argc, char *args[])
	{
		SDL_Window *window = NULL;
		SDL_Surface *screenSurface = NULL;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			cout << "SDL Could not initialize due to: " << SDL_GetError() << endl;
		}	

		else
		{
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				cout << "Window could not be generated due to: " << SDL_GetError() << endl;
			}
			else
			{
				screenSurface = SDL_GetWindowSurface(window);
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
				SDL_UpdateWindowSurface(window);
				SDL_Delay(2000);
			}
		}

		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
	
	-> If you receive an error like link.exe exited with code 1 in order to resolve it just navigate to C:\Windows and find link.exe and delete it.
	-> Rebuild the project and run it. It should produce a window with the screen filled with the color red.

BEFORE PROCEEDING:

Using the project that was set up earlier for SDL2 replace the contents of the main function of your project's main.cpp file to that of the contents of the main function in HW03's main.cpp file 
	
STEPS IN MAKING THE MAIN.CPP IN THE HW WORK.

1. Download the SDL2_gfx library in the link: http://cms.ferzkopp.net/index.php/software/13-sdl-gfx
	-> Pick the one for the older version named: SDL2_gfx-1.0.0.tar.gz
	-> This one has the VS2010 solution to check the header and c files of the library and test it out as well.
2. Extract the contents of the library on your desktop.
3. For the HW we specifically need these 3 headers and 2 c files.
	-> SDL2_gfxPrimitives.h, SDL2_rotozoom.h,SDL2_gfxPrimitives_font.h
	-> SDL2_gfxPrimitives.c, SDL2_rotozoom.c
4. Use a text editor like notepad++ to edit the SDL2_gfxPrimitives.h and SDL2_rotozoom.h
	-> change #include "SDL.h" to #include <SDL2\SDL.h> and save your changes.
5. Copy the header files mentioned above along with the c files and put it within your project's solution folder.
6. Right Click on your project-> Add -> Existing items.
	-> Add the files you just copied to your project folder.
7. In the main.cpp which now contains the contents of the main function written in HW03 make the following changes:

	-> Add: #include "SDL2_gfxPrimitives.h"
	-> Comment out: DestroyTexture(tex);
	
8. If you run the project it should produce a pink rectangle and end with a pink window.