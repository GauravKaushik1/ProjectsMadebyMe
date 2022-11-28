#include "ReadWriteFile.h"
#include <iostream>
#include <fstream>
#include <cstring>
/*
//using std::cout ;
//using std::cin;*/
/*
//using std::endl;*/
using std::string;
using std::ios;
/*
using std::ofstream;
using std::ifstream;
using std::fstream;*/

//constructor with default parameters
ReadWriteFile::ReadWriteFile(string f/*="default"*/,bool cui/*=0*/){
	//initialising the class data members
	this->cui=0;
	this->fname=NULL;
	this->filename="";
	
	this->setui1(cui);
	this->AdjustFilename(f);	
}

//function to set the value of cui
void ReadWriteFile::setui1(bool cui){
	this->cui=cui;
}

//function to readfile
void ReadWriteFile::readfile(){
	if(this->cui==1){
		std::cout << "Reading from file : "<< fname << std::endl;
	}
	std::ifstream fi(this->fname,ios::in|ios::binary);
	if(!fi){
    std::cerr << "Error!"
		 << this->fname 
		 << " Does not Exist"<<std::endl;
  	return ;
	}
	if(this->is_empty()){
		return ;
	}
	
	string line="";

  	while (getline(fi, line)) {
       
        // Print line (read from file) in Console
        std::cout << line << std::endl;
    }
  	fi.close();
}

//function to check if file is empty
bool ReadWriteFile::is_empty()
{	std::ifstream pFile(this->fname);
    bool n=(pFile.peek() == std::ifstream::traits_type::eof());
    pFile.close();
    return (n==1)?1:0;
}
//function to write in file
void ReadWriteFile::writetofile(){
	
	if(this->cui==1){
		std::cout << "Writing to file : "<< this->fname << std::endl;
	}
	std::ofstream fi(this->fname,ios::out|ios::app|ios::binary);
	if(fi.is_open()){
		if(this->cui==1){
			if(this->is_empty()){
			std::cerr << "Writing in Empty file"<< std::endl;
			}	
			else{
				std::cerr << "First,Reading data in file"<< std::endl;
				this->readfile();
			}
		}
		
		std::cerr <<"Note: Please Enter 0endOk in next line when you are done Writing to file !" << std::endl;
		std::cout << "Enter text for write in file :" << std::endl;
		
		string line="";
		
		while (fi) {
 
        	// Read a Line from standard input
	        std::getline(std::cin, line);
        
			// Enter 0endOk in next line to exit
	        if (line == "0endOK")
	            break;
 
 	       // Write line in file
    	    fi << line << std::endl;
        	
			if(this->cui==1&&line!="")
 		      	std::cerr << "Wrote this to file : "
				   <<line<<std::endl;
    		}
 
		fi.close();
		
		std::cout << "Reading from file : "<< this->fname
				  << " ..." << std::endl;

		this->readfile();
	}
	else{
		std::cerr << "Error could not open the file"<<std::endl;
	}
}

//function to excecute program one by one automatically
string ReadWriteFile::textfornamechange(int i){
	string statements[]={"Using default file name i.e., ","Recieved file name : "};
	return statements[i-1];
}

//function to contain and print Messages for filename change
void ReadWriteFile::ui(string nf/*="default"*/,bool cui/*=1*/){
	this->setui1(cui);
	
	int c=0;
	
	if((this->abcchecks(this->filename)!=-1)&&this->abcchecks(nf)!=-1){
	//condition to check 
	//if user entered filename or not in contructor and ui
	//if not entered in both then show displayinputrequest() and
	//take input 
		std::cerr << "Filename passed as an argument to neither construct nor ui()"
				  << std::endl;
		this->displayinputrequest();

		std::getline(std::cin,nf);
	}
	
	this->AdjustFilename(nf);
	
	this->displaymenu();
	
	std::cin >> c;
	
	if(c==1){
		this->readfile();
	}
	else if(c==2){
		this->writetofile();
	}
}

//function to check filename nf for default values
int ReadWriteFile::abcchecks(string nf){
	if(nf[0]=='d'){//check for "default" in nf
		if(nf[1]=='e'&&nf[2]=='f'&&nf[3]=='a'){
			if(nf[4]=='u'&&nf[5]=='l'&&nf[6]=='t'){
				return 1;
			}
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
	}
	else if(nf[0]=='W'){//check for "WritingFilecpp.txt" in nf
		if(nf[1]=='r'&&nf[2]=='i'&&nf[3]=='t'){
			if(nf[4]=='i'&&nf[5]=='n'&&nf[6]=='g'&&nf[7]=='F'){
				if(nf[8]=='i'&&nf[9]=='l'&&nf[10]=='e'){
					if(nf[11]=='c'&&nf[12]=='p'&&nf[13]=='p'&&nf[14]=='.'){
						if(nf[15]=='t'&&nf[16]=='x'&&nf[17]=='t'){
							return 2;
						}
						else{
							return -1;
						}
					}
					else{
						return -1;
					}
				}
				else{
					return -1;
				}
			}
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
	}
	
	return -1;
}

//function to display name change or file name received by program
void ReadWriteFile::Displayfilenamestate(int i){
	if(this->cui==0){
		return ;
	}
	std::cout << "Processing ...\n";
	std::cout << std::flush ;
	std::cout << this->textfornamechange(i);
	std::cout << this->fname << std::endl;
}

//function to set then use the name to display relavent messages
void ReadWriteFile::AdjustFilename(string f/*="default"*/){
	
	string fn="WritingFilecpp.txt";
	//default value
	if(this->abcchecks(f)!=-1)
	{
	this->filename=fn;//storing default value in filename string
	this->fname=&this->filename[0];//making filename to char* fname
	this->Displayfilenamestate(1);//display relavent messages
	}
	else
	{
	this->filename=f;//storing the given name in filename string
	this->fname=&this->filename[0];//making filename to char* fname
	this->Displayfilenamestate(2);//display relavent messages
	}
}

//function to display the options of functionality provided	
void ReadWriteFile::displaymenu(){
	if(this->cui==0){
		return ;
	}
	string item[]={"Read from","Write to"};
	int n=2;
	std::cout << "File Operations Menu : " << std::endl;
	for(int i=0;i<n;i++){
		std::cout << i+1<< ". "<< item[i]<<  " file : " 
				  << this->filename << std::endl;
	}
	std::cout << "Input your choice : ";
	std::cout<<std::flush;
}

//function to display the request to input the filename
void ReadWriteFile::displayinputrequest(){
	if(this->cui==0){
		return ;
	}
	std::cout << "Tip:-Input "
		 << "\"default\"(without Quotes) "
		 << "for default file name"<<std::endl
		 << "Enter Filename (max characters 100): ";
	std::cout<< std::flush;
}

//destructor to free up memory from the data members
ReadWriteFile::~ReadWriteFile(){
	this->fname=NULL;
	this->cui=0;
	this->filename="";
	/*
	//To check if destructor is called
	std::cout << "destructor called" << std::endl;
	//*/
}
