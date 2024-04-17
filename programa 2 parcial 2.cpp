#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    double salario;

public:
    Empleado() {}

    Empleado(string nombre, string apellido, int edad, double salario) : nombre(nombre), apellido(apellido), edad(edad), salario(salario) {}

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setApellido(string apellido) {
        this->apellido = apellido;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setSalario(double salario) {
        this->salario = salario;
    }

    string getNombre() const {
        return nombre;
    }

    string getApellido() const {
        return apellido;
    }

    int getEdad() const {
        return edad;
    }

    double getSalario() const {
        return salario;
    }

    friend ostream& operator<<(ostream& os, const Empleado& empleado) {
        os << empleado.nombre << " " << empleado.apellido << " " << empleado.edad << " " << empleado.salario;
        return os;
    }
};

int main() {
    vector<Empleado> empleados;
    string nombre, apellido;
    int edad;
    double salario;
    char respuesta;

    ofstream archivo("empleados.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    do {
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cout << "Ingrese apellido: ";
        cin >> apellido;
        cout << "Ingrese edad: ";
        cin >> edad;
        cout << "Ingrese salario: ";
        cin >> salario;

        Empleado nuevoEmpleado(nombre, apellido, edad, salario);
        empleados.push_back(nuevoEmpleado);

        archivo << nuevoEmpleado << endl;

        cout << "¿Desea ingresar otro empleado? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');

    archivo.close();

    cout << "Datos almacenados en empleados.txt" << endl;

    return 0;
}
