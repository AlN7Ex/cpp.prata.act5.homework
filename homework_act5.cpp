//homework_act5 -- Theme: Cycles and expressions of relationship


// Task 1 -			Напишите программу, запрашивающую у пользователя ввод двух целых чисел.
//					Затем программ должна вычислить и выдать сумму всех целых чисел, лежащих
//					между этими двумя целыми. Предполагается, что меньшее значение вводится
//					первым. Например, если пользователь ввел 2 и 9, программа должна
//					сообщить, что сумма всех целых чисел от 2 до 9 равна 44.

#include <iostream>
int count(int first_num, int second_num);

int main()
{
	using namespace std;
	short first_num, second_num;
	cout << "Enter two number for count sum of all number beetwen them." << endl;
	cout << "Enter first number: ";
	cin >> first_num;
	cout << "Enter second (more then first): ";
	cin >> second_num;
	const short sum = count(first_num, second_num);
	cout << "Sum of all number beetwen "
		 << first_num << " and " << second_num << ": "
		 << sum << endl;

	return 0;
}

int count(int first, int second)
{
	int sum = 0;
	for (int a = first; a <= second; a++)
	{
		sum += a;
	}

	return sum;
}



// Task 2 -- Перепишите код из листинга 5.4 с использованием объекта array вместо
//			 встроенного массива и типа long double вместо long long.
//			 Найдите значение 100!


//formore.cpp

#include <iostream>
#include <array>

int main()
{
	const int factorial_size = 100;
	std::array<long double, 100> factorial;
	factorial[0] = factorial[1] = 1L;

	for (int i = 2; i < factorial_size; i++)
	{
		factorial[i] = i * factorial[i - 1];
	}
	for (int i = 0; i < factorial_size; i++)
	{
		std::cout << i << "! = " << factorial[i] << std::endl;
	}

	return 0;
}


// Task 3 -- Напишите программу, которая приглашает пользователя вводить числа.
//			 После каждого введенного значения программа должна выдавать
//			 накопленную сумму введенных значений. Программа должна завершаться
//			 при вводе 0

#include <iostream>

int main()
{
	using namespace std;
	cout << "Enter digit and gets sum." << endl;
	cout << "Enter the number: ";
	short number, accumulated = 0;
	cin >> number;
	while (number != 0)
	{
		accumulated += number;
		cout << "Accumulated numbers: " << accumulated << endl;
		cout << "Enter the number yet: ";
		cin >> number;
	}
	cout << "All accumulated numbers: " << accumulated << endl;

	return 0;
}


//Task 3 -- Дафна инвестировала 100$ под простые 10%. Другими словами, ежегодно
//			инвестиция должна приносить 10% инвестированной суммы (10$ каждый год):

//			прибыль = 0.10 * исходные баланс.

//			В то же время Клео инвестировала 100$ под сложные 5%. Это значит, что
//			прибыль составить 5% от текущего баланса, включая предыдущую накопленную
//			прибыль:
//
//			прибыль = 0.05 * текущий баланс
//
//			Клео зарабатвает 5% от 100$ в первый год, что даёт ей 105$. На следующий
//			год она зарабатывает 5% от 105$, что составляет 5.25$ и т.д. Напишите
//			программу, которая вычислит, сколько лет понадобится для того, чтобы
//			сумма баланса Клео превысила сумму баланса Дафны, с отображением обоих
//			балансов за каждый год


#include <iostream>
double dafna(double source_capital);
double cleo(double cleo_capital);

int main()
{
	using namespace std;
	const int source_capital = 100;
	long double dafna_capital, cleo_capital;
	dafna_capital = cleo_capital = source_capital;
	int year_count = 0;

	do
	{
		dafna_capital += dafna(source_capital);
		cout << "Now Dafna's capital is " << dafna_capital << "$" << endl;
		cleo_capital += cleo(cleo_capital);
		cout << "Now Cleo's capital is " << cleo_capital << "$" << endl;
		cout << ":" << endl;
		year_count++;

	}
	while (dafna_capital > cleo_capital);

	cout << "Need " << year_count << " years." << endl;
}

double dafna(double source_capital)
{
	return source_capital * 0.1;
}

double cleo(double cleo_capital)
{
	return cleo_capital * 0.05;
}


// Task 5 - Предположим, что вы продаете книгу по программированию на языке С++
//			для начинающих. Напишите программу, которая позволит ввести ежемесячные
//			объемы продаж в течение года (в количестве книг). Программа должна
//			использовать цикл, в котором выводится приглашение с названием месяца,
//			применяя массив указателей на char (или массив объектов string),
//			инициализированный строками названиями месяцев, и сохраняя введенные
//			значения в массиве int. Затем программа должна найти сумму содержимого
// 			массива и выдать общий объём продаж за год.

#include <iostream>
const int MONTHS = 12;
int main()
{
	using namespace std;
	short books[MONTHS] = {};
	short total_sales = 0;
	const string Months[MONTHS]
	{
		"January", "Febraury", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};

	for (int i = 0; i < MONTHS; i++)
	{
		cout << Months[i] << ": ";
		cin >> books[i];
		total_sales += books[i];
		//cout << "Books [" << i << "]: " << books[i] << endl;
	}
	cout << "Total sales in the year: " << total_sales << endl;

	return 0;
}


// Task 7 - Разработайте структуру по имени car, которая будет хранить
//			следующую информация об автомобиле: название производителя
//			и год выпоска автомобиля. Напишите программу, которая запросит
//			пользователя, сколько амтомобилей необходимо включить в каталог.
//			Затем программа должна применить new для создание динамического
//			массива структур car указанного пользователем размера. Далее
//			она должна пригласить пользователя ввести название производителя
//			и год выпуска для наполнение данными каждой структуры в массиве.
//			И, наконец, она должна отобразить содержимое каждой структуры.


#include <iostream>
#include <string>
struct car
{
	std::string brand;
	int year;
};

int main()
{
	using namespace std;
	cout << "How many cars do you want to add? ";
	int amount;
	cin >> amount;
	car * pcar = new car [amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter car: ";
		cin >> pcar[i].brand;
		cout << "Enter year: ";
		cin >> pcar[i].year;
	}
	cout << "Your collections:" << endl;
	
	for (int i = 0; i < amount; i++)
	{
		cout << pcar[i].year << "-" << pcar[i].brand << endl;
	}
	delete [] pcar;

	return 0;
}
