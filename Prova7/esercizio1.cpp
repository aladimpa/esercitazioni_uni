#include <iostream>
using namespace std;

int sostituisci(char s[], char a, char b)
{
    int cont = 0;
    for (int i=0; s[i]!='\0'; i++)
    {
        if (s[i] == a)
        {
            s[i] = b;
            cont = cont + 1;
        }
    }
    return cont;
}

int main()
{
    char x, y;
    char str[512];
    cout << "Inserisci una stringa (attenzione: massimo 511 caratteri)" << endl;
    cin >> str;
    cout << "Inserisci la lettera che vorresti scambiare" << endl << "Lettera: ";
    cin >> x;
    cout << "Inserisci la lettera che andrà a sostituire l'altra" << endl << "Lettera: ";
    cin >> y;
    int sostituzioni = sostituisci(str, x, y);
    cout << "Il numero di lettere cambiate è: " << sostituzioni << endl << "La stringa modificata è: " << str << endl;
    return 0;
}