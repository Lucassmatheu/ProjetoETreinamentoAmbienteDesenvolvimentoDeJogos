#include<iostream>
#include"Jogador.h"
using namespace std;


class Projetil 
{
	float posicaoX, posicaoY, posicaoZ;
	float direcaoX, direcaoY, direcaoZ;
	float velocidade;
	float distancia_Maxima;

  public:
	  Projetil() : posicaoX(0), posicaoY(0), posicaoZ(0), velocidade(), distancia_Maxima() {}

	  void AtualizarProjetil(float pX, float pY, float pZ) 
	  {
		  posicaoX += direcaoX * velocidade;
		  posicaoY += direcaoY * velocidade;
		  posicaoZ += direcaoZ * velocidade;

	  }

};