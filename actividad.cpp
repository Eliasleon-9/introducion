#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct { int hora, minuto, segundo; } tiempo;

//funcion para imprimir
void imprimirTiempo(tiempo vt[], int tamanio) {
    for(int i = 0; i < tamanio; i++) {
        cout << "hora " << i << ": " << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
    }
}

//funcion para generar horas randomicas
int horaRand() {
	return rand()%24;
} 


//funcion para generar minutos y segundos randomicas
int msRand() {
    return rand()%60;
}
void agregar(tiempo vt[], int tamanio){
	for (int i=0;i<tamanio;i++){
		vt[i].hora=horaRand();
		vt[i].minuto=msRand();
		vt[i].segundo=msRand();
	}
}

int main() {
    const int TMA = 5;
    tiempo vt[TMA];

	agregar(vt,TMA);
    imprimirTiempo(vt, TMA);
    return 0;
}
