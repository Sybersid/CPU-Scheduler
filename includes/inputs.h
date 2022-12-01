#ifndef INPUTS
#define INPUTS

typedef unsigned int u_int;
char* file_name;
int time_quantum;

enum policy_type {
    FCFS,
    SRTF,
    RR,
    NONE
};

#endif 