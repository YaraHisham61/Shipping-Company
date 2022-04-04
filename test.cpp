#include "Company.h"
#include"LinkedPriorityQueue.h"
#include "Cargo.h"


int main() 
{
	int x=0;
	LinkedPriorityQueue<int>L;
	L.Enqueue(x, 3);
	x = 1;
	L.Enqueue(x, 5);
	x = 2;
	L.Enqueue(x, 1);

	while (!L.IsEmpty())
	{
		int y;
		cout << " " << L.Peek(y);
		L.Dequeue(y);
	}
	return 0;
}