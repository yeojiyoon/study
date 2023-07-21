#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib")

const unsigned int WIN_W = 300;
const unsigned int WIN_H = 300;

int main(void)
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "Hello GLFW", NULL, NULL);
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
