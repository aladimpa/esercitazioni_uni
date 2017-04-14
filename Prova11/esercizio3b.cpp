#include <iostream>
using namespace std;

template<typename T>
T det_max (T num[], int dim)
{
    T max=num[0];
        for (int i=1; i<dim; i++)
        {
            if (num[i]>max)
            {
                max = num[i];
            }
        }
        return max;
}

template<typename T>
T dividi(T num[], int n)
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
        T* array1 = new T[dim];
        T* array2 = new T[dim];
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
    int n, tipo;
    cout << "Quanti numeri vuoi inserire? ";
    cin >> n;
    cout << "I numeri che devi inserire sono:" << endl
        << "Reali? (con la virgola) Premi 1;" << endl
        << "Interi? Premi 2." << endl;
    cin >> tipo;
    switch(tipo)
    {
        case 1: 
        {
            double* numeri1 = new double[n];
            for (int i=0; i<n; i++)
            {
                cout<< "Inserire il " << i+1 << " numero: ";
                cin >> numeri1[i];
            }
            cout << "Tra i numeri inseriti il massimo è " << dividi(numeri1, n) << endl;
            delete[] numeri1;
            break;
        }
        case 2:
        {
            int* numeri2 = new int[n];
            for (int i=0; i<n; i++)
            {
                cout<< "Inserire il " << i+1 << " numero: ";
                cin >> numeri2[i];
            }
            cout << "Tra i numeri inseriti il massimo è " << dividi(numeri2, n) << endl;
            delete[] numeri2;
            break;
        }
        
    }
    return 0;
}