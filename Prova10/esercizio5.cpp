#include <iostream>
#include <cstring>
using namespace std;

class O

class RigaOrdine
{
    public:
            RigaOrdine();
            RigaOrdine( int id, char nome[], char cognome[], char indizirro[], char cf[], char descr[], int numpz, double costounit, int rgo[]);
            RigaOrdine(const RigaOrdine& ro);
            ~RigaOrdine();
            int getId() const;
            const char* getNome() const;
            const char* getCognome() const;
            const char* getIndirizzo() const;
            const char* getCF() const;
            const char* getDescr() const;
            int getNumpz() const;
            double getCostoUnit() const;
            const int* getRgo() const;
            void setId( int id);
            void setNome( char nome[] );
            void setCognome( char cognome[] );
            void setIndirizzo( char indirizzo[] );
            void setCF( char cf[] );
            void setDescr( char descr[] );
            void setNumpz( int numpz );
            void setCostoUnit (double costounit);
            void inserisci_rigaOrdine(); // è un modifica di tutto
            double calcola();// sostanzialmente è un selettore
            void stampa();
    private:
            int _id;
            char* _nome;
            char* _cognome;
            char* _indirizzo;
            char* _cf;
            char* _descr;
            int _numpz;
            double _costounit;
            int* _rgo;
};

RigaOrdine::RigaOrdine()
{
    _id = 0;
    _nome = NULL;
    _cognome = NULL;
    _indirizzo = NULL;
    _cf = NULL;
    _descr = NULL;
    _numpz = 0;
    _costounit = 0.0;
    _rgo = new int[5];
    for (int i=0; i<5; i++)
    {
        _rgo[i] = NULL;
    }
}

RigaOrdine::RigaOrdine(int id, char nome[], char cognome[], char indizirro[], char cf[], char descr[], int numpz, double costounit, int rgo[])
{
    if (numpz > 0)
    {
        _id = id;
        int dim = strlen(nome);
        _nome = new char[dim+1];
        strcpy(_nome, nome);
        int dim1 = strlen(cognome);
        _cognome = new char[dim1+1];
        strcpy(_cognome, cognome);
        int dim2 = strlen(indirizzo);
        _indirizzo = new char[dim2+1];
        strcpy(_indirizzo, indirizzo);
        if (strlen(cf)==16)
        {
            _cf = new char[17];
            strcpy(_cf, cf);
        }
        else _cf = NULL;
        int n = strlen(descr);
        _descr = new char[n+1];
        strcpy(_descr, descr);
        _numpz = numpz;
        _costounit = costounit;
        rgo 
    }
    else
    {
        _id = 0;
        _nome = NULL;
        _cognome = NULL;
        _indirizzo = NULL;
        _cf = NULL;
        _descr = NULL;
        _numpz = 0;
        _costounit = 0.0;
        _rgo = new int[5];
        for (int i=0; i<5; i++)
        {
            _rgo[i] = NULL;
        }
    }
}

RigaOrdine::RigaOrdine(const RigaOrdine& ro)
{
    if (_descr != NULL)
    {
        delete[] _descr;
    }
    if (_nome != NULL)
    {
        delete[] _nome;
    }
    if (_cognome != NULL)
    {
        delete[] _cognome;
    }
    if (_indirizzo != NULL)
    {
        delete[] _indirizzo;
    }
    if (_cf != NULL)
    {
        delete[] _cf;
    }
    if (ro._numpz > 0)
    {
        _id = ro._id;
        int dim = strlen(ro._nome);
        _nome = new char[dim+1];
        strcpy(_nome, ro._nome);
        int dim1 = strlen(ro._cognome);
        _cognome = new char[dim1+1];
        strcpy(_cognome, ro._cognome);
        int dim2 = strlen(ro._indirizzo);
        _indirizzo = new char[dim2+1];
        strcpy(_indirizzo, ro._indirizzo);
        if (strlen(cf)==16)
        {
            _cf = new char[17];
            strcpy(_cf, ro._cf);
        }
        else _cf = NULL;
        int n = strlen(ro._descr);
        _descr = new char[n+1];
        strcpy(_descr, ro._descr);
        _numpz = ro._numpz;
        _costounit = ro._costounit;
    }
    else
    {
        _id = 0;
        _nome = NULL;
        _cognome = NULL;
        _indirizzo = NULL;
        _cf = NULL;
        _descr = NULL;
        _numpz = 0;
        _costounit = 0.0;
        _rgo = new int[5];
        for (int i=0; i<5; i++)
        {
            _rgo[i] = NULL;
        }
    }
}

