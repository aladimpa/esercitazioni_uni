#include <iostream>
#include <cmath>
using namespace std;


int potenza(int n,int b, int& e, int& m)
{
    if ((n <= 0)||(b <= 0))
    {
        return -1;
    }
    else if (b == 1) 
    {
        return 0;
    }
    else 
    {
        while (n > pow(b,e))
        {
            e++;
        }
        m = pow(b,e);
        return 1;
    }
}

int main()
{
    int num1, num2, risultato, m;
    int e = 1;
    char risposta = 's';
    do
    {
        cout << "Inserisci il primo numero: " << endl;
        cin >> num1;
        cout << "Inserisci il secondo numero: " << endl;
        cin >> num2;
        if (potenza(num1, num2, e, m) == -1)
        {
            cout << "Hai inserito dei numeri negativi" << endl;
        }
        else if (potenza(num1, num2, e, m) == 0)
        {
            cout << "Hai inserito 1 nel secondo numero" << endl;
        }
        if (potenza(num1, num2, e, m) == 1)
        {
            cout << "La potenza minima è: " << e << endl
                << "E il suo valore è: " << m << endl;
        }
        cout << "Vuoi inserire una nuova coppia di numeri? s-n" << endl;
        cin >> risposta;
    } while (risposta == 's');
    return 0;
}