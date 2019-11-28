#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
const int maxn = 123;

int line[maxn][maxn]; //邻接矩阵
int vis[maxn], nxt[maxn];   //标记visited, nxt存放第一列(发起匹配)
int n, m, p;

/**
在一个n*n的矩阵中，找n个数使得这n个数都在不同的行和列里并且要求这n个数中的最大值和最小值的差值最小。
**/

bool find(int x, int mid){
	
	for(int j = 1; j <= m; ++j){ //扫描第二列(等待匹配)
		//cout << j << "	" << vis[j] << "	" << line[x][j] << "	" << p << "    "  << p+mid << "	" << nxt[j] << endl;
		if(line[x][j] >=p && line[x][j] <= p+mid && !vis[j]){
			vis[j] = 1; //标记j为访问过
			if(nxt[j] == -1 || find(nxt[j], mid)){ //j未匹配 或 腾出来
				nxt[j] = x; //存放j
				return true;
			}
		}
	}
	return false;
}

bool match(int mid){

	memset(nxt, -1, sizeof(nxt));
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		//cout << "mid: " << mid <<  "	i: " << i << " 		find(i, mid) :" << find(i, mid) << endl;
				// if(find(i, mid)){
		// 	cnt++;
		// }
		if(!find(i, mid)){
			return false;
		}	
	}
	//return cnt == n;
	return true;

}

int slove(int minv, int maxv){
	int left = 0, right = maxv-minv;
	int ans = right;

	while(left <= right){
		int mid = left + (right - left)/2;

		bool ismatch = match(mid);
		for(p = minv; p + mid <= maxv; p++){
                	if(match(mid)){
                    		ismatch=true;
                    		break;
                	}
            }

		//cout << "mid:" << mid << " ismatch:" << ismatch << endl;
		if(ismatch){
			ans = mid;
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return ans;	
}

int main(){

	int t;
	while(cin >> t){
		if(t == 0){
			break;
		}	
		while(t--){
			cin >> n; //n个点
			m = n;
			memset(line, 0, sizeof(line));

			int maxv = 0, minv = INF;

			for(int i = 1; i <= n; ++i){
				for(int j = 1; j <= m; ++j){
					cin >> line[i][j];
		
					maxv = max(maxv, line[i][j]);
					minv = min(minv, line[i][j]);
				}
			}
			cout << slove(minv, maxv) << endl;
		}	
	}
	
	return 0;

}
