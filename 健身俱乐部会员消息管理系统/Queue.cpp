#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* ps)
{
    assert(ps);
    /*ps->size = 0;
    ps->array = NULL;
    ps->capicity = 0;*/
    ps->array = (QueueDateType*)malloc(sizeof(QueueDateType) * 4);
    if (ps->array == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(-1);
    }
    ps->size = 0;
    ps->capicity = 4;
}
static void IsAddCapicity(Queue* ps)
{
    assert(ps);
    if (ps->size >= ps->capicity)
    {
        QueueDateType* ptr;
        ps->capicity *= 2;
        ptr = (QueueDateType*)
            realloc(ps->array, sizeof(QueueDateType) * (ps->capicity));
        if (ps->array == NULL)
        {
            printf("%s\n", strerror(errno));
            exit(-1);
        }
        else
        {
            ps->array = ptr;
        }
    }
}
void QueuePushBack(Queue* ps, QueueDateType x)
{
    assert(ps);
    //如果满了需要增容
    IsAddCapicity(ps);
    ps->array[ps->size] = x;
    ps->size++;
}

void QueuePopFront(Queue* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->array[start] = ps->array[start + 1];
		start++;
	}
	ps->size--;
}

void QueueDestory(Queue* ps)
{
    if (NULL == ps)
        assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capicity = 0;
}