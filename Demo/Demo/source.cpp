#include "list.h"
#include "iostream"
#include "string"
using namespace std;

int main() {
	Sequence Selist;
	Single Silist;
	while (true) {
		cout <<endl<< "1.˳���" << endl;
		cout << "2.������" << endl;
		cout << "3.�˳�" << endl;
		int k = 0;
		cin >> k;
		
		if (k == 1) {
			while (true) {
				cout << "ѡ���ܣ�" << endl;
				cout << "  1.Ԫ�ز���" << endl;
				cout << "  2.Ԫ��ɾ��" << endl;
				cout << "  3.˳����е�ֵ" << endl;
				cout << "  4.�˳�ϵͳ" << endl;
				int i = 0;
				cin >> i;
				
				if (i == 1) {
					while (true) {
						int j = 0;
						cout << "ѡ��ʽ:" << endl << "  0.�˳�" << endl;
						cout << "  1.˳����루������룬����@��ʾ������" << endl;
						cout << "  2.ѡ�����" << endl;
						cin >> j;
						if (j == 0) {
							break;
						}
						if (j == 1) {
							string x;
							int temp = 0;
							cout << "�������Ԫ�أ�" << endl;
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
							cout << "����ָ��Ԫ��ֵ��"; cin >> t;
							cout << endl << "�������Ԫ�أ�"; cin >> x;
							Selist.Insert(t, x);
						}
					}
				}

				if (i == 2) {
					int x = 0;
					cout << endl << "����ɾ��Ԫ�أ�"; cin >> x;
					Selist.Remove(x);
				}
				if (i == 3) { cout << "˳����е�ֵ��" << endl; Selist.Display(); cout << endl; }

				if (i == 4) {
					break;
				}
				
			}
		}


		if (k == 2) {
			while (true) {

				cout << "ѡ���ܣ�" << endl;
				cout << "  1.Ԫ�ز���" << endl;
				cout << "  2.Ԫ��ɾ��" << endl;
				cout << "  3.�������е�ֵ" << endl;
				cout << "  4.��������" << endl;
				cout << "  5.�˳�ϵͳ" << endl;
				int i = 0;
				cin >> i;
				if (i == 1) {
					while (true) {
						int j = 0;
						cout << "ѡ��ʽ��" << endl << "  0.�˳�" << endl;
						cout << "  1.˳����루������룬����@��ʾ������" << endl;
						cout << "  2.ѡ�����" << endl;
						cin >> j;
						if (j == 0) {
							break;
						}
						if (j == 1) {
							string x ;
							int temp = 0;
							cout << "�������Ԫ�أ�"<<endl;
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
							cout << "����ָ��Ԫ��ֵ��"; cin >> t;
							cout << endl << "�������Ԫ�أ�"; cin >> x;
							Silist.Insert(t, x);
						}
					}
				}

				if (i == 2) {
					int x = 0;
					cout << endl << "����ɾ��Ԫ�أ�"; cin >> x;
					Silist.Remove(x);
				}
				if (i == 3) { cout << "�������е�ֵ" << endl; Silist.Display(); cout << endl; }
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