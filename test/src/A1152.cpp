#include <iostream>
#include <string>
using namespace std;

bool is_Prime(int n) {
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    int n, m;
    cin >> n >> m >> s;
    for(int i = 0; i < n - m; i++) {
        string t = s.substr(i, m);
        int tmp = stoi(t);
        if(is_Prime(tmp)) {
            printf("%s\n", t.c_str());
            return 0;
        }
    }
    printf("404\n");
    return 0;
}