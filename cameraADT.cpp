#include <GL/freeglut.h>
#include <iostream>
#include "Polygon.h"
#include "Camera.h"

Camera::Camera(){

}

void Camera::move_Cam(float x, float y, float fovy, float gl_aspect){

	// camere instrinsic parameter  
	gl_eye_x = x;
	gl_eye_y = y;
	gl_fovy = fovy; 
	gl_aspect = gl_aspect;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		

	//원근투영(시야각, 종횡비, 전방절단면, 후방절단면)
	gluPerspective(gl_fovy, gl_aspect, 0.01f, 10.0f);		

	// camere extrinsic parameter  (view)
	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
   	gluLookAt(gl_eye_x, gl_eye_y, 2.0f,
      		gl_eye_x, gl_eye_y, 0.0f,
      		0.0f, 1.0f, 0.0f);
}