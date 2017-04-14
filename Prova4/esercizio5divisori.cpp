#include <iostream>
using namespace std;

int main()
{
    int numero, dividendo;
    do
    {
        cout << "Inserisci un numero intero positivo" << endl;
        cin >> numero;
        if (numero<1)
        {
            cout << "Non hai inserito correttamente il numero" << endl;
        }
        else 
        {
            dividendo=numero;
        }
    } while (numero<1);
    cout << "I divisori di " << numero << " sono:" << endl;
    cout << numero << endl;
    for (int i=dividendo/2; i>0; i--)
    {
        if (dividendo%i==0)
        {
            cout << i << endl;
        }
     }
}