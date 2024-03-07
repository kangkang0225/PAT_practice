#include <iostream>
#include <vector>
using namespace std;

int N, M, Rela[201][3], K, Rest[101][101];
// N为人数，M为关系数，Rela为关系记录，K为几个休息区

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) scanf("%d%d", &Rela[i][1], &Rela[i][2]);
    scanf("%d", &K);
    for(int i = 1; i <= K; i++)
    for(int j = 1; j <= 100; j++){
        if(getchar() != '\n') scanf("%d", &Rest[i][j]);
        else break;
    }
    return 0;
}
