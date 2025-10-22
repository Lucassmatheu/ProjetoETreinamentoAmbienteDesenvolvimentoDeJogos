#include "Movimento.h"
#include<iostream>
using namespace std;

class movimentacao 
{
	int x, y;

	public:
        movimentacao() : x(0), y(y) {}

        void controlar(char comando)
        {
            switch (comando) {
            case 'w': // mover para frente
                cout << "Andando para frente!" << endl;
                y += 1;
                break;

            case 'a': // mover para esquerda
                cout << "Andando para a esquerda!" << endl;
                x -= 1;
                break;

            case 'd': // mover para direita
                cout << "Andando para a direita!" << endl;
                x += 1;
                break;

            case 's': // mover para trás
                cout << "Andando para trás!" << endl;
                y -= 1;
                break;

            case 'S': // correr (Shift)
                cout << "Correndo com SHIFT!" << endl;
                y += 2;
                break;

            default:
                cout << "Comando inválido!" << endl;
            }

            // Mostra posição atual
            cout << "Posição atual: (" << x << ", " << y << ")\n";
        }
        void moverComMouse(int mouseX, int mouseY) {
            x = mouseX;
            y = mouseY;
            std::cout << "Movendo para posição do mouse: (" << x << ", " << y << ")" << std::endl;
        }
};