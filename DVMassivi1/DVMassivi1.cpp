// DVMassivi1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
using namespace std;


void DynamicArray(int**& originalArr, int& sizeRow, int& sizeCol) // Выделение памяти под массив
{
    originalArr = new int* [sizeRow];
    for (int i = 0; i < sizeRow; i++) {
        originalArr[i] = new int[sizeCol];
    }
}
void FillingArray(int**& originalArr, int& sizeRow, int& sizeCol) // заполнение массива
{
    for (int i = 0; i < sizeRow; i++)
    {
        for (int j = 0; j < sizeCol; j++)
        {
            originalArr[i][j] = 1 + rand() % 9;
        }
    }
}

void PrintArray(int**& originalArr, int& sizeRow, int& sizeCol) // вывод массива на экран
{
    for (int i = 0; i < sizeRow; i++)
    {
        for (int j = 0; j < sizeCol; j++)
        {
            cout << originalArr[i][j]<< " ";
        }
        cout << endl;
    }
}

void AddColumn(int**& originalArr, int**& arrAddColumn, int& sizeRow, int& sizeColAdd, int& position) // добавление столбца в массив
{
    if (position - 1 != 0)
    {
        for (int i = 0; i < sizeRow; i++)
        {
            for (int j = 0; j < position - 1; j++)
            {
                arrAddColumn[i][j] = originalArr[i][j];
            }
        }
    }

    for (int i = 0; i < sizeRow; i++)
    {
        for (int j = position - 1; j < sizeColAdd; j++)
        {
            if (j == position - 1)
            {
                arrAddColumn[i][j] = 1 +  rand() % 9;
            }
            else
            {
                arrAddColumn[i][j] = originalArr[i][j - 1];
            }
        }
    }
}


int main()
{
    setlocale(0, "");
    srand(time(0));
    int sizeRow = 5;
    int sizeCol = 5;
    int sizeColAdd = sizeCol + 1;
    int positionInsert = 0;
    int** originalArr;
    int** arrAddColumn;

    DynamicArray(originalArr, sizeRow, sizeCol);
    FillingArray(originalArr, sizeRow, sizeCol);

    cout << endl << endl;
    cout << "Изначальный массив: " << endl << endl;
    PrintArray(originalArr, sizeRow, sizeCol);
    DynamicArray(arrAddColumn, sizeRow, sizeColAdd);
    cout << "Введите позицию для вставки столбца: "; 
    cin >> positionInsert; cout << endl;
   AddColumn(originalArr, arrAddColumn, sizeRow, sizeColAdd, positionInsert);
   cout << "Массив с добавленым столбцом в указанную позицию: " << endl << endl;
   PrintArray(arrAddColumn, sizeRow, sizeColAdd);

   return 0;
}