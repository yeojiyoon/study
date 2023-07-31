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

const char* vertSource =
"#version 330 core \n\
in vec4 vertexPos; \n\
void main(void) { \n\
	gl_Position = vertexPos; \n\
}";

const char* fragSource =
"#version 330 core \n\
out vec4 FragColor; \n\
void main(void) { \n\
	FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n\
}";

GLuint vert = 0;
GLuint frag = 0;
GLuint prog = 0;

void initFunc(void)
{
	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vertSource, NULL);
	glCompileShader(vert);

	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragSource, NULL);
	glCompileShader(frag);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog);

	glUseProgram(prog);
}

GLfloat vertPos[] = {
	-0.5F, -0.5F, 0.0F, 1.0F,
	+0.5F, -0.5F, 0.0F, 1.0F,
	-0.5F, +0.5F, 0.0F, 1.0F,
};

void drawFunc(void) {
	// clear in gray color
	glClear(GL_COLOR_BUFFER_BIT);
	// provide the vertex attributes
	GLuint loc = glGetAttribLocation(prog, "vertexPos");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, vertPos);
	// draw a triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// done
	glFinish();
}

void refreshFunc(GLFWwindow* window)
{
	//refresh
	drawFunc();
	//GLFW action
	glfwSwapBuffers(window);
}

void keyFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		break;
	}
}

int main(int argc, char* argv[]) {
	// start GLFW & GLEW
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "basename", NULL, NULL);
	glfwSetWindowPos(window, WIN_X, WIN_Y);
	glfwMakeContextCurrent(window);
	glewInit();
	// prepare
	glfwSetWindowRefreshCallback(window, refreshFunc);
	glfwSetKeyCallback(window, keyFunc);
	glClearColor(0.5F, 0.5F, 0.5F, 1.0F);
	// main loop
	initFunc();
	while (! glfwWindowShouldClose(window)) {
		// draw
		drawFunc();
		// GLFW actions
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// done
	glfwTerminate();
	return 0;
}
