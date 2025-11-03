#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Arma
{
private:
    string nome;
    int dano;
    double velocidadeMaxima;
    float distanciaMaxima;

    // Controle de tiro
    float fireRateRPM;             // tiros por minuto
    float tempoDesdeUltimoTiro;    // cronômetro interno
    bool modoAutomatico;           // true = AUTO, false = SEMI

public:

    // Construtor
    Arma(string n, int d, double v, float dist)
        : nome(n),
        dano(d),
        velocidadeMaxima(v),
        distanciaMaxima(dist),
        fireRateRPM(600.0f),
        tempoDesdeUltimoTiro(0.0f),
        modoAutomatico(true)
    {
    }

    virtual ~Arma() = default;

    // Métodos abstratos (implementados nas subclasses)
    virtual void disparar(float dirX, float dirY, float dirZ) = 0;
    virtual void recarregar() = 0;

    // ✅ Controle de tiro e cadência
    bool tentarDisparar(bool gatilhoSegurado, bool gatilhoApertado,
        float deltaTime,
        float dirX, float dirY, float dirZ);
   

    // ✅ Alternar modo automático/semi
    void alternarModoDisparo();
    
    

    // ✅ Getters
    int getDano() const { return dano; }
    double getVelocidade() const { return velocidadeMaxima; }
    float getDistanciaMaxima() const { return distanciaMaxima; }

    // ✅ Configuração do FireRate
    void  setFireRateRPM(float rpm) { fireRateRPM = rpm; }
    float getFireRateRPM() const { return fireRateRPM; }

    // ✅ Reset no temporizador de cadência ao trocar de arma
    void resetTempoDesdeUltimoTiro() { tempoDesdeUltimoTiro = 0.0f; }
};
