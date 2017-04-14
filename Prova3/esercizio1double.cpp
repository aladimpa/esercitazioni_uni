#include <iostream>
using namespace std;

double addizione (double x,double y)
{
    double z = x + y;
    return z;
}

double sottrazione (double x,double y)
{
    double z = x - y;
    return z;
}

double moltiplicazione (double x,double y)
{
    return x*y;
}

double divisione (double x,double y)
{
    return x / y;
}

int main()
{
    double num1;
    double num2;
    char operaz;
    cout<< "Inserisci il primo numero: ";
    cin>> num1;
    cout<< "Inmserisci il secondo numero: ";
    cin>> num2;
    cout<< "Inserisci il tipo di operazione che si vuole eseguire (+/-/*/:) ";
    cin>> operaz;
    switch (operaz)
    {
        case '+':
                cout << "Il risultato dell'addizione è " << addizione(num1,num2) << endl;
                break;
        case '-':
                cout << "Il risultato della sottrazione è " << sottrazione(num1,num2) << endl;
                break;
        case '*':
                cout << "Il risultato della moltiplicazione è " << moltiplicazione(num1,num2) << endl;
                break;
        case ':':
                if (num2 !=0)
                {
                    cout << "Il risultato della divisione è " << divisione(num1,num2) << endl;
                }
                else
                {
                    cout<< "E' impossibile eseguire la divisione perchè il divisore è 0" << endl;
                }
                break;
        default :
                cout << "Inserire correttamente i dati richiesti!" << endl;
    }
    return 0;
}