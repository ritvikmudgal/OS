#!/bin/bash
# Practical 3: Process control, Communication, Protection commands
# Run: bash p3_commands.sh   (or type the commands one by one in terminal)
# Note: fork() is a system call (see Practical 4), getpid is shown with $$

echo "---- Process Control ----"
echo "PID of this shell: $$"       # getpid
ps                                  # running processes
sleep 100 &                         # run in background
ps
kill $!                             # kill last background process
sleep 2

echo "---- Communication ----"
echo "hello" > out.txt              # output redirection
cat < out.txt                       # input redirection
ls | wc -l                          # pipe: count files
cat out.txt | grep hello            # pipe with grep

echo "---- Protection Management ----"
ls -l out.txt
chmod 755 out.txt                   # change permissions
ls -l out.txt
chown $USER out.txt                 # change owner
chgrp $(id -gn) out.txt             # change group
ls -l out.txt
rm out.txt
