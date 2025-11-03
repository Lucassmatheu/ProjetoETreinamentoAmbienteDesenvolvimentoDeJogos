#include "Movimento.h"
#include "Jogador.h"
#include "Camera.h"
#include <iostream>

using namespace std;

class movimentacao
{
    Jogador* jogador;
    cameraPS camera;

    int x, y;

public:
    movimentacao() : x(0), y(0), jogador(nullptr) {}

    void conectarJogador(Jogador* j)
    {
        jogador = j;
    }

    void controlar(char comando)
    {
        switch (comando) {
        case 'w':
            cout << "Andando para frente!" << endl;
            y += 1;
            break;

        case 'a':
            cout << "Andando para a esquerda!" << endl;
            x -= 1;
            break;

        case 'd':
            cout << "Andando para a direita!" << endl;
            x += 1;
            break;

        case 's':
            cout << "Andando para trás!" << endl;
            y -= 1;
            break;

        case 'S':
            cout << "Correndo com SHIFT!" << endl;
            y += 2;
            break;

        default:
            cout << "Comando inválido!" << endl;
        }

        cout << "Posição atual: (" << x << ", " << y << ")\n";
    }

    void moverComMouse(int mouseX, int mouseY)
    {
        x = mouseX;
        y = mouseY;
        camera.MoverCamera(mouseX, mouseY);

        cout << "Movendo para posição do mouse: (" << x << ", " << y << ")" << endl;
    }

    void BotaoEsquerdo(bool segurando, float deltaTime)
    {
        if (jogador)
            jogador->atualizar(segurando, deltaTime);
    }
};
