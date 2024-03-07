#include <iostream>
#include <cmath>
using namespace std;

int n, f = 1;

bool is_Prime(int n){
    if(n <= 1) return false;
    int m = pow(n, 0.5);
    for(int i = 2; i <= m; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    if(is_Prime(n)) {
        if(is_Prime(n - 6)){
            printf("Yes\n");
            printf("%d", n - 6);
        } else if(is_Prime(n + 6)){
            printf("Yes\n");
            printf("%d", n + 6);
        } else {
            printf("No\n");
            int num = n + 1;
            while(f){
                if(is_Prime(num)){
                    if(is_Prime(num - 6) || is_Prime(num + 6)) {
                        printf("%d", num);
                        f = 0;
                    } else num++;
                } else num++;
            }
        }
    } else {
        printf("No\n");
        int num = n + 1;
        while(f){
            if(is_Prime(num)){
                if(is_Prime(num - 6) || is_Prime(num + 6)) {
                    printf("%d", num);
                    f = 0;
                } else num++;
            } else num++;
        }
    }
    return 0;
}