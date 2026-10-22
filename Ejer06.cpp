#include<iostream>
using namespace std;

void factorial(int *p, long *r){
    *r = 1;
    for(int i=1;i<=*p;i++)
    {
        *r = *r * i;
    }
}

int main(){
    int num;
    long res;
    cout<<"Ingrese un numero:";
    cin>>num;

    if(num<0)
    {
        cout<<"No existe factorial de un numero negativo"<<endl;
    }
    else
    {
        factorial(&num,&res);
        cout<<"El factorial de "<<num<<" es: "<<*res<<endl;
    }
    system("pause");
    return 0;
}