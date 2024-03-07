#include <iostream>
using namespace std;

int N, num, f;

int main() {
    scanf("%d", &N);
    while(N--) {
        f = 0;
        scanf("%d", &num);
        int board[num + 1][num + 1];
        for(int i = 0; i < num + 1; i++) {
            for(int j = 0; j < num + 1; j++) board[i][j] = 0;
        }
        for(int i = 1; i < num + 1; i++) {
            int tmp = 0;
            scanf("%d", &tmp);
            board[tmp][i] = 1;
        }
        int column = 0, row = 0;
        for(int i = 1; i < num + 1; i++) {
            for(int j = 1; j < num + 1; j++) {
                row += board[i][j];
            }
            if(row > 1) f = 1;
            row = 0;
        }
        for(int i = 1; i < num + 1; i++) {
            for(int j = 1; j < num + 1; j++) {
                column += board[j][i];
            }
            if(column > 1) f = 1;
            column = 0;
        }
        
        if(!f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}