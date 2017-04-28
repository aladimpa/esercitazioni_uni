#include <iostream>
#include <cstring>
using namespace std;

class Data
{
    public:
            Data();
            Data(int gg, int mm, int aa);
            Data(const Data& data);
            ~Data();
            int getG() const;
            int getM() const;
            int getA() const;
            void setG(int gg);
            void setM(int mm);
            void setA(int aa);
            void inserisci_data();
            void stampa_data();
            void copia_data(Data& data);
    private:
            int _giorno;
            int _mese;
            int _anno;
            int max(int mese, int anno);
};

Data::Data()
{
    _giorno = 1;
    _mese = 1;
    _anno = 1700;
}

int Data::max( int mese, int anno)
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
    return numgiorni;
}

Data::Data(int gg, int mm, int aa)
{
    if ((mm>0)&&(mm<13))
    {
        _mese = mm;
    }
    else
    {
        _mese = 1;
    }
    if (aa>1699)
    {
        _anno = aa;
    }
    else
    {
        _anno = 1700;
    }
    int giorni = max(mm, aa);
    if ((gg>0)&&(gg<=giorni))
    {
        _giorno = gg;
    }
    else
    {
        _giorno = 1;
    }
}

Data::Data(const Data& data)
{
    if ((data._mese>0)&&(data._mese<13))
    {
        _mese = data._mese;
    }
    else
    {
        _mese = 1;
    }
    if (data._anno>1699)
    {
        _anno = data._anno;
    }
    else
    {
        _anno = 1700;
    }
    int giorni = max(data._mese, data._anno);
    if ((data._giorno>0)&&(data._giorno<=giorni))
    {
        _giorno = data._giorno;
    }
    else
    {
        _giorno = 1;
    }
}
Data::~Data()
{

}

int Data::getG() const
{
    return _giorno;
}

int Data::getM() const
{
    return _mese;
}

int Data::getA() const
{
    return _anno;
}

void Data::setG(int gg)
{
    int giorno = max(_mese, _anno);
    if ((gg>0)&&(gg<=giorno))
    {
        _giorno = gg;
    }
    else
    {
        _giorno = 1;
    }
}

void Data::setM(int mm)
{
    if ((mm>0)&&(mm<13))
    {
        _mese = mm;
    }
    else 
    {
        _mese = 1;
    }
}

void Data::setA(int aa)
{
    if ((aa>0)&&(aa<13))
    {
        _anno = aa;
    }
    else 
    {
        _anno = 1;
    }
}

void Data::inserisci_data()
{
    cout << "Inserimento data" << endl;
    cout << "Inserisci l'anno: ";
    do 
    {
        cin >> _anno;
        if (_anno<1700)
        {
            cout << "Dato scorretto, inserire nuovamente l'anno" <<endl;
        }
    } while(_anno<1700);
    cout << "Inserisci il mese: ";
    do 
    {
        cin >> _mese;
        if ((_mese<1)||(_mese>12))
        {
            cout << "Dato scorretto, inserire nuovamente il mese" <<endl;
        }
    } while((_mese<1)||(_mese>12));
    cout << "Inserisci il giorno: ";
    int giorno = max(_mese, _anno);
    do 
    {
        cin >> _giorno;
        if ((_giorno<1)||(_giorno>giorno))
        {
            cout << "Dato scorretto, inserire nuovamente il giorno" <<endl;
        }
    } while((_giorno<1)||(_giorno>giorno));
}

void Data::stampa_data()
{
    cout << _giorno << "/" << _mese << "/" << _anno << endl;
}

void Data::copia_data(Data& data)
{
    if ((data._mese>0)&&(data._mese<13))
    {
        _mese = data._mese;
    }
    else
    {
        _mese = 1;
    }
    if (data._anno>1699)
    {
        _anno = data._anno;
    }
    else
    {
        _anno = 1700;
    }
    int giorni = max(data._mese, data._anno);
    if ((data._giorno>0)&&(data._giorno<=giorni))
    {
        _giorno = data._giorno;
    }
    else
    {
        _giorno = 1;
    }
}

class Partita
{
    public:
            Partita();
            Partita(Data data, char squadra1[], char squadra2[], int ngoal1, int ngoal2, int nes, int nam);
            Partita(const Partita& p);
            ~Partita();
            Data getData() const;
            const char* getSquadra(int n) const;
            int getNgoal(int n) const;
            int getNespulsi() const;
            int getNammoniti() const;
            void setData(Data data);
            void setSquadra(char squadra1[], char squadra2[]);
            void setNgoal(int n1, int n2);
            void setNespulsi(int espulsi);
            void setNammoniti(int ammoniti);
            void inserisci_partita();
            void stampa_partita();
            void copia_partita(Partita& partita);
    private:
            Data _data;
            char* _squadra[2];
            int _ngoal[2];
            int _nespulsi;
            int _nammoniti;
};

