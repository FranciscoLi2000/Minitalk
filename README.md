# Minitalk

Minitalk is a UNIX signal-based inter-process communication project.

## Description
The client sends a string to the server using SIGUSR1 and SIGUSR2.
The server decodes the signals and prints the received message.

## Usage

```bash
make
./server
./client <SERVER_PID> "message"
