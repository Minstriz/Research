#include<iostream>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
	int height;
};
typedef Node* Nodeptr;
Nodeptr CreateNode(int x) {
	Nodeptr p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}

int Max(int a, int b) {
	return(a > b) ? a : b;
}
int getHeight(Node* root) { //neu ben trai be hon ben phai cong ben trai & nguoc lai.
	if (root == NULL)
		return 0;
	return 1 + Max(getHeight(root->left), getHeight(root->right));
	return root->height;
}

Node* rightRotate(Node* root) {
	Node* x = root->left;
	root->left = x->right;
	x->right = root;
	return x;
}

Node* leftRotate(Node* root) {
	Node* y = root->right;
	root->right = y->left;
	y->left = root;
	return y;
}
//Insertion - AVL Tree
Node* chenNode(Node* root, int value) {
	//1. Insert
	if (root == NULL)
		return new Node{ value, NULL, NULL, 1 }; // Trả về Node có height = 1
	if (value > root->data)
		root->right = chenNode(root->right, value);
	else if (value < root->data)
		root->left = chenNode(root->left, value);
	else
		return root; // Neu bang thi khong them

	//3. Rotate
	int valBalance = getHeight(root->left) - getHeight(root->right);

	//Kiểm tra 4 TH xảy ra:
	// trai trai
	if (valBalance > 1 && value < root->left->data)
		return rightRotate(root);

	//phai phai
	if (valBalance < -1 && value > root->right->data)
		return leftRotate(root);

	//trai phai
	if (valBalance > 1 && value > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//phai trai
	if (valBalance < -1 && value < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}


//In cay
void print(Node* root, int space) {
	if (root == NULL)
		return;
	space += 10;

	print(root->right, space);
	cout << " " << endl;

	for (int i = 10; i < space; i++)
		cout << " ";
	cout << root->data << " (" << root->height << ") " << "\n";

	print(root->left, space);
}
void preorder(Nodeptr r) {
	if (r != NULL) {
		cout << r->data << " ";
		preorder(r->left);
		preorder(r->right);
	}
}
void inorder(Nodeptr r) {
	if (r != NULL) {
		inorder(r->left);
		cout << r->data << " ";
		inorder(r->right);
	}

}
void postorder(Nodeptr r) {
	if (r != NULL) {
		postorder(r->left);
		postorder(r->right);
		cout << r->data << " ";
	}

}


Node* GiaTriNodeLonNhat(Node* root) //ham tim node the mang
{
	Node* current = root;
	while (current->right != NULL)
		current = current->right;
	return current;
}
Nodeptr xoaNode(Nodeptr root, int key) {
	if (root == NULL)
		return root;
	if (key > root->data)
		root->right = xoaNode(root->right, key);
	else if (key < root->data)
		root->left = xoaNode(root->left, key);
	else {
		//TrHop 0 co con hoac co 1 con
		if (root->left == NULL || root->right == NULL) {
			// Dung 1 node tam thoi de check
			Node* temp = root->left;
			if (root->right != NULL)
				temp = root->right;

			// TH 0 con
			if (temp == NULL) {
				temp = root;
				root = NULL;
				delete temp;
			}
			// TH 1 con
			else {
				//gan gia tri cua temp vao root
				root->key = temp -> key;
				delete temp;
			}
		}
		//Neu co ca 2 con
		else {
			// Tim node the mang
			Node* temp = GiaTriNodeLonNhat(root->left);

			// Gan data cua temp vao root goc
			root->data = temp->data;

			// Xóa temp như 2 TH trên - Delete the inorder successor
			root->right = xoaNode(root->right, temp->data);
		}
	}

	if (root == NULL) //triet de
		return root;

	//can bang cay
	int valBalance = heSoCanBang(root);

	//4 truong hop

	// trai trai
	if (valBalance > 1 && heSoCanBang(root->left) >= 0)
		return rightRotate(root);

	//phai phai
	if (valBalance < -1 && heSoCanBang(root->right) <= 0)
		return leftRotate(root);

	//trai phai
	if (valBalance > 1 && heSoCanBang(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//phai trai
	if (valBalance < -1 && heSoCanBang(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

int main() {
	int nodebatky = 0;
	struct Node *root = NULL;
	Node* tree = NULL;
	root = chenNode(root, 24);
	root = chenNode(root, 17);
	root = chenNode(root, 11);
	root = chenNode(root, 27);
	root = chenNode(root, 53);
	root = chenNode(root, 4);
	root = chenNode(root, 8);
	root = chenNode(root, 40);
	root = chenNode(root, 63);
	root = chenNode(root, 71);
	root = chenNode(root, 32);
	root = chenNode(root, 15);
	root = chenNode(root, 20);
	root = chenNode(root, 48);
	root = chenNode(root, 50);
	root = chenNode(root, 46);
	root = chenNode(root, 44);
	print2D(root);
	cout << "NLR:"; preorder(root); cout << endl;
	cout << "LNR:"; inorder(root); cout << endl;
	cout << "LRN:"; postorder(root);
	cout << "\nXoa 8";
	xoaNode(root, 8);
	print2D(root);
	cout << "\n--------------------";
	cout << "\nXoa 36";
	xoaNode(root, 36);
	print2D(root);
	cout << "\nXoa node bat ky: "; 
	cin >> nodebatky;
	xoaNode(root, nodebatky);
	print2D(root);
}
