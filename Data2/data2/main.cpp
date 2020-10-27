#include "iostream"
#include "string"
#include "assert.h"
#include "stack.h"
using namespace std;

int main() {
	while (true) {
		cout << "1.数制转换 " << endl;
		cout << "2.回文判断 " << endl;
		cout << "3.退出" << endl;
		string sa ;
		cin >> sa;
		int i = 0;

		while (true) {
			if (isdigit(sa[i])) {
				if (i + 1 == sa.length()) break;
			}
			else { cerr << "输入的不是数字"; exit(3); }
			i++;
		}
		int a = atoi(sa.c_str());
		if (a == 1) {
			while (true) {
				cout << endl << "  1.二进制" << endl;
				cout << "  2.八进制" << endl;
				cout << "  3.十六进制" << endl;
				cout << "  4.退出" << endl;
				
				int b;
				cin >> b;
				if (b >= 4) { break; }
				string sc;
				
					cout << endl << "输入待转化值：";
					cin >> sc;
					int i = 0;
					while (true) {
						if (isdigit(sc[i])) {
							if (i + 1 == sc.length()) break;
						}
						else { cerr << "输入的不是正数" << endl<<endl; break; }
						i++;
					}
					if (!isdigit(sc[i])) break;
				
				int c = atoi(sc.c_str());
				if (b == 1) { cout << "转化为二进制值为："; binary(c); cout << endl; }
				if (b == 2) { cout << "转化为八进制值为：" << endl; octonary(c); cout << endl; }
				if (b == 3) { cout << "转化为十六进制值为：" << endl; hexadecimal(c); cout << endl; }
				
			}
		}
		if (a == 2) {
			cout << endl << "输入待判断值：";
				judge();
				cout << endl<<endl;
		}
		if (a >= 3) { break; }
	}




	return 0;
}
