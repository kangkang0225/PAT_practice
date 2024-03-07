#include <iostream>
#include <vector>
using namespace std;

int MSize, N, M, res[10009], Find[10009], Time;

struct node {
    int value, full;
    node() {
        value = full = 0;
    }
};

int foundPrime(int n) {
    int f = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) f = 0;
    }
    if(!f) return foundPrime(n + 1);
    else return n;
}

int main() {
    scanf("%d%d%d", &MSize, &N, &M);
    int prime = foundPrime(MSize);
    for(int i = 0; i < N; i++) scanf("%d", &res[i]);
    for(int i = 0; i < M; i++) scanf("%d", &Find[i]);
    vector<node> hashtable(prime);
    for(int i = 0; i < N; i++) {
        int tmp = 0;
        for(int j = 0 ; j < prime; j++) {
            tmp++;
            int index = (res[i] + j * j) % prime;
            if(!hashtable[index].full) {
                hashtable[index].value = res[i];
                hashtable[index].full = 1;
                break;
            }
        }
        if(tmp == prime) printf("%d cannot be inserted.\n", res[i]);
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j <= prime; j++) {
            Time++;
            int index = (Find[i] + j * j) % prime;
            if(Find[i] == hashtable[index].value || !hashtable[index].full) break;
        }
    }
    double ave = Time * 1.0 / M;
    printf("%.1lf\n", ave);
    return 0;
}