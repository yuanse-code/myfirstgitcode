#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueTest()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	////QueuePop(&q);
	//////printf("%d\n", QueueBack(&q));

	//QueuePush(&q, 10);
	//QueuePush(&q, 20);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}

	QueueDestory(&q);
}
int main()
{
	QueueTest();
	return 0;
}