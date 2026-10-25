#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Numero de filas (1 a 15): ";
    cin >> n;

    if (n < 1 || n > 15) {
        cout << "Numero de filas invalido." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // Centrar la fila
        cout << string((n - i - 1) * 2, ' ');

        long long coeficiente = 1;

        for (int k = 0; k <= i; k++) {
            cout << setw(4) << coeficiente;

            coeficiente = coeficiente * (i - k) / (k + 1);
        }

        cout << endl;
    }

    return 0;
}