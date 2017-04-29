/*
	Subject : Computer Graphics
	Student Number : 20113337 
	Name : Choi young keun
	Title : HW1
*/


#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

#define GRAVITY 9.8f
#define PI 3.14f

#define MAX_SPEED 11
#define MIN_XSPEED -5


class Polygon{
private:
	float g_delta_x;
	float g_delta_y;
	float velocity_x;
	float velocity_y;
	float g_color_r;
	float g_color_g;
	float g_color_b;
	float timer;

public:
	Polygon(){
		g_delta_x = 0.0f;
		g_delta_y = 1.0f;
		g_color_r = 1.0f;
		g_color_g = 1.0f;
		g_color_b = 0.0f;
		velocity_x = 0.0f;
		velocity_y = 0.0f;
		timer = 0.0f;
	}
	void init_S();				//initialize Square
	void init_C();				//initialize Circle
	void init_star();				//initialize Star
	void init_random();			//display all Particle
	void setColor(float r, float g, float b);			//setting color
	void setVelocity(float x, float y);				//setting velocity
	void setVertex();								//setting vertex3f
	void timerPlus();								//time += 0.01f

	float getVertexX();							//return g_delta_x
	float getVertexY();							//return g_delta_y

};


class Gogh{
private:
	int count;
	Polygon *s;
public:
	Gogh(int num) 
	{	
		count = num;
		s = new Polygon[count];
	}
	void setCount(int count);				//setting Polygon number
	void print_S();						//print Square
	void print_C();						//print Circle
	void print_star();					//print Star
	void print_random();					//print random polygons
	void setV();							//setting vertexs
	void setColor();						//setting colors
	void draw();							//display polygons vertex 
	void timer();							//increase polygons timer
	void setColor(float r, float g, float b);	//select polygons color 

};


#endif