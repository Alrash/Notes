#include <iostream>
#include <set>
#include <string>

using std::set;
using std::cout;
using std::pair;
using std::endl;
using std::string;

int main()
{
	set<int> ss;
	string str;

	for (int i = 0; i < 10; i++)
		ss.insert(i);

	pair<set<int>::iterator, bool> isExist;

	cout << "The contents of this set :";
	for (set<int>::iterator it = ss.begin(); it != ss.end(); it++)
		cout << " " << *it;
	cout << "." << endl;

	isExist = ss.insert(10);
	str = isExist.second ? "true" : "false";
	cout << "Insert 10 and it existed just moment. " << str << endl;
	isExist = ss.insert(10);
	str = isExist.second ? "true" : "false";
	cout << "Insert 10 again and it existed just moment. " << str << endl;

	cout << "Now, the contents of this set :";
	for (set<int>::iterator it = ss.begin(); it != ss.end(); it++)
		cout << " " << *it;
	cout << "." << endl;

	return 0;
}
