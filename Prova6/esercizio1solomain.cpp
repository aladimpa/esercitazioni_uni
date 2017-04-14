#include <iostream>
using namespace std;

int main()
{
    int n, s;
    int nc = 1;
    int np = 0;
    cout << "Quanti numeri della serie di Fibonacci vuoi vedere?" << endl;
    cin >> n;
    if ( n > 0 )
    {
        cout << "La serie di Fibonacci è: " << endl << nc << " ";
        for (int i=1; i<n; i++)
        {
            s = nc + np;
            nc = s;
            np = nc - np;
            cout << nc << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Attenzione! Non hai inserito correttamente il numero" << endl;
    }
    return 0;
}