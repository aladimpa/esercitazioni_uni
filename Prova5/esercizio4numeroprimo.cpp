#include <iostream>
using namespace std;

int numero_primo(int n)
{
    bool primo = true;
    int se_primo;
    for (int i=2; i<n/2; i++)
    {
        if (n%i == 0)
        {
            primo = false;
            break;
            se_primo = 0;
        }
        else
        {
            se_primo = 1;
        }
    }
    return se_primo;
}

int main()
{
    int numero, se_primo;
    char risposta = 's';
    do
    {
        cout << "Inserisci un numero intero positivo." << endl << 
            "Attenzione uscirà 0 se il numero non è primo, 1 se invece lo è!" << endl
            << "Numero: ";
        cin >> numero;
        cout << "Risultato: ";
        if (numero > 0)
        {
            se_primo = numero_primo( numero);
            cout << se_primo << endl;
            cout << endl << "Vuoi inserire un altro numero? s-n" << endl;
            cin >> risposta;
        } 
        else 
        {
            cout << "Attenzione! Devi inserire correttamente il numero" << endl;
        }
    } while (risposta == 's');
    return 0;
}