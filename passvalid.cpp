#include <iostream>
#include <string>
using namespace std;
bool lower(char a){
	return (a>='a'&&a<='z')?1:0;
}
bool symbol(char a){
	bool upper(char);
	bool num(char);
	bool lower(char);
	return (!(upper(a))||(lower(a))||(num(a))/*||(a!=' ')*/)?1:0;
//	whether space is treated as special character or symbol
}
bool upper(char a){
	return (a>='A'&&a<='Z')?1:0;
}
bool num(char a){
	return ((a>='1'&&a<='9')||(a=='0'))?1:0;
}
void passval(string a){
	bool l=0,u=0,s=0,n=0;
	for(int i=0;a[i]!='\0';i++){
		if(symbol(a[i]))
			s=1;
		cout<<"s = "<<s<<endl;
		if(upper(a[i]))
			u=1;
		cout<<"u = "<<u<<endl;
		if(num(a[i]))
			n=1;	
		cout<<"n = "<<n<<endl;
		if(lower(a[i]))
			l=1;
		cout<<"l = "<<l<<endl;
	}
	if((u==1)&&(s==1)&&(n==1)&&(l==1))
	{
		cout<<"strong";
	}
	else{
		cout<<"weak";
	}
	cout<<endl;
}
int main()
{
	string a;
	getline(cin,a);
	passval(a);
	return 0;
}