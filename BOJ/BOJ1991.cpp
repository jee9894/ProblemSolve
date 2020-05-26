/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 트리 순회
        Problem Number     : 1991
        algorithm          : Graph traversal
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2020.01.01 create
        ----------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>

using namespace std;

class Node
{
public:
	Node() : value(0), leftChild(NULL), rightChild(NULL)
	{
	}

	void SetRoot(char root)
	{
		this->value = root;
	}

	void SetLeft(Node *left)
	{
		this->leftChild = left;
	}

	void SetRight(Node *right)
	{
		this->rightChild = right;
	}

	void Preorder()
	{
		cout << this->value;
		Node *temp = this->leftChild;
		if (temp != NULL) temp->Preorder();
		temp = this->rightChild;
		if (temp != NULL) temp->Preorder();
	}

	void Inorder()
	{
		Node *temp = this->leftChild;
		if (temp != NULL) temp->Inorder();
		cout << this->value;
		temp = this->rightChild;
		if (temp != NULL) temp->Inorder();
	}

	void Postorder()
	{
		Node *temp = this->leftChild;
		if (temp != NULL) temp->Postorder();
		temp = this->rightChild;
		if (temp != NULL) temp->Postorder();
		cout << this->value;
	}

private:
	char value;
	Node *leftChild;
	Node *rightChild;
};


int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Node *Tree = new Node[N];
	for (int i = 0; i < N; ++i)
	{
		char root, left, right;
		cin >> root >> left >> right;
		Tree[root - 'A'].SetRoot(root);
		if(left != '.')
			Tree[root - 'A'].SetLeft(&Tree[left-'A']);
		if(right != '.')
			Tree[root - 'A'].SetRight(&Tree[right-'A']);
	}
	
	Tree[0].Preorder();
	cout << "\n";
	Tree[0].Inorder();
	cout << "\n";
	Tree[0].Postorder();

	delete[] Tree;
}