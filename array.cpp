#include <iostream>
using namespace std;

int main()
{
    int sparseMatrix[4][5] =
    {
        {0 , 1 , 1 , 0 , 0 },
        {1 , 0 , 1 , 1 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 1 , 1 , 0 , 0 }
    };

    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compactMatrix[3][size];

    // Making of new matrix
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
  
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
        cout <<" "<< compactMatrix[i][j];
        cout <<"\n";
    }
return 0;
}