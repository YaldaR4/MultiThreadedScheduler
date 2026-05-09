Spring 2026: CSC-465/665
Operating Systems

Project Proposal:
Multi-Threaded Task Scheduler Simulation

Yalda Rawan

Dr. Nathalie Japkowicz

American University

------------------------------------------------------------

Project Overview

This project simulates how an operating system manages and schedules multiple CPU tasks using different scheduling algorithms. The project was developed using the C programming language and POSIX threads (pthreads) to demonstrate concepts related to multitasking, process scheduling, concurrency, and CPU management.

The scheduler creates multiple tasks, where each task contains:
- Task ID
- Burst Time
- Priority
- Waiting Time
- Turnaround Time

Threads are used to simulate task execution and CPU behavior. The project compares how different scheduling algorithms affect execution order, waiting time, turnaround time, and CPU fairness.

In addition to the C implementation, an interactive visualization was created using HTML, CSS, and JavaScript to visually demonstrate the scheduling process, CPU execution, and Gantt chart behavior.

------------------------------------------------------------

Main Features

- Multi-threaded task simulation using POSIX threads
- FCFS (First Come First Serve) Scheduling
- Round Robin Scheduling
- Priority Scheduling
- Waiting time calculation
- Turnaround time calculation
- CPU execution simulation
- Interactive visualization webpage
- Gantt chart visualization
- Scheduling comparison table
- Animated task execution

------------------------------------------------------------

Technologies Used

Programming Languages:
- C
- HTML
- CSS
- JavaScript

Libraries and Tools:
- POSIX Threads (pthread)
- GCC Compiler
- Linux Mint 22
- Oracle VirtualBox

------------------------------------------------------------

Project Files

scheduler.c
Main C program containing:
- POSIX thread implementation
- FCFS scheduling
- Round Robin scheduling
- Priority scheduling
- Waiting and turnaround time calculations

fcfs_version.c
Backup version for FCFS implementation.

round_robin_version.c
Backup version for Round Robin implementation.

index.html
Main webpage for the scheduler visualization.

style.css
Design and styling for the visualization webpage.

script.js
Controls animations, CPU execution, Gantt chart updates, and scheduling visualization.

README.txt
Project documentation and instructions.

------------------------------------------------------------

How to Compile the C Program

Use the following command:

gcc scheduler.c -o scheduler -pthread

------------------------------------------------------------

How to Run the C Program

Run the executable using:

./scheduler

------------------------------------------------------------

How to Open the Visualization

Open the interactive scheduler visualization using:

xdg-open index.html

------------------------------------------------------------

Scheduling Algorithms Explanation

1. FCFS (First Come First Serve)

FCFS executes tasks in the order they arrive in the ready queue. The first task that arrives gets CPU access first. This method is simple and easy to implement, but long tasks may increase waiting time for smaller tasks.

Example:
T1 → T2 → T3 → T4 → T5

------------------------------------------------------------

2. Round Robin Scheduling

Round Robin gives each task a fixed CPU time slice called a time quantum. If a task is not completed during its time slice, it returns to the ready queue for another turn. This method improves fairness and multitasking.

Example:
T1 → T2 → T3 → T4 → T5 → T1 → T2 ...

------------------------------------------------------------

3. Priority Scheduling

Priority Scheduling executes tasks based on their priority values. In this project, smaller priority numbers represent higher priority tasks.

Example:
Priority 1 runs before Priority 5.

------------------------------------------------------------

Research Connection

This project is connected to important Operating Systems concepts that I learned while studying CPU scheduling, multitasking, and multithreading. During this project, I researched how operating systems manage multiple tasks at the same time and how the CPU decides which task should run first.

I learned that different scheduling algorithms can change the execution order, waiting time, fairness, and overall system performance. For example, FCFS scheduling runs tasks based on arrival order, Round Robin shares CPU time more fairly between tasks using a time quantum, and Priority Scheduling allows more important tasks to run first.

While building this project, I also learned how POSIX threads (pthreads) are used in the C programming language to simulate concurrent task execution. Using threads helped me better understand how operating systems perform multitasking and manage multiple processes simultaneously.

The interactive visualization helped me connect the theory with practical implementation by showing:
- Ready Queue behavior
- CPU execution order
- Gantt Chart scheduling
- Task switching in Round Robin
- Priority-based execution

Creating both the C simulation and the visual web model improved my understanding of:
- CPU scheduling algorithms
- Waiting time and turnaround time calculations
- Multithreading
- Concurrency
- Operating Systems process management

This project helped me see how Operating Systems scheduling works in a more practical and visual way instead of only learning the theory from lectures and textbooks.

------------------------------------------------------------

Learning Outcomes

This project helped improve understanding of:
- CPU scheduling algorithms
- Operating Systems concepts
- Multithreading
- Concurrency
- Process management
- CPU fairness
- Waiting time calculations
- Turnaround time calculations
- Gantt chart visualization
- Interactive scheduling simulation

------------------------------------------------------------

Conclusion

This project successfully demonstrates how an operating system scheduler manages multiple tasks using different scheduling algorithms. By comparing FCFS, Round Robin, and Priority Scheduling, the project shows how scheduling decisions affect CPU execution order, fairness, and overall performance.

The interactive visualization provides a clearer understanding of task scheduling behavior and Gantt chart execution, making Operating Systems concepts easier to understand in a practical and visual way.

---------------------------------------------------------

References

Silberschatz, A., Galvin, P. B., & Gagne, G.
Operating System Concepts.
Wiley Publishing.

POSIX Threads (pthreads) Documentation for C Programming.

HTML, CSS, and JavaScript Web Development Documentation.


