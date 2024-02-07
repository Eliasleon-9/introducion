#include <iostream>
using namespace std;
 int main()
 {
    int n1, n2, n3;
    cout<<"Ingrese el primer numero\n";
    cin>>n1;
    cout<<"Ingrese el segundo numero\n";
    cin>>n2;
    cout<<"Ingrese el tercer numero\n";
    cin>>n3;
    if (n1>n2)
    {
        cout<<"el numero "<<n1<<" es mayor";
    } else if(n2>n3){
        cout<<"el nmero "<<n2<<" es mayor";
    }else {
        cout<<"el numero "<<n3<<" es mayor";
    }

    return 0;
 }