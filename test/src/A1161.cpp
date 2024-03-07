#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    int next;
}A[100000];

vector<int>a1, a2, ans;
// a1, a2分别是两条链的地址, ans为答案链的地址

int N, n1, n2, x, y, l1, l2;
// N为给的节点数, n1, n2分别为初始节点, l1, l2为两条链的节点数

int main(){
    scanf("%d%d%d", &n1, &n2, &N);
    for(int i = 0; i < N; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        A[a].data = b;
        A[a].next = c;
    }
    x = n1;
    while(x != -1) {
        a1.push_back(x);
        x = A[x].next;
        l1++;
    }
    y = n2;
    while(y != -1) {
        a2.push_back(y);
        y = A[y].next;
        l2++;
    }
    if(a1.size() < a2.size()) swap(a1, a2);
    for(int i = 0, j = a2.size() - 1; i < a1.size(); i++) {
        ans.push_back(a1[i]);
        if(i & 1 && j >= 0) ans.push_back(a2[j--]);
    }
    for(int i = 0; i < ans.size() - 1; i++){
        printf("%05d %d %05d\n", ans[i], A[ans[i]].data, ans[i + 1]);
    }
    printf("%05d %d -1", ans.back(), A[ans.back()].data);
    return 0;
}