#include <iostream>
using namespace std;

int main()
{
    int secondi;
    cout<<"Inserisci i secondi che si desiderano convertire: ";
    cin>> secondi;
    const int min = 60;
    const int ores = min*60;
    const int gg = ores*24;
    const int sett = gg*7;
    int settimane = secondi/sett;
    secondi = secondi % sett;
    int giorni = secondi / gg;
    secondi = secondi % gg;
    int ore = secondi / ores;
    secondi = secondi % ores;
    int minuti = secondi / min;
    secondi = secondi % min;
    cout<< "I secondi inseriti corrispondono a: " << endl
                                                << settimane << " settimana/e" << endl 
                                                << giorni << " giorno/i" << endl
                                                << minuti << " minuto/i" << endl   
                                                << secondi << " secondo/i" << endl;
    return 0;                                                
}