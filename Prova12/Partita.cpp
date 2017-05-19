// Bisogna ripetere gli include e includere la definizione della classe
#include "Partita.h"
#include <iostream>
#include <cstring>
using namespace std;

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

Partita::Partita(const Partita& p) : _data(p._data)
{
    // _data = Data(p._data); -> sostituita dalla lista di inizializzazione
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
    // Visto che in tutti i costruttori _squadra[0] = new char[qualcosa] non possono essere NULL
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
    if (n==1)
        return _ngoal[0];
    else
        return _ngoal[1];
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