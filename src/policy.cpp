#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include "../includes/task.h"

void fcfs_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array) {
    u_int clock = 0;
    int i = 0;

    while(i<count) {
        if (task_list[i].remaining_time == 0) {
            task_list[i].finish_time = clock;
            finish_array.push_back(task_list[i]);
            printf("<time %u> Process %u is finished...\n", clock, task_list[i].pid);
            i++;
        } else if (task_list[i].arrival_time <= clock) {
            if (task_list[i].remaining_time == -1) {
                task_list[i].remaining_time = task_list[i].burst_time;
                task_list[i].start_time = clock;
                }
            printf("<time %u> Process %u is running.\n", clock, task_list[i].pid);
            task_list[i].remaining_time--;
            }
            clock++;
        }

}

// void srtf_policy(task task_array[], u_int count, task finish_array[]) {


// }

// void rr_policy(task task_array[], u_int count, u_int time_quantum, task finish_array[]) {
    

// }