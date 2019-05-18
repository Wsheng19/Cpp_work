#include<iomanip>
#include<cstring>
#include<iostream>
using namespace std;
bool isEE(string s1, string s2)
{
	bool ans = 1;
	int i, j;
	for (i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++)
	{
		if (s1[i] == '%')
		{
			i++;
			while (j < s2.length() && s2[j] != s1[i]) j++;
		}
		else if (s1[i] == '_') continue;
		else if (s1[i] != s2[j])
		{
			ans = 0;
			break;
		}
	}
	if (ans && i == s1.length() && j == s2.length())
		ans = 1;
	else
		ans = 0;
	return ans;
}
int main()
{
	freopen("xx.in", "r", stdin);
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << (isEE(s1, s2) ? "yes" : "no") << endl;
	}
	return 0;
}
