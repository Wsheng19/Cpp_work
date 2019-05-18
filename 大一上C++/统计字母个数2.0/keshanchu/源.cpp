#include<iostream>
using namespace std;

int main()
{
	char arr[1000];
	int n, tongji[26] = { 0 };
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cin.getline(arr, 1000);
		for (int j = 0; j < 1000; j++)
		{
			if (arr[j] >= 'a'&&arr[j] <= 'z') tongji[arr[j] - 'a']++;
			else if (arr[j] >= 'A'&&arr[j] <= 'Z') tongji[arr[j] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++)
		if (tongji[i] && i != 25)
		{
			cout << char(i + 'a') << " 的个数是: " << tongji[i] << endl;
			n = 0;
		}
	if (n) cout << "字符串中无字母" << endl;
	system("pause");
}