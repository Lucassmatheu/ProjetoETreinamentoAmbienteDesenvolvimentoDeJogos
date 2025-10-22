#include <iostream>
using namespace std;

// Classe responsável por controlar o movimento do jogador
class Movimentos
{
private:
    int x; // posição no eixo X
    int y; // posição no eixo Y

public:
    // Construtor que define a posição inicial
    Movimentos() : x(0), y(0) {}

    // Método principal de controle de movimento
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
};
