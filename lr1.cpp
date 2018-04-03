#include <iostream>
using std :: cout;
using std :: cin;
using std :: endl;
int f(int *array, int a, int b)
{
	if (a <= 5)
	{
		for (int i = 0; i < a; i++)
		{
			array[i] = i+1;
		}
		return a;
	}
	
	if (b <=4)
	{
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		array[4] = 5;
		array[5] = 0;
		array[6] = a;	
		return 7;
	} 
	if (b>=a-3)
	{
		array[0] = 1;
		array[1] = 0;
		array[2] = a-4;
		array[3] = a-3;
		array[4] = a-2;
		array[5] = a-1;
		array[6] = a;
		return 7;
	}
	if ((b>3)&&(b<a-2))
	{
		array[0] = 1;
		array[1] = 0;
		array[2] = b-2;
		array[3] = b-1;
		array[4] = b;
		array[5] = b+1;
		array[6] = b+2;
		array[7] = 0;
		array[8] = a;
		return 9;
	}
}
int main ()
{
	cout << "Enter the total number of pages ";
	int a, b;
	cin >> a;
	cout << "Enter the current page number ";
	cin >> b;
	
	int *array = new int[9];
	int n = f(array,a,b);
	
	for (int i =0; i < n; i++)
	{
		if (array[i] == 0)
		{
			cout << "... ";
		}
		else
		{
			if (array[i] == b)
			{
				cout << "[" << array[i] << "]" << " ";
			}
			else
			{
				cout << array[i] << " ";
			}
		}
	}
	return 0;
}
