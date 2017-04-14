#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int numeri(char s[], int a[], int n)
{
    int numeri[n];
    int k = 0;
    int cont = 0;
    int z = 0;
    int calcolo = 0;
    int q = strlen(s);
    for (int i = q-1; i > -1; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            cont = cont + 1;
            numeri[k] = s[i] - '0';
            k = k + 1;
            continue;
        }
        else
        {
            if (cont == 1)
            {
                a[z] = numeri[0];
                z = z + 1;
            }
            if (cont > 1)
            {
                for ( int x=0; x<k; x++)
                {
                    calcolo = calcolo + (pow(10,x)*numeri[x]);
                }
                a[z] = calcolo;
                z = z + 1;
            }
            calcolo = 0;
            cont = 0;
            k = 0;
        }
    }
    int cont_num = 0;
    for (int r=0 ; r<z; r++)
    {
        cont_num = cont_num + 1;
    }
    return cont_num;
}

int main()
{
    char stringa[101];
    int n = 0;
    cout << "Inserisci una stringa" << endl;
    cin.getline(stringa,101);
    cout << "Inserisci il numero di numeri che vuoi visualizzare della stringa" << endl;
    cin >> n;
    if (n <= 0)
    {
        cout << "Errore: il programma non può essere eseguito perchè hai inserito un numero minore di 1" << endl;
    }
    else
    {
        int a[n];
        int num = numeri(stringa, a, n);
        cout << num << endl;
        for ( int i=num-1; i>-1; i-- )
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}