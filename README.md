# ChafaCAD

## Requirements

- clang
- [GLEW](https://glew.sourceforge.net)
- [GLFW](https://www.glfw.org)

## References

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
