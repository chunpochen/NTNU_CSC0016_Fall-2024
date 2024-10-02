# UNIX Shell and History Feature

This project involves creating a simple UNIX shell that can execute basic commands and store a history of previously executed commands. The project is divided into two parts:

## Part I — Creating a Simple Shell

In this part, we implement a basic UNIX shell that:
1. Reads user input from the command line.
2. Parses the input into commands and arguments.
3. Uses the `fork()` system call to create a child process.
4. In the child process, executes the command using `execvp()`.
5. Supports both foreground and background execution. Commands followed by `&` are executed in the background, and the shell does not wait for their completion.

### Key Features:
- **Command Execution**: The shell can execute basic UNIX commands like `ls`, `pwd`, and more.
- **Background Execution**: By appending `&` at the end of a command, the shell will execute the command in the background without waiting for it to finish.
- **Exiting the Shell**: The shell continues running until the user types `exit`.

## Part II — Adding a History Feature

In this part, we extend the shell to maintain a history of the most recent commands. The shell will:
1. Store the last 10 commands entered by the user.
2. Allow users to view the command history by typing `history`.
3. Support re-execution of the most recent command using `!!` and re-execution of a specific command using `!N`, where `N` is the command number in the history.

### Key Features:
- **Command History**: The shell stores up to 10 of the most recent commands.
- **Re-execution**: 
  - Use `!!` to execute the most recent command.
  - Use `!N` to execute the `N`th command from the history.
- **History Management**: The shell correctly handles edge cases, such as when there is no history or when an invalid command number is entered.
