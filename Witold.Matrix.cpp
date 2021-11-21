#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class witold
{
private:
	int value;
public:
	int** array;
	int rows, cols;
public:
	void matrix();

	witold(int rows, int cols);

	~witold();

	void getelements();

	void multiplier(int value, const witold& first);

	void display();

	int operator () (int rows, int cols);

	witold operator = (const witold& second)
	{
		for (int row = 0; row < this->rows; row++)
		{
			for (int col = 0; col < this->cols; col++)
				this->array[row][col] = second.array[row][col];
		}
		return *this;
	}
	witold operator *= (const int value)
	{
		for (int row = 0; row < this->rows; row++)
		{
			for (int col = 0; col < this->cols; col++)
			{
				this->array[row][col] *= value;
				std::cout << this->array[row][col] << "   ";
			}
			std::cout << endl;
			std::cout << endl;
		}
		return *this;
	}
	witold operator * (const witold& second)
	{
		for (int row = 0; row < this->rows; row++) {
			for (int col = 0; col < this->cols; col++) {
				for (int d = 0; d < this->cols; d++) {
					this->value += this->array[row][d] * second.array[d][col];
				}
				std::cout << this->value << "   ";
				this->value = 0;
			}
			std::cout << endl;
		}
		return *this;
	}
	witold operator -= (int rows)
	{
		for (int row = 0; row < this->rows; row++)
		{
			for (int col = 0; col < this->cols; col++)
			{
				this->array[row][col] -= rows;
				std::cout << array[row][col] << "   ";
			}
			std::cout << endl;
			std::cout << endl;
		}
		return *this;
	}
	witold operator == (const witold& second)
	{
		for (int row = 0; row < this->rows; row++)
		{
			for (int col = 0; col < this->cols; col++)
			{
				if (this->array[row][col] == second.array[row][col])
					std::cout << "Matrix [" << row + 1 << "][" << col + 1 << "] are simmilar" << endl;
				else std::cout << "Matrix [" << row + 1 << "][" << col + 1 << "] are NOT simmilar" << endl;
			}
		}
		return *this;
	}
};

void witold::matrix()
{
	array = new int* [this->rows];
	for (int rows = 0; rows < this->rows; rows++)
		array[rows] = new int[this->cols];
}
witold::witold(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix();
}
witold::~witold()
{
	for (int rows = 0; rows < this->rows; rows++)
		delete[] array[rows];
	delete[] array;
}
void witold::getelements()
{
	for (int row = 0; row < this->rows; row++)
	{
		for (int col = 0; col < this->cols; col++)
		{
			this->array[row][col] = rand() % 10;
			if (this->array[row][col] == 0)
				this->array[row][col] = rand() % 10;
		}
	}
}
int witold::operator () (int rows, int cols)
{
	return this->array[rows - 1][cols - 1];
}
void witold::multiplier(int value, const witold& first)
{
	this->value = value;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			this->value *= first.array[row][col];
		}
	}
	std::cout << "Value = " << this->value << endl;
}
void witold::display()
{
	for (int row = 0; row < this->rows; row++)
	{
		for (int col = 0; col < this->cols; col++)
		{
			std::cout << this->array[row][col] << "      ";
		}
		std::cout << endl;
		std::cout << endl;
	}
}


void main()
{
	//Welcome
	std::cout << "Welcome" << endl;
	std::cout << "Enter size of matrix m X n" << endl;
	std::cout << "Here (rows): ";
	int rows, cols;
	cin >> rows;
	std::cout << "Here (columns): ";
	cin >> cols;
	std::cout << endl;
	srand(time(NULL));
	witold matrix1(rows, cols);
	matrix1.getelements();
	std::cout << "=======1=======" << endl;
	matrix1.display();
	Sleep(1000);
	srand(time(NULL));
	witold matrix2(rows, cols);
	matrix2.getelements();
	std::cout << "=======2=======" << endl;
	matrix2.display();
	std::cout << endl;
	//Functionality
	std::cout << "This program can:" << endl;
	std::cout << "1) Multiply matrix" << endl;
	std::cout << "2) Multiply matrix by number" << endl;
	std::cout << "3) Multiply number by matrix" << endl;
	std::cout << "4) Find an element by index" << endl;
	std::cout << "5) Subtract a number from matrit" << endl;
	std::cout << "6) Compare" << endl;
	//Choose action
	std::cout << "Choose your action by number (1-6): ";
	std::cout << endl;
	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 49:
			{
				matrix1* matrix2;
				break;
			}
			case 50:
			{
				int number;
				std::cout << "Enter a value: ";
				cin >> number;
				std::cout << "Choose matrix (1/2)" << endl;
				while (true)
				{
					if (_kbhit())
					{
						if (_getch() == 49)
							matrix1 *= number;
						else if (_getch() == 50)
							matrix2 *= number;
						else std::cout << "Wrong data" << endl;
					}
				}
					break;
			}
			case 51:
			{
				int number;
				std::cout << "Enter a value: ";
				cin >> number;
				std::cout << "Choose matrix (1/2): ";
				while (true)
				{
					if(_kbhit())
					{
						if (_getch() == 49)
							matrix1.multiplier(number, matrix1);
						else if (_getch() == 50)
							matrix2.multiplier(number, matrix2);
						else std::cout << "Not founded" << endl;
					}
				}
				break;
			}
			case 52:
			{
				int i, j;
				std::cout << "Enter index of row: ";
			retry1:
				cin >> i;
				if (i > rows && i < 0)
				{
					std::cout << "Wrong match, retry" << endl;
					goto retry1;
				}
				std::cout << "Enter index of column: ";
			retry2:
				cin >> j;
				if (j > cols && j < 0)
				{
					std::cout << "Wrong match, retry" << endl;
					goto retry2;
				}
			retry3:
				std::cout << "Choose a matrix(1/2)";
				std::cout << endl;
				while (true)
				{
					if (_kbhit())
					{
						if (_getch() == 49)
							std::cout << "Your element " << matrix1(i, j);
						else if (_getch() == 50)
							std::cout << "Your element " << matrix2(i, j);
						else goto retry3;
					}
				}
				break;
			}
			case 53:
			{
				int number;
				std::cout << "Enter a value which will be subtracted from matrix: ";
				cin >> number;
				std::cout << "Choose matrix (1/2): ";
				while (true)
				{
					if (_kbhit())
					{
						if (_getch() == 49)
							matrix1 -= number;
						else if (_getch() == 50)
							matrix2 -= number;
						else std::cout << "Not founded" << endl;
					}
				}
				break;
			}
			case 54:
			{
				std::cout << "Result: " << endl;
				matrix1 == matrix2;
				cout << endl;
				break;
			}
			}
		}
	}
	//Final
	std::cout << endl;
	std::cout << "Final!" << endl;
	system("pause");
}