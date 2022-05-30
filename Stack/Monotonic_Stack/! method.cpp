#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//單調遞增堆疊作為範例
stack <int> stk;
vector <int> data;

vector <int> m_push(int x){
	vector <int> v;
	
	if (stk.empty()){
		stk.push(x);
		return v;
	}
	
	while (!stk.empty() && stk.top() > x){
		v.push_back(stk.top());
		stk.pop();
	}
	stk.push(x);
	return v;
}

void show(){
	cout << "遭彈出元素\n";
	if (data.empty()) cout << "None";
	else cout << "依序:"; for (int i: data) cout << i << ' ';
	cout << '\n';
}

int main() {
	data = m_push(3); //stk = {3}
	show();
	data = m_push(5); //stk = {3, 5}
	show();
	data = m_push(6); //stk = {3, 5, 6}
	show();
	data = m_push(4); //stk = {3, 4}
	show();
	data = m_push(7); //stk = {3, 4, 7}
	show();
	data = m_push(2); //stk = {2}
	show();
}