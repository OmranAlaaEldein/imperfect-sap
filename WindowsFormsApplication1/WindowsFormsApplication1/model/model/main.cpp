/*
*		This Code Was Created By Jeff Molofee 2000
*		A HUGE Thanks To Fredric Echols For Cleaning Up
*		And Optimizing The Base Code, Making It More Flexible!
*		If You've Found This Code Useful, Please Let Me Know.
*		Visit My Site At nehe.gamedev.net
*/

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <iostream>
#include "Model_3DS.h"
#include "3DTexture.h"
#include "texture.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "Shark.h"
#include "Leaf.h"
#include "Root.h"
#include <glut.h>
#include <math.h>
#include<vector>
#include <string.h>
#include<fstream>
#include<exception>
#include <sstream>

#define WINDOW_TITLE    "Computer Graphics Project"

using namespace std;

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
int  mm = 0;
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();


	// Reset The Modelview Matrix
}


Model_3DS *tree;
Root root;
Shark shark;
Leaf leaf;

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	//the project
	//tree
    glPushMatrix();
	tree = new Model_3DS();
	tree->Load("a.3DS");
	glPopMatrix();
	//picture
	if (root.C_soil >= 0.00810 && root.C_soil < 0.0321)
	{
		mm = LoadTexture("images\\1.bmp", 255);
	}else if (root.C_soil >= 0.0321&&root.C_soil < 0.0621)
	{
		mm = LoadTexture("images\\2.bmp", 255);
	}
	else if (root.C_soil>= 0.0621&&root.C_soil <= 0.0830)
	{
		mm = LoadTexture("images\\3.bmp", 255);
	}
	tree->Materials[0].tex.LoadBMP("images\\101.bmp");
	return TRUE;										// Initialization Went OK
}

int num = 0,v=0;
double r = 0;

int DrawGLScene()									     // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();	                               // Reset The Current Modelview Matrix
    /////////////////////////////////
	////code
	if(root.C_soil>0.005)//???????                                      //
		{
			
			if (root.C_root<root.C_soil)                                                      //the operator is continue but we stop it.
			{//cout << "the soil is poor . . . . . . . . . . . ..";?????
			}
	else
				if (root.C_root == root.C_soil)                                                      //the operator is continue but we stop it.
				{//cout << "the tree is enought . . . . . . . . . . . ..";??????
				}else
				{
				//ROOT:
					float mass_root = (root.sub() / 9.8);
					root.old_mass = root.old_mass + mass_root;
					root.Time();
					root.speed_water();

					root.C_root = root.C_root + (0.015*mass_root);
					root.C_soil = root.C_soil - (0.015*mass_root);
                    //SHARK :
					if (shark.power()>0)
					{
						float op_mass = shark.new_value(root.old_mass);
						root.old_mass = root.old_mass - op_mass;
						root.C_root = root.C_root - (0.015*op_mass);
						if (root.old_mass<0)
						{
							root.old_mass = 0.0001;
							root.C_root = root.old_mass*0.015;
						}
						//leaf:
						if (shark.h_shark >= shark.h_all)
						{
							float op_mass_leaf = leaf.new_value(root.T, shark.mass_shark);
							shark.mass_shark = shark.mass_shark - op_mass_leaf;
							shark.c_shark = shark.c_shark - (0.015*op_mass_leaf);
							if (shark.mass_shark<0)
							{
								shark.mass_shark = 0.0001;
								shark.c_shark = shark.mass_shark*0.015;
							}
							shark.h_shark = -op_mass_leaf / ((shark.p*3.14*shark.r*shark.r) * 30000);
							leaf.power(shark.c_shark, root.T);
							//////////////////////////////////
							//fog	?????????????????????????????????
							//glDisable(GL_TEXTURE_2D);
       //                     float  fog_colour[] = { 0.55f,0.55f,0.6f,0.0f };
							//	//glClearColor(0.55f, 0.55f, 0.79f, 0.6f);

							//	glFogf(GL_FOG_START, 10.0f);
							//	glFogf(GL_FOG_END, 2000);
							//	glFogfv(GL_FOG_COLOR, fog_colour);
							//	glFogi(GL_FOG_MODE, GL_EXP);
							//	glFogf(GL_FOG_DENSITY, 0.2);
							//	// enable the fog
							//	glEnable(GL_FOG);

							//	glEnable(GL_DEPTH_TEST);
							//	glEnable(GL_LIGHT0);
							//	glEnable(GL_LIGHTING);
							//	
							//	
							//	glEnable(GL_FOG);
							//	glEnable(GL_TEXTURE_2D);
							//
							//////////////////////
						}
					}
				} 
	
}
	//////////////////////////////////////////////////
	//code
	
