//Task 4 -- Дафна инвестировала 100$ под простые 10%. Другими словами, ежегодно
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

enum typeCalculation
{
	SIMPLE_INTEREST,
	COMPOUND_INTEREST
};

struct Anyone
{
	double simpleInterestRate;
	double compoundInterestRate;
	double initialBalance;
	double currentBalance;
};

double balanceCalculation(Anyone *  const anyone, typeCalculation types);

int main()
{
	using namespace std;
	int year_count = 0;
	
	Anyone * const Dafna = new Anyone;
	Dafna->simpleInterestRate = 0.1;
	Dafna->initialBalance = 100;
	Dafna->currentBalance = 100;

	Anyone * const Cleo = new Anyone;
	Cleo->compoundInterestRate = 0.05;
	Cleo->initialBalance = 100;
	Cleo->currentBalance = 100;

	do
	{
		Dafna->currentBalance += balanceCalculation(Dafna, SIMPLE_INTEREST);
		cout << "Now Dafna's balance is " << Dafna->currentBalance << "$" << endl;
		Cleo->currentBalance += balanceCalculation(Cleo, COMPOUND_INTEREST);
		cout << "Now Cleo's balance is " << Cleo->currentBalance << "$" << endl;
		cout << ":" << endl;
		year_count++;

	}
	while (const Dafna->currentBalance > const Cleo->currentBalance);

	cout << "Need " << year_count << " years." << endl;
	delete Dafna;
	delete Cleo;

	return 0;
}

double balanceCalculation(Anyone * const anyone, typeCalculation types)
{
	if (types == SIMPLE_INTEREST)
	{
		return anyone->initialBalance * anyone->simpleInterestRate;
	}
	else if (types == COMPOUND_INTEREST)
	{
		return anyone->currentBalance * anyone->compoundInterestRate;
	}
	else
	{
		std::cerr << "Something wrong!";
		return -1;
	}
}