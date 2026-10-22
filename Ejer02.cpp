#include<iostream>
using namespace std;
int main(){
    int num[5] = {10,25,6,4,9};
    int *p = num;
    for(int i=0;i<5;i++)
    {
        cout<<"Elemento "<<*(p+i)<<endl; //10
    }

    system("pause");
    return 0;
}