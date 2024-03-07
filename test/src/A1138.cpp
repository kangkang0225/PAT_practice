#include <iostream>
using namespace std;

struct node {
    int Lchild, Rchild, Parent;
    node() {
        Lchild = Rchild = Parent = -1;
    }
}tree[50009];

int N, preorder[50009], inorder[50009]; 

int build(int now, int start, int end, int pre) {
    if(start > end) return -1;
    tree[now].Parent = preorder[pre];
    if(now == 0) tree[preorder[now]].Parent = -1;
    for(int i = 1; i <= N; i++) {
        if(inorder[i] == preorder[now]) {
            tree[now].Lchild = build(now + 1, start, i - 1, now);
            tree[now].Rchild = build(i + now - start + 1, i + 1, end, now);
        }
    }
    return preorder[now];
}

int find(int index) {
    if(tree[index].Lchild != -1) return find(tree[index].Lchild);
    else if(tree[index].Rchild != -1) return find(tree[index].Rchild);
    else return index;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &preorder[i]);
    for(int i = 1; i <= N; i++) scanf("%d", &inorder[i]);
    build(1, 1, N, 1);
    int ans = find(1);
    printf("%d\n", ans);
    return 0;
}