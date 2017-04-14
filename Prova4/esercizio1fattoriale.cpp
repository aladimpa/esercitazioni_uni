#include <iostream>
using namespace std;

int main()
{
    int numero;
    unsigned int fattoriale;
    fattoriale = 0;
    do 
    {  
        cout << "Inserire un numero intero positivo" << endl;
        cin >> numero;
        if (numero <= 0)
        {
            cout << "Attenzione! Bisogna inserire un numero intero maggiore di zero" << endl;
        }
        else 
        {
            fattoriale=numero;
            for (int i=numero-1; i>0; i--)
            {
                fattoriale = i*fattoriale;
            }
            cout << "Il fattoriale è: " << fattoriale << endl;
        }

    } while (numero <= 0);
    return 0;
}