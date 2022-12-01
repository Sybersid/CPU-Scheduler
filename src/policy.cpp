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
                } else if (ready_queue.front().remaining_time > 0) {
                    if (ready_queue.front().remaining_time == ready_queue.front().burst_time) {
                        ready_queue.front().start_time = clock;
                    }
                    printf("<time %u> Process %u is running.\n", clock, ready_queue.front().pid);
                    ready_queue.front().remaining_time--;
                } else {
                    wait_time++;
                    printf("<time %u> No process running...\n", clock);
                }
                clock++;
            }

            printf("<time %u> All processes finished...\n", clock);
            printf("========================================================================================\n");
        }

void srft_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array, u_int &wait_time) {
    u_int clock;
    int i = 0;
    int k;
    int x;
    int y;
    std::vector<task> ready_queue;

    while (i<count) {
        for (k=0; k<count; k++) {
                if (task_list[k].arrival_time <= clock && task_list[k].remaining_time == -1) {
                        task_list[k].remaining_time = task_list[k].burst_time;
                        ready_queue.push_back(task_list[k]);
                        ready_queue.shrink_to_fit();
                        } else continue;
                }

                task temp;
                for (x=0; x<ready_queue.size(); x++) {
                    for (y=0; y<ready_queue.size()-x-1; y++) {
                        if (ready_queue[y].remaining_time < ready_queue[y+1].remaining_time) {
                            temp = ready_queue[y+1];
                            ready_queue[y+1] = ready_queue[y];
                            ready_queue[y] = temp;
                        }
                    }
                }
                if (!ready_queue.empty()) {
                if (ready_queue.back().remaining_time == 0) {
                    ready_queue.back().finish_time = clock;
                    finish_array.push_back(ready_queue.back());
                    printf("<time %u> Process %u is finished...\n", clock, ready_queue.back().pid);
                    i++;
                    ready_queue.pop_back();
                    continue;
                } else if (ready_queue.back().remaining_time > 0) {
                    if (ready_queue.back().remaining_time == ready_queue.back().burst_time) {
                        ready_queue.back().start_time = clock;
                    }
                    printf("<time %u> Process %u is running.\n", clock, ready_queue.back().pid);
                    ready_queue.back().remaining_time--;
                } 
                } else {
                    wait_time++;
                    printf("<time %u> No process running...\n", clock);
                }
                clock++;
            }

            printf("<time %u> All processes finished...\n", clock);
            printf("========================================================================================\n");
        
    }

 void rr_policy(std::vector<task> &task_list, u_int &count, int &time_quantum, std::vector<task> &finish_array, u_int &wait_time) {
    u_int clock;
    std::queue<task> ready_queue;
    int i = 0;
    int k;
    int j = 0;

    while (i<count) {
        for (k=0; k<count; k++) {
                if (task_list[k].arrival_time <= clock && task_list[k].remaining_time == -1) {
                        task_list[k].remaining_time = task_list[k].burst_time;
                        ready_queue.push(task_list[k]);
                    } else continue;
                }
                if (!ready_queue.empty()) {
                    if (ready_queue.front().remaining_time == 0) {
                        ready_queue.front().finish_time = clock;
                        finish_array.push_back(ready_queue.front());
                        printf("<time %u> Process %u is finished...\n", clock, ready_queue.front().pid);
                        i++;
                        ready_queue.pop();
                        j=0;
                        continue;
                    } else if (ready_queue.front().remaining_time > 0) {
                        if (ready_queue.front().remaining_time == ready_queue.front().burst_time) {
                            ready_queue.front().start_time = clock;
                        }
                        if (j<time_quantum) {
                            printf("<time %u> Process %u is running.\n", clock, ready_queue.front().pid);
                            ready_queue.front().remaining_time--;
                            j++;
                            clock++;
                        } else {
                            j=0;
                            ready_queue.push(ready_queue.front());
                            ready_queue.pop();
                        }
                    } 
                } else {
                    wait_time++;
                    printf("<time %u> No process running...\n", clock);
                    clock++;
                }
            }

            printf("<time %u> All processes finished...\n", clock);
            printf("========================================================================================\n");
    }