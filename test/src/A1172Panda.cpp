#include <stdio.h>

const int maxn = 100010;

int main(){
    int pandas_weight[maxn]; // 熊猫体积
    int pandas_milk[maxn]; // 每只熊猫喝奶量
    for(int i = 0; i < maxn; i++) pandas_weight[i] = -1; // 体积数组初始化
    for(int i = 0; i < maxn; i++) pandas_milk[i] = 0; // 体积数组初始化
    int num; // 熊猫的数量
    scanf("%d", &num);
    for(int i = 0; i < num; i++) scanf("%d", &pandas_weight[i]);

    // 判定成功的起始指针index和探路指针forward
    int index = 0, forward = 0;
    pandas_milk[index] = 200;
    while(forward < num){
        if(pandas_milk[forward] == 100 && index != 0){ // 每次迭代之前判定新加内容是否合法
            for(int i = index + 1; i <= forward; i++){
                pandas_milk[i] += 100;
            }
        } else if(pandas_milk[forward] == 100){
                for(int i = index; i <= forward; i++){
                pandas_milk[i] += 100;
            }
        }else { // 合法条件下
            if(pandas_weight[forward + 1] > pandas_weight[forward]){ // 如果后一个熊猫大于现在这个，那么加奶并添加到区间中去
                pandas_milk[forward + 1] = pandas_milk[forward] + 100;
                forward++;
            } else if(pandas_weight[forward + 1] < pandas_weight[forward]){ // 小于，减奶添加
                pandas_milk[forward + 1] = pandas_milk[forward] - 100;
                forward++;
            } else{ // 等于，等奶添加
                pandas_milk[forward + 1] = pandas_milk[forward];
                forward++;
            }
        }

        if(pandas_milk[forward - 1] == 200 && pandas_milk[forward] >= 200 && pandas_milk[forward - 2] >= 200) index = forward - 1; // 如果找到下一个谷底，迭代上一个谷底
    }

    int res = 0;
    for(int i = 0; i < num; i++){
        res += pandas_milk[i];
    }
    printf("%d", res);
    return 0;
}