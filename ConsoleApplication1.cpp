// Список цел чисел и найти сумму последнего и предпоследнего эл списка

#include <iostream>

using namespace std;

struct node {
	int val;
	node* next;
};

class List {
	node* Head;
public:
	List() {
		Head = NULL;
	}

	~List() {
		while (Head != NULL) {
			node* temp = Head->next;
			delete Head;
			Head = temp;
		}
	}

	void add(int x) { //Функция добавления элемента в список (вывод будет происходить слева направо)
		node* temp = new node;
		temp->val = x;
		temp->next = NULL;
		if (Head == NULL) {
			Head = temp;
		}
		else {
			node* tempNew = Head;
			while (tempNew->next != NULL) {
				tempNew = tempNew->next;
			}
			tempNew->next = temp;
		}
	}

	void insert(int x, int pos) { //Функция добавления элемента в заданную позицию
		if (pos == 1) {
			node* temp = new node;
			temp->val = x;
			temp->next = Head;
			Head = temp;
		}
		else {
			node* temp = new node;
			temp->val = x;
			if (Head == NULL) {
				Head = temp;
			}
			else {
				node* tempNew = Head;
				int count = 1;
				while (tempNew->next != NULL && count < pos - 1) {
					tempNew = tempNew->next;
					count++;
				}
				node* tempNew2 = tempNew->next;
				tempNew->next = temp;
				temp->next = tempNew2;
			}
		}
	}

	void delByPos(int pos) { //Функция удаления элемента под заданной позицией
		node* temp = Head;
		if (pos == 1) {
			Head = Head->next;
			delete temp;
		}
		else {
			node* del;
			int count = 1;
			while (Head != NULL && count < pos - 1) {
				temp = temp->next;
				count++;
			}
			del = temp->next;
			temp->next = del->next;
			delete del;
		}
	}

	void delByVal(int value) { //Функция удаления элемента по его значению
		node* temp = Head;
		node* del = Head->next;
		if (temp->val == value) {
			Head = Head->next;
			delete temp;
		}
		else {
			while (del != NULL) {
				if (del->val == value) {
					break;
				}
				else {
					temp = del;
					del = del->next;
				}
			}
			if (del == NULL) {}
			else {
				temp->next = del->next;
				delete del;
			}
		}
	}

	void swapByPos(int i, int j) { //Функция обмена элементов под заданными позициями
		node* tempi = Head;
		node* tempj = Head;
		int count = 1;
		while (tempi->next != NULL && count != i) {
			tempi = tempi->next;
			count++;
		}
		count = 1;
		while (tempj->next != NULL && count != j) {
			tempj = tempj->next;
			count++;
		}
		swap(tempi->val, tempj->val);
	}

	int size() { //Функция определения количества элементов списка
		node* temp = Head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	void print() { //Функция вывода списка на экран
		node* temp = Head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
	}

	int get(int pos) { //Функция получения элемента по позиции
		node* temp = Head;
		int count = 1;
		int x = 0;
		while (temp->next != NULL && count != pos) {
			temp = temp->next;
			count++;
		}
		x = temp->val;
		return x;
	}
};

int main() {
	int n, m, size, sum = 0;
	List obj;
	cout << "Enter a linked list size:\n";
	cout << "n = ";
	cin >> n;
	cout << "Enter a linked list:\n";
	for (int i = 0; i < n; i++) {
		cin >> m;
		obj.add(m);
	}

	size = obj.size();
	obj.print();
	cout << "\n\n";
	sum = obj.get(size - 1);
	sum += obj.get(size);

	cout << "Sum = " << sum << "\n";

	system("pause");
	return 0;
}


/*

	cin >> option;
	switch (option) {
	case 1:
		obj.delByPos(1);
		break;
	case 2:
		obj.delByPos(obj.size());
		break;
	case 3:
		int x;
		cout << "Enter an element: ";
		cin >> x;
		obj.insert(x, 4);
		break;
	case 4:
		obj.delByVal(4);
		break;
	case 5:
		obj.swapByPos(3, 6);
		break;
	}
	cout << "Output of the program:\n";
	obj.print();
	system("pause");
	return 0;
}*/