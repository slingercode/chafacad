# ChafaCAD

## Requirements

- clang
- [Raylib](https://www.raylib.com/)

## Local Installation

1. Clone Raylib
2. Build the application in order to obtain the `libraylib.a` file
3. Copy the `libraylib.a` from the raylib source code into the chafacad `lib` folder
4. Copy the required raylib headers from the raylib source code into the chafacad `include` folder

- I use the font [Berkeley Mono](https://berkeleygraphics.com/typefaces/berkeley-mono) (🐐) so the configuration expects this font

## References

- [Raylib - Working on MacOS](https://github.com/raysan5/raylib/wiki/Working-on-macOS)
- [themutti - Raylib installation](https://github.com/themutti/raylib-installation)

### Old References

This links are from my previous version that was using GLEW and GLFW but I'm
keeping them in order to create an archive

- [Some interesting post in reddit](https://www.reddit.com/r/opengl/comments/199433i/how_can_i_setup_opengl_for_development_on_an_m2/?share_id=PtuJHyXrNGdZehrqYYZTM&utm_content=1&utm_medium=ios_app&utm_name=ioscss&utm_source=share&utm_term=1)
- [OpenGL tutorial](https://www.opengl-tutorial.org/)
- [Triangle](https://antongerdelan.net/opengl/hellotriangle.html)
- [Triangle solved](https://github.com/dmsurti/hello_triangle/blob/master/main.c)

## Personal comments

- Apparently, OpenGL in MacOS and the M lineup is kinda special.
  So my option is this: use the last supported OpenGL version (4.1) with GLEW and use GLFW
- I spend like 1.5 hours trying to make the basic glfw example... there are some important
  steps in order to link the library into the project. ([this is a nice help](https://stackoverflow.com/questions/60894143/linking-glew-and-glfw3-on-mac-on-command-line))

  So... we need to link to the path that brew install it. in the build its the solution.