//	h = ((10)*shark.h_shark) / shark.h_all;
	////the photo
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_FOG);
	glTranslatef(-0.12f, -0.175f, -1.5f);
	glBindTexture(GL_TEXTURE_2D, mm);
	glColor3d(1, 1, 1);
	glScaled(0.15, 0.15, 0.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);			glVertex3f(-8, -3, 0);
	glTexCoord2f(1, 0); 	    glVertex3f(10, -3, 0);
	glTexCoord2f(1, 1);			glVertex3f(10, 6, 0);
	glTexCoord2f(0, 1);			glVertex3f(-8, 6, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_FOG);
	glPopMatrix();
	//tree
	glPushMatrix();
	glRotated(r, 0, 0, 1);
	glPushMatrix();
    glDisable(GL_TEXTURE_2D);
	glDisable(GL_FOG);
	glRotated(r, 0, 0, 1);
	glTranslatef(-0.05f, 0.1f, -0.7f);		// Move Left 1.5 Units And Into The Screen 6.0
	glScaled(0.25 , 0.25 + (shark.h_all / 500), 0.25);
	tree->Draw();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_FOG);
	glPopMatrix();
	//leaf
	glDisable(GL_TEXTURE_2D);
	if(v == 0)
	{
		if (((4 * shark.h_shark) / shark.h_all) >= 1.5 && ((4 * shark.h_shark) / shark.h_all) <= 3)
			tree->Materials[0].tex.LoadBMP("images\\102.bmp");
		else
			if (((4 * shark.h_shark) / shark.h_all) > 3)
			{			tree->Materials[0].tex.LoadBMP("images\\105.bmp"); v = 1;
	}
	}
	glEnable(GL_TEXTURE_2D);
	///////////////////////////////////////////
	//line
		glPushMatrix();
		glRotated(r, 0, 0, 1);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_FOG);
		glTranslatef(-0.08, -0.25, -0.6);
		glScalef(0.05, 0.05,0.05);
		glColor3d(0, 0, 1);
		//h = (6 * shark.h_shark) / shark.h_all;
		glBegin(GL_LINES);
		glVertex2f(0.25, 0.0);
		glVertex2f(0.55, 0.5);
		glVertex2f(1.2, 0.0);
		glVertex2f(0.95, 0.5);
		
		if (((4 * shark.h_shark) / shark.h_all) >=0.5)
		{
			glVertex2f(0.55, 0.5);
			glVertex2f(0.55, ((4 * shark.h_shark) / shark.h_all));
			glVertex2f(0.95, 0.5);
			glVertex2f(0.95, ((4 * shark.h_shark) / shark.h_all));

		}

		glVertex2f(0.65, 0.0);
		glVertex2f(0.65, 0.1 + ((4 * shark.h_shark) / shark.h_all));
		glVertex2f(0.75, 0.0);
		glVertex2f(0.75, 0.2 + ((4 * shark.h_shark) / shark.h_all));
		glVertex2f(0.85, 0.0);
		glVertex2f(0.85, 0.3+ ((4 * shark.h_shark) / shark.h_all));
		if (((4 * shark.h_shark) / shark.h_all) >= 3.5)
		{
			glVertex2f(0.95, 3.7);
			glVertex2f(1.4, 4.7);
			Sleep(200);
			if (((4 * shark.h_shark) / shark.h_all) >= 3.8)
			{
				glVertex2f(1.4, 4.7);
				glVertex2f(2.6, 5.7);
				Sleep(200);
			}
		}
        glEnd();
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_FOG);
		glPopMatrix();
	Sleep(700);
	
	glPopMatrix();
	////////////////////
	//sun
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_FOG);
	glScalef(0.05, 0.05, 1);
	glTranslatef(-8, 7, -1.0);
	glBegin(GL_LINES);
	for (float angle = -3.14f; angle <= 3.14f; angle +=(3.14*12 /(root.T)))
	{

		float x1, y1;
		x1 = cos(angle);
		y1 = sin(angle);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x1, y1, 0.0f);
	}
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_FOG);
	glPopMatrix();
	
	//ROUND   ??????????????????????????????????
	if (num % 2 == 0)
	{
		r=(leaf.U / 700);
		num++;
	}
	else
	{
		r=(-(leaf.U /700));
		num++;
	}
	
	return TRUE;										// Keep Going
}




GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
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

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:
	{
		switch (wParam)
		{
		case SC_SCREENSAVE:
		case SC_MONITORPOWER:
			return 0;
		}
		break;
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
	if (MessageBox(NULL, "Would You Like To Run In Fullscreen Mode?", "Start FullScreen?", MB_YESNO | MB_ICONQUESTION) == IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("the project", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if ((active && !DrawGLScene()) || keys[VK_ESCAPE])	// Active?  Was There A Quit Received?
			{
				done = TRUE;							// ESC or DrawGLScene Signalled A Quit
			}
			else									// Not Time To Quit, Update Screen
			{
				SwapBuffers(hDC);					// Swap Buffers (Double Buffering)
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("NeHe's First Polygon Tutorial", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}