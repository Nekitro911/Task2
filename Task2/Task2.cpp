// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;

const int max = 500;
int N = 100;
int array[max];
int compare = 0;
int fw = 0;

void IncArray(void);
void DecArray(void);
void RandArray(void);
void ViewArray(void);
void CheckSum(void);
void Series(void);
void ShellSort(void);
void QuickSort(int* array, int first, int last);
void ChangeArraySize(void);
int main()
{
	setlocale(LC_ALL, "Russian");

	system("mode con cols=70 lines=60");
	system("color 0");
	
	char c;
	while (1)
	{
		system("cls");
		cout << "\n";
		cout << " Размер массива - " << N << ".\n\n";
		cout << " 1) Создать возрастающий массив\n";
		cout << " 2) Создать убывающий массив\n";
		cout << " 3) Создать рандомный массив\n";
		cout << " 4) Просмотр массива\n";
		cout << " 5) Сортировка методом Шелла\n";
		cout << " 6) Сортировка методом Хоара\n";
		cout << " 7) Изменить размер массива\n";
		cout << "\n";
		cout << " Esc - Выход\n";
		c = _getch();
		switch (c)
		{
			system("cls");
		case '1':system("cls"); IncArray(); system("pause"); break;
		case '2':system("cls"); DecArray(); system("pause"); break;
		case '3':system("cls"); RandArray(); system("pause"); break;
		case '4':system("cls"); ViewArray(); CheckSum(); Series(); system("pause"); break;
		case '5':system("cls"); ShellSort(); system("pause"); break;
		case '6':
			system("cls");
			compare = 0;
			fw = 0;
			cout << "До сортировки:\n";
			CheckSum();
			Series();
			cout << "\n";
			QuickSort(array, 0, N - 1);
			ViewArray();
			cout << "После сортировки:\n";
			CheckSum();
			Series();
			cout << "\n";
			cout << "Количество пересылок: " << fw << ", количество сравнений: " << compare << endl;
			system("pause");
			fw = 0;
			compare = 0;
			break;
		case '7':system("cls"); ChangeArraySize(); system("pause"); break;
		case 27:return 0;
		default:cout << "\nОшибка! Неверный ввод. Нажмите любую клавишу."; _getch();
		}
	}
}
void IncArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = i + 1;
	}
	cout << "Возрастающий массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}

void DecArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - i;
	}
	cout << "Убывающий массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}

void RandArray()
{
	for (int i = 0; i < N; i++)
	{
		array[i] = 1 + rand() % N;
	}
	cout << "Рандомный массив создан!\n\n";
	ViewArray();
	CheckSum();
	Series();
}

void ViewArray()
{
	for (int i = 0; i != N; i = i + 10)
	{

		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n", array[i], array[i + 1], array[i + 2], array[i + 3], array[i + 4], array[i + 5], array[i + 6], array[i + 7], array[i + 8], array[i + 9]);
	}
	cout << "\n";
}


void CheckSum()
{
	int cs;
	cs = 0;
	for (int i = 0; i < N; i++)
	{
		cs = cs + array[i];
	}
	cout << "Контрольная сумма: " << cs << "\n";
}

void Series()
{
	int s;
	s = 0;
	for (int i = 0; i < N + 1; i++)
	{
		if (array[i] <= array[i + 1])
			s = s;
		else
			s = s + 1;
	}
	cout << "Количество серий: " << s << "\n";
}

void ShellSort()
{
	int gap, i, j, temp;
	compare = 0;
	fw = 0;
	cout << "До сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	for (gap = N / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < N; i++, compare++)
			for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap, compare++)
			{
				compare++;
				temp = array[j];
				fw++;
				array[j] = array[j + gap];
				fw++;
				array[j + gap] = temp;
				fw++;
			}
	}
	ViewArray();
	cout << "После сортировки:\n";
	CheckSum();
	Series();
	cout << "\n";
	cout << "Количество пересылок: " << fw << ", количество сравнений: " << compare << endl;
}
void QuickSort(int* array, int first, int last) {
	int i = first, j = last, temp, x = array[(first + last) / 2];
	do
	{
		compare++;
		while (array[i] < x)
			i++;
		while (array[j] > x)
			j--;
		if (i <= j)
		{
			compare++;
			if (i < j)
				compare++;
			{
				temp = array[i];
				fw++;
				array[i] = array[j];
				fw++;
				array[j] = temp;
				fw++;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		QuickSort(array, i, last);
	if (first < j)
		QuickSort(array, first, j);
}
void ChangeArraySize()
{
	system("cls");
	cout << "\n";
	cout << " Введите размер массива: ";
	cin >> N;
	cout << " Размер массива изменен N = " << N << endl;
	cout << "\n";
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
