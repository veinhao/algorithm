#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool consle(string str)
{
	stack<char> st;
	st.push(-1);
	int i=0;
	
	while(i<str.length())
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
			st.push(str[i]);
		else if(str[i]==')'||st.top()==-1)
		{
			if(st.top()!='(')
				return false;
			else
				st.pop();
		}
		else if(str[i]==']'||st.empty())
		{
			if(st.top()!='[')
				return false;
			else
				st.pop();
		}
		else if(str[i]=='}'||st.empty())
		{
			if(st.top()!='{')
				return false;
			else
				st.pop();
		}
		i+=1;
	}
	if(st.top()==-1)
		return true;
	else
		return false;
	
}

int main()
{
	string str="I have ) ( ) dream";
	//consle(str)?cout<<"Yes indeed":cout<<"No Wrong";  
	if(consle(str)){
		cout<<"Yes indeed";
	}else{
		cout<<"No Wrong";
	}
	system("pause");
	return 0;
}









