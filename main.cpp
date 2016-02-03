// Example program
#include <iostream>
#include <string>
using namespace std;

void maxIndex(int *A, int *B, int numOfElements)
{
    int maxA = A[0];
    int *Amax = new int[numOfElements];

    Amax[0] = 0;
    for(int i = 1; i < numOfElements; i++)
    {
         if(A[i] > maxA)
        {
           Amax[i] = i;
           maxA = A[i];
        }
        else
            Amax[i] = Amax[i - 1];

    }

    int maxSum = B[0] + A[0];
    int maxJ = 0;
    for(int i = 0; i < numOfElements; i++)
    {
        if(B[i] + A[Amax[i]] > maxSum)
        {
            maxSum = B[i] + A[Amax[i]];
            maxJ = i;
        }

    }


    cout << Amax[maxJ] << " " << maxJ;
    delete Amax;
}

int main()
{
    int numOfElements;
    cin >> numOfElements;
    int *A = new int[numOfElements];
    int *B = new int[numOfElements];

    for(int i = 0; i < numOfElements; i++)
    {
      cin >> A[i];
    }
    for(int i = 0; i < numOfElements; i++)
    {
      cin >> B[i];
    }

    maxIndex(A, B, numOfElements);

    delete A, B;

}
