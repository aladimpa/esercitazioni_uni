#include <iostream>
#include <cstring>
using namespace std;

class RigaOrdine
{
    public:
            RigaOrdine();
            RigaOrdine( int id, char descr[], int numpz, double costounit);
            RigaOrdine(const RigaOrdine& ro);
            ~RigaOrdine();
            int getId() const;
            const char* getDescr() const;
            int getNumpz() const;
            double getCostoUnit() const;
            void setId( int id);
            void setDescr( char descr[] );
            void setNumpz( int numpz );
            void setCostoUnit (double costounit);
            void inserisci_rigaOrdine(); // è un modifica di tutto
            double calcola();// sostanzialmente è un selettore
            void stampa();
    private:
            int _id;
            char* _descr;
            int _numpz;
            double _costounit;
};

RigaOrdine::RigaOrdine()
{
    _id = 0;
    _descr = NULL;
    _numpz = 0;
    _costounit = 0.0;
}

RigaOrdine::RigaOrdine(int id, char descr[], int numpz, double costounit)
{
    if (numpz > 0)
    {
        _id = id;
        int n = strlen(descr);
        _descr = new char[n+1];
        strcpy(_descr, descr);
        _numpz = numpz;
        _costounit = costounit;
    }
    else
    {
        _id = 0;
        _descr = NULL;
        _numpz = 0;
        _costounit = 0.0;
    }
}

RigaOrdine::RigaOrdine(const RigaOrdine& ro)
{
    if (_descr != NULL)
    {
        delete[] _descr;    // me lo deve spiegare
    }
    if (ro._numpz > 0)
    {
        _id = ro._id;
        int n = strlen(ro._descr);
        _descr = new char[n+1];
        strcpy(_descr, ro._descr);
        _numpz = ro._numpz;
        _costounit = ro._costounit;
    }
    else
    {
        _id = 0;
        _descr = NULL;
        _numpz = 0;
        _costounit = 0.0;
    }
}

RigaOrdine::~RigaOrdine()
{
    if (_descr != NULL)
        delete[] _descr;
}

int RigaOrdine::getId() const
{
    return _id;
}

