#include "list.h"
#include "iostream"
#include "string"
using namespace std;

int main() {
	Sequence Selist;
	Single Silist;
	while (true) {
		cout <<endl<< "1.顺序表" << endl;
		cout << "2.单链表" << endl;
		cout << "3.退出" << endl;
		int k = 0;
		cin >> k;
		
		if (k == 1) {
			while (true) {
				cout << "选择功能：" << endl;
				cout << "  1.元素插入" << endl;
				cout << "  2.元素删除" << endl;
				cout << "  3.顺序表中的值" << endl;
				cout << "  4.退出系统" << endl;
				int i = 0;
				cin >> i;
				
				if (i == 1) {
					while (true) {
						int j = 0;
						cout << "选择方式:" << endl << "  0.退出" << endl;
						cout << "  1.顺序插入（逐个输入，输入@表示结束）" << endl;
						cout << "  2.选择插入" << endl;
						cin >> j;
						if (j == 0) {
							break;
						}
						if (j == 1) {
							string x;
							int temp = 0;
							cout << "输入插入元素：" << endl;
							while (true)
							{
								cin >> x;
								if (x == "@")break;
								temp = atoi(x.c_str());
								Selist.Set(temp);
							}

						}
						if (j == 2) {
							int t = 0, x = 0;
							cout << "输入指定元素值："; cin >> t;
							cout << endl << "输入插入元素："; cin >> x;
							Selist.Insert(t, x);
						}
					}
				}

				if (i == 2) {
					int x = 0;
					cout << endl << "输入删除元素："; cin >> x;
					Selist.Remove(x);
				}
				if (i == 3) { cout << "顺序表中的值：" << endl; Selist.Display(); cout << endl; }

				if (i == 4) {
					break;
				}
				
			}
		}


		if (k == 2) {
			while (true) {

				cout << "选择功能：" << endl;
				cout << "  1.元素插入" << endl;
				cout << "  2.元素删除" << endl;
				cout << "  3.单链表中的值" << endl;
				cout << "  4.逆序单链表" << endl;
				cout << "  5.退出系统" << endl;
				int i = 0;
				cin >> i;
				if (i == 1) {
					while (true) {
						int j = 0;
						cout << "选择方式：" << endl << "  0.退出" << endl;
						cout << "  1.顺序插入（逐个输入，输入@表示结束）" << endl;
						cout << "  2.选择插入" << endl;
						cin >> j;
						if (j == 0) {
							break;
						}
						if (j == 1) {
							string x ;
							int temp = 0;
							cout << "输入插入元素："<<endl;
							while (true)
							{
								cin >> x;
								if (x == "@")break;
								temp = atoi(x.c_str());
								Silist.Set(temp);
							}

						}
						if (j == 2) {
							int t = 0, x = 0;
							cout << "输入指定元素值："; cin >> t;
							cout << endl << "输入插入元素："; cin >> x;
							Silist.Insert(t, x);
						}
					}
				}

				if (i == 2) {
					int x = 0;
					cout << endl << "输入删除元素："; cin >> x;
					Silist.Remove(x);
				}
				if (i == 3) { cout << "单链表中的值" << endl; Silist.Display(); cout << endl; }
				if (i == 4) {
					cout << endl;
					Silist.reverse();
					cout << endl;
				}

				if (i == 5) {
					break;
				}
			}
		}

		if (k == 3) break;


	}
	return 0;
}