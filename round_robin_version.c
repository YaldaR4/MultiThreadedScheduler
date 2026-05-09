#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TASKS 5
#define TIME_QUANTUM 2

// structure for each task
typedef struct {

    int id;
    int burst_time;
    int remaining_time;
    int priority;

    int waiting_time;
    int turnaround_time;

} Task;


// task array
Task tasks[MAX_TASKS];


// function for thread execution
void* executeTask(void* arg) {

    Task* task = (Task*) arg;

    printf("\n----------------------------------\n");

    printf("CPU is running Task %d\n",
           task->id);

    printf("Burst Time: %d seconds\n",
           task->burst_time);

    printf("Priority: %d\n",
           task->priority);

    sleep(1);

    printf("Task %d completed\n",
           task->id);

    printf("----------------------------------\n");

    return NULL;
}



// FCFS scheduling function
void calculateFCFS() {

    int current_time = 0;

    float total_waiting = 0;
    float total_turnaround = 0;

    printf("\n========== FCFS Scheduling ==========\n");

    for(int i = 0; i < MAX_TASKS; i++) {

        tasks[i].waiting_time = current_time;

        tasks[i].turnaround_time =
            tasks[i].waiting_time + tasks[i].burst_time;

        current_time += tasks[i].burst_time;

        total_waiting += tasks[i].waiting_time;

        total_turnaround += tasks[i].turnaround_time;
    }

    printf("\nTask\tBurst\tWaiting\tTurnaround\n");

    for(int i = 0; i < MAX_TASKS; i++) {

        printf("T%d\t%d\t%d\t%d\n",

               tasks[i].id,
               tasks[i].burst_time,
               tasks[i].waiting_time,
               tasks[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n",
           total_waiting / MAX_TASKS);

    printf("Average Turnaround Time: %.2f\n",
           total_turnaround / MAX_TASKS);
}



// Round Robin scheduling function
void roundRobin() {

    int completed = 0;
    int current_time = 0;

    printf("\n========== Round Robin Scheduling ==========\n");

    // copy burst time into remaining time
    for(int i = 0; i < MAX_TASKS; i++) {

        tasks[i].remaining_time =
            tasks[i].burst_time;
    }

    // continue until all tasks finish
    while(completed < MAX_TASKS) {

        for(int i = 0; i < MAX_TASKS; i++) {

            // skip completed tasks
            if(tasks[i].remaining_time <= 0) {
                continue;
            }

            printf("\nRunning Task %d\n",
                   tasks[i].id);

            // if remaining time is bigger than quantum
            if(tasks[i].remaining_time > TIME_QUANTUM) {

                printf("Task %d uses %d seconds\n",
                       tasks[i].id,
                       TIME_QUANTUM);

                current_time += TIME_QUANTUM;

                tasks[i].remaining_time -= TIME_QUANTUM;
            }

            // task finishes
            else {

                printf("Task %d finishes execution\n",
                       tasks[i].id);

                current_time += tasks[i].remaining_time;

                tasks[i].waiting_time =
                    current_time - tasks[i].burst_time;

                tasks[i].turnaround_time =
                    current_time;

                tasks[i].remaining_time = 0;

                completed++;
            }

            sleep(1);
        }
    }

    // print results
    printf("\nTask\tBurst\tWaiting\tTurnaround\n");

    for(int i = 0; i < MAX_TASKS; i++) {

        printf("T%d\t%d\t%d\t%d\n",

               tasks[i].id,
               tasks[i].burst_time,
               tasks[i].waiting_time,
               tasks[i].turnaround_time);
    }
}



// main function
int main() {

    pthread_t threads[MAX_TASKS];

    printf("====================================\n");
    printf(" Multi-Threaded Task Scheduler\n");
    printf("====================================\n");

    // sample tasks
    tasks[0] = (Task){1, 5, 5, 3, 0, 0};
    tasks[1] = (Task){2, 4, 4, 1, 0, 0};
    tasks[2] = (Task){3, 3, 3, 2, 0, 0};
    tasks[3] = (Task){4, 2, 2, 5, 0, 0};
    tasks[4] = (Task){5, 6, 6, 4, 0, 0};

    printf("\nCreating Threads...\n");

    // run thread simulation
    for(int i = 0; i < MAX_TASKS; i++) {

        pthread_create(&threads[i],
                       NULL,
                       executeTask,
                       &tasks[i]);

        pthread_join(threads[i], NULL);
    }

    // run FCFS
    calculateFCFS();

    // run Round Robin
    roundRobin();

    return 0;
}
