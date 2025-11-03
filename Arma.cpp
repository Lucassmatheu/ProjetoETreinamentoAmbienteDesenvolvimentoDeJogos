#pragma once
#include <iostream>
using namespace std;

class Arma
{
private:
    string nome;
    int dano;
    double velocidadeMaxima;
    float distanciaMaxima;

    // Controle de tiro
    float fireRateRPM = 600.0f;       // tiros por minuto
    float tempoDesdeUltimoTiro = 0.0f;
    bool modoAutomatico = true;       // true = AUTO, false = SEMI

public:

    // Construtor
    Arma(string n, int d, double v, float dist)
        : nome(n), dano(d), velocidadeMaxima(v), distanciaMaxima(dist) {
    }

    virtual ~Arma() {}

    // Controle do modo de tiro
    void setModoAutomatico(bool valor) { modoAutomatico = valor; }
    bool getModoAutomatico() const { return modoAutomatico; }
    

    // Lógica de cadência (FPS game loop)
    bool tentarDisparar(bool gatilhoSegurado, bool gatilhoApertado,
        float deltaTime,
        float dirX, float dirY, float dirZ)
    {
		// Atualiza o tempo desde o último tiro
        tempoDesdeUltimoTiro += deltaTime;
		// Calcula o intervalo entre tiros em segundos
        float intervalo = 60.0f / fireRateRPM;

        if (modoAutomatico)
        {
			// se gatilho está segurado e o tempo desde o último tiro é maior ou igual ao intervalo
            if (gatilhoSegurado && tempoDesdeUltimoTiro >= intervalo)
            {
				// dispara a arma e reseta o temporizador
                disparar(dirX, dirY, dirZ);
                tempoDesdeUltimoTiro = 0.0f;
                return true;
            }
        }
        else // SEMI
        {
            if (gatilhoApertado && tempoDesdeUltimoTiro >= intervalo)
            {
                disparar(dirX, dirY, dirZ);
                tempoDesdeUltimoTiro = 0.0f;
                return true;
            }
        }
        return false;
    }
    void setFireRateRPM(float rpm) { fireRateRPM = rpm; }
    float getFireRateRPM() const { return fireRateRPM; }
    void alternarModoDisparo() {
		// Alterna o modo de tiro
		// entre automático e semiautomático 
		// e exibe no console
        modoAutomatico = !modoAutomatico;

        if (modoAutomatico)
            cout << "Modo de tiro: Automático" << endl;
        else
            cout << "Modo de tiro: Semiautomático" << endl;
    }

    // Métodos que a subclasse implementa
    virtual void disparar(float dirX, float dirY, float dirZ) = 0;
    virtual void recarregar() = 0;

    // Getters
    int getDano() const { return dano; }
    double getVelocidade() const { return velocidadeMaxima; }
    float getDistanciaMaxima() const { return distanciaMaxima; }
};
