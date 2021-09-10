# Circular Buffer
Implemenation of Circular Buffer for Storing Character Strings.
Language : C

Circular Buffer is an easy to manage data structure that provides access to data in constant time.

![Alt Text](https://github.com/therahulmanocha/circular_buff/blob/main/640px-Circular_Buffer_Animation.gif)
## Usage

```C
 queue myqueue;
 q_init(&myqueue,10); // Initialize Queue with Buffer size 10
 const char *data = "abcdefghjk";
 q_put(&myqueue, data, 7); // Insert 7 characters in Queue

 char getbuff[10];
 q_get(&myqueue, getbuff, 3 ); // Pop 3 characters from Queue
    
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
