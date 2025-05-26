# 📡 Minitalk – Inter-Process Communication in C

Welcome to **Minitalk**, a 42 Barcelona project developed during my studies at 42 Network. This project explores inter-process communication (IPC) in Unix using signals. It showcases how messages can be sent from one process to another (client → server) using only `SIGUSR1` and `SIGUSR2`, character by character in binary form.

---

## 🧠 Project Objective

The aim of Minitalk is to implement a simple messaging system using POSIX signals. The project includes:

- **Client program**: Sends a string message to a server process.
- **Server program**: Receives signals, reconstructs the message, and prints it.
- **Bonus**: Extended features including UTF-8 support and acknowledgment signals.

This project focuses on:
- Deep understanding of signal handling
- Bitwise operations
- Process synchronization
- Robust use of `sigaction`, `kill`, `pause`, and `usleep`

---

## 🔧 Technical Overview

### ✅ Mandatory Part

- **Signals**:
  - `SIGUSR1` = Bit `0`
  - `SIGUSR2` = Bit `1`

- **Client (`client.c`)**:
  - Converts each character into binary and sends it bit-by-bit using `kill()`.
  - Waits briefly between signals to allow the server to process them.
  - Sends a `\0` to signal the end of the message.

- **Server (`server.c`)**:
  - Reconstructs characters bit-by-bit from incoming signals.
  - Uses a `sigaction` handler with `SA_SIGINFO` for client PID tracking.
  - Sends a `SIGUSR1` back to confirm reception of each byte.

### ⭐ Bonus Part

- **UTF-8 Support**:
  - Validates and decodes multi-byte UTF-8 characters using a buffer.
  - Ensures correct interpretation of non-ASCII characters.

- **Acknowledgment Handling**:
  - Client waits for a `SIGUSR1` after each bit sent before proceeding.
  - Prevents signal loss and race conditions in fast systems.

- **Files**:
  - `client_bonus.c` / `server_bonus.c`
  - Enhanced error handling, validation, and multi-byte decoding logic.

---

## 📁 Project Structure

Minitalk/
├── includes/ # Header files
│ ├── minitalk.h # Main project declarations
│ └── minitalk_bonus.h # Bonus-specific definitions
├── libft/ # Custom C library functions
├── sources/ # Mandatory client/server source code
├── sources_bonus/ # Bonus implementations
├── en.Minitalk.pdf # Official project subject PDF
├── Makefile # Build automation
└── README.md # Project documentation

---

## ▶️ Usage

### 🛠 Compilation

```
make        # Builds both client and server
make bonus  # Builds bonus version
make clean  # Removes object files
make fclean # Cleans everything including binaries
```

## 🚀 Running the Programs

1. Start the server:
```
./server
# Output: Server PID: 12345
```

2. Send a message from the client:
```
./client 12345 "Hello, 42!"
```

3. Bonus version:
```
./server_bonus
./client_bonus 12345 "¡Hola, UTF-8 🌍!"
```

## 📌 Key Learnings

Bit-level data transfer using signals.

Writing efficient and safe signal handlers.

Managing asynchronous communication between processes.

Implementing UTF-8 decoding and validation from scratch.

Structuring clean and modular C projects with Makefile and libft.

## 📜 License
This project is licensed under the MIT License.

## 🙋‍♂️ About Me

I'm Francisco Li, a 42 Barcelona student with a background in languages and communication, currently transitioning into technology. This project reflects my journey in mastering systems-level programming in C.
Feel free to connect or contribute!

---

Let me know if you'd like a Spanish version or a more personalized style (e.g., informal tone, emojis, etc.).

