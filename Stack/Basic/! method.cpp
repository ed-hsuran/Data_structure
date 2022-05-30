#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack <int> stk;
	//建構式 stack <Type> stk
	stk.push(4);
	//將元素推入stk頂端   stk = {4}
	stk.push(7);
	//                    stk = {4, 7}
	stk.pop();
	//將stk頂端之元素彈出 stk = {4}
	stk.top();
	//檢視stk頂端元素     return 4
	stk.size();
	//回傳stk元素個數     return 1
	stk.empty();
	//回傳stk是否為空堆疊 return 0(false)
	
	/* stk.pop() stk.top()
	需在 stk.empty() == 0 的情況下
	不然會報錯 */
}