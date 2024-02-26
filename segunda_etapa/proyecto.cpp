#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t TAMANO = 10;

// Definicion de la estructura Libro con arrays
struct Libro {
    int ISBN;
    string titulo;
    string autor;
    int publicacion;
    string genero; //genero
    double precio; //precio
    int paginas; //paginas
};
// Definicion de la estructura Usuario
struct Usuario {
    int userID;
    string nombre;
    string apellido;
    string email;
    int celular; // celular
};
//Definicion de la estructura Bibliotecario
struct Bibliotecario {
    int employeeID;
    string nombre;
    string apellido;
    string email;
    double salario; // salario
};
// Funcion para llenar la biblioteca con libros aleatorios
void llenar(Libro *libros, int cantidad) {
    string listaTitulo[] = {"El Aleph", "Cien anhos de soledad", "1984", "Don Quijote de la Mancha", "Harry Potter y la Piedra Filosofal", "La Odisea", "Las aventuras de Tom Sawyer", "El Principito", "Rebelion en la granja", "La Metamorfosis"};
    string listaAutor[] = {"Jorge Luis Borges", "Gabriel Garcia Marquez", "George Orwell", "Miguel de Cervantes", "J.K. Rowling", "Homero", "Mark Twain", "Antoine de Saint-Exupery", "George Orwell", "Franz Kafka"};
    string listaGenero[] = {"Ficcion", "Novela", "Ciencia Ficcion", "Clasico", "Fantasia", "Misterio", "Aventura", "Infantil", "Fabula", "Terror"};

    for (int i = 0; i < cantidad; i++) {
        libros[i].ISBN = i + 1;
        int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceAutor = rand() % 10;
        int indiceGenero = rand() % 10;
        libros[i].titulo = listaTitulo[indiceTitulo];
        libros[i].autor = listaAutor[indiceAutor];
        libros[i].publicacion = rand() % 25 + 1980; // Años entre 1980 y 2024
        libros[i].genero = listaGenero[indiceGenero]; // genero de libros
        libros[i].precio = rand() % 300 + 50; // Precios entre 50 y 349
        libros[i].paginas = rand() % 500 + 100; // Paginas entre 100 y 599
    }
}

// FunciOn para llenar los datos de usuario de manera aleatoria
void llenar(Usuario *usuarios, int cantidad) {
    string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
    string listaApellidos[] = {"Perez", "Gomez", "Rodriguez", "Martinez", "Lopez", "Gonzalez", "Sanchez", "Fernandez", "Garcia", "Torres"};
    for (int i = 0; i < TAMANO; i++) {
        usuarios[i].userID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        usuarios[i].nombre = listaNombres[indiceNombre];
        usuarios[i].apellido = listaApellidos[indiceApellido];
        usuarios[i].email = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        usuarios[i].celular = (rand() % 2 + 6) * 10000000 + rand() % 10000000; //numero de celular
    }
}
//Funcion para llenar los datos de bibliotecario de manera aleatoria
void llenar(Bibliotecario *bibliotecarios, int cantidad) {
    string listaNombres[] = {"Santiago", "Belen", "Luz", "Isabel", "Fabian", "Carla", "Sergio", "Gustavo", "Mario", "Melanie"};
    string listaApellidos[] = {"Leon", "Roca", "Justiniano", "Soliz", "Rivero", "Torrico", "Cuellar", "Tantani", "Rivas", "Roque"};
    for (int i = 0; i < TAMANO; i++) {
        bibliotecarios[i].employeeID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        bibliotecarios[i].nombre = listaNombres[indiceNombre];
        bibliotecarios[i].apellido = listaApellidos[indiceApellido];
        bibliotecarios[i].email = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        bibliotecarios[i].salario = rand() % 1501 + 1500 ; // salario entre 1500 y 3000
    }
}
// Funcion para mostrar los libros
void mostrar(Libro *libros, int inicio, int fin) {
    if (inicio < fin) {
        cout << "ISBN:" << libros[inicio].ISBN << ".   Titulo:" << libros[inicio].titulo << ".   Autor:" << libros[inicio].autor << ".   anho:" << libros[inicio].publicacion << ".   Genero:" << libros[inicio].genero << ".   Precio:Bs" << libros[inicio].precio << ".   Paginas:" << libros[inicio].paginas << endl;
        mostrar(libros, inicio + 1, fin);
    }
}

// Funcion para mostrar los datos de los usuarios
void mostrar(Usuario *usuarios, int inicio, int fin) {
    if (inicio < fin) {
        cout << "User ID: " << usuarios[inicio].userID << ".   Nombre: " << usuarios[inicio].nombre << ".   Apellido: " << usuarios[inicio].apellido << ".   Email: " << usuarios[inicio].email << ".   Celular: " << usuarios[inicio].celular << endl;
        mostrar(usuarios, inicio + 1, fin);
    }
}
//Funcion para mostrar los datos de los bibliotecarios
void mostrar(Bibliotecario *bibliotecarios, int inicio, int fin) {
    if (inicio < fin) {
        cout << "Employee ID: " << bibliotecarios[inicio].employeeID << ".   Nombre: " << bibliotecarios[inicio].nombre << ".   Apellido: " << bibliotecarios[inicio].apellido << ".   Email: " << bibliotecarios[inicio].email << ".   Salario: Bs" << bibliotecarios[inicio].salario << endl;
        mostrar(bibliotecarios, inicio + 1, fin);
    }
}
void menuListados(Libro *libros, Usuario *usuarios, Bibliotecario *bibliotecarios) { 
    int opcionListados;
    do {
        cout << "\nSubmenu de Listados:" << endl;
        cout << "1. Listado de Libros" << endl;
        cout << "2. Listado de Usuarios" << endl;
        cout << "3. Listado de Bibliotecarios" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionListados;

        switch (opcionListados) {
            case 1:
                mostrar(libros, 0, TAMANO);
                break;
            case 2:
                mostrar(usuarios, 0, TAMANO);
                break;
            case 3:
                mostrar(bibliotecarios, 0, TAMANO);
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionListados != 0);
}
void menuBusqueda(Libro *libros, Usuario *usuarios, Bibliotecario *bibliotecarios) {
    int opcionBusqueda;
    do {
        cout << "\nSubmenu de Busqueda:" << endl;
        cout << "1. Busqueda de Libro" << endl;
        cout << "2. Busqueda de Usuario" << endl;
        cout << "3. Busqueda de Bibliotecario" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionBusqueda;

    } while (opcionBusqueda != 0);
}
void menuPrincipal(Libro *libros, Usuario *usuarios, Bibliotecario *bibliotecarios) {
    int opcionPrincipal;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Llenar Datos" << endl;
        cout << "2. Listados" << endl;
        cout << "3. Busqueda" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1:
                llenar(libros, TAMANO);
                llenar(usuarios, TAMANO);
                llenar(bibliotecarios, TAMANO);
                cout << "Datos llenados exitosamente." << endl;
                break;
            case 2:
                menuListados(libros, usuarios, bibliotecarios);
                break;
            case 3:
                menuBusqueda(libros, usuarios, bibliotecarios);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcin invalida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 0);
}

int main() {
    srand(time(nullptr));
    Libro libros[TAMANO]; // array de libros
    Usuario usuarios[TAMANO]; // array de usuarios
    Bibliotecario bibliotecarios[TAMANO]; //array de bibliotecarios

    menuPrincipal(libros, usuarios, bibliotecarios);
    return 0;
}
