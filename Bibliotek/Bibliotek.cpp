// Bibliotek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "draw.h"
#include "Polygon.h"

int main()
{

	draw test = draw(1, 2); //Oppretter 2 punkter med 2 koordinater. Kan bruke 3 også.
	draw test2 = draw(6, 8);
	draw b = draw(2, 3);
	//test.skriv();
	//test2.skriv();
	//draw linje = draw(test,test2); //Har konstruktoren satt opp sånn at den kan enten ta inn koordinater(int) eller 2 punkter.
	//linje.skriv(); 
	Polygon test3 = Polygon(test, test2);
	//test3.pSkriv();
	Polygon a = test3 + test2;
	Polygon c = a - test;
	Polygon d = a + test;
	d = d + test2;
	a.pSkriv();
	c.pSkriv();
	d.pSkriv();
	return 0;
}