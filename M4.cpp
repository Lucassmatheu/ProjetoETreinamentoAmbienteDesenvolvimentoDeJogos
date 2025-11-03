#include <iostream>
#include "ClasseArma.h"
using namespace std;

class M4 : public Arma
{
	public:
		//Contrutor com valores específicos para a M4
	//	        tIpo da arma,     dano,   velocidade do projétil,  distancia maxima		
	M4() : Arma("M4",         30,         700.0,                 350.0f) {}
	void disparar(float dirX, float dirY, float dirZ) override
	{
		cout << "M4 disparou!" << endl;
		cout << "Direção do tiro: ("
			<< dirX << ", " << dirY << ", " << dirZ << ")" << endl;
	}
	void recarregar() override
	{
		cout << "M4 está recarregando..." << endl;
	}
};