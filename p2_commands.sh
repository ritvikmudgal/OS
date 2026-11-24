#!/bin/bash
# Practical 2: Information, File and Directory management commands
# Run: bash p2_commands.sh   (or type the commands one by one in terminal)

echo "---- Information Maintenance ----"
echo "hello os lab" > a.txt
wc a.txt          # lines, words, characters
cal               # calendar
who               # logged in users
date              # date and time
pwd               # present directory

echo "---- Directory Management ----"
mkdir lab         # make directory
ls                # list
cd lab            # change directory
pwd
cd ..
rmdir lab         # remove empty directory

echo "---- File Management ----"
cat a.txt                      # show file
cp a.txt b.txt                 # copy
mv b.txt c.txt                 # rename/move
echo "hello os lab 2" > d.txt
cmp a.txt d.txt                # compare byte by byte
sort a.txt > s1.txt; sort d.txt > s2.txt
comm s1.txt s2.txt             # compare sorted files
diff a.txt d.txt               # show differences
find . -name "*.txt"           # search files
grep "os" a.txt                # search pattern
awk '{print $1}' a.txt         # print first column
rm c.txt s1.txt s2.txt         # delete files
