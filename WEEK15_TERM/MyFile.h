#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> 	vec;
ifstream 		fin("test.txt");

void readFile()
{
	if (fin.is_open()) {
		string line;
		while( !fin.eof() ) {
			getline(fin, line);
			vec.push_back(line);
		}
	}
	else {
		cout << "[error] Check your file." << endl;
	}
	fin.close();
}
void vecFormat(vector<string> &v)
{
	vector<string> temp;
	string str = "";
	for (int i = 0; i < v.size(); i++) {
		str += v[i];
	}
	istringstream ss(str);
	string word, line = "";
	while (getline(ss, word, ' ')) {
		if (line.length() + word.length() + 1 > 75) {
			temp.push_back(line);
			line = "";
		}
		line += word + " ";
	}
	if (line != "") {
		temp.push_back(line);
	}
	v.clear();
	v.assign(temp.begin(), temp.end());
}