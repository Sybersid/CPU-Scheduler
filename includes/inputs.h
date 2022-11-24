#ifndef INPUTS
#define INPUTS

typedef unsigned int u_int;
char* file_name;
u_int time_quantum;

enum policy_type {
    FCFS,
    SRTF,
    RR,
    NONE
};

#endif 