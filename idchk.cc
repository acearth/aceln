#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int aw[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
string res="10X98765432";
int isReg(string str)
{
	for(int i=0;i<str.length()-1;++i)
	{
		if(str[i]<'0')
			return -1;
		if(str[i]>'9')
			return -1;
	}
	return 0;
}
char pweight(string str)
{
	int r=0;
	int j;
	for(int i=0;i<17;++i)
	{
		j=str[i]-'0';
		r+=j*aw[i];
	}
	r%=11;
//	cout<<r<<endl;
	return res[r];
}
int main()
{
	ifstream cin("in.txt");
	int n;
	cin>>n;
	vector<string>  vse;
	string st;
	for(int i=0;i<n;++i)
	{
		cin>>st;
		if(isReg(st)==-1)
		{
			vse.push_back(st);
		}
		else
		{
			if(pweight(st)!=st[17])
				vse.push_back(st);
		}
	}
	if(vse.size()==0)
		cout<<"All passed"<<endl;
	else
	{
		cout<<vse.size()<<endl;
		for(int i=0;i<vse.size();++i)	
		{
			cout<<vse[i]<<endl;
		}
	}
	vse.clear();
}
