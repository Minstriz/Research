#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 20; 
const int MaxN = 1 + 1e5;

int n;
bool mark[MaxN];
vector<int> adj[MaxN];
struct Node {
	int dinhke;
	int trongso;
	Node*link;
};
struct DanhSachKe {
	Node*dsk[MAX];
	int n;
};
struct CanhDoThi {
	int dinhdau;
	int dinhcuoi;
	int trongso;
};
int docDsKe(DanhSachKe &a, const char *text) {
	FILE*fp = fopen(text, "rt");
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
void inDsKe(DanhSachKe &a) {
	cout << endl;
	for (int i = 0; i < a.n; i++) {
		cout << endl;
		Node*p = a.dsk[i];
		cout << i << ":";
		while (p != NULL) {
			cout << "(" << p->dinhke << "," << p->trongso << ")";
			p = p->link;
		}
	}
}
//void BFS(DanhSachKe a, int u) {
//	queue<int> q;
//	q.push(1);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		mark[u] = 1;
//		cout << u << " ";
//		for (int v : adj[u])
//			if (!mark[v]) q.push(v);
//	}
//}
void BFS(DanhSachKe a, int u) {
	DanhSachKe arrV;
	arrV.n = 0;
	queue<int> Q;
	VISIT  visited;
	for (int i = 0; i < a.n; i++) {
		visited[i];
	}
	Q.push(startV);

}
void main() {
	DanhSachKe a;
	if (docDsKe(a, "text.txt") == 1)
	{
		inDsKe(a);
	}
	else cout << "\nCan not read file.";
}