#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int N, R, K, M;
// N为地点的数量，R为相邻地点路线的数量，K为物种数量，M为提供的方法数量
int N_of_R[100005][3], Sol[21][501];
// N_of_R为路线数量，Sol为提供的解决方案
set<int> S;
// S提供解决方案中不同物种的数量

int main(){
    scanf("%d%d%d", &N, &R, &K);
    for(int i = 1; i <= R; i++){
        scanf("%d%d", &N_of_R[i][1], &N_of_R[i][2]);
    }
    scanf("%d", &M);
    int temp[M + 1] = {0};
    // 标识符，确定是否在物种数量上出现了问题
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++) {
            scanf("%d", &Sol[i][j]);
            S.insert(Sol[i][j]);
        }
        if(S.size() < K) {
            // printf("Error: Too few species.\n");
            temp[i] = -1;
        }
        if(S.size() > K) {
            // printf("Error: Too many Species.\n");
            temp[i] = 1;
        }
        S.clear();
    }
    for(int i = 1; i <= M; i++){
        if(temp[i] == 0){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= R; k++){
                    if(j == N_of_R[k][1]){
                        if(Sol[i][j] == Sol[i][(N_of_R[k][2])]) temp[i] = 2;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= M; i++){
        if(temp[i] == 2) printf("No\n");
        if(temp[i] == 0) printf("Yes\n");
        if(temp[i] == -1) printf("Error: Too few species.\n");
        if(temp[i] == 1) printf("Error: Too many species.\n");

    }
    return 0;
}