Partita::Partita()
{
    _data = Data();
    _squadra[0] = new char[9];
    strcpy(_squadra[0], "Squadra1");
    _squadra[1] = new char[9];
    strcpy(_squadra[1], "Squadra2");
    _ngoal[0] = 0;
    _ngoal[1] = 0;
    _nespulsi = 0;
    _nammoniti = 0;
}

Partita::Partita(Data data, char squadra1[], char squadra2[], int ngoal1, int ngoal2, int nes, int nam)
{
    _data = Data(data);
    int dim1 = strlen(squadra1);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], squadra1);
    int dim2 = strlen(squadra2);
    _squadra[1] = new char[dim2+1];
    strcpy(_squadra[1], squadra2);
    if (ngoal1 < 0)
    {
        _ngoal[0] = 0;
    }
    else
    {
        _ngoal[0] = ngoal1;
    }
    if (ngoal2 < 0)
    {
        _ngoal[1] = 0;
    }
    else
    {
        _ngoal[1] = ngoal2;
    }
    if (nes < 0)
    {
        _nespulsi = 0;
    }
    else
    {
        _nespulsi = nes;
    }
    if (nam < 0)
    {
        _nammoniti = 0;
    }
    else
    {
        _nammoniti = nam;
    }
}

Partita::Partita(const Partita& p)
{
    delete[] _squadra[0];
    delete[] _squadra[1];
    _data = Data(p._data);
    int dim1 = strlen(p._squadra[0]);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], p._squadra[0]);
    int dim2 = strlen(p._squadra[1]);
    _squadra[1] = new char[dim2+1];
    strcpy(_squadra[1], p._squadra[1]);
    if (p._ngoal[0] < 0)
    {
        _ngoal[0] = 0;
    }
    else
    {
        _ngoal[0] = p._ngoal[0];
    }
    if (p._ngoal[1] < 0)
    {
        _ngoal[1] = 0;
    }
    else
    {
        _ngoal[1] = p._ngoal[1];
    }
    if ( p._nespulsi< 0)
    {
        _nespulsi = 0;
    }
    else
    {
        _nespulsi = p._nespulsi;
    }
    if (p._nammoniti < 0)
    {
        _nammoniti = 0;
    }
    else
    {
        _nammoniti = p._nammoniti;
    }
}

Partita::~Partita()
{
    if (_squadra[0] != NULL)
        delete[] _squadra[0];
    if (_squadra[1] != NULL)
        delete[] _squadra[1];
}

Data Partita::getData() const
{
    return _data;
}

const char* Partita::getSquadra(int n) const
{
    if (n==1)
    {
        return _squadra[0];
    }
    else
    {
        return _squadra[1];
    }
}

int Partita::getNgoal(int n) const
{
    (n==1) ? _ngoal[0] : _ngoal[1];
}

int Partita::getNespulsi() const
{
    return _nespulsi;
}

int Partita::getNammoniti() const
{
    return _nammoniti;
}

void Partita::setData(Data data)
{
    _data = Data(data);
}

void Partita::setSquadra(char squadra1[], char squadra2[])
{
    delete[] _squadra[0];
    delete[] _squadra[1];
    int dim1 = strlen(squadra1);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], squadra1);
    int dim2 = strlen(squadra2);
    _squadra[1] = new char[dim2+1];
    strcpy(_squadra[1], squadra2);
}

void Partita::setNgoal(int n1, int n2)
{
    (n1<0)? _ngoal[0]=0 : _ngoal[0]=n1;
    (n2<0)? _ngoal[1]=0 : _ngoal[1]=n2;
}
void Partita::setNespulsi(int espulsi)
{
    (espulsi<0) ? _nespulsi=0 : _nespulsi=espulsi;
}

