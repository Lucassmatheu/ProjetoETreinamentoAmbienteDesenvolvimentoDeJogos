#pragma once
#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <iostream>
using namespace std;

class movimentacaoJ
{
    int x, y;

public:
    movimentacaoJ() : x(0), y(0) {}

    void controlar(char comando);
    void moverComMouse(int mouseX, int mouseY);
    void ButtoneEsquerdo(int apertarButtonEsquerdo);

};
#endif