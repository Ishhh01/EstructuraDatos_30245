#include<iostream>
#include<string>
using namespace std;
struct Alumno{
    string nombre;
    int edad;
    float nota;
};
int main(){
    int n;
    cout<<"Ingrese cantidad de alumnos:"<<endl;
    cin>>n;

    Alumno al[n];
    Alumno *p = al;
    cout<<"DATOS DE ALUMNO"<<endl;
    for(int i=0;i<n;i++)
    {
        cin.ignore();
        cout<<"Ingrese nombre:";
        getline(cin,p[i].nombre);

        cout<<"Ingrese la edad:";
        cin>>p[i].edad;

        cout<<"Ingrese nota:";
        cin>>p[i].nota;
    }
    system("cls");
    //imprimir
    for(int i=0;i<n;i++)
    {
        cout<<"Nombre:"<<p[i].nombre<<endl;

        cout<<"Edad:"<<p[i].edad<<endl;

        cout<<"Nota:"<<p[i].nota<<endl;
    }
    system("pause");
    return 0;
}