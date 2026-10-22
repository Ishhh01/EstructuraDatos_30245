#include<iostream>
using namespace std;

void factorial(int *n, long long *resultado){
    *resultado = 1;
    for(int i=1;i<=*n;i++)
    {
        *resultado = *resultado * i;
    }
}

int main(){
    int num;
    long long fact;
    int *p = &num;
    long long *pf = &fact;

    cout<<"Ingrese un numero:";
    cin>>*p;

    if(*p<0)
    {
        cout<<"No existe factorial de un numero negativo"<<endl;
    }
    else
    {
        factorial(p,pf);
        cout<<"El factorial de "<<*p<<" es: "<<*pf<<endl;
    }
    system("pause");
    return 0;
}
