# virtualscheduler
A virtual scheduler that works on top of the linux scheduler with customisable scheduling algorithms.

This virtual scheduler runs on top of the existing linux scheduler which isn't modified. It consists of two major components: a generator and a scheduler. The generator is responsible for generating the processes at regular interval. The scheduler maintains a ‘Ready Queue’ which contains the set of runnable processes at any time-instance. It chooses/schedules one of the runnable processes according to the scheduling algorithm for execution which can be selected by the user right after program compilation. Next it sends a ‘notify’ signal to only that chosen/scheduled process and ‘suspend’ signal to all other processes. Depending on the signal (‘notify’/’suspend’’) received from the scheduler, the processes can either (re)start processing or wait until it’s scheduled again. Once all the processes terminate, the scheduler also terminates.

The Scheduler is also responsible for calculating the average turnaround time and average waiting time for various schedulers.
