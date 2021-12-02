#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

enum class Estado {ESTADO1, ESTADO2, ESTADO3, ESTADO4, NO_ACEPTADO, ACEPTADO};

Estado reconocerNumero(const string& inputString);

int main() {
    string inputString;

    cout << "Programa que reconoce si un string es un numero entero o real: ";
    cin >> inputString;

    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::ACEPTADO) {
        cout << "La cadena fue aceptada" << endl;
    }
    else if (ultimo == Estado::NO_ACEPTADO) {
        cout << "La cadena no fue aceptada" << endl;
    }

    cout << endl;
    system("pause");
    system("cls");

    return 0;
}

Estado reconocerNumero(const string& inputString)
{
    unsigned int pos = 0;
    Estado actual = Estado::ESTADO1;

    bool cadenaRechazada = false;

    while (!cadenaRechazada && pos <= inputString.length()) {

        switch (actual) {
        case Estado::ESTADO1:
            if (inputString[pos] == '0') {
                actual = Estado::ESTADO2;
            }
            break;
        case Estado::ESTADO2:
            if (inputString[pos] == '0') {
                actual = Estado::ESTADO3;
            }
            break;
        case Estado::ESTADO3:
            if (inputString[pos] == '1') {
                actual = Estado::ESTADO4;
            }
            break;
        case Estado::ESTADO4:
            actual = Estado::ACEPTADO;
            break;
        }
        pos++;
    }
    if (cadenaRechazada) {
        return Estado::NO_ACEPTADO;
    }
    return actual;
}