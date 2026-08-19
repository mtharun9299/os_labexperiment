#!/bin/bash
echo "Parent Process ID : $$"
(
echo "Child Process ID : $$"
echo "Parent Process ID : $PPID"
exit 0
) &
wait
echo "Child Process Completed"
