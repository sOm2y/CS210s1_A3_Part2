/*
--This programme is made by sOm2y
--PLEASE DO NOT COPY THE CODE!
*/

#include <iostream>     /*cout*/
#include <stdio.h>      /*printf, fgets*/
#include <stdlib.h>     /*atoi*/
#include <string>	/*stoi*/
#include <cstdlib>
#include <sstream>	/*stringstream*/

using namespace std;

void toDecimal(string s){
	string text1;
	string text2;
	string text1and2;
	int result=0;
	int temp;
	stringstream strToHex;

	for(int i=0;i<s.size();i+=2){

			text1=s[i];
			text2=s[i+1];
			text1and2=text1+text2;				
			strToHex << text1and2;
			strToHex >> hex >> temp;

			if((temp&0x80)==0x80){	
				if(i+2==s.size()){
					result=0;
					break;				
				}
				result=result+(temp-128)*128;		
					
			}else{
								
				result= result+temp;
				break;								
			}	
		strToHex.str(string());
		strToHex.clear();
		
	}
	cout<<result;	
}

int main(int argc, char** argv){
        int i;
        for(i=1;i<argc;i++){
		string input=(argv[i]);
		cout<<input<<": ";
		toDecimal(input);
                cout<<endl;
        }
}
