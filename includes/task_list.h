#ifndef TASK_LIST
#define TASK_LIST

typedef unsigned int u_int;
struct task {
    u_int pid;
    u_int arrival_time;
    u_int burst_time;
    };

#endif 