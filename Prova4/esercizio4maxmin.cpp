#include <iostream>
using namespace std;

int main()
{
    double max, min, numero;
    int cont=-1;
    cout << "Inserisci una serie numerica di numeri reali, premere invio ogni volta che si inserisce un numero"
        << endl << "Per terminare l'inserimento inserire il numero 0 (zero)" << endl;
    do
    {
        cin >> numero;
        cont = cont + 1;
        if (numero!=0)
        {
            if (cont==0)
            {
                min = numero;
                max = numero;
            }
            else if (cont>0)
            {
                if (numero<min)
                {
                    min = numero;
                    
                }
                else if (max<numero)
                {
                    max = numero;
                    
                }
            }
        }
    } while (numero!=0);
    switch (cont)
    {
        case 0:
                 cout << "Non hai inserito nessun numero" << endl;
                 break;
        case 1:
                cout << "Il massimo e il minimo corrispondono ed è: "<< max << endl;
                break;
        default:
                cout << "Il massiomo è: " << max << endl << "Il minimo è: " << min << endl;
                break;
    }
    return 0;
}
