// Create a function to calculate the perimeter of a triangle and a rectangle
// structs to use:
// - point (2 members)
// - shape (2 members)
#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    int x;
    int y;
};

struct shape
{
    int n_lati;
    point vertici[4];   // ho creato un array di tipo (struct) point
};

int main()
{
    double perimetro = 0;
    int nlati = 0;
    do 
    {
        cout << "Inserisci il numero di lati" << endl;
        cin >> nlati;
        if (nlati != 3 && nlati !=4)
        {
            cout << "Attenzione: non hai inserito correttamente" << endl;
        }
    } while (nlati != 3 && nlati !=4);
    // ora devo creare una nuova shape
    shape forma;
    // devo salvare nella forma creata il numero di lati
    forma.n_lati = nlati;
    // ora devo chiedere i punti
    for (int i=0; i<nlati; i++ )
    {
        cout << "inserisci la coordinata x del vertice " << i+1 << ": ";
        cin >> forma.vertici[i].x;
        cout << "inserisci la coordinata y del vertice " << i+1 << ": ";
        cin >> forma.vertici[i].y;
    }
    for (int j=1; j<nlati; j++)
    {
        perimetro = perimetro + 
            sqrt(pow(forma.vertici[j-1].x-forma.vertici[j].x,2) + pow(forma.vertici[j-1].y-forma.vertici[j].y,2));
    }
    cout << "Il perimetro è: " << perimetro << endl;
    return 0;
}