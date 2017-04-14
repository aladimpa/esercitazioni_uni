#include <iostream>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

struct appartamento_in_vendita 
{
    int cod_id;
    char via[64];
    char comune[32];
    int num_vani;
    int sup_mq;
    int prezzo;
};

int inserimento_appartamento (appartamento_in_vendita& appartamento)
{
    int cont = 0;
    fstream fappartamenti;
    fappartamenti.open ("vendita_appartamenti.txt", ios::in);
    if (!fappartamenti)
    {
        fappartamenti.close();
        fappartamenti.open ("vendita_appartamenti.txt", ios::out);
    }
    else
    {
        string line;
        if (fappartamenti)
        {
            while (getline(fappartamenti, line ))
            {
                cont = cont + 1;
            }
        }
    }
    fappartamenti.close();
    fappartamenti.open ("vendita_appartamenti.txt", ios::app);
    cout << "Il numero identificativo del nuovo appartamento è: " << (cont / 7)+1 << endl;
    appartamento.cod_id = (cont / 7)+1;
    fappartamenti << "1 " << appartamento.cod_id << endl;
    cout << "Inserisci la via in cui si trova (attenzione: massimo 63 caratteri): ";
    cin.ignore();
    cin.getline (appartamento.via, 64);
    fappartamenti << "2 " << appartamento.via << endl;
    cout << "Inserisci il comune in cui si trova (attenzione: massimo 31 caratteri): ";
    cin.getline (appartamento.comune, 32);
    fappartamenti << "3 " << appartamento.comune << endl;
    do
    {
        cout << "Inserisci il numero di vani dell'appartamento: ";
        cin >>appartamento.num_vani;
        if (appartamento.num_vani<1)
        {
            cout << "Attenzione! Il numero di vani deve essere almeno 1" << endl;
        }
        else
        {
            fappartamenti << "4 " << appartamento.num_vani << endl;
        }
    } while (appartamento.num_vani<1);
    do
    {
        cout << "Inserisci i mq di superficie dell'appartamento: ";
        cin >> appartamento.sup_mq;
        if (appartamento.sup_mq<10)
        {
            cout << "Attenzione! I mq devono essere almeno 10" << endl;
        }
        else
        {
            fappartamenti << "5 " << appartamento.sup_mq<< endl;
        }
    } while (appartamento.sup_mq<10);
    do
    {
        cout << "Inserisci il prezzo dell'appartamento: ";
        cin >> appartamento.prezzo;
        if (appartamento.prezzo<1)
        {
            cout << "Attenzione! Il prezzo deve essere positivo" << endl;
        }
        else
        {
            fappartamenti << "6 " << appartamento.prezzo << endl << endl;
        }
    } while (appartamento.prezzo<1);
    fappartamenti.close();
    return 1;
}

void calcolo_media_minimo_massimo (appartamento_in_vendita& appartamento)
{
    fstream fappartamenti;
    fappartamenti.open("vendita_appartamenti.txt", ios::in);
    if (!fappartamenti)
    {
        cout << "Non esiste il file" << endl;
    }
    else
    {
        int cont = 0;
        string line;
        if (fappartamenti)
        {
            while (getline(fappartamenti, line ))
            {
                cont = cont + 1;
            }
        }
        fappartamenti.close();
        double media = 0;
        int massimo = 0;
        int minimo = INT_MAX;
        int somma = 0;
        int prezzo;
        string tipo;
        char ignora;
        fappartamenti.open("vendita_appartamenti.txt", ios::in);
        while (!fappartamenti.eof())
        {
            // fappartamenti >> tipo;
            getline (fappartamenti, tipo, ' ');
            if (tipo == "6")
            {
                // fappartamenti >> ignora;
                fappartamenti >> prezzo;
                somma = somma + prezzo;
                if (massimo < prezzo)
                {
                    massimo = prezzo;
                }
                if (minimo > prezzo)
                {   
                    minimo = prezzo;
                }
            } 
            else 
            {
               getline (fappartamenti, tipo); 
            }
        }
        media = somma / (cont / 7);
        cout << "La media dei prezzi degli appartamenti inseriti è: " << media << ";" << endl
            << "Il prezzo minimo degli appartamenti è: " << minimo << ";" << endl
            << "Il prezzo massimo deli appartamenti è: " << massimo << ";" << endl;
        fappartamenti.close();
    }
}

