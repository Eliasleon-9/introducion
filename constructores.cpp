#include <iostream>
#include <string>

using namespace std;

class Usuario {
private:
    int id;
    string nombre;
    string apellido;
    string email;
    string celular;

public:
    // Constructor
    Usuario(int _id, const string& _nombre, const string& _apellido, const string& _email, const string& _celular)
        : id(_id), nombre(_nombre), apellido(_apellido), email(_email), celular(_celular) {
    }

    int get_Id() const {
        return id;
    }

    string get_Nombre() const {
        return nombre;
    }

    string get_Apellido() const {
        return apellido;
    }

    string get_Email() const {
        return email;
    }

    string get_Celular() const {
        return celular;
    }

    // Setters
    void set_Id(int _id) {
        id = _id;
    }

    void set_Nombre(const string& _nombre) {
        nombre = _nombre;
    }

    void set_Apellido(const string& _apellido) {
        apellido = _apellido;
    }

    void set_Email(const string& _email) {
        email = _email;
    }

    void set_Celular(const string& _celular) {
        celular = _celular;
    }
};

int main() {
    // Crear un objeto de la clase Usuario
    Usuario usuario1(1, "John", "Doe", "john.doe@gmail.com", "123-456-7890");

    // Acceder a los atributos
    cout << "ID: " << usuario1.get_Id() << endl;
    cout << "Nombre: " << usuario1.get_Nombre() << endl;
    cout << "Apellido: " << usuario1.get_Apellido() << endl;
    cout << "Email: " << usuario1.get_Email() << endl;
    cout << "Celular: " << usuario1.get_Celular() << endl;

    // Modificar algunos atributos
    usuario1.set_Nombre("Jane");
    usuario1.set_Email("jane.doe@gmail.com");

    // Imprimir los cambios
    cout << "\nDespues de la modificacion:" << endl;
    cout << "Nombre: " << usuario1.get_Nombre() << endl;
    cout << "Email: " << usuario1.get_Email() <<endl;

    return 0;
}
