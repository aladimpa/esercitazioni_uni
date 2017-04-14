#include <iostream>
using namespace std;

int conteggio (char s[], int a[])
{
    for (int i=0; s[i]!='\0'; i++)
    {
        switch (s[i])
        {
            case 'a':
                {
                    a[0] = a[0] +1;
                    break;
                }
            case 'e':
                {
                    a[1] = a[1] +1;
                    break;
                }
            case 'i':
                {
                    a[2] = a[2] +1;
                    break;
                }
            case 'o':
                {
                    a[3] = a[3] +1;
                    break;
                }
            case 'u':
                {
                    a[4] = a[4] +1;
                    break;
                }
        }
    }
    return a[0] + a[1] + a[2] + a[3] + a[4];
}

int main()
{
    const int dim = 5;
    char str[512];
    int vocali[dim];
    cout << "Inserire una stringa (Attenzione: massimo 511 caratteri)" << endl;
    cin >> str;
    cout << "Il numero totale delle vocali presenti nella stringa inserita sono: " << conteggio(str, vocali) << endl;
    cout << "Ci sono: " << endl << "- " << vocali[0] << " a;" << endl << "- " << vocali[1] << " e;" << endl
        << "- " << vocali[2] << " i;" << endl << "- " << vocali[3] << " o;" << endl << "- " << vocali[4] << " u;" << endl;
    return 0;
}