#include <iostream>
using namespace std;

int M, N, Rec[1008], fMax = 1, fMin = 1;

void order(int n) {
    if(n > N) return;
    order(n * 2);
    order(n * 2 + 1);
    printf("%d%s", Rec[n], n == 1 ? "\n" : " ");
}

void heap(int index) {
    for(int i = 2; i <= N; i++) {
        if(Rec[i] <= Rec[i / 2]) fMin = 0;
        if(Rec[i] >= Rec[i / 2]) fMax = 0;
    }
    if(fMax == 1) printf("Max Heap\n");
    else if(fMin == 1) printf("Min Heap\n");
    else printf("Not Heap\n");
    order(1);
    fMax = fMin = 1;
}

int main() {
    scanf("%d%d", &M, &N);
    while(M--) {
        for(int i = 1; i <= N; i++) scanf("%d", &Rec[i]);
        heap(1);
        Rec[200] = {0};
    }
    return 0;
}