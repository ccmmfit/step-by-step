#include<bits/stdc++.h>
using namespace std;
const int maxn = 1234;
int line[maxn][maxn]; //邻接矩阵
int vis[maxn], nxt[maxn];   //标记visited, nxt存放第一列(发起匹配)
int n, m;

bool find(int x){
	
	for(int j = 1; j <= m; ++j){ //扫描第二列(等待匹配)
		if(line[x][j] && !vis[j]){
			vis[j] = 1; //标记j为访问过
			if(nxt[j] == 0 || find(nxt[j])){ //j未匹配 或 腾出来
				nxt[j] = x; //存放j
				cout << "match: " << x << " -- " << j << endl; 
				return true;
			}
		}
	}
	return false;
}


int main(){

	int t, u, v;
	cin >> t >> n >> m; //n个点
	while(t--){
		cin >> u >> v;
		line[u][v] = 1;
	}

	cout << endl << "=================" << endl;

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		if(find(i)){
			cnt += 1;
		}
	}
	cout << cnt << endl;
	for(int i = 1; i <= n; ++i){
		cout << nxt[i] << " -- " << i << endl;
	}
	return 0;
}

/**
7 4 4
1 1
1 2
2 2
2 3
3 1
3 2
4 3
**/
