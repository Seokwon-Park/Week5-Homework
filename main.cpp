#include <GLFW\glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <vector>

#include "math.h"
#include "GeometricObject.h"


const int width = 640;
const int height = 480;
int num_lines = 5;
int num_boxes = 10;
int num_circles_x = 5; 
int num_circles_y = 4;
//num_circles
double xpos, ypos;
//Mouse Location x, y;

float* pixels = new float[width*height * 3];


//Line **my_lines = new Line*[num_lines];
//Box **my_boxes = new Box*[num_boxes];

std::vector<GeometricObject*> ob_list;


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}



void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}
	for (int i = 0; i < num_circles_x; i++)
	{
		for (int j = 0; j < num_circles_y; j++)
		{
			double f;
			f = (xpos - (i * 128 + 64))*(xpos - (i * 128 + 64)) + ((height - ypos) - (j * 120 + 60))*((height - ypos) - (j * 120 + 60)) - 2500;

			if (f < 0.0f)
			{
				ob_list.push_back(GeometricObject::getGeometricObject("Circle", i, j, NULL, NULL, 50, 3, 0.0f, 1.0f, 0.0f));
			}
			else
			{
				ob_list.push_back(GeometricObject::getGeometricObject("Circle", i, j, NULL, NULL, 50, 3, 1.0f, 0.0f, 0.0f));
			}
		}
	}
	//TODO: anti-aliasing

	for (auto itr : ob_list)
	{
		itr->draw();
	}

	//TODO: try moving object
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		ob_list.push_back(GeometricObject::getGeometricObject("Line", 34 + i * 128, 30, 94 + i * 128, 90, NULL, 3, 0, 0, 0));
		ob_list.push_back(GeometricObject::getGeometricObject("Line", 34 + i * 128, 90, 94 + i * 128, 30, NULL, 3, 0, 0, 0));
		ob_list.push_back(GeometricObject::getGeometricObject("Circle", i, 1, NULL, NULL, 30, 5, 1.0f, 0.0f, 0.0f));
		ob_list.push_back(GeometricObject::getGeometricObject("Box", i, 3 , NULL, NULL, 60, NULL, 0, 0, 0));
	}

	int ix = 0;	
	int j = 0;
	for (int i = 20; i < (num_circles_x*num_circles_y+20); i++)
	{
		ob_list.push_back(GeometricObject::getGeometricObject("Circle", ix, j, NULL, NULL, 50, 3, 1.0f, 0.0f, 0.0f));
		if (i % 5 ==4)
		{
			j++;
			ix = 0;
		}
		ix++;
	}

	

	//initialize Box
	for (int i = 21; i < 26; i++)
	{
		ob_list.push_back(GeometricObject::getGeometricObject("Box",(i-21), 2, NULL, NULL, 30, NULL,0,0,0));

		//Box *temp = new Box(i * 50, 50, 50);
		//ob_list [i] = temp;
		//my_boxes[i]->initialize(i*50, 50, 30);
	}	
	
		

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Week5", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glfwGetCursorPos(window, &xpos, &ypos);
		/* Render here */

		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	for (auto itr : ob_list)
	{
		delete itr;
	}

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
