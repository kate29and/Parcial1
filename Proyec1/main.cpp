#include <iostream>
#include <fstream>
#include <istream>
#include <time.h>
#include <stdlib.h>

void impri(char ***Materias, int Num,int s,int l);
void llenar(char*** horario, int s, int d,int f);
void formatotxt(char ***Materias, int Num, int paso, char *Caja);
void liberador(char ***Materias, char ***horario, char *Caja, char *Cajahorario, int Num);
void random(char ***horario, char ***Materias, int Num);
void rellenarArreglo(char *arreglo, int longitud, char relleno);
void formatohorariotxt(char ***horario, int paso, char *Cajahorario);
int conversor(char Dato[30]);


using namespace std;

int main()
{
    /////////Declaracion e inicializacion de Variables///////

    ofstream Archivo;//Variable para escribir el txt.
    ofstream Archivo2;
    char ***Materias=nullptr; // Arreglo dinamico con ptr
    int Num=0;//Numero de materias;
    char documento[11], documento2[12];//Numero de documento

    int dia = 0, dia2 = 0, hora = 0;
    char eleccion = ' ';
    char ***horario = nullptr;
    bool H=true;



    ///////////////Recepcion de datos por teclado////////////

    cout<<"Ingrese su numero de documento: ";
    cin>>documento;

    documento2[0]+='H';
    for(int i = 1; i<12; i++){
        documento2[i] = documento[i-1];
    }
 ;

    cout<<"Ingrese el numero de materias: ";
    cin>>Num;
    //////////////// Matriz dinamica de Datos///////////////

    Materias = new char**[Num+1];
    for (int k=0; k<Num+1 ; k++){
        Materias[k]=new char*[5];//memoria para columnas
        for (int j = 0; j < 5; j++) {
            if(j==1){
                Materias[k][j] = new char[25]; // memoria para dato
            }

        }
    }
    llenar(Materias,Num+1,5,25);
    Materias[0][0]= "Codi";
    Materias[0][1]= "Mate";
    Materias[0][2]= "HorT";
    Materias[0][3]= "HorP";
    Materias[0][4]= "Cred";
    for(int i=1; i<Num+1; i++){
        cout<<"Ingrese el codigo de la materia ["<<i<<"] : ";
        cin>>Materias[i][0];

        if(i>1){
            while(H!=false){

                for(int k = 1; k<Num; k++){
                    if(conversor(Materias[i][0])==conversor(Materias[k][0])){
                        cout<<"La materia ya fue ingresada, intente otra "<<endl;
                        cout<<"Ingrese el codigo de la materia ["<<i<<"] : ";
                        cin>>Materias[i][0];
                        k=1;
                    }
                    else{
                        H=false;
                    }

                }
            }
        }


        cout<<endl;

        cout<<"Ingrese el nombre de la materia : ";
        cin>>Materias[i][1];
        cout<<endl;

        cout<<"Ingrese Horas de clase teorica : ";
        cin>>Materias[i][2];
        cout<<endl;

        cout<<"Ingrese Horas de clase practica: ";
        cin>>Materias[i][3];
        cout<<endl;

        cout<<"Ingrese el numero de creditos de la materia: ";
        cin>>Materias[i][4];
        cout<<endl;
    }

    ////////////////////Imprimir Datos///////////////////////

    impri(Materias, Num+1,5,25);
    char *almacen=new char [50];
    int paso=-1;
    ////////////////Pasar datos a Arreglo Lineal//////////////

     formatotxt(Materias, Num, paso, almacen);
    //////////////////Escribimos el Archivo///////////////////

     Archivo.open(documento);
     Archivo <<almacen ;
     Archivo.close();

    //////////////////Borrar memoria reservada///////////////



    ///////////////////Fin de la ejecucion///////////////////
    ///
    ///
    //crear matriz para horarios
    horario = new char**[14];
    for (int i = 0; i < 14; i++) {
        horario[i] = new char*[6];
        for (int j = 0; j < 6; j++) {
            horario[i][j] = new char[10];
        }
    }

    llenar(horario,14,6,10);

    horario[0][0]= "Hora      ";
    horario[0][1]= "1.Lunes   ";
    horario[0][2]= "2.Martes  ";
    horario[0][3]= "3.Miercole";
    horario[0][4]= "4.Jueves  ";
    horario[0][5]= "5.Viernes ";

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

    impri(horario,14,6,10);

    do {
        cout << "-----------------CRONOGRAMA--------------------" << endl;
        cout << "Ingrese el primer dia que desea registrar: " << endl;

        cin >> dia;

        cout << "Ingrese el horario donde registrara la materia: " << endl;

        cin >> hora;

        if (horario[hora-5][dia][0] == ' ') {
            cout << "Ingresa el codigo de la materia: ";
            cin >> horario[hora-5][dia];
            rellenarArreglo(horario[hora][dia], 10,  ' ');

            cout << endl;
            impri(horario,14,6,10);
        }
        else {
            cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
        }


        cout << "\nEl usuario ha sido agregado. Presiona cualquier tecla para agregar otro usuario\no '*' para terminar: ";
        cin >> eleccion;
        cout << endl;

    } while (eleccion != '*');

    ////////GUARDAR TXT HORARIO////////
    char *almacenhorario= new char [1200];
    paso=-1;

    formatohorariotxt(horario, paso, almacenhorario);
    //////////////////Escribimos el Archivo///////////////////

    Archivo.open(documento2);
    Archivo <<almacenhorario ;
    Archivo.close();


    cout << "\nProceso de eleccion de horas de repaso"<<endl;

    int opc=0;

    cout<<"Elige el metodo de asignacion de horas de repaso"<<endl;



    cout<<"1. Manual. "<<endl;
    cout<<"2. Automatico(No recomendable)"<<endl;
    cin>>opc;

    switch(opc){



    case 1:
        do {
            cout << "-----------------CRONOGRAMA--------------------" << endl;
            cout << "Ingrese el primer dia que desea registrar: " << endl;

            cin >> dia;

            cout << "Ingrese el horario donde registrara la materia: " << endl;

            cin >> hora;

            if (horario[hora-5][dia][0] == ' ') {
                cout << "Ingresa el codigo de la materia: ";
                cin >> horario[hora-5][dia];
                rellenarArreglo(horario[hora-5][dia], 10,  ' ');

                cout << endl;
                impri(horario,14,6,10);
            }
            else {
                cout<< "Ya esta ocupado el horario, intenta con otro. "<<endl;
            }


            cout << "\nEl usuario ha sido agregado. Presiona cualquier tecla para agregar otro usuario\no '*' para terminar: ";
            cin >> eleccion;
            cout << endl;

        } while (eleccion != '*');
        break;

    case 2:

        random(horario, Materias, Num);

        break;



    }

    liberador(Materias, horario, almacenhorario, almacen, Num);
}

