#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---
#Documentation

 1. Open up a new empty win32 app project on Microsoft Visual Studio 2010.
 
 2. Download the SDL Development Library for windows found in the following link: [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)
	 
 3. Also download the SDL GFX library using the following link: [http://cms.ferzkopp.net/index.php/software/13-sdl-gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)
 
 4. Create a SDL folder in the Visual Studio directory and copy both the extracted SDL Development Library and the SDL GFX library into the folder.
 
 5. Copy the main.cpp to the source file in the solution explorer of your project.
 
 6. Right click the name of your project and select the properties tab. In the configuration properties under the C/C++ tab, add the following additional include directories: 
	 > $(SolutionDir)\SDL\SDL2_gfx-1.0.1 
	
	 > $(SolutionDir)\SDL\SDL2-2.0.3\include
    
 7. Still in the solution properties, go to the linker tab and select the input tab. Add the following libraries in the additional dependencies:
	> SDL2.lib

	>SDL2main.lib

 8. Depending on your operating system, copy either the x86 or x64 SDL2.dll to the debug folder of your solution.

 9. Add the following lines of code at the start of main.cpp: 
	
	`#include <iostream>`

	`#include <SDL.h>`
	
	`#include <SDL2_gfxPrimitives.h>`
	
	`#undef main` 

 10. Comment out the following line of code within main.cpp:
	
	`SDL_DestroyTexture(tex);`

 11. Build the program and it should work.
