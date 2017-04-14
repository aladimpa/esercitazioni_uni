#include <iostream>
using namespace std;

int main()
{ 
    int cont;
    double numero, media, somma;
    cout << "Inserisci una serie numerica formata da almeno un numero diverso da zero" << endl
        << " Per interropere la serie bisogna inserire 0" << endl;
    do 
    {
        cin >> numero;
        if (numero!=0)
        {
            cont=cont+1;
            somma=somma+numero;
        }
    } while (numero!=0);
    if (cont!=0)
    {
        media=somma/cont;
        cout << "La media dei numeri inseriti è: " << media << endl;
    }
    else 
    {
        cout << "Attenzione! Devi inserire almeno un munero" << endl;
    }
    return 0;
}