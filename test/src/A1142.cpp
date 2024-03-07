#include <iostream>
#include <vector>
#include <set>
using namespace std;

int Nv, Ne, M, K, edge[209][209];

set<int> point;

int main() {
    scanf("%d%d", &Nv, &Ne);
    for(int i = 1; i <= Nv; i++) edge[i][i] = 1;
    for(int i = 0; i < Ne; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a][b] = edge[b][a] = 1;
    }
    for(int i = 1; i <= Nv; i++) point.insert(i);
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &K);
        vector<int> V;
        set<int> tmpoint = point;
        for(int i = 0; i < K; i++) {
            int a;
            scanf("%d", &a);
            V.push_back(a);
            tmpoint.erase(a);
        }
        int f = 0;
        for(int i = 0; i < V.size(); i++) {
            for(int j = 0; j < V.size(); j++) {
                if(!edge[V[i]][V[j]]) f = 1;
            }
        }
        if(f) {
            printf("Not a Clique\n");
            continue;
        }
        int t = 0;
        for(int it : tmpoint) {
            int num = 0;
            for(int itt : V) {
                if(edge[it][itt]) num++;
            }
            if(num >= V.size()) {
                printf("Not Maximal\n");
                t = 1;
                break;
            }
        }
        if(t) continue;
        printf("Yes\n");
    }
    return 0;
}