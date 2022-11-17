/*SecretMessage Program as MAde by Gaurav Kaushik*/
#include <iostream>
#include <string>
using namespace std;
string EnDecodeStr(string a){
	char lowerEncodeDecode(int);
	int n=a.size();
	for(int i=0;a[i]!='\0'&&i<n;i++){
		if(a[i]!=' ')
			a[i]=lowerEncodeDecode(a[i]);
	}
	return a;
}
/*
char EncodeDecode(int a){
	if(a>=97&&a<=122||a>=65&&a<=90)	{
		int x=(/*a>=65&&*//*
a<=90)?64:96;*/
/*	if(x==96)
		cout<<"value is in lower case";
	else if(x==64) 
		cout<<"value is in CAPTIAL";
		*/
/*		return char(x+27-(a-x));}
	else{
	//	cout<<"Sorry currently only alphabets are allowed to be encoded"; 
		return a;
	}
}*/char lowerEncodeDecode(int a){
	if(a>=97&&a<=122||a>=65&&a<=90)	{
		int x=(/*a>=65&&*/a<=90)?64:96;
		return char(96+27-(a-x));}
	else{
		return a;
	}
}
int main()
{		string c;
		string EnDecodeStr(string);
		getline(cin,c);
		//use either c.size() or stringname.length() to get length of string
		c=EnDecodeStr(c);
		//outstring(c);
		cout<<c;
	return 0;
}