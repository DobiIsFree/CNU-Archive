#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


char selectCommand(string input, vector<string> &para)
{
	char command;
	command = input[0];
	if (input.length() != 1) {
		para.clear();
		input = input.substr(2, input.length() - 3);
		istringstream ss(input);
		string p;
		while (getline(ss, p, ',')) {
			para.push_back(p);
		}
	}
     cout<<"Debug : "<<command<<endl;
     for(int i=0; i<para.size(); i++){
          cout<<"Debug: "<< para[i]<<endl;
     }
	return command;
}
int main(){
   string s = ")";
   cout<<s.length();

}