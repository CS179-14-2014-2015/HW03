#HW03 Compile Me (deadline: 2014-12-09)
===

Get `main.cpp` to compile and run. Document how you got it to compile below.

The program uses the following libraries:

* [SDL2](http://wiki.libsdl.org/APIByCategory)
* [SDL2_gfx](http://cms.ferzkopp.net/index.php/software/13-sdl-gfx)

The program needs modifications to run (in particular, the `#include`s)

After getting it to run, you may add more stuff to it.

---

1. Download SDL2-devel-2.0.3-VC.zip in the development library section in http://libsdl.org/download-2.0.php

2. Extract the file into the computer. 

3. Download SDL2_gfx-1.0.1.tar.gz in http://cms.ferzkopp.net/index.php/software/13-sdl-gfx

4. Extract the file into the computer

5. Create an empty project in Visual Studios (any name can do)

6. Download the main.cpp for the homework.

7. Copy and paste the main.cpp file into the source files at the solution explorer pane of Visual studios.

8. Right click on the project name at the solution explorer and select properties.

9. Under configuration properties, go to VC++ Directories, select the drop down button on include directories and click <edit>.

10. Click the ... button in the white space and select the path location on where the include folder of SDL2-2.0.3 is. (ex. C:\Users\Marty\Documents\SDL\SDL2(1)\SDL2-2.0.3\include). Then click ok.

11. Click another ... button and select the path location on where the SDL2_gfx-1.0.1 file location is. (ex. C:\Users\Marty\Documents\SDL\SDL2_gfx-1.0.1). Then click ok.

12. Click the drop down button on the library directories and select <edit>.

13. Click the ... button then look for the directory for the x86 folder in SDL2-2.0.3. (ex. C:\Users\Marty\Documents\SDL\SDL2(1)\SDL2-2.0.3\lib\x86). Then click ok.

14. Under the configuration properties, click the arrow beside linker.

15. Under linker, click input.

16. Click the drop down on additional dependencies and select <edit>.

17. Type in the white space SDL2.lib and SDL2main.lib. Then click ok. 

18. Now back to linker, click system. Click the drop down button on SubSystem and select Console (/SUBSYSTEMS:CONSOLE).

19. Click Apply then ok.

20. In the main.cpp file, add in the start:
"#include <SDL.h>"
"#include <SDL2_gfxPrimitives.h>."

21. In main.cpp, look for the code "SDL_DestroyTexture(tex);" and then comment it out.

22. Now right click on the project name at the solution explorer pane, and then select add, and then existing item.

23. Select the "SDL2_gfx-1.0.1" folder and select the files named:
SDL2_gfxPrimitives.h, SDL2_gfxPrimitives_font.h, SDL2_rotozoom.h, SDL2_gfxPrimitives.c, SDL2_rotozoom.c. 
Then click ok.

24. In the main.cpp file, you should see a int main(). Change it to become like this: 
int main(int argc, char* argv[])

25. In the SDL2-2.0.3\lib\x86 location. Copy the SDL2.dll file and paste it into the Windows\System32 directory.

26. Now try to run the program!
