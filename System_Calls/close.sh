#!/bin/bash
exec 3< wait.c
echo "File Opened Successfully"
exec 3<&-
echo "File Closed Successfully"
