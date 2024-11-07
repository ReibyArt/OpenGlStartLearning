// Next Hello Triangle Chapter //

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
	/*std::cout << "HellO!";*/

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLReibyArtGames", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create a window GLFW!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed To Initialize GLAD!" << std::endl;
		return -1;
	}
	// Call Functions // 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// Render // 
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		// Render Command Must Be Here //
		// Change Window Color //

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.4f,0.3f,1.0f);

		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

// PROTOTYPE OF FUNCTION //
// Changes Size of Screen
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// Input Key Escape
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
