#include "ReadWriteFile.h"
#include <iostream>
#include <fstream>

using namespace std;

int main () {
	//using the cui provided by Gaurav Kaushik
	ReadWriteFile on;
 	on.ui();//*/
 	/*//for testing purposes
ReadWriteFile in;
 	in.ui("Hi.txt");//entered filename in ui()*/
 	
 	//Mannually doing it yourself
	ReadWriteFile onto("Demo.txt");//entered filename in constructor
 	onto.readfile();
 	onto.writetofile();
 	onto.readfile();
 	/*
	ReadWriteFile into("Hi.txt");
 	into.ui("Myfile.txt");
	//entered filename in ui will reset the old one maybe*/
 return 0;
}
