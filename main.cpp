#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

string binaryToHex (string text){
	int result =0 ;
    for(size_t count 	= 0; count < text.length() ; ++count){
        result *=2;
        result += text[count]=='1'? 1 :0;
    }  

    stringstream ss;
    ss << "0x" << hex << setw(8) << setfill('0')  << result;

    string hexVal(ss.str());
    cout<<hexVal<<endl;
    return hexVal;
}

int main(){
	string bin("00000001000000111111001100001000");
	binaryToHex(bin);

 	FILE * pFile;
  	long lSize;
  	char * buffer;
  	size_t result;

  	pFile = fopen ( "example.txt" , "rb" );
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  	// obtain file size:
  	fseek (pFile , 0 , SEEK_END);
  	lSize = ftell (pFile);
  	rewind (pFile);

	// allocate memory to contain the whole file:
  	buffer = (char*) malloc (sizeof(char)*lSize);
 	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  	// copy the file into the buffer:
  	result = fread (buffer,1,lSize,pFile);
  	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  	/* the whole file is now loaded in the memory buffer. */
  	string tmp(buffer);
  	binaryToHex(tmp);

	
  	// terminate
  	fclose (pFile);
  	free (buffer);
  	return 0;
}