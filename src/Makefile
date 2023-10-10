
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address -g
#LIBRARY = s21_matrix_oop.a
CLEAN = clean
REPORT = gcov_report
TESTS = ./Testing/
#SRC = $(wildcard *.cpp)
UNAME := $(shell uname)
SRC_TEST = $(wildcard $(TESTS)*.cc)
SRC_TEST_HEADER = $(wildcard $(TESTS)*.h)
TARGET = test

GCOV_FLAGS = -g -fprofile-arcs -ftest-coverage -lgcov 

ifeq ($(UNAME), Linux)
 TEST_FLAGS += -lgtest -lm
else
 TEST_FLAGS += -lgtest -lgtest_main -pthread -lm
endif
all : $(CLEAN) $(LIBRARY) $(TARGET)
$(TARGET) : 
	$(CXX) -std=c++17 $(FLAGS) $(SRC_TEST) $(TEST_FLAGS) -o tests
	./tests


$(REPORT) : $(CLEAN) $(SRC) $(SRC_TEST) build_file
	$(CXX) -std=c++17 $(FLAGS) $(GCOV_FLAGS) $(SRC_TEST) $(SRC) $(TEST_FLAGS) -o Build/$(REPORT)
	Build/./$(REPORT)
	lcov -o $(REPORT).info -c -d .
	lcov -r $(REPORT).info "/usr*" -o $(REPORT).info
	genhtml $(REPORT).info -o html_report
	open html_report/index.html

build_file:
	mkdir Build

rm_buld_file:
	rm -rf Build
style: 
	clang-format -i *.h $(SRC_TEST) $(SRC_TEST_HEADER)

$(CLEAN) :
	rm -rf tests *.a *.o $(TESTS).*o ./html_report/ gcov_report *.gcno *.gcda *.info *.out Build
