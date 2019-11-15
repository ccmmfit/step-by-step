#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> E; //邻接表
const int maxn = 12345;
int vis[maxn];   //标记visited

void dfs(int v){
	vis[v] = 1; //标记顶点v为visited
	cout << v << " ";
	for(int j = 0; j < E[v].size(); ++j){ //遍历顶点v的邻接边
		int nearv = E[v][j];
		//cout << "near " << nearv << endl;
		if(!vis[nearv]){ //如果未访问过
			dfs(nearv);  //递归dfs
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
			dfs(i);
			cout << endl;
		}
	}
	return 0;
}

/**
11
2 4 5
1 8
1 3
2 2 8
2 0 6
2 0 7
1 4
1 5
2 1 3
2 3 10
1 9
**/