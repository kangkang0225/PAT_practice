#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int N, M, Birth[100001], A_of_C, Oldest, f;
// N为校友会人数，M为来参会的人数, Birth为校友会生日, A_of_C是参会的人中校友会人数

string temp, ans, ans0, oldest = "99999999", oldest_of_g = "99999999";
// 校友会纪录，参会记录

set<string> A;

int toi[8];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        cin >> temp;
        A.insert(temp);
    }
    // 输入校友会记录

    scanf("%d", &M);
    for(int i = 1; i <= M; i++){
        cin >> temp;
        if(A.count(temp)){
            A_of_C++;
            string birth = temp.substr(6, 8);
            if(birth < oldest) {
                oldest = birth;
                ans = temp;
            }
        } else {
            string birth = temp.substr(6, 8);
            if(birth < oldest_of_g) {
                oldest_of_g = birth;
                ans0 = temp;
            }
        }
    }
    // 比对校友会中哪些人来了并计算人数，并算出最大生日

    if(A_of_C){
        cout << A_of_C << "\n";
        cout << ans << "\n";
    } else {
        cout << A_of_C << "\n";
        cout << ans0 << "\n";
    }
    return 0;
}