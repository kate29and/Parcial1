#include <iostream>

using namespace std;

void imprimir(char*** horario);
void llenar(char*** horario);

int main() {
    int n = 2, dia = 0, hora = 0;
    char eleccion = ' ';
    char ***horario = nullptr;
    horario = new char**[7];
    for (int i = 0; i < 7; i++) {
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
    horario[1][0]= "1.6-8     " ;
    horario[2][0]= "2.8-10    " ;
    horario[3][0]= "3.10-12   " ;
    horario[4][0]= "4.12-14   " ;
    horario[5][0]= "5.14-16   " ;
    horario[6][0]= "6.16-18   " ;
    imprimir(horario);
    do {
        cout << "-----------------CRONOGRAMA--------------------" << endl;
        cout << "Ingrese que dia desea registrar: " << endl;
        cout << "1-Lunes" << endl;
        cout << "2-Martes" << endl;
        cout << "3-Miercole" << endl;
        cout << "4-Jueves" << endl;
        cout << "5-Viernes" << endl;
        cin >> dia;

        cout << "Ingrese el horario donde registrara la materia: " << endl;
        cout << "1-> 6-8" << endl;
        cout << "2-> 8-10" << endl;
        cout << "3-> 10-12" << endl;
        cout << "4-> 12-14" << endl;
        cout << "5-> 14-16" << endl;
        cout << "6-> 16-18" << endl;
        cin >> hora;

        if (horario[dia][hora][0] == '*') {
            cout << "Ingresa el codigo de la materia: ";
            cin >> horario[dia][hora];
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

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }
    delete[] horario;
}

void llenar(char*** horario) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 10; k++) {
                horario[i][j][k] = '*';
            }
        }
    }
}

void imprimir(char*** horario) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            cout << " | ";
            for (int k = 0; k < 10; k++) {

                cout << horario[i][j][k] << " ";
            }
        }
        cout << " | "<<endl;
    }
}
