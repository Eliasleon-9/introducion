#include <iostream>
using namespace std;

int contarVocales(char *pc) {
    int contadorVocales = 0;
    while (*pc != '\0') {
        if (*pc == 'a' || *pc == 'e' || *pc == 'i' || *pc == 'o' || *pc == 'u') {
            contadorVocales++;
        }
        pc++;
    }
    return contadorVocales;
}


int main() {
    char cadena[] = "hola mundo desde upds";
    char *pc = cadena;
    //realizar el conteo de las vocales de la cadena por medio de puntero. 
    //pasarlo a una funcion el parametro del puntero.

    int cantidadVocales = contarVocales(pc);

    cout << "La cantidad de vocales en la cadena es: " << cantidadVocales << endl;

    return 0;
}