#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


int main()
{
    int opc=0;
    int n=0;
    char ***Categ = nullptr;
    char ***Categ2 = nullptr;

    cout<<"Ingresar numero de materias: ";
    cin>>n;

    int s=0;
    Categ = new char**[n];
    for (int i=0; i<n; i++){
        int a=6, b=8;
        Categ[i] = new char*[5];
        if(i==0){
            for (int j=0;j<5;j++){
                Categ[i][j] = new char[30];
                cin>>Categ[i][j];
            }
        }
        else{
            Categ[i][j] = new char[30];
            Categ[i][j]=a;
        }
    }

    s=0;
    for (int i = 0; i < n; i++) {
        for (int j=0;j<5;j++){
            cout << Categ[i][j]<<'|';
            s++;
        }
        cout<<endl;
    }

}
