#pragma once

class cameraFPS
{
	float anguloHorizontal;
	float anguloVertical;
	float sensibilidade;
	
 public:
	cameraFPS() :anguloHorizontal(0), anguloVertical(0), sensibilidade(0.5f) {}

	void MoverCamera(int moverX, int moverY);
	void GetDirecao(float& dirX, float& dirY, float& dirZ);



};