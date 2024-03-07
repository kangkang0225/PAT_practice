#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int parent, lchild, rchild, level;
    node(){
        parent = -1;
        lchild = -1;
        rchild = -1;
        level = 0;
    }
} A[10001];
// A为构建的树

string s;

int n, num, post[1001], in[1001], full, a, b;
// n为总结点数，post为后序遍历，in为中序遍历, full为0表示树已满，为1表示未满

int deal(int Now, int Start, int End, int Pre){
// Now为后续遍历当前所在的节点，Pre为后序遍历中的父节点，Start，End为中序左右两节点区间
    if(Start > End) return -1;
    int i = Start;
    while(i < End && in[i] != post[Now]) i++;
    // i为中序当前所在节点位置
    A[post[Now]].parent = Pre;
    A[post[Now]].level = A[Pre].level + 1;
    A[post[Now]].lchild = deal((Now - 1 - (End - i)), Start, i - 1, post[Now]);
    A[post[Now]].rchild = deal(Now - 1, i + 1, End, post[Now]);
    if(A[post[Now]].lchild * A[post[Now]].rchild < 0) full = 1;
    return post[Now];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    deal(n - 1, 0, n - 1, 1001);
    scanf("%d", &num);
    while(num--){
        int f = 0;
        cin >> s;
        if(s == "It"){
            cin >> s >> s >> s >> s;
            if(full) cout << "No\n";
            else cout << "Yes\n";
            continue;
        } else{
            a = stoi(s);
            cin >> s;
            if(s == "is") {
                cin >> s >> s;
                if(s == "root") {
                    if(a == post[n - 1]) f = 1;
                } else if(s == "parent") {
                    cin >> s >> b;
                    if(A[b].parent == a) f = 1;
                } else if (s == "left") {
                    cin >> s >> s >> b;
                    if (A[b].lchild == a) f = 1;
                } else {
                    cin >> s >> s >> b;
                    if (A[b].rchild == a) f = 1;
                }
            } else {
                cin >> b >> s >> s;
                if(s == "siblings") {
                    if (A[a].parent == A[b].parent) f = 1;
            } else {
                cin >> s >> s >> s;
                if (A[a].level == A[b].level) f = 1;
                }
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}