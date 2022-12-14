#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& k);
int Sum(int** a, const int rowCount, const int colCount);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int rowCount = 7;
	int colCount = 7;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int k = 0;
	Calc(a, rowCount, colCount, k);
	cout << "k = " << k << endl;
	cout << "Sum = " << Sum(a, rowCount, colCount) << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Calc(int** a, const int rowCount, const int colCount, int& k)
{
	k = 0;
	for (int i = 1; i < rowCount -1; i++)
		for (int j = 1; j < colCount - 1; j++)
			if (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j + 1])
			{
				k++;
				a[i][j] = 0;
			}
}
int Sum(int** a, const int rowCount, const int colCount)
{
	int sum = 0;
	for (int i = 0; i < rowCount - 1; ++i)
	{
		for (int j = i + 1; j < rowCount ; ++j)
		{

			sum += a[i][j];
				

		}
		
		
	}
	return sum;
}