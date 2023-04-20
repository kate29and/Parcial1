#include <iostream>

using namespace std;

void imprimir(char*** horario);
void llenar(char*** horario);

int main() {
    int n = 2, dia = 0, hora = 0;
    char eleccion = ' ';
    char ***horario = nullptr;
    horario = new char**[14];
    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }
    llenar(horario);

    horario[0][0]= "Hora      ";
    horario[0][1]= "1.Lunes   ";
    horario[0][2]= "2.Martes  ";
    horario[0][3]= "3.Miercole";
    horario[0][4]= "4.Jueves  " ;
    horario[0][5]= "5.Viernes " ;

    horario[1][0]= "6         " ;
    horario[2][0]= "7         " ;
    horario[3][0]= "8         " ;
    horario[4][0]= "9         " ;
    horario[5][0]= "10        " ;
    horario[6][0]= "11        " ;
    horario[7][0]= "12        " ;
    horario[8][0]= "13        " ;
    horario[9][0]= "14        " ;
    horario[10][0]="15        " ;
    horario[11][0]="16        " ;
    horario[12][0]="17        " ;
    horario[13][0]="18        " ;
    imprimir(horario);
    do {
        cout << endl;
        cout << "Ingrese que dia desea registrar: " << endl;
        cin >> dia;

        cout << endl;
        cout << "Ingrese el horario donde registrara la materia: " << endl;        
        cin >> hora;

        if (horario[hora][dia][0] == '*') {
            cout << "Ingresa el codigo de la materia: ";
            cin >> horario[hora][dia];
            cout << endl;

            imprimir(horario);
        }
        else {
            cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
        }

        cout << "\nEl usuario ha sido agregado. Presiona cualquier tecla para agregar otro usuario\no '*' para terminar: ";
        cin >> eleccion;
        cout << endl;
        n++;
    } while (eleccion != '*');

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }
    delete[] horario;
}

void llenar(char*** horario) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 10; k++) {
                horario[i][j][k] = '*';
            }
        }
    }
}

void imprimir(char*** horario) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            cout << " | ";
            for (int k = 0; k < 10; k++) {

                cout << horario[i][j][k];
            }
        }
        cout << " | "<<endl;
    }
}
