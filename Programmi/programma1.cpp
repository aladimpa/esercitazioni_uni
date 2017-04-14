//Write a program to calculate some trigonometric properties of triangles.
//The program should
// - Ask for the three sides of the triangle, validating and asking again if the side is zero-sized or negative
// - Show a menú to perform the following functionalities
//  - Calculate the sine
//  - Calculate the cosine
//  - Calculate the tangent
//  These functionalities should be realized in separated functions

#include <iostream>
using namespace std;

double sine(double opposite, double hypotenuse)
{
    // soh
    double sine;
    sine = opposite/hypotenuse;
    return sine;
}

double cosine(double adjacent, double hypotenuse)
{
    //cah
    double cosine;
    cosine = adjacent/hypotenuse;
    return cosine;
}

double tangent(double opposite, double adjacent)
{
    //toa
    double tangent;
    tangent = opposite/adjacent;
    return tangent;
}

void menu(double hypotenuse, double opposite, double adjacent)
{
    int choice;
    double result;
    bool exit;
    do
    {
        cout << "What do you want to calculate? Choose the number" << endl
        << "1 -> Calculate the sine" << endl
        << "2 -> Calculate the cosine" << endl
        << "3 -> Calculate the tangent" << endl
        << "Attention! If you want to exit insert the number 0 (zero)" << endl;
        cin >> choice;
        switch (choice)
        {
            case 0:
                exit = true;
                break;
            case 1: 
                result = sine(opposite, hypotenuse);
                cout << "The sine is " << result << endl << endl;
                exit = false;
                break;
            case 2:
                result = cosine(adjacent, hypotenuse);
                cout << "The cosine is " << result << endl << endl;
                exit = false;
                break;
            case 3:
                result = cosine(adjacent, opposite);
                cout << "The tangent is " << result << endl << endl;
                exit = false;
                break;
            default:
                cout << "You didn't insert the correct numer!" << endl ;
                exit = false;
                break;
        } 
    }while (exit!=true);
}

int main()
{
    double hyp, opp, adj;
    double sin, cos, tg; 
    

    do
    {
        cout << "Insert the hypotenuse of the triangle:" << endl;
        do 
        {   
            cin >> hyp;
            if (hyp<1)
            {
                cout << "You didn't insert correctly the hypotenuse, so insert it again, bigger of 0 (zero)" << endl;
            }
        } while (hyp<1);
        cout << "Insert the opposite side of triangle:" << endl;
        do 
        {
            cin >> opp;
            if (opp<1)
            {
               cout << "You didn't insert correctly the opposite side, so insert it again, bigger of 0 (zero)" << endl;
            }
        } while (opp<1); 
        cout << "Insert the adjacent side of the triangle:" << endl;
        do 
        {
            cin >> adj;
            if (adj<1)
            {
                cout << "You didn't insert correctly the adjacent side, so insert it again, bigger of 0 (zero)" << endl;
            }
        } while (adj<1);
        if ((hyp*hyp)!=((opp*opp)+(adj*adj)))
        {
            cout << "You didn't insert correctly tha sides. To stop the program press ctrl+c" << endl;
        }
        else
        {
            menu (hyp, opp, adj);
        }
    }while((hyp*hyp)!=((opp*opp)+(adj*adj)));
    return 0;
}