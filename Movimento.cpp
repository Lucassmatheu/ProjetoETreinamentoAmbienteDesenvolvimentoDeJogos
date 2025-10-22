#include <iostream>
#include <vector>
#include "Movimento.h

class movimento 
{
	int x, y;

	public:
		void andar() 
		{
            switch (comando) {
            case 'w': // nadar para frente
                std::cout << "Nadando para frente!" << std::endl;
                y += 1;
                break;
            case 'a': // nadar para o lado esquerdo
                std::cout << "Nadando para a esquerda!" << std::endl;
                x -= 1;
                break;
            case 'd': // nadar para o lado direito
                std::cout << "Nadando para a direita!" << std::endl;
                x += 1;
                break;
            case 's': // nadar para trás
                std::cout << "Nadando para trás!" << std::endl;
                y -= 1;
                break;
            case 'S': // correr com Shift (letra maiúscula)
                std::cout << "Correndo com SHIFT!" << std::endl;
                x += 2; // exemplo de corrida mais rápida
                break;
            default:
                std::cout << "Comando inválido!" << std::endl;
            }


		}
		void correr()
		{
		}
};