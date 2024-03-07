#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

long long func(long long num){
    int i = 1; // 第i行
    int n = 1; // 结尾加的数
    int m = 0; // 乘数
    int a = 0;
    int ans = -1; // 判断是否相等；
    int tmp = 0; // 每行的乘数相加次数
    while(ans < num){
        tmp = 0;
        for(int j = 0; j < i; j++){ // 每行元素+1
            ans = m * 3 + i;
            a++;
            if(ans >= num) break;
            if(tmp + 1 < i) {
                m++;
                tmp++;
            }
        }
        i++;
    }
    if(ans == num) return a;
    else return -1;
};

int main(){
    int n;
    scanf("%d", &n);
    int arr[n] = {};
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        if((func(arr[i])) != -1) printf("%d\n", func(arr[i]));
        else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}