const char* RigaOrdine::getDescr() const
{
    return _descr;
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

class Ordine
{
    public:
            Ordine();
            Ordine( int ido, char nome[], char cognome[], char indirizzo[], char cf[], RigaOrdine* rgo[], int n);
            Ordine( const Ordine& ord);
            ~Ordine();
            int getIdo() const;
            const char* getNome() const;
            const char* getCognome() const;
            const char* getIndirizzo() const;
            const char* getCF() const;
            RigaOrdine** getRigheordine() const;
            int getN() const;
            void setIdo(int ido);
            void setNome(char nome[]);
            void setCognome(char cognome[]);
            void setIndirizzo (char indirizzo[]);
            void setCF(char cf[]);
            void setRigheordine(RigaOrdine* righeordine[]);
            void setN(int n);
            void inserisci();
            RigaOrdine* datoindice(int indice);
            RigaOrdine* datoid(int id);
            double calcola();
            void stampa();
    private:
            int _ido;
            char* _nome;
            char* _cognome;
            char* _indirizzo;
            char* _cf;
            RigaOrdine** _righeordine;
            int _n;
};

Ordine::Ordine()
{
    _ido = 0;
    _nome = NULL;
    _cognome = NULL;
    _indirizzo = NULL;
    _cf = NULL;
    _righeordine = NULL;
    _n = 0;
}

Ordine::Ordine(int ido, char nome[], char cognome[], char indirizzo[], char cf[], RigaOrdine* rgo[], int n)
{
    _ido = ido;
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
    _righeordine = new RigaOrdine*[n];
    for (int i=0; i<n; i++)
    {
        _righeordine[i] = rgo[i];
    }
    _n = n;
}

Ordine::Ordine(const Ordine & ord)
{
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
    _ido = ord._ido;
    int dim = strlen(ord._nome);
    _nome = new char[dim+1];
    strcpy(_nome, ord._nome);
    int dim1 = strlen(ord._cognome);
    _cognome = new char[dim1+1];
    strcpy(_cognome, ord._cognome);
    int dim2 = strlen(ord._indirizzo);
    _indirizzo = new char[dim2+1];
    strcpy(_indirizzo, ord._indirizzo);
    if (strlen(ord._cf)==16)
    {
        _cf = new char[17];
        strcpy(_cf, ord._cf);
    }
    else _cf = NULL;
    _righeordine = new RigaOrdine*[ord._n];
    for (int i=0; i<ord._n; i++)
    {
        _righeordine[i] = ord._righeordine[i];
    }
    _n = ord._n;
}

Ordine::~Ordine()
{
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

int Ordine::getIdo() const
{
    return _ido;
}

const char* Ordine::getNome() const
{
    return _nome;
}

const char* Ordine::getCognome() const
{
    return _cognome;
}

const char* Ordine::getIndirizzo() const
{
    return _indirizzo;
}

const char* Ordine::getCF() const
{
    return _cf;
}

 RigaOrdine** Ordine::getRigheordine() const
{
    if (_n == 0)
    {
        return NULL;
    }
    else
    {
        return _righeordine;
    }
}

int Ordine::getN() const
{
    return _n;
}

void Ordine::setIdo(int ido)
{
    _ido = ido;
}

void Ordine::setNome(char nome[])
{
    if (_nome != NULL)
    {
        delete[] _nome;
    }
    int dim = strlen(nome);
    _nome = new char[dim+1];
    strcpy(_nome, nome);
}

void Ordine::setCognome(char cognome[])
{
    if (_cognome != NULL)
    {
        delete[] _cognome;
    }
    int dim = strlen(cognome);
    _cognome = new char[dim+1];
    strcpy(_cognome, cognome);
}

void Ordine::setIndirizzo(char indirizzo[])
{
    if (_indirizzo != NULL)
    {
        delete[] _indirizzo;
    }
    int dim = strlen(indirizzo);
    _indirizzo = new char[dim+1];
    strcpy(_indirizzo, indirizzo);
}

void Ordine::setCF(char cf[])
{
    if (_cf != NULL)
    {
        delete[] _cf;
    }
    int dim = strlen(cf);
    if (dim == 16)
    {
        _cf = new char[dim+1];
        strcpy(_cf, cf);
    }
    else _cf = NULL;
}

void Ordine::setRigheordine(RigaOrdine* righeordine[])
{
    if (_n==0 )
    {
        cout << "Il modificatore setRigheOrine non è stato chiamato correttamente" << endl;
    }
    else
    {
        for(int i=0; i<_n; i++)
        {
            _righeordine[i] = righeordine[i];
        }
    }
}

void Ordine::setN(int n)
{
    _n = n;
}

void Ordine::inserisci()
{
    bool ok = false;
    for (int i=0; i<_n; i++)
    {
        if (_righeordine[i]!=NULL)
        {
            _righeordine[i]->inserisci_rigaOrdine();
            ok = true;
        }
    }
    if (!ok)
    {
        RigaOrdine** _righeordinevecchio = new RigaOrdine*[_n];
        for (int j=0; j<_n; j++)
        {
            _righeordinevecchio[j]=_righeordine[j];
        }
        _righeordine = new RigaOrdine*[_n+_n];
        for (int x=0; x<_n; x++)
        {
            _righeordine[x] = _righeordinevecchio[x];
        }
        delete[] _righeordinevecchio;
        _righeordine[_n+1]->inserisci_rigaOrdine();
        _n= _n+_n;
    }
}

RigaOrdine* Ordine::datoindice(int indice)
{
    if(_righeordine[indice] == NULL)
    {
        return NULL;
    }
    else 
    {
        return _righeordine[indice];
    }

}

RigaOrdine* Ordine::datoid(int id)
{
    for (int i=0; i < _n; i++)
    {
        if(_righeordine[i]->getId() == id)
        {
            return _righeordine[i];
        }
    }
    return NULL;
}

double Ordine::calcola()
{
    double somma = 0.0;
    for (int i=0; i < _n; i++)
    {
        somma += _righeordine[i]->calcola();
    }
    return somma;
}
void Ordine::stampa()
{
    cout << "Ordine " << _ido 
        << " di " << _nome << " " << _cognome
        << " " << _cf << endl << _indirizzo << endl;
    for (int i=0; i < _n; i++)
    {
        _righeordine[i]->stampa();
    }
}

int main()
{
    return 0;
}