#include "iostream"
#include "string"
#include "assert.h"
#include "stack.h"
using namespace std;

int main() {
	while (true) {
		cout << "1.����ת�� " << endl;
		cout << "2.�����ж� " << endl;
		cout << "3.�˳�" << endl;
		string sa ;
		cin >> sa;
		int i = 0;

		while (true) {
			if (isdigit(sa[i])) {
				if (i + 1 == sa.length()) break;
			}
			else { cerr << "����Ĳ�������"; exit(3); }
			i++;
		}
		int a = atoi(sa.c_str());
		if (a == 1) {
			while (true) {
				cout << endl << "  1.������" << endl;
				cout << "  2.�˽���" << endl;
				cout << "  3.ʮ������" << endl;
				cout << "  4.�˳�" << endl;
				
				int b;
				cin >> b;
				if (b >= 4) { break; }
				string sc;
				
					cout << endl << "�����ת��ֵ��";
					cin >> sc;
					int i = 0;
					while (true) {
						if (isdigit(sc[i])) {
							if (i + 1 == sc.length()) break;
						}
						else { cerr << "����Ĳ�������" << endl<<endl; break; }
						i++;
					}
					if (!isdigit(sc[i])) break;
				
				int c = atoi(sc.c_str());
				if (b == 1) { cout << "ת��Ϊ������ֵΪ��"; binary(c); cout << endl; }
				if (b == 2) { cout << "ת��Ϊ�˽���ֵΪ��" << endl; octonary(c); cout << endl; }
				if (b == 3) { cout << "ת��Ϊʮ������ֵΪ��" << endl; hexadecimal(c); cout << endl; }
				
			}
		}
		if (a == 2) {
			cout << endl << "������ж�ֵ��";
				judge();
				cout << endl<<endl;
		}
		if (a >= 3) { break; }
	}




	return 0;
}
