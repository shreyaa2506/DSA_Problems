#include <bits/stdc++.h> 


void insertintostack(stack<int>&stack, int num){
	if (stack.empty()){
		stack.push(num);
	}
	else{
		if(num>stack.top()){
			stack.push(num);
		}
		else{
			int num1 = stack.top();
			stack.pop();
			insertintostack(stack,num);
			stack.push(num1);
		}
	}

}
void sortStack(stack<int> &stack)
{
	if (stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	insertintostack(stack,num);
}