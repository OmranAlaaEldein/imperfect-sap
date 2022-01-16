/*
*		This Code Was Created By Jeff Molofee 2000
*		A HUGE Thanks To Fredric Echols For Cleaning Up
*		And Optimizing This Code, Making It More Flexible!
*		If You've Found This Code Useful, Please Let Me Know.
*		Visit My Site At nehe.gamedev.net
*/

#include<cmath>
#include "texture.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>				// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>			// Header File For The Glaux Library
#include "Model_3DS.h"
#include"3DTexture.h"
#include<string>
#include<iostream>
#include <sstream> 

CCamera objCamera;
HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLfloat lightpos[]={-105.0f,20.0f,-10.0f,1.0f};
GLfloat lightamb[]={1.0f,1.0f,1.0f,1.0f};
GLfloat lightDiff[]={0.9f,0.9f,0.9f,1.0f};
GLfloat lightspec[]={0.6f,0.6f,0.6f,1.0f};
GLfloat matamb[]={1.0f,1.0f,1.0f,1.0f};
GLfloat matdiff[]={0.9f,0.9f,0.9f,1.0f};
GLfloat matspec[]={0.6f,0.6f,0.6f,1.0f};
GLfloat matshm[]={128.0f};
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	objCamera.mWindowWidth  = width;
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,500.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	objCamera.mWindowWidth  = width;
	objCamera.mWindowHeight = height;

}

int down;  // grass
int front,Left,Right,back,top;  // skyBox

int build1_front,build1_left,build1_right,build1_back;
int build2_front,build2_left,build2_right,build2_back;
int build3_front,build3_left,build3_right,build3_back;
int build4_front,build4_left,build4_right,build4_back;
int build5_front,build5_left,build5_right,build5_back;
int build6_front,build6_left,build6_right,build6_back;
int build7_front,build7_left,build7_right,build7_back;
int football;

int grass,grass1,train1,bottom;
int metal,glass,wall,bbbb,bbbb1,neon,ss,ss1,dd;


int road,roadtex;
int mc;
Model_3DS tree,trafic,m,F,soor;
Model_3DS *train;
Model_3DS *man;

double x=-105,y,z=-117;
float cv,vc,bc;
int terraintexture ;
double Train_x=-35;
int TerrainSize = 512;
float step = 1/512.0;
double Train_y=90,Train_z=0;
double rr=-6;
bool fogoff=false,lightoff=false;
void key()
{
	
	
	if(keys[VK_UP]){
		x+= cos( (y +90) * (3.141/180))*0.09;
		z+= -sin( (y +90) * (3.141/180))*0.09;
		
	}
	if(keys[VK_DOWN]){
		x+= cos( (y +90) * (3.141/180))*-0.09;
		z+= -sin( (y +90) * (3.141/180))*-0.09;
	}
	if(keys[VK_RIGHT])
		y=y-0.7;
	if(keys[VK_LEFT])
		y=y+0.7;
	if (keys['R'])
	{
		rr+=0.1;
	}
		if (keys['F'])
	{
		rr-=0.1;
	}
	//	if  ( keys['I'])
	//{
	//	Train_x+=0.1;
	//	 x+=0.2;
	//	

	//}
	//if  ( keys['K'])
	//{
	//	Train_x-=0.1;

 //             x-=0.2;
	//	
	//}


	
			if  ( keys['K'])
	{
		
		Train_x+= cos( (Train_y +90) * (3.141/180))*0.085;
		Train_z+= -sin( (Train_y +90) * (3.141/180))*0.085;
	
		x+= cos( (y +90) * (3.141/180))*-0.17;
		z+= -sin( (y +90) * (3.141/180))*-0.17;

	}
	if  ( keys['I'])
	{
		
		Train_x+= cos( (Train_y +90) * (3.141/180))* -0.085;
		Train_z+= -sin( (Train_y +90) * (3.141/180))* -0.085;
       x+= cos( (y +90) * (3.141/180))*0.17;
		z+= -sin( (y +90) * (3.141/180))*0.17;
			
		  
	}
	if  ( keys['L'])
	{
		Train_y-=0.3;

       y-=0.3;
		
	}
		if  ( keys['J'])
	{
		Train_y+=0.3;
		y+=0.3;
       
		
	}






		///////////////////
		
			if  ( keys['S'])
	{
		
		Train_x+= cos( (Train_y +90) * (3.141/180))*0.035;
		Train_z+= -sin( (Train_y +90) * (3.141/180))*0.035;
	
		
	}
	if  ( keys['W'])
	{
		
		Train_x+= cos( (Train_y +90) * (3.141/180))* -0.035;
		Train_z+= -sin( (Train_y +90) * (3.141/180))* -0.035;
       	
		  
	}
	if  ( keys['D'])
	{
		Train_y-=0.09;

       
		
	}
		if  ( keys['A'])
	{
		Train_y+=0.09;
		
	}



		if ( keys['Q']){ fogoff= true;}
		if (keys['E']){fogoff= false;}

		if(keys['Z']){cv+=1;}
	if(keys['X']){cv-=1;}
	if(keys['C']){vc+=1;}
	if(keys['V']){vc-=1;}
	if(keys['B']){bc+=1;}
	if(keys['N']){bc-=1;}
	
	


}
void Keyboard_Input()
{
	/*if((GetKeyState(VK_UP) & 0x80) || (GetKeyState('W') & 0x80))
	{	
		objCamera.Move_Camera(CAMERASPEED);
	}

	if((GetKeyState(VK_DOWN) & 0x80) || (GetKeyState('S') & 0x80))
	{
		objCamera.Move_Camera(-CAMERASPEED);
	}

	if((GetKeyState(VK_LEFT) & 0x80) || (GetKeyState('A') & 0x80))
	{	
		objCamera.Rotate_View(0,-CAMERASPEED, 0);
	}

	if((GetKeyState(VK_RIGHT) & 0x80) || (GetKeyState('D') & 0x80))
	{
		objCamera.Rotate_View(0, CAMERASPEED, 0);
	}
	if  ( keys['T'])
	{
		rr+=0.2;
	}
	if  ( keys['G'])
	{
		rr-=0.2;
	}
	if  ( keys['I'])
	{
		Train_x+=0.1;
		objCamera.Move_Camera(0.04);
		

	}
	if  ( keys['L'])
	{
		Train_x-=0.2;
		objCamera.Move_Camera(-CAMERASPEED);	
	}*/
	
	
	
	
		
		
}



