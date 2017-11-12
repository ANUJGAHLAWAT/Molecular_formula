#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<cctype>
using namespace std;
string s;
int i;
int hcount(int k,int z)
{ 
	for(int j=k-1;j<k+2;j++)
	{
		cout<<s[j]<<endl;
	    if(s[j]=='=')
	    	z-=2;
 		else if(s[j]=='#')
 			z-=3;
    	else if(s[j]=='(')
    	{
    		z-=1;
       		if(j>k)
       		{
       			if(s[j+1]=='=')
					z=z-2;			
		
       			else if(s[j+1]!='='||s[j+1]!='#')
		        	z=z-1;     
		    }
   		}  	
		else if(isalpha(s[j])||isdigit(s[j]))
		{
			if(isalpha(s[j])&&isdigit(s[j+1]))
			    z-=1;
			else if(isdigit(s[j])&&(s[j+1]==')'))
				    continue; 
			else if(isalpha(s[j+1])&&isdigit(s[j]))
				z-=1;
		    else if(j!=k)
			    z-=1;
			cout<<z<<endl;
		}
		else if(s[j]==')')
		{
			if(j<k)
				z-=1;	
		}
				    			
    }
    cout<<" final z= "<<z<<endl;
    return z;
}
int main()
{
	int l,o=0,c=0,h=0,n=0,x=0;
	ifstream f;
	f.open("smile.txt");
	if(f.good())
	cout<<" file is opened now"<<endl;
	getline(f,s);
	f.close();
	l=s.length();
	cout<<l<<endl;
	cout<<s[-1]<<endl<<endl;
	for(i=0;i<l;i++)
	{
	   switch(s[i])
	   {
	   		case 'O':
	   			h+=hcount(i,2);
	   			o++;
	   			break;
	   		case 'C':
			    c++;
			    h+=hcount(i,4);
			    break;
			case 'c':
				c++;	
	   		    h+=hcount(i,3);
	   		    break;
	   		case 'N':
	   			n++;	
	   		    h+=hcount(i,3);
	   		    break;
	   		case 'n':
	   			n++;	
	   		    h+=hcount(i,2);
	   		    break;
	   		case 'S':
	   		    x++;	
	   		    h+=hcount(i,2);
	   		    break;    
	   			
	   	}	
	}
	cout<<"molecular formula is::  "<<"C"<<c<<"H"<<h<<"N"<<n<<"O"<<o<<"S"<<x<<endl;
	return 0;
}
