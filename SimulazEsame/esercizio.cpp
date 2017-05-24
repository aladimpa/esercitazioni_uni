#include <iostream>
using namespace std;

class ComparaPrezzi
{
    public:
        ComparaPrezzi();
        ComparaPrezzi( int id, int n, double prezzi[]);
        ComparaPrezzi( const ComparaPrezzi& c);
        ~ComparaPrezzi();
        int getId() const;
        int getN() const;
        const double* getP() const;
        void setId(int id);
        void setP (double p[]);
        double calcolaPrezzoMinMax( double& max) const;
        friend istream& operator>>(istream& is, ComparaPrezzi& c);
    private:
        int _id;
        int _n;
        double* _p;
};

ComparaPrezzi::ComparaPrezzi()
{
    _id = 0;
    _n = 0;
    _p = NULL;
}

ComparaPrezzi::ComparaPrezzi(int id, int n, double prezzi[])
{
    if (n>=0)
    {
        _n = n;
        _id = id;
        _p = new double[n];
        for (int i=0; i<n; i++)
        {
            _p[i] = prezzi[i];;
        }
    }
    else
    {
        cout << "Errore: n invalido" << endl;
        _id = 0;
        _n = 0;
        _p = NULL;
    }

}

ComparaPrezzi::ComparaPrezzi(const ComparaPrezzi& c)
{
    if (_p != NULL)
    {
        _p = NULL;
    }
    if (c._n>=0)
    {
        _n = c._n;
        _id = c._id;
        _p = new double[c._n];
        for (int i=0; i<c._n; i++)
        {
            _p[i] = c._p[i];
        }
    }
    else
    {
        cout << "Errore: n invalido" << endl;
        _id = 0;
        _n = 0;
        _p = NULL;
    }
}

ComparaPrezzi::~ComparaPrezzi()
{
    if (_p != NULL)
    {
        _p = NULL;
    }
}

int ComparaPrezzi::getId() const
{
    return _id;
}
        
int ComparaPrezzi::getN() const
{
    return _n;
}
        
const double* ComparaPrezzi::getP() const
{
    return _p;
}

void ComparaPrezzi::setId(int id)
{
    if (_id <0)
    {
        _id = id;
    }
}

void ComparaPrezzi::setP (double p[])
{
    for (int i; i<_n; i++)
    {
        _p[i] = p[i];
    }
}

double ComparaPrezzi::calcolaPrezzoMinMax( double& max) const
{
    double min;
    double massimo;
    for (int i=0; i< _n; i++)
    {
        min = _p[i];
        if (_p[i]>massimo)
        {
            massimo = _p[i];
        }
        if (_p[i]<min)
        {
            min = _p[i];
        }
    }
    max = massimo;
    return min;
}

istream& operator>>(istream& is, ComparaPrezzi& c)
{
    cout << "Inserisci i prezzi: " << endl;
    for(int i=0; i<c._n; i++)
    {
        is >> c._p[i];
        do
        {
            if (c._p[i]<0.0)
            cout << "Prezzo scorretto" << endl;
        }
        while (c._p[i]<0.0);
    }
    return is;
}

int main()
{
    const int dim = 5;
    int id = 10;
    int n = dim;
    double p[dim]= {0.0};
    ComparaPrezzi pr(id, n, p);
    cin >> p[dim];
    double massimo=0.0;
    double minimo = pr.calcolaPrezzoMinMax(massimo);
    cout << "Il prezzo minimo è: " << minimo 
        << endl << "Il prezzo massimo è: " << massimo << endl;
    return 0;
}