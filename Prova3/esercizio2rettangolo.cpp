#include <iostream>
using namespace std;

int main ()
{
    double x, y, a, b, c, d;
    cout << "Inserisci la coordinata x del punto che si vuole analizzare: ";
    cin >> x;
    cout << "Inserisci la coordinata y del punto che si vuole analizzare: ";
    cin >> y;
    cout << "Inserisci la coordinata a del rettangolo: ";
    cin >> a;
    cout << "Inserisci la coordinata b del rettangolo: ";
    cin >> b;
    cout << "Inserisci la coordinata c del rettangolo: ";
    cin >> c;
    cout << "Inserisci la coordinata d del rettangolo: ";
    cin >> d;
    if ((a<x)&&(x<c)&&(d<y)&&(y<b))
    {
        cout << "Il punto con coordinate " << x << " e " << y << " è dentro al rettangolo abcd" << endl;
    }
    else 
    {
        cout << "Il punto con coordinate " << x << " e " << y << " è fuori al rettangolo abcd" << endl;
    }
    return 0;
}