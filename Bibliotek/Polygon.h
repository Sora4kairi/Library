#pragma once
#include "stdafx.h"
#include "draw.h"
#include <iostream>
class Polygon //Polygon brukes for linjer her. Setter sammen til en trekant/firkant. 
{
	
private:
	draw Pa, Pb, Pc, Pd; //Støtter opp til 4 punkt per polygon for øyeblikket. 

public:
	Polygon(draw a, draw b, draw c) { //Tar inn 3 punkter fra draw. 
		this->Pa = a;
		this->Pb = b;
		this->Pc = c;
	};
	Polygon pSkriv() { //Kaller på skriv fra draw til å skrive ut hvert punkts koordinater. 
		std::cout << std::endl << "Punkt a: ";
		Pa.skriv();
		std::cout << std::endl << "Punkt b: ";
		Pb.skriv();
		std::cout << std::endl << "Punkt c: ";
		Pc.skriv();
		std::cout << std::endl << "Punkt d: ";
		Pd.skriv();
		std::cout << std::endl;
		return 0;
	};
	Polygon(draw a, draw b) { //2 punkter istedetfor 3, setter siste punktet automatiskt til 0. 
		this->Pa = a;
		this->Pb = b;
	};
	Polygon(Polygon a, draw c) { //Linje og punkt, vil da sette inn verdien fra de den har og til slutt til punktet. 
		this->Pa = a.Pa;
		this->Pb = a.Pb;
		this->Pc = a.Pc;
		this->Pd = c;

	};
	Polygon(Polygon a, Polygon c) { //Kun støtte for 2-koordinater enda. 
		this->Pa = a.Pa;
		this->Pb = a.Pb;
		this->Pc = c.Pa;
		this->Pd = c.Pb;
	};

	Polygon(int x) { };//Bruker bare int som return-verdi så denne trenger ikke gjøre noe. 

	friend Polygon operator+(Polygon l, draw p) { return Polygon(l, p); }; //Overloader + for å fungere med både linje/punkt og linje/linje.
	friend Polygon operator+(Polygon l, Polygon j) { return Polygon(l, j); };
	friend Polygon operator==(Polygon l, draw p) { 
		draw a = draw(l.Pa);
		draw b = draw(l.Pb);
		draw c = draw(l.Pc);
		draw d = draw(l.Pd);
		if(a.x == p.x || a.y == p.y || a.z == p.z) return 1;
		else if(b.x == p.x || b.y == p.y || b.z == p.z) return 1;
		else if(c.x == p.x || c.y == p.y || c.z == p.z) return 1;
		else if(d.x == p.x || d.y == p.y || d.z == p.z) return 1;
		else return 0;
	};
	friend Polygon operator-(Polygon l, draw p) { //Sjekker om koordinatene er likt koordinatene til punktet man vil ta vekk. Er de det, vil den returnere et nytt polygon.
		draw a = draw(l.Pa);
		draw b = draw(l.Pb);
		draw c = draw(l.Pc);
		if (a.x == p.x || a.y == p.y || a.z == p.z) return Polygon(l.Pb, l.Pc);
		else if (b.x == p.x || b.y == p.y || b.z == p.z) return Polygon(l.Pa, l.Pc);
		else if (c.x == p.x || c.y == p.y || c.z == p.z) return Polygon(l.Pa, l.Pb);
		else return 0;
	};
	~Polygon();
};