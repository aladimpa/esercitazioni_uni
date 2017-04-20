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

}

void Data::stampa_data()
{

}

void Data::copia_data(Data& data)
{

}

Data Data::calcolo_data_prec()
{

}

Data Data::calcolo_data_succ()
{

}

int main()
{
    return 0;
}
