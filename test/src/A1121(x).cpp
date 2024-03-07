#include <iostream>
#include <set>
#include <stack>
#include <map>
using namespace std;

int n, m, t1, t2, t, f, couple1[50009], couple2[50009];

set<int> single;
map<int, int> may;
stack<int> goal;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        may[t1] = t2;
        may[t2] = t1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        single.insert(t);
    }
    for(auto it : single) {
        for(auto itt: single) {
            if(may[it] == itt) {
                goal.push(it);
                goal.push(itt);
            }
        }
    }
    while(!f) {
        single.erase(goal.top());
        goal.pop();
        if(goal.size() == 0) f = 1;
    }
    printf("%d\n", single.size());
    for(auto it : single) {
        if(it != *single.begin()) printf(" ");
        printf("%d", it);
    }
    return 0;
}