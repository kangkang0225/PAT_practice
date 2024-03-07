#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, M, K, Edge[300][300], length = 9999999, L;

void check(int index) {
    int num, a, f = 0, sum = 0;
    set<int> S;
    vector<int> V;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &a);
        S.insert(a);
        V.push_back(a);
    }
    for(int i = 0; i < num - 1; i++) {
        if(!Edge[V[i]][V[i + 1]]) f = 1;
        sum += Edge[V[i]][V[i + 1]];
    }
    if(f) printf("Path %d: NA (Not a TS cycle)\n", index);
    else if(S.size() < N || V[0] != V[num - 1]) printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    else if(S.size() == N && V.size() > S.size() + 1) {
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if(sum < length) {
            length = sum;
            L = index;
        }
    }
    else{
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if(sum < length) {
            length = sum;
            L = index;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Edge[a][b] = Edge[b][a] = c;
    }
    scanf("%d", &K);
    for(int i = 1; i <= K; i++) check(i);
    printf("Shortest Dist(%d) = %d\n", L, length);
    return 0;
}