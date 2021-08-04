# Makefile

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

VECTOR_CPP = tests/vector/cpp_files/vector.cpp
VECTOR_EXECUTABLE = tests/vector/executables/testVector
VECTOR_OUTPUT = tests/vector/output/outputVector.txt

MY_VECTOR_CPP = tests/vector/cpp_files/myVector.cpp
MY_VECTOR_EXECUTABLE = tests/vector/executables/testMyVector
MY_VECTOR_OUTPUT = tests/vector/output/outputMyVector.txt

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

vector:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(VECTOR_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(VECTOR_CPP) -o $(VECTOR_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(GREEN)Creating executable: $(NORMAL)$(MY_VECTOR_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(MY_VECTOR_CPP) -o $(MY_VECTOR_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(BLUE)Outputting to files...$(NORMAL)\n"
	./$(VECTOR_EXECUTABLE) > $(VECTOR_OUTPUT)
	./$(MY_VECTOR_EXECUTABLE) > $(MY_VECTOR_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(VECTOR_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(MY_VECTOR_OUTPUT)

vector_diff:
	@echo "$(BLUE)Diff results...$(NORMAL)\n"
	diff $(VECTOR_OUTPUT) $(MY_VECTOR_OUTPUT); [ $$? -eq 1 ]

clean:
	@echo "$(RED)Removing executables:$(NORMAL) $(VECTOR_EXECUTABLE) $(MY_VECTOR_EXECUTABLE)\n"
	/bin/rm -f $(VECTOR_EXECUTABLE) $(MY_VECTOR_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(RED)Removing output files:$(NORMAL) $(VECTOR_OUTPUT) $(MY_VECTOR_OUTPUT)\n"
	/bin/rm -f $(VECTOR_OUTPUT) $(MY_VECTOR_OUTPUT)