int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);
	glLightfv(GL_LIGHT1,GL_POSITION,lightpos);
	glLightfv(GL_LIGHT1,GL_AMBIENT,lightamb);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lightDiff);
	glLightfv(GL_LIGHT1,GL_SPECULAR,lightspec);
	glEnable(GL_LIGHT1);
	glMaterialfv(GL_FRONT,GL_AMBIENT,matamb);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,matdiff);
    glMaterialfv(GL_FRONT,GL_SPECULAR,matspec);
	glMaterialfv(GL_FRONT,GL_SHININESS,matshm);
	glEnable(GL_COLOR_MATERIAL);
	objCamera.Position_Camera(0, 2.5f, 5,	0, 2.5f, 0,   0, 1, 0);

	// Sky Box
	back = LoadTexture("back.bmp");			    
	front = LoadTexture("front.bmp");
	top = LoadTexture("top.bmp");
	down = LoadTexture("grass.bmp");
	Right = LoadTexture("right.bmp");
	Left = LoadTexture("left.bmp");
	
	///////////////////////////////////////////////////
	//
	///////// Build #1
	build1_front=LoadTexture("build1.bmp",255);
	build1_back=LoadTexture("build1.bmp",255);
	build1_left=LoadTexture("build1.bmp",255);
	build1_right=LoadTexture("build1.bmp",255);
	//////////////////////////////////////////////////////

	// Build #2
	build2_front=LoadTexture("wallhome.bmp",255);
	build2_back=LoadTexture("build2.bmp",255);
	build2_left=LoadTexture("wallhome.bmp",255);
	build2_right=LoadTexture("wallhome.bmp",255);
	//////////////////////////////////////////////////////
	// Build #3
	build3_front=LoadTexture("wall_build3.bmp",255);
	build3_back=LoadTexture("build3.bmp",255);
	build3_left=LoadTexture("wall_build3.bmp",255);
	build3_right=LoadTexture("wall_build3.bmp",255);
	//////////////////////////////////////////////////////
	// Road
	road=LoadTexture("road.bmp",255);
	/////////////////////////////////////////////////////
	// Build #4
	build4_front=LoadTexture("wallhome.bmp",255);
	build4_back=LoadTexture("build4.bmp",255);
	build4_left=LoadTexture("wallhome.bmp",255);
	build4_right=LoadTexture("wallhome.bmp",255);
	/////////////////////////////////////////////////////
	// Build #4
	build5_front=LoadTexture("wallhome.bmp",255);
	build5_back=LoadTexture("build5.bmp",255);
	build5_left=LoadTexture("wallhome.bmp",255);
	build5_right=LoadTexture("wallhome.bmp",255);
	/////////////////////////////////////////////////////
	// Build #5
	build6_front=LoadTexture("wallhome.bmp",255);
	build6_back=LoadTexture("build6.bmp",255);
	build6_left=LoadTexture("wallhome.bmp",255);
	build6_right=LoadTexture("wallhome.bmp",255);
	/////////////////////////////////////////////////////
	// Build #6
	build7_front=LoadTexture("wallhome.bmp",255);
	build7_back=LoadTexture("build7.bmp",255);
	build7_left=LoadTexture("wallhome.bmp",255);
	build7_right=LoadTexture("wallhome.bmp",255);
	/////////////////////////////////////////////
	football=LoadTexture("football.bmp",255);

	tree = Model_3DS();

	
	soor = Model_3DS();

	tree.Load("tree.3DS");
	//trafic.Load("Urn.3ds");
	//m.Load("Manhal.3DS");
	//F.Load("Fire.3DS");
	soor.Load("soor.3DS");


	tree.Materials[0].tex.LoadBMP("wood.bmp");
	
	//trafic.Materials[0].tex.LoadBMP("Green.bmp");
	//trafic.Materials[1].tex.LoadBMP("Green.bmp");
	
	//m.Materials[0].tex.LoadBMP("ManhalTex.bmp");
	//F.Materials[0].tex.LoadBMP("FireTex.bmp");
	
	soor.Materials[0].tex.LoadBMP("FireTex.bmp");
	glTexParameteri(GL_TEXTURE,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE,GL_TEXTURE_WRAP_T,GL_REPEAT);



	////////////////////////////////////////  train 

	
	train =  new  Model_3DS();
	train->Load("train/CLRV1.3DS");
	GLTexture a,b,c,d,e,f,g,h,i,k,l,m,n,o,j,oo,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,pp,qq,rr,ss,tt,uu,vv,ww,xx,yy,zz;
	a.LoadBMP("train/door.BMP");
	b.LoadBMP("train/bodyFron.BMP");
	c.LoadBMP("train/bodyLeft.BMP");
	d.LoadBMP("train/bodyRear.BMP");
	e.LoadBMP("train/bodyRigh.BMP");
	f.LoadBMP("train/Cieling.BMP");
	g.LoadBMP("train/Cieling_.BMP");
	h.LoadBMP("train/flaps.BMP");
	i.LoadBMP("train/grate.BMP");
	j.LoadBMP("train/rollSign.BMP");
	k.LoadBMP("train/roof.BMP");
	l.LoadBMP("train/roofEnd.BMP");
	m.LoadBMP("train/roofVent.BMP");
	n.LoadBMP("train/vent.BMP");
	o.LoadBMP("train/warningS.BMP");
	oo.LoadBMP("train/saeeq.BMP");
	aa.LoadBMP("train/bloor.BMP");
	bb.LoadBMP("train/mska.BMP");
	cc.LoadBMP("train/qrse.BMP");
	dd.LoadBMP("train/ground.BMP");
	zz.LoadBMP("train/b.BMP");
	yy.LoadBMP("train/as1.BMP");
	train->Materials[0].tex=bb;
	train->Materials[1].tex=cc;
	train->Materials[2].tex=d;
	train->Materials[3].tex=cc;
	train->Materials[4].tex=f;
	train->Materials[5].tex=cc;
	train->Materials[6].tex=f;
	train->Materials[7].tex=oo;
	train->Materials[8].tex=oo;
	train->Materials[9].tex=oo;
	train->Materials[10].tex=n;
	train->Materials[11].tex=bb;
	train->Materials[12].tex=a;
	train->Materials[13].tex=bb;
	train->Materials[14].tex=bb;
	train->Materials[15].tex=e;
	train->Materials[16].tex=bb;
	train->Materials[17].tex=c;
	train->Materials[18].tex=b;
	train->Materials[19].tex=bb;
	train->Materials[20].tex=c;
	train->Materials[21].tex=bb;
	train->Materials[22].tex=bb;
	train->Materials[23].tex=cc;
	train->Materials[24].tex=bb;
	train->Materials[25].tex=f;
	train->Materials[26].tex=zz;
	train->Materials[27].tex=bb;
	train->Materials[28].tex=g;
	train->Materials[29].tex=cc;
	train->Materials[30].tex=bb;
	train->Materials[31].tex=aa;
