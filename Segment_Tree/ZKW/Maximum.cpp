//參考網址 蛋餅的競程隨筆 Iterative-SegmentTree
//https://omeletwithoutegg.github.io/2019/12/07/Iterative-SegmentTree/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//zkw線段樹--(迭代型線段樹)
//區間最大值
//以下為左閉右開

const int MAXN = 50005;
ll n, arr[MAXN], zkw[MAXN<<1], tag[MAXN];

void init(ll v[]){ //建樹
	for (int i=0; i<n; i++) zkw[i+n] = v[i]; //底層元素
	for (int i=n-1; i>0; i--) zkw[i] = max(zkw[i<<1], zkw[i<<1|1]); //往上拉
} // |或閘 --> 此用於偶數則++

void update(int i, ll v){ //打懶標
	zkw[i] += v;
	if (i < n) tag[i] += v; //葉節點沒得推
}

void push(int i){ //推懶標，將標記由上而下推給子節點
	for (int h=__lg(n); h>=0; h--){
		int p = i >> h; //越祖先越優先
		if (!tag[p>>1]) continue;
		update(p, tag[p>>1]);
		update(p^1, tag[p>>1]);
		tag[p>>1] = 0; //記得推完撤掉標記
	}
}

void pull(int i){ //更新邊界，更改結果下往上拉
	while (i > 1){
		zkw[i>>1] = max(zkw[i], zkw[i^1]) + tag[i>>1];
		i >>= 1;
	}
}

void modify(int l, int r, int v){  //區間修改
	int _l = l, _r = r;
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1) update(l++, v); //如果 l 是右子樹則右移
		if (r & 1) update(--r, v); //如果r-1是左子樹則左移
	}
	pull(_l+n); //邊界重新更新
	pull(_r+n-1);
} // ^互斥或閘 --> 此用於偶數++ 奇數--

ll query(int l, int r){ //詢問區域最大值
	ll ans = -1e18;
	push(l+n); //懶標推下去
	push(r+n-1);
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l & 1) ans = max(ans, zkw[l++]); //如果 l 是右子樹則右移
		if (r & 1) ans = max(ans, zkw[--r]); //如果r-1是左子樹則左移
	}
	return ans;
} // &閘 --> 此用於判定奇偶(左右子樹)

void show(){ //打印當前線段樹
	cout << "\n/我是zkw線段樹\\\n";
	for (int i=1; i<(n<<1); i++){
		cout << zkw[i] << " ";
		if (__lg(i) != __lg(i+1)) cout << "\n";
	}
	cout << "\\我是zkw線段樹/\n";
}

void show_tag(){ //打印未處理懶標
	bool noexist = true;
	cout << "\n有懶標:\n";
	for (int i=1; i<(n<<1); i++){
		if (tag[i]) printf("%d號: 標記%d\n", i, tag[i]), noexist = false;
	}
	if (noexist) cout << "None\n";
	cout << "\n";
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
	modify(2, 5, 7); //第2 ~ 4號各加 7
	modify(3, 8, 5); //第3 ~ 7號各加 5
	show();	show_tag();
	cout << "第0個到第3個的最大元素? " << query(0, 4) << "\n";
	show();	show_tag();
	cout << "第4個到第7個的最大元素? " << query(4, 8) << "\n";
	show();	show_tag();
}
