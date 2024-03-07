#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node {
    string id;
    int gp, gm, gf, g;
};

map<string, int> mp;

bool cmp(const node &a, const node &b) {
    if(a.g == b.g) return a.id < b.id;
    return a.g > b.g;
}

int main() {
    string id;
    int p, m, n, tmp, f = 1;
    vector<node> ans, v;
    scanf("%d%d%d", &p, &m, &n);
    for(int i = 0; i < p; i++) {
        cin >> id >> tmp;
        if(tmp >= 200) {
            ans.push_back(node{id, tmp, -1, -1, 0});
            mp[id] = f++;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> id >> tmp;
        if(mp[id]) ans[mp[id] - 1].gm = tmp;
    }
    for(int j = 0; j < n; j++) {
        cin >> id >> tmp;
        if(mp[id]) {
            ans[mp[id] -1].gf = tmp;
            ans[mp[id] -1].g = tmp;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].gm > ans[i].gf)ans[i].g = int(ans[i].gm * 0.4 + ans[i].gf * 0.6 + 0.5);
    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].g >= 60) v.push_back(ans[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        printf("%s %d %d %d %d\n", v[i].id.c_str(), v[i].gp, v[i].gm, v[i].gf, v[i].g);
    }
    return 0;
}