/*SecretMessage Program as MAde by Gaurav Kaushik*/
#include <iostream>
#include <string>
using namespace std;
//syntax of funtion pointer as parameter to another function
//ReturnDataType functionname(ReturnDataTypeOfFunctionPointer (*Function PointerName)(ParametersOfFunctionPointer)){Funtion Body}
template <class t,class z> string stringoperations(string a,t (*Operation)(z)){
//templates as datatypes for functions 
	int n=a.size();
	for(int i=0;a[i]!='\0'&&i<n;i++){
		if(a[i]!=' ')
			a[i]=Operation(a[i]);
	}
	return a;
}
void numberint(char a){
	if(a=='0')
		cout<<"123";
	else
		cout<<"543";
}
char EncodeDecode(int a){
	if(a>=97&&a<=122||a>=65&&a<=90)	{
		int x=(a>=65&&a<=90)?64:96;
/*	if(x==96)
		cout<<"value is in lower case";
	else if(x==64) 
		cout<<"value is in CAPTIAL";
		*/
		return char(x+27-(a-x));}
	else{
	//	cout<<"Sorry encoding and decoding of this charcter is work-in-progress"; 
		return a;
	}
}
int main()
{	string c,e;
	getline(cin,c);
	c=stringoperations<char,int>(c,EncodeDecode);
	//Function Pointer Calling syntax
	//FuntionName(FuntionToBePassedAsParameter);
	cout<<c;
	//e=stringoperations<void(t),char>(c,numberint);
	stringoperations<void(t),char>(c,numberint);
	//use tag <datatypes to be used separated by template classes>
//	cout<<e;
	return 0;
}