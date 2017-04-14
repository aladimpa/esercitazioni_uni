#include <iostream>
using namespace std;

int massimo_comune_divisore (int a, int b)
{
    int mcd = 0;
    int r = 0;
    do
    {     
        if ( b == 0)
        {
            mcd = a;
        }
        else 
        {
            r = a % b;  
            if (r == 0)
            {
                mcd = b;
            }
            else 
            {
                a = b;
                b = r;
            }
        } 
    } while ( r != 0);
    return mcd;
}

int main()
{
    int num1, num2, m_c_d;
    char ignora_trattino;
    char risposta = 's';
    do 
    {
        cout << "Inserisci due numeri naturali separati da un trattino (es: 3-7)" << endl;
        cin >> num1 >> ignora_trattino >> num2;
        if ((num1 >= 0) && (num2 >= 0))
        {
            m_c_d = massimo_comune_divisore(num1, num2);
            cout << "Il massimo comune divisore dei due numeri è: " << m_c_d << endl;
            cout << "Vuoi inserire un altro numero? Inserisci s oppure n" << endl;
            cin >> risposta;
        }
        else
        {
            cout << "Attenzione! Devi inserire correttamente i numeri" << endl;
        }
    } while (risposta == 's');
    return 0;
}