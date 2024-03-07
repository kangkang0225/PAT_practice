#include <iostream>
using namespace std;

struct node {
    int Lchild, Rchild, Parent, Level;
    node() {
        Lchild = Rchild = Parent = -1;
        Level = 0;
    }
} tree[10005];

int M, N, Inorder[1009], Preorder[1009], fa, fb, a, b, fx, fy, fxy, fe;

int build(int now, int begin, int end, int pre){
    if(begin > end) return -1;
    tree[Preorder[now]].Parent = Preorder[pre];
    if(now == 0) tree[Preorder[now]].Parent = -1;
    tree[Preorder[now]].Level = tree[tree[Preorder[now]].Parent].Level + 1;
    for(int i = 0; i < N; i++){
        if(Inorder[i] == Preorder[now]){
            tree[Preorder[now]].Lchild = build(now + 1, begin, i - 1, now);
            tree[Preorder[now]].Rchild = build(i - begin + now + 1, i + 1, end, now);
        }
    }
    return Preorder[now];
}

void find_ansestor(int x, int y) {
    if(fe) return;
    if(tree[x].Level > tree[y].Level) {
        fx++; 
        find_ansestor(tree[x].Parent, y);
        if(fe) return;
    } 
    if(tree[x].Level < tree[y].Level) {
        fy++; 
        find_ansestor(x, tree[y].Parent);
        if(fe) return;
    } 
    if(x == y && !fxy) {
        if(fx > 0) printf("%d is an ancestor of %d.\n", b, a);
        if(fy > 0) printf("%d is an ancestor of %d.\n", a, b);
        fe++;
        return;
    } else if(x == y && fxy) {
        printf("LCA of %d and %d is %d.\n", a, b, x);
        fe++;
        return;
    } else {
        fxy = 1;
        find_ansestor(tree[x].Parent, tree[y].Parent);
        if(fe) return;
    }
}

void find(int a, int b) {
    for(int i = 0; i < N; i++) {
        if(Inorder[i] == a) fa++;
        if(Inorder[i] == b) fb++;
    }
    if(fa == 0 || fb == 0) {
        if(fa == 0 && fb == 0) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(fa == 0) printf("ERROR: %d is not found.\n", a);
        else if(fb == 0) printf("ERROR: %d is not found.\n", b);
    } else if(a == b) {
        printf("LCA of %d and %d is %d.\n", a, a, a);
    } else {
        find_ansestor(a, b);
        fe = fx = fy = fxy = 0;
    }
    fa = fb = 0;
}

int main() {
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++) scanf("%d", &Inorder[i]);
    for(int i = 0; i < N; i++) scanf("%d", &Preorder[i]);
    build(0 , 0, N - 1, 0);
    while(M--){
        scanf("%d%d", &a, &b);
        find(a, b);
    }
    return 0;
}
