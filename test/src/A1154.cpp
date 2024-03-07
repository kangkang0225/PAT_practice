#include <iostream>
#include <set>
using namespace std;

set<int> S;
int n, m, k, a, b, rec_e[10001][10001], rec_p[10001][10001], f = 1;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        rec_e[a][b] = rec_e[b][a] = 1;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &rec_p[i][j]);
            S.insert(rec_p[i][j]);
        }
        for(int j = 0; j < n; j++){
            for(int m = 0; m < j; m++){
                if(rec_p[i][m] == rec_p[i][j]){
                    if(rec_e[j][m] == 1) f--;
                }
            }
        }
        if(f == 1) printf("%d-coloring\n", S.size());
        else printf("No\n");
        S.empty();
        f = 1;
    }
    return 0;
}