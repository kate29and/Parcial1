#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


int main()
{
    int opc=0;
    int n=0;
    char ***Categ = nullptr;

    cout<<"Ingresar numero de materias: ";
    cin>>n;

    Categ = new char**[n+1]; // memoria para filas
    for (int i=0; i<n+1 ; i++){
        Categ[i] = new char*[5];//memoria para columnas
        for (int j = 0; j < 5; j++) {
            Categ[i][j] = new char[10]; // memoria para dato
        }
    }
    int s=0;

    char m[] = "Horas-Materias-Codigo-Horario-Creditos-";
    char* m_ptr = m;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0) {
                for (int k = 0; *m_ptr != '-'; k++) {
                    Categ[i][j][k] = *m_ptr; //apunta a m
                    m_ptr++;
                }
                m_ptr++; // avanzar el puntero para saltar el espacio
            }
            else {
                if (j == 0) {
                    cout << "Ingrese horas de la materia " << i << ": ";
                }
                else if (j == 1) {
                    cout << "Ingrese nombre de la materia " << i << ": ";
                }
                else if (j == 2) {
                    cout << "Ingrese codigo de la materia " << i << ": ";
                }
                else if (j == 3) {
                    cout << "Ingrese horas semanales de la materia " << i << ": ";
                }
                else if (j == 4) {
                    cout << "Ingrese creditos de la materia " << i << ": ";
                }
                cin >> Categ[i][j];
            }


        }
    }


   /* for (int i = 0; i < n+1; i++) {
        for (int j=0;j<5;j++){
            if (i == 0) {
                for (int k=0; m[s]!=' '; k++){
                    Categ[i][j][k]=m[s];
                    s++;
                }
            }
            else {
                Categ[i][j][0] = '*';
            }
        }
    }*/


    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < 5; j++) {

            cout << Categ[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < 5; j++) {
            delete[] Categ[i][j];
        }
        delete[] Categ[i];
    }
    delete[] Categ;
}
