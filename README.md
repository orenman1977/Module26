# Module26
Итоговое задание

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

// Процессор: Core i9-9900KF:
// 10 млн элементов (0...10)

// в основном потоке
Summa main = 44987807
Time taken is 0.0253211 sec

// 1 поток
itog26 10000000 1
Summa threads = 44987807
Time taken is 0.0152789 sec

// 2 потока
itog26 10000000 2
Summa threads = 44987807
Time taken is 0.0088379 sec

// 4 потока
itog26 10000000 4
Summa threads = 44987807
Time taken is 0.0057749 sec

// 8 потоков
itog26 10000000 8
Summa threads = 44987807
Time taken is 0.005744 sec

// 16 потоков
itog26 10000000 16
Summa threads = 44987807
Time taken is 0.0063812 sec
