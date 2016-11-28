#pragma once

#include "Interfaces.h"
#include "Matrix.h"
#include <windows.h>
#include "glad.h"
#include "Util.h"
#include <GLFW/glfw3.h>

#ifdef GLAD_DEBUG
inline void PreGLCall(const char *name, void *funcptr, int len_args, ...)
{
	//Util::DebugPrintF("Calling: %s (%d arguments)\n", name, len_args);
}

inline void PostCallback(const char *name, void *funcptr, int len_args, ...) {
	GLenum error_code;
	error_code = glad_glGetError();

	if (error_code != GL_NO_ERROR)
	{
		Util::DebugPrintF("ERROR %d in %s\n", error_code, name);
	}
}
#endif

inline void DefaultKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	Util::DebugPrintF("Pressed key: %i\n", key);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

class GLDrawContext 
{
public:
	GLDrawContext();
	~GLDrawContext();

	bool Init();
	void BeginScene();
	void Draw() const;
	void EndScene() const;
	GLFWwindow* GLDrawContext::GetWindow() const;
	void Release() const;

	
	std::string LoadShaderFromFile(const char* filename) const;
	GLuint LoadShaderProgramFromFile(const char* filename) const;
	GLuint LoadShader(const char*, GLenum type) const;
	GLuint LoadShaderProgram(const char* vs_text, const char* fs_text)const;

private:
	DisplayState m_currentDisplayState;
	GLuint m_vaoId;
	
	GLfloat m_clearColor[4];
	float m_clearDepth;
	GLFWwindow* m_window;

	Matrix m_worldMatrix;
	Matrix m_projectionMatrix;
};
