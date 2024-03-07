#include <iostream>
#include <vector>
using namespace std;

int A, B, N, M, Record[11][1001], Out[11], Mark[200001];
// A B为初始输入的两个数，N为参加游戏的人数(行数)，M为游戏轮数（列数），Record为游戏记录，Out为出局者记录，Mark判断是否重复
vector<int> V(2);

int main(){
    scanf("%d%d", &A, &B);
    Mark[A] = Mark[B] = 1;
    V[0] = A;
    V[1] = B;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++) scanf("%d", &Record[i][j]);
    // 输入记录
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            int flag = 0;
            // 标记，若为0则不能为前两个数相减得到，若为-1则与前面的数字重复
            if(Out[j] == 1) continue;
            // 如果该玩家之前已经被判定为输，则跳过此轮直接来到下一轮
            if(Mark[Record[j][i]] == 1) {
            // 如果该玩家说出的数字和之前的重复
                Out[j] = 1;
                flag = -1;
                // 则将该玩家记录为输,并将其标记为这一轮输出的对象
            }
            for(auto it: V){
                if(Mark[it + Record[j][i]] == 1){
                    Mark[Record[j][i]] = 1;
                    flag++;
                    V.push_back(Record[j][i]);
                    break;
                }
            }
            if(flag <= 0){
                Out[j] = 1;
                printf("Round #%d: %d is out.\n", i, j);
                // 如果标记不大于零，则对其进行标记，并输出输了的玩家与轮数
            }
        }
    }
    int flag2 = 0;
    for(int i = 1; i <= N; i++){
        if(!Out[i]){
            if(!flag2){
                printf("Winner(s):");
                flag2++;
            }
            printf(" %d", i);
        }
    }
    if(!flag2) printf("No winner.");
}