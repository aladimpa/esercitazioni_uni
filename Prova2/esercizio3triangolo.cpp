#include <iostream>
#include <cmath>
using namespace std;

double calcolo_area_triangolo(double x,double y,double z)
{
    double p, A;
    p = (x+y+z)/2;
    A = sqrt(p*(p-x)*(p-y)*(p-z));
    return A;
}

int main()
{
    double a,b,c;
    cout<< "Inserisci il primo lato del triangolo: ";
    cin >> a;
    cout<< "Inserisci il secondo lato del triangolo: ";
    cin >> b;
    cout<< "Inserisci il terzo lato del triangolo: ";
    cin >> c;
    cout<< "L'area del triangolo è: " << calcolo_area_triangolo(a,b,c) << endl;
    return 0;
}