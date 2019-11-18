#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Tab {
public:
	Tab(char n, char e, string p) :vn(n), vt(e), prod(p) {};

	char vn;
	char vt;
	string prod;
};

vector<Tab> table;
string str;
char cur;
char a;
vector<char> VT{ 'a','b','c','d' }; 
vector<char> VN{ 'E','A','B' }; 

int isPartVT(char ch)
{
	for (char u : VT) {
		if (u == ch) {
			return 1;
		}
	}
	return 0;
}

int isPartVN(char ch)
{
	for (char u : VN) {
		if (u == ch) {
			return 1;
		}
	}
	return 0;
}

void initTable()
{
	table.push_back(Tab('E', 'a', "aA"));       
	table.push_back(Tab('E', 'b', "bB"));
	table.push_back(Tab('A', 'c', "cA"));
	table.push_back(Tab('A', 'd', "d"));
	table.push_back(Tab('B', 'c', "cB"));
	table.push_back(Tab('B', 'd', "d"));
}

bool parser()
{
	int i = 0;
	stack<char>  s;   

	s.push(str[i++]);
	s.push('E');
	a = str[i++];
	while (!s.empty()) {
		cur = s.top(); 
		s.pop();					
		if (isPartVT(cur)&&cur==a)
		{
			a = str[i++];
		}
		else if (cur == '#'&&cur==a)
		{
			return 1;

		}
		else if (isPartVN(cur) && isPartVT(a)) {
			for (Tab u : table) {
				if (u.vn == cur && u.vt == a) {
					string tempProd = u.prod;
					cout << cur << "->" << tempProd << endl;
					for (int j = tempProd.size() - 1; j >= 0; --j) {
							s.push(tempProd[j]);
					}
				}
			}
		}		
		else
		{
			return 0;
		}
	}
}

int main(int argc, char *argv[])
{
	initTable();
	cout << "Input(#...#):";
	cin >> str;
	cout << "Use:" << endl;
	if (parser()) {
		cout << "Success!" << endl;
	}
	else {
		cout << "Fail!" << endl;
	}
	return 0;
}
