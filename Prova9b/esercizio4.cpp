#include <iostream>
using namespace std;

char occorrenza(char* stringa1, char* stringa2)
{
    for (int i=0; stringa1[i] != '\0'; i++)
    {
        if ((*(stringa1+i))==(*(stringa2+i)))
        {
            return *(stringa1+i);
        }
    }
    return -1;
}

int main()
{
    const int dim = 32;
    char str1[dim];
    char str2[dim];
    cout << "Inserire la prima stringa (massimo 31 caratteri)" << endl;
    cin >> str1;
    cout << "Inserire la seconda stringa (massimo 31 caratteri)" << endl;
    cin >> str2;
    if (occorrenza (str1, str2) == -1)
    cout << "Non ci sono occorrenze tra le due stringhe" << endl;
    else
    cout << "La prima occorrenza si verifica con la lettera " << occorrenza (str1, str2) << endl;
    return 0;
}