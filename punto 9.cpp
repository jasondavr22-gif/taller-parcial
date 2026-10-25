#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int opcion;
    string cadena;
    string resultado;

    cout << "1. Comprimir" << endl;
    cout << "2. Descomprimir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida." << endl;
        return 0;
    }

    cout << "Cadena: ";
    getline(cin, cadena);

    if (opcion == 1) {
        // COMPRIMIR
        for (int i = 0; i < cadena.length(); ) {
            char c = cadena[i];
            int contador = 0;

            while (i < cadena.length() && cadena[i] == c) {
                contador++;
                i++;
            }

            resultado += c;
            resultado += to_string(contador);
        }

        cout << "Comprimida: " << resultado << endl;
    }
    else {
        // DESCOMPRIMIR
        bool valido = true;
        int i = 0;

        while (i < cadena.length() && valido) {
            char c = cadena[i];

            if (isdigit((unsigned char)c)) {
                valido = false;
                break;
            }

            i++;
            if (i >= cadena.length() ||
                !isdigit((unsigned char)cadena[i])) {
                valido = false;
                break;
            }

            long long contador = 0;

            while (i < cadena.length() &&
                   isdigit((unsigned char)cadena[i])) {
                int digito = cadena[i] - '0';

                if (contador > (cadena.size() - 1) / 10) {
                    valido = false;
                    break;
                }

                contador = contador * 10 + digito;
                i++;
            }

            if (!valido || contador == 0) {
                valido = false;
                break;
            }

            if (contador > 1000000) {
                valido = false;
                break;
            }

            for (long long j = 0; j < contador; j++) {
                resultado += c;
            }
        }

        if (valido) {
            cout << "Descomprimida: " << resultado << endl;
        }
        else {
            cout << "Formato invalido." << endl;
        }
    }

    return 0;
}