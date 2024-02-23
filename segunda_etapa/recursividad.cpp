#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

void imprimir(int *n, int cant){
    for (int i = 0; i < cant; i++)
        cout << i << "=" << n[i] << endl;
}

void imprec(int *n, int cant){
    if(cant > 0){
        imprec(n, cant-1);
        cout << cant-1 << "=" << n[cant-1] << endl;
    }
}

bool busqueda(int *n, int cant, int valor){
    if (cant <= 0) {
        return false;
    }
    if (n[cant-1] == valor) {
        return true;
    }
    return busqueda(n, cant-1, valor);
}

void mayor(int *n, int cant, int &m){
    if(cant > 0){
        if(n[cant-1]>m){
            m=n[cant-1];
        } 
        mayor(n,cant-1,m);
    }
}

void randomico(int *n, int cant){
    srand(time(0));
    for(int i = 0; i < cant; i++){
        n[i] = rand() % 30;
    }
}

void menu(int *numeros, int TAM){
    int opcion;
    int valor;
    int m = 0;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Llenar numeros" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3. Busqueda" << endl;
        cout << "4. Mayor" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                randomico(numeros, TAM);
                break;
            case 2:
                cout << "Impresion de numeros:" << endl;
                imprimir(numeros, TAM);
                break;
            case 3:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                cout << valor << (busqueda(numeros, TAM, valor) ? " se encuentra" : " no se encuentra") << " en el arreglo." << endl;
                break;
            case 4:
                mayor(numeros, TAM, m);
                cout << "El mayor es: " << m << endl;
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Seleccione una opcion valida." << endl;
        }
    } while (opcion != 5);
}

int main(){
    const int TAM = 7;
    int numeros[TAM];

    menu(numeros, TAM);

    return 0;
}
