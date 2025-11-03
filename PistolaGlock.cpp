#include <iostream>	
#include "ClasseArma.h"
using namespace std;

class PistolaGlock : public Arma
{
	public:
		//Contrutor com valores específicos para a Pistola Glock
	//	                   tIpo da arma,          dano,   velocidade do projétil,  distancia maxima		
	PistolaGlock() : Arma("Pistola Glock",         20,         350.0,                 150.0f) {}
	void disparar(float dirX, float dirY, float dirZ) override
	{
		cout << "Pistola Glock disparou!" << endl;
		cout << "Direção do tiro: ("
			<< dirX << ", " << dirY << ", " << dirZ << ")" << endl;
	}
	void recarregar() override
	{
		cout << "Pistola Glock está recarregando..." << endl;
	}
};