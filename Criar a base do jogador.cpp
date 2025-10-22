#include <iostream>
#include <vector>
#include "Movimento.h"

using namespace std;

class Jogador
{
	private:
		string nome;
		int vida;
		int time;
		// Vector usado para armazenar a muni��o de cada arma do jogador.
		vector<int> municoes;
		int armaAtual = 0;
		vector<int> capacidadeMaxima;
		
	    
	public:
		Jogador(string n, int v, int t)
			: nome(n), vida(v), time(t)
		{
			// Cada �ndice representa uma arma diferente (rifle, pistola, escopeta etc.).
			// Isso permite que cada arma tenha sua pr�pria capacidade de disparos,
			// tornando o sistema mais realista e f�cil de expandir.
			municoes = { 200,100,60,30, 15, 12, 5 }; 
			capacidadeMaxima = { 200,100,60,30, 15, 12, 5 };
		}
		




		 string getNome() const { return nome; }
		 int getVida() const { return vida; }
		 int getTime() const { return time; }
		 
		 
		 void atirar() 
		 {
			 // Se Muni��o da arma atual maior 0
			 if (municoes[armaAtual] > 0)
			 {
				 municoes[armaAtual]--;
				 cout << nome << " disparou com a arma " << armaAtual
					 << "! Muni��o restante: " << municoes[armaAtual] << endl;
				 if (municoes[armaAtual] == 0) 
				 {
					 recarregar();
				 }
			 }
			 else
			 {
				 cout << "Sem muni��o na arma " << armaAtual << "!" << endl;
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

		 



};