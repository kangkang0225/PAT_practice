#include <iostream>
#include <map>
using namespace std;

map<int, int> ans;
// 用于记录左子树右子树的位置
int N, Records[31], L, R;
// N为输入数量，Records为输入记录, index为ans索引

void sort(int index, int L, int R){
    if(L > R) return;
    int temp = L;
    for(int i = L + 1; i <= R; i++){
        if(Records[temp] > Records[i]) temp = i;
    }
    ans[index] = Records[temp];
    sort(index << 1, L, temp - 1);
    sort(index << 1 | 1, temp + 1, R);
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &Records[i]);
    sort(1, 1, N);
    for (auto it : ans) {
    if (it.first != 1) cout << ' ';
        cout << it.second;
    }
    return 0;
}