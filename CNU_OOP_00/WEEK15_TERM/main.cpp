#include "MyFile.h"
#include "Strategy.h"

char setPara(string input, vector<string> &para)
{
	char c;
	c = input[0];
	if (input.length() != 1) {
		para.clear();
		input = input.substr(2, input.length() - 3);	// subtract 3 for c, '(', ')'
		istringstream ss(input);
		string p;
		while (getline(ss, p, ',')) {
			para.push_back(p);
		}
	}
	return c;
}
void outputLine(){
	for (int i = 0; i < 80; i++)
		cout << "-";
	cout << endl;
}

int main()
{
	Context 	context;
	Next 		*next_   = new Next();
	Prev 		*prev_   = new Prev();
	Insert 		*insert_ = new Insert();
	Delete 		*delete_ = new Delete();
	Change 		*change_ = new Change();
	Search 		*search_ = new Search();
	Terminate 	*terminate_ = new Terminate();

	vector<string> 	para;
	string 			input, msg = "(console)";
	int 			index = 0;
	
	readFile();
	vecFormat(vec);

	while (1)
	{
		int emptyLine = 0;
		outputLine();

		for (int i = index; i < index + 20; i++) {
			if (i == vec.size()) {
				emptyLine = index + 20 - i;
				break;
			}
			cout << setw(3) << right << i + 1 << "| ";
			cout << vec[i] << endl;
		}
		if (emptyLine > 0) {
			for (int i = vec.size(); i < vec.size() + emptyLine; i++) {
				cout << setw(3) << right << i + 1 << "| " << '\n';
			}
		}
		outputLine();
		cout << " n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
		outputLine();
		cout << msg << endl;
		outputLine();
		cout << "입력: ";
		cin >> input;

		char cmd = setPara(input, para);
		switch (cmd) {
		case 'n':
			context.setStrategy(next_);
			msg = context.run(vec, para, index);
			break;
		case 'p':
			context.setStrategy(prev_);
			msg = context.run(vec, para, index);
			break;
		case 'i':
			context.setStrategy(insert_);
			msg = context.run(vec, para, index);
			break;
		case 'd':
			context.setStrategy(delete_);
			msg = context.run(vec, para, index);
			break;
		case 'c':
			context.setStrategy(change_);
			msg = context.run(vec, para, index);
			break;
		case 's':
			context.setStrategy(search_);
			msg = context.run(vec, para, index);
			break;
		case 't':
			context.setStrategy(terminate_);
			msg = context.run(vec, para, index);
			break;
		}
		if (exit_) { break; }
		vecFormat(vec);
	}
	return 0;
}