#include <iostream>
#include <math.h>
using namespace std;

class Punto2D
{
    public:
            Punto2D();
            Punto2D(double x, double y);
            Punto2D(const Punto2D& p2D);
            ~Punto2D();
            double getX() const;
            double getY() const;
            void setX(double x);
            void setY(double y);
            Punto2D operator+(Punto2D p2D);
            Punto2D operator-(Punto2D p2D);
            Punto2D operator*(double n);
            const Punto2D& operator=(const Punto2D& p2D);
            friend ostream& operator<<(ostream& os, const Punto2D& p2D);
            friend istream& operator>>(istream& is, Punto2D& p2D);
            double distanza(Punto2D p2D) const;
    private:
            double _x;
            double _y;
};

Punto2D::Punto2D()
{
    _x = 0;
    _y = 0;
}

Punto2D::Punto2D(double x, double y)
{
    _x = x;
    _y = y;
}

Punto2D::Punto2D(const Punto2D& p2D)
{
    _x = p2D._x;
    _y = p2D._y;
}

Punto2D::~Punto2D()
{
    cout << "Questo è il distruttore" << endl;
}

double Punto2D::getX() const
{
    return _x;
}

double Punto2D::getY() const
{
    return _y;
}

void Punto2D::setX(double x)
{
    _x = x;
}

void Punto2D::setY(double y)
{
    _y = y;
}

Punto2D Punto2D::operator+(Punto2D p2D)
{
    Punto2D p(_x+p2D._x, _y+p2D._y);
    return p;
}

Punto2D Punto2D::operator-(Punto2D p2D)
{
    Punto2D p(_x-p2D._x, _y-p2D._y);
    return p;
}

Punto2D Punto2D::operator*(double n)
{
    Punto2D p(_x*n, _y*n);
    return p;
}

const Punto2D& Punto2D::operator=(const Punto2D& p2D)
{
    if (this != &p2D)   //evita autoassegnamento
    {
        _x = p2D._x;
        _y = p2D._y;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Punto2D& p2D)
{
    os << '(' << p2D._x << ',' << p2D._y << ')';
    return os;
}

istream& operator>>(istream& is, Punto2D& p2D)
{
    is >> p2D._x >> p2D._y;
    return is;
}

double Punto2D::distanza(Punto2D p2D) const
{
    double dx = (_x - p2D._x);
    double dy = (_y - p2D._y);
    return sqrt(dx * dx + dy * dy);
}

/*int main()
{
    Punto2D p1, p2;
    cout << "Inserire le coordinate x e y del primo punto: " << endl;
    cin >> p1;
    cout << "Inserire le coordinate x e y del secondo punto: " << endl;
    cin >> p2;
    cout << "Punto 1: " << p1 << endl;
    cout << "Punto 2: " << p2 << endl;
    cout << "Punto 1 + Punto2 = " << p1 + p2 << endl;
    cout << "Punto 1 - Punto 2 = " << p1 - p2 << endl;
    cout << "La loro distanza vale: " << p1.distanza(p2) << endl;
    return 0;
}*/

class Poligono2D
{
    public:
            Poligono2D();
            Poligono2D(int n, Punto2D poligono);
            Poligono2D(const Poligono2D& pol);
            ~Poligono2D();
            double perimetro();
            Poligono2D operator*(double w);
            const Poligono2D& operator=(const Poligono2D& pol);
            //operatore di sel con indice
            friend ostream& operator<<(ostream& os, const Poligono2D& pol);
            friend istream& operator>>(istream& is, const Poligono2D& pol);
    private:
            Punto2D* _poligono;
            int _n;
};

Poligono2D::Poligono2D()
{
    
}

Poligono2D::Poligono2D(int n, Punto2D poligono)
{

}

Poligono2D::Poligono2D(const Poligono2D& pol)
{

}

Poligono2D::~Poligono2D()
{

}

double Poligono2D::perimetro()
{

}

Poligono2D Poligono2D::operator*(double w)
{

}

const Poligono2D& Poligono2D::operator=(const Poligono2D& pol)
{

}

//operatore di sel con indice
//{
//    
//}

ostream& operator<<(ostream& os, const Poligono2D& pol)
{

}

istream& operator>>(istream& is, const Poligono2D& pol)
{

}

int main()
{
    return 0;
}