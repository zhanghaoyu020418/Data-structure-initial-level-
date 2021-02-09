#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueDestroy(&q);
	while (!QueueEmpty(&q))
	{
		printf("%d %d ", QueueFront(&q), QueueBack(&q));
		QueuePop(&q);
	}
	puts(" ");


}

int main()
{
	TestQueue();
	return 0;
}

