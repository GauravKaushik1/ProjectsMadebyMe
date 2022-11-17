#include <iostream>
#include <fstream>
#include <math>
#include <cctype>
#include <string>
#include "wtfile.h"
using namespace std;
void wtfile::readfile(this->fname){
	char c;
	ifstream in(this->fname);
	if(!in){
    cout<<"Error! File Does not Exist";
  	return;}
  	while(in.eof()==0){
    in.get(c);
    cout<<c;
  	}
  	return;
}
void wtfile::writetofile(this->fname){
	char fn[15],text[100];
	char fname[]="WritingFilecpp.txt";
	void readfile(char[/*15*/]);
	cout<<"Input File Name:";
	cin>>fn;
	if(fn=="default"){
		strcpy(fname,fn);
		}
	fstream fi;
	fi.open(fname);
	if(fi.is_open()){
		if(is_empty(fi))
			cout<<"Writing in Empty file";
	cout<<"text for write in file "<<fname;
	cin>>text;
	fi<<text;
	}
	fi.close();
	cout<<"Reading from file..."<<endl;
	readfile(fname);
	
}
void program(){
	void writetofile();
 	writetofile();
}
int main () {
 void program();
 program();
 return 0;
}