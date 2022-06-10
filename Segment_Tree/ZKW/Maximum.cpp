#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//zkw線段樹--(迭代型線段樹)
//區間最大值

const int MAXN = 5005;
ll n, arr[MAXN], zkw[MAXN<<1];

void init(ll v[]){ //建樹
	for (int i=0; i<n; i++) zkw[i+n] = v[i]; //底層元素
	for (int i=n-1; i>0; i--) zkw[i] = max(zkw[i<<1], zkw[i<<1|1]); //往上拉
} // |或閘 --> 此用於偶數則++

void modify(int i, int v){ //單點修改
	for (zkw[i+=n] = v; i>1; i>>=1) zkw[i>>1] = max(zkw[i], zkw[i^1]);
} // ^互斥或閘 --> 此用於偶數++ 奇數--

ll query(int l, int r){ //詢問區域最大值
	ll ans = -1e18;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1) ans = max(ans, zkw[l++]); //如果 l 是右子樹則右移
		if (r & 1) ans = max(ans, zkw[--r]); //如果r-1是左子樹則左移
	}
	return ans;
} // &閘 此用於判定奇偶(左右子樹)

void show(){
	cout << "/我是zkw線段樹\\\n";
	for (int i=1; i<(n<<1); i++){
		cout << zkw[i] << " ";
		if (__lg(i) != __lg(i+1)) cout << "\n";
	}
	cout << "\\我是zkw線段樹/\n";
}

int main(){
	n = 8;
	arr[0] = 5;	arr[1] = 3;
	arr[2] = 4;	arr[3] = 8;
	arr[4] = 2;	arr[5] = 9;
	arr[6] = 6; arr[7] = 7;
	// {5, 3, 4, 8, 2, 9, 6, 7}
	init(arr);
	show();
	modify(2, 12);
	modify(6, 10);
	show();
	cout << "第0個到第4個的最大元素? " << query(0, 5) << "\n";
	cout << "第3個到第7個的最大元素? " << query(3, 8) << "\n";
}