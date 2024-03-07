#include <iostream>
#include <vector>
using namespace std;

int V, E, N, Edges[10001][2], Distance[100001], Judge[1001], flag, a, b, c, d;
int Start, End, Index;

vector<int> R;

void deal(int Start, int Index, vector<int>R){
    for(int i = 0; i < R.size(); i++){
        int Min = 9999999, now = Judge[Index];
        for(int j = 0; j < R.size(); j++){
            if(!Judge[j] && Distance[j] != 9999999 && Distance[j] <= Min){
                if(Distance[j] < Min){
                    if(j == now) flag = 1;
                    else flag = 0;
                } else if(Distance[j] == Min){
                    if(j == now) flag = 1;
                }
                Min = Distance[j];
            }
        }
        if(!flag) return;
        ++Index;
        if(Index > V) return;
        Judge[now] = 1;
        for(int j = 1; j <= V; j++){
            if(!Judge[j] && Distance[j] > Distance[now] + Edges[now][j] && Edges[now][j] != 0) Distance[j] = Distance[now] + Edges[now][j];
        }
    }
};

int main(){
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; i++){
        scanf("%d%d%d", &a, &b, &d);
        Edges[a][b] = Edges[b][a] = d;
    }
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        flag = 1;
        fill(Judge, Judge + 1001, 0);
        fill(Distance, Distance + 100001, 9999999);
        for(int j = 0; j < V; j++){
            scanf("%d", &c);
            R.push_back(c);
        }
        Start = R[0];
        End = R[V - 1];
        Distance[Start] = 0;
        deal(Start, Index, R);
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}