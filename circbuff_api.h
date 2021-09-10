/************************************
* Circular Buffer API 
* Function List:
* q_full,q_empty,q_size,q_init,q_put,q_get
**************************************/

#ifndef CIRCBUFF_API_H
#define CIRCBUFF_API_H

#ifndef DEBUG
#define DEBUG 0
#endif

#define dbg_print(text,arg1,arg2,myqueue) ({ \
	if(DEBUG) \
	{ \
		printf("DEBUG :"); \
		printf(#text,arg1,arg2); \
		printf("\n"); \
		printf("buffer = %s\n",myqueue->buff); \
		printf("head = %d, tail = %d\n", myqueue->head, myqueue->tail); \
	} \
})


typedef struct queue
{
    char *buff;
    int  maxsize;
    int head;
    int tail;
} queue;

int q_init(queue *myqueue, int size);
int q_put(queue *myqueue, const char *data, int size);
int q_get(queue *myqueue, char *data, int size);
int q_free(queue *myqueue);
bool q_full(queue *myqueue);
bool q_empty(queue *myqueue);
int q_size(queue *myqueue);


#endif
