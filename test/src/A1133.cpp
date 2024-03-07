#include <iostream>
using namespace std;

int A, D, N, index1[100009] = {-2}, i1, index2[100009] = {-2}, i2, index3[100009] = {-3}, i3;

struct node {
    int Address, Data, Next;
}Linklist[100009], ans[100009];

int main() {
    scanf("%d%d%d", &A, &D, &N);
    for(int i = 0; i < D; i++) {
        int a, d, n;
        scanf("%d%d%d", &a, &d, &n);
        Linklist[a].Data = d;
        Linklist[a].Next = n;
    }
    int address = A;
    for(int i = 0; i < D; i++) {
        if(Linklist[address].Data < 0) index1[i1++] = address;
        else if(Linklist[address].Data <= N) index2[i2++] = address;
        else if(Linklist[address].Data > N) index3[i3++] = address;
        address = Linklist[address].Next;
    }
    for(int j = 0; j < i1; j++) {
        ans[index1[j]].Data = Linklist[index1[j]].Data;
        if(j != 0) {
            int tmp = j - 1;
            ans[index1[tmp]].Next = index1[j];
        }
    }
    for(int j = 0; j < i3; j++) {
        ans[index3[j]].Data = Linklist[index3[j]].Data;
        if(j != 0) {
            int tmp = j - 1;
            ans[index3[tmp]].Next = index3[j];
        }
    }
    for(int j = 0; j < i2; j++) {
        ans[index2[j]].Data = Linklist[index2[j]].Data;
        if(j != 0) {
            int tmp = j - 1;
            ans[index2[tmp]].Next = index2[j];
        }
    }
    int begin = 0;
    if(i1 > 0 && i2 > 0 && i3 > 0) {
        begin = index1[0];
        ans[index1[--i1]].Next = index2[0];
        ans[index2[--i2]].Next = index3[0];
        ans[index3[--i3]].Next = -1;
    } else if(i1 > 0 && i2 > 0) {
        begin = index1[0];
        ans[index1[--i1]].Next = index2[0];
        ans[index2[--i2]].Next = -1;
    } else if(i2 > 0 && i3 > 0) {
        begin = index2[0];
        ans[index2[--i2]].Next = index3[0];
        ans[index3[--i3]].Next = -1;
    } else if(i1 > 0 && i3 > 0) {
        begin = index1[0];
        ans[index1[--i1]].Next = index3[0];
        ans[index3[--i3]].Next = -1;
    } else if(i1 > 0) {
        begin = index1[0];
        ans[index1[--i1]].Next = -1;
    } else if(i2 > 0) {
        begin = index2[0];
        ans[index2[--i2]].Next = -1;
    } else if(i3 > 0) {
        begin = index3[0];
        ans[index3[--i3]].Next = -1;
    }
    for(int i = 0; i < D; i++) {
        if(i != D - 1) printf("%05d %d %05d\n", begin, ans[begin].Data, ans[begin].Next);
        else printf("%05d %d %01d\n", begin, ans[begin].Data, ans[begin].Next);
        begin = ans[begin].Next;
    }
}