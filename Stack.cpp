#include <iostream>
using namespace std;
#define MAXSTACK 100
typedef int TYPE;
struct StackD {
	int sp;
	TYPE elem[MAXSTACK];
};

void init_StackD(StackD& s);
int isEmptyD(StackD s);
int isFullD(StackD s);
void pushD(StackD& s, int x);
int popD(StackD& s);
void input_StackD(StackD& s);
void output_StackD(StackD s);
void top(StackD s);

//*************************DSLK******************************


typedef int TYPEINFO;
struct Node {
	TYPEINFO data;
	Node* link;
};
typedef Node* Nodeptr;
struct Stack {
	Nodeptr top;
};

void init_Stack(Stack& s);
int isEmpty(Stack s);
Nodeptr tao_Node(TYPEINFO x);
void push(Stack& s, TYPEINFO a);
int pop(Stack& s);
void input_Stack(Stack& s);
void output_Stack(Stack s);
int Top(Stack& s);
void popRandom(Stack& s, TYPEINFO x);
///////////////////////////////////////////////////
const int STOP = -1;
void init_StackD(StackD& s) {
	s.sp = -1;
}
int isEmptyD(StackD s) {
	return s.sp == -1;
}
int isFullD(StackD s) {
	return s.sp == MAXSTACK - 1;
}
void pushD(StackD& s, int x) { //them vao  cuoi 
	if (isFullD(s))
		cout << "\nFull!";
	else {
		s.sp++;
		s.elem[s.sp] = x;
	}
}
int popD(StackD& s) {
	int a;
	if (isEmptyD(s))
		return -1;
	else {
		a = s.elem[s.sp];
		/*s.elem[s.sp--];*/
		s.sp--;
	}
	return a;
}
void input_StackD(StackD& s) {
	int x;
	while (1)
	{
		cout << "\nNhap gia tri cho Stack(-1 to out): ";
		cin >> x;
		if (x == STOP) break;
		pushD(s, x);
	}
}

void output_StackD(StackD s) {
	for (int i = 0; i <= s.sp; i++)
		cout << s.elem[i] << " ";
}
void top(StackD s) {
	cout << s.elem[s.sp];
}
//*************************DSLK******************************
void init_Stack(Stack& s) {
	s.top = NULL;
}
int isEmpty(Stack s) {
	return s.top == NULL;
}
Nodeptr tao_Node(TYPEINFO x) {
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}

void push(Stack& s, TYPEINFO a) {
	Nodeptr p;
	p = tao_Node(a);
	if (isEmpty(s))
		s.top = p;
	else {
		p->link = s.top;
		s.top = p;
	}
}

int pop(Stack& s) {
	Nodeptr p;
	TYPEINFO a;
	if (!isEmpty(s)) {
		p = s.top;
		s.top = p->link;
		a = p->data;
		delete p;
		return a;
	}
}
void popRandom(Stack& s, TYPEINFO x) {
	Stack sT;
	Nodeptr p;
	TYPEINFO a;
	init_Stack(sT);
	while (!isEmpty(s)) {
		if (s.top->data == x)
			a = pop(s);
		else {
			sT.top->data = s.top->data;
			p = s.top;
			s.top = p->link;
		}
	}
	s.top->data = sT.top->data;
	cout << "\nPhan tu duoc lay ra: " << a;
	cout << "\nDanh sach tam: "; output_Stack(sT);
	cout << "\nDanh sach con lai :"; output_Stack(s);
}

void input_Stack(Stack& s) {
	int x;
	while (1) {
		cout << "\nNhap gia tri cho Stack (-1 to out): ";
		cin >> x;
		if (x == STOP)
			break;
		push(s, x);
	}
}

void output_Stack(Stack s) {
	Nodeptr p = s.top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}

int Top(Stack& s) {
	return s.top->data;
}

void main() {
	StackD sd;
	//khoi tao stack
	init_StackD(sd);
	//nhap xuat stack 
	input_StackD(sd);
	output_StackD(sd);
	//xem phan tu dau tien cua stack 
	//cout << "\nPhan tu tren dau cua mang: "; top(sd);
	//Lay 1 phan tu ra khoi ds (pop)
	int a = popD(sd);
	if (a == -1) cout << "\nDanh sach rong!";
	else
		cout << "\nPhan duoc lay ra trong ds la: " << a;
	cout << "\nDS sau khi duoc lay ra : "; output_StackD(sd);
	//*************************DSLK*******************************
	//Stack s;
	//init_Stack(s); //khoi tao

	//input_Stack(s); //nhap xuat
	//output_Stack(s);

	////lay phan tu dau ra khoi ds
	//cout << endl;
	//int a = pop(s);
	//cout << "\nPhan tu duoc lay khoi ds la: " << a;
	//cout << "\nDanh sach con lai: "; output_Stack(s);

	////xem phan tu dau cua danh sach
	//cout << "\nPhan tu dau cua danh sach la: " << Top(s);

	//lay phan tu ngau nhien trong ds
	/*int x;
	cout << "\nNhap x can lay ra khoi ds: "; cin >> x;
	popRandom(s, x);*/
}