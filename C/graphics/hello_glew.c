#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

int main(void)
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(300, 300, "Hello GLEW", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
