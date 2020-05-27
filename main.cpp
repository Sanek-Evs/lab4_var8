#include <iostream>
#include "BST.h"
using namespace std;

int main(){
	BST a;
	setlocale (0, "");

	for (int i = 0; i < 100; i++) {
		int k, num;
		cout << "Выберите действие:\n" <<
			"1 [число] - Вставить число\n" <<
			"2 [число] - Удалить число\n" <<
			"3 - Очистить дерево\n" <<
			"4 [число] - Проверить, есть ли число в дереве\n" <<
			"5 - Проверить, есть ли в дереве элементы\n" <<
			"6 - Вывод дерева" << endl;
		cin >> k;

		switch (k) {
			case 3: {
				a.clear();
				break;
			}
			case 5: {
				cout << (a.isEmpty() ? "Дерево пусто" : "В дереве есть элементы") << endl;
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
				cout << (a.isContains(num) ? "Да" : "Нет") << endl;
				break;
			}
			default: {
				cout << "Некорректная команда" << endl;
				break;
			}
		}
		cout << endl << endl;
	}
	return 0;
}
