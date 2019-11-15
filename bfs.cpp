#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> E; //邻接表
const int maxn = 12345;
int vis[maxn];   //标记visited
queue<int> q;    //队列

void bfs(int v){
	vis[v] = 1; //访问顶点v并标记
	q.push(v);  //入队列
	while(!q.empty()){
		int u = q.front(); //获取队头
		cout << u << "  "; 
		q.pop(); //出队列
		for(int j = 0; j < E[u].size(); ++j){ //遍历u的邻接边
			int near_u = E[u][j];
			if(!vis[near_u]){ //如果未访问过
				vis[near_u] = 1; //访问顶点near_u并标记
				q.push(near_u);  //入队列
			}
		}
	}
}


int main(){

	int n;
	cin >> n; //n个点
	for(int i = 0; i < n; i++){
		int m, temp;
		cin >> m;
		vector<int> v;
		for(int j = 0; j < m; j++){
			cin >> temp;
			v.push_back(temp);
		}
		E.push_back(v);
	}

	cout << endl << "=================" << endl;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			bfs(i);
			cout << endl;
		}
	}
	return 0;
}

/**
8
3 5 4 7
1 4
2 6 4
1 7
3 0 2 1
2 0 6
2 5 2
2 0 3
*/