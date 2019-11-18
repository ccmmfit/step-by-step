#include<bits/stdc++.h>
using namespace std;

/**
根据上一行数据求当前行
**/
vector<int> getv(vector<int> a, int n){
	vector<int> ans;
	ans.push_back(1);
	for(int i = 1; i < a.size(); ++i){
		ans.push_back(a[i-1] + a[i]);
	}
	ans.push_back(1);
	return ans;
}

void paint(int n){
	vector<int> a;
	a.push_back(1);
	for(int i = 1; i <= n; ++i){
		int j = 1;
		for(; j < n - i + 1; ++j){
			cout << " ";
		}
		if(i != 1){
			a = getv(a, i);
		}		
		for(int k = 0; j <= n + i -1; ++k){
			if(j != n - i + 1){
				cout  << " ";
				j++;
			}

			cout << a[k];
			j++;
		}
		for(; j <= n; ++j){
			cout  << " ";
		}
		cout << endl;
	}
}

/**
计算组合C(n, m) n为下标， m为上标
**/
int combi(int n, int m){
	int res = 1;

	for(int i = 1; i <= m; ++i){
		res = res*(n-i+1)/i;
	}

	return res;
}

void paint2(int n){ 

    for(int i = 0; i < n; ++i){ 
    	for(int j = 0; j <= i; j++){ 
    	   int k;/* 排版设定开始 */ 
    	   if(j==0){ 
    	   		for(k = 0; k <= n-i; k++) 
    	   		  cout << " ";
    	   	}else{ 
    	   		cout << " ";
    	   	}/* 排版设定结束 */ 
    	   	cout << combi(i, j);
		} 
		cout << endl;
	}
}



int main(){
	int n;
	while(cin >> n){
		paint(n);
		cout << endl << endl;
		paint2(n);
	}
	
	return 0;
}