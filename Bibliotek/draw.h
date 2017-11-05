#pragma once
#include "stdafx.h"
#include <iostream>
class draw
{
	
public:
	int x, y, z;
	draw()
	{
		this->x = 0; //Setter alle koordinatene som ikke er definert til 0.
		this->y = 0;
		this->z = 0;
	}
	draw(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->z = 0;
	};

	draw(int x)
	{
		this->x = x;
		this->y = 0;
		this->z = 0;
	};
	draw(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	draw skriv() { //Skriver ut koordinatene til punktet. 
		std::cout << " x: " << x << " y: " << y << " z: " << z << std::endl;
		return 0;
	}
	friend draw operator==(draw a, draw b) { //Overloader == i tilfelle det vil brukes i main. 
		if (a.x == b.x || a.y == b.y || a.z == b.z) return true;
		else return false;
	}
	~draw();
};