#include <iostream>
using namespace std;

bool controllo_data (int &giorno, int &mese, int &anno, char tipocontrollo)
{
    int maxAnno;
    if (tipocontrollo == 'o')
    {
        maxAnno = 2016;
    } 
    else 
    {
        maxAnno = 1900;
    }
    if ((anno >= maxAnno)&&(anno <= 2099))
    {
        if ((mese >= 1)&&(mese <= 12))
        {
            int numgiorni;
            switch (mese)
            {
                case 2: 
                        if (((anno%4==0)&&(anno%100!=0))||((anno%100==0)&&(anno%400==0)))
                            numgiorni=29;
                        else
                            numgiorni=28;
                        break;
                case 4: 
                        numgiorni=30;
                        break;
                case 6:
                        numgiorni=30;
                        break;
                case 9:
                        numgiorni=30;
                        break;
                case 11: 
                        numgiorni=30;
                        break;
                default: 
                        numgiorni=31;
            }
            if ((giorno > numgiorni) || (giorno < 1)) 
            {
                cout << "Non hai inserito in modo corretto la data" << endl; return false;
            } 
            else 
            {
                return true;
            }
        }
        else cout << "Non hai inserito in modo corretto la data" << endl; return false;
    }
    else cout << "Non hai inserito in modo corretto la data" << endl; return false;   
}

int main ()
{
    int gg, mg, ag, gn, mn, an, ge, me, ae;
    char ignora_trattino;
    cout << "Inserisci la data di oggi utilizzando il trattino (gg-mm-aaaa): " << endl;
    cin >> gg >> ignora_trattino >> mg >> ignora_trattino >> ag;
    if (!controllo_data(gg, mg, ag, 'o')) return 1;
    cout << "Inserisci la data di nascita utilizzando il trattino (gg-mm-aaaa): " << endl;
    cin >> gn >> ignora_trattino >> mn >> ignora_trattino >> an;
    if (!controllo_data(gn, mn, an, 'n')) return 1;
    if (an > ag)
    {
        cout << "E' impossibile essere nati successivamente all'età corrente" << endl;
    }
    else 
    {
        if ((mn <= mg)&&(gn <= gg)) //anni già compiuti
        {
            ge = gg - gn;
            me = mg - mn;
            ae = ag - an;
            if (ae > 99)
            {
                cout << "Complimenti! Lei ha più di cento anni!" << endl;
            }
            else if (ae < 1)
            {
                cout << "Attentenzione! Hai meno di un anno!" << endl;
            }
            else
            cout << "Lei ha:" << endl << 
                    ae << " anni" << endl << me << " mese/i" << endl << ge << " giorno/i" << endl;
        }
        else 
        {
            ae = ag - an -1;
            me = mg - mn -1;
            ge = gg - gn;
            if (ae > 99)
            {
                cout << "Complimenti! Lei ha più di cento anni!" << endl;
            }
            else if (ae < 1)
            {
                cout << "Attentenzione! Hai meno di un anno!" << endl;
            }
            else
            cout << "Lei ha:" << endl << 
                    ae << " anni" << endl << me << " mese/i" << endl << ge << " giorno/i" << endl;
        }
    }
}
