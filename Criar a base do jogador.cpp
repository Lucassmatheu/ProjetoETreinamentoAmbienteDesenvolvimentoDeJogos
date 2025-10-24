#include <iostream>
#include <vector>
#include "Movimento.h"
#include"Camera.h"


using namespace std;

class Jogador
{
	private:
		string nome;
		int vida;
		int time;
		// Vector usado para armazenar a munição de cada arma do jogador.
		vector<int> municoes;
		int armaAtual = 0;
		vector<int> capacidadeMaxima;
		movimentacao  Movimentacao;
		cameraFPS camera;
	    
   
		
	    
	public:
		Jogador(string n, int v, int t)
			: nome(n), vida(v), time(t)
		{
			// Cada índice representa uma arma diferente (rifle, pistola, escopeta etc.).
			// Isso permite que cada arma tenha sua própria capacidade de disparos,
			// tornando o sistema mais realista e fácil de expandir.
			municoes = { 200,100,60,30, 15, 12, 5 }; 
			capacidadeMaxima = { 200,100,60,30, 15, 12, 5 };
		}
		


		void mover(char comando)
		{
			Movimentacao.controlar(comando);
		}
		void mouse(int deltaX, int deltaY) 
		{
			Movimentacao.moverComMouse(deltaX, deltaY);

		}


		 string getNome() const { return nome; }
		 int getVida() const { return vida; }
		 int getTime() const { return time; }
		 
		 void ButtonEsquerdoMouse(int ButtoMouse) 
		 {
			 Movimentacao.ButtoneEsquerdo(ButtoMouse);
			
		 }
		 
		 void atirar() 
		 {
			 float dirX, dirY, dirZ;
			 camera.GetDirecao(dirX, dirY, dirZ);

			 cout << "Tiro disparado na direção: ("
				 << dirX << ", " << dirY << ", " << dirZ << ")" << endl;
			 // Se Munição da arma atual maior 0
			 if (municoes[armaAtual] > 0)
			 {
				 municoes[armaAtual]--;
				 cout << nome << " disparou com a arma " << armaAtual
					 << "! Munição restante: " << municoes[armaAtual] << endl;
				 if (municoes[armaAtual] == 0) 
				 {
					 recarregar();
				 }
			 }
			 else
			 {
				 cout << "Sem munição na arma " << armaAtual << "!" << endl;
			 }
		 } 
		 void tomarDano(int dano)
		 {
			 vida = 100;
			 vida -= dano;
			 if (vida < 0) {
				 vida = 0;
					 cout << nome << " tomou " << dano << " de dano. Vida atual: " << vida << endl;
			 }
		 
		 }
		 void recarregar()
		 {
			 municoes[armaAtual] = capacidadeMaxima[armaAtual];
			 cout << "A arma " << armaAtual << " foi recarregada." << endl;


		 };
		 
		 void olharComMouse(int deltaX, int deltaY) 
		 {
			 camera.MoverCamera(deltaX, deltaY);

		 }
		
		 



};
/*
	🔹 SOBRE empty() e push_back():

	- O método empty() é usado em vetores (std::vector) para verificar se o vetor está vazio.
	  Retorna true se não houver nenhum elemento dentro do vetor, e false caso contrário.
	  Exemplo:
		  if (municoes.empty()) { cout << "Sem armas!" << endl; }

	- O método push_back() adiciona um novo elemento ao final do vetor.
	  Ele é muito usado para inserir dinamicamente valores em um vetor,
	  principalmente quando o tamanho dele pode variar durante o jogo.
	  Exemplo:
		  municoes.push_back(30); // adiciona uma arma com 30 balas

	💡 No contexto do jogo FPS:
	   Você pode usar push_back() para adicionar novas armas ao inventário do jogador,
	   e empty() para verificar se o jogador não tem nenhuma arma equipada.
*/