void prezzo_medio_tra_soglie_di_sup (appartamento_in_vendita& appartamento, int minimo, int massimo)
{
    fstream fappartamenti;
    fappartamenti.open("vendita_appartamenti.txt", ios::in);
    if (!fappartamenti)
    {
        cout << "Non esiste il file" << endl;
    }
    else
    {
        int somma = 0;
        int cont = 0;
        string tipo;
        while (!fappartamenti.eof())
        {
            getline (fappartamenti, tipo, ' ');
            if (tipo == "5") 
            {
                int superficie;
                fappartamenti >> superficie;
                if (superficie > minimo && superficie < massimo)
                {
                    fappartamenti >> superficie; // Ignora il 6 della riga dopo
                    int prezzo;
                    fappartamenti >> prezzo;
                    somma += prezzo;
                    cont++;
                }
            } 
            else
            {
                getline (fappartamenti, tipo);
            }
        }
        double media = somma / cont;
        cout << "La media dei prezzi degli appartamenti che sono più grandi di " << minimo << " e meno di " << massimo << " è " << media << endl;
    }
}

/*void conta_vani(archivio_appartamenti& appartamento)
{
    if (appartamento.num_appartamento == 0)
    {
        cout << "Non è possibile visualizzare il numero di appartamenti per vani perchè non sono stati registrati appartamenti" << endl;
    }
    else
    {
        int cont[9];
        for (int i = 0; i < 8; i++) {
            cont[i] = 0;
        }
        if (vani > 8) {
            cont[8]++;
        } else {
            cont[nvani - 1]++;
        }
        for (int i = 0; i < 8; i++) {
            if (vani > 8) {
                cout << "8+: " << cont[8] << endl;
            } else {
                cout << i+1 << ": " << cont[i] << endl;
            }
        }
        int cont1 = 0;
        int cont2 = 0;
        int cont3 = 0;
        int cont4 = 0;
        int cont5 = 0;
        int cont6 = 0;
        int cont7 = 0;
        int cont8 = 0;
        int cont8more = 0;
        for (int i=0; i<appartamento.num_appartamento; i++)
        {
            switch (appartamento.nuovo_appartamento[i].num_vani)
            {
                case 1:
                {
                    cont1 = cont1 + 1;
                    break;
                }
                case 2:
                {
                    cont2 = cont2 + 1;
                    break;
                }
                case 3:
                {
                    cont3 = cont3 + 1;
                    break;
                }
                case 4:
                {
                    cont4 = cont4 + 1;
                    break;
                }
                case 5:
                {
                    cont5 = cont5 + 1;
                    break;
                }
                case 6:
                {
                    cont6 = cont6 + 1;
                    break;
                }
                case 7:
                {
                    cont7 = cont7 + 1;
                    break;
                }
                case 8:
                {
                    cont8 = cont8 + 1;
                    break;
                }
                default:
                {
                    cont8more = cont8more + 1;
                }
            }
        }
        cout << "1 vano: " << cont1 << endl
            << "2 vani: " << cont2 << endl
            << "3 vani: " << cont3 << endl
            << "4 vani: " << cont4 << endl
            << "5 vani: " << cont5 << endl
            << "6 vani: " << cont6 << endl
            << "7 vani: " << cont7 << endl
            << "8 vani: " << cont8 << endl
            << "più di 8 vani: " << cont8more << endl;
    }
}

void info_appartamenti_con_n_vani(archivio_appartamenti& appartamento, int n)
{
    int cont = 0;
    if (appartamento.num_appartamento == 0)
    {
        cout << "Non è possibile visualizzare le informazioni degli appartamenti con " << n << " vani perchè non sono stati registrati appartamenti" << endl;
    }
    else
    {
         for (int i=0; i<appartamento.num_appartamento; i++)
         {
             if (appartamento.nuovo_appartamento[i].num_vani == n)
             {
                 cont = cont + 1;
                 cout << endl << "- codice identificativo: " << appartamento.nuovo_appartamento[i].cod_id << ";" << endl
                    << "- via: " << appartamento.nuovo_appartamento[i].via << ";" << endl
                    << "- comune: " << appartamento.nuovo_appartamento[i].comune << ";" << endl
                    << "- superficie: " << appartamento.nuovo_appartamento[i].sup_mq << " mq;" << endl
                    << "- prezzo: " << appartamento.nuovo_appartamento[i].prezzo << ";" << endl << endl;
             }
         }
         if (cont == 0)
         {
             cout << "Non ci sono appartamenti registrati con " << n << " vani" << endl;
         }
    }
}

void informazioni_con_prezzo_tra_soglie(archivio_appartamenti& appartamento, int minimo, int massimo)
{
    int cont = 0;
    if (appartamento.num_appartamento == 0)
    {
        cout << "Non è possibile visualizzare le informazioni dell'appartamento perchè non sono stati registrati appartamenti" << endl;
    }
    else
    {
        for (int i=0; i<appartamento.num_appartamento; i++)
        {
            if (appartamento.nuovo_appartamento[i].prezzo>minimo && appartamento.nuovo_appartamento[i].prezzo<massimo)
            {
                cont = cont + 1;
                 cout << endl << "- codice identificativo: " << appartamento.nuovo_appartamento[i].cod_id << ";" << endl
                    << "- via: " << appartamento.nuovo_appartamento[i].via << ";" << endl
                    << "- comune: " << appartamento.nuovo_appartamento[i].comune << ";" << endl
                    << "- vani: " << appartamento.nuovo_appartamento[i].num_vani << ";" << endl
                    << "- superficie: " << appartamento.nuovo_appartamento[i].sup_mq << " mq;" << endl
                    << "- prezzo: " << appartamento.nuovo_appartamento[i].prezzo << " euro;" << endl << endl;
                    
             }
         }
         if (cont == 0)
         {
             cout << "Non ci sono appartamenti registrati con il prezzo compreso tra le due soglie inserite" << endl;
         }
    }
}*/

