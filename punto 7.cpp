#include <iostream>
#include <string>
using namespace std;

int main() {
    char opcion;
    int k;
    string mensaje;

    cout << "Cifrar (C) o descifrar (D): ";
    cin >> opcion;

    cout << "Desplazamiento: ";
    cin >> k;

    cin.ignore();

    cout << "Mensaje: ";
    getline(cin, mensaje);

    // Si queremos descifrar, invertimos el desplazamiento
    if (opcion == 'D' || opcion == 'd') {
        k = -k;
    }

    // Normalizar el desplazamiento entre 0 y 25
    k = ((k % 26) + 26) % 26;

    // Recorrer el mensaje
    for (int i = 0; i < mensaje.length(); i++) {
        char c = mensaje[i];

        if (c >= 'A' && c <= 'Z') {
            mensaje[i] = (c - 'A' + k) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            mensaje[i] = (c - 'a' + k) % 26 + 'a';
        }
    }

    cout << "Resultado: " << mensaje << endl;

    return 0;
}