train->Materials[32].tex=bb;
	train->Materials[33].tex=aa;
	train->Materials[34].tex=e;
	train->Materials[35].tex=oo;
	train->Materials[36].tex=bb;
	train->Materials[37].tex=bb;
	train->Materials[38].tex=oo;
	train->Materials[39].tex=bb;
	train->Materials[40].tex=bb;
	train->Materials[41].tex=bb;
	train->Materials[42].tex=dd;
	train->Materials[43].tex=dd;
	train->Materials[44].tex=dd;
	train->Materials[45].tex=dd;
	train->Materials[46].tex=dd;
	train->Materials[47].tex=cc;
	train->Materials[48].tex=cc;

	glass=LoadTexture("glass1.bmp");

	man= new Model_3DS();
	man->Load("man_sitting3.3Ds");
	GLTexture man_t;
	man_t.LoadBMP("man_sitting3.BMP");
	man->Materials[0].tex=man_t;

	PlaySound("1.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

	return TRUE;										// Initialization Went OK
}





float th=0.0;

void draw_skybox()
{
	glBindTexture(GL_TEXTURE_2D,down);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(70,0);
	glVertex3f(100,0,0);

	glTexCoord2f(70,70);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,70);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,front);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,top);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,Right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,Left);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();


}
float speed=1;

void buid1()
{

	glBindTexture(GL_TEXTURE_2D,build1_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(20,0);
	glVertex3f(100,0,0);

	glTexCoord2f(20,20);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,20);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build1_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(20,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(20,20);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,20);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build1_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(20,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(30,30);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,20);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build1_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,20);
	glVertex3f(100,40,-100);

	glTexCoord2d(20,20);
	glVertex3f(100,40,0);

	glTexCoord2d(20,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build1_back);
	glBegin(GL_QUADS);

	glTexCoord2d(20,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(20,20);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,20);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build1_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(20,0);
	glVertex3f(100,0,0);

	glTexCoord2f(20,20);
	glVertex3f(100,40,0);

	glTexCoord2f(0,20);
	glVertex3f(-100,40,0);
	glEnd();

}


