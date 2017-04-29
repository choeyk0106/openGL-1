#include <GL/freeglut.h>
#include <iostream>
#include <unistd.h>
#include "Polygon.h"

//////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------- Polygon Class ADT -----------------------------------*/

void Polygon::init_S(){

	glPushMatrix();
	glTranslatef(g_delta_x, g_delta_y, 0);
	glColor3f(g_color_r,  g_color_g, g_color_b);
	glBegin(GL_POLYGON);
	glVertex3f(0.15f, 0.15f, 0.0f);		
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, 0.15f, 0.0f);
	glEnd();	
	glPopMatrix();

}

void Polygon::init_C(){

	glPushMatrix();
	glTranslatef(g_delta_x, g_delta_y, 0);		//(x, y, z) 로 물체를 이동시킴
		glColor3f(g_color_r,  g_color_g, g_color_b);
		glBegin(GL_POLYGON);

		for(int i=0; i<=100; i++){
			float angle = 2*PI*i/100;
			glVertex3f(cos(angle)/5, sin(angle)/5, 0.0f);
		}
		glEnd();
	glPopMatrix();

}

void Polygon::init_star(){

	glPushMatrix();
	glTranslatef(g_delta_x, g_delta_y, 0);		//(x, y, z) 로 물체를 이동시킴
	glColor3f(g_color_r,  g_color_g, g_color_b);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -0.20f, 0.0f);
	glVertex3f(0.20f, -0.32f, 0.0f);
	glVertex3f(0.12f, -0.12f, 0.0f);
	glVertex3f(0.32f, 0.04f, 0.0f);
	glVertex3f(0.08f, 0.04f, 0.0f);
	glVertex3f(0.0f, 0.32f, 0.0f);
	glVertex3f(-0.08f, 0.04f, 0.0f);
	glVertex3f(-0.32f, 0.04f, 0.0f);
	glVertex3f(-0.12f, -0.12f, 0.0f);
	glVertex3f(-0.20f, -0.32f, 0.0f);
	glEnd();
	glPopMatrix();

}

void Polygon::init_random(){
	init_S();
	init_star();
	init_C();
}

void Polygon::setVelocity(float x, float y){
	velocity_x = x;
	velocity_y = y;

}

void Polygon::setVertex(){

	g_delta_x = velocity_x * timer;
	g_delta_y = velocity_y * timer - 0.5 * GRAVITY * timer * timer;

	if(g_delta_y <= 0 ){ 					//Clipping
		timer = 0.0f;
	}
	else if(g_delta_y > 10)
		timer == 0.0f;
	else if(g_delta_x < -5)
		timer == 0.0f;
	else if(g_delta_x > 5)
		timer == 0.0f;

}

void Polygon::setColor(float r, float g, float b){

	g_color_r = r;
	g_color_b = b;
	g_color_g = g;

}

void Polygon::timerPlus(){
	timer += 0.01f;
}

float Polygon::getVertexX(){
	return g_delta_x;
}

float Polygon::getVertexY(){
	return g_delta_y;
}


////////////////////////////////////////////////////////////////////////////////
/*-------------------------------- Gogh Class ADT ---------------------------------*/

void Gogh::setCount(int num){
	delete[] s;
	count = num;
	s = new Polygon[count];
	setV();
}

void Gogh::print_S(){
	for(int i=0; i<count; i++){
		s[i].init_S();
		
	}

}

void Gogh::print_C(){
	for(int i=0; i<count; i++){
		s[i].init_C();
		
	}
}

void Gogh::print_star(){
	for(int i=0; i<count; i++){
		s[i].init_star();
		
	}
}

void Gogh::print_random(){
	int i=0;
	for(i=0; i<count/3; i++)
		s[i].init_star();
	for(i=count/3; i<count*2/3; i++)
		s[i].init_C();
	for(i=count*2/3; i<count; i++)
		s[i].init_S();

}
void Gogh::setV(){

	srand((unsigned int)time(NULL));
	for(int i=0; i<count; i++){
		
		float vx = (float)rand()/(float)RAND_MAX;
		float vy = (float)rand()/(float)RAND_MAX;

		vx *= MAX_SPEED;
		vy *= MAX_SPEED;
		vx += MIN_XSPEED;
		vy += 5;

		s[i].setVelocity(vx, vy);
	}
}

void Gogh::setColor(){

	srand((unsigned int)time(NULL));				//set random color
	for(int i=0; i<count; i++){

		float r = (float)rand()/(float)RAND_MAX;
		float g = (float)rand()/(float)RAND_MAX;
		float b = (float)rand()/(float)RAND_MAX;

		s[i].setColor(r, g, b);
	}

}

void Gogh::setColor(float r, float g, float b){
	for(int i=0; i<count; i++){
		s[i].setColor(r, g, b);
	}

}

void Gogh::draw(){

	for(int i=0; i<count; i++){
		s[i].setVertex();
	}
}

void Gogh::timer(){

	for(int i=0; i<count; i++){
		s[i].timerPlus();
	}
}


