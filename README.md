#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---
### Linux

* Install SDL2
	+ cd ~
	+ sudo apt-get install mercurial
	+ hg clone http://hg.libsdl.org/SDL (take a coffe...)
	+ cd SDL/
	+ ./autogen.sh
	+ ./configure
	+ make
	+ sudo make install
	+ sudo ldconfig
	
* Install SDL2_gfx
	+ cd ~
	+ wget http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.1.zip 
	+ unzip SDL2_gfx-1.0.1.zip
	+ cd SDL2_gfx-1.0.1/
	+ sudo chmod +x autogen.sh	
	+ ./autogen.sh
	+ ./configure
	+ make
	+ sudo make install
	+ sudo ldconfig

* Delete useless files
	+ rm -rf ~/*SDL*

* Compile the programm
	+ go to HW03 folder
	+ g++ -std=c++0x -c main.cpp
	+ g++ -o testSDL main.o -lSDL2 -lSDL2_gfx

* Run it! 
	+ ./testSDL
