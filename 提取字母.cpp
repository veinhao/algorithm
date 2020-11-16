#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> seperators={',',' ','.','?'};

bool isSeperator(char ch)
{
	bool flag = false;
	int i=0;
	int len=seperators.size();
	for(i=0;i<len;i++){
		if(ch==seperators[i]){
			flag=true;
			return flag;
			}
	}
	return flag;
}

vector<string> parseText(string text)
{
	vector<string> words;
	string word;
	int i,start=-1,end =0,len=text.size();
	for(i=0;i<len;i++){
		if(!isSeperator(text[i]))
		{
			if(start==-1)
				start=i;
		}else{
			end=i;
			if(start!=-1){
			word=text.substr(start,end-start);
			//cout<<word<<endl;
			words.push_back(word);
			end=0;
			start=-1; 
		}
		}
	}
	return words;
	
}

void display(vector<string> word)
{
	vector<string>::iterator it; 
	for(it=word.begin();it!=word.end();it++){
		cout<<*it<<endl;
	}
}

int main()
{
	string test="I have, a dream?";
	vector<string> result=parseText(test);
	display(result);
	return 0;
 } 
