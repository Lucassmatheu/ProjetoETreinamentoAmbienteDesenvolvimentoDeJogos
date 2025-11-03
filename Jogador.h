#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <vector>
#include "ClasseArma.h"  // Agora o Jogador usa Arma*
#include "Camera.h"
using namespace std;

class Jogador
{
private:
    string nome;
    int vida;
    int time;

    vector<Arma*> arsenal;      // Lista de armas
    vector<int> municoes;       // Munição de cada arma
    vector<int> capacidadeMaxima; // Capacidade por arma

    int armaAtual;

    cameraPS camera;

    // Controle do tiro
    bool gatilhoAnterior = false;
    float tempoDesdeUltimoTiro = 0.0f;

public:

    // Construtor
    Jogador(string n, int v, int t);

    // Controle de movimento
    
    void moverComMouse(int mouseX, int mouseY);

    // Lógica de tiro — chamada por frame do jogo
    void atualizar(bool gatilho, float deltaTime);

    // Arsenal
    void adicionarArma(Arma* arma, int balas, int capMax);
    void trocarArma(int indice);
    void recarregar();
  

    // Dano
    void tomarDano(int dano);

    // Getters
    string getNome() const;
    int getVida() const;
    int getTime() const;
};

#endif
