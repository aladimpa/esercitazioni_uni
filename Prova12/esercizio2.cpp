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
    delete[] _squadra[0];
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
    char nome1[32];
    cout << "Squadra 1: ";
    cin >> nome1;
    delete[] _squadra[0];
    int dim1= strlen(nome1);
    _squadra[0] = new char[dim1+1];
    strcpy(_squadra[0], nome1);
    char nome2[32];
    cout << "Squadra 2: ";
    cin >> nome2;
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

}
void Partita::copia_partita(Partita& partita)
{

}