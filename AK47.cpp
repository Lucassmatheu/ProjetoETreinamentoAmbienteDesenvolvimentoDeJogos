#include <iostream>
#include "ClasseArma.h"
using namespace std;

class AK47 : public Arma
{
public:
    // Construtor com valores específicos para a AK-47
    //      tipo, dano, velocidade do projétil, distancia maxima
    AK47() : Arma("AK-47", 35, 800.0, 400.0f)
    {
		// Define o RPM da AK-47
		// AQUI ESTA SENDO FEITO DE SEGUINTE FORMA EXPLICITA
		// SETANDO O VALOR DO FIRE RATE PARA 600 RPM
        setFireRateRPM(600.0f); // <- define o RPM da AK-47
    }

    void disparar(float dirX, float dirY, float dirZ) override
    {
        cout << "AK-47 disparou!" << endl;
        cout << "Direção do tiro: ("
            << dirX << ", " << dirY << ", " << dirZ << ")" << endl;
    }

    void recarregar() override
    {
        cout << "AK-47 está recarregando..." << endl;
    }
};
