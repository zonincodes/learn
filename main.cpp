#include <iostream>
#include <GLFW/glfw3.h>



void window_size_callback(GLFWwindow *window, int width, int height)
{
    glfwSetWindowSize(window, width, height);
}

// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }

int main()
{

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    GLFWwindow *window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
       // Main loop
       glfwSetWindowTitle(window, "My Window");


    while( !glfwWindowShouldClose(window) )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetWindowSizeCallback(window, window_size_callback);
        // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    // Terminate GLFW
    glfwTerminate();




    return 0;
}
