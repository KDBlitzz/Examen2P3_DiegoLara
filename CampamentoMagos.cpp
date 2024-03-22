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

void CampamentoMagos::AgregarMago(Mago* NuevoMago) // agrega los magos al vector
{
	magos.push_back(NuevoMago);
}

void CampamentoMagos::EliminarMago(int indiceMago)
{
	this->magos.erase(this->magos.begin() + indiceMago); // eliminar el mago en el indice dado
}

void CampamentoMagos::ListarMagos() // Listar todos los magos
{
	for (int i = 0; i < magos.size(); i++)
	{
		cout << "Mago: #" << i + 1 << endl;
		magos[i]->to_String();
	}
}

void CampamentoMagos::GuardarMagos() // Guarda los magos al binario
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

void CampamentoMagos::CargarMagos() // carga los magos existentes al vector de magos
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
void CampamentoMagos::SimularBatalla(int player1, int player2) // Simula la batalla entre dos magos
// utilizando validaciones y conversiones de daño
{
	double conversion = 0;
	double poderAtacante = 0;
	double totalDamage = 0;
	int random = 0;
	int contador = 1;
	bool turnoDeJugador1 = false;
	bool turnoDeJugador2 = false;
	cout << "¡Comienza la batalla entre " << magos[player1]->getNombre() << " y " << magos[player2]->getNombre() << " !" << endl << endl;
	cout << "Turno: " << contador << endl;
	if (magos[player1]->getVelocidad() > magos[player2]->getVelocidad()) {
		conversion = (magos[player1]->getAtaque() - (magos[player2]->getResistencia() / 2));
		poderAtacante = ((double)magos[player1]->getPoder() / 100);
		totalDamage = conversion * poderAtacante;
		magos[player2]->setVida(magos[player2]->getVida() - totalDamage);
		random = 5 + (rand() % 10);
		magos[player1]->setAtaque(magos[player1]->getAtaque() + random);
		cout << magos[player1]->getNombre() << " ataca a " << magos[player2]->getNombre() << " causando " << totalDamage << " de daño." << endl;
		cout << "Vida de " << magos[player2]->getNombre() << ": " << magos[player2]->getVida();
		contador++;
		turnoDeJugador2 = true;
		turnoDeJugador1 = false;
	}
	else if(magos[player1]->getVelocidad() < magos[player2]->getVelocidad()){
		conversion = (magos[player2]->getAtaque() - (magos[player1]->getResistencia() / 2));
		poderAtacante = ((double)magos[player2]->getPoder() / 100);
		totalDamage = conversion * poderAtacante;
		magos[player1]->setVida(magos[player1]->getVida() - totalDamage);
		random = 5 + (rand() % 10);
		magos[player2]->setAtaque(magos[player2]->getAtaque() + random);
		cout << magos[player2]->getNombre() << " ataca a " << magos[player1]->getNombre() << " causando " << totalDamage << " de daño." << endl;
		cout << "Vida de " << magos[player1]->getNombre() << ": " << magos[player1]->getVida() << endl;
		contador++;
		turnoDeJugador2 = false;
		turnoDeJugador1 = true;
	}
	else if (magos[player1]->getVelocidad() == magos[player2]->getVelocidad()) {
		if (magos[player1]->getPoder() > magos[player2]->getPoder())
		{
			conversion = (magos[player1]->getAtaque() - (magos[player2]->getResistencia() / 2));
			poderAtacante = ((double)magos[player1]->getPoder() / 100);
			totalDamage = conversion * poderAtacante;
			magos[player2]->setVida(magos[player2]->getVida() - totalDamage);
			random = 5 + (rand() % 10);
			magos[player1]->setAtaque(magos[player1]->getAtaque() + random);
			cout << magos[player1]->getNombre() << " ataca a " << magos[player2]->getNombre() << " causando " << totalDamage << " de daño." << endl;
			cout << "Vida de " << magos[player2]->getNombre() << ": " << magos[player2]->getVida() << endl;
			contador++;
			turnoDeJugador2 = true;
			turnoDeJugador1 = false;
		}
		else if (magos[player1]->getPoder() < magos[player2]->getPoder()) {
			conversion = (magos[player2]->getAtaque() - (magos[player1]->getResistencia() / 2));
			poderAtacante = ((double)magos[player2]->getPoder() / 100);
			totalDamage = conversion * poderAtacante;
			magos[player1]->setVida(magos[player1]->getVida() - totalDamage);
			random = 5 + (rand() % 10);
			magos[player2]->setAtaque(magos[player2]->getAtaque() + random);
			cout << magos[player2]->getNombre() << " ataca a " << magos[player1]->getNombre() << " causando " << totalDamage << " de daño." << endl;
			cout << "Vida de " << magos[player1]->getNombre() << ": " << magos[player1]->getVida() << endl;
			contador++;
			turnoDeJugador2 = false;
			turnoDeJugador1 = true;
		}
	}
	while (magos[player1]->getVida() > 0 && magos[player2]->getVida() > 0) {
		cout << "\nTurno: " << contador << endl;
		if (turnoDeJugador1)
		{
			conversion = (magos[player1]->getAtaque() - (magos[player2]->getResistencia() / 2));
			poderAtacante = ((double)magos[player1]->getPoder() / 100);
			totalDamage = conversion * poderAtacante;
			magos[player2]->setVida(magos[player2]->getVida() - totalDamage);
			random = 5 + (rand() % 10);
			magos[player1]->setAtaque(magos[player1]->getAtaque() + random);
			cout << magos[player1]->getNombre() << " ataca a " << magos[player2]->getNombre() << " causando " << totalDamage << " de daño." << endl;
			cout << "Vida de " << magos[player2]->getNombre() << ": " << magos[player2]->getVida() << endl;
			contador++;
			turnoDeJugador2 = true;
			turnoDeJugador1 = false;
		}
		if (turnoDeJugador2)
		{
			conversion = (magos[player2]->getAtaque() - (magos[player1]->getResistencia() / 2));
			poderAtacante = ((double)magos[player2]->getPoder() / 100);
			totalDamage = conversion * poderAtacante;
			magos[player1]->setVida(magos[player1]->getVida() - totalDamage);
			random = 5 + (rand() % 10);
			magos[player2]->setAtaque(magos[player2]->getAtaque() + random);
			cout << magos[player2]->getNombre() << " ataca a " << magos[player1]->getNombre() << " causando " << totalDamage << " de daño." << endl;
			cout << "Vida de " << magos[player1]->getNombre() << ": " << magos[player1]->getVida() << endl;
			contador++;
			turnoDeJugador2 = false;
			turnoDeJugador1 = true;
		}
	}
	cout << "¡La Batalla ha terminado!" << endl; // termina la batalla
	if (magos[player1]->getVida() < 0)
	{
		cout << magos[player2]->getNombre() << " es el ganador." << endl;
	}
	if (magos[player2]->getVida() < 0)
	{
		cout << magos[player1]->getNombre() << " es el ganador." << endl;
	}
	srand(time(NULL));
}