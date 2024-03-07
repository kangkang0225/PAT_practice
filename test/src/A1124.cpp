#include <iostream>
#include <set>
#include <vector>
using namespace std;

string res[1009];
int M, N, S, f, index[1009];
set<string> m;
vector<string> ans;

int main() {
    scanf("%d%d%d", &M, &N, &S);
    for(int i = 1; i <= M; i++) {
        cin >> res[i];
    }
    if(S > M) {
        printf("Keep going...\n");
        return 0;
    }
    int goal = S;
    for(int i = 0; i < N; i++) {
        if(i != 0) goal += N;
        if(goal > M) break;
        int pre = m.size();
        m.insert(res[goal]);
        int now = m.size();
        if(now > pre) {
            ans.push_back(res[goal]);
            f++;
        }
        else {
            for(int j = goal; j <= M; j++) {
                int pre = m.size();
                m.insert(res[j]);
                int now = m.size();
                if(now > pre) {
                    ans.push_back(res[j]);
                    f++;
                    break;
                }
            }
        }
    }
    if(f) {
        for(int i = 0; i < f; i++) cout << ans[i] << "\n";
    } else printf("Keep going...\n");
    return 0;
}