void buid2()
{

	glBindTexture(GL_TEXTURE_2D,build2_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build2_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build2_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build2_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build2_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build2_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void buid3()
{

	glBindTexture(GL_TEXTURE_2D,build3_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build3_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build3_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build3_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build3_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build3_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void build4()
{

	glBindTexture(GL_TEXTURE_2D,build4_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build4_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build4_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build4_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build4_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build4_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void build5()
{

	glBindTexture(GL_TEXTURE_2D,build5_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build5_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build5_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build5_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build5_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build5_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void build6()
{

	glBindTexture(GL_TEXTURE_2D,build6_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build6_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build6_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build6_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build6_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build6_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void build7()
{

	glBindTexture(GL_TEXTURE_2D,build7_front);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,0,-100);

	glTexCoord2f(0,1);
	glVertex3f(-100,0,-100);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,build7_back);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(-100,0,-95);

	glTexCoord2f(1,0);
	glVertex3f(100,0,-95);

	glTexCoord2f(1,1);
	glVertex3f(100,40,-95);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,-95);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build7_left);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,40,-95);

	glTexCoord2d(1,0);
	glVertex3f(-100,40,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,1);
	glVertex3f(100,40,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build7_right);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3f(100,0,-100);

	glTexCoord2d(0,1);
	glVertex3f(100,40,-100);

	glTexCoord2d(1,1);
	glVertex3f(100,40,0);

	glTexCoord2d(1,0);
	glVertex3f(100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build7_front);
	glBegin(GL_QUADS);

	glTexCoord2d(1,0);
	glVertex3f(-100,0,-95);

	glTexCoord2d(1,1);
	glVertex3f(-100,40,-95);

	glTexCoord2d(0,1);
	glVertex3f(-100,40,0);

	glTexCoord2d(0,0);
	glVertex3f(-100,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,build7_back);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-100,0,0);

	glTexCoord2f(1,0);
	glVertex3f(100,0,0);

	glTexCoord2f(1,1);
	glVertex3f(100,40,0);

	glTexCoord2f(0,1);
	glVertex3f(-100,40,0);
	glEnd();

}


void drawing_road()
{

	glBindTexture(GL_TEXTURE_2D,road);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-5,0,-5);

	glTexCoord2f(1,0);
	glVertex3f(5,0,-5);

	glTexCoord2f(1,1);
	glVertex3f(5,0,-80);

	glTexCoord2f(0,1);
	glVertex3f(-5,0,-80);
	glEnd();
	////////////////////////////////////////
	glPushMatrix();
	    glTranslated(100,0.1,-10);

    	glRotated(90,0,1,0);

		glBindTexture(GL_TEXTURE_2D, road);

    	glBegin(GL_QUADS);
	      glTexCoord2f(0,0);
	      glVertex3f(-5,0,-20);

	      glTexCoord2f(1,0);
	      glVertex3f(5,0,-20);

          glTexCoord2f(1,1);
     	  glVertex3f(5,0,-180);

	      glTexCoord2f(0,1);
	      glVertex3f(-5,0,-180);
	
	   glEnd();
	glPopMatrix();
	/////////////////////////////////////////////
		
	glPushMatrix();
	    glTranslated(100,0.1,-50);
    	glRotated(90,0,1,0);
	
		glBindTexture(GL_TEXTURE_2D,road);

    	glBegin(GL_QUADS);
	      glTexCoord2f(0,0);
	      glVertex3f(-5,0,-20);

	      glTexCoord2f(1,0);
	      glVertex3f(5,0,-20);

          glTexCoord2f(1,1);
     	  glVertex3f(5,0,-180);

	      glTexCoord2f(0,1);
	      glVertex3f(-5,0,-180);
	
	   glEnd();
	glPopMatrix();
	
	/////////////////////////////////////////////	
	glPushMatrix();
	    glTranslated(100,0.1,-75);
    	glRotated(90,0,1,0);

		glBindTexture(GL_TEXTURE_2D,road);

    	glBegin(GL_QUADS);
	      glTexCoord2f(0,0);
	      glVertex3f(-5,0,-20);

	      glTexCoord2f(1,0);
	      glVertex3f(5,0,-20);

          glTexCoord2f(1,1);
     	  glVertex3f(5,0,-180);

	      glTexCoord2f(0,1);
	      glVertex3f(-5,0,-180);
	
	   glEnd();
	glPopMatrix();


	/////////////////////////////////////////////	
	glPushMatrix();
	    glTranslated(80,0.1,0);
		glBindTexture(GL_TEXTURE_2D,road);

    	glBegin(GL_QUADS);
	      glTexCoord2f(0,0);
	      glVertex3f(-5,0,-5);

	      glTexCoord2f(1,0);
	      glVertex3f(5,0,-5);

          glTexCoord2f(1,1);
     	  glVertex3f(5,0,-80);

	      glTexCoord2f(0,1);
	      glVertex3f(-5,0,-80);
	
	   glEnd();
	glPopMatrix();
	/////////////////////////////////////////////	
	glPushMatrix();
	    glTranslated(-80,0.1,0);
		glBindTexture(GL_TEXTURE_2D,road);

    	glBegin(GL_QUADS);
	      glTexCoord2f(0,0);
	      glVertex3f(-5,0,-5);

	      glTexCoord2f(1,0);
	      glVertex3f(5,0,-5);

          glTexCoord2f(1,1);
     	  glVertex3f(5,0,-80);

	      glTexCoord2f(0,1);
	      glVertex3f(-5,0,-80);
	
	   glEnd();
	glPopMatrix();
}
void drawing_football()
{
	glBindTexture(GL_TEXTURE_2D,football);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-25,0,0);

	glTexCoord2f(1,0);
	glVertex3f(25,0,0);

	glTexCoord2f(1,1);
	glVertex3f(25,0,-25);

	glTexCoord2f(0,1);
	glVertex3f(-25,0,-25);
	glEnd();
}
void drawing_buidings()
{
	// Buiding #1
	glPushMatrix();
	glTranslated(10,0,-90);
	glScaled(0.05,0.5,0.05);
	buid1();
	glPopMatrix();
	///////////////////
	// Buiding #2
	glPushMatrix();
	glTranslated(-10,0,-90);
	glScaled(0.05,0.6,0.05);
	buid1();
	glPopMatrix();
	///////////////////

	// Buiding #3
	glPushMatrix();
	glTranslated(25,0,-90);
	glScaled(0.05,0.25,0.05);
	buid2();
	glPopMatrix();

	///////////////////
	// Buiding #4
	glPushMatrix();
	glTranslated(-40,0,-90);
	glScaled(0.07,0.2,0.05);
	buid3();
	glPopMatrix();
    //////////////////////
	// Buiding #4
	glPushMatrix();
	glTranslated(0, 0, -90);
	glScaled(0.05, 0.2, 0.05);
	build4();
	glPopMatrix();
	//////////////////////

	
	// Road
	drawing_road();
	///////////////////////
	// Buiding #5
	glPushMatrix();
	glTranslated(-25,0,-90);
	glScaled(0.08,0.3,0.05);
	build4();
	glPopMatrix();
	/////////////////////////////
	// Buiding #6
	glPushMatrix();
	glTranslated(40,0,-90);
	glScaled(0.09,0.36,0.05);
	build5();
	glPopMatrix();
	/////////////////////////////
	// Buiding #7
	glPushMatrix();
	glTranslated(-60,0,-90);
	glScaled(0.09,0.5,0.05);
	build6();
	glPopMatrix();
	/////////////////////////////

	// Buiding #7
	glPushMatrix();
	glTranslated(-79.2, 0, -90);
	glScaled(0.08, 0.3, 0.05);
	build4();
	glPopMatrix();
	/////////////////////////////

	// Buiding #7
	glPushMatrix();
	glTranslated(+78, 0, -90);
	glScaled(0.07, 0.3, 0.05);
	build4();
	glPopMatrix();
	/////////////////////////////



	// Buiding #8
	glPushMatrix();
	glTranslated(60,0,-90);
	glScaled(0.09,0.45,0.05);
	build7();
	glPopMatrix();
	////////////////////////////
	// Buiding #9
	glPushMatrix();
	glTranslated(90,0,-90);
	glScaled(0.05,0.25,0.05);
	buid2();
	glPopMatrix();
	///////////////////////////
	// Buiding #10
	glPushMatrix();
	glTranslated(-90,0,-86);
	glRotated(90,0,1,0);
	glScaled(0.06,0.36,0.07);
	build5();
	glPopMatrix();
	////////////////////////////////

	///////////////////////////// End buildings in back ///////////////////////////////
	// Buiding #11
	glPushMatrix();
	glTranslated(-90,0,-61);
	glRotated(90,0,1,0);
	glScaled(0.06,0.36,0.07);
	build7();
	glPopMatrix();
	////////////////////////////////
	// Buiding #12
	glPushMatrix();
	glTranslated(-90,0,-37);
	glRotated(90,0,1,0);
	glScaled(0.06,0.34,0.07);
	buid3();
	
	glPopMatrix();
	////////////////////////////////
	// Buiding #13
	glPushMatrix();
	glTranslated(-90,0,-24);
	glRotated(90,0,1,0);
	glScaled(0.06,0.27,0.07);
	build6();
	glPopMatrix();

	////////////////////////////////  END LEft BUILDINGS ////////////////////////////////
	// Buiding #4
	glPushMatrix();
	glTranslated(0, 0, -4);
	glRotated(180, 0, 1, 0);
	glScaled(0.06, 0.27, 0.07);
	build5();
	glPopMatrix();
	//////////////////////

	// Buiding #14
	glPushMatrix();
	glTranslated(-92,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.27,0.07);
	
	buid2();
	glPopMatrix();
	////////////////////////////////
	// Buiding #15
	glPushMatrix();
	glTranslated(-69,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.2,0.07);
	build5();
	glPopMatrix();
	/////////////////////////////////
	// Buiding #16
	glPushMatrix();
	glTranslated(-56,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.34,0.07);
	buid1();
	glPopMatrix();
	/////////////////////////////////
	// Buiding #17
	glPushMatrix();
	glTranslated(-46,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.3,0.07);
	build7();
	glPopMatrix();
	///////////////////////////////////
	// Buiding #18
	glPushMatrix();
	glTranslated(-36,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.2,0.07);
	buid2();
	glPopMatrix();
	///////////////////////////////////
	// Buiding #19
	glPushMatrix();
	glTranslated(-26,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.37,0.07);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #20
	glPushMatrix();
	glTranslated(-13,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.2,0.07);
	build4();
	glPopMatrix();
	////////////////////////////////////
	////////////////////////////////
	// Buiding #21
	glPushMatrix();
	glTranslated(+92,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.27,0.07);
	buid1();
	glPopMatrix();
	
	////////////////////////////////
	
	////////////////////////////////
	// Buiding #21
	glPushMatrix();
	glTranslated(+82, 0, -4);
	glRotated(180, 0, 1, 0);
	glScaled(0.05, 0.27, 0.07);
	build4();
	glPopMatrix();

	////////////////////////////////

	// Buiding #21
	glPushMatrix();
	glTranslated(-82, 0, -4);
	glRotated(180, 0, 1, 0);
	glScaled(0.05, 0.27, 0.07);
	build4();
	glPopMatrix();

	////////////////////////////////


	// Buiding #22
	glPushMatrix();
	glTranslated(+69,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.2,0.07);
	build6();
	glPopMatrix();
	/////////////////////////////////
	// Buiding #23
	glPushMatrix();
	glTranslated(+56,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.34,0.07);
	buid3();
	glPopMatrix();
	/////////////////////////////////
	// Buiding #24
	glPushMatrix();
	glTranslated(+46,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.3,0.07);
	build7();
	glPopMatrix();
	///////////////////////////////////
	// Buiding #25
	glPushMatrix();
	glTranslated(+36,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.2,0.07);
	buid2();
	glPopMatrix();
	///////////////////////////////////
	// Buiding #26
	glPushMatrix();
	glTranslated(+26,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.04,0.37,0.07);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #27
	glPushMatrix();
	glTranslated(+13,0,-4);
	glRotated(180,0,1,0);
	glScaled(0.06,0.2,0.07);
	buid3();
	glPopMatrix();
	
	//////////////////////////////////
	// Buiding #27
	glPushMatrix();
	glTranslated(+13, 0, -4);
	glRotated(180, 0, 1, 0);
	glScaled(0.06, 0.2, 0.07);
	buid3();
	glPopMatrix();

	//////////////////////////// END BACK BUILDINGS /////////////////////////////////
	// Buiding #28
	glPushMatrix();
	glTranslated(90,0,-61);
	glRotated(-90,0,1,0);
	glScaled(0.06,0.36,0.07);
	build7();
	glPopMatrix();
	////////////////////////////////
	// Buiding #29
	glPushMatrix();
	glTranslated(90,0,-37);
	glRotated(-90,0,1,0);
	glScaled(0.06,0.34,0.07);
	buid3();
	
	glPopMatrix();
	////////////////////////////////
	// Buiding #30
	glPushMatrix();
	glTranslated(90,0,-24);
	glRotated(-90,0,1,0);
	glScaled(0.06,0.27,0.07);
	build6();
	glPopMatrix();
	///////////////////////////////////
	// Buiding #30
	glPushMatrix();
	glTranslated(90, 0, -11);
	glRotated(-90, 0, 1, 0);
	glScaled(0.06, 0.2, 0.07);
	build5();
	glPopMatrix();
	////////////////////////////////////
	//////////////////////////////// Right Buildings ////////////////////////////////////////////
	// football
	glPushMatrix();
	  glTranslated(45,0,-50);
	  drawing_football();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(10,0,-62);
	glRotated(-90,0,1,0);
	glScaled(0.067,0.27,0.07);
	buid3();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(-12,0,-62);
	glScaled(0.067,0.39,0.07);
	build4();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(-25,0,-62);
	glScaled(0.067,0.2,0.07);
	build5();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(-40,0,-62);
	glScaled(0.067,0.27,0.07);
	build6();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(-55,0,-62);
	glScaled(0.067,0.39,0.07);
	build7();
	glPopMatrix();
	////////////////////////////////
	// Buiding #center 1
	glPushMatrix();
	glTranslated(-69,0,-62);
	glScaled(0.05,0.7,0.07);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-13, 0, -20);
	glScaled(0.05, 0.7, 0.07);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-25, 0, -20);
	glScaled(0.05, 0.3, 0.07);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-40, 0, -20);
	glScaled(0.05, 0.25, 0.07);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-55, 0, -20);
	glScaled(0.06, 0.2, 0.07);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-67, 0, -20);
	glScaled(0.06, 0.25, 0.07);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-72, 0, -33);
	glRotatef(-90, 0, 1, 0);
	glScaled(0.06, 0.2, 0.07);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-66, 0, -40);
	glScaled(0.06, 0.3, 0.035);
	build7();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-53, 0, -40);
	glScaled(0.06, 0.2, 0.035);
	buid3();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-40, 0, -40);
	glScaled(0.06, 0.15, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-28, 0, -40);
	glScaled(0.06, 0.3, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-17, 0, -40);
	glScaled(0.05, 0.2, 0.035);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-7, 0, -35);
	glRotatef(90, 0, 1, 0);
	glScaled(0.07, 0.13, 0.035);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-11, 0, -34);
	glRotatef(90, 0, 1, 0);
	glScaled(0.06, 0.34, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-33, 0, -34);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-45, 0, -24);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-45, 0, -24);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	/////////////////////////////////
	////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-66, 0, -35);
	glScaled(0.06, 0.3, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-53, 0, -35);
	glScaled(0.06, 0.35, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-40, 0, -35);
	glScaled(0.06, 0.4, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-28, 0, -35);
	glScaled(0.06, 0.3, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-17, 0, -35);
	glScaled(0.05, 0.2, 0.035);
	build5();
	glPopMatrix();
	//////////////////////////////////

   //////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////
	glPushMatrix();
	glTranslated(80, 0, 0);

	// Buiding #center 2
	glPushMatrix();
	glTranslated(-13, 0, -20);
	glScaled(0.05, 0.7, 0.07);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-25, 0, -20);
	glScaled(0.05, 0.3, 0.07);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-40, 0, -20);
	glScaled(0.05, 0.25, 0.07);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-55, 0, -20);
	glScaled(0.06, 0.2, 0.07);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 2
	glPushMatrix();
	glTranslated(-67, 0, -20);
	glScaled(0.06, 0.25, 0.07);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-72, 0, -33);
	glRotatef(-90, 0, 1, 0);
	glScaled(0.06, 0.2, 0.07);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-66, 0, -40);
	glScaled(0.06, 0.3, 0.035);
	build7();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-53, 0, -40);
	glScaled(0.06, 0.2, 0.035);
	buid3();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-40, 0, -40);
	glScaled(0.06, 0.15, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-28, 0, -40);
	glScaled(0.06, 0.3, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-17, 0, -40);
	glScaled(0.05, 0.2, 0.035);
	build5();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-7, 0, -35);
	glRotatef(90, 0, 1, 0);
	glScaled(0.07, 0.13, 0.035);
	build6();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-11, 0, -34);
	glRotatef(90, 0, 1, 0);
	glScaled(0.06, 0.34, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-33, 0, -34);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-45, 0, -24);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center left
	glPushMatrix();
	glTranslated(-45, 0, -24);
	glRotatef(90, 0, 1, 0);
	glScaled(0.03, 0.45, 0.035);
	buid1();
	glPopMatrix();
	//////////////////////////////////
	/////////////////////////////////
	////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-66, 0, -35);
	glScaled(0.06, 0.3, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-53, 0, -35);
	glScaled(0.06, 0.35, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-40, 0, -35);
	glScaled(0.06, 0.4, 0.035);
	buid2();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-28, 0, -35);
	glScaled(0.06, 0.3, 0.035);
	build4();
	glPopMatrix();
	//////////////////////////////////
	// Buiding #center 3
	glPushMatrix();
	glTranslated(-17, 0, -35);
	glScaled(0.05, 0.2, 0.035);
	build5();
	glPopMatrix();
	//////////////////////////////////
 
	glPopMatrix();

	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////

}
void drawing_trees()
{
	glPushMatrix();
	glTranslated(-7, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(+9, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-18, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-38, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-60, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-80, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(15, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(38, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(60, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(80, 0, -84);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();





	glPushMatrix();
	glTranslated(27, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(45, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(70, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-45, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-70, 0, -16.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-8.5, 0, -43.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.3, 0, -36.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();

	////////////////////////////// Right ////////////////////////////////////

	glPushMatrix();
	glTranslated(+73, 0, -43.5);
	glScalef(0.03f, 0.02f, 0.06f);
	tree.Draw();
	glPopMatrix();


}
void drawing_soor()
{

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	/////////////////

	glPushMatrix();
	glTranslated(0, 0, -65);

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-75, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-79, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-87, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-91, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-95, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-99, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-103, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-107, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-111, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-115, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-119, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-123, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-127, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-131, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPopMatrix();




	//1/////
	
	glPushMatrix();
	glTranslated(68, 0, -65);

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-75, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-79, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-83, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-87, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-91, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-95, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-99, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-103, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-107, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-111, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-115, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-119, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-123, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-127, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-131, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();



	glPopMatrix();


	////////////////


	///////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(-7, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	/////////////////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(-74.5, 0, -18);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -22);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -26);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -30);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -34);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -38);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-74.5, 0, -42);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


    ///////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(0, 0, -28.5);

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();

   ////////////////////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(69, 0, 0);

	glPushMatrix();
	glTranslated(-74.5, 0, -18);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -22);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -26);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -30);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -34);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -38);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-74.5, 0, -42);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();

	/////////////////////// End Left Soor ///////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(80, 0, 0);

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	///////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(-7, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -5);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	/////////////////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(-74.5, 0, -18);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -22);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -26);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -30);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -34);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -38);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-74.5, 0, -42);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	///////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(0, 0, -28.5);

	glPushMatrix();
	glTranslated(-7, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-11, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-19, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-23, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-27, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-31, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-35, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-39, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-43, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-47, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-51, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-55, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-59, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-67, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-71, 0, -16);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(69, 0, 0);

	glPushMatrix();
	glTranslated(-74.5, 0, -18);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -22);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -26);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -30);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -34);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-74.5, 0, -38);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-74.5, 0, -42);
	glRotatef(-90, 0, 1, 0);
	glScalef(0.002, 0.002, 0.002);
	soor.Draw();
	glPopMatrix();

	glPopMatrix();


	glPopMatrix();


}
void fogo()

