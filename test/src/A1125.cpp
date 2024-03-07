#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int result = *v.begin();
    for(int i = 1; i < n; i++) {
        result = (result + v[i]) / 2;
    }
    printf("%d\n", result);
    return 0;
}