#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

    int X[100005], now, index, A, B;
    // A为磁盘容量，now为当前输出的数字，index为磁盘指针，B为内存, X[]为磁盘
    priority_queue<int, vector<int>, greater<int>>Q1, Q2;
    // Q1，Q2交换位置，实现循环

int main(){
    scanf("%d %d", &A, &B);
    for(int i = 1; i <= A; i++){
        scanf("%d", &X[i]);
    }
    for(int i = 1; i <= B; i++){
        Q1.push(X[i]);
    }
    index = B + 1;
    while(Q1.size()){
        now = Q1.top();
        printf("%d", now);
        Q1.pop();
        if(index <= A){
            if(now < X[index]) Q1.push(X[index]);
            else Q2.push(X[index]);
            index++;
        }
        if(Q1.size()) printf(" ");
        else{
            swap(Q1, Q2);
            printf("\n");
        }
    }
    return 0;
}