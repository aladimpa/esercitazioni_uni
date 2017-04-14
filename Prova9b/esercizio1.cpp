#include <iostream>
using namespace std;

void scambia(int* pa, int* pb, int* pc)
{
    int d;
    d = *pb;
    *pb = *pa;
    *pa = *pc;
    *pc = d;
}

int main()
{
    int a, b, c;
    cout << "Inserisci tre numeri interi" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    scambia(&a, &b, &c);
    cout << "Numeri invertiti!" << endl << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl; 
    return 0;
}