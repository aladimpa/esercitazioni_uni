#include <iostream>
#include <cstring>
using namespace std;

/* codice prodotto           _id (numero intero)
    descrizione prodotto    _descr (stringa) (puntatore)
    num pezzi ordinati      _numpz (num intero)
    costo unitario          _costounit (num reale)

    Metodi: costruttore di default
            costruttore di paramentri
            costruttore di copia
            distruttore
            selettori
            modificatori
            inserire una riga d'ordine
            calcolare il costo totale
            stampare riga d'ordine incluso il costo totale
*/

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
        delete[] _descr;
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