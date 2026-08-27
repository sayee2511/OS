#!/bin/bash
echo "PARENT PROCESS"
echo "Parent PID : $$"
(
    echo "CHILD PROCESS"
    echo "Child PID : $BASHPID"
    echo "Parent PID : $$"
    exit 0
)
wait
echo "Child Process Completed"
