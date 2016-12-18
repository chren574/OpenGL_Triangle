#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


int main()
{
	std::cout << "Init\n";
	glfwInit();
	// Only OpenGL 3 is used
	// ENUM: GLFW_CONTEXT_VERSION_MAJOR, VALUE: 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Errors if legacy code is used
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Not resizeble by the user
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// etting glewExperimental to true ensures GLEW uses more modern techniques for managing OpenGL functionality. 
	// Leaving it to its default value of GL_FALSE might give issues when using the core profile of OpenGL.
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW\n";
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);


	// RENDER LOOP
	while (!glfwWindowShouldClose(window))
	{
		// Checks if any events are triggerd (keyboard, mouse...)
		glfwPollEvents();
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

