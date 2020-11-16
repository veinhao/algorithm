#include<iostream>
#include<map>
#include<string>

using namespace std;

bool isUnique(string &str)
{
	map<char,int> myMap;
	for(int i=0;i<str.length();i++){
		myMap[str[i]]++;
	}
	if(myMap[str[i]]!=1){
		 return false;
	}
}

int main()
{
	
}
