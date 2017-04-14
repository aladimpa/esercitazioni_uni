#include <iostream>
#include <cmath>
using namespace std;

double calcolo_distanza(double x1, double y1, double x2, double y2)
{
    double distanza;
    distanza = sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
    return distanza;
}

int main()
{
    double x1, y1, x2, y2, distanza;
    char ignora_trattino;
    char uscita='n';
    cout << "Inserisci le coordinate dei due punti" << endl;
    do
    {
            cout << "Inserisci le coordinate del primo punto utilizzando un trattino (0-1)" << endl;
            cin >> x1 >> ignora_trattino >> y1;
            cout << "Inserisci le coordinate del secondo punto utilizzando un trattino (0-1)" << endl;
            cin >> x2 >> ignora_trattino >> y2;
            distanza = calcolo_distanza (x1, y1, x2, y2);
            cout << "La distanza tra i due punti è: " << distanza << endl;
            cout << "Vuoi uscire dal programma? Inserire s-n" << endl;
            cin >> uscita;
    } while (uscita == 'n');
    return 0;
}