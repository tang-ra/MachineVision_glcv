// MachineVision_glcv.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"resource.h"
#include<Winuser.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);	//���ڴ�С�ı�ص�����
void processInput(GLFWwindow *window);		//�����ص�
void commandFun(WPARAM wParam, LPARAM lParam);	//��ť�ص�

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
HWND hwnd;			//ȫ�ִ��ھ��
HDC hdc;			//ȫ���豸����
HGLRC hglrc;		//ȫ����Ⱦ����
HINSTANCE hinstance;	//ȥ�ִ���ʵ��


int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//hwnd = glfwGetWin32Window(window);
	hwnd = GetActiveWindow();
	if (!hwnd)
		std::cout << "hwnd null";
	hinstance = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
	HMENU hMenu = LoadMenu(hinstance, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hwnd, hMenu);


	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCammandCallback(window, commandFun);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	std::cout << "The Opencv version used is: " << cv::getVersionString();

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// �����������룺��ѯGLFW��֡�Ƿ���/�ͷ���ؼ��������ǵ�
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw��ÿ�����ڴ�С�ı�ʱ��ͨ������ϵͳ���û�������С��������ص������ͻ�ִ��
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//ȷ���Ӵ����µ��Ӵ��ߴ���ƥ�䣻ע���Ⱥ�
	//�߶Ƚ����Դ�������Ĥ��ʾ����ָ���ĸ߶ȡ�
	glViewport(0, 0, width, height);
}

// ��ť�¼��ص�����
// ---------------------------------------------------------------------------------------------
void commandFun(WPARAM wParam, LPARAM lParam)
{
	WORD id = LOWORD(wParam);
	switch (id)
	{
	case IDM_FILE_NEW:
		break;
	default:
		MessageBox(hwnd, L"No Command Handle", 0, MB_ICONEXCLAMATION);
		break;
	}
	return;
}
		
