#include <iostream>
#include <vector>
using namespace std;

struct node {
    int parent, l, r, level;
    node() {
        parent = l = r = -1;
        level = 0;
    }
}tree[5000];

int n, tmp, post[50], in[50];

int build(int now, int begin, int end, int pre) {
    if(begin > end) return -1;
    tree[post[now]].parent = post[pre];
    if(pre == n) tree[post[now]].parent = -1;
    tree[post[now]].level = tree[post[pre]].level + 1;
    for(int i = 1; i <= n; i++) {
        if(in[i] == post[now]) {
            tree[post[now]].l = build(now - end + i - 1, begin, i - 1, now);
            tree[post[now]].r = build(now - 1, i + 1, end, now);
        }
    }
    return post[now];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &in[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &post[i]);
    build(n, 0, n, n);
    int index = 1;
    for(int i = 1; i <= n; i++) {
        if(index % 2 == 0) {
            for(int j = 1; j <= n; j++) {
                if(tree[in[j]].level == index) {
                    if(index != 1) printf(" ");
                    printf("%d", in[j]);
                }
            }
        } else {
            for(int j = n; j >= 1; j--) {
                if(tree[in[j]].level == index) {
                    if(index != 1) printf(" ");
                    printf("%d", in[j]);
                }
            }
        }
        index++;
    }
    return 0;
}