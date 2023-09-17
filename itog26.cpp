/*	Многопоточное программирование
	Модуль 26. Введение в многопоточное программирование
	Итоговое задание
*/
// Задача: реализуйте подсчёт суммы элементов массива несколькими потоками.
//
//  Массив случайных чисел размером N должен разбиваться на M равных частей(M < N), каждая из которых выполняется в отдельном потоке.
//	Каждый поток вычисляет сумму элементов своей части.
//	По завершении выполнения потоков, вычисляется общая сумма массива.
//	Входные переменные :
//
//  N — размер массива;
//
//  M — количество частей, на которые будет разбит массив.
//
//  Результат: сумма элементов массива.

#include "itog26.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

int main(size_t argc, char** argv)
{
	if (argc != 3) {
		std::cout << "Using: itog26 [array size] [number of parts]\n";
		return 1;
	}

	glava26::result = 0 ;
	const size_t quantity_numbers = atoi(argv[1]);		// кол-во чисел
	const size_t quantity_pieces = atoi(argv[2]);		// кол-во частей
	size_t lenght = quantity_numbers / quantity_pieces;	// размер одной части

	// заполняю массив чисел
	std::vector<int> arr_nums;
	std::vector<std::thread> arr_threads;
	for (size_t i = 0; i < quantity_numbers; ++i) {
		arr_nums.push_back(std::rand() % 10);
	}

	// заполняю массив потоков
	auto start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < quantity_pieces; ++i) {
		size_t size = lenght;
		if (i == quantity_pieces - 1) size = quantity_numbers - i * lenght;
		//std::thread t(glava26::sumFunc, arr_nums.data(), i * lenght, size);
		//arr_threads.push_back(std::move(t));
		arr_threads.push_back(std::move(std::thread(glava26::sumFunc, arr_nums.data(), i * lenght, size)));
	}

	// жду завершения потоков
	for (size_t i = 0; i < quantity_pieces; ++i) {
		if (arr_threads[i].joinable()) arr_threads[i].join();
	}
	auto end = std::chrono::high_resolution_clock::now();

	// итоговая сумма многопоток
	std::cout << "\nSumma threads = " << glava26::result << "\n";
	double time_taken =	std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Time taken is " << time_taken * 1e-9 << " sec\n";

	glava26::result = 0;
	start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < quantity_numbers; ++i) {
		glava26::result += arr_nums[i];
	}
	end = std::chrono::high_resolution_clock::now();

	// итоговая сумма основной поток
	std::cout << "\nSumma main = " << glava26::result << "\n";
	time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Time taken is " << time_taken * 1e-9 << " sec\n";

}

void glava26::sumFunc(int* arr, int index, int lenght) {
	int sum = 0;
	for (int i = index; i < (index + lenght); ++i) sum += arr[i];
	glava26::result += sum;
}

