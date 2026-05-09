const cpu = document.getElementById("cpu");

const gantt = document.getElementById("gantt");


// FCFS visualization
function runFCFS() {

    gantt.innerHTML = "";

    const tasks = ["T1", "T2", "T3", "T4", "T5"];

    runTasks(tasks);
}


// Round Robin visualization
function runRoundRobin() {

    gantt.innerHTML = "";

    const tasks = [
        "T1", "T2", "T3", "T4", "T5",
        "T1", "T2", "T3", "T5",
        "T1", "T5"
    ];

    runTasks(tasks);
}


// Priority visualization
function runPriority() {

    gantt.innerHTML = "";

    const tasks = ["T2", "T3", "T1", "T5", "T4"];

    runTasks(tasks);
}


// animation function
function runTasks(taskList) {

    let index = 0;

    const interval = setInterval(() => {

        if(index >= taskList.length) {

            cpu.innerHTML = "Finished";

            clearInterval(interval);

            return;
        }

        const task = taskList[index];

        cpu.innerHTML = task + " Running";

        // create gantt block
        const block = document.createElement("div");

        block.classList.add("gantt-block");

        block.innerHTML = task;

        // task colors
        if(task === "T1")
            block.style.backgroundColor = "#ff6b6b";

        if(task === "T2")
            block.style.backgroundColor = "#4ecdc4";

        if(task === "T3")
            block.style.backgroundColor = "#1a535c";

        if(task === "T4")
            block.style.backgroundColor = "#ffa600";

        if(task === "T5")
            block.style.backgroundColor = "#6a4c93";

        gantt.appendChild(block);

        index++;

    }, 1000);
}
