#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int const TAMJ = 3;
int const MJUEGO = 5;
int const MDEVS = 5;
int const MAX_PERSONAS = 5;

struct vjuego{
    string nombre;  // nombre del juego
    int ranking; //numero randomico del 1 al 10
    bool tipo;  //de tipo offline y online
    string dev; //desarrollador del juego
};

struct persona{
    string nombre;
    int id_persona;
    vjuego juegos[TAMJ]; // Lista de juegos de la persona
};

string nombres[]={"Juan Perez", "Maria Flor", "Pedro Vaca", "Juan Peralta", "Santiago Roca"};
string vjuegos[]={"WoW", "Age of Empire", "Dota", "Tetris", "Mario Bros"};
string desa[]={"Nintendo", "Rockstar Games", "Ubisoft", "Electronic Arts", "Blizzard Entertainment" };

// Funcion para generar un numero aleatorio
int Randomico(int max) {
    return rand() % max ;
}

//funcion para no repetir nombres de personas
bool repetido(string n, persona *p, int cant) {
	for (int i = 0; i < cant; i++) {
		if (n.compare(p[i].nombre) == 0) {
			return true;
		}
	}
	return false;
}

// Funcion para llenar la informacion de un juego
void llenar(vjuego &j, int cant) {
    j.nombre = vjuegos[Randomico(MJUEGO)];
    j.ranking = Randomico(10) + 1; // Generar ranking aleatorio entre 1 y 10
    j.tipo = Randomico(2) == 1 ? true : false;
    j.dev = desa[Randomico(MDEVS)];
}

// Funcion para llenar la informacion de una persona
void llenar(persona *p, int cant) {
	string n;
	for (int i = 0; i < cant; i++) {
		do {
			n = nombres[Randomico(MAX_PERSONAS)];
		} while (repetido(n, p, i));
		p[i].nombre = n;
		p[i].id_persona = i + 1;
		for (int j = 0; j < TAMJ; j++) {
			llenar(p[i].juegos[j], MJUEGO);
		}
	}
}

// Funcion para imprimir la informacion de una persona
void imprimir(persona p, int cant) {
    cout << "Nombre: " << p.nombre << endl;
    for (int i = 0; i < TAMJ; i++) {
        cout << "Juego " << i + 1 << ": " << p.juegos[i].nombre << endl;
        cout << "  Desarrollador: " << p.juegos[i].dev << endl;
        cout << "  Tipo: " << (p.juegos[i].tipo ? "Online" : "Offline") << endl;
        cout << "  Ranking: " << p.juegos[i].ranking << endl;
    }
    cout << endl;
}

// Funcion para imprimir la informacion de un juego
void imprimirJ(vjuego j, int cant) {
    cout << j.nombre << endl;
    cout << j.dev << endl;
    cout << (j.tipo ? "Online" : "Offline") << endl;
    cout << j.ranking << endl;
    cout << endl;
}

// Funcion para calcular y mostrar la valoracion de juego por persona
void valoracion(persona p, int cant) {
	int maxRanking = 0;
	string juegoMaxRanking;
	for (int i = 0; i < TAMJ; i++) {
		if (p.juegos[i].ranking > maxRanking) {
			maxRanking = p.juegos[i].ranking;
			juegoMaxRanking = p.juegos[i].nombre;
		}
	}
	cout << p.nombre << endl;
	cout << juegoMaxRanking << " " << maxRanking << endl;
	cout << endl;
}

// Implementacion del menu principal
void menu() {
    int opcion;
    persona personas[MAX_PERSONAS];
    do {
        cout << "Menu:\n";
        cout << "1. Llenado de personas\n";
        cout << "2. Impresion de personas\n";
        cout << "3. Ranking de juego por persona\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // Llenado de personas
				llenar(personas, MAX_PERSONAS);
				cout << "Personas llenadas.\n";
				break;
            case 2:
                // Impresion de personas
				for (int i = 0; i < MAX_PERSONAS; i++) {
					imprimir(personas[i], TAMJ);
				}
				break;
            case 3:
                // Ranking de juego por persona
				for (int i = 0; i < MAX_PERSONAS; i++) {
					valoracion(personas[i], TAMJ);
				}
				break;
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Por favor seleccione nuevamente.\n";
        }
    } while (opcion != 0);
}

// Funcion principal
int main(){
    srand(time(0)); 
    menu(); 
    return 0;
}
