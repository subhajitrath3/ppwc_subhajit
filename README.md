# PPWC Subhajit - Daily C Programming Practice

This repository contains solutions to daily lab problems for the "Practical Programming with C" subject. The code is written in C and is organized by problem number or topic. It serves as a personal log of my daily practice and a reference for fundamental programming concepts.

## 📁 Repository Structure

```
ppwc_subhajit/
├── daily_exercises/     # Daily programming exercises (Day 1, Day 2, etc.)
├── basics/             # Basic programs and utilities
├── advanced/           # Advanced programming concepts (future)
├── utils/              # Utility functions and helpers (future)
├── tests/              # Test programs and validation
├── Makefile           # Build automation
├── .gitignore         # Git ignore file
└── README.md          # This file
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make build tool
- Linux/Unix environment

### Building Programs

```bash
# Build all programs
make all

# Clean build artifacts
make clean

# List all available programs
make list

# Get help on available targets
make help
```

### Running Programs

```bash
# Run a specific daily exercise
make run-day01_hello_world
make run-day02_conditionals

# Run basic programs
make run-calculator
make run-number_guessing

# Run all tests
make run-tests
```

## 📚 Daily Exercises

### Week 1: Fundamentals
- **Day 1** (`day01_hello_world.c`) - Hello World, Basic I/O, Variables
- **Day 2** (`day02_conditionals.c`) - If-else, Switch-case, Comparison operators
- **Day 3** (`day03_loops.c`) - For loops, While loops, Do-while loops
- **Day 4** (`day04_functions.c`) - Function definition, Recursion, Parameter passing
- **Day 5** (`day05_arrays_strings.c`) - Arrays, String operations, String functions
- **Day 6** (`day06_pointers.c`) - Pointer basics, Pointer arithmetic, Dynamic memory
- **Day 7** (`day07_structures.c`) - Structures, User-defined types, Nested structures

### Basic Programs
- **Calculator** (`basics/calculator.c`) - Simple arithmetic calculator
- **Number Guessing Game** (`basics/number_guessing.c`) - Interactive guessing game

## 🧪 Testing

The repository includes a simple testing framework in `tests/basic_test.c` that validates core functionality:

```bash
make run-tests
```

Tests cover:
- Basic arithmetic operations
- Factorial calculations
- Prime number detection
- String operations

## 📝 Creating New Exercises

Use the provided template to create new daily exercises:

1. Copy `daily_exercises/template.c` to a new file
2. Fill in the exercise details and code
3. Build and test using `make all`

Example:
```bash
cp daily_exercises/template.c daily_exercises/day08_file_handling.c
# Edit the new file
make run-day08_file_handling
```

## 🎯 Learning Objectives

This repository covers essential C programming concepts:

- **Basic I/O Operations**: printf, scanf, format specifiers
- **Data Types**: int, float, char, arrays, strings
- **Control Structures**: if-else, switch-case, loops
- **Functions**: declaration, definition, recursion, parameter passing
- **Pointers**: basic pointers, pointer arithmetic, dynamic memory allocation
- **Structures**: user-defined types, nested structures
- **Memory Management**: malloc, free, memory safety
- **File Handling**: (planned for future exercises)
- **Advanced Topics**: (planned for future exercises)

## 🛠 Build System Features

The Makefile provides:
- Automatic compilation of all C files
- Proper handling of subdirectories
- Individual program execution
- Test suite runner
- Clean build artifacts
- Math library linking (`-lm`)
- Warning flags for better code quality

## 📋 Best Practices

- Use meaningful variable names
- Add comments for complex logic
- Follow consistent coding style
- Test your programs thoroughly
- Handle edge cases and errors
- Use proper memory management

## 🔄 Daily Practice Routine

1. Read the exercise description
2. Understand the problem requirements
3. Plan your solution approach
4. Write the code following best practices
5. Compile and test your program
6. Review and optimize if needed
7. Document any learnings or challenges

## 🤝 Contributing

This is a personal learning repository, but suggestions and improvements are welcome through issues and pull requests.

## 📄 License

This project is for educational purposes. Feel free to use the code as a reference for your own learning.
