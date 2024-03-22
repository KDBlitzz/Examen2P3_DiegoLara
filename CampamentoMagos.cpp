#include "CampamentoMagos.h"

CampamentoMagos::CampamentoMagos()
{
}

CampamentoMagos::CampamentoMagos(vector<Mago*> magos)
{
	this->magos = magos;
}

CampamentoMagos::~CampamentoMagos()
{
	for (int i = 0; i < this->magos.size(); i++) // borrar memoria
	{
		delete this->magos[i];
	}
	this->magos.clear();
}

vector<Mago*> CampamentoMagos::getMagos()
{
	return this->magos;
}

void CampamentoMagos::setMagos(vector<Mago*> magos)
{
	this->magos = magos;
}

void CampamentoMagos::AgregarMago(Mago* NuevoMago)
{
	magos.push_back(NuevoMago);
}

void CampamentoMagos::EliminarMago(int indiceMago)
{
	this->magos.erase(this->magos.begin() + indiceMago); // eliminar el mago en el indice dado
}

void CampamentoMagos::ListarMagos()
{
	for (int i = 0; i < magos.size(); i++)
	{
		cout << "Mago: #" << i + 1 << endl;
		magos[i]->to_String();
	}
}

void CampamentoMagos::GuardarMagos()
{
	ofstream archivo("Magos.dal", ios::binary);
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	for (const Mago* mago : magos) {
		archivo.write(reinterpret_cast<const char*>(mago), sizeof(Mago));
	}
	archivo.close();
}

void CampamentoMagos::CargarMagos()
{
	ifstream archivo("Magos.dal", ios::binary);
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	Mago* magoTemp = new Mago();
	while (archivo.read(reinterpret_cast<char*>(magoTemp), sizeof(Mago))) {
		magos.push_back(magoTemp);
		magoTemp = new Mago();
	}
	//delete magoTemp;
	archivo.close();

}
void CampamentoMagos::SimularBatalla()
{
}