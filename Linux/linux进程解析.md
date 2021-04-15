# linux进程解析

### 1、创建进程

```c
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

void *func(void* arg)
{
    printf("func run..\n");
    return NULL:
}
int main()
{
    phread_t t1;
    int err = pthread_create(&t1,NULL,func,NULL);
    if(err != 0)
    {
        printf("thread_create Failed:%s\n",strerror(errno));
        // strerror(errno)打印错误
    }
    else{
        printf("thread_create success\n");
    }
    sleep(1);
    return EXIT_SUCCESS;
}
```

`int pthread_carete(pthread_t *thread,const pthread_attr_t *attr,void*(start_routine), void*arg);`

进程标识 + 进程的一些配置(NULL表示默认配置) + 函数的地址 + 调用第三个函数传递的参数

**调用成功返回0**

### 2、线程挂起

`pthread_join()`



线程执行`pthread_create报错提示`

`gcc -o app p_join.c -lpthread`解决报错函数不存在问题