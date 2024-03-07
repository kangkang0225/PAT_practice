#include <stdio.h>

const int maxn = 100010;

struct Land{
    int price;
    bool size; // 原始数据如果比n大，则为false，反之为true
}land[maxn];

int func(Land l[], int count, int n){
    int res = 0; // 总共有多少种路线
    for(int i = 0; i < count; i++){
        int sum = 0; // price的和
        int temp = i; // 每次迭代从i开始
        while(sum <= n){
            sum += l[temp].price;
            if(sum <= n && temp != count - 1){
                temp++;
                res++;
            } else if(sum <= n && temp == count - 1){
                res++;
                break;
            }
        }
    }
    return res;
}

int main(){
    // 初始化
    int m, n;
    scanf("%d%d", &m, &n);
    int count = 0; // 判断其中有多少个数
    for(int i = 0; i < m; i++) {
        scanf("%d", &land[i]);
        if(land[i].price <= n) land[i].size = true;
        else land[i].size = false;
        count++;
    }

    int res = func(land, count, n);
    printf("%d", res);

    return 0; 
}