#include <iostream>
#include <cstring>
using namespace std;

int anagramma(char s1[], char s2[])
{
    int cont_presente = 0;
    if (strlen(s1)==strlen(s2))
    {
        for (int i=0; s1[i] != '\0'; i++)
        {          
            for (int k=0; s2[k] != '\0'; k++)
            {
                if (s1[i] == s2[k])
                {
                    cont_presente = cont_presente + 1;
                    break;
                }
                
            }
        }
        if (cont_presente == strlen(s1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    const int dim = 512;
    char stringa1[dim];
    char stringa2[dim];
    cout << "Inserisci la parola" << endl << "Parola: ";
    cin >> stringa1;
    cout << "Inserisci un anagramma della parola " << stringa1 << "precedentemente inserita" << endl << "Anagramma: ";
    cin >> stringa2;
    if ( anagramma(stringa1, stringa2) )
    {
        cout << "E' un anagramma" << endl;
    }
    else
    {
        cout << "Non è un anagramma" << endl;
    }
    return 0;
}