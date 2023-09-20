# C Code - Assembly Simulator
## Anomaly Detection Application
This C project is an anomaly detection application designed to read and process input files. It handles various tasks concurrently, such as managing concurrent operations across multiple files, organizing file differentiation, and scheduling. The application is developed to run on Ubuntu within a virtual machine.

## Overview
The anomaly detection application processes input files and performs various operations based on the content of the files. Here is a brief summary of the project's key features:

Reads input files, line by line.
Processes words within each line to identify their context.
Manages concurrent operations across multiple files.
Differentiates files based on content and organizes them.
Developed for use on Ubuntu within a virtual machine.
## Project Structure
The project consists of the following main components:

Assembler.h and Assembler.cpp: These files provide header and implementation for the main assembler functionality.
In addition, there are additional files.

The primary code is contained in the following file, as per your provided code snippet:
main.c: This file contains the main algorithm for processing input files, identifying symbols, data, and commands, and encoding them appropriately.
## Usage
To use the anomaly detection application, follow these steps:
```bash
gcc main.c -o anomaly_detection
```
Ensure you have the necessary dependencies (see Dependencies).
Build the project using the instructions provided in Building.
Run the application by executing the compiled binary with the input file as an argument.
The application will process the input file and perform anomaly detection operations.
