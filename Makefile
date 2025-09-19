# Makefile for PPWC Daily Practice
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCDIR = .
BUILDDIR = build
BINDIR = bin

# Create necessary directories
$(shell mkdir -p $(BUILDDIR) $(BINDIR))

# Find all .c files recursively (exclude template.c)
SOURCES = $(shell find $(SRCDIR) -name "*.c" -not -path "./$(BUILDDIR)/*" -not -path "./$(BINDIR)/*" -not -name "template.c")

.PHONY: all clean run-tests help list

# Default target
all: $(SOURCES)
	@echo "Building all programs..."
	@for src in $(SOURCES); do \
		dir=$$(dirname "$$src"); \
		base=$$(basename "$$src" .c); \
		outdir="$(BINDIR)/$$dir"; \
		mkdir -p "$$outdir"; \
		echo "Compiling $$src..."; \
		$(CC) $(CFLAGS) "$$src" -o "$$outdir/$$base" -lm; \
	done
	@echo "Build complete!"

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR) $(BINDIR)
	@echo "Cleaned build directories"

# Run all test executables
run-tests:
	@echo "Running all test executables..."
	@find $(BINDIR) -name "*test*" -type f 2>/dev/null | while read exe; do \
		echo "Running $$exe..."; \
		$$exe; \
		echo ""; \
	done

# Compile and run a specific program by path
run-%:
	@prog=$$(echo "$*" | sed 's|_|/|g'); \
	src_file=""; \
	if [ -f "$$prog.c" ]; then \
		src_file="$$prog.c"; \
	elif [ -f "daily_exercises/$$prog.c" ]; then \
		src_file="daily_exercises/$$prog.c"; \
	elif [ -f "basics/$$prog.c" ]; then \
		src_file="basics/$$prog.c"; \
	elif [ -f "tests/$$prog.c" ]; then \
		src_file="tests/$$prog.c"; \
	else \
		echo "Source file not found for: $*"; \
		exit 1; \
	fi; \
	dir=$$(dirname "$$src_file"); \
	base=$$(basename "$$src_file" .c); \
	outdir="$(BINDIR)/$$dir"; \
	mkdir -p "$$outdir"; \
	echo "Compiling $$src_file..."; \
	$(CC) $(CFLAGS) "$$src_file" -o "$$outdir/$$base" -lm; \
	echo "Running $$outdir/$$base..."; \
	$$outdir/$$base

# List all available programs
list:
	@echo "Available programs:"
	@find . -name "*.c" -not -name "template.c" -not -path "./$(BUILDDIR)/*" -not -path "./$(BINDIR)/*" | sed 's|^\./||' | sed 's|\.c$$||' | sort

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Compile all C files"
	@echo "  clean       - Remove build artifacts"
	@echo "  run-tests   - Run all test executables"
	@echo "  run-<name>  - Compile and run specific program"
	@echo "  list        - List all available programs"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make run-day01_hello_world"
	@echo "  make run-calculator"
	@echo "  make run-basic_test"