#include <iostream>
#include <string>
using namespace std;

string reverse(string a){
	string b;
	int l=a.length()-1;
	for(int i=l;i>=0;i--){
		b.pushback(a[i]);
	}
	return b;
}
string remsymbol(string a){
	string b;
	int l=a.length();
	bool isy(char a);
	for(int i=0;i<=l;i++){
		if(!isy(a[i])){
				b.pushback(a[i]);
		}
	}
	return b;
}
bool isy(char a){
return ((a>=65&&a<=90)||(a==' ')||(a>=97&&a<=122))?0:1;
}
int main()
{
	string a;
	
string reverse(string a);
	string remsymbol(string a);
	cin>>a;
	a=reverse(a);
	cout<<remsymbol(a);
	return 0;
}