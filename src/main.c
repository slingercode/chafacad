#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#define CHAFACAD "ChafaCAD"

void error_callback(int error, const char* description) {
    fprintf(stderr, "Error [%d]: %s\n", error, description);
}

/*
 * [GLFW documentation - Window closing and close flag](https://www.glfw.org/docs/latest/window_guide.html#window_close)
 */
void close_window_callback(GLFWwindow* window) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void key_window_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        close_window_callback(window);
    }
}

int main(void) {
    glfwSetErrorCallback(error_callback);

    /* Initialize GLFW */
    if (!glfwInit()) {
        fprintf(stderr, "Error: There was an error trying to initialize GLFW\n");

        return 1;
    }
    
    /* MacOS only. Set the maximum OpenGL version available */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(640, 480, CHAFACAD, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Error: Could not create a window\n");
        glfwTerminate();

        return 1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    /* Initialize GLEW */
    glewInit();

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported: %s\n", version);

    /* Set close callback when the windows is going to be closed */
    glfwSetWindowCloseCallback(window, close_window_callback);

    /* Set the keys callback */
    glfwSetKeyCallback(window, key_window_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