RigaOrdine::~RigaOrdine()
{
    if (_descr != NULL)
    {
        delete[] _descr;
    }
    if (_nome != NULL)
    {
        delete[] _nome;
    }
    if (_cognome != NULL)
    {
        delete[] _cognome;
    }
    if (_indirizzo != NULL)
    {
        delete[] _indirizzo;
    }
    if (_cf != NULL)
    {
        delete[] _cf;
    }
}

int RigaOrdine::getId() const
{
    return _id;
}

const char* RigaOrdine::getDescr() const
{
    return _descr;
}

const char* RigaOrdine::getNome() const
{
    return _nome;
}

const char* RigaOrdine::getCognome() const
{
    return _cognome;
}

const char* RigaOrdine::getIndirizzo() const
{
    return _indirizzo;
}

const char* RigaOrdine::getCF() const
{
    return _cf;
}

int RigaOrdine::getNumpz() const
{
    return _numpz;
}

double RigaOrdine::getCostoUnit() const
{
    return _costounit;
}

void RigaOrdine::setId(int id)
{
    _id = id;
}

void RigaOrdine::setNome(char nome[])
{
    if (_nome != NULL)
    {
        delete[] _nome;
    }
    int dim = strlen(nome);
    _nome = new char[dim+1];
    strcpy(_nome, nome);
}

void RigaOrdine::setCognome(char cognome[])
{
    if (_cognome != NULL)
    {
        delete[] _cognome;
    }
    int dim = strlen(cognome);
    _cognome = new char[dim+1];
    strcpy(_cognome, cognome);
}

void RigaOrdine::setIndirizzo(char indirizzo[])
{
    if (_indirizzo != NULL)
    {
        delete[] _indirizzo;
    }
    int dim = strlen(indirizzo);
    _indirizzo = new char[dim+1];
    strcpy(_indirizzo, indirizzo);
}

void RigaOrdine::setCF(char cf[])
{
    if (_cf != NULL)
    {
        delete[] _cf;
    }
    int dim = strlen(cf);
    _cf = new char[dim+1];
    strcpy(_cf, cf);
}

void RigaOrdine::setDescr(char descr[])
{
    if (_descr != NULL)
    {
        delete[] _descr;
    }
    int n = strlen(descr);
    _descr = new char[n+1];
    strcpy(_descr, descr);
}

void RigaOrdine::setNumpz(int numpz)
{
    _numpz = numpz;
}

void RigaOrdine::setCostoUnit(double costounit)
{
    _costounit = costounit;
}

double RigaOrdine::calcola()
{
    return (_costounit*_numpz);
}

void RigaOrdine::inserisci_rigaOrdine()
{
    cout << "Inserisci codice identificativo dell'ordine" << endl << "Id: ";
    cin >> _id;
    cout << "Inserisci descrizione (max 511 caratteri)" << endl << "Descrizione: ";
    char descrizione[512];
    cin >> descrizione;
    if (_descr != NULL)
    {
        delete[] _descr;    // me lo deve spiegare
    }
    int n = strlen(descrizione);
    _descr = new char[n+1];
    strcpy(_descr, descrizione);
    cout << "Inserisci numero pezzi" << endl;
    do
    {
        cout << "Numero: ";
        cin >> _numpz;
        if (_numpz < 1)
        {
            cout << "Inserito dato invalido, prego inserire nuovamente" << endl;
        }
    } while(_numpz < 1);
    cout << "Inserisci costo" << endl;
    do
    {
        cout << "Costo unitario: ";
        cin >> _costounit;
        if (_costounit < 1)
        {
            cout << "Inserito dato invalido, prego inserire nuovamente" << endl;
        }
    } while(_costounit < 1);
}

void RigaOrdine::stampa()
{
    cout << "Il codice identificativo è: " << _id << endl;
    if (_descr != NULL)
    {
        cout << "La descrizione è: " << _descr << endl;        
    }
    cout << "Il numero di prodotti è: " << _numpz << endl;
    cout << "Il costo unitario è: " << _costounit << endl;
    cout << "Il prezzo finale è: " << calcola() << endl;
}

int main()
{
    RigaOrdine x;
    x.stampa();
    x.inserisci_rigaOrdine();
    x.stampa();
    return 0;
}