#pragma once
#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <iostream>
using namespace std;

class movimentacao
{
    int x, y;

public:
    movimentacao() : x(0), y(0) {}

    void controlar(char comando);
    void moverComMouse(int mouseX, int mouseY);
    void ButtoneEsquerdo(int apertarButtonEsquerdo);

};
#endif