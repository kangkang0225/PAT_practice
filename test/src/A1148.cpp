#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, Rec[200];

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &Rec[i]);
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            vector<int>lie, a(N + 1, 1);
            a[i] = a[j] = -1;
            for(int k = 1; k <= N; k++) {
                if(Rec[k] * a[abs(Rec[k])] < 0) lie.push_back(k);
            } 
            if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}