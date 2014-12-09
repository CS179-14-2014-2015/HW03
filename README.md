#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

<hr>

Resources used:
MinGW
MSys
Command Line

Referred to http://lemonlauncher.sourceforge.net/mingw for steps to install SDL 1.2 and SDL_gfx.

Referred to http://stackoverflow.com/questions/15570768/sdl-gfx-2-0-24-dll-is-not-build-using-mingw to fix a make error involving ```SDL_gfxPrimitives.h```.

Encountered lots of ```not declared in scope``` errors with SDL 1.2.

Assuming the problem had something to do with the differing versions, decided to install SDL 2.0 instead, attempting and failing to follow the same instructions used to install SDL 1.2.

Instead, copied all files in my ```\SDL2-2.0.3\i686-w64-mingw32``` folder to ```\MinGW```.

Referred to http://stackoverflow.com/questions/22446008/winapifamily-h-no-such-file-or-directory-when-compiling-sdl-in-codeblocks to fix a make error involving SDL_platform.

All errors disappeared except for the ones involving SDL_gfx functions.

Assuming the problem had something to do with the differing versions again, decided to install SDL2_gfx as well, attempting and similarly failing to follow the same instructions used to install SDL_gfx.

Since the problem seemed to be coming from the fact that the SDL2_gfx folder didn't have a ```Makefile.mingw``` file unlike SDL_gfx, copied it from SDL_gfx to SDL2_gfx and edited the filenames within the file to match those in the SDL2_gfx folder.

Added the ff includes:
```
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include <cstddef>
#include <iostream>
```

Compiled using the ff command: g++ main.cpp -lmingw32 -lSDL2_gfx -lSDL2main -lSDL2 -o main -std=c++11