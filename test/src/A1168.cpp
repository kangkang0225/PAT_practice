#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    int sqrtN = std::sqrt(n);
    for(int i = 2; i <= sqrtN; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    char Date[9];
    for(int i = 1; i <= 8; i++){
        scanf("%c", &Date[i]);
    }
    int Date_digit[9], Judge[9];
    for(int i = 1; i <= 8; i++){
        Date_digit[i] = Date[i] - '0';
    }

    int a, b, c, d, e, f, g, h;
    a = Date_digit[1] * 10000000;
    b = Date_digit[2] * 1000000;
    c = Date_digit[3] * 100000;
    d = Date_digit[4] * 10000;
    e = Date_digit[5] * 1000;
    f = Date_digit[6] * 100;
    g = Date_digit[7] * 10;
    h = Date_digit[8] * 1;

    int hh[9];
    hh[1] = a+b+c+d+e+f+g+h;
    hh[2] = b+c+d+e+f+g+h;
    hh[3] = c+d+e+f+g+h;
    hh[4] = d+e+f+g+h;
    hh[5] = e+f+g+h;
    hh[6] = f+g+h;
    hh[7] = g+h;
    hh[8] = h;

    int flag = 0;
    for(int i = 1; i <= 8; i++){
        for(int j = i; j <= 8; j++){
            printf("%c", Date[j]); 
        }
        if(isPrime(hh[i])) {
            printf(" Yes\n");
        }
        else{
            printf(" No\n");
            flag++;
        }

    }

    if(flag == 0) printf("All Prime!");

    
}