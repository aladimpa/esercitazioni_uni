#include <iostream>
using namespace std;

int main()
{
    const int dim = 32;
    char str1[dim];
    char str2[dim];
    int ok = 0;
    cout << "Inserire la prima stringa (massimo 31 caratteri)" << endl;
    cin >> str1;
    cout << "Inserire la seconda stringa (massimo 31 caratteri)" << endl;
    cin >> str2;
    for (int i=0; str1[i] != '\0'; i++)
    {
        if ((*(str1+i))==(*(str2+i)))
        {
            cout << "La prima occorrenza si verifica con la lettera " << *(str1+i) << endl;
            ok = 1;
            break;
        }
    }
    if (ok == 0)
    cout << "Non ci sono occorrenze tra le due stringhe" << endl;
    return 0;
}