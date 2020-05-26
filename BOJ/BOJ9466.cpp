/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : �� ������Ʈ
		Problem Number     : 9466
		algorithm          : Graph traversal
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.29 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 100001

int wanted[MAX_SIZE];
bool visited[MAX_SIZE];
// ���̻� ��带 �湮���� �������� Ȯ���ϴ� �迭
bool confirm[MAX_SIZE];
int cnt;

void DFS(int num)
{
	visited[num] = true;

	int next = wanted[num];
	if (visited[next] != true)
	{
		DFS(next);
	}
	// �ѹ� �湮�ߴ� ����ε� �ٽ� �湮�ߴ� -> confirm�迭�� false�̴� -> ����Ŭ�� �����Ѵ�
	else if (confirm[next] != true)
	{
		// �̹� ��忡 ���� ī��Ʈ
		cnt++;
		// ���� ���� ��带 �Ǵٽ� Ž���Ҷ����� ī��Ʈ
		for (int i = next; i != num; i = wanted[i]) 
		{
			cnt++;
		}
	}
	// �̹� ���� ���̻� �湮���� ��������
	confirm[num] = true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		for (int i = 1; i < MAX_SIZE; ++i)
		{
			wanted[i] = cnt = 0;
			visited[i] = confirm[i] = false;
		}

		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) 
		{
			cin >> wanted[i];
		}

		for (int i = 1; i <= N; ++i)
		{
			if (visited[i] != true)
			{
				DFS(i);
			}
		}

		cout << N - cnt << "\n";
	}
}