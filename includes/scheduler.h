#ifndef SCHEDULER
#define SCHEDULER

void task_loader(char* file_name, std::array<task,MAX_TASK_NUM> &task_array, u_int &count);

void fcfs_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array, u_int &wait_time);

void srft_policy(std::vector<task> &task_list, u_int &count, std::vector<task> &finish_array, u_int &wait_time);

void rr_policy(std::vector<task> &task_list, u_int &count, int &time_quantum, std::vector<task> &finish_array, u_int &wait_time);

void stats(u_int &count, std::vector<task> &finish_array, u_int &wait_time);

#endif 