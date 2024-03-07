#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b, k, v, x;
    scanf("%d%d", &n, &m);
    vector<int> vertex[n];
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        vertex[a].push_back(i);
        vertex[b].push_back(i);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &v);
        vector<int> rec(m, 0);
        for(int j = 0; j < v; j++) {
            scanf("%d", &x);
            for(int k = 0; k < vertex[x].size(); k++) {
                rec[vertex[x][k]] = 1;
            }
        }
        int f = 1;
        for(int j = 0; j < m; j++) {
            if(!rec[j]) {
                printf("No\n");
                f = 0;
                break;
            }
        }
        if(f) printf("Yes\n");
    }
    return 0;
}