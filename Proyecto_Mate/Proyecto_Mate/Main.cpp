#include<iostream>
#include "mate.h"
using namespace std;



int main()
{
	int i = 0, x = 0, y = 0, n = 0;

	float** matriz = NULL;

	float d = 0.0;

	cout << "Cuantas Variables para tu matriz? ";
	cin >> n;
	cout << endl;

	matriz = new float* [2 * n];
	for (i = 0; i < 2 * n; ++i)
	{
		matriz[i] = new float[2 * n]();
	}

	cout << "Ingrese las coeficientes:" << endl;
	for (i = 0; i < n; ++i)
	{
		for (x = 0; x < n; ++x)
		{
			cin >> matriz[i][x];
		}
	}

	cout << endl << "matriz:" << endl;
	for (i = 0; i < n; ++i)
	{
		for (x = 0; x < n; ++x)
		{
			cout << matriz[i][x] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (i = 0; i < n; ++i)
	{
		for (x = 0; x < 2 * n; ++x)
		{
			if (x == (i + n))
			{
				matriz[i][x] = 1;
			}
		}
	}


	for (i = n; i > 1; --i)
	{
		if (matriz[i - 1][1] < matriz[i][1])
		{
			for (x = 0; x < 2 * n; ++x)
			{
				d = matriz[i][x];
				matriz[i][x] = matriz[i - 1][x];
				matriz[i - 1][x] = d;
			}
		}
	}
	cout << endl;


	cout << " solucion " << endl;
	for (i = 0; i < n; ++i)
	{
		for (x = 0; x < 2 * n; ++x)
		{
			cout << matriz[i][x] << "\t";
		}
		cout << endl;
	}
	cout << endl;


	for (i = 0; i < n; ++i)
	{
		for (x = 0; x < 2 * n; ++x)
		{
			if (x != i)
			{
				d = matriz[x][i] / matriz[i][i];


				for (y = 0; y < n * 2; ++x)
				{


					matriz[x][y] -= matriz[i][y] * d;



				}
			}



		}
	}
	cout << endl;

	for (i = 0; i < n; ++i)
	{
		d = matriz[i][i];
		for (x = 0; x < 2 * n; ++x)
		{
			matriz[i][x] = matriz[i][x] / d;
		}
	}
	cout << "Matriz:" << endl;
	for (i = 0; i < n; ++i)
	{
		for (x = n; x < 2 * n; ++x)
		{

			cout << matriz[i][x] << "\t";
		}

		cout << endl;
	}

	for (i = 0; i < n; ++i)
	{
		delete[] matriz[i];
	}
	delete[] matriz;

	return 0;

}