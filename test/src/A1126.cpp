#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> path;
vector<bool> visit;

int n, m, num, a, b, even;

void judge(int index) {
    visit[index] = true;
    num++;
    for(int i = 0; i < path[index].size(); i++) {
        if(visit[path[index][i]] == false) {
            judge(path[index][i]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    path.resize(n + 1);
    visit.resize(n + 1);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(i != 1) printf(" ");
        printf("%d", path[i].size());
    }
    printf("\n");
    for(int i = 1; i <= n; i++) {
        if(path[i].size() % 2 == 0) even++;
    }
    judge(1);
    if(num == n && even == n) printf("Eulerian\n");
    else if(num == n && even == n - 2) printf("Semi-Eulerian");
    else printf("Non-Eulerian");
    return 0;
}