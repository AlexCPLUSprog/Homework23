#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Задание 1
template <typename T>
void three_max(T &num1, T &num2, T &num3) {
	if (num1 > num2 && num1 > num3) {
		num2 = num1;
		num3 = num1;
	}
	else
		if (num2 > num1 && num2 > num3) {
			num1 = num2;
			num3 = num2;
		}
		else
			if (num3 > num1 && num3 > num2) {
				num1 = num3;
				num2 = num3;
			}
	
}

template <typename T>
void fill_arr(T *arr, int lenght) {
	srand(time(0));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (20 + 2) -2;
}

template <typename T>
void show_arr(T *arr, int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

// Задание 2
template <typename T>
int &ret_arr(T *arr,const int lenght) {
	for (int i = 0; i < lenght; i++)
		if (arr[i] < 0)		
			return arr[i];
	return *arr;
}

// Задание 3
template <typename T1, typename T2>
void zero_arr(T1 arr1[], T2 arr2[], const int lenght1, const int lenght2){
	for (int* pi = arr1; pi != arr1 + lenght1; pi++)
		for (int* pj = arr2; pj != arr2 + lenght2; pj++)
			if (*pj == *pi)
				*pj = 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a = 6, b = 5, c = 7;

	// Задание 1.
	cout << "Задание 1.\n";
	three_max(a, b, c);
	cout << a << ' ' << b << ' ' << c << "\n\n";

	// Задание 2.
	cout << "Задание 2.\n";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size);
	show_arr(arr, size);
	if (ret_arr(arr,size) < 0)
		cout << "Первое отрицательное число в массиве: " << ret_arr(arr,size) << "\n\n";
	else
		cout << "Отрицательных чисел нет. Первый элемент в массиве: " << ret_arr(arr, size) << "\n\n";

	// Задание 3.
	cout << "Задание 3.\n";
	const int size2 = 10, size3 = 8;
	int arr2[size2]{ -3, 2, 6, -11, 2, 4, 10, 8, 9, 1 };
	int arr3[size3]{ 6, 5, 12, 11, -7, 9, 1, 17 };
	cout << "Массив 1:\n";
	show_arr(arr2, size2);
	cout << "Массив 2:\n";
	show_arr(arr3, size3);
	cout << "Массив 2 после вызова функции:\n";
	zero_arr(arr2, arr3, size2, size3);
	show_arr(arr3, size3);
	
	return 0;
}