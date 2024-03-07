#include <stdio.h>

struct tree{
    int value;
    tree* left;
    tree* right;
};

int main(){
    int n;
    int arr[2][n];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[1][0] == arr[0][1]){
            tree tree1;
            tree1.value = arr[1][0];
        }
    }
}