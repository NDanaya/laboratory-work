#include <iostream>
#include <math.h>

using namespace std;

double** allocateMemory(int, int);
void displayMatrix(double**, int, int);
void inputTaylorMatrix(double**, int, int, double);
double sinx(double, double);
double cosx(double, double);
void inputFunctionsMatrix(double**, int, int);
double compareMatrix(double**, double**, int, int);


int main()
{
	cout << "Enter the order of the matrix: ";
	int n;
	cin >> n;

	double** A = allocateMemory(n, n);

	cout << "Enter the accuracy:";
	double k;
	cin >> k;

	inputTaylorMatrix(A, n, n, k);
	cout << " Taylor series matrix: " << endl;
	displayMatrix(A, n, n);

	double** B = allocateMemory(n, n);

	inputFunctionsMatrix(B, n, n);
	cout << " Regular functions matrix: " << endl;
	displayMatrix(B, n, n);

	cout << "Matrix comparison: " << compareMatrix(A, B, n, n) << endl;

	system("pause");
	return 0;
}

double** allocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw invalid_argument("Dimentions can not be less or equal zero!");
	}

	double ** matrix = new double*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];
	}

	return matrix;
}

void displayMatrix(double** matrix, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (matrix == nullptr)
	{
		throw invalid_argument("Matrix can not be null.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

void inputTaylorMatrix(double** matrix, int n, int m, double k)
{
	if (n <= 0 || m <= 0)
	{
		throw invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (matrix == nullptr)
	{
		throw invalid_argument("Matrix can not be null.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				matrix[i][j] = (2 * cosx((double)(2 * i), k) - sinx((double)(2 * j), k)) / pow((i + 1), 2);
			}
			else
			{
				matrix[i][j] = i + j;
			}
		}
	}
}

double sinx(double x, double k)
{
	double term = x;
	double sum = x;
	int i = 1;

	do
	{
		sum += term;
		term *= (-1 * x * x) / ((2 * i) * (2 * i + 1));
		i++;
	} while (fabs(term) > k);

	return sum;
}

double cosx(double x, double k)
{
	double term = 1;
	double sum = 1;
	int i = 1;

	do
	{
		sum += term;
		term *= -1 * x * x / ((2 * i - 1) * (2 * i));
		i++;
	} while (fabs(term) > k);

	return sum;
}

void inputFunctionsMatrix(double** matrix, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (matrix == nullptr)
	{
		throw invalid_argument("Matrix can not be null.");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != j)
			{
				matrix[i][j] = (2 * cos(2 * i) - sin(2 * j)) / pow((i + 1), 2);
			}
			else
			{
				matrix[i][j] = i + j;
			}
		}
	}
}

double compareMatrix(double** A, double** B, int n, int m)
{
	if (A == nullptr || B == nullptr)
	{
		throw invalid_argument("Matrix can not be null.");
	}

	if (n <= 0 || m <= 0)
	{
		throw invalid_argument("Dimentions can not be less or equal zero!");
	}

	double maxDifference = 0;

	for (int i = 0; i < n; i++)
	{
		double difference = 0;
		for (int j = 0; j < m; j++)
		{
			difference = *(*(A + i) + j) - *(*(B + i) + j);
			if (difference > maxDifference)
			{
				maxDifference = difference;
			}
		}
	}

	return maxDifference;
}