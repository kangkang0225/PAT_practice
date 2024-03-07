#include <iostream>
#include <map>
#include <vector>
using namespace std;

int M, N, U, V, rec[10009];

map<int, bool> mp;

int main() {
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &rec[i]);
        mp[rec[i]] = true;
    }
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &U, &V);
        int a = 0;
        for(int i = 0; i < N; i++) {
            a = rec[i];
            if((a >= U && a <= V) || (a <= U && a >= V)) break;
        }
        if(!mp[U] && !mp[V]) printf("ERROR: %d and %d are not found.\n", U, V);
        else if(!mp[U] || !mp[V]) printf("ERROR: %d is not found.\n", !mp[U] ? U : V);
        else if(a == U || a == V) printf("%d is an ancestor of %d.\n", a, a == U ? V : U);
        else printf("LCA of %d and %d is %d.\n", U, V, a);
    }
    return 0;
}