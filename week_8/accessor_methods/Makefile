.PHONY: all clean coverage

all:
	@g++ -std=c++23 -Wall -Wextra -Weffc++ -pedantic -g main.cpp password_protected_data.cpp

coverage: clean
	@g++ --coverage -g main.cpp password_protected_data.cpp
	@./a.out
	@printf "\n=== coverage ===\n"
	@gcov -mr a-password_protected_data

clean:
	@rm -f *.gcda *.gcno *.gcov a.out
