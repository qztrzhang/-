#pragma once
#include "iostream"
#include "string"
using namespace std;

const int defaultSize = 100;

class root
{
public:
	root(){}
	~root(){}
	virtual bool Set(int x) = 0;   //°´ÕÕË³ÐòÒÀ´ÎÏò±íÖÐÊäÈëÖµ
	virtual bool Insert(int& x, int& y) = 0;
	virtual bool Remove(int& x) = 0;
	virtual void Display() = 0;
};

class Sequence : public root {
private:
	int* data;
	int maxSize;
	int last;
public:
	Sequence(int sz = defaultSize);
	~Sequence() { delete[] data; }
	bool Set(int x);
	bool Insert(int& x, int& y);
	bool Remove(int& x);
	void Display();
};



Sequence::Sequence(int sz) {
	if (sz > 0) {
		maxSize = sz; last = -1;
		data = new int[maxSize];
		if (data == NULL) {
			cerr << "´¢´æ·ÖÅä´íÎó£¡" << endl; exit(1);
		}
	}
}

bool Sequence::Set(int x) {
	if (last + 1 == maxSize) {
		maxSize += 100;
	}
	this->data[last+1 ] = x;
	last++;
	
	return true;
}

bool Sequence::Insert(int& x, int& y) {
	if (last == -1) return false;
	for (int i = 0; i <= last; i++) {
		if (data[i] == x) {
			for (int j = last; j > i; j--) {
				if (j == last) { this->Set(data[j]); continue; }
				data[j+1]=data[j];
			}
			data[i + 1] = y;
		}
	}
	return true;
}
//bool Sequence::Insert(int i, int& x) {
//	if (last == maxSize) return false;
//	if (i<0 || i>last + 1)return false;
//	for (int j = last; j >= i; j--)data[j + 1] = data[j];
//	data[i] = x;
//	last++;
//	return true;
//}


bool Sequence::Remove(int& x) {
	if (last == -1)return false;
	for (int j = 1; j <= last; j++) {
		if (data[j - 1] == x) {
			data[j - 1] = data[j];
			last--; j--;
		}
	}
	if (data[last] == x) { data[last] = NULL; last--; }
	return true;
}

//bool Sequence::Remove(int i,int& x) {
//	if (last == -1)return false;
//	if (i<1 || i>last + 1)return false;
//	x = data[i - 1];
//	for (int j = i; j <= last; j++) data[j - 1] = data[j];
//	last--;
//	return true;
//}


void Sequence::Display() {
	for (int i = 0; i <= last; i++)
		cout << "#" << i << ":" << data[i] << endl;
}


struct LinkNode {
	int data;
	LinkNode* link;
	LinkNode(LinkNode* ptr = NULL) { link = ptr; }
	LinkNode(const int& item, LinkNode* ptr = NULL) { data = item; link = ptr; }
};

class Single :public root{
private:
	LinkNode* first;
public:
	Single() {first = new LinkNode;}
	Single(const int& x) { first = new LinkNode(x); }
	~Single();
	int length()const;//ËÑË÷µÚi¸öÔªËØµÄµØÖ·
	bool Set(int x);
	bool Insert(int& x, int& y);
	bool Remove(int& x);
	void Display();
	bool reverse();
	LinkNode* Locate(int i);
};


LinkNode* Single::Locate(int i) {
	if (i < 0) return NULL;
	LinkNode* current = first; int k = 0;
	while (current != NULL && k < i) {
		current = current->link; k++;
	}
	return current;
}





Single::~Single() {
	LinkNode* q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

int Single::length()const {
	LinkNode* p = first->link; int count = 0;
	while (p != NULL) {
		p = p->link; count++;
	}
	return count;
}

bool Single::Set(int x) {
	LinkNode* q = new LinkNode(x);
	if (q == NULL)return false;
	LinkNode* current = first;
	while (current->link != NULL) {
		current = current->link;
		
	}
	current->link = q;
	return true;
}

bool Single::Insert(int& x, int& y) {
	LinkNode* current = first->link;
	LinkNode* newNode = new LinkNode(y);
	while (current != NULL) {
		if (current->data == x) {
			newNode->link = current->link;
			current->link = newNode;
			break;
		}
		current = current->link;
	}
	return true;
}
//bool Single::Insert(int i, int& x) {
//	LinkNode* current = Locate(i);
//	if (current == NULL)return false;
//	LinkNode* newNode = new LinkNode(x);
//	if (newNode == NULL) { cerr << "´¢´æ·ÖÅä´íÎó£¡" << endl; exit(1); }
//	newNode->link = current->link;
//	current->link = newNode;
//	return true;
//}


bool Single::Remove(int& x) {
	LinkNode* current = first;
	while (current->link != NULL) {
		if (current->link->data == x) {
			LinkNode* del = current->link;
			current->link = current->link->link;
			delete del;
			continue;
		}
		current = current->link;
	}
	return true;
}

//bool Single::Remove(int i,int& x) {
//	LinkNode* current = Locate(i);
//	if (current = NULL) return false;
//	LinkNode* newNode = new LinkNode(x);
//	if (newNode == NULL) { cerr << "´¢´æ·ÖÅä´íÎó£¡" << endl; exit(1); }
//	newNode->link = current->link;
//	current->link = newNode;
//	return true;
//}


void Single::Display() {
	LinkNode* current = first->link; int i = 0;
	while (current != NULL) {
		cout << "#" << i++ << ":" << current->data << endl;
		current = current->link;
	}
}


bool Single::reverse() {
	LinkNode* prev = first->link;
	LinkNode* next = first->link->link;
	LinkNode* temp = NULL;
	prev->link = NULL;
	while (next!=NULL) {
		temp = next->link;
		next->link = prev;
		prev = next;
		next = temp;
	}
	first->link = prev;
	return true;
}
