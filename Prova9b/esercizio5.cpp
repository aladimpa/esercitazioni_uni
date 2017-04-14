#include <iostream>
using namespace std;

const int n = 2;

void funzione(int mat[n][n], int* b[n])
{
    for (int k=0; k<n; k++)
    {
        *(b+k)=0;
    }
    for (int i=0; i<n; i++)
    {
        int somma = 0;
        for (int j=0; j<n; j++)
        {
            somma = somma + mat[i][j];
        }
        if (somma < 0)
        {
            *(b+i) = *(mat+i);
            //cout << **(p+i) << i << endl;
        }
    }
}

int main()
{
    int mat [n][n];
    int* p[n];
    cout << "Compilazione matrice (7x7):" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "(" << i+1 << "," << j+1 << ") ";
            cin >> mat[i][j];
        }
    }
    funzione(mat, p);
    cout << "Visualizzazione righe tabella con somma minore di 0:" << endl;
    for (int z=0; z<n; z++)
    {
        if (*(p+z)!=0)
        {
            for (int x=0; x<n; x++)
            {
               cout << *(*(p+z)+x) << " ";
            }
        }
        else 
        {
            for (int w=0; w<n; w++)
            cout << " - ";
        }
        cout << endl;
    }
    return 0;
}