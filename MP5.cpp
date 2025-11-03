#include<iostream>
#include "ClasseArma.h"
using namespace std;


class MP5 : public Arma
{
	public:
		//Contrutor com valores específicos para a MP5
	//	        tIpo da arma,     dano,   velocidade do projétil,  distancia maxima		
	MP5() : Arma("MP5",         20,         600.0,                 250.0f) {}
	void disparar(float dirX, float dirY, float dirZ) override
	{
		cout << "MP5 disparou!" << endl;
		cout << "Direção do tiro: ("
			<< dirX << ", " << dirY << ", " << dirZ << ")" << endl;
	}
	void recarregar() override
	{
		cout << "MP5 está recarregando..." << endl;
	}
};