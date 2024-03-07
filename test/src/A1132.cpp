#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        string s, s1, s2;
        cin >> s;
        s1 = s.substr(0, s.size() / 2);
        s2 = s.substr(s.size() / 2, s.size());
        if(stoi(s1) * stoi(s2) != 0 && stoi(s) % (stoi(s1) * stoi(s2)) == 0) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}