# Makefile

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

VECTOR_CPP = tests/vector/cpp_files/std_vector_tests.cpp
VECTOR_EXECUTABLE = tests/vector/executables/testVector
VECTOR_OUTPUT = tests/vector/output/outputVector.txt

MY_VECTOR_CPP = tests/vector/cpp_files/my_vector_tests.cpp
MY_VECTOR_EXECUTABLE = tests/vector/executables/testMyVector
MY_VECTOR_OUTPUT = tests/vector/output/outputMyVector.txt

STACK_CPP = tests/stack/cpp_files/std_stack_tests.cpp
STACK_EXECUTABLE = tests/stack/executables/testStack
STACK_OUTPUT = tests/stack/output/outputStack.txt

MY_STACK_CPP = tests/stack/cpp_files/my_stack_tests.cpp
MY_STACK_EXECUTABLE = tests/stack/executables/testMyStack
MY_STACK_OUTPUT = tests/stack/output/outputMyStack.txt

MAP_CPP = tests/map/cpp_files/std_map_tests.cpp
MAP_EXECUTABLE = tests/map/executables/testMap
MAP_OUTPUT = tests/map/output/outputMap.txt

MY_MAP_CPP = tests/map/cpp_files/my_map_tests.cpp
MY_MAP_EXECUTABLE = tests/map/executables/testMyMap
MY_MAP_OUTPUT = tests/map/output/outputMyMap.txt

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all: vector stack map

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

stack:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(STACK_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(STACK_CPP) -o $(STACK_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(GREEN)Creating executable: $(NORMAL)$(MY_STACK_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(MY_STACK_CPP) -o $(MY_STACK_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(BLUE)Outputting to files...$(NORMAL)\n"
	./$(STACK_EXECUTABLE) > $(STACK_OUTPUT)
	./$(MY_STACK_EXECUTABLE) > $(MY_STACK_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(STACK_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(MY_STACK_OUTPUT)

map:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(MAP_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(MAP_CPP) -o $(MAP_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(GREEN)Creating executable: $(NORMAL)$(MY_MAP_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(MY_MAP_CPP) -o $(MY_MAP_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(BLUE)Outputting to files...$(NORMAL)\n"
	./$(MAP_EXECUTABLE) > $(MAP_OUTPUT)
	./$(MY_MAP_EXECUTABLE) > $(MY_MAP_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(MAP_OUTPUT)
	@echo "----------------------------------------------------"
	@cat $(MY_MAP_OUTPUT)

clean:
	@echo "$(RED)Removing executables:$(NORMAL) $(VECTOR_EXECUTABLE) $(MY_VECTOR_EXECUTABLE)\n"
	/bin/rm -f $(VECTOR_EXECUTABLE) $(MY_VECTOR_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(RED)Removing output files:$(NORMAL) $(VECTOR_OUTPUT) $(MY_VECTOR_OUTPUT)\n"
	/bin/rm -f $(VECTOR_OUTPUT) $(MY_VECTOR_OUTPUT)
