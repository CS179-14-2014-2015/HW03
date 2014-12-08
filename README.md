#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---
How to set up SDL2 and SDL_gfx in Visual Studio 2010/2012

* Download the SDL2 Development Library
	* https://www.libsdl.org/download-2.0.php
	* as of 12/8/2014, the most recent version is SDL2-devel-2.0.3-VC.zip
* Extract contents to wherever you want to keep it (such as a collection of all headers and libraries you use for Visual Studio)
	* For the purposes of this documentation, we will assume you put it in a folder labeled 'SDL' and will be referred to as the "SDL folder"
	* Inside the SDL folder, there should be two folders: /include and /lib. You'll be using these later on.
* Download SDL2_gfx
	* http://cms.ferzkopp.net/index.php/software/13-sdl-gfx
	* as of 12/8/2014, the most recent version is SDL2_gfx-1.0.1.zip
* Extract to a memorable location, such as alongside the SDL folder. For the purposes of this documentation, this folder will be referred to as the "SLD2_gfx folder"

--Setting up SDL and SDL2_gfx--
* Start an empty Win32 Console App under VC++ on Visual Studio 
* Drag main.cpp to the Source Files area of the project's Solution Explorer
* Inside the SDL2_gfx folder, copy all the .h and .c files
	* There should be 4 .c files and 5 .h files
* Go to your SDL folder's include folder, and make a new folder inside it called 'gfx'
	* Paste the .h and .c files inside 'gfx'
		* Drag the .c files to the Resource Files area of the project's Solution Explorer
* Right click on the project and go to Properties
* Under Configuration Properties > C/C++ > General > Additional Include Directories, add the /include folder from the SDL folder
* Under Configuration Properties > Linker > General > Additional Library Directories, add the /lib/x86 folder from the SDL folder
	* Under Configuration Properties > Linker > Input > Additional Dependencies, make sure you add SDL2.lib and SDL2main.lib
* Click OK
* Inside the /lib/x86 folder, copy SDL2.dll and paste it inside the project's solution folder
	* To be more specific, paste them in the same place as where the .vcxproj files are at
		* Also, make sure to have some random .BMP file named "potato.bmp" in this folder (bonus points if it's an actual potato with a black background)
* Run the program
* If set up correctly, the program should display a static transluscent pink square & a moving copy of potato.bmp
* main.cpp can then be swapped out for other .cpp files that require both SDL and SDL2_gfx


--Changes made to vanilla main.cpp to get it to run and display that weird pink square--
* add ` 
#include <iostream>
#include <SDL.h>
#include <gfx/SDL2_gfxPrimitives.h>
` to very top of cpp
* change int main() to int main(int argc, char* argv[])
* comment out SDL_DestroyTexture(tex); (because no texture was ever initialized)