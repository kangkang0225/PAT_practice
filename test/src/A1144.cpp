#include <iostream>
#include <map>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    map<int, int> m;
    for(int i = 0; i < N; i++){
        int a = 0;
        scanf("%d", &a);
        m[a] = 1;
    }
    int num = 0;
    while(++num){
        if(m[num] == 0) break;
    }
    cout << num;
    return 0;
}