#include <iostream>
using namespace std;

void scambio_per_valore(int* pa, int* pb)
{
    int c;
    c = *pb;
    *pb = *pa;
    *pa = c;
}

void scambio_per_riferimento(int& pa, int& pb)
{
    int c;
    c = pb;
    pb = pa;
    pa = c;
}

int main()
{
    int a, b, c;
    cout << "Inserisci due numeri interi" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    scambio_per_valore(&a, &b);
    cout << "Numeri invertiti!" << endl << "a: " << a << endl << "b: " << b << endl; 
    scambio_per_riferimento(a, b);
    cout << "Numeri invertiti nuovamente!" << endl << "a: " << a << endl << "b: " << b << endl; 
    return 0;
}