#include <iostream>
using namespace std;

char Inp[26][7][5], Out[100][100];

string s;

int main(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            Out[i][j] = ' ';
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < 5; k++){
                scanf(" %c", &Inp[i][j][k]);
            }
        }
    }
    getchar();
    getline(cin, s);
    int flag = 0;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        while(j < s.size() && s[j] >= 'A' & s[j] <= 'Z') j++;
        if(i == j) continue;
        for(int k = i; k < j; k++){
            for(int l = 0; l < 7; l++){
                for(int m = 0; m < 5; m++){
                    Out[l][m + (k - i) * 6] = Inp[s[k]- 'A'][l][m];
                }
            }
        }
        if(flag){
            printf("\n");
        }
        for(int k = 0; k < 7; k++){
            flag = 1;
            for(int l = 0; l < (j - i) * 6 - 1; l++) printf("%c", Out[k][l]);
            cout << '\n';
        }
        i = j;
    }
    return 0;
}