#include <bits/stdc++.h>
#define str string
#define pb push_back
using namespace std;

string s;
int priority(string op){ //判斷運算子優先權&判別運算子
	if (op == "^") return 3;
	if (op == "*" || op == "/") return 2;
	if (op == "+" || op == "-") return 1;
	return 0;
}

vector <string> convert(string s){ //將字串轉為vector
	string tmp = "";
	vector <string> collect;
	for (char c: s){
		if (priority(str{c}) || c == '(' || c == ')'){
			if (tmp != "") collect.pb(tmp);
			collect.pb(str{c});
			tmp = "";
		}
		else tmp.append(str{c});
	}
	collect.pb(tmp);
	return collect;
}

vector <string> infix_postfix(vector <string> s){ //中序式轉後序式
	stack <string> ops;
	vector <string> post;
	for (string c: s){
		if (c == "("){
			ops.push(c);
		}
		else if (c == ")"){
			while (ops.top() != "("){
				post.pb(ops.top());
				ops.pop();
			}
			ops.pop();
		}
		else if (priority(c)){
			while (!ops.empty() && priority(ops.top()) >= priority(c)){
				post.pb(ops.top());
				ops.pop();
			}
			ops.push(c);
		}
		else post.pb(c);
	}
	while (!ops.empty()){
		post.pb(ops.top());
		ops.pop();
	}
	return post;
}

int cal(int a, int b, string op){ //運算式
	if (op == "^") return pow(a, b);
	if (op == "*") return (a * b);
	if (op == "/") return (a / b);
	if (op == "+") return (a + b);
	if (op == "-") return (a - b);
}

int sum(vector <string> s){ //後序計算出結果
	stack <int> help;
	for (auto tmp: s){
		if (priority(tmp)){
			int b = help.top(); help.pop();
			int a = help.top(); help.pop();
			help.push(cal(a, b, tmp));
		}
		else help.push(stoi(tmp));
	}
	return help.top();
}

int main() {
	s = "((3+4)*2)^3";
	vector <string> data = convert(s);
	cout << sum(infix_postfix(data));
}