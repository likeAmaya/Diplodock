#pragma once

#include <windows.h>
#include <TextureAndLightingPCH.h>

#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/freeglut.h>


#include "Form1.h"

using namespace System::Windows::Forms;


namespace OpenGLForm 
{
	public enum class LighterType { Parallel, Omni, Spot, No };

	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}

			rtri = 0.0f;
			rquad = 0.0f;
		}


		System::Void Render(System::Void)
		{
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
			//glTranslatef(-1.5f,0.0f,-6.0f);						// Move left 1.5 units and into the screen 6.0

			glTranslatef(_xTriangleTranslate, _yTriangleTranslate, _zTriangleTranslate);
			glRotatef(_xTriangleRotate, 1.0f, 0.0f, 0.0f);
			glRotatef(_yTriangleRotate, 0.0f, 1.0f, 0.0f);
			glRotatef(_zTriangleRotate, 0.0f, 0.0f, 1.0f);
			glScalef(_xTriangleScale, _yTriangleScale, _zTriangleScale);

			//glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate the triangle on the y axis 
			glBegin(GL_TRIANGLES);								// Start drawing a triangle
				glColor3f(1.0f,0.0f,0.0f);						// Red
				glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (front)
				glColor3f(0.0f,1.0f,0.0f);						// Green
				glVertex3f(-1.0f,-1.0f, 1.0f);					// Left of triangle (front)
				glColor3f(0.0f,0.0f,1.0f);						// Blue
				glVertex3f( 1.0f,-1.0f, 1.0f);					// Right of triangle (front)
				glColor3f(1.0f,0.0f,0.0f);						// Red
				glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (right)
				glColor3f(0.0f,0.0f,1.0f);						// Blue
				glVertex3f( 1.0f,-1.0f, 1.0f);					// Left of triangle (right)
				glColor3f(0.0f,1.0f,0.0f);						// Green
				glVertex3f( 1.0f,-1.0f, -1.0f);					// Right of triangle (right)
				glColor3f(1.0f,0.0f,0.0f);						// Red
				glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (back)
				glColor3f(0.0f,1.0f,0.0f);						// Green
				glVertex3f( 1.0f,-1.0f, -1.0f);					// Left of triangle (back)
				glColor3f(0.0f,0.0f,1.0f);						// Blue
				glVertex3f(-1.0f,-1.0f, -1.0f);					// Right of triangle (back)
				glColor3f(1.0f,0.0f,0.0f);						// Red
				glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (left)
				glColor3f(0.0f,0.0f,1.0f);						// Blue
				glVertex3f(-1.0f,-1.0f,-1.0f);					// Left of triangle (left)
				glColor3f(0.0f,1.0f,0.0f);						// Green
				glVertex3f(-1.0f,-1.0f, 1.0f);					// Right of triangle (left)
			glEnd();											// Done drawing the pyramid

			glLoadIdentity();									// Reset the current modelview matrix
			//glTranslatef(1.5f,0.0f,-7.0f);						// Move right 1.5 units and into the screen 7.0
			//glRotatef(rquad,1.0f,1.0f,1.0f);					// Rotate the quad on the x axis 

			

			glTranslatef(_xCubeTranslate, _yCubeTranslate, _zCubeTranslate);
			glRotatef(_xCubeRotate, 1.0f, 0.0f, 0.0f);
			glRotatef(_yCubeRotate, 0.0f, 1.0f, 0.0f);
			glRotatef(_zCubeRotate, 0.0f, 0.0f, 1.0f);
			glScalef(_xCubeScale, _yCubeScale, _zCubeScale);

			GLfloat mat1_ambient[] = { 0.19225f, 0.19225f, 0.19225f };
			float mat1_diffuse[] = { 0.50754f, 0.50754f, 0.50754f };
			float mat1_specular[] = { 0.508273f, 0.508273f, 0.508273f };
			float mat1_shininess = 0.4f;

			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat1_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat1_diffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat1_specular);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);

			if (_currentLighter == LighterType::No)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT4);
			}
			else if (_currentLighter == LighterType::Parallel) 
			{
				// направленный источник света
				GLfloat light0_diffuse[] = { 0.4, 0.7, 0.2 }; // цвет
				GLfloat light0_direction[] = { 0.0, 0.0, 1.0, 0.0 };
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT4);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
				glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
			}
			else if (_currentLighter == LighterType::Omni)
			{
				// точечный источник света
				// убывание интенсивности с расстоянием
				// задано функцией f(d) = 1.0 / (0.4 * d * d + 0.2 * d)
				GLfloat light2_diffuse[] = { 0.4, 0.7, 0.2 };
				GLfloat light2_position[] = { 0.0, 0.0, 1.0, 1.0 };
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT2);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHT4);
				glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
				glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
				glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
				glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);
				glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.4);
			}
			else if (_currentLighter == LighterType::Spot)
			{
				// прожектор
				// убывание интенсивности с расстоянием
				// отключено (по умолчанию)
				// половина угла при вершине 30 градусов
				// направление на центр плоскости
				// включен рассчет убывания интенсивности для прожектора
				GLfloat light4_diffuse[] = { 0.4, 0.7, 0.2 };
				GLfloat light4_position[] = { 0.0, 0.0, 1.0, 1.0 };
				GLfloat light4_spot_direction[] = { 0.0, 0.0, -1.0 };
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT4);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHT2);
				glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
				glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
				glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30);
				glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction);
				glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 15.0);
			}

			glBegin(GL_QUADS);									// Draw a quad
				glColor3f(0.0f,1.0f,0.0f);						// Set The color to green
				glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right of the quad (top)
				glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left of the quad (top)
				glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom left of the quad (top)
				glVertex3f( 1.0f, 1.0f, 1.0f);					// Bottom right of the quad (top)
				glColor3f(1.0f,0.5f,0.0f);						// Set The color to orange
				glVertex3f( 1.0f,-1.0f, 1.0f);					// Top Right of the quad (bottom)
				glVertex3f(-1.0f,-1.0f, 1.0f);					// Top Left of the quad (bottom)
				glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom left of the quad (bottom)
				glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom right of the quad (bottom)
				glColor3f(1.0f,0.0f,0.0f);						// Set The color to red
				glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Right of the quad (front)
				glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left of the quad (front)
				glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom left of the quad (front)
				glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom right of the quad (front)
				glColor3f(1.0f,1.0f,0.0f);						// Set The color to yellow
				glVertex3f( 1.0f,-1.0f,-1.0f);					// Top Right of the quad (back)
				glVertex3f(-1.0f,-1.0f,-1.0f);					// Top Left of the quad (back)
				glVertex3f(-1.0f, 1.0f,-1.0f);					// Bottom left of the quad (back)
				glVertex3f( 1.0f, 1.0f,-1.0f);					// Bottom right of the quad (back)
				glColor3f(0.0f,0.0f,1.0f);						// Set The color to blue
				glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right of the quad (left)
				glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left of the quad (left)
				glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom left of the quad (left)
				glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom right of the quad (left)
				glColor3f(1.0f,0.0f,1.0f);						// Set The color to violet
				glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right of the quad (right)
				glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Left of the quad (right)
				glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom left of the quad (right)
				glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom right of the quad (right)
			glEnd();											// Done drawing the quad

			//rtri+=0.2f;											// Increase the rotation variable for the triangle
			//rquad-=0.15f;										// Decrease the rotation variable for the quad
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}

	public: 
		GLfloat _xCubeTranslate = 0.0f, _yCubeTranslate = 0.0f, _zCubeTranslate = -6.0f;
		GLfloat _xCubeRotate = 0.0f, _yCubeRotate = 0.0f, _zCubeRotate = 0.0f;
		GLfloat _xCubeScale = 1.0f, _yCubeScale = 1.0f, _zCubeScale = 1.0f;

		GLfloat _xTriangleTranslate = 1.5f, _yTriangleTranslate = 0.0f, _zTriangleTranslate = -7.0f;
		GLfloat _xTriangleRotate = 0.0f, _yTriangleRotate = 0.0f, _zTriangleRotate = 0.0f;
		GLfloat _xTriangleScale = 1.0f, _yTriangleScale = 1.0f, _zTriangleScale = 1.0f;

		LighterType _currentLighter = LighterType::No;

		bool _isCubeSelected = true;
		bool _isProjectorLighterActive = false;
		bool _isDirectedLighterActive = false;
		bool _isSpotLighterActive = false;


	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
				{
					sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
					1,											// Version Number
					PFD_DRAW_TO_WINDOW |						// Format Must Support Window
					PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
					PFD_DOUBLEBUFFER,							// Must Support Double Buffering
					PFD_TYPE_RGBA,								// Request An RGBA Format
					16,										// Select Our Color Depth
					0, 0, 0, 0, 0, 0,							// Color Bits Ignored
					0,											// No Alpha Buffer
					0,											// Shift Bit Ignored
					0,											// No Accumulation Buffer
					0, 0, 0, 0,									// Accumulation Bits Ignored
					16,											// 16Bit Z-Buffer (Depth Buffer)  
					0,											// No Stencil Buffer
					0,											// No Auxiliary Buffer
					PFD_MAIN_PLANE,								// Main Drawing Layer
					0,											// Reserved
					0, 0, 0										// Layer Masks Ignored
				};
			
			GLint  iPixelFormat; 
		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations

			glEnable(GL_LIGHTING);
			// двухсторонний расчет освещения
			glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
			// автоматическое приведение нормалей к
			// единичной длине
			glEnable(GL_NORMALIZE);
			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height==0)										// Prevent A Divide By Zero By
			{
				height=1;										// Making Height Equal One
			}

			glViewport(0,0,width,height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	};
}