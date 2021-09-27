# Makefile

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

FT_CONTAINERS_EXECUTABLE = test_ft_containers
FT_CONTAINERS_SRC = tests/ft/ft_main.cpp
FT_OUTPUT = ft_output

STD_CONTAINERS_EXECUTABLE = test_std_containers
STD_CONTAINERS_SRC = tests/std/std_main.cpp
STD_OUTPUT = std_output

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(FT_CONTAINERS_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(FT_CONTAINERS_SRC) -o $(FT_CONTAINERS_EXECUTABLE)
	@echo "----------------------------------------------------"
	@echo "$(GREEN)Creating executable: $(NORMAL)$(STD_CONTAINERS_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(STD_CONTAINERS_SRC) -o $(STD_CONTAINERS_EXECUTABLE)

ft:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(FT_CONTAINERS_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(FT_CONTAINERS_SRC) -o $(FT_CONTAINERS_EXECUTABLE)

std:
	@echo "$(GREEN)Creating executable: $(NORMAL)$(STD_CONTAINERS_EXECUTABLE)\n"
	$(CC) $(FLAGS) $(STD_CONTAINERS_SRC) -o $(STD_CONTAINERS_EXECUTABLE)

test:
	@./$(FT_CONTAINERS_EXECUTABLE) > $(FT_OUTPUT)
	@./$(STD_CONTAINERS_EXECUTABLE) > $(STD_OUTPUT)

clean:
	@echo "$(RED)Removing executables:$(NORMAL) $(FT_CONTAINERS_EXECUTABLE) $(STD_CONTAINERS_EXECUTABLE)\n"
	/bin/rm -f $(FT_CONTAINERS_EXECUTABLE) $(STD_CONTAINERS_EXECUTABLE)
	@echo "$(RED)Removing output files:$(NORMAL) $(FT_OUTPUT) $(STD_OUTPUT)\n"
	/bin/rm -f $(FT_OUTPUT) $(STD_OUTPUT)
