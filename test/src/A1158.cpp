#include <iostream>
#include <vector>
#include <set>
using namespace std;

int K, N, M, a, b, c;
// K为阈值，N为总共有多少个电话号码，M为通话记录

long long rec[1001][1001], peo_long[1001], peo_short[1001], recall_count[1001];
// rec为通话记录, peo_long为每个人有多少长通话记录，peo_short为每个人有多少短通话记录

long long help_judge[1001][4];
// 辅助判断是否满足第二个条件

set<int> caller, caller_sus, caller_noma, judge;
// 判断总共有多少打电话者，多少骗子，多少正常人, 多少个待审核的

int main(){
    scanf("%d%d%d", &K, &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);
        rec[a][b] = c;
        help_judge[i][0] = a;
        help_judge[i][1] = b;
        help_judge[i][2] = c;
        help_judge[i][3] = i;
        caller.insert(a);
        if(c > 5) peo_long[a]++;
        else peo_short[a]++;
        if(peo_short[a] > K) judge.insert(a);
    }
    int temp = -1;
    for(auto it: judge){
        int call_back = 0;
        int x = 0;
        for(int count = temp + 1; count <= temp + (peo_long[it] + peo_short[it]); count++) {
            if(help_judge[count][2] <= 5){
                int tmp = count + 1;
                if(help_judge[count][0] != help_judge[tmp][0]) x = count;
                if(rec[help_judge[count][1]][it] > 0) call_back++;
            }
        }
        temp = x;
        float f1 = call_back, f2 = peo_short[it];
        if(f1 / f2 <= 0.2) caller_sus.insert(it);
    }
    int last[1001] = {0};
    for(auto it = caller_sus.begin(); it != caller_sus.end(); it++){
        int f = 0;
        if(last[*it] == 0){
            printf("%d", *it);
            last[*it] = 1;
            f++;
        }
        for(auto itt = caller_sus.begin(); itt != caller_sus.end(); itt++){
            if(*it != *itt && rec[*it][*itt] > 0 && rec[*itt][*it] > 0 && last[*itt] == 0){
                printf(" %d", *itt);
                f++;
                last[*itt] = 1;
            }
        }
        if(f) printf("\n");
    }
    if(caller_sus.size() == 0) printf("None\n");
    return 0;
}