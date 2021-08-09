#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


#include "circbuff_api.h"


int main(void) {

    queue myqueue;
    assert(q_init(&myqueue,10)==0);

    const char *data = "abcdefghjk";

    assert(q_put(&myqueue, data, 7) == 7); // abcdefg___

    char getbuff[10];
    assert(q_get(&myqueue, getbuff, 3 ) == 3); // ___defg___
    printf("getbuff = %s\n",getbuff);

    assert(q_put(&myqueue, data,5) == 5); // decdefgabc
    // full
    assert(q_full(&myqueue) == true);

    assert(q_get(&myqueue, getbuff, 9) == 9); // _e_______
    printf("getbuff = %s\n", getbuff);
    assert(q_empty(&myqueue) == true);


    return 0;
}
