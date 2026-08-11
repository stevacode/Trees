// Trees.cpp : Binary tree
//
#include "Trees.h"


TreeNode* root = nullptr;

void Treecreate()
{
	TreeNode* p, * t;
	int x;
	Queue q;
	create(&q, 100);
	cout << "Enter root value: ";
	cin >> x;
	root = new TreeNode;
	root->data = x;
	root->left = root->right = nullptr;
	enqueue(&q, root);
	while (!isEmpty(&q))
	{
		p = dequeue(&q);
		cout << "Enter left child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new TreeNode;
			t->data = x;
			t->left = t->right = nullptr;
			p->left = t;
			enqueue(&q, t);
		}
		cout << "Enter right child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new TreeNode;
			t->data = x;
			t->left = t->right = nullptr;
			p->right = t;
			enqueue(&q, t);
		}
	}
}

void preorder(TreeNode* p)
{
	if (p)
	{
		cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(TreeNode* p)
{
	if (p)
	{
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}
}

void postorder(TreeNode* p)
{
	if (p)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
}


int main()
{
	Treecreate();
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	inorder(root);
	cout << endl;

	return 0;
}
