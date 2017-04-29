#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include "Polygon.h"
#include "Camera.h"

static int polygon_count=0;
static int shape = 1;

//polygon parameter
static float init_x = 0.0f;
static float init_y = 0.0f;
static float gl_delta_x =  0.0f;
static float gl_delta_y =  0.0f;

//camera parameter
static float gl_eye_x = 0.0f;					
static float gl_eye_y = 5.0f;
static float gl_fovy = 155.0f;
static float gl_aspect = 0.0f;

//polygon init
Gogh G(100);			//default 100

//camera init
Camera* C = new Camera;

//call back function
void myidle();
void mydisplay();
void init();
void myreshape(int width, int height);
void mykeyboard(int key, int x, int y);
void mykeyboard(unsigned char key, int x, int y);
void mymouse(int button, int state, int x, int y);
void mymenu(int value);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 400);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	
	glutCreateWindow("Polygon Fountain");		//실제 창이 만들어 지는곳

	init();		//initialize

	glutMouseFunc(mymouse);
	glutReshapeFunc(myreshape);
	glutSpecialFunc(mykeyboard);
	glutKeyboardFunc(mykeyboard);
	glutIdleFunc(myidle);
	
	glutDisplayFunc(mydisplay);	//실제 화면을 구성하는 곳

	glutMainLoop();

	return 0;
}


void init(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	G.setV();			//initialize first velocity
	G.setColor();		//initialize first color

}
void myreshape(int weight, int height){
	gl_aspect = (float)weight / (float)height;
	glViewport(0, 0, weight, height);
	glutPostRedisplay();
}

void mykeyboard(int key, int x, int y){
	
	switch(key){
		case GLUT_KEY_LEFT:
			gl_eye_x += -0.1f ;
			break;
		case GLUT_KEY_RIGHT:
			gl_eye_x += 0.1f;
			break;
		case GLUT_KEY_UP:
			gl_eye_y += 0.1f;
			break;
		case GLUT_KEY_DOWN:
			gl_eye_y += -0.1f;
			break;
		case GLUT_KEY_HOME:
			gl_eye_x = 0.0f;					
			gl_eye_y = 5.0f;
			gl_fovy = 155.0f;
			break;
	}
	glutPostRedisplay();
}
void mykeyboard(unsigned char key, int x, int y){
	
	switch(key){
		case '-':
		case '_':
			gl_fovy += 2.0f ;
			break;
		case '+':
		case '=':
			gl_fovy += -2.0f;
			break;
	}
	glutPostRedisplay();
}
void mymouse(int button, int state, int x, int y){

	switch(button){

		case GLUT_RIGHT_BUTTON:
			int submenu1 = glutCreateMenu(mymenu);
    	 		glutAddMenuEntry("# of polygons = 150",1);
     			glutAddMenuEntry("# of polygons = 500",2);
     			glutAddMenuEntry("# of polygons = 1000",3);
     			glutAddMenuEntry("# of polygons = 3000",4);
     			glutAddMenuEntry("# of polygons = 5000",5);

     			int submenu2 = glutCreateMenu(mymenu);
     			glutAddMenuEntry("# red",6);
     			glutAddMenuEntry("# green",7);
     			glutAddMenuEntry("# violet",8);
     			glutAddMenuEntry("# white",9);
     			glutAddMenuEntry("# initialize", 10);

     			int submenu3 = glutCreateMenu(mymenu);
    	 		glutAddMenuEntry("# Square",11);
     			glutAddMenuEntry("# Circle",12);
     			glutAddMenuEntry("# Star",13);
     			glutAddMenuEntry("# Random",14);

     			int mainmanu = glutCreateMenu(mymenu);
     			glutAddSubMenu("Polygon Count", submenu1);
     			glutAddSubMenu("Polygon Color", submenu2);
     			glutAddSubMenu("Polygon Shape", submenu3);

     			glutAttachMenu(GLUT_RIGHT_BUTTON);

     			glutPostRedisplay();
			break;
	}
}

//mouse click event
void mymenu(int value){
	
	switch(value) {
     case 1:
          polygon_count = 150;
          G.setCount(polygon_count);
          G.setColor();
          break;
     case 2:
          polygon_count = 500;
          G.setCount(polygon_count);
          G.setColor();
          break;
     case 3:
          polygon_count = 1000;
          G.setCount(polygon_count);
          G.setColor();
          break;
     case 4:
          polygon_count = 3000;
          G.setCount(polygon_count);
          G.setColor();
          break;
     case 5:
          polygon_count = 5000;
          G.setCount(polygon_count);
          G.setColor();
          break;
     case 6:
     	G.setColor(0.9155f, 0.1f, 0.1f);
          break;
     case 7:
     	G.setColor(0.1f, 0.865f, 0.2f);
          break;
     case 8:
     	G.setColor(0.5456f, 0.0f, 0.8f);
          break;
     case 9:
     	G.setColor(1.0f, 1.0f, 1.0f);
          break;
     case 10:
     	G.setColor();
          break;
     case 11:
     	shape = 1;
          break;
     case 12:
     	shape = 2;
          break;
     case 13:
     	shape = 3;
          break;
     case 14:
     	shape = 4;
          break;
     }
	glutPostRedisplay();
}
void myidle(){

	G.draw();			//update vertex

	glutPostRedisplay();
}

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	
	C->move_Cam(gl_eye_x, gl_eye_y, gl_fovy, gl_aspect);

	if(shape==1)				//select polygon shape
		G.print_S();
	else if(shape==2)
		G.print_C();
	else if(shape==3)
		G.print_star();
	else if(shape==4)
		G.print_random();
	
		G.timer();		//increase timer 
	

	glColor3f(0.6f, 0.1f, 0.3f);
	glBegin(GL_POLYGON);
	glVertex3f(3.5f, 0.0f, 0.0f);		
	glVertex3f(3.5f, -2.0f, 0.0f);
	glVertex3f(-3.5f, 0.0f, 0.0f);
	glVertex3f(-3.5f, -2.0f, 0.0f);
	glEnd();

	glutSwapBuffers();
}