void Partita::setNammoniti(int ammoniti)
{
    (ammoniti<0) ? _nammoniti=0 : _nammoniti=ammoniti;
}
void Partita::inserisci_partita()
{
    cout << "Inserimento partita" << endl;
    _data.inserisci_data();
    char nome1[32];
    cout << "Squadra 1: ";
    cin >> nome1;
    if (_squadra[0] != NULL)
        delete[] _squadra[0];
    int dim1= strlen(nome1);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], nome1);
    char nome2[32];
    cout << "Squadra 2: ";
    cin >> nome2;
    if (_squadra[1] != NULL)
        delete[] _squadra[1];
    int dim2= strlen(nome2);
    _squadra[1] = new char[dim2+1];
    strcpy(_squadra[1], nome2);
    cout << "Inserisci il numero di goal della squadra " << _squadra[0] << ": ";
    do
    {
        cin >> _ngoal[0];
        if (_ngoal[0]<0)
        {
            cout << "Dato incorretto. Inserire nuovamente" << endl;
        }
    } while (_ngoal[0]<0);
    cout << "Inserisci il numero di goal della squadra " << _squadra[1] << ": ";
    do
    {
        cin >> _ngoal[1];
        if (_ngoal[1]<0)
        {
            cout << "Dato incorretto. Inserire nuovamente" << endl;
        }
    } while (_ngoal[1]<0);
    cout << "Inserisci il numero totale degli espulsi: ";
    do
    {
        cin >> _nespulsi;
        if (_nespulsi<0)
        {
            cout << "Dato incorretto. Inserire nuovamente" << endl;
        }
    } while (_nespulsi < 0);
    cout << "Inserisci il numero totale degli ammoniti: ";
    do
    {
        cin >> _nammoniti;
        if (_nammoniti<0)
        {
            cout << "Dato incorretto. Inserire nuovamente" << endl;
        }
    } while (_nammoniti < 0);
}

void Partita::stampa_partita()
{
    cout << "Partita: " << endl;
    cout << _squadra[0] << " vs " << _squadra[1] << " ";
    _data.stampa_data();
    cout << _ngoal[0] << "-" << _ngoal[1] << endl;
    cout << "Ammoniti: " << _nammoniti << endl;
    cout << "Espulsi: " << _nespulsi << endl;
}
void Partita::copia_partita(Partita& partita)
{
    delete[] _squadra[0];
    delete[] _squadra[1];
    _data.copia_data(partita._data);
    int dim1 = strlen(partita._squadra[0]);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], partita._squadra[0]);
    int dim2 = strlen(partita._squadra[1]);
    _squadra[1] = new char[dim2+1];
    strcpy(_squadra[1], partita._squadra[1]);
    if (partita._ngoal[0] < 0)
    {
        _ngoal[0] = 0;
    }
    else
    {
        _ngoal[0] = partita._ngoal[0];
    }
    if (partita._ngoal[1] < 0)
    {
        _ngoal[1] = 0;
    }
    else
    {
        _ngoal[1] = partita._ngoal[1];
    }
    if ( partita._nespulsi< 0)
    {
        _nespulsi = 0;
    }
    else
    {
        _nespulsi = partita._nespulsi;
    }
    if (partita._nammoniti < 0)
    {
        _nammoniti = 0;
    }
    else
    {
        _nammoniti = partita._nammoniti;
    }
}

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
            Partita* _archivio;
            int _n;
};

ArchivioPartite::ArchivioPartite()
{
    _n = 0;
    _archivio = new Partita[100];
}

ArchivioPartite::ArchivioPartite(const ArchivioPartite& ap)
{
    if (_archivio != NULL)
    {
        delete[] _archivio;
    }
    if ((ap._n>0)&&(ap._n<=101))
    {
        _n = ap._n;
        _archivio = new Partita[100];
        for (int i=0; i<ap._n; i++)
        {
            _archivio[i] = Partita(ap._archivio[i]);
        }
    }
    else
    {
        _n = 0;
        _archivio = new Partita[100];
    }
}

ArchivioPartite::~ArchivioPartite()
{
    if (_archivio != NULL)
    {
        delete[] _archivio;
    }
}

void ArchivioPartite::inserisci_partita()
{
    _archivio[_n].inserisci_partita();
    _n++;
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
    ap.partita_dato_indice(0).stampa_partita();
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
                    tot = tot + ap.partita_dato_indice(i).getNgoal(1);
                    tot = tot + ap.partita_dato_indice(i).getNgoal(2);
                }
                cout << "Goal totali: " << tot << endl;
                break;
            }
            case 3: 
            {
                int max = 0;
                for (int i=0; i < ap.n_partite_archivio(); i++ )
                {
                    int somma = ap.partita_dato_indice(i).getNgoal(1) + ap.partita_dato_indice(i).getNgoal(2);
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
                        tot = tot + ap.partita_dato_indice(i).getNespulsi();
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
                        tot = tot + ap.partita_dato_indice(i).getNammoniti();
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
                    cout << "Inserisci il mese in numero (1-12: ";
                    cin >> mese;
                    if ((mese>0)&&(mese<13))
                    {
                        int mesep;
                        for (int i=0; i < ap.n_partite_archivio(); i++ )
                        {
                            mesep = ap.partita_dato_indice(i).getData().getM();
                            if (mese == mesep)
                            {
                                ap.partita_dato_indice(i).stampa_partita();
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