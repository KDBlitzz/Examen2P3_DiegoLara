#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Mago
{
private:
	string Nombre;
	string tipoDeMago;
	int poder;
	int velocidad;
	int resistencia;
	int ataque;
	int vida;
public:
	Mago();
	Mago(string Nombre, string tipo, int poder, int velocidad, int resistencia, int ataque);
	~Mago();
	string getNombre();
	void setNombre(string nombre);
	string getTipo();
	void setTipo(string tipoMago);
	int getPoder();
	void setPoder(int poder);
	int getVelocidad();
	void setVelocidad(int velocidad);
	int getResistencia();
	void setResistencia(int resistencia);
	int getAtaque();
	void setAtaque(int ataque);
	int getVida();
	void setVida(int vida);
	void to_String();
};

