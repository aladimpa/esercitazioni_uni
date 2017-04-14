// Get the numbers in a string 
// save them inside an n-sized array
// return the total number of numbers found 
// print the array of numbers
// "fondamenti 100 350 di 12 informatica 24; 10" — n=10 —> [100, 350, 12, 24, 10, 0, 0, 0, 0, 0] (5 numbers)  

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isDigit(char d) {
    return d - '0' >= 0 && d - '0' <= 9;
}

int getNumbersInString(char s[], int a[], int n){
    int nfound = 0;
    //Zero the array
    for (int i=0; i<n; i++){
        a[i] = 0;
    }
    
    int idx = 0;
    int apos = 0;
    while (s[idx] != '\0'){
        if ( isDigit(s[idx]) ) {
            int digits = 1;
            while ( isDigit(s[idx+digits]) ){
                digits++;
            }
            if (apos < n) {
                int newn = 0;
                for (int k=0; k < digits; k++){
                    newn += (s[idx+k] - '0') * pow (10, digits - k - 1);
                }
                a[apos] = newn;
                apos++;
                nfound++;
            } else {
                nfound++;
            }
            idx += digits;
        } else {
            idx++;
        }
    }

    return nfound;
}

int main(){
    int n = 11;
    char message[] = "ciao73i1w87ee953n2m11mo65532lolicon446582misterx4096bye1037ed25519";
    int numbrs[n];
    int foundNum = getNumbersInString(message, numbrs, n);
    for (int i=0; i<n; i++){
        cout <<numbrs[i] << " ";
    }
    cout << endl << "Found " << foundNum << " numbers" << endl;
    if (foundNum > n) {
        cout << foundNum - n << " numbers were not included" << endl;
    }
    return 0;
}