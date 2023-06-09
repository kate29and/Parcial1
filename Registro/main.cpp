
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void llenar(char*** Categ,int n);
void imprimir(char ***Categ,int n, char* cc);
void regist(char ***Categ,int n, char cc[15]);
void liberar(char ***Categ,int n);
int conversor(char Dato[30]);
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
            Categ[i][j] = new char[15]; // memoria para dato
        }
    }
    llenar(Categ,n);
    regist(Categ,n,cc);

    hora = new char**[7]; // memoria para filas
    for (int i=0; i<7 ; i++){
        hora[i] = new char*[6];//memoria para columnas
        for (int j = 0; j < 6; j++) {
            hora[i][j] = new char[10]; // memoria para dato
        }
    }
    llenar(hora,7);

    liberar(Categ,n);
    liberar(hora,7);
}

void regist(char ***Categ,int n, char cc[15]){


    Categ[0][0]= "Codigo         ";
    Categ[0][1]= "Materia        ";
    Categ[0][2]= "Hora Teorica   ";
    Categ[0][3]= "Hora Practica  ";
    Categ[0][4]= "Creditos       ";

    for (int i = 1; i < n + 1; i++) {

        cout << "Ingrese codigo de la materia: " << i << ": ";
        cin>>Categ[i][0];

        if(i<=1){
            for(int k=1;k<=i-1;k++){
                if(conversor(Categ[k][0])==conversor(Categ[i][0])){
                    cout<<"hh";
                }
                else{
                    break;
                }
            }
       }


        cout << "Ingrese nombre de la materia: " << i << ": ";
        cin>>Categ[i][1];

        cout << "Ingrese horas teoricas:       " << i << ": ";
        cin>>Categ[i][2];

        cout << "Ingrese horas practicas:      " << i << ": ";
        cin>>Categ[i][3];

        cout << "Ingrese creditos de la materia: " << i << ": ";
        cin>>Categ[i][4];

    }
    imprimir(Categ,n,cc);
}
int conversor(char Dato[30]){

    int n=0;
    for(int i=0; Dato[i]!='\0'; i++){
        n=n*10+(Dato[i]-'0');

    }
    return n;
}
void imprimir(char*** Categ,int n, char* cc) {
    ofstream outputFile(cc); // modo escritura
    if (!outputFile) {
        cout << "Error al crear archivo de salida" << endl;
    }
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < 5; j++) {
            cout << " | ";
            for (int k = 0; k < 15; k++) {
                cout << Categ[i][j][k] ;
            }
            outputFile<< Categ[i][j] << '| ';
        }
        cout << " | "<<endl;
    }
    outputFile.close();

}

void llenar(char*** Categ,int n) {
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 15; k++) {
                Categ[i][j][k] = '*';
            }
        }
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
void Imprimir(char ***Materias, int Num,int tam){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < tam; b++) {
            for (int c = 0; c < 25; c++) {
                cout<<Materias[a][b][c];
                if (Materias[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}
