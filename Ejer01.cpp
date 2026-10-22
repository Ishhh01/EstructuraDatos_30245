#include<iostream>
using namespace std;
int main(){
    int num = 10;
    int *p = &num;
    cout<<"valor de num:"<<num<<endl; //10
    cout<<"valor de la direccion de memoria de num: "<<&num<<endl; //4234234
    cout<<"valor del *p: "<<*p<<endl;//10
    cout<<"valor del p: "<<p<<endl;//df97f89f
    system("pause");
    return 0;
}