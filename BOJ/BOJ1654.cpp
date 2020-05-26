/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : ���� �ڸ���
        Problem Number     : 1654
        algorithm          : Binary Search
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2020.01.02 create
        ---------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>
using namespace std;

#define MAX_SIZE 10001

unsigned int ranWire[MAX_SIZE];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;
	cin >> K >> N;

	//  low = 1, high = �Է¹��� K���� ������ ���� �� ���� ����
	unsigned int high = 0, low = 1;
	for (int i = 1; i <= K; ++i)
	{
		cin >> ranWire[i];
		high = ranWire[i] > high ? ranWire[i] : high;
	}

	// �̺� Ž�� ����
	unsigned int result = 0;
	while (high >= low)
	{
		// �߰��� ����
		unsigned int mid = (high + low) / 2;

		unsigned int cnt = 0;
		for (int i = 1; i <= K; ++i)
		{
			cnt += ranWire[i] / mid;
		}

		// �ڸ� ������ ������ N�� ���� ������ ��
		if (cnt >= N)
		{
			result = mid > result ? mid : result;
			// �ڸ� ���� ������ ������ �ڸ� ������ ���̸� �� �÷��� ��
			low = mid + 1;
		}
		else
		{
			// �ڸ� ���� ������ ������ �ڸ� ������ ���̸� �ٿ��� ��
			high = mid - 1;
		}
	}

	cout << result << "\n";
}