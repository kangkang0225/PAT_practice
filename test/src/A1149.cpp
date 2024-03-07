#include <iostream>
using namespace std;

int N, M, Pair[10009][2], L, f;

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d%d", &Pair[i][0], &Pair[i][1]);
    while(M--){
        int List[100009] = {0};
        scanf("%d", &L);
        for(int i = 0; i < L; i++) {
            int tmp = 0;
            scanf("%d", &tmp);
            List[tmp] = 1;
        }
        for(int i = 0; i < N; i++) {
            if(List[Pair[i][0]] == 1 && List[Pair[i][1]] == 1) f = 1;
        }
        if(f) printf("No\n");
        else printf("Yes\n");
        f = 0;
    }
    return 0;
}