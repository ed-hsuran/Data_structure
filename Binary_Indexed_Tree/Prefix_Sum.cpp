//參考網址 WiwiHo的競程筆記
//https://cp.wiwiho.me/fenwick-tree/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//二元搜索樹(BIT)
//動態前綴和範例

ll n, BIT[500005];

int lowbit(int i){ //取得為 1的最低位元
	return (i & -i);
}

void modify(int i, int v){ //修改單點影響區間
	while (i <= n){
		BIT[i] += v;
		i += lowbit(i);
	}
}

ll query(int i){ //回傳1~i的區間和
	ll ans = 0;
	while (i > 0){
		ans += BIT[i];
		i -= lowbit(i);
	}
	return ans;
}

int main(){
	n = 10;
	modify(1, 5); modify(2, 8);
	modify(3, 6); modify(4, 10);
	modify(5, 4); modify(6, 7);
	modify(7, 2); modify(8, 1);
	modify(9, 9); modify(10, 3);
	// {5, 8, 6, 10, 4, 7, 2, 1, 9, 3}
	// 前綴和 = {5, 13, 19, 29, 33, 40, 42, 43, 52, 55}
	cout << query(6);
}