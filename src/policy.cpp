#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include "../includes/task.h"

void fcfs_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array) {
    u_int clock = 0;
    std::queue<task> ready_queue;
    int i = 0;

    while (i<count) {
        int k;
        for (k=0; k<task_list.size(); k++) {
                if (task_list[i].arrival_time <= clock && task_list[i].remaining_time == -1) {
                        task_list[i].remaining_time = task_list[i].burst_time;
                        task_list[i].start_time = clock;
                        ready_queue.push(task_list[i]);
                    } else break;
                }
                if (ready_queue.front().remaining_time == 0) {
                    ready_queue.front().finish_time = clock;
                    finish_array.push_back(ready_queue.front());
                    printf("<time %u> Process %u is finished...\n", clock, ready_queue.front().pid);
                    i++;
                    ready_queue.pop();
                    continue;
                } else if (ready_queue.front().remaining_time > 0) {
                    printf("<time %u> Process %u is running.\n", clock, ready_queue.front().pid);
                    ready_queue.front().remaining_time--;
                }
                clock++;
            }
        } 

// void srtf_policy(task task_array[], u_int count, task finish_array[]) {


// }

// void rr_policy(task task_array[], u_int count, u_int time_quantum, task finish_array[]) {
    

// }