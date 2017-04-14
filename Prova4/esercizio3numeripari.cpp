#include <iostream>
using namespace std;

int main()
{
    int numero; 
    int npari=0;
    int cont=0;
    cout << "Inserisci una serie numerica formata da numeri interi positivi, maggiori di 0" << endl 
        << "Per interropere l'inserimento devi inserire 0 oppure un numero negativo" << endl;
    do 
    {
        cin >> numero;
        if (numero >0)
        {
            cont = cont + 1;
            if (numero%2==0)
            {
                npari= npari + 1;
            }
        }
    } while (numero>0);
    if (cont==0)
    {
        cout << "La tua serie numerica è vuota: non hai inserito nessun numero" << endl;
    }
    else
    {
        if (npari!=0)
        {
            if (npari==1)
            {
                cout <<"Su " << cont << " numero/i inseriti, ce n'è uno solo pari" << endl;
            }
            else
            {
                cout <<"Su " << cont << " Numero/i inseriti, " << npari << " sono pari" << endl;
            }
        }
        else
        {
            cout << "Non ci sono numeri pari nella serie numerica inserita" << endl;
        }
    }
    return 0;
}