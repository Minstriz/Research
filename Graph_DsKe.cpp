#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX = 20;
struct Node {
	int dinhke;
	int trongso;
	Node* link;
};
typedef Node* Nodeptr;
struct DanhSachKe {
	Node* dsk[MAX];
	int n;
};
struct CanhDoThi {
	int dinhdau;
	int dinhcuoi;
	int trongso;
};

int docDsKe(DanhSachKe& a, const char* text) {
	FILE* fp = fopen(text, "rt");
	if (fp == NULL)
		return 0;
	fscanf(fp, "%d", &a.n);
	for (int i = 0; i < a.n; i++) {
		a.dsk[i] = NULL;
	}
	for (int i = 0; i < a.n; i++) {
		int m;
		fscanf(fp, "%d", &m);
		for (int j = 0; j < m; j++) {
			Node* p = new Node;
			if (1)
				fscanf(fp, "%d%d", &p->dinhke, &p->trongso);
			else
				fscanf(fp, "%d", &p->dinhke);
			p->link = a.dsk[i];
			a.dsk[i] = p;
		}
	}
	fclose(fp);
	return 1;
}
void inDsKe(DanhSachKe& a) {
	cout << endl;
	for (int i = 0; i < a.n; i++) {
		cout << endl;
		Node* p = a.dsk[i];
		cout << i << ":";
		while (p != NULL) {
			cout << "(" << p->dinhke << "," << p->trongso << ")";
			p = p->link;
		}
	}
}
int soDinhDoThi(DanhSachKe a) {
	return a.n;
}
int soCanhDoThi(DanhSachKe a) {
	int dem = 0;
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != 0) {
			if (p->trongso != 0) dem++;
			p = p->link;
		}
	}
	return dem;
}
int demSoBacVao(DanhSachKe a, int b) { //a la dinh bat ky
	int dem = 0;
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != 0) {
			if (p->dinhke == b) dem++;
			p = p->link;
		}
	}
	return dem;
}
int demSoBacRa(DanhSachKe a, int b) { //a la dinh bat ky
	int dem = 0;
	Node* p = a.dsk[b];
	while (p != NULL) {
		if (p->dinhke != 0) {
			dem++;
			p = p->link;
		}
	}
	return dem;
}
int kiemTraBoUV(DanhSachKe a, int u, int v) { //u va v la 2 dinh bat ky
	int dem = 0;
	cout << "\nNhap u: "; cin >> u;
	cout << "\nNhap v:"; cin >> v;
	Node* p = a.dsk[u];
	while (p != NULL) {
		if (p->dinhke == v)
			return 1;
		p = p->link;
	}
	return 0;
}
int trongSoMin(DanhSachKe a) {
	int min = 1;
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != NULL) {
			min = p->trongso;
			break;
		}
	}
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != NULL) {
			if (p->trongso < min) {
				min = p->trongso;
			}
			p = p->link;
		}
	}
	return min;
}
int trongSoMax(DanhSachKe a) {
	int max = 1;
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != NULL) {
			max = p->trongso;
			break;
		}
	}
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != NULL) {
			if (p->trongso > max) {
				max = p->trongso;
			}
			p = p->link;
		}
	}
	return max;
}
CanhDoThi CoupleVertexMax(DanhSachKe a) {
	CanhDoThi b;
	for (int i = 0; i < a.n; i++) {
		Node* p = a.dsk[i];
		while (p != NULL) {
			if (trongSoMax(a)== p->trongso)
			{
				b.trongso = p->trongso;
				b.dinhdau = i;
				b.dinhcuoi = p->dinhke;
			}
				p = p->link;
		}
	}
	return b;
}
void main() {
	DanhSachKe a;
	if (docDsKe(a, "text.txt") == 1)
	{
		inDsKe(a);
	}
	else cout << "\nCan not read file.";
	cout << "\nSo dinh do thi: " << soDinhDoThi(a);
	cout << "\nSo canh do thi: " << soCanhDoThi(a);

	//int c;
	//cout << "\nNhap c: "; cin >> c;
	//cout << "\nTinh bac vao cua c: " << demSoBacVao(a, c);
	//cout << "\nNhap c : "; cin >> c;
	//cout << "\nBac ra cua c :" << demSoBacRa(a, c);

	////Kiem tra (u,v)
	//int u = 0; int v = 0;
	//if (kiemTraBoUV(a, u, v) == 1) cout << "\nDay la 1 canh trong do thi!";
	//else cout << "\nDay khong phai 1 canh trong do thi!";
	//trong so min
	cout << "\nTrong so nho nhat:" << trongSoMin(a);
	//trong so max
	cout << "\nTrong so lon nhat:" << trongSoMax(a);
	//Tra ve cap dinh co trong so lon nhat
	CanhDoThi b;
	b = CoupleVertexMax(a);
	cout << "\nCap dinh co trong so lon nhat: [" << b.dinhdau << "][" << b.dinhcuoi << "]" << "Trong so: " << b.trongso;
}