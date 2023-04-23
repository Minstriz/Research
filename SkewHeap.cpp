#include <iostream>
using namespace std;

struct Node {
	int info;
	Node*left;
	Node*right;
};
typedef Node* Nodeptr;

void khoiTao(Nodeptr &n) {
	n->info = 0;
	n->left = n->right = NULL;
}
Nodeptr ghepCay(Nodeptr h1, Nodeptr h2) {
	Nodeptr tam = new Node;
	if (h1 == NULL)
		return h2;
	else if (h2 == NULL)
		return h1;
	else
	{
		if (h1->info > h2->info) {
			tam = h1;
			h1 = h2;
			h2 = tam;
		}
		tam = h1->left;
		h1->left = h1->right;
		h1->right = tam;
		h1->left = ghepCay(h2, h1->left);
	}
	return h1;
}
Nodeptr add(Nodeptr root,int giatri) {
	Nodeptr tam = new Node;
	khoiTao(tam);
	tam->info = giatri;
	root = ghepCay(root, tam);
	return root;
}
Nodeptr deleteMax(Nodeptr root) {
	if (root == NULL) {
		cout << "\nCay nghieng bi rong!";
		return NULL;
	}
	Nodeptr tam1;
	Nodeptr tam2;

	tam1 = root->left;
	tam2 = root->right;
	tam1 = ghepCay(tam1, tam2);
	return tam1;
}
void preOrder(Nodeptr root) {
	if (root == NULL)
		return;
	cout << root->info << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void main() {
	const int MAX = 10;
	int day[MAX] = { 24,17,11,53,4,13,38,43,31,22 };
	Nodeptr root = NULL;
	for (int i = 0; i < MAX; i++) {
		root = add(root, day[i]);
	}
	preOrder(root);
}
