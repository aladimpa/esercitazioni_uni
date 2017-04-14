#include <iostream>
#include <cstring>
using namespace std;

char* concatenazione_stringhe(char stringa1[], char stringa2[])
{
    int prima = strlen(stringa1);
    int dim = prima;
    prima = strlen(stringa2);
    dim += prima;
    char* stringa3 = new char[dim+1];
    strcat(stringa3, stringa1);
    strcat(stringa3, stringa2);
    return stringa3;
}

int main()
{
    const int dim = 32;
    char str1[dim];
    char str2[dim];
    cout << "Inserisci la prima stringa (massimo 31 caratteri)" << endl << "Stringa:";
    cin >> str1;
    cout << "Inserisci la seconda stringa (massimo 31 caratteri)" << endl << "Stringa:";
    cin >> str2;
    char* pstr3 = concatenazione_stringhe(str1, str2);
    cout << pstr3;
    delete[] pstr3;
    return 0;
}