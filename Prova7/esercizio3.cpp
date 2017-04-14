#include <iostream>
using namespace std;

int rimozione(char s[], char a)
{
    int cont = 0;
    int i = 1;
    
    while (s[i-1] != '\0')
    {
        if (s[i-1] == a)
        {
            for (int k=i-1; s[k]!='\0'; k++)
            {
                s[k] = s[k+1];
            }
            cont = cont + 1;
            if (s[i-1] != a)
            {
                i = i + 1;
            }
        }
        else
        {
            i = i + 1;
        }
    }
    return cont;
}

int main()
{
    char lettera;
    char str[512];
    cout << "Inserisci una stringa (attenzione: massimo 511 caratteri)" << endl;
    cin >> str;
    cout << "Inserisci la lettera che vuoi eliminare" << endl << "Lettera: ";
    cin >> lettera;
    cout << "Hai eliminato in tutto " << rimozione( str, lettera ) << " carattere/i" << endl 
        << "La stringa modificata è: " << str << endl; 
    return 0;
}