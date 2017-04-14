#include <iostream>
using namespace std;

int main()
{
    cout << "Quanti elementi vuoi inserire?" << endl;
    int dim = 0;
    cin >> dim;
    while (dim<1) 
    {
        cout << "Numero inserito non valido. Inserire nuovamente" << endl;
        cin >> dim;
    }
    int* num = new int[dim];
    for (int i=0; i<dim; i++)
    {
        cout << "inserire il " << i+1 << "° numero: ";
        cin >> num[i];
    }
    int tmp;
    for (int v=dim-1; v>0; v--)
    {
        for (int j=0; j<v; j++)
        {
            if (num[j] > num[j+1])
            {
                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }
    cout << "L'array ordinato in modo crescente è il seguente: " << endl;
    for (int i=0; i<dim; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    delete[] num;
    return 0;
}