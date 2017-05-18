/*
    Per compilare: g++ -o Esercizio3statico Data.cpp Partita.cpp esercizio3statico.cpp
*/
#include <iostream>
#include <cstring>
using namespace std;

// Basta includere la prima classe, perché data viene inserita da dentro al file `Partita.h`
#include "Partita.h"

class ArchivioPartite
{
    public:
            ArchivioPartite();
            ArchivioPartite(const ArchivioPartite& ap);
            ~ArchivioPartite();
            void inserisci_partita();
            int n_partite_archivio();
            Partita partita_dato_indice(int n);
            void stampa_archivio();
    private:
            Partita _archivio[100];
            int _n;
};

ArchivioPartite::ArchivioPartite()
{
    _n = 0;
}

ArchivioPartite::ArchivioPartite(const ArchivioPartite& ap)
{
    for (int i=0; i<ap._n;i++)
    {
        _archivio[i] = ap._archivio[i];
    }
    _n = ap._n;
}

ArchivioPartite::~ArchivioPartite()
{
}

void ArchivioPartite::inserisci_partita()
{
    if (_n < 100) 
    {
        _archivio[_n].inserisci_partita();
        _n++;
    }
    else
    {
        cout << "Spazio finito, non é possibile inserire altre partite" << endl;
    }
}

int ArchivioPartite::n_partite_archivio()
{
    return _n;
}

Partita ArchivioPartite::partita_dato_indice(int n)
{
    if ((n > _n)&&(n < 0))
    {
        cout << "Non esiste la partita cercata" << endl;
        return Partita();
    }
    else
    {
        return _archivio[n];
    }
}

void ArchivioPartite::stampa_archivio()
{
    for (int i = 0; i< _n; i++)
    {
        _archivio[i].stampa_partita();
    }
}

int main()
{
    ArchivioPartite ap;
    bool esci = false;
    do
    {
        int scelta;
        cout << "Inserisci il numero per la scelta:" << endl
            << "1 - Inserimento partita;" << endl
            << "2 - Mostra numero dei goal totali;" << endl
            << "3 - Mostra numero massimo dei goal segnati in una singola partita;" << endl
            << "4 - Mostra il numero medio degli espulsi per partita;" << endl
            << "5 - Mostra il numero massimo degli ammoniti;" << endl
            << "6 - Mostra partite giocate nel mese da te richiesto;" << endl
            << endl << "7 - Esci" << endl
            << endl << "Scelta: ";
        cin >> scelta;
        switch (scelta)
        {
            case 1: 
            {
                ap.inserisci_partita();
                break;
            }
            case 2: 
            {
                int tot = 0;
                for (int i=0; i < ap.n_partite_archivio(); i++ )
                {
                    Partita part(ap.partita_dato_indice(i));
                    tot = tot + part.getNgoal(1);
                    tot = tot + part.getNgoal(2);
                }
                cout << "Goal totali: " << tot << endl;
                break;
            }
            case 3: 
            {
                int max = 0;
                for (int i=0; i < ap.n_partite_archivio(); i++ )
                {
                    Partita part(ap.partita_dato_indice(i));
                    int somma = part.getNgoal(1) + part.getNgoal(2);
                    if (somma > max)
                    {
                        max = somma;
                    }
                }
                cout << "Il massimo numero di goal effettuati in una partita é: " << max << endl;
                break;
            }
            case 4: 
            {
                if (ap.n_partite_archivio() == 0)
                {
                    cout << "Non sono state giocate partite." << endl;
                }
                else
                {
                    int tot = 0;
                    for (int i=0; i < ap.n_partite_archivio(); i++ )
                    {
                        Partita part(ap.partita_dato_indice(i));
                        tot = tot + part.getNespulsi();
                    }
                    cout << "Il numero medio degli espulsi é: " << tot/ap.n_partite_archivio() << endl;
                }
                break;
            }
            case 5: 
            {
                if (ap.n_partite_archivio() == 0)
                {
                    cout << "Non sono state giocate partite." << endl;
                }
                else
                {
                    int tot = 0;
                    for (int i=0; i < ap.n_partite_archivio(); i++ )
                    {
                        Partita part(ap.partita_dato_indice(i));
                        tot = tot + part.getNammoniti();
                    }
                    cout << "Il numero medio degli ammoniti é: " << tot/ap.n_partite_archivio() << endl;
                }
                break;
            }
            case 6: 
            {
                int mese;
                do
                {
                    cout << "Inserisci il mese in numero (1-12): ";
                    cin >> mese;
                    if ((mese>0)&&(mese<13))
                    {
                        int mesep;
                        for (int i=0; i < ap.n_partite_archivio(); i++ )
                        {
                            Partita part(ap.partita_dato_indice(i));
                            mesep = part.getData().getM();
                            if (mese == mesep)
                            {
                                part.stampa_partita();
                            }
                        }
                    }
                } while (!((mese>0)&&(mese<13)));
                break;
            }
            case 7: 
            {
                esci = true;
                break;
            }
            default: 
            {
                cout << "Scelta scorretta!" << endl;
                break;
            }
        }
    } while (!esci);
    return 0;
}