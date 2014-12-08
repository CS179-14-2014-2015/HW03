#HW03 Compile Me (deadline: 2014-12-09)
===
### Setting Up SDL2 and SDL2_gfx 
#### for Ubuntu 14.04 and Linux Mint 17 with Code::Blocks for development

#### SDL 2 Installation
1) Using bash, install the following SDL2 core and library extensions using aptitude with root access:
	
```bash
apt-get install build-essential libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-ttf-dev
```

2) Type in _ldconfig_ as root in your terminal to load the libraries.

#### SDL2_gfx Installation

1) Go ahead and download [SDL2_gfx](http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.1.tar.gz).

2) Extract it and go to the extracted folder using your terminal.

3) As per source instructions type in the following: 

```bash
././autogen.sh    
./configure     # This checks your system configuration
make            # This generates the Makefile for compilation    
make install    # Make sure to run this with root privileges
```

4) The SDL2_gfx library should now be in your system, specifically under /usr/local/lib and /usr/local/include.

_cd_ into __test__ from the extracted directory you downloaded earlier.

Now rerun the commands below to compile the test files:

```bash
./autogen.sh    
./configure     
make            
```

To check if compilation has been successful, run the test programs such as _testrotozoom_ by typing in:

```bash
./rotozoom
```

A window should appear with a picture having various zoom effects.

#### Setting Up Code::Blocks

1) From the Makefile in your __test__ directory, you should see something similar to this assigned to _LIBS_ :

```bash
-lSDL2_test -Wl,-rpath,/usr/local/lib -L/usr/local/lib -lSDL2 -lpthread   -lSDL2_gfx 
```

2) Copy this to you clipboard and open Code::Blocks. Go to Settings > Compiler > Compiler Settings > Other options.
Go ahead and paste this to the blank text box.
Do this also on the text box under Linker Settings > Other linker options.
Also, don't forget to enable C++0x if you're using C++11/14 under Compiler Options.

#### For the Homework

1) Simply include SDL2, SDL2_gfx, and iostream:

```cpp
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
```

2) Comment-out the non-existing _tex_ statement:

```cpp
SDL_DestroyTexture(tex);
```

Build it, and you're good to go!
