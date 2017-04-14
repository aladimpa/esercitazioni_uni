#include <iostream>
using namespace std;

int det_max(int num[], int dim)
{
    int max=num[0];
        for (int i=1; i<dim; i++)
        {
            if (num[i]>max)
            {
                max = num[i];
            }
        }
        return max;
}

int dividi(int num[], int n)
{
    if (n==1)
    {
        return num[0];
    }
    if (n%2 != 0)
    {
        return det_max(num, n);
    }
    else
    {
        int dim = n/2;
        int* array1 = new int[dim];
        int* array2 = new int[dim];
        for (int i=0; i<n; i++)
        {
            if (i < (n/2))
            {
                array1[i] = num[i];
            }
            else
            {
                array2[i-(dim)] = num[i];
            }
        }
        if (det_max(array1, dim) > det_max(array2, dim))
        {
            return det_max(array1, dim);
        }
        else
        {
            return det_max(array2, dim);
        }
        delete[] array1;
        delete[] array2;
    }
}

int main()
{
    int n;
    cout << "Quanti numeri vuoi inserire? ";
    cin >> n;
    int* numeri = new int[n];
    for (int i=0; i<n; i++)
    {
        cout<< "Inserire il " << i+1 << " numero: ";
        cin >> numeri[i];
    }
    cout << "Tra i numeri inseriti il massimo è " << dividi(numeri, n) << endl;
    delete[] numeri;
    return 0;
}