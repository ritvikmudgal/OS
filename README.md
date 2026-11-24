# OS Lab (DSC08) - Practical List with Code Files

Read the question here, then open the code file mentioned under it.

**Where to run:** a Linux terminal (college lab machine, Ubuntu, WSL on Windows, or a Linux VM).
Practicals 5 and 6 only work on Linux. The C programs compile with `gcc`.

Quick index:

| No. | Code file |
|-----|-----------|
| 1   | none (OS simulator, or demo steps in Practical 1 below) |
| 2   | p2_commands.sh |
| 3   | p3_commands.sh |
| 4   | p4a.c, p4b.c, p4c.c |
| 5   | p5.c |
| 6   | p6.c |
| 7   | p7.c |
| 8   | p8.c |
| 9   | p9.c |
| 10  | p10.c |
| 11  | p11.c |
| 12  | p12.c |

---

## Practical 1
**Q.** Demonstration of various Operating System functions using OS Simulator.

**File:** no code. If your lab gives you an OS simulator, open it and show process
scheduling, memory allocation and file operations (screenshot each, write 2-3 lines on
which OS function it shows).

**If the simulator is confusing:** demonstrate the same OS functions in the Linux terminal.
First compile the programs (in the same folder as the code files):

    gcc p4c.c -o p4c
    gcc p7.c -o p7
    gcc p8.c -o p8
    gcc p12.c -o p12

Then follow these steps. Take a screenshot after each one and write one line on which
OS function it shows.

**1. Process management** (creating, listing, killing, scheduling processes)

    sleep 100 &        # start a process in the background
    ps                 # list processes, you will see sleep
    kill %1            # stop that process
    ./p8               # FCFS scheduling (enter 3 processes, burst times 24 3 3)

**2. Memory management** (checking memory, allocating it to processes)

    free -m            # used and free memory
    ./p12              # first-fit, best-fit, worst-fit (blocks 100 500 200 300 600,
                       #   processes 212 417 112 426)

**3. File management** (create, write, read, delete)

    touch a.txt
    echo hi > a.txt
    cat a.txt
    rm a.txt

**4. System calls** (fork/wait and file copy using system calls)

    ./p4c              # fork and wait
    echo "test data" > src.txt
    ./p7 src.txt dest.txt && cat dest.txt   # file copy using open/read/write

---

## Practical 2
**Q.** Execute various LINUX commands for:
- i. Information Maintenance: wc, clear, cal, who, date, pwd
- ii. File Management: cat, cp, rm, mv, cmp, comm, diff, find, grep, awk
- iii. Directory Management: cd, mkdir, rmdir, ls

**File:** `p2_commands.sh`

    bash p2_commands.sh
(or type the commands one by one in the terminal and take screenshots)

---

## Practical 3
**Q.** Execute various LINUX commands for:
- i. Process Control: fork, getpid, ps, kill, sleep
- ii. Communication: Input-output redirection, Pipe
- iii. Protection Management: chmod, chown, chgrp

**File:** `p3_commands.sh`

    bash p3_commands.sh
Note: fork is a system call (not a shell command), see Practical 4. getpid is shown using `$$`.

---

## Practical 4
**Q.** Write a program (using fork() and/or exec() commands) where parent and child execute:
- i. same program, same code.
- ii. same program, different code.
- iii. before terminating, the parent waits for the child to finish its task.

**Files:** `p4a.c` (i), `p4b.c` (ii), `p4c.c` (iii)

    gcc p4a.c -o p4a && ./p4a
    gcc p4b.c -o p4b && ./p4b
    gcc p4c.c -o p4c && ./p4c

---

## Practical 5
**Q.** Write a program to report behaviour of Linux kernel including kernel version,
CPU type and CPU information.

**File:** `p5.c` (Linux only)

    gcc p5.c -o p5 && ./p5

---

## Practical 6
**Q.** Write a program to report behaviour of Linux kernel including information on
configured memory, amount of free and used memory. (Memory information)

**File:** `p6.c` (Linux only)

    gcc p6.c -o p6 && ./p6

---

## Practical 7
**Q.** Write a program to copy files using system calls.

**File:** `p7.c`

    echo "test data" > src.txt
    gcc p7.c -o p7 && ./p7 src.txt dest.txt
    cat dest.txt

---

## Practical 8
**Q.** Write a program to implement First Come First Serve (FCFS) scheduling algorithm.

**File:** `p8.c`

    gcc p8.c -o p8 && ./p8
Sample input: 3 processes, burst times 24 3 3

---

## Practical 9
**Q.** Write a program to implement Shortest Job First (SJF) scheduling algorithm.

**File:** `p9.c`

    gcc p9.c -o p9 && ./p9
Sample input: 3 processes, burst times 24 3 3

---

## Practical 10
**Q.** Write a program to implement non-preemptive priority-based scheduling algorithm.

**File:** `p10.c`

    gcc p10.c -o p10 && ./p10
Sample input: 3 processes, (burst, priority) = 3 2, 1 1, 2 3
Lower priority number = higher priority.

---

## Practical 11
**Q.** Write a program to calculate sum of n numbers using Pthreads.

**File:** `p11.c`

    gcc p11.c -o p11 -pthread && ./p11
Note the `-pthread` flag. Sample input: n = 10 (output 55).

---

## Practical 12
**Q.** Write a program to implement first-fit, best-fit and worst-fit allocation strategies.

**File:** `p12.c`

    gcc p12.c -o p12 && ./p12
Sample input: blocks 100 500 200 300 600, processes 212 417 112 426
