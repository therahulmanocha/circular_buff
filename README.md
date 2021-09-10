# Circular Buffer
Implemenation of Circular Buffer for Storing Character Strings.
Language : C

Circular Buffer is an easy to manage data structure that provides access to data in constant time.

## Usage

```C

    queue myqueue;
    q_init(&myqueue,10);
    const char *data = "abcdefghjk";
    q_put(&myqueue, data, 7)

    char getbuff[10];
    q_get(&myqueue, getbuff, 3 )
    
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
