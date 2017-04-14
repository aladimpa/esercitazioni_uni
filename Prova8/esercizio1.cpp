#include <iostream>
#include <cstring>
using namespace std;

struct esame
{
    char nome_stud[32];
    char cognome_stud[32];
    int num_matricola;
    int voto;
};

struct sessione
{
    int num_esami;
    esame archivio_esame[100];
};

int inserimento_esame(esame& e /* non servirebbe */, sessione& sessione) 
{
    int inserito;
    cout << "Inserire il nome dello studente: ";
    cin >> e.nome_stud; //sessione.archivio_esame[sessione.num_esami].nome_stud;
    cout << "Inserisci il cognome: ";
    cin >> e.cognome_stud;
    cout << "Inserisci il numero di matricola: ";
    cin >> e.num_matricola;
    do
    {
        cout << "Inserisci il voto: ";
        cin >> e.voto;
        if (e.voto<18 || e.voto>30)
        {
            cout << "Attenzione! Non hai inserito correttamente il voto" << endl;
        } 
    }while (e.voto<18 || e.voto>30);
    if (sessione.num_esami<100)
    {
        sessione.archivio_esame[sessione.num_esami] = e;    //quindi questo non servirebbe
        sessione.num_esami = sessione.num_esami + 1;
        cout << sessione.num_esami << endl;
        inserito = 1;
    }
    else
    {
        inserito = 0;
    }
    return inserito;
}

double media_voti (sessione& sessione)
{
    int somma = 0;
    switch (sessione.num_esami)
    {
        case 0:
        {
                return 0.0;
                break;
        }
        case 1:
        {
                return sessione.archivio_esame[0].voto;
        }
        default:
        {
                for (int i=0; i < sessione.num_esami; i++)
                {
                    somma = somma + sessione.archivio_esame[i].voto;
                }
                return somma/sessione.num_esami;
        }
    }
}

int num_studenti(int n, sessione& sessione)
{
    int contatore = 0;
    for (int i=0; i<sessione.num_esami; i++)
    {
        if (sessione.archivio_esame[i].voto > n)
        contatore = contatore + 1;
    }
    return contatore;
}

int istogramma_voti( sessione& sessione)
{
    for (int i=0;i<13;i++)
    {
        cout << endl << "voto " << i+18 << " "; 
        for (int j=0;j<sessione.num_esami;j++) 
        {
            if(sessione.archivio_esame[j].voto == i+18)
            {
                cout << "*";
            }
        } 
    }
    cout << endl;
}

int main()
{
    esame e; //creo variabile di tipo esame
    sessione sessione;
    int soglia=0;
    int continua = 1;
    do 
    {
        cout << "scelte disponibili: " << endl
        << "1 - Inserire un nuovo esame;" << endl
        << "2 - Media dei voti;" << endl
        << "3 - Numero di studenti con voto superiore ad una certa soglia;" << endl
        << "4 - Istogramma dei voti coseguiti;" << endl 
        << "5 - Esci;" << endl << endl
        << "Seleziona un'opzione: ";
        int scelta = 0;
        cin >> scelta;
        switch(scelta)
        {
            case 1: 
            {
                    if (inserimento_esame(e, sessione))
                    {
                         cout << "Nuovo esame inserito correttamente" << endl << endl;
                    }
                    else
                    {
                        cout << "Non è stato possibile inserire un nuovo esame" << endl << endl;
                    }
                    break;
            }
            case 2: 
            {
                    if (media_voti(sessione) == 0.0)
                    {
                        cout << "Non hai inserito voti" << endl << endl;
                    }
                    else
                    {
                        cout << "La media dei voti è: " << media_voti(sessione) << endl;
                    }
                    break;
            }
            case 3: 
            {
                    do
                    {
                        cout << "Inserire il voto di soglia" << endl << "Voto: ";
                        cin >> soglia;
                            if (soglia<18 || soglia>30)
                            {
                                cout << "Devi inserire correttamente la soglia" << endl;
                            }
                    } while (soglia<18 || soglia>30);
                    
                    switch (num_studenti(soglia, sessione))
                    {
                        case 0: cout << "Non ci sono studenti" << endl;
                                break;
                        case 1: cout << "C'è un solo studente" << endl;
                                break;
                        default: cout << "Gli studenti sono: " << num_studenti(soglia, sessione) << endl;
                    }
                    break;
            }
            case 4: 
            {
                    istogramma_voti( sessione);
                    break;
            }
            case 5: 
            {
                    continua=0;
                    break;
            }
            default: 
            {
                    cout << "Opzione non disponibile" << endl;
                    break;
            }
        }
    } while (continua);
    return 0;
}