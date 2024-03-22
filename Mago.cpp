#include "Mago.h"

Mago::Mago()
{
}

Mago::Mago(string Nombre, string tipo, int poder, int velocidad, int resistencia, int ataque)
{
	this->Nombre = Nombre;
	this->tipoDeMago = tipo;
	this->poder = poder;
	this->velocidad = velocidad;
	this->resistencia = resistencia;
	this->ataque = ataque;
	this->vida = 100;
}

Mago::~Mago()
{
	this->Nombre = "";
	this->tipoDeMago = "";
	this->poder = 0;
	this->velocidad = 0;
	this->resistencia = 0;
	this->ataque = 0;
	this->vida = 0;
}

string Mago::getNombre()
{
	return this->Nombre;
}

void Mago::setNombre(string nombre)
{
	this->Nombre = nombre;
}

string Mago::getTipo()
{
	return this->tipoDeMago;
}

void Mago::setTipo(string tipoMago)
{
	this->tipoDeMago = tipoMago;
}

int Mago::getPoder()
{
	return this->poder;
}

void Mago::setPoder(int poder)
{
	this->poder = poder;
}

int Mago::getVelocidad()
{
	return this->velocidad;
}

void Mago::setVelocidad(int velocidad)
{
	this->velocidad = velocidad;
}

int Mago::getResistencia()
{
	return this->resistencia;
}

void Mago::setResistencia(int resistencia)
{
	this->resistencia = resistencia;
}

int Mago::getAtaque()
{
	return this->ataque;
}

void Mago::setAtaque(int ataque)
{
	this->ataque = ataque;
}

int Mago::getVida()
{
	return this->vida;
}

void Mago::setVida(int vida)
{
	this->vida = vida;
}

void Mago::to_String()
{
	cout << "Nombre: " << this->Nombre << endl;
	cout << "Tipo de Mago: " << this->tipoDeMago << endl;
	cout << "Poder: " << this->poder << endl;
	cout << "Velocidad: " << this->velocidad << endl;
	cout << "Resistencia: " << this->resistencia << endl;
	cout << "Ataque: " << this->ataque << endl;
	cout << "Vida: " << this->vida << endl;
	cout << endl;
}
