#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    int n=0;
    char ***Categ = nullptr;
    char cc[15];
    cout<<"Ingresar documento de identidad: ";
    cin>>cc;
    cout<<"Ingresar numero de materias: ";
    cin>>n;

    Categ = new char**[n+1]; // memoria para filas
    for (int i=0; i<n+1 ; i++){
        Categ[i] = new char*[5];//memoria para columnas
        for (int j = 0; j < 5; j++) {
            Categ[i][j] = new char[10]; // memoria para dato
        }
    }
    ofstream outputFile(cc); // modo escritura

    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0) {

                if (j == 0) {
                    char p[]="Materias";
                    Categ[i][j]=p;
                }
                else if (j == 1) {
                     char p[]="Codigo";
                    Categ[i][j]=p;
                }
                else if (j == 2) {
                    char p[]="Horario";
                    Categ[i][j]=p;
                }
                else if (j == 3) {
                    char p[]="Creditos";
                    Categ[i][j]=p;
                }

            }
            else {

                if (j == 0) {
                    cout << "Ingrese nombre de la materia " << i << ": ";
                }
                else if (j == 1) {
                    cout << "Ingrese codigo de la materia " << i << ": ";
                }
                else if (j == 2) {
                    cout << "Ingrese horas semanales de la materia " << i << ": ";
                }
                else if (j == 3) {
                    cout << "Ingrese creditos de la materia " << i << ": ";
                }
                cin >> Categ[i][j];


            }
            outputFile<< Categ[i][j] << ' ';


        }
        outputFile << endl;
    }

    outputFile.close();

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
