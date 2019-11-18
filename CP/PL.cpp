#include<iostream>
#include<string>
#include<vector>

using namespace std;

class StateTransTable
{
public:
	char pre;
	char next;
	char az;//characters
	StateTransTable(char p, char n, char a)
	{
		pre = p;
		next = n;
		az = a;
	}
};

class DFA
{
public:
	string States;
	char BeginState;
	char EndState;
	string Azs;//character set
	vector<StateTransTable> STT;

	bool init();
	void inputAzs();
	char nextState(char p,char az);
};

bool DFA::init()
{
	cout << "Input states:" << endl;
	cin >> States;
	cout << "Input Azs" << endl;
	cin >> Azs;
	cout << "Input trans(eg. 1a2);end with(#)" << endl;
	while (true)
	{
		char input[4];
		cin >> input;
		if (strcmp(input, "#") == 0)
			break;
		StateTransTable Temp(input[0], input[1], input[2]);
		STT.push_back(Temp);
	}

	cout << "Input beginState:" << endl;
	cin >> BeginState;
	cout << "Input EndState:" << endl;
	cin >> EndState;
	return true;
}

void DFA::inputAzs()
{
	cout << "Input what you want to judge:" << endl;
	string s;
	cin >> s;
	char pre = BeginState;
	int i = 0;
	while (i < s.length())
	{
		pre = nextState(pre, s[i]);
		i++;
	}
	if (pre!= EndState) cout << "Yes!" << endl; //nops??
	else cout << "No!" << endl;
}

char DFA::nextState(char p, char az)
{
	for (int i = 0; i < STT.size(); i++)
	{
		if (STT[i].pre == p && STT[i].az == az)
			return STT[i].next;
	}
	return NULL;
}


int main()
{
	DFA d;
	d.init();
	d.inputAzs();
	
	system("pause");
	return 0;
}
