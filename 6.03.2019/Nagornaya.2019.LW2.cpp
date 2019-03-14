#include <iostream>
#include <math.h>

using namespace std;

void inputLength(int&);
double* memoryAllocation(int);
void randomArray(double*, int);
void divideDigits(double*, int, int, int&);
double* createOdd(double*, int);
void displayArray(double*, int);
void quickSort(double*, int, int);
void swap(double*, double*);
void roundDigits(double*, int, int);

int main()
{
	//c-oldArray; x-newArray
	int n;
	inputLength(n);
	double * c = new double[n];
	randomArray(c, n);
	cout << "Array:   " << endl;
	displayArray(c, n);

	int a;
	cout << "Enter a divisor:  " << endl;
	cin >> a;

	int m = 0;
	divideDigits(c, n, a, m);


	double* x = memoryAllocation(n / 2);
	x = createOdd(c, n);

	int left = 0;
	int right = m - 1;
	quickSort(x, left, right);

	int k;
	cout << endl;
	cout << "Enter a digit of rounding:  " << endl;
	cin >> k;


	roundDigits(x, n - m, k);
	displayArray(x, n - m);


	system("pause");
	return 0;
}

void inputLength(int& n)
{
	cout << "Enter length of array:  " << endl;
	cin >> n;
	if (n < 0)
	{
		cout << "Error" << endl;
		inputLength(n);
	}
}

double* memoryAllocation(int n)
{
	return new double[n];
}

void randomArray(double* array, int n)
{
	for (double* p = array, i = 1; p < array + n; p++, i++)
	{
		*p = rand() % 20 - 9;
	}
}

void displayArray(double* array, int n)
{
	for (double* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}

void quickSort(double* x, int left, int right)
{
	int i = left, j = right;
	double tmp;
	double pivot = x[(left + right) / 2];
	
	while (i <= j) 
	{
		while (x[i] > pivot)
			i++;
		while (x[j] < pivot)
			j--;

		if (i <= j) 
		{
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			i++;
			j--;
		}
	}
	
	if (left < j)
		quickSort(x, left, j);
	if (i < right)
		quickSort(x, i, right);
}

double* createOdd(double* c, int n)
{

	double* x = new double[n / 2];
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			x[j] = c[i];
			j++;
		}
	}

	return x;
}

void divideDigits(double* c, int n, int a, int& m)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			c[i] /= a;
			m++;
		}
	}
}

void roundDigits(double* x, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = floor(x[i] * pow(10, k) + 0.5) / pow(10, k);
	}
}