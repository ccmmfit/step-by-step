#include<bits/stdc++.h>
using namespace std;

/**
搜索为v的数组下标
[left, right]
**/
int oldBinary(int *a, int n, int v){
	int left = 0, right = n-1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if(a[mid] < v){
			left = mid + 1;
		}else if(a[mid] > v){
			right = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

/**
求第一个为v的数组下标
[left, right)
不能判断找不到的情况： 小于a[0]会返回0, 大于a[n-1]时返回n+1
**/
int lowerBinary(int *a, int n, int v){
	int left = 0, right = n; //注意
	while(left < right){
		int mid = left + (right - left)/2;
		if(a[mid] < v){
			left = mid + 1;
		}else if(a[mid] >= v){ //注意
			right = mid; //注意
		}
	}
	return left;
}

/**
求最后一个为v的数组下标
[left, right）
小于a[0]会返回-1, 大于a[n-1]时返回n
**/
int upperBinary(int *a, int n, int v){
	int left = 0, right = n;
	while(left < right){
		int mid = left + (right - left)/2;
		if(a[mid] <= v){ //注意
			left = mid + 1;
		}else if(a[mid] > v){ //注意
			right = mid;
		}
	}
	return left-1;
}

/**
求最后一个为v的数组下标
(left, right]
小于a[0]会返回-1, 大于a[n-1]时返回n
**/
int upperBinary2(int *a, int n, int v){
	int left = -1, right = n-1; //注意
	while(left < right){
		int mid = right - (right - left)/2;
		if(a[mid] <= v){
			left = mid; //注意
		}else if(a[mid] > v){
			right = mid-1; //注意
		}
	}
	return left;
}

int main(){
	// 2 3 3 4 5 5 5 6 6 7 8
	int a[] = {2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 8};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "oldBinary: " << oldBinary(a, n, 5) << endl;
	cout << "lowerBinary: " << lowerBinary(a, n, 5) << endl;
	cout << "upperBinary: " << upperBinary(a, n, 5) << endl;	
	cout << "upperBinary2: " << upperBinary2(a, n, 5) << endl;
}