int main()
{
    appartamento_in_vendita appartamento;
    int continua = 1;
    int scelta = 0;
    do
    {
        cout << endl << "Opzioni disponibili:" << endl
            << "1 - inserimento di un nuovo appartamento;" << endl
            << "2 - visualizzazione del prezzo medio, minimo e massimo;" << endl
            << "3 - visualizzazione del prezzo medio con superficie compresa tra due soglie;" << endl
            << "4 - visualizzazione dei numeri di: monolocali, bilocali, trilocali, di 4, 5, 6, 7, 8 vani e con più di 8 vani;" << endl
            << "5 - visualizzazioni informazioni di appartamento con n vani;" << endl
            << "6 - visualizzazione informazioni appartamenti il cui prezzo è compreso tra due soglie;" << endl
            << "7 - esci;" << endl << endl
            << "Numero scelta: "; 
        cin >> scelta;
        cout << endl;
        switch (scelta)
        {
            case 1:
            {
                if (inserimento_appartamento(appartamento))
                {
                    cout << "Appartamento inserito con successo!" << endl;
                }
                else
                {
                    cout << "E' già stato inserito il numero massimo di appartamento!" << endl;
                }
                break;
            }
            case 2:
            {
                calcolo_media_minimo_massimo (appartamento);
                break;
            }
            case 3:
            {
                int sup_minima = 0;
                int sup_massima = 0;
                do
                {
                    cout << "Inserisci la soglia della superficie minima: ";
                    cin >> sup_minima;
                    if (sup_minima < 10)
                    {
                        cout << "Attenzione! Devi inserire una superficie maggiore di 10 mq" << endl;
                    }
                    else
                    {
                        do
                        {
                            cout << "Inserisci la soglia della superficie massima: ";
                            cin >> sup_massima;
                            if (sup_massima<sup_minima)
                            {
                                cout << "Attenzione! Devi inserire una superficie superiore al minimo inserito." << endl
                                    << "Ti ricordo che la soglia minima inserita è: " << sup_minima << endl;
                            }
                            else
                            {
                                prezzo_medio_tra_soglie_di_sup (appartamento, sup_minima, sup_massima);
                            }
                        } while (sup_massima<sup_minima);
                    }
                } while (sup_minima < 0);
                break;
            }
            case 4:
            {
                //conta_vani(appartamento);
                break;
            }
            case 5:
            {
                /*int n = 0;
                do 
                {
                    cout << "Inserisci il numero di vani: ";
                    cin >> n;
                    if (n < 1)
                    {
                        cout << "Attenzione: i numeri di vani devono essere almeno 1" << endl;
                    }
                    else
                    {
                        info_appartamenti_con_n_vani(appartamento, n);
                    } 
                } while (n < 1);
                */break;
            }
            case 6:
            {
                /*int prezzo_minimo = 0;
                int prezzo_massimo = 0;
                do
                {
                    cout << "Inserisci la soglia del prezzo minimo: ";
                    cin >> prezzo_minimo;
                    if (prezzo_minimo < 1)
                    {
                        cout << "Attenzione! Devi inserire un prezzo maggiore di 0" << endl;
                    }
                    else
                    {
                        do
                        {
                            cout << "Inserisci la soglia del prezzo massimo: ";
                            cin >> prezzo_massimo;
                            if (prezzo_massimo<prezzo_minimo)
                            {
                                cout << "Attenzione! DEvi inserire un prezzo superiore al minimo inserito." << endl
                                    << "Ti ricordo che la soglia minima inserita è: " << prezzo_minimo << endl;
                            }
                            else
                            {
                                informazioni_con_prezzo_tra_soglie(appartamento, prezzo_minimo, prezzo_massimo);
                            }
                        } while (prezzo_massimo<prezzo_minimo);
                    }
                } while (prezzo_minimo < 0);
                */break;
            }
            case 7:
            {
                continua = 0;
                break;
            }
            default:
            {
                cout << "Attenzione, opzione scelta non disponibile" << endl;
            }
        }
    }while (continua == 1);
}