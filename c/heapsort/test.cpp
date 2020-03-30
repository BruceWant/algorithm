/*
构造一个NUM个数最大堆；
*/
#include<iostream>
#include<ctime>
using namespace std;
 
const int NUM = 10;
 
void print(int p[] , int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "heap[" << i << "] = " << p[i] << endl;
	}
}
 
int left(int heap[] , int i)
{
	return 2 * i;
}
 
int right(int heap[] , int i)
{
	return 2 * i + 1;
}

void max_heapify(int heap[], int location)
{
	int largest = 0, l, r, temp;
	l = left(heap, location);
	r = right(heap, location);

	if (l <= NUM && heap[l] > heap[location])
	{
		largest = l;
	}
	else
		largest = location;
	if (r <= NUM && heap[r] > heap[largest])
	{
		largest = r;
	}
	if (location != largest)
	{
		temp = heap[location];
		heap[location] = heap[largest];
		heap[largest] = temp;
		max_heapify(heap, largest);
	}
}

void bulid_max_heap(int heap[])
{
	//叶子节点不用max_heapify，所以是节点数的一半
	for (int i = NUM / 2; i >= 1; i--)
	{
		max_heapify(heap, i);
	}
}

int main()
{
	int heap[NUM + 1] = {0};
	srand(time(NULL));
	for (int i = 1; i <= NUM; i++)
	{
		heap[i] = rand() % 100;
	}
	print(heap, NUM);

	bulid_max_heap(heap);
	cout << "-------------" << endl;
	print(heap, NUM);
	return 0;
}
