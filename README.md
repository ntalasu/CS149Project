# CS149 File System Project

A command-line file management program written in C for an Operating Systems course project.

## Overview

This project provides a simple interactive interface for performing common file operations. The program uses C's standard file I/O APIs to create, write, read, search, open, and close files.

## Features

* Create a new file
* Append content to a file
* Read and display file contents
* Search for a file by filename
* Open a file and track the currently open file
* Safely close an open file
* Handle invalid menu input and file-operation errors

## Implementation

The main implementation is contained in `FileSystem.c`.

Key functions include:

* `getFilename()` — reads and cleans a filename entered by the user
* `createFile()` — creates a file using `fopen()` with write mode
* `writeToFile()` — appends content using `fopen()` with append mode and `fprintf()`
* `readFromFile()` — reads file contents using `fgetc()` until `EOF`
* `searchFile()` — checks whether a file can be opened for reading
* `closeFile()` — safely closes a `FILE*` and reports whether closing succeeded

The program also maintains an `openFile` pointer so it can track whether a file is currently open and prevent another file from being opened at the same time.

## Technologies

* C
* Standard C File I/O
* Operating Systems concepts

## Running the Program

Compile the program with GCC:

```bash
gcc FileSystem.c -o filesystem
```

Run it with:

```bash
./filesystem
```

## Example Workflow

After starting the program, choose an operation from the menu:

```text
--- File Operations Menu ---
1. Create file
2. Write to file
3. Read from file
4. Search file
5. Open file
6. Close open file
7. Exit
Choose an option (1-7):
```

For example, you can create a file, write content to it, read the contents back, and then close the file.

## Learning Objectives

This project provides practice with C programming and operating-system-level file operations, including file pointers, file I/O, resource management, input handling, error checking, and basic state management.
