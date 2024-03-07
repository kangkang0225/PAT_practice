#include <iostream>
using namespace std;

struct node {
    string value;
    int Lchild, Rchild;
} Tree[100];

int N, leaf, index1;

int findIndex(int a) {
    for(int j = 1; j <= N; j++) {
        if(Tree[j].Lchild == a || Tree[j].Rchild == a) {
            index1 = j;
            findIndex(j);
        }
    }
    return index1;
}

string inorder(int index) {
    if(Tree[index].Lchild == -1 && Tree[index].Rchild == -1) return Tree[index].value;
    if(Tree[index].Lchild == -1 && Tree[index].Rchild != -1) return "(" + Tree[index].value + inorder(Tree[index].Rchild) + ")";
    if(Tree[index].Lchild != -1 && Tree[index].Rchild != -1) return "(" + inorder(Tree[index].Lchild) + Tree[index].value +inorder(Tree[index].Rchild) + ")";
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        Tree[i].value = s;
        Tree[i].Lchild = l;
        Tree[i].Rchild = r;
        if(l == -1 && r == -1) leaf = i;
    }
    findIndex(leaf);
    string ans = inorder(index1);
    if(ans[0] == '(') ans = ans.substr(1, ans.size() - 2);
    printf("%s\n", ans.c_str());
    return 0;
}