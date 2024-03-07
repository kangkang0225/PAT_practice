#include <iostream>
#include <vector>
using namespace std;

int n, m, k, num, a, b, path[209][209];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        path[a][b] = path[b][a] = 1;
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &num);
        int point, road[n + 1] = {0}, start, end, last, f = 0;
        for(int i = 0; i < num; i++) {
            scanf("%d", &point);
            if(i == 0) {
                start = point;
                // road[point]++;
            }
            if(i == num - 1) end = point;
            if(i != 0 && path[last][point]) road[point]++;
            if(i != 0 && !path[last][point]) f += 1;
            last = point;
        }
        if(start != end) f += 1;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += road[i];
        }
        if(sum != n) f = 1;
        if(!f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}