void formatohorariotxt(char ***horario, int paso, char *Cajahorario){
    for (int i = 0; i < 14; i++) {
        for (int b = 0; b < 6; b++) {

            for (int c = 0; c < 10; c++) {
                if (horario[i][b][c]=='\0') break;

                if (horario[i][b][c]!='\0'){
                    paso++;
                    Cajahorario[paso]= horario[i][b][c];
                }
            }
            paso++;
            Cajahorario[paso]='|';
        }
        paso++;
        Cajahorario[paso]='\n';
    }
}

void rellenarArreglo(char *arreglo, int longitud, char relleno) {
    int tamanoActual = 0;
    while (arreglo[tamanoActual] != '\0') {
        tamanoActual++;
    }
    int espaciosSobrantes = longitud - tamanoActual;
    if (espaciosSobrantes > 0) {
        for (int i = tamanoActual; i < longitud; i++) {
            arreglo[i] = relleno;
        }
        arreglo[longitud] = '\0';
    }
}

int conversor(char Dato[30]){

    int n=0;
    for(int i=0; Dato[i]!='\0'; i++){
        n=n*10+(Dato[i]-'0');

    }
    return n;
}


void random(char ***horario, char ***Materias, int Num){

    for(int i = 0; i<Num; i++){

        int aux = (conversor(Materias[i][4])*3)-(conversor(Materias[i][2])+conversor(Materias[i][3]));
        cout<<"la operacion da: "<<aux<<endl;


        int Q = 0;
        while(Q<aux){
            int dia = 1+rand()%(6-1);

            int hora = 1+rand()%(14-1);

            cout<<dia<<" "<<hora<<endl;

            if(horario[hora][dia][0] == ' '){

                cout<<"Funciona :D"<<endl;
                Q++;
                horario[hora][dia] = Materias[i][0];
                rellenarArreglo(horario[hora][dia], 10,  ' ');
                impri(horario,14,6,10);

            }

        }

    }

}



void llenar(char*** horario, int s, int d,int f) {

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < f; k++) {
                horario[i][j][k] = ' ';
            }
        }
    }


}



void impri(char ***Materias, int Num,int s,int l){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < s; b++) {
            for (int c = 0; c < l; c++) {
                cout<<Materias[a][b][c];
                if (Materias[a][b][c]=='\0') break;
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}


void formatotxt(char ***Materias, int Num, int paso, char *Caja){
    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 25; c++) {
                if (Materias[a][b][c]=='\0') break;

                if (Materias[a][b][c]!='\0'){
                    paso++;
                    Caja[paso]= Materias[a][b][c];
                }
            }
            paso++;
            Caja[paso]='|';
        }
        paso++;
        Caja[paso]='\n';
    }
}

void liberador(char ***Materias, char ***horario, char *Cajahorario, char *Caja, int Num){
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 6; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }
    delete[] horario;

    for (int a = 0; a < Num; a++) {
        for (int b = 0; b < 5; b++) {
            delete[] Materias[a];
        }
    }
    delete[] Materias;
    delete[] Caja;
    delete[] Cajahorario;
    Materias=nullptr;
    Caja=nullptr;
    Cajahorario=nullptr;
}




