#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include "../includes/task.h"

void fcfs_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array, u_int &wait_time) {
    u_int clock;
    std::queue<task> ready_queue;
    int i = 0;
    int k;

    while (i<count) {
        for (k=0; k<count; k++) {
                if (task_list[k].arrival_time <= clock && task_list[k].remaining_time == -1) {
                        task_list[k].remaining_time = task_list[k].burst_time;
                        ready_queue.push(task_list[k]);
                    } else continue;
                }
                if (ready_queue.front().remaining_time == 0 && !ready_queue.empty()) {
                    ready_queue.front().finish_time = clock;
                    finish_array.push_back(ready_queue.front());
                    printf("<time %u> Process %u is finished...\n", clock, ready_queue.front().pid);
                    i++;
                    ready_queue.pop();
                    continue;
                } else if (task_list[i].arrival_time > clock) {
                    wait_time++;
                    printf("<time %u> No process running.\n", clock);
                } else if (ready_queue.front().remaining_time > 0) {
                    if (ready_queue.front().remaining_time == ready_queue.front().burst_time) {
                        ready_queue.front().start_time = clock;
                    }
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