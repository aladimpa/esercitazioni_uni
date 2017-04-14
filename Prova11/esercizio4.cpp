#include <iostream>
using namespace std;

void problema_hanoi(int n, char inizio, char appoggio, char fine)
{
    cout << n << endl << inizio << endl << appoggio << endl << fine << endl;
    if (n==1)
    {
        cout << "Sposto un disco da " << inizio << " a " << fine  << endl;
    }
    else 
    {
        problema_hanoi(n-1, inizio, fine, appoggio);
        problema_hanoi(1, inizio, appoggio, fine);
        problema_hanoi(n-1, appoggio, inizio, fine);
    }
}

int main()
{
    int n = 3;
    int a = 'A';
    int b = 'B';
    int c = 'C';
    problema_hanoi(n, a, b, c);
    
}