#include<iostream>
#include <cmath>
#include "Jogador.h"
#include"Camera.h"


/*
	🔹 Classe cameraFPS
	Responsável por controlar a visão do jogador em primeira pessoa (FPS).

	➤ Atributos:
		- anguloHorizontal: rotação esquerda/direita (Eixo X do mouse)
		- anguloVertical: rotação cima/baixo (Eixo Y do mouse)
		- sensibilidade: define a velocidade de resposta ao movimento do mouse

	➤ Método principal:
		- MoverCamera(moverX, moverY):
			Atualiza os ângulos de visão de acordo com o movimento do mouse.
			Limita o ângulo vertical entre -89° e +89° para evitar rotação total.

	💡 Em jogos reais:
		- moverX → controla a rotação do corpo do jogador
		- moverY → controla a inclinação da cabeça/câmera
*/


class cameraFPS 
{
	float anguloHorizontal;
	float anguloVertical;
	float sensibilidade;
	float PI;


	
 public:
	 cameraFPS() :anguloHorizontal(0), anguloVertical(0), sensibilidade(0.5f) {}
	 float getAnguloHorizontal() const { return anguloHorizontal; }
	 float getAnguloVertical() const { return anguloVertical; }



	 void MoverCamera(int moverX, int moverY) 
	 {
		 anguloHorizontal += moverX * sensibilidade;
		 anguloVertical += moverY * sensibilidade;
		 if (anguloVertical > 89.0f) anguloVertical = 89.0f;
		 if (anguloVertical < -89.0f) anguloVertical = -89.0f;

		 cout << "Valor do angulo Horizontal:" << anguloHorizontal << endl;
		 cout << "Valor do angulo Vertical" << anguloVertical << endl;


	 }

	 void GetDirecao(float& dirX, float& dirY, float& dirZ)
	 {
		 /*
	🔹 Método GetDirecao()
		Converte os ângulos da câmera (horizontal e vertical)
		em um vetor tridimensional que representa a direção da mira.

		Fórmulas:
			 = cos(vertical) * cos(horizontal)
			dirY = sin(vertical)
			dirZ = cos(vertical) * sin(horizontal)

		➤ Esse vetor é usado para:
			- Calcular a trajetória do tiro
			- Direcionar projéteis e raios de detecção de colisão
			- Determinar o ponto que o jogador está mirando
*/

		 dirX = cos(anguloVertical * PI / 180) * cos(anguloHorizontal * PI / 180);
		 dirY = sin(anguloVertical * PI / 180);
		 dirZ = cos(anguloVertical * PI / 180) * sin(anguloHorizontal * PI / 180);
	 }

	 


};