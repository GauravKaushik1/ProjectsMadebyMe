#include <iostream>
#include <string>
using namespace std;
/*
int many(string a,char b){
	int c=0,l=a.length();
	for(int i=0;i<=l;i++){
		if(a[i]==b)
			c++;
	}
	return c;
}*/
int pos(string a ,char b){
	int l=a.length();
	for(int i=0;i<=l;i++){
		if(a[i]==b){
			return i;
		}
	}
	return -1;
	
}
int sepor(string a,int start,int finish,char b){
	for(int i=start;i<=finish;i++)
	{
		if(a[i]==b){
			return i;
		}
	}
	return -1;
}
int sepol(string a,int start,int finish,char b){
	for(int i=start;i<=finish;i--)
	{
		if(a[i]==b){
			return i;
		}
	}
	return -1;
}
void sec(string a ){
//bool gl=0,tl=0,gr=0,tr=0;
int l=a.length();
int tl,tr,gl,gr;
//int z,y,x,yc,xc;
int pos(string,char);
int sepor(string,int,int,char);
int sepol(string,int,int,char);
	/*int s=pos(a,'$'),t=pos(a,'T'),g=pos(a,'G');
	if(!((s<g&&g<t)||(t<g&&g<s)))
	{cout<<"ALARAM";}*/
	int z=pos(a,'$');
	tr=sepor(a,z,l,'T');
	tl=sepol(a,z,0,'T');
	if(tl!=(-1))
		gl=sepor(a,z,tl,'G');
	if(tr!=(-1))
		gr=sepol(a,z,tr,'G');
	
	if((tl!=(-1)&&gl==(-1))||(tr!=-1&&gr==(-1))){
		cout<<"ALARAM";
	}
	/*
for( yc=z;yc<=l;yc++)//checking theif on right hand side
	{
		if(a[yc]=='T'){
			tr=1;
			break;
		}
	}
	if(tr==1){
		for( xc=yc;xc>=z;xc--){//theif detected on right so find if guard is on the left of theif
			if(a[xc]=='G'){
					gr=1;
					break;
				}
		}
	}
	if(gr==1){
		for(y=z;y>=0;y--){//guard is there to protect $ on the right side from theif detected on the right
			if(a[y]=='T'){
				tl=1;
				break;
			}
		}	
	}
	if(tl==1){
		for(x=y;x<=z;x++)//theif detected on left so find if guard is on the right of theif
		{
			if(a[x]=='G'){
				gl=1;
				break;
			}
		}
	}
	if((tl==1&&gl==0)||(tr==1&&gr==0))
	{
		std::cout<<"ALARAM";
	}*/
}
int main()
{	
	string astring;
	void sec(string);
		std::cin>>astring;
	sec(astring);	
	return 0;
}