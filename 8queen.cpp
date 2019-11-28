#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
const int maxn = 123;
int cnt;

int nxt[maxn];   //nxt存放第一列(发起匹配)
int n, m;


bool check(int x){
	for(int i = 1; i < x; ++i){
		if(nxt[x] == nxt[i] || abs(nxt[x] - nxt[i]) == x-i){
			return false;
		}
	}
	return true;
}

void print(){
	for (int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
		 	cout << j != nxt[i] ? "0" : "1";	
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int x, int n){

	if(x > n && n > 0)  { //当行号超过n时，说明满足了条件，总情况数+		
		cnt++;
		print();
	} 
	  
	for(int j = 1; j <= m; ++j){ //遍历列
		//cout << nxt[x] << " -- " << j << endl;
		nxt[x] = j;
		if(check(x)){		
			dfs(x+1, n);
		}
	}
}


int main(){

	int t;
	while(cin >> n){
		
		m = n;
		memset(nxt, 0, sizeof(nxt));
		cnt = 0;
		dfs(1, n);
		cout << cnt << endl;
		
	}
	
	return 0;

}

