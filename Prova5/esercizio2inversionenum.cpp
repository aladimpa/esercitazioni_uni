#include <iostream>
#include <cmath>
using namespace std;

int inverti(int x)
{
    int reversedNumber = 0, resto;
    while(x != 0)
    {
        resto = x%10;
        reversedNumber = reversedNumber*10 + resto;
        x /= 10;
    }
    return reversedNumber;
}


int main()
{
    int numero, numero_invertito;
    char risposta = 's';
    do 
    {
        cout << "Inserisci un numero intero positivo" << endl;
        cin >> numero;
        if (numero > 9)
        {
            numero_invertito = inverti(numero);
            cout << "Il numero invertito è: " << numero_invertito << endl;
            cout << "Vuoi inserire un altro numero? Inserisci s oppure n" << endl;
            cin >> risposta;
        }
        else
        if (numero < 1)
        {
            cout << "Attenzione! Devi inserire un numero intero positivo" << endl;
        }
        else 
        {
            cout << "Non è possibile invertire il numero perchè è composto da solo una cifra" << endl;
        }
    } while (risposta == 's');
    return 0;
}