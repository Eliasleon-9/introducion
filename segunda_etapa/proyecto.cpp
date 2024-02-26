#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t TAMANO = 5;

// Definicion de la estructura Libro con arrays
struct SLibro {
    int nISBN;
    string sTitulo;
    string sAutor;
    int nPublicacion;
    string sGenero; //genero
    double dPrecio; //precio
    int nPaginas; //paginas
};

// Definicion de la estructura Usuario
struct SUsuario {
    int nUserID;
    string sNombre;
    string sApellido;
    string sEmail;
    int nCelular; // celular
};

// Definicion de la estructura Bibliotecario
struct SBibliotecario {
    int nEmployeeID;
    string sNombre;
    string sApellido;
    string sEmail;
    double dSalario; // salario
};

// Funcion para no repetir titulos de libros
bool tituloRepetido(const string& titulo, const SLibro* libros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (titulo == libros[i].sTitulo) {
            return true; // Si el titulo esta repetido
        }
    }
    return false; // Si el titulo no esta repetido
}
// Funcion para llenar la biblioteca con libros aleatorios
void llenarLibros(SLibro *libros, int cantidad) {
    string listaTitulo[] = {"El Aleph", "Cien anhos de soledad", "1984", "Don Quijote de la Mancha", "Harry Potter y la Piedra Filosofal", "La Odisea", "Las aventuras de Tom Sawyer", "El Principito", "Rebelion en la granja", "La Metamorfosis"};
    string listaAutor[] = {"Jorge Luis Borges", "Gabriel Garcia Marquez", "George Orwell", "Miguel de Cervantes", "J.K. Rowling", "Homero", "Mark Twain", "Antoine de Saint-Exupery", "George Orwell", "Franz Kafka"};
    string listaGenero[] = {"Ficcion", "Novela", "Ciencia Ficcion", "Clasico", "Fantasia", "Misterio", "Aventura", "Infantil", "Fabula", "Terror"};

    for (int i = 0; i < cantidad; i++) {
        string tituloAleatorio;
        do {
            int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
            tituloAleatorio = listaTitulo[indiceTitulo];
        } while (tituloRepetido(tituloAleatorio, libros, i)); // Verificar si el titulo esta repetido
        libros[i].nISBN = i + 1;
        libros[i].sTitulo = tituloAleatorio;
        int indiceAutor = rand() % 10;
        int indiceGenero = rand() % 10;
        libros[i].sAutor = listaAutor[indiceAutor];
        libros[i].nPublicacion = rand() % 25 + 1980; // Años entre 1980 y 2024
        libros[i].sGenero = listaGenero[indiceGenero]; // genero de libros
        libros[i].dPrecio = rand() % 300 + 50; // Precios entre 50 y 349
        libros[i].nPaginas = rand() % 500 + 100; // Paginas entre 100 y 599
    }
}

// Funcion para llenar los datos de usuario de manera aleatoria
void llenarUsuarios(SUsuario *usuarios, int cantidad) {
    string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
    string listaApellidos[] = {"Perez", "Gomez", "Rodriguez", "Martinez", "Lopez", "Gonzalez", "Sanchez", "Fernandez", "Garcia", "Torres"};
    for (int i = 0; i < TAMANO; i++) {
        usuarios[i].nUserID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        usuarios[i].sNombre = listaNombres[indiceNombre];
        usuarios[i].sApellido = listaApellidos[indiceApellido];
        usuarios[i].sEmail = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        usuarios[i].nCelular = (rand() % 2 + 6) * 10000000 + rand() % 10000000; //numero de celular
    }
}

// Funcion para llenar los datos de bibliotecario de manera aleatoria
void llenarBibliotecarios(SBibliotecario *bibliotecarios, int cantidad) {
    string listaNombres[] = {"Santiago", "Belen", "Luz", "Isabel", "Fabian", "Carla", "Sergio", "Gustavo", "Mario", "Melanie"};
    string listaApellidos[] = {"Leon", "Roca", "Justiniano", "Soliz", "Rivero", "Torrico", "Cuellar", "Tantani", "Rivas", "Roque"};
    for (int i = 0; i < TAMANO; i++) {
        bibliotecarios[i].nEmployeeID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        bibliotecarios[i].sNombre = listaNombres[indiceNombre];
        bibliotecarios[i].sApellido = listaApellidos[indiceApellido];
        bibliotecarios[i].sEmail = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        bibliotecarios[i].dSalario = rand() % 1501 + 1500 ; // salario entre 1500 y 3000
    }
}

// Funcion para mostrar los libros
void mostrarLibros(SLibro *libros, int inicio, int fin) {
    if (inicio < fin) {
        cout << "ISBN:" << libros[inicio].nISBN << ".   Titulo:" << libros[inicio].sTitulo << ".   Autor:" << libros[inicio].sAutor << ".   anho:" << libros[inicio].nPublicacion << ".   Genero:" << libros[inicio].sGenero << ".   Precio:Bs" << libros[inicio].dPrecio << ".   Paginas:" << libros[inicio].nPaginas << endl;
        mostrarLibros(libros, inicio + 1, fin);
    }
}

// Funcion para mostrar los datos de los usuarios
void mostrarUsuarios(SUsuario *usuarios, int inicio, int fin) {
    if (inicio < fin) {
        cout << "User ID: " << usuarios[inicio].nUserID << ".   Nombre: " << usuarios[inicio].sNombre << ".   Apellido: " << usuarios[inicio].sApellido << ".   Email: " << usuarios[inicio].sEmail << ".   Celular: " << usuarios[inicio].nCelular << endl;
        mostrarUsuarios(usuarios, inicio + 1, fin);
    }
}

