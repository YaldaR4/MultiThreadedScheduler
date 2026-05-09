#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// total number of tasks
#define MAX_TASKS 5

// structure for each task
typedef struct {

    int id;
    int burst_time;
    int priority;

    int waiting_time;
    int turnaround_time;

} Task;

// array to store all tasks
Task tasks[MAX_TASKS];


// function for running each task using threads
void* executeTask(void* arg) {

    // convert the argument into Task type
    Task* task = (Task*) arg;

    // show task information
    printf("\n----------------------------------\n");
    printf("CPU is running Task %d\n", task->id);

    printf("Burst Time: %d seconds\n",
           task->burst_time);

    printf("Priority: %d\n",
           task->priority);

    // simulate CPU execution time
    sleep(task->burst_time);

    // task completed
    printf("Task %d completed\n",
           task->id);

    printf("----------------------------------\n");

    return NULL;
}


// FCFS scheduling calculation
void calculateFCFS() {

    int current_time = 0;

    float total_waiting = 0;
    float total_turnaround = 0;

    printf("\n========== FCFS Scheduling ==========\n");

    // calculate waiting and turnaround times
    for(int i = 0; i < MAX_TASKS; i++) {

        // waiting time is current CPU time
        tasks[i].waiting_time = current_time;

        // turnaround time formula
        tasks[i].turnaround_time =
            tasks[i].waiting_time + tasks[i].burst_time;

        // update current CPU time
        current_time += tasks[i].burst_time;

        // add totals for averages
        total_waiting += tasks[i].waiting_time;

        total_turnaround += tasks[i].turnaround_time;
    }

    // display results table
    printf("\nTask\tBurst\tPriority\tWaiting\tTurnaround\n");

    for(int i = 0; i < MAX_TASKS; i++) {

        printf("T%d\t%d\t%d\t\t%d\t%d\n",

               tasks[i].id,
               tasks[i].burst_time,
               tasks[i].priority,
               tasks[i].waiting_time,
               tasks[i].turnaround_time);
    }

    // print average calculations
    printf("\nAverage Waiting Time: %.2f\n",
           total_waiting / MAX_TASKS);

    printf("Average Turnaround Time: %.2f\n",
           total_turnaround / MAX_TASKS);
}


// main function
int main() {

    // thread array
    pthread_t threads[MAX_TASKS];

    printf("====================================\n");
    printf(" Multi-Threaded Task Scheduler\n");
    printf("====================================\n");

    // create sample tasks
    tasks[0] = (Task){1, 2, 3, 0, 0};
    tasks[1] = (Task){2, 4, 1, 0, 0};
    tasks[2] = (Task){3, 3, 2, 0, 0};
    tasks[3] = (Task){4, 1, 5, 0, 0};
    tasks[4] = (Task){5, 2, 4, 0, 0};

    printf("\nCreating Threads...\n");

    // run each task
    for(int i = 0; i < MAX_TASKS; i++) {

        pthread_create(&threads[i],
                       NULL,
                       executeTask,
                       &tasks[i]);

        pthread_join(threads[i], NULL);
    }

    // calculate FCFS results
    calculateFCFS();

    return 0;
}