{
	glEnable(GL_FOG);
	GLfloat color[] ={1, 1 ,1,1};
	glFogfv(GL_FOG_COLOR,color);
	glFogi(GL_FOG_MODE,GL_LINEAR);
	glFogi(GL_FOG_START,-10);
	glFogi(GL_FOG_END,400);
	glHint(GL_FOG_HINT,GL_NICEST);

}
void lighhtr()
{
	glEnable(GL_LIGHTING);
}

///////////////////////////////////////////////////////////////////////////////////////////////
int DrawGLScene(GLvoid)									//// Here's Where We Do All The Drawing
{

	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();	

	
		glRotated(-y , 0.0, 1.0, 0.0);
	glTranslated( -x, rr, -z );
	key();	
	
	glScaled(2,2,2);
draw_skybox();

	if  ( fogoff==true)

	{
		fogo();
	}
	else if (  fogoff==false) { glDisable(GL_FOG);}


	lightpos[0]=cv;
	lightpos[1]=vc;
	lightpos[2]=bc;
	glLightfv(GL_LIGHT1,GL_POSITION,lightpos);
	
drawing_buidings();
drawing_soor();


	glPushMatrix();
	
	
	glTranslated(Train_x,0,Train_z-50);
	glRotated(Train_y,0,1,0);
	glScaled(0.7,0.7,0.7);
	

glPushMatrix();
	

	glScaled(4,4,4);
	
	glRotated(90,0,1,0);
	glTranslated(0,1.76,-0.38);
	
	          glEnable(GL_BLEND);     // Turn Blending On
			  glBlendFunc (GL_ONE, GL_ONE);
			 
			 glBindTexture(GL_TEXTURE_2D,glass);
			glColor4f(1.0f, 1.0f, 1.0f, 0.03);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d( -2.55, -1.0, 0.0);
			glTexCoord2d(1.0, 0.0); glVertex3d( 2.55, -1.0, 0.0);
			glTexCoord2d(1.0, 1.0); glVertex3d( 2.55, -0.4, 0.0);
			glTexCoord2d(0.0, 1.0); glVertex3d( -2.55, -0.4, 0.0);
			glEnd();
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d( -2.55, -1.0, 1.24);
			glTexCoord2d(1.0, 0.0); glVertex3d( 2.55, -1.0, 1.24);
			glTexCoord2d(1.0, 1.0); glVertex3d( 2.55, -0.4, 1.24);
			glTexCoord2d(0.0, 1.0); glVertex3d( -2.55, -0.4, 1.24);
			glEnd();
				glDisable(GL_BLEND);     // Turn Blending On
				glEnable(GL_DEPTH_TEST);   // Turn Depth Testing Off
				glEnable(GL_TEXTURE_2D);
	
glPopMatrix();
				
glPushMatrix();
glTranslated(1.8,5,14);
              glEnable(GL_BLEND);     // Turn Blending On
			  glBlendFunc (GL_ONE, GL_ONE);
		
			  glBindTexture(GL_TEXTURE_2D,glass);
			glColor4f(1.0f, 1.0f, 1.0f, 0.03);
			glTranslated(0.1,0,0);
			glScaled(0.9,0.9,1);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d( -3, -1.9, 0.0);
			glTexCoord2d(1.0, 0.0); glVertex3d( 1, -1.9, 0.0);
			glTexCoord2d(1.0, 1.0); glVertex3d( 1, 1, 0.0);
			glTexCoord2d(0.0, 1.0); glVertex3d( -3, 1, 0.0);
			glEnd();
			glTranslated(0.08,0,-28);
			glScaled(0.9,0.9,1);
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d( -3, -1.9, 0.0);
			glTexCoord2d(1.0, 0.0); glVertex3d( 1, -1.9, 0.0);
			glTexCoord2d(1.0, 1.0); glVertex3d( 1, 1, 0.0);
			glTexCoord2d(0.0, 1.0); glVertex3d( -3, 1, 0.0);
			glEnd();




			  	glDisable(GL_BLEND);     // Turn Blending On
				glEnable(GL_DEPTH_TEST);   // Turn Depth Testing Off
				glEnable(GL_TEXTURE_2D);
	
glPopMatrix();

train->Draw();
glTranslated(2,2.2,13.5);
glScaled(0.04,0.04,0.04);

man->Draw();

	

	glPopMatrix();
	
	

	
	return TRUE;										// Everything Went OK
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
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
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right-WindowRect.left,	// Calculate Window Width
		WindowRect.bottom-WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
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

	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
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
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

	case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
			case SC_SCREENSAVE:					// Screensaver Trying To Start?
			case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
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
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
				   HINSTANCE	hPrevInstance,		// Previous Instance
				   LPSTR		lpCmdLine,			// Command Line Parameters
				   int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("NeHe's OpenGL Framework",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while(!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
			{
				done=TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{


			/*
				Keyboard_Input();
			objCamera.Mouse_Move();*/
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done=TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1]=FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen=!fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("ProjectGraphic",1024,800,16,fullscreen))
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
