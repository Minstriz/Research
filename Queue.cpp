#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
const int MAX = 50;
typedef int type;
typedef struct Node* Nodeptr;
//khai bao cac hang so
const int STOP = -1;
//danh sach dac
struct Queue {
	//front : phan tu dau tien
	//rear: phan tu cuoi cung
	int front, rear;
	int elem[MAX];
};
void khoiTao(Queue& q);
int isEmpty(Queue q);
int isFull(Queue q);
int enQueue(Queue& q, type x);
void print(Queue q);
void setValue(Queue& q);
int deQueue(Queue& q);
void printFirstElem(Queue q);


void khoiTao(Queue& q) {
	q.front = -1;
	q.rear = -1;
}
//Ham kiem tra Queue co rong hay khong
int isEmpty(Queue q) {
	if (q.front == -1)
		return 1;
	return 0;
}
//Ham kiem tra Queue co day hay khong
int isFull(Queue q) {
	return (q.rear - q.front == MAX - 1);
}

//Ham them mot phan tu vao hang doi. Hay sua(vuet) lai ham nay cho chinh xac
int enQueue(Queue& q, type x) {
	if (isFull(q))
		return 0; //hang day
	else {
		if (q.front == -1)
			q.front = 0;
		q.rear++;
		q.elem[q.rear] = x;
		return q.rear;
	}
}
//In ham doi
void print(Queue q) {
	if (isEmpty(q) != -1) {
		for (int i = q.front; i <= q.rear; i++) {
			cout << q.elem[i] << " ";
		}
	}
	else cout << "\nRong !!!";
}
void setValue(Queue& q) {
	int x;
	while (1) {
		cout << "\nNhap vao Queue(Nhap -1 de thoat!): ";
		cin >> x;
		if (x == STOP) break;
		enQueue(q, x);
	}
}
//Ham lay mot phan tu ra khoi ham doi theo quy tac (First in First out)
//Ham tra ve phan tu duoc lay
int deQueue(Queue& q) {
	if (isEmpty(q) != -1) {
		if (q.front == q.rear) {
			khoiTao(q);
		}
		else {
			int t = q.elem[q.front];
			q.front++;
			return t;
		}
	}
	else
		return 0;
}

//Cau 3: Sinh vien tu viet doan ma dung de xem gia tri cua phan tu o dau hang doi
//sau do chay chuong trinh
void printFirstElem(Queue q) {
	if (!isEmpty(q)) {
		cout <<"\nPhan tu dau tien cua danh sach la: " << q.elem[q.front];
	}
}

//danh sach lien ket
struct QueueDSLK {
	Nodeptr front, rear;
};
struct Node {
	int data;
	Node* link;
};
void khoiTaoDSLK(QueueDSLK& q);
int isEmptyDSLK(QueueDSLK q);
Nodeptr tao_NodeDSLK(type x);
void enQueueDSLK(QueueDSLK& q, type x);
void setValueDSLK(QueueDSLK& q);
void printDSLK(QueueDSLK q);
type deQueueDSLK(QueueDSLK& q);
type getFrontDSLK(QueueDSLK q);

//DANH SACH LIEN KET
void khoiTaoDSLK(QueueDSLK& q)
{
	q.front = NULL;
	q.rear = NULL;
}

int isEmptyDSLK(QueueDSLK q)
{
	if (q.front == NULL)
		return 1;
	return 0;
}

Nodeptr tao_NodeDSLK(type x)
{
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}

void enQueueDSLK(QueueDSLK& q, type x)
{
	Nodeptr p;
	p = tao_NodeDSLK(x);
	if (isEmptyDSLK(q)) {
		q.front = p;
		q.rear = p;
	}
	else {
		q.rear->link = p;
		q.rear = p;
	}
}
void setValueDSLK(QueueDSLK& q) {
	int x;
	while (1) {
		cout << "\nNhap gia tri cho Queue(-1 to exit): ";
		cin >> x;
		if (x == STOP) break;
		enQueueDSLK(q, x);
	}
}
void printDSLK(QueueDSLK q) {
	Nodeptr p;
	p = q.front;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
type deQueueDSLK(QueueDSLK& q) {
	if (isEmptyDSLK(q))
		return -1;
	else {
		Nodeptr p = q.front;
		q.front = p->link;
		type t = p->data;
		delete p;
		return t;
	}
}

type getFrontDSLK(QueueDSLK q) {
	cout << "\nPhan tu dau cua DSLK:";
	return q.front->data;
}

void main() {

	//DANH SACH DAC:
	Queue p; int x;
	khoiTao(p);
	//Nhap
	setValue(p);
	//them phan tu
	//cout << "\nnhap ptu mun them:"; cin >> x;
	//enQueue(p, x);
	//print(p);
	//lay 1 phan tu ra khoi hang doi
	//cout << deQueue(p);
	//cout << endl;
	//cout << "\nSau khi thuc hien dequeue: ";
	//print(p);
	//Phan tu dau danh sach 
	printFirstElem(p);


	//***********************//
	//**DANH SACH LIEN KET**//
	//*********************//

	//QueueDSLK q;
	//khoiTaoDSLK(q);
	////Ham nhap xuat
	//setValueDSLK(q);
	//printDSLK(q);
	////lay mot phan tu ra khoi hang doi
	//cout << "\nSau khi lay 1 phan tu ra khoi hang doi:";
	//deQueueDSLK(q);
	//printDSLK(q);
	////Cau 3: 
	//getFrontDSLK(q);
	system("pause");
}