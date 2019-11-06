#include<bits/stdc++.h>
using namespace std;
int step;

/**
河内之塔(TowersofHanoi)是法国人M.Claus(Lucas)于1883年从泰国带至法国的，河内为越战时北越的首都，即现在的胡志明市；
1883年法国数学家 EdouardLucas曾提及这个故事，据说创世 纪时Benares有一座波罗教塔，是由三支钻石棒（Pag）所支撑，
开始时神在第一根棒上放置64 个由上至下依由小至大排列的金盘（Disc），并命令僧侣将所有的金盘从第一根石棒移至第三根 石棒，
且搬运过程中遵守大盘子在小盘子之下的原则，若每日仅搬一个盘子，则当盘子全数搬 运完毕之时，此塔将毁损，而也就是世界末日来临之时。
**/

/**
将一个规模为N的问题划分为k个规模较小的子问题

正向解释: n个盘子都在棒A处，先将n-1个盘子 A->B，再将第n个盘子 A->C, 然后将n-1个盘子 B->C
		 n-1个盘子都在棒B处，先将n-2个盘子 B->A, 再将第n-1个盘子 B->C, 然后将n-2个盘子 A->C
		 n-2个盘子都在棒A处, ...
		 .
		 .
		 .
逆向解释：1个盘子时，A->C
		 2个盘子时，A->B, A->C, B->C
		 3个盘子时，A->C, A->B, C->B, A->C, B->A, B->C, A->C
		 .
		 .
		 .
**/
void slove(int n, char A, char B, char C){
	if(n == 1){
		//A->C
		cout << "move from " << A << " to " << C << endl;
	}else{
		//A->B  A->C  B->C
		slove(n-1, A, C, B);
		cout << "move from " << A << " to " << C << endl;
		slove(n-1, B, A, C);
	}
	step++;
}

/**
n为奇数次，先从A->C;
n为偶数次，先从A->B;
总步数step: 2^n-1
**/
int main(){
	int n;
	while(cin >> n){
		step = 0;
		slove(n, 'A', 'B', 'C');

		cout << endl << "step:" << step << endl;
		cout << "=====================" << endl;
	}
	
	return 0;
}
