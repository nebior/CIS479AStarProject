#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	int slength = 0, glength = 0;
	string input, goal, mod1, mod2, mod;
	bool valid = false;
	while (valid != true)
	{
		cout << "Input starting string: ";
		cin >> input;
		cout << "Input goal string: ";
		cin >> goal;
		mod = input;
		slength = input.size();
		glength = goal.size();
		if (slength != glength)
		{
			cout << "Strings are not same length. Re-input strings." << endl;
		}
		else
			valid = true;
	}
	char x[1000][1000] , test[1000];
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			x[i][j] = '\0';
		}
	}
	strcpy_s(x[0], input.c_str());
	while (true)
	{
		if (true)
		{
			cout << goal << endl;
			break;
		}
		
	}
	system("pause");
	return 0;
}