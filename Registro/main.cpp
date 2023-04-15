#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void memoria(char ***Categ,int n);
void impri(char ***Categ,int n,int s);
void regist(char ***Categ,int n, char cc[15]);
void liberar(char ***Categ,int n);

int main()
{
    int n=0;
    char ***Categ = nullptr;
    char ***hora = nullptr;
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
    regist(Categ,n,cc);
    hora = new char**[n+1]; // memoria para filas
    for (int i=0; i<n+1 ; i++){
        hora[i] = new char*[6];//memoria para columnas
        for (int j = 0; j < 6; j++) {
            hora[i][j] = new char[10]; // memoria para dato
        }
    }
    ofstream outputFile("x"); // modo escritura
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }

    int s=5, hor=8;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < s; j++) {

            if (i == 0) {

                if (j == 0) {
                    char p[]="Hora";
                    hora[i][j]=p;
                }
                else if (j == 1) {
                    char p[]="Lunes";
                    hora[i][j]=p;
                }
                else if (j == 2) {
                    char p[]="Martes";
                    hora[i][j]=p;
                }
                else if (j == 3) {
                    char p[]="Miercoles";
                    hora[i][j]=p;
                }
                else if (j == 4) {
                    char p[]="Jueves";
                    hora[i][j]=p;
                }
                else if (j == 5) {
                    char p[]="Viernes";
                    hora[i][j]=p;
                }
            }
            else if  (j==0) {

                if (i==1){
                    char p[]="08-10";
                    hora[i][j]=p;
                }
                else if(i==2){
                    char p[]="10-12";
                    hora[i][j]=p;
                }
                else if(i==3){
                    char p[]="12-14";
                    hora[i][j]=p;
                }
                else if(i==4){
                    char p[]="14-16";
                    hora[i][j]=p;
                }
                else if(i==5){
                    char p[]="16-18";
                    hora[i][j]=p;
                }
            }
            else if(j!=0) {

                hora[i][j][1]='*';
            }


        }
        outputFile << endl;
    }
    outputFile.close();
    impri(hora,n,s+1);

    liberar(Categ,n);
    liberar(hora,n);
}




void memoria(char ***Categ,int n){
    Categ = new char**[n+1]; // memoria para filas
    for (int i=0; i<n+1 ; i++){
        Categ[i] = new char*[5];//memoria para columnas
        for (int j = 0; j < 5; j++) {
            Categ[i][j] = new char[10]; // memoria para dato
        }
    }
}

void regist(char ***Categ,int n, char cc[15]){

    ofstream outputFile(cc); // modo escritura
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }
    int s=5;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < s; j++) {
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
                    char p[]="Hte ";
                    Categ[i][j]=p;
                }
                else if (j == 3) {
                    char p[]="Hpr ";
                    Categ[i][j]=p;
                }
                else if (j == 4) {
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
                    cout << "Ingrese horas teoricas" << i << ": ";
                }
                else if (j == 3) {
                    cout << "Ingrese horas practicas " << i << ": ";
                }
                else if (j == 4) {
                    cout << "Ingrese creditos de la materia " << i << ": ";
                }
                cin >> Categ[i][j];
            }
            outputFile<< Categ[i][j] << ' ';
        }
        outputFile << endl;
    }
    outputFile.close();
    impri(Categ,n,s);
}


void impri(char ***Categ,int n, int s){

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < s; j++) {
            cout << Categ[i][j] << ' ';
        }
        cout << endl;
    }
}

void liberar(char ***Categ,int n){

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < 5; j++) {
            delete[] Categ[i][j];
        }
        delete[] Categ[i];
    }
    delete[] Categ;
}
