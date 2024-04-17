#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Empleado {
public:
    string nombre;
    string apellido;
    int edad;
    double salario;

    Empleado(string nombre, string apellido, int edad, double salario) : nombre(nombre), apellido(apellido), edad(edad), salario(salario) {}
};

int main() {
    vector<Empleado> empleados;

    empleados.push_back(Empleado("Juan", "Perez", 30, 2000.0));
    empleados.push_back(Empleado("Maria", "Lopez", 25, 1800.0));
    empleados.push_back(Empleado("Pedro", "Gomez", 35, 2200.0));

    string nombreCompleto;
    bool salir = false;

    while (!salir) {
        cout << "Ingrese el nombre completo del empleado (o 'salir' para salir): ";
        getline(cin, nombreCompleto);

        if (nombreCompleto == "salir") {
            salir = true;
        } else {
            bool encontrado = false;
            for (const auto& empleado : empleados) {
                string nombreEmpleado = empleado.nombre + " " + empleado.apellido;
                if (nombreEmpleado == nombreCompleto) {
                    encontrado = true;
                    cout << "Nombre: " << empleado.nombre << endl;
                    cout << "Apellido: " << empleado.apellido << endl;
                    cout << "Edad: " << empleado.edad << endl;
                    cout << "Salario: $" << empleado.salario << endl;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Empleado no encontrado." << endl;
            }
        }
    }

    cout << "Programa finalizado." << endl;

    return 0;
}
