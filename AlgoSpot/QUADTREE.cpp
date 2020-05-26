#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator &iter)
{
	char head = *(iter++);

	if (head == 'b' || head == 'w')
		return string(1, head);
	
	string upperLeft = reverse(iter);
	string upperRight = reverse(iter);
	string lowerLeft = reverse(iter);
	string lowerRight = reverse(iter);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);

	int testCase;
	cin >> testCase;

	//string quadTree;
	for (int i = 0; i < testCase; ++i)
	{
		string quadTree;
		cin >> quadTree;

		string::iterator iter = quadTree.begin();
		cout << reverse(iter) << endl;
	}

	return 0;
}