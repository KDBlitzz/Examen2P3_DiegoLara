#pragma once
#include "Mago.h"
class CampamentoMagos
{
private:
	vector<Mago*> magos;
public:
	CampamentoMagos();
	CampamentoMagos(vector<Mago*> magos);
	~CampamentoMagos();
	vector<Mago*> getMagos();
	void setMagos(vector<Mago*> magos);
	void AgregarMago(Mago* NuevoMago);
	void EliminarMago(int indiceMago);
	void ListarMagos();
	void GuardarMagos();
	void CargarMagos();
	void SimularBatalla();
};

