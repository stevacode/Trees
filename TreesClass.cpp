#include "QueueCpp.h"


class TreesClass {
public:
	Node* root;
	TreesClass() {
		root = nullptr;
	}
	void createTree();
	void preorder(Node* p);
	void inorder(Node* p);
	void postorder(Node* p);
	void levelOrder(Node* p);
	int height(Node* root);
};

void TreesClass::createTree() {
	int x;
	Queue q(100);
	Node* p, * t;
	cout << "Enter root value: ";
	cin >> x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = nullptr;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Enter left child of " << p->data << ": ";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			q.enqueue(t);
		}
		cout << "Enter right child of " << p->data << ": ";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}

void TreesClass::preorder(Node* p) {
	if (p) {
		cout << p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void TreesClass::inorder(Node* p) {
	if (p) {
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}
void TreesClass::postorder(Node* p) {
	if (p) {
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << " ";
	}
}

void TreesClass::levelOrder(Node* p) {
	Queue q(100);
	cout << p->data << " ";
	q.enqueue(p);
	while (!q.isEmpty()) {
		p = q.dequeue();
		if (p->lchild) {
			cout << p->lchild->data << " ";
			q.enqueue(p->lchild);
		}
		if (p->rchild) {
			cout << p->rchild->data << " ";
			q.enqueue(p->rchild);
		}
	}
}

int TreesClass::height(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = height(root->lchild);
	int rightHeight = height(root->rchild);
	return max(leftHeight, rightHeight) + 1;
}


int main() {
	TreesClass tree;
	tree.createTree();
	cout << "Preorder: ";
	tree.preorder(tree.root);
	cout << endl;
	cout << "Inorder: ";
	tree.inorder(tree.root);
	cout << endl;
	cout << "Postorder: ";
	tree.postorder(tree.root);
	cout << endl;
	cout << "Level Order: ";
	tree.levelOrder(tree.root);
	cout << endl;

	cout << "Height of the tree: " << tree.height(tree.root) << endl;
	cout << "Height of the tree (using level order): " << tree.height(tree.root) << endl;
	cout << "Height of the tree (using recursion): " << tree.height(tree.root) << endl;

	
	return 0;
}