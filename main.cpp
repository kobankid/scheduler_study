#include <iostream>
#include <pthread.h>
#include <cstdio>
#include "vsim/vsim_main.hpp"

#define NUM_THREAD (4)

void *thread_func(void *param)
{
    printf("thread_func %d\n", *(int *)param);
    vsim_main();

    return NULL;
}

int main(int argc, char *argv[], char *envp[])
{
    std::cout << "Hello world!" << std::endl;

    // std::cout << "Please press any key" << std::endl;
    // int a;
    // std::cin >> a;

    pthread_t thread[NUM_THREAD];
    int param[NUM_THREAD];
    int ret = 0;

    for (int i = 0; i < NUM_THREAD; i++) {
        param[i] = i;
        ret = pthread_create(&(thread[i]), NULL, thread_func, (void *)&param[i]);
        if (ret != 0) {
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREAD; i++) {
        if (thread[i] != (pthread_t)NULL) {
            ret = pthread_join(thread[i], NULL);
            if (ret != 0) {
                std::cout << "Error: Failed to wait for the thread termination." << std::endl;
                exit(1);
            }
            thread[i] = (pthread_t)NULL;
        }
    }

    std::cout << "done" << std::endl;
    
    if (ret != 0) {
        exit(1);
    }

    return 0;
}
