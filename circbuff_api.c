/************************************
* Circular Buffer API 
* Function List:
* q_full,q_empty,q_size,q_init,q_put,q_get
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG 1

#include "circbuff_api.h"

bool q_full(queue *myqueue)
{
    if((myqueue->head + 1) % myqueue->maxsize == myqueue->tail)
        return true;

    return false;
}

bool q_empty(queue *myqueue)
{
    if(myqueue->head == myqueue->tail)
        return true;
    return false;
}

int q_size(queue *myqueue)
{
    if(myqueue->head >= myqueue->tail)
         return myqueue->maxsize - myqueue->head + myqueue->tail;
    else
         return myqueue->tail - myqueue->head;
}


int q_init(queue *myqueue, int size)
{
    assert(myqueue);
    if(size == 0)
        return -1;
    char *buff = (char *) malloc(sizeof(char) * size);
    myqueue->buff = buff;
    myqueue->head = 0;
    myqueue->tail = 0;
    myqueue->maxsize = size;
    dbg_print("q_init : %s %s","","",myqueue);
    return 0;
}

int q_put(queue *myqueue, const char *data, int size)
{
    assert(myqueue);
    assert(data);

    if(!q_full(myqueue))
    {
        int currsize = q_size(myqueue);
        int wrsize = (currsize < size) ? currsize : size;
        if(myqueue->head +  wrsize < myqueue->maxsize) // no wrap around
        {
            memcpy(myqueue->buff + myqueue->head , data, wrsize);
        }
        else // wrap around the buffer
        {
            int chunk0 = myqueue->maxsize - myqueue->head;
            memcpy(myqueue->buff + myqueue->head , data, chunk0);
            memcpy(myqueue->buff, data + chunk0, wrsize - chunk0);
        }

        myqueue->head = (myqueue->head + wrsize) % myqueue->maxsize;

        dbg_print("q_put : %s, %d",data,size,myqueue);

        return wrsize;
    }

    return 0;

}

int q_get(queue *myqueue, char *data, int size)
{
    assert(myqueue);
    assert(data);

    if(!q_empty(myqueue))
    {
        int getsize = myqueue->maxsize - q_size(myqueue);
        int rdsize = (getsize < size) ? getsize : size;
        if(myqueue->tail + rdsize < myqueue->maxsize) //no wrap around
        {
            memcpy(data,myqueue->buff + myqueue->tail, rdsize);
        }
        else //wrap around
        {
            int chunk0 = myqueue->maxsize - myqueue->tail;
            memcpy(data,myqueue->buff + myqueue->tail, chunk0);
            memcpy(data+chunk0,myqueue->buff, rdsize-chunk0);
        }

        *(data + rdsize) = '\0';
        myqueue->tail = (myqueue->tail + rdsize) % myqueue->maxsize;
        dbg_print("q_get : %s, %d","", size, myqueue);
        return rdsize;
    }

    return 0;

}