// Funcion para mostrar los datos de los bibliotecarios
void mostrarBibliotecarios(SBibliotecario *bibliotecarios, int inicio, int fin) {
    if (inicio < fin) {
        cout << "Employee ID: " << bibliotecarios[inicio].nEmployeeID << ".   Nombre: " << bibliotecarios[inicio].sNombre << ".   Apellido: " << bibliotecarios[inicio].sApellido << ".   Email: " << bibliotecarios[inicio].sEmail << ".   Salario: Bs" << bibliotecarios[inicio].dSalario << endl;
        mostrarBibliotecarios(bibliotecarios, inicio + 1, fin);
    }
}

// Función recursiva para buscar libros por título
void buscarLibro(SLibro *libros, int inicio, int fin, const string& sTitulo) {
    if (inicio < fin) {
        if (libros[inicio].sTitulo == sTitulo) {
            cout << "ISBN:" << libros[inicio].nISBN << ".   Titulo:" << libros[inicio].sTitulo << ".   Autor:" << libros[inicio].sAutor << ".   anho:" << libros[inicio].nPublicacion << ".   Genero:" << libros[inicio].sGenero << ".   Precio:Bs" << libros[inicio].dPrecio << ".   Paginas:" << libros[inicio].nPaginas << endl;
        }
        buscarLibro(libros, inicio + 1, fin, sTitulo);
    }
}

// Funcion recursiva para buscar usuarios por nombre, apellido o nombre completo
void buscarUsuario(SUsuario *usuarios, int inicio, int fin, const string& busqueda) {
    if (inicio < fin) {
        // Comprobar si el nombre, apellido o nombre completo coincide con la búsqueda
        if (usuarios[inicio].sNombre == busqueda || usuarios[inicio].sApellido == busqueda || (usuarios[inicio].sNombre + " " + usuarios[inicio].sApellido) == busqueda) {
            cout << "User ID: " << usuarios[inicio].nUserID << ".   Nombre: " << usuarios[inicio].sNombre << ".   Apellido: " << usuarios[inicio].sApellido << ".   Email: " << usuarios[inicio].sEmail << ".   Celular: " << usuarios[inicio].nCelular << endl;
        }
        buscarUsuario(usuarios, inicio + 1, fin, busqueda); // Llamada recursiva con el siguiente usuario
    }
}

// Funcion recursiva para buscar bibliotecarios por nombre, apellido o nombre completo
void buscarBibliotecario(SBibliotecario *bibliotecarios, int inicio, int fin, const string& busqueda) {
    if (inicio < fin) {
        if(bibliotecarios[inicio].sNombre == busqueda || bibliotecarios[inicio].sApellido == busqueda ||(bibliotecarios[inicio].sNombre + " " + bibliotecarios[inicio].sApellido) == busqueda) {
            cout << "Employee ID: " << bibliotecarios[inicio].nEmployeeID << ".   Nombre: " << bibliotecarios[inicio].sNombre <<".   Apellido: " <<bibliotecarios[inicio].sApellido << ".   Email: " << bibliotecarios[inicio].sEmail << ".   Salario: " << bibliotecarios[inicio].dSalario << endl;
        }
        buscarBibliotecario(bibliotecarios, inicio + 1, fin, busqueda);
    }
}

// Menú para mostrar los listados
void menuListados(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) { 
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
                mostrarLibros(libros, 0, TAMANO);
                break;
            case 2:
                mostrarUsuarios(usuarios, 0, TAMANO);
                break;
            case 3:
                mostrarBibliotecarios(bibliotecarios, 0, TAMANO);
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionListados != 0);
}

// Menú para realizar búsquedas
void menuBusqueda(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) {
    int opcionBusqueda;
    do {
        cout << "\nSubmenu de Busqueda:" << endl;
        cout << "1. Busqueda de Libro" << endl;
        cout << "2. Busqueda de Usuario" << endl;
        cout << "3. Busqueda de Bibliotecario" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionBusqueda;

        switch (opcionBusqueda) {
            case 1:
                {
                string sBusqueda;
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                getline(cin, sBusqueda);
                cout << "\nResultados de la busqueda:" << endl;
                buscarLibro(libros, 0, TAMANO, sBusqueda);
                }
                break;
            case 2:
                {
                string sBusqueda;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore();
                getline(cin, sBusqueda);
                cout << "\nResultados de la busqueda:" << endl;
                buscarUsuario(usuarios, 0, TAMANO, sBusqueda);
                }
                break;
            case 3:
                {
                string sBusqueda;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore();
                getline(cin, sBusqueda);
                cout << "\nResultados de la busqueda:" << endl;
                buscarBibliotecario(bibliotecarios, 0, TAMANO, sBusqueda);
                }
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcionBusqueda != 0);
}

// Menú principal
void menuPrincipal(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) {
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
                llenarLibros(libros, TAMANO);
                llenarUsuarios(usuarios, TAMANO);
                llenarBibliotecarios(bibliotecarios, TAMANO);
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
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 0);
}

int main() {
    srand(time(nullptr));
    SLibro libros[TAMANO]; // array de libros
    SUsuario usuarios[TAMANO]; // array de usuarios
    SBibliotecario bibliotecarios[TAMANO]; //array de bibliotecarios

    menuPrincipal(libros, usuarios, bibliotecarios);
    return 0;
}
