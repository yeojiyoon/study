#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma warning(disable: 4711 4710 4100)
#include <stdio.h>
#include <string.h>

const unsigned int WIN_W = 300;
const unsigned int WIN_H = 300;
const unsigned int WIN_X = 100;
const unsigned int WIN_Y = 100;

void refreshFunc(GLFWwindow* window)
{
	//refresh
	printf("refresh called\n");
	fflush(stdout);
	glClear(GL_COLOR_BUFFER_BIT);
	glFinish();
	//GLFW action
	glfwSwapBuffers(window);
}

GLfloat clr[4] = { 0.933F, 0.769F, 0.898F, 1.0F };

void keyFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case 'Q': clr[0] += 0.01F; if (clr[0] > 1.0F) clr[0] = 1.0F; break;
	case 'W': clr[1] += 0.01F; if (clr[1] > 1.0F) clr[1] = 1.0F; break;
	case 'E': clr[2] += 0.01F; if (clr[1] > 1.0F) clr[2] = 1.0F; break;
	case 'A': clr[0] -= 0.01F; if (clr[0] < 0.0F) clr[0] = 0.0F; break;
	case 'S': clr[1] -= 0.01F; if (clr[1] < 0.0F) clr[1] = 0.0F; break;
	case 'D': clr[2] -= 0.01F; if (clr[2] < 0.0F) clr[2] = 0.0F; break;
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		break;
	}
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
}

int main(int argc, char* argv[])
{
#if defined(_WIN32) || defined(_WIN64)
	char* win_name = (strrchr(argv[0], '\\') == NULL) ? argv[0] : (strrchr(argv[0], '\\') + 1);
#else
	char* win_name = (strrchr(argv[0], '/') == NULL) ? argv[0] : (strrchr(argv[0], '/') + 1);
#endif
	glfwInit(); // start glfw
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, win_name, NULL, NULL);
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window);
	glewInit();
	glfwSetWindowRefreshCallback(window, refreshFunc);
	glfwSetKeyCallback(window, keyFunc);
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glFinish();
		glfwSwapBuffers(window);
		glfwPollEvents(); //loop 동안 키보드 입력을 확인하고 적절한 callback함수를 호출
	}
	glfwTerminate();
	return 0;
}
