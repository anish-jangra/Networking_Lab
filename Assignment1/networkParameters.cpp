#include <bits/stdc++.h>
using namespace std;

int main()
{
	system("ifconfig > test.txt");
	system("nmcli device show wlo1 >> test.txt");

	ifstream f;
	f.open("test.txt");
	string temp = "";
	map <string, string> DATA;
	DATA["IP4.GATEWAY:"] = "";
	DATA["IP4.ADDRESS[1]:"] = "";
	DATA["IP4.DNS[1]:"] = "";
	DATA["netmask"] = "";
	DATA["GENERAL.HWADDR:"] = "";
	while ((f >> temp))
	{
		if (DATA.find(temp) != DATA.end())
		{
			string aux = temp; f >> temp;
			DATA[aux] = temp;
		}
	}
	for (auto x : DATA)
	{
		cout.width(25); cout << left << x.first << x.second << "\n";
	}
	system("rm test.txt");
	return 0;

}
