#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Сортировка вставками 
void insertionSort(vector<double>& bucket) {
	int n = bucket.size();
	for (int i = 1; i < n; i++) {
		double key = bucket[i];//текущий элемент для вставки
		int j = i - 1;

		//сдвигаем элементы больше key вправо
		while (j >= 0 && bucket[j] > key) {
			bucket[j + 1] = bucket[j];
			j--;
		}
		bucket[j + 1] = key;

	}
}

//bucket_sort
void bucketSort(vector<double>& arr) {
	
	//поиск минимуму и максимума
	double min = arr[0];
	double max = arr[0];
	for (double num : arr) {
		if (num < min) {
			min = num;
		}
		if (num > max) {
			max = num;
		}
	}

	//создание бакетов
	int count = arr.size();
	vector<vector<double>> buckets(count);

	//распределение чисел по бакетам
	for (double num : arr) {
		double pos = (num - min) / (max - min); //(0...1)
		int bucket_index = pos * count; //определяем индекс ведра

		if (bucket_index >= count) {
			bucket_index = count - 1; //защита от выхода за границы
		}
		buckets[bucket_index].push_back(num);
	}

	//сортировка каждого бакета
	for (auto& bucket : buckets) {
		insertionSort(bucket);
	}

	//сборка в исходный массив
	int index = 0;
	for (auto& bucket : buckets) {
		for (double num : bucket) {
			arr[index] = num;
			index++;
		}
	}
}
int main() {
	cout << "Введите числа: \n";

	vector<double> numbers;
	double num;
	while (cin >> num) {
		numbers.push_back(num);
	}

	bucketSort(numbers);

	cout << "Отсортированный массив:\n";
	for (double n : numbers) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}