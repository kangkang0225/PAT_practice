// 5个城市 6条路 从0号城市到达2号城市
// 5个城市中的救援队数量分别是1 2 1 5 3
// 第1，2个数分别是路的始末城市，第三个数为长度
// 输出：最短路的数量，最大聚集的救援队数量
#include <stdio.h>

int main(){
	int city[4] = {};
	scanf("%d%d%d%d", &city[0], &city[1], &city[2], &city[3]);
	int rescue_number[city[0]] = {};
	for(int i = 0; i < city[0]; i++){
		scanf("%d", &rescue_number[i]);
	}
	int road[city[1]][3] = {};
	for(int i = 0; i < city[1]; i++){
		scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
	}
	int sign[city[1]] = {};
	int max = 0;
	for(int i = 0; i < city[1]; i++){
		
	}
}