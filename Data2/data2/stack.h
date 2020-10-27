#pragma once
#include "iostream"
#include "string"
#include "assert.h"
using namespace std;

const int stackIncreament = 20;
class Stack {
public:
	Stack() {};
	virtual void Push(const int& x) = 0;
	virtual int Pop() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
};

class  SeqStack :public Stack {
public:
	SeqStack(int sz = 50);
	void Push(const int& x);
	int Pop();
	bool IsEmpty();
	bool IsFull();
private:
	int* elements;
	int top;
	int maxSize;
	void overflowProcess();
};

SeqStack::SeqStack(int sz) :top(-1), maxSize(sz) {
	elements = new int[maxSize];
	assert(elements != NULL);
}

void SeqStack::overflowProcess() {
	int* newArray = new int[maxSize + stackIncreament];
	if (newArray == NULL) { cerr << "存储分配失败" << endl; exit(1); }
	for (int i = 0; i <= top; i++)newArray[i] = elements[i];
	maxSize = maxSize + stackIncreament;
	delete[] elements;
	elements = newArray;
}

void SeqStack::Push(const int& x) {
	if (IsFull() == true) overflowProcess();
	elements[++top] = x;
}

int SeqStack::Pop() {
	if (IsEmpty() == true) { cerr << "栈满" << endl; exit(2); }
	return elements[top--];
}

bool SeqStack::IsEmpty() {
	return (top == -1) ? true : false;
}

bool SeqStack::IsFull() {
	return (top == maxSize - 1) ? true : false;
}

//十进制转化为二进制
void binary(int x) {
	SeqStack A;
	while (x) {
		A.Push(x % 2);
		x /= 2;
	}
	while (!A.IsEmpty()) {
		cout << A.Pop();
	}
};

//十进制转化为八进制
void octonary(int x) {
	SeqStack A;
	while (x) {
		A.Push(x % 8);
		x /= 8;
	}
	while (!A.IsEmpty()) {
		cout << A.Pop();
	}
};

//十进制转化为十六进制
void hexadecimal(int x) {
	SeqStack A;
	char hex[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int i = 0, m,a=0; int num[100];
	while (x>0) {
		num[i++] = x % 16;
		x = x / 16;
	}
	for (int j=0 ; j <= i-1; j++) {
		m = num[j];
		A.Push(hex[m]);
	}
	while (!A.IsEmpty()) {
		cout << char(A.Pop());
	}

};




template<class T>
struct  LinkNode {
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }
	LinkNode(const T& item, LinkNode<T>* ptr = NULL) {
		data = item; link = ptr;
	}
};

template<class T>
class LinkedQueue
{
public:
	LinkedQueue() :rear(NULL), front(NULL) {}
	~LinkedQueue() {
		makeEmpty();
	}
	bool EnQueue(const T& x);
	T DeQueue(T& x);
	//bool DeQueueR();
	void makeEmpty();
	//T getFront();
	//T getRear();
	bool IsEmpty()const { return (front == NULL) ? true : false; }
	//int getSize()const;
protected:
	LinkNode<T>* front, * rear;
};

template<class T>
bool LinkedQueue<T>::EnQueue(const T& x) {
	if (front == NULL) {
		front = rear = new LinkNode<T>(x);
		if (front == NULL)return false;
	}
	else
	{
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL)return false;
		rear = rear->link;
	}
	return true;
}
template <class T>
T LinkedQueue<T>::DeQueue(T& x)
{
	if (IsEmpty() == true) return false;
	LinkNode<T>* p = front;
	x = front->data;
	front = front->link;
	delete p;
	return true;
}

template <class T>
void LinkedQueue<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (front != NULL)
	{
		p = front;
		front = front->link;
		delete p;
	}
}


void judge() {
	string sa;
	cin >> sa;
	int num = sa.length();
	LinkedQueue<char> cha;
	for (int i = 0; i < num; i++)
	{
		char a = sa[i];

		cha.EnQueue(a);
	}
	for (int i = 0; i < num; i++)
	{
		char a = 'a';
		cha.DeQueue(a);
		if (sa[num - i - 1] == a)
		{

		}
		else { break; }
	}
	if (cha.IsEmpty() == true) {
		cout<<"yes";
	}
	else {
		cout<<"no";
	}
}

