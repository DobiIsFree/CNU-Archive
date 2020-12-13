#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string 	msg_err = "[error] Invalid inpuut";
string 	msg_suss = "(console) successed!";
string 	msg_fail = "[error] Invalid inpuut";
bool 	exit_ = false;

void divide2word(string line, vector<string> &words)
{
	istringstream ss(line);
	string w;
	while (getline(ss, w, ' ')) {
		words.push_back(w);
	}
}
bool NAN(string str)
{
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return true;
		}
	}
	return false;
}

class Strategy
{
public:
	virtual string execute(vector<string> &vec, vector<string> para, int &index) = 0;
};

class Next : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		string msg;
		int next = index + 20;
		int last = vec.size() - (vec.size() % 20);
		
		if (next >= last) {
			msg = "(console) This is last page!";
			index = last;
		} else {
			msg = "(console) This is next page!";
			index += 20;
		}
		return msg;
	}
};
class Prev : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		string msg;
		int prev = index - 20;

		if (prev <= 0) {
			msg = "(console) This is first page!";
			index = 0;
		}
		else {
			msg = "(console) This is previous page!";
			index -= 20;
		}
		return msg;
	}
};
class Insert : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		// Validation : parameters
		if (para.size() != 3 || NAN(para[0]) || NAN(para[1]) || para[2].length() > 75) {
			return msg_err;
		}
		
		int insert_line = stoi(para[0]) - 1;
		int insert_word = stoi(para[1]) - 1;
		string word = para[2];

		if (insert_line < index || insert_line > index + 20 || insert_line >= vec.size() || insert_line < 0) {
			return msg_err;
		}

		vector<string> words;
		divide2word(vec[insert_line], words);

		if (insert_word >= words.size() || insert_word < 0) {
			return msg_err;
		}

		words.insert(words.begin() + insert_word + 1, word);

		string line = "";
		for (int i = 0; i < words.size(); i++) {
			line += words[i] + " ";
		}

		vec[insert_line] = line;
		return msg_suss;
	}
};

class Delete : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		// Validation : parameters
		if (para.size() != 2 || NAN(para[0]) || NAN(para[1])) {
			return msg_err;
		}

		int delete_line = stoi(para[0]) - 1;
		int delete_word = stoi(para[1]) - 1;

		if (delete_line < index || delete_line > index + 20 || delete_line >= vec.size() || delete_line < 0) {
			return msg_err;
		}

		vector<string> words;
		divide2word(vec[delete_line], words);

		if (delete_word >= words.size() || delete_word < 0) {
			return msg_err;
		}

		words.erase(words.begin() + delete_word);

		string line = "";
		for (int i = 0; i < words.size(); i++) {
			line += words[i] + " ";
		}
		vec[delete_line] = line;

		return msg_suss;
	}
};

class Change : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		// Validation : parameters
		if (para.size() != 2) {
			return msg_err;
		}
		
		string oldstr = para[0];
		string newstr = para[1];
		if (oldstr == "" || newstr == "") {
			return msg_err;
		}

		vector<string> words, temp;
		for (int i = 0; i < vec.size(); i++) {
			divide2word(vec[i], words);
		}
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == oldstr) {
				words[i] = newstr;
			}
		}

		string str = "";
		for (int i = 0; i < words.size(); i++) {
			if (str.length() + words[i].length() + 1 > 75) {
				temp.push_back(str);
				str = "";
			}
			str += words[i] + " ";
		}
		if (str != "") {
			temp.push_back(str);
		}
		vec.clear();
		vec.assign(temp.begin(), temp.end());

		return msg_suss;
	}
};
class Search : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		// Validation : parameters
		if (para.size() != 1) { return msg_err; }

		string word = para[0];
		bool isFound = false;
		
		if (word == "") {
			return msg_err;
		}
		for (int i = 0; i < vec.size(); i++) {
			vector<string> words;
			divide2word(vec[i], words);
			for (int j = 0; j < words.size(); j++) {
				if (words[j] == word) {
					isFound = true;
					index = i;
					break;
				}
			}
			if (isFound) { break; }
		}

		if (isFound) {
			return msg_suss;
		} else {
			return msg_fail;
		}
	}
};
class Terminate : public Strategy
{
public:
	string execute(vector<string> &vec, vector<string> para, int &index)
	{
		ofstream out("test.txt");
		if (! out.is_open()) {
			return msg_fail;
		} else {
			string str = "";
			for (int i = 0; i < vec.size(); i++) {
				str += vec[i] + ' ';
			}
			out << str;
			out.close();
			exit_ = true;
			return msg_suss;
		}
	}
};
class Context
{
private:
	Strategy *strategy;

public:
	void setStrategy(Strategy *s) { this->strategy = s; }
	string run(vector<string> &lines, vector<string> para, int &index)
	{
		return this->strategy->execute(lines, para, index);
	}
};