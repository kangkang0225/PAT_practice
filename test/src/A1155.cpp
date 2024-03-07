#include <iostream>
#include <vector>
using namespace std;

int N, Rec[1008], Max = 1, Min = 1;
// N为输入的总数，Rec为输入记录

vector<int> V;
// 输出的数据，类似一个栈

void func(int index){
    if(index * 2 > N && index * 2 + 1 > N){
        for(int i = 0; i < V.size(); i++){
            printf("%d%c", V[i], ((i == V.size() - 1) ? '\n' : ' '));
        }
    } else {
        if(Rec[index * 2 + 1]) {
            V.push_back(Rec[index * 2 + 1]);
            func(index * 2 + 1);
            V.pop_back();
        }
        V.push_back(Rec[index * 2]);
        func(index * 2);
        V.pop_back();
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &Rec[i]);
    V.push_back(Rec[1]);
    func(1);
    if(Rec[1] >= Rec[2]){
        for(int i = 2; i <= N; i++){
            if(Rec[i / 2] < Rec[i]) Max--; 
        }
        if(Max == 1) {
            printf("Max Heap\n");
            return 0;
        }
    } else if(Rec[1] <= Rec[2]){
        for(int i = 2; i <= N; i++){
            if(Rec[i / 2] > Rec[i]) Min--;
        }
        if(Min == 1) {
            printf("Min Heap\n");
            return 0;
        }
    }
    printf("Not Heap\n");
}