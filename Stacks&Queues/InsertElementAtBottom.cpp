void solve(stack<int>& s, int x){
    if (s.empty()){
        s.push(x);
        return;
    }
    int ch = s.top();
    s.pop();
    solve(s,x);
    s.push(ch);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}