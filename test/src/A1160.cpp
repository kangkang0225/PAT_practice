#include <iostream>
#include <vector>
using namespace std;

int N, K[6], m[6];
// N为输入的行数，K[]为所需位数, m[]为位数之和, n为加一位数之和

vector<vector<int>> ans(5), n(5), flag(5);

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d%d", &K[i], &m[i]);
    }
    for(int i = 1; i <= N; i++){
        if((m[i] / 9) == (K[i] - 1) && m[i] % 9 == 0){
            flag[i - 1].push_back(1);
            int a = m[i] / 9 - 1;
            for(int j = 1; j <= 8; j++){
                int num = j * (a + 2) + (9 - j) * (a + 1) + 9 * a;
                ans[i - 1].push_back(num);
                n[i - 1].push_back(10);
            }
        }
        if(m[i] / 9 > (K[i] * 9)){
            flag[i - 1].push_back(-1);
        }
        if(m[i] ){}
    }
}
