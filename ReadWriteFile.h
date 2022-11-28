#include <iostream>
#include <string>

using std::string;

#ifndef ReadWriteFile_H
#define ReadWriteFile_H

class ReadWriteFile{
	
	private:	
	//variable declaration
	string filename;
	//to contain file name as set by AdjustFilename()
	char* fname;
	//to be used for file read and write operations
	bool cui;
	//to contain the choice of whether user wants ui as set by the setui1()
	
	public:
	
	//constructor with default parameters
	ReadWriteFile(string f="default",bool cui=0);
	//function to set the value of cui
	void setui1(bool cui);
	//function to readfile
	void readfile();
	//function to check if file is empty
	bool is_empty();
	//function to write in file
	void writetofile();
	//function to excecute program one by one automatically
	void ui(string nf="default",bool cui=1);
	//function to contain and print Messages for filename change 
	string textfornamechange(int i);
	//function to check filename nf for default values 
	int abcchecks(string nf);
	//function to display name change or file name received by program
	void Displayfilenamestate(int i);
	//function to set then use the name to display relavent messages
	void AdjustFilename(string f="default");
	//function to display the options of functionality provided	
	void displaymenu();
	//function to display the request to input the filename
	void displayinputrequest();
	//destructor to free up memory from the data members
	~ReadWriteFile();
	
};

#endif //ReadWriteFile_H
