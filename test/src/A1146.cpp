#include <iostream>
#include <vector>
using namespace std;

int N, M, K, In[1009];

vector<int> Out[1009];

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Out[a].push_back(b);
        In[b]++;
    }
    scanf("%d", &K);
    int f = 1;
    for(int i = 0; i < K; i++) {
        int judge = 1;
        vector<int> tmp(In, In + N + 1);
        for(int i = 0; i < N; i++) {
            int a = 0;
            scanf("%d", &a);
            if(tmp[a] != 0) judge = 0;
            for(int it : Out[a]) tmp[it]--;
        }
        if(judge) continue;
        printf("%s%d", f == 1 ? "" : " ", i);
        f = 0;
    }
    return 0;
}