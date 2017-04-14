#include <iostream>
using namespace std;

int main()
{
    float num1, num2, add, sott, molt, divis;
    cout << "Inserisci il primo numero: "<<endl;
    cin >> num1;
    cout << "Inserisci il secondo numero: "<<endl;
    cin >> num2;
    add=num1+num2;
    sott=num1-num2;
    molt=num1*num2;
    divis=num1/num2;
    cout << "I risultati delle operazioni sono:" << endl
            << "Addizione = " << add << ";" << endl
            << "Sottrazione = " << sott << ";" << endl
            << "Moltiplicazione = " << molt << ";" << endl
            << "Divisione = " << divis << ";" << endl;
    return 0;
}