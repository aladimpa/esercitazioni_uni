#include <iostream>
#include <math.h>
using namespace std;

double elevamento(double base, double potenza)
{
    if(potenza == 0)
    {
        return 1;
    }
    return base*elevamento(base, potenza-1);
}

double fatt(double num)
{
    if (num==0)
    {
        return 1;
    }
    return num*fatt(num-1);
}

double sin(double n, double x)
{
    double segno, numeratore, denominatore;
    double ris = 0.0;
    for (int k=0; k<n; k++)
    {
        segno = elevamento(-1,k);
        numeratore = elevamento(x, (2*k+1));
        denominatore = fatt(2*k+1);
        ris = ris + (segno*(numeratore/denominatore));
    }
    return ris;
}

int main()
{
    int numero, termine;
    cout << "Calcolo del seno in radianti." << endl;
    cout << "Inserisci il numero su cui vuoi calcolare il sin: ";
    cin >> numero;
    cout << "Fino a quale termine vuoi calcolarlo? ";
    cin >> termine;
    double seno = sin(termine, numero);
    cout << "Il seno è " << seno << endl; 
    return 0;
}