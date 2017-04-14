#include <iostream>
using namespace std;

int main()
{
    int dim = 0;
    cout << "Inserisci il numro di righe/colonne della matrice" << endl;
    cout << "Numero: ";
    cin >> dim;
    const int n = dim;
    const int* const m = &n;
    int mat [n][*m];
    int* p[n];
    for (int k=0; k<n; k++)
    {
        *(p+k)=NULL;
    }
    cout << "Compilazione matrice:" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<*m; j++)
        {
            cout << "(" << i+1 << "," << j+1 << ") ";
            cin >> mat[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        int somma = 0;
        for (int j=0; j<*m; j++)
        {
            somma = somma + mat[i][j];
        }
        if (somma < 0)
        {
            *(p+i) = *(mat+i);
            //cout << **(p+i) << i << endl;
        }
    }
    cout << "Visualizzazione righe tabella con somma minore di 0:" << endl;
    for (int z=0; z<n; z++)
    {
        if (*(p+z)!=NULL)
        {
            for (int x=0; x<*m; x++)
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