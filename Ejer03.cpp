#include<iostream>
using namespace std;
struct Alumno{
    string nombre;
    int edad;
    float nota;
};
int main(){
    Alumno al= {"Mike",42,16.5};
    Alumno *p = &al;
    cout<<"DATOS DE ALUMNO"<<endl;
    cout<<"Nombre:"<<p->nombre<<endl;
    cout<<"Edad:"<<p->edad<<endl;
    cout<<"Nota:"<<p->nota<<endl;
    system("pause");
    return 0;
}