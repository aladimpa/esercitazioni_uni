#include <iostream>
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
            Data calcolo_data_prec();
            Data calcolo_data_succ();
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

Data Data::calcolo_data_prec()
{
    Data d;
    d.copia_data(*this);
    cout << "Giorno precedente: " << endl;
    if (d._mese == 1)
    {
        if (d._giorno==1)
        {
            _anno = d._anno -1;
            _mese = 12;
            _giorno = max(d._mese, d._anno);
        }
        else
        {
            _giorno = d._giorno - 1;
            _mese = d._mese;
            _anno = d._anno;
        }
    }
    else
    {
        _giorno = d._giorno - 1;
        _mese = d._mese;
        _anno = d._anno;
    }
}

Data Data::calcolo_data_succ()
{
    Data d;
    d.copia_data(*this);
    cout << "Giorno successivo: " << endl;
    if (d._mese == 12)
    {
        if (d._giorno==31)
        {
            _anno = d._anno +1;
            _mese = 1;
            _giorno = 1;
        }
        else
        {
            _giorno = d._giorno + 1;
            _mese = d._mese;
            _anno = d._anno;
        }
    }
    else if (_giorno=max(_mese, _anno))
    {
        _giorno = 1;
        _mese = d._mese + 1;
        _anno = d._anno;
    }
}

int main()
{
    Data prec;
    prec.calcolo_data_prec();
    prec.stampa_data();
    Data succ;
    succ.calcolo_data_succ();
    succ.stampa_data();
    return 0;
}
