#include <iostream>
using namespace std;

// Classe respons�vel por controlar o movimento do jogador
class Movimentos
{
private:
    int x; // posi��o no eixo X
    int y; // posi��o no eixo Y

public:
    // Construtor que define a posi��o inicial
    Movimentos() : x(0), y(0) {}

    // M�todo principal de controle de movimento
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

        case 's': // mover para tr�s
            cout << "Andando para tr�s!" << endl;
            y -= 1;
            break;

        case 'S': // correr (Shift)
            cout << "Correndo com SHIFT!" << endl;
            y += 2;
            break;

        default:
            cout << "Comando inv�lido!" << endl;
        }

        // Mostra posi��o atual
        cout << "Posi��o atual: (" << x << ", " << y << ")\n";
    }
};
