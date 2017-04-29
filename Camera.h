#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>
#include <GL/freeglut.h>

class Camera{
private:
	float gl_eye_x;		//move left camera		
	float gl_eye_y;		//move right camera
	float gl_fovy;		//in-out camera
	float gl_aspect;		//
public:
	Camera(); 
	void move_Cam(float x, float y, float fovy, float gl_aspect);
};

#endif