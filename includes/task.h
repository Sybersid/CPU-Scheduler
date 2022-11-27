#ifndef TASK_LIST
#define TASK_LIST

typedef unsigned int u_int;
static const int MAX_TASK_NUM = 32;

struct task {
    u_int pid;
    u_int arrival_time;
    u_int burst_time;
    int start_time;
    int remaining_time;
    int finish_time;
    };

#endif 