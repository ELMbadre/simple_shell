test
# Simple Shell Project

## Overview

The Simple Shell Project is a collaborative effort to create a basic UNIX command interpreter in C. The project involves building an interactive shell that can execute user commands, handle various scenarios, and support both built-in functionalities and external command execution.

## Mandatory Tasks

### 1. Betty would be proud

Write clean and beautiful code that passes the Betty checks.

### 2. Simple shell 0.1

Write a UNIX command line interpreter with the following features:

- Display a prompt and wait for user input.
- Execute simple command lines (no semicolons, pipes, redirections).
- Handle errors.
- Handle the "end of file" condition (`Ctrl+D`).

### 3. Simple shell 0.2

Extend Simple shell 0.1 to handle command lines with arguments.

### 4. Simple shell 0.3

Enhance Simple shell 0.2 to handle the `PATH` and avoid unnecessary `fork` calls.

### 5. Simple shell 0.4

Further improve Simple shell 0.3 by implementing the `exit` built-in.

### 6. Simple shell 1.0

Add the `env` built-in to print the current environment.

### 7. What happens when you type `ls -l *.c` in the shell

Write a blog post detailing the step-by-step process when typing `ls -l *.c` in a shell. Publish it on Medium.

## Usage

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell.
```

## Authors

Khalid Elaasry.
EL MOUTARIF Badreddine.
