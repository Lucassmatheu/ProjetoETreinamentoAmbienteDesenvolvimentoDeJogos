#include <iostream>
#include <vector>
#include "Camera.h"
#include "ClasseArma.h"

using namespace std;

class Jogador
{
private:
    string nome;
    int vida;
    int time;

    vector<Arma*> arsenal;   // Armas do jogador
    vector<int> municoes;    // Munição atual por arma
    vector<int> capacidadeMaxima;

    int armaAtual;

    cameraPS camera; 

    bool gatilhoAnterior = false;

public:
    Jogador(string n, int v, int t)
        : nome(n), vida(v), time(t), armaAtual(0)
    {
    }

    void adicionarArma(Arma* arma, int balas, int capMax)
    {
        arsenal.push_back(arma);
        municoes.push_back(balas);
        capacidadeMaxima.push_back(capMax);

        cout << "Pegou arma com " << balas << "/" << capMax << endl;
    }
    void teclaBPressionada() {
        arsenal[armaAtual]->alternarModoDisparo();
    }

    void trocarArma(int indice)
    {
        if (indice >= 0 && indice < arsenal.size())
        {
            armaAtual = indice;
            cout << "Arma trocada para índice " << armaAtual << endl;
        }
        else
        {
            cout << "Arma inválida!" << endl;
        }
    }

    void atualizar(bool gatilhoSegurado, float deltaTime)
    {
        float dirX, dirY, dirZ;
        camera.GetDirecao(dirX, dirY, dirZ);

        bool gatilhoApertado = (gatilhoSegurado && !gatilhoAnterior);
        gatilhoAnterior = gatilhoSegurado;

        if (municoes[armaAtual] <= 0)
        {
            cout << "Sem munição! Recarregando..." << endl;
            recarregar();
            return;
        }

        bool disparou = arsenal[armaAtual]->tentarDisparar(
            gatilhoSegurado,
            gatilhoApertado,
            deltaTime,
            dirX, dirY, dirZ);

        if (disparou)
        {
            municoes[armaAtual]--;

            cout << "Tiro! Munição: "
                << municoes[armaAtual] << "/"
                << capacidadeMaxima[armaAtual] << endl;

            // ✅ RECOIL aplicado ao disparo 🔥
            camera.MoverCamera(0, -5);

            if (municoes[armaAtual] == 0)
                recarregar();
        }
    }

    void recarregar()
    {
        municoes[armaAtual] = capacidadeMaxima[armaAtual];
        cout << "Recarregado: "
            << municoes[armaAtual] << "/"
            << capacidadeMaxima[armaAtual] << endl;
    }

    void olharComMouse(int dx, int dy)
    {
        camera.MoverCamera(dx, dy);
    }

    void tomarDano(int dano)
    {
        vida -= dano;
        if (vida < 0) vida = 0;

        cout << nome << " tomou " << dano << " de dano! Vida atual: " << vida << endl;
    }

    string getNome() const { return nome; }
    int getVida() const { return vida; }
    int getTime() const { return time; }
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
