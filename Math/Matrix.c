#include <math.h>
#include <stdio.h>
#define MarNum 6
float cal_Det(const float array[6][6],int n);
float cal_Cof(const float array[MarNum][MarNum],int i,int n);
void FindCof(float arr[MarNum][MarNum], float arr2[MarNum][MarNum], int i, int j, int n);
void matrix_inver(float arr[MarNum][MarNum]);

float cal_Cof(const float array[MarNum][MarNum],int i,int n){

	int k = 0;
	int j = 0;
	float arr2[MarNum][MarNum] = { 0 };
	for (k = 0; k < n - 1; k++)//去除0行i列，剩下的组成新的矩阵
	{
		for (j = 0; j < n - 1; j++)
		{
			if (j < i)
			{
				arr2[k][j] = array[k + 1][j];
			}
			else
			{
				arr2[k][j] = array[k + 1][j + 1];
			}
		}
	}
	return cal_Det(arr2, n - 1);
}

float cal_Det(const float array[MarNum][MarNum],int n){
	float sum = 0;
	int i = 0;
	if (n == 1)//1阶行列式直接得出结果
	{
		sum = array[0][0];
	}
	else if (n == 2)
	{
		sum = array[0][0] * array[1][1] - array[0][1] * array[1][0];//杀戮法求解
	}
	else if (n == 3)
	{
		sum = array[0][0] * array[1][1] * array[2][2]
			+ array[0][1] * array[1][2] * array[2][0]
			+ array[1][0] * array[2][1] * array[0][2]
			- array[0][2] * array[1][1] * array[2][0]
			- array[0][1] * array[1][0] * array[2][2]
			- array[1][2] * array[2][1] * array[0][0];//划线法求解
	}
	else
	{
		for (i = 0; i < n; i++)//按第一行展开
		{
			if (array[0][i] != 0)//展开项不为0才计算
			{
				sum += ((int)pow(-1, i + 0)) * array[0][i] * (cal_Cof(array, i, n));//2阶以上继续递归		
			}
			else
				sum += 0;//展开项为0
		}
	}
	return sum;
}
void FindCof(float arr[MarNum][MarNum], float arr2[MarNum][MarNum], int i, int j, int n)
{
	int m = 0;
	int k = 0;
	for (m = 0; m < n - 1; m++)
	{
		for (k = 0; k < n - 1; k++)
		{
			if (k < j)
			{
				if (m < i)
				{
					arr2[m][k] = arr[m][k];
				}
				else
				{
					arr2[m][k] = arr[m + 1][k];
				}
			}
			else
			{
				if (m < i)
				{
					arr2[m][k] = arr[m][k + 1];
				}
				else
				{
					arr2[m][k] = arr[m + 1][k + 1];
				}
			}
		}
	}
}

void matrix_inver(float arr[MarNum][MarNum])
{
	int i, j, n=MarNum;
	float tmp[MarNum][MarNum] = { 0 };
	//保护arr，将arr指向内存的数据拷贝到tmp二维数组中
	for (i = 0; i < n; i++)
	{
		for(j=0;j<n;j++){
            tmp[i][j] = arr[i][j];
        }
	}
	float a = 1.0 / (cal_Det(tmp, n));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			float tmp2[MarNum][MarNum] = { 0 };
			FindCof(tmp, tmp2, j, i, n);//求转置后的伴随
			float b = pow(-1, i + j) * cal_Det(tmp2, n - 1);
			arr[i][j] = a * b;
		}
	}
}
int main(void){
    float array[6][6] = {
    {1,2,3,4,5,6},
    {6,1,2,3,4,5},
    {5,6,1,2,3,4},
    {4,5,6,1,2,3},
    {3,4,5,6,1,2},
    {2,3,4,5,6,1}
    };
    matrix_inver(array);
    for(int i=0;i<MarNum;i++){
        for(int j=0;j<MarNum;j++){
            printf("%.3f ",array[i][j]);
            if(j==5) printf("\n");
        }
    }
    
}