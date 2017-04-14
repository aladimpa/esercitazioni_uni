#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    cout << "Inserisci tre numeri interi" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    int d;
    d = *pb;
    *pb = *pa;
    *pa = *pc;
    *pc = d;
    cout << "Numeri invertiti!" << endl << "a: " << *pa << endl << "b: " << *pb  << endl << "c: " << *pc << endl; 
    return 0;
}