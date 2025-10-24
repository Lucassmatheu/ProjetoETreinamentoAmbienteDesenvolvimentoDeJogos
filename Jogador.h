#ifndef JOGADOR_H
#define JOGADOR_H

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
    vector<int> municoes;
    int armaAtual;
    vector<int> capacidadeMaxima;
    movimentacao Movimentacao;
    cameraFPS camera;

public:
    Jogador(string n, int v, int t);
    void mover(char comando);
   
    void atirar();
    void recarregar();
    void tomarDano(int dano);
    void moverComMouse(int mouseX, int mouseY);

    string getNome() const;
    int getVida() const;
    int getTime() const;
};

#endif