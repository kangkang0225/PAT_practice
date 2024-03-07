#include <iostream>
#include <string>
using namespace std;

string Data[32];
// 储存当前节点的数或符号

int lc[32], rc[32], root = 1, mark[32], count;
// lc左节点，rc右节点，root根节点的位置，mark记录是否为根节点，count输入数量

void deal(int n){
    printf("(");
    if(lc[n] * rc[n] > 1){
        deal(lc[n]);
        deal(rc[n]);
    }
    cout << Data[n];
    if(lc[n] * rc[n] < 0){
        if(lc[n] < 0) deal(rc[n]);
        if(rc[n] < 0) deal(lc[n]);
    }
    printf(")");
}

int main(){
    scanf("%d", &count);
    for(int i = 1; i <= count; i++){
        cin >> Data[i] >> lc[i] >> rc[i];
        // scanf("%s%d%d", &Data[i], &lc[i], &rc[i]);
        mark[lc[i]] = mark[rc[i]] = 1;
    }
    while(mark[root]) root++;
    deal(root);
    return 0;
}