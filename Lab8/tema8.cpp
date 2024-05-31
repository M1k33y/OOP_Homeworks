#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;
ifstream fin("file.in");

struct cmp
{
	int nr;
	string cuv;
	bool operator < (const cmp& x) const
	{
		if (nr < x.nr)
			return true;
		if (nr == x.nr)
			return cuv > x.cuv;
		return false;
	}
};

void transformare(string& s)
{
	for (int i = 0; i <= s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
}
int main()
{
	string s;
	map <string, int> Map;
	getline(fin,s);

	transformare(s);
	map <string, int> wordCount;

	auto sep = s.find_first_of(" ,?!.");
	while (sep < s.size())
	{
		if (sep > 0)
			Map[s.substr(0, sep)]++;

		s = s.substr(sep + 1);
		sep = s.find_first_of(" ,?!.");
	}
	
	priority_queue <cmp> q;
	
	for (auto i:Map)
		q.push({i.second,i.first});
	
	while (!q.empty())
	{
		cout << q.top().cuv << " => ";
		cout << q.top().nr << endl;
		q.pop();
	}
	return 0;

}

