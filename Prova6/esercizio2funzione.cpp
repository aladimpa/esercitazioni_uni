#include <iostream>
using namespace std;

void serie_Fibonacci (int x)
{
    int nc = 1;
    int np = 0;
    int s;
    cout << nc << " ";
    for (int i=1; i<x; i++)
        {
            s = nc + np;
            nc = s;
            np = nc - np;
            cout << nc << " ";
        }
}

int main()
{
    int n, s;
    cout << "Quanti numeri della serie di Fibonacci vuoi vedere?" << endl;
    cin >> n;
    if ( n > 0 )
    {
        cout << "La serie di Finobacci è:" << endl;
        serie_Fibonacci (n);
        cout << endl;
    }
    else
    {
        cout << "Attenzione! Non hai inserito correttamente il numero" << endl;
    }
    return 0;
}