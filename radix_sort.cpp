#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n;

//функция для получения максимального элемента
int getMax() {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

//сортировка по конкретному разряду
void sortByDigit(int r) {
	int d10 = 1;
	for (int i = 0; i < r; i++) {
		d10 *= 10;
	}

	vector<int> c(10, 0); //счетчик цифр
	vector<int> b(n); //временный массив
	vector<int> d(10); //позиции для вставки

	//подсчет кол-ва каждой цифры
	for (int i = 0; i < n; i++) {
		c[(a[i] / d10) % 10]++;
	}

	//вычисление стартовых позиций
	d[0] = 0;
	for (int i = 1; i < 10; i++) {
		d[i] = d[i - 1] + c[i - 1];
	}

	//распределение элементов
	for (int i = 0; i < n; i++) {
		int x = (a[i] / d10) % 10;
		b[d[x]] = a[i];
		d[x]++;
	}
	a = b;
}

int main() {
	//ввод кол-ва элементов
	cout << "Введите кол-во элементов массива: ";
	cin >> n;
	a.resize(n);

	//ввод элементов
	cout << "Введите элементв массива: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//находим максимальное число
	int max = getMax();

	//вычисляем кол-во разрядов
	int r = 0;
	while (max != 0) {
		max /= 10;
		r++;
	}

	//поразрядная сортировка 
	for (int i = 0; i < r; i++) {
		sortByDigit(i);
	}

	cout << "\nОтсортированный массив: \n";
	for (int num : a) {
		cout << num << " ";
	}
	return 0;
}