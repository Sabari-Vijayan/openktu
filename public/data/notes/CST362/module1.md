---
title: Introduction to Python 
--- 

# Introduction to Python

## Guido van Rossum – Creator of Python

Guido van Rossum invented the Python programming language in the early 1990s.
Python is a **high-level, general-purpose programming language** used for solving problems on modern computers.
The language and its supporting tools are **free**, and Python programs can run on **any operating system**.

![Guido van Rossum](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/Guido_van_Rossum_in_PyConUS24_%28cropped%29.jpg/960px-Guido_van_Rossum_in_PyConUS24_%28cropped%29.jpg)

---

## Running Code in the Interactive Shell

Python is an **interpreted language**, and it allows executing expressions directly in an interactive environment called the **Python shell**.

### Opening the Shell

The simplest way to open the shell is through **IDLE (Integrated DeveLopment Environment)**, which comes bundled with Python.
Opening IDLE launches a window called **Python Shell**.

### Shell Prompt

A shell window displays a startup message followed by the prompt:

```
>>>
```

* The cursor at this prompt waits for your Python commands.
* You can get help by typing `help` or by using the *Help* menu in IDLE.

---

## How Python Works

### **Definition (One Line)**

Python is a **high-level, interpreted, dynamically-typed programming language** whose primary implementation (CPython) compiles source code to bytecode and executes it on a virtual machine.

---

## Execution Pipeline (Step-by-Step)

### **1. Source Code**

You write human-readable `.py` files.

### **2. Lexing / Tokenizing**

Python converts the text to **tokens**—keywords, identifiers, operators, literals, etc.

### **3. Parsing → AST**

Tokens are parsed into an **Abstract Syntax Tree (AST)** that represents program structure.

### **4. Compilation → Bytecode**

The AST is compiled into **Python bytecode** (platform-independent instructions).
Modules may store bytecode as `.pyc` in the `__pycache__` directory.

### **5. Bytecode Execution (PVM)**

The **Python Virtual Machine (PVM)** executes the bytecode using an evaluation loop.
Each bytecode instruction (e.g., `LOAD_CONST`, `BINARY_ADD`) is implemented in C.

### **6. Native operations via C API**

Many built-in operations, I/O tasks, and performance-heavy routines use Python’s **C API** to call optimized C code.

---

## Data Types in Python

![Python Data Types](https://media.geeksforgeeks.org/wp-content/uploads/20241210131752166623/Python-Data-Types.webp)

---

If you want this content simplified, expanded, or split into units, just tell me!

