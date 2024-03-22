#include "Mago.h"
#include "CampamentoMagos.h"
#include <locale>
void ejercicio_1() {
	CampamentoMagos* administrador = new CampamentoMagos();
	bool ejer1 = true;
	string nombre = "";
	string tipoMago = "";
	int eliminarMago = 0;
	int poder = 0;
	int velocidad = 0;
	int resistencia = 0;
	int ataque = 0;
	int option = 0;
	while (ejer1) {
		cout << "1. Agregar Mago" << endl;
		cout << "2. Eliminar Mago" << endl;
		cout << "3. Listar Magos" << endl;
		cout << "4. Guardar Magos" << endl;
		cout << "5. Cargar Magos" << endl;
		cout << "6. Simular Batalla" << endl;
		cout << "7. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cout << "Ingrese el nombre del mago: " << endl;
			cin >> nombre;
			cout << "Ingrese el tipo de mago(1. Fuego, 2. Electrico, 3. Hielo): " << endl;
			cin >> tipoMago;
			while (tipoMago != "Fuego" && tipoMago != "Electrico" && tipoMago != "Hielo") {
				cout << "Ingrese uno de los tipos que le pide: " << endl;
				cin >> tipoMago;
			}
			if (tipoMago == "Fuego")
			{
				cout << "Ingrese el poder(70-100): " << endl;
				cin >> poder;
				while (poder < 70 || poder > 100) {
					cout << "Ingrese un poder en el rango indicado: " << endl;
					cin >> poder;
				}
				cout << "Ingrese la velocidad(40-70): " << endl;
				cin >> velocidad;
				while (velocidad < 40 || velocidad > 70) {
					cout << "Ingrese una velocidad en el rango indicado: " << endl;
					cin >> velocidad;
				}
				cout << "Ingrese la resistencia(30-60): " << endl;
				cin >> resistencia;
				while (resistencia < 30 || resistencia >= 61) {
					cout << "Ingrese una resistencia en el rango indicado: " << endl;
					cin >> resistencia;
				}
				cout << "Ingrese el ataque(60-90): " << endl;
				cin >> ataque;
				while (ataque < 60 || ataque >= 91) {
					cout << "Ingrese un ataque en el rango indicado: " << endl;
					cin >> ataque;
				}

			}
			if (tipoMago == "Electrico")
			{
				cout << "Ingrese el poder (50-80): " << endl;
				cin >> poder;
				while (poder < 50 || poder >= 81) {
					cout << "Ingrese un poder en el rango indicado: " << endl;
					cin >> poder;
				}
				cout << "Ingrese la velocidad (60-100): " << endl;
				cin >> velocidad;
				while (velocidad < 60 || velocidad >= 101) {
					cout << "Ingrese una velocidad en el rango indicado: " << endl;
					cin >> velocidad;
				}
				cout << "Ingrese la resistencia(40-70): " << endl;
				cin >> resistencia;
				while (resistencia < 40 || resistencia >= 71) {
					cout << "Ingrese una resistencia en el rango indicado: " << endl;
					cin >> resistencia;
				}
				cout << "Ingrese el ataque(50-80): " << endl;
				cin >> ataque;
				while (ataque < 50 || ataque >= 81) {
					cout << "Ingrese un ataque en el rango indicado: " << endl;
					cin >> ataque;
				}
			}
			if (tipoMago == "Hielo")
			{
				cout << "Ingrese el poder(60-90): " << endl;
				cin >> poder;
				while (poder < 60 || poder >= 91) {
					cout << "Ingrese un poder en el rango indicado: " << endl;
					cin >> poder;
				}
				cout << "Ingrese la velocidad(30-60): " << endl;
				cin >> velocidad;
				while (velocidad < 30 || velocidad >= 61) {
					cout << "Ingrese una velocidad en el rango indicado: " << endl;
					cin >> velocidad;
				}
				cout << "Ingrese la resistencia(50-80): " << endl;
				cin >> resistencia;
				while (resistencia < 50 || resistencia >= 81) {
					cout << "Ingrese una resistencia en el rango indicado: " << endl;
					cin >> resistencia;
				}
				cout << "Ingrese el ataque(40-70): " << endl;
				cin >> ataque;
				while (ataque < 40 || ataque >= 71) {
					cout << "Ingrese un ataque en el rango indicado: " << endl;
					cin >> ataque;
				}

			}
			administrador->AgregarMago(new Mago(nombre, tipoMago, poder, velocidad, resistencia, ataque));
			cout << "Mago agregado exitosamente." << endl;
			break;
		case 2:
			if (administrador->getMagos().empty())
			{
				cout << "No hay magos, agregue o cargue el archivo binario para que allan magos." << endl;
			}
			else {
				administrador->ListarMagos();
				cout << "Ingrese el indice del mago que desea eliminar: " << endl;
				cin >> eliminarMago;
				while (eliminarMago > administrador->getMagos().size() || eliminarMago < 0) {
					cout << "Ingrese un indice valido: " << endl;
					cin >> eliminarMago;
				}
				administrador->EliminarMago(eliminarMago - 1);
				cout << "Mago eliminado exitosamente" << endl;
			}
			break;
		case 3:
			if (administrador->getMagos().empty())
			{
				cout << "No hay magos, agregue o cargue el archivo binario para que allan magos." << endl;
			}
			else {
				administrador->ListarMagos();
			}
			break;
		case 4:
			if (administrador->getMagos().empty())
			{
				cout << "No hay magos, agregue o cargue el archivo binario para que allan magos." << endl;
			}
			else {
				administrador->GuardarMagos();
				cout << "Magos guardados exitosamente." << endl;
			}
			break;
		case 5:
			administrador->CargarMagos();
			cout << "Magos cargados exitosamente" << endl;
			break;
		case 6:
			break;
		case 7:
			ejer1 = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() {
	bool menu = true;
	int optionMenu = 0;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Free Royale" << endl;
		cout << "2. Salir" << endl;
		cin >> optionMenu;
		switch (optionMenu) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	menu();
}
