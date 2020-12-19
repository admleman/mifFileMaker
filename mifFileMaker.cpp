#include <iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;
int main(){
	
	int bitWidth, dataDepth;
	int counter=0;
	string file_name,xData;
	vector<string> theData;
	ofstream memInitFile;

	cout<<"Enter file name(w/o the extension): ";
	cin>> file_name;
	cout<<"\nEnter the bit-width of each word: ";
	cin>>bitWidth;
	cout<<"\nEnter the depth of the data: ";
	cin>>dataDepth;
  memInitFile.open(file_name+".mif");
	
	for(auto i = 0; i<dataDepth; i++){
		cout<<i<<"th memory location, or type 0x to end, USE BINARY!: ";
		cin>>xData;
    if(xData == "0x"){
      break;
    }
    else{
		  theData.push_back(xData);
    }

  }
	
	memInitFile<<"WIDTH = "<<bitWidth<<";\n";
	memInitFile<<"DEPTH = "<<dataDepth<<";\n\n";
	memInitFile<<"ADDRESS_RADIX = DEC;\nDATA_RADIX = BIN;\nCONTENT BEGIN\n";
	
	
	for(auto i = theData.begin();i!=theData.end();i++){
		memInitFile<<counter<<":"<< *i <<";\n";
		cout<<counter<<":"<< *i <<";\n";
    counter++;
	}
memInitFile<<"END;";
memInitFile.close();
cout<<"done!\n";
return 0;
}
