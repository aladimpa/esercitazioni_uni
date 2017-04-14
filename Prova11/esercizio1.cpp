#include <iostream>
using namespace std;

int elevamento(int base, int potenza)
{
    if(potenza ==0)
    {
        return 1;
    }
    return base*elevamento(base, potenza-1);
}

int main()
{
    int base, potenza;
    cout << "Elevamento a potenza" << endl;
    cout << "Insercisci la base: ";
    cin >> base; 
    cout << "Inserisci la potenza: ";
    cin >> potenza;
    int ris = elevamento(base, potenza);
    cout << "Il risultato è: "<< ris << endl;
    return 0;
}