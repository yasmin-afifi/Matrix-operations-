#include <iostream>
#include <string>
#include<cstdlib>
#include<sstream>
using namespace std;

constexpr auto COLS = 30;
constexpr auto ROWS = 30;

void Get_Inverse(float A[ROWS][COLS], float C[ROWS][COLS], int row);
int Get_Determinant(float A[ROWS][COLS], int n);
void Get_Adjoint(float A[ROWS][COLS], float adj[ROWS][COLS], int n);
void Get_Cofactor(float A[ROWS][COLS], float temp[ROWS][COLS], int n, int m, int size);

//function input matrix
void enter_matrix(float A[COLS][ROWS], int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> A[i][j];
		}
	}
}

//function of addition
void Add_matrix(float A[ROWS][COLS], float B[ROWS][COLS], float C[ROWS][COLS], int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << "\t" << C[i][j];

		}
		cout << "\n";
	}
}

//function of subtraction 
void Sub_matrix(float A[ROWS][COLS], float B[ROWS][COLS], float C[ROWS][COLS], int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << "\t" << C[i][j];

		}
		cout << "\n";
	}
}

//function of multiplication 
void Mal_matrix(float A[ROWS][COLS], float B[ROWS][COLS], float C[ROWS][COLS], int n, int m)
{
	int i, j, k;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			C[i][j] = 0;
			for (k = 0; k < m; ++k) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << "\t" << C[i][j];

		}
		cout << "\n";
	}

}

//function of division 
void Div_matrix(float A[ROWS][COLS], float B[ROWS][COLS], float C[ROWS][COLS], int row1, int col1, int row2) {

	float I[ROWS][COLS];
	Get_Inverse(B, I, row2);

	Mal_matrix(A, I, C, row1, col1);

}

//function to get the inverse
void Get_Inverse(float A[ROWS][COLS], float C[ROWS][COLS], int row)
{

	int det = Get_Determinant(A, row);
	if (det == 0)
	{
		cout << "Singular matrix, can't find its inverse.\n";
	}

	float adj[ROWS][COLS];
	Get_Adjoint(A, adj, row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {

			C[i][j] = adj[i][j] / float(det);
		}
	}

}

//function to get the determinant
int Get_Determinant(float A[ROWS][COLS], int n)
{
	int D = 0;

	if (n == 1)
		return A[0][0];

	float temp[ROWS][COLS];

	int sign = 1;

	for (int i = 0; i < n; i++)
	{

		Get_Cofactor(A, temp, 0, i, n);
		D += sign * A[0][i] * Get_Determinant(temp, n - 1);

		sign = -sign;
	}

	return D;
}

//function to get the cofactor
void Get_Cofactor(float A[ROWS][COLS], float temp[ROWS][COLS], int n, int m, int size)
{
	int i = 0, j = 0;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{

			if (row != n && col != m)
			{
				temp[i][j++] = A[row][col];

				if (j == size - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

//function to get the adjooint
void Get_Adjoint(float A[ROWS][COLS], float adj[ROWS][COLS], int n)
{
	if (n == 1)
	{
		adj[0][0] = 1;
		return;
	}

	int sign = 1;
	float temp[ROWS][COLS];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Get_Cofactor(A, temp, i, j, n);


			sign = ((i + j) % 2 == 0) ? 1 : -1;


			adj[j][i] = (sign) * (Get_Determinant(temp, n - 1));
		}
	}
}

//function of display screen
void display_screen()
{
	cout << "1-Show matrix A.\n";
	cout << "2-Show matrix B.\n";
	cout << "3-Addition C=A+B.\n";
	cout << "4-Subtraction C=A-B.\n";
	cout << "5-Multiplication C=A*B. \n";
	cout << "6-Transpose matrix A.\n";
	cout << "7-Transpose matrix B.\n";
	cout << "8-Division C=A/B.\n";
	cout << "9-Exit.\n";

}

//function of transpose
void Trans_matrix(float A[ROWS][COLS], float C[ROWS][COLS], int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			C[j][i] = A[i][j];
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << "\t" << C[i][j];

		}
		cout << "\n";
	}
}

//function to show the matrix
void Show_matrix(float A[ROWS][COLS], int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << "\t" << A[i][j];
		}
		cout << "\n";
	}
}

//function to check error in sum
string Error_sum(int row1, int col1, int row2, int col2)
{
	string error = "\nError.\n";
	if (row1 != row2 || col1 != col2)

		return error;
}

//function to check error in product
string Error_mult(int col1, int row2)
{
	string error = "\nError.\n";
	if (col1 != row2)
		return error;
}

//function to check error in divison 
string Error_div(int col1, int row2)
{
	string error = "\nError.\n";
	if (col1 != row2)
		return error;
}


int main()
{
	int n = 0, m = 0;
	int z = 0, x = 0;
	float A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];


	//reading first matrix
	cout << "The properties of first matrix.\n";
	cout << "Enter number of Rows:"; cin >> n;
	cout << "Enter number of Colums:"; cin >> m;
	cout << "Please enter the first matrix \n";

	enter_matrix(A, n, m);

	//reading second matrix
	cout << "The properties of second matrix.\n";
	cout << "Enter number of Rows:"; cin >> z;
	cout << "Enter number of Colums:"; cin >> x;
	cout << "Please enter the second matrix \n";

	enter_matrix(B, z, x);

	//taking user choice to make an operation 
	int choice = 0;
	do
	{
		display_screen();
		cout << "enter your choice.\n";
		cin >> choice;

		switch (choice)
		{
		case 1: Show_matrix(A, n, m);

			break;

		case 2: Show_matrix(B, z, x);

			break;

		case 3:
			if (n != z || m != x)
			{
				cout << Error_sum(n, m, z, x);
			}
			else
			{
				Add_matrix(A, B, C, n, m);
			}
			break;

		case 4:
			if (n != z || m != x)
			{
				cout << Error_sum(n, m, z, x);
			}
			else
			{
				Sub_matrix(A, B, C, n, m);
			}
			break;

		case 5:
			if (m != z)
			{
				cout << Error_mult(m, z);
			}
			else
			{
				Mal_matrix(A, B, C, n, m);
			}
			break;

		case 6: Trans_matrix(A, C, n, m);

			break;

		case 7: Trans_matrix(B, C, z, x);

			break;

		case 8:
			if (m != z || z != x)
			{
				cout << Error_div(m, z);
			}
			else
			{
				Div_matrix(A, B, C, n, m, z);
			}
			break;

		case 9:
			break;
		}

	} while (choice != 9);
	return 0;
}
