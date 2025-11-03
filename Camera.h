#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>
using namespace std;

class cameraPS
{
private:
    float anguloHorizontal;
    float anguloVertical;
    float sensibilidade;
    const float PI = 3.14159265359f;

public:
    cameraPS()
        : anguloHorizontal(0), anguloVertical(0), sensibilidade(0.5f) {
    }

    void MoverCamera(int moverX, int moverY)
    {
        anguloHorizontal += moverX * sensibilidade;
        anguloVertical += moverY * sensibilidade;

        if (anguloVertical > 89.0f) anguloVertical = 89.0f;
        if (anguloVertical < -89.0f) anguloVertical = -89.0f;
    }

    void GetDirecao(float& dirX, float& dirY, float& dirZ)
    {
        dirX = cos(anguloVertical * PI / 180) * cos(anguloHorizontal * PI / 180);
        dirY = sin(anguloVertical * PI / 180);
        dirZ = cos(anguloVertical * PI / 180) * sin(anguloHorizontal * PI / 180);
    }
};

#endif
