#include <iostream>
#include "BST.h"
using namespace std;

int main(){
	BST a;
	setlocale (0, "");

	for (int i = 0; i < 100; i++) {
		int k, num;
		cout << "�������� ��������:\n" <<
			"1 [�����] - �������� �����\n" <<
			"2 [�����] - ������� �����\n" <<
			"3 - �������� ������\n" <<
			"4 [�����] - ���������, ���� �� ����� � ������\n" <<
			"5 - ���������, ���� �� � ������ ��������\n" <<
			"6 - ����� ������" << endl;
		cin >> k;

		switch (k) {
			case 3: {
				a.clear();
				break;
			}
			case 5: {
				cout << (a.isEmpty() ? "������ �����" : "� ������ ���� ��������") << endl;
				break;
			}
			case 6: {
				a.print();
				break;
			}
			case 1: {
				cin >> num;
				a.insert(num);
				break;
			}
			case 2: {
				cin >> num;
				a._delete(num);
				break;
			}
			case 4: {
				cin >> num;
				cout << (a.isContains(num) ? "��" : "���") << endl;
				break;
			}
			default: {
				cout << "������������ �������" << endl;
				break;
			}
		}
		cout << endl << endl;
	}
	return 0;
}
