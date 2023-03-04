// DVMassivi3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
            cout << originalArr[i][j] << " ";
        }
        cout << endl;
    }
}

void ArrayShifts(int**& originalArr, int& sizeRow, int& sizeCol, int side, int shift)
{
    int temp;

    if (side == 1) // сдвиг влево
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < sizeRow; j++)
            {
                temp = originalArr[j][0];

                for (int g = 0; g < sizeCol - 1; g++)
                {
                    originalArr[j][g] = originalArr[j][g + 1];
                }

                originalArr[j][sizeCol - 1] = temp;
            }
        }
    }
    else if (side == 2) // сдвиг вправо
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < sizeRow; j++)
            {
                temp = originalArr[j][sizeCol - 1];

                for (int g = sizeCol - 1; g > 0; g--)
                {
                    originalArr[j][g] = originalArr[j][g - 1];
                }

                originalArr[j][0] = temp;
            }
        }
    }
    else if (side == 3) // сдвиг вверх
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < sizeCol; j++)
            {
                temp = originalArr[0][j];

                for (int g = 0; g < sizeRow - 1; g++)
                {
                    originalArr[g][j] = originalArr[g + 1][j];
                }

                originalArr[sizeRow - 1][j] = temp;
            }
        }
    }
    else if (side == 4) // сдвиг вниз
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < sizeCol; j++)
            {
                temp = originalArr[sizeRow - 1][j];

                for (int g = sizeRow - 1; g > 0; g--)
                {
                    originalArr[g][j] = originalArr[g - 1][j];
                }

                originalArr[0][j] = temp;
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
    int** originalArr;
    int shift, side;

    DynamicArray(originalArr, sizeRow, sizeCol);
    FillingArray(originalArr, sizeRow, sizeCol);

    cout << endl << endl;
    cout << "Изначальный массив: " << endl << endl;
    PrintArray(originalArr, sizeRow, sizeCol);
    
      cout << "\tСдвиг в массиве можно произвести:\n"
      << "\t\t1) Влево;\n"
      << "\t\t2) Вправо;\n"
      << "\t\t3) Вверх;\n"
      << "\t\t4) Вниз;\n"
      << endl << endl;
  cout << "Введите сторону сдвига: "; 
  cin >> side; 
  cout << endl;
  cout << "Введите количество сдвигов: ";
  cin >> shift;
  cout << endl; 
  ArrayShifts(originalArr, sizeRow, sizeCol, side, shift);
  cout << "Массив-результат после сдвигов" << endl;
  PrintArray(originalArr, sizeRow, sizeCol);
 
    return 0;
}