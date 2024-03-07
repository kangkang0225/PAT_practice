#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct node {
    string id, area;
    int score;
    void upper(string school) {
        for(int i = 0; i < school.size(); i++) {
            if(school[i] >= 'A' && school[i] <= 'Z') this->area[i] = school[i] + ('a' - 'A');
        }
    }
    node() {
        score = 0;
    }
} rec[100009];

struct node_ans {
    int rank, tws, ns;
    string school;
    node_ans() {
        rank = tws = ns = 0;
    }
} ans[100009];

int N, index_ans;

set<string> school;

bool cmp(node_ans &a, node_ans &b) {
    if(a.tws == b.tws) {
        if(a.ns == b.ns) return a.school < b.school;
        return a.ns < b.ns;
    }
    return a.tws > b.tws;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin >> rec[i].id >> rec[i].score >> rec[i].area;
        rec[i].upper(rec[i].area);
        int presize = school.size();
        school.insert(rec[i].area);
        if(presize != school.size()) {
            ans[index_ans].school = rec[i].area;
            if(rec[i].id[0] == 'A') ans[index_ans].tws = rec[i].score;
            else if(rec[i].id[0] == 'B') ans[index_ans].tws += rec[i].score / 1.5;
            else if(rec[i].id[0] == 'T') ans[index_ans].tws += rec[i].score * 1.5;
            ans[index_ans].ns++;
            index_ans++;
        } else {
            for(int j = 0; j < index_ans; j++) {
                if(ans[j].school == rec[i].area) {
                    int anscore = 0;
                    if(rec[i].id[0] == 'A') ans[j].tws += rec[i].score;
                    else if(rec[i].id[0] == 'B') ans[j].tws += rec[i].score / 1.5;
                    else if(rec[i].id[0] == 'T') ans[j].tws += rec[i].score * 1.5;
                    ans[j].ns++;
                }
            }
        }
    }
    sort(ans, ans+index_ans, cmp);
    int judge = 0;
    printf("%d\n", index_ans);
    for(int i = 0; i < index_ans; i++) {
        if(i == 0) {
            printf("%d %s %d %d\n", 1, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
            continue;
        }
        if(ans[judge].tws == ans[i].tws) {
            printf("%d %s %d %d\n", judge + 1, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
            continue;
        }
        printf("%d %s %d %d\n", i + 1, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
        judge = i;
    }
    return 0;
}