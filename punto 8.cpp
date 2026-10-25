#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Ingrese N (>= 1): ";
    cin >> N;

    int mejorNumero = 1;
    int mejoresPasos = -1;
    long long mejorMaximo = 1;

    for (int i = 1; i <= N; i++) {
        long long x = i;
        int pasos = 0;
        long long maximo = x;

        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            }
            else {
                x = 3 * x + 1;
            }

            pasos++;

            if (x > maximo) {
                maximo = x;
            }
        }

        if (pasos > mejoresPasos) {
            mejoresPasos = pasos;
            mejorNumero = i;
            mejorMaximo = maximo;
        }
    }

    cout << "Numero con la secuencia mas larga: "
         << mejorNumero << endl;
    cout << "Pasos: " << mejoresPasos << endl;
    cout << "Valor maximo alcanzado: "
         << mejorMaximo << endl;

    return 0;
}