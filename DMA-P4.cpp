#include <iostream>
using namespace std;

int** twoD()
{
	int *r1 = new int[3]{1,2,3};
    int *r2 = new int[4]{4,5,6,7};

    int **pData = new int *[2];  //poiter of pointer, 
    pData[0]=r1;                 //pointing to 1D array r1
    pData[1]=r2;                 //pointing to 1D array r2
    return pData;
}

int main()
{
   int ** pData=twoD();
    cout<<pData[1][3];
}