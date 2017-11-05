#pragma once
#include "stdafx.h"
#include <iostream>
class draw //Bruker draw som punkt-klasse. Oppretter punkter med koordinater her som senere blir gjort om til polygoner. 
{
	
public:
	int x, y, z;
	draw()
	{
		this->x = 0; //Setter alle koordinatene som ikke er definert til 0.
		this->y = 0;
		this->z = 0;
	}
	draw(int x, int y) //2 koordinater, siste blir automatisk satt til 0.
	{
		this->x = x;
		this->y = y;
		this->z = 0;
	};

	draw(int x) //Samme som over, de koordinatene som ikke blir definert blir satt til 0. 
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