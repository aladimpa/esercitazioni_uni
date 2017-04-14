#include <iostream>
using namespace std;

double prodotto_scalare (double x[], double y[], int n)
{
    double* px = x;
    double* py = y;
    double prodotto = 0.0;
    for (int i=0; i<n; i++)
    {
        prodotto = prodotto + ((*(px+i))*(*(py+i)));
    }
    return prodotto;
}

int main()
{
    int n;
    cout << "Quanti numeri vuoi inserire per ogni array?" << endl;
    cout << "Numero: ";
    cin >> n;
    const int m = n;
    double a[m];
    double b[m];
    cout << "Compila il primo array" << endl;
    for (int i=0; i<n; i++)
    {
        cout << i+1 << ": ";
        cin >> a[i];
    }
    cout << "Compila il secondo array" << endl;
    for (int j=0; j<n; j++)
    {
    cout << j+1 << ": ";
    cin >> b[j];
    }
    int prod_scalare = prodotto_scalare(a, b, m);
    cout << "Il prodotto scalare tra i due array è " << prod_scalare << endl;
    return 0;
    }