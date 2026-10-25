#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string contrasena;

    bool mayuscula = false;
    bool minuscula = false;
    bool digito = false;
    bool simbolo = false;

    cout << "Ingrese la contrasena: ";
    getline(cin, contrasena);

    for (int i = 0; i < contrasena.length(); i++) {
        char c = contrasena[i];

        if (isupper(c)) {
            mayuscula = true;
        }
        else if (islower(c)) {
            minuscula = true;
        }
        else if (isdigit(c)) {
            digito = true;
        }
        else if (!isspace(c)) {
            simbolo = true;
        }
    }

    bool longitud = contrasena.length() >= 8;
    bool valida = longitud && mayuscula && minuscula
                  && digito && simbolo;

    if (valida) {
        cout << "Contrasena valida." << endl;
    }
    else {
        if (!longitud) {
            cout << "- Debe tener al menos 8 caracteres." << endl;
        }

        if (!mayuscula) {
            cout << "- Falta al menos una letra mayuscula." << endl;
        }

        if (!minuscula) {
            cout << "- Falta al menos una letra minuscula." << endl;
        }

        if (!digito) {
            cout << "- Falta al menos un digito." << endl;
        }

        if (!simbolo) {
            cout << "- Falta al menos un simbolo." << endl;
        }

        cout << "Contrasena invalida." << endl;
    }

    return 0;
}
