#include <iostream>
#include <string>
#include <thread>
#define BUFF 10

int S = 0;

void sum(int* arr, int a)
{
	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		sum += arr[i];
	}
	std::cout << "sum = " << sum << std::endl;
	S += sum;
	std::cout << "S = " << S << std::endl;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int N = 12;
	int M = 4;
	int a = N / M;
	int b = a;
	while (b <= N)
	{
		int* arrs = new int[BUFF];
		int i = b - 1;
		//std::cout << i << " " << b << std::endl;
		for (int j = 0; j < a; j++)
		{
			arrs[j] = arr[i];
			i--;
		}
		std::thread t(sum, arrs, a);
		t.join();
		b += a;
		delete[] arrs;
	}
	std::cout << "Sum = " << S << std::endl;
	return 0;
}