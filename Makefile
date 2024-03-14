# Makefile 예제

# 컴파일러 설정
CXX = g++
# 컴파일 옵션 설정
CXXFLAGS = -Wall -Wextra -std=c++11
# 링크할 파일들 설정
SRCS = $(wildcard *.cpp)
# 컴파일한 파일들 설정
OBJS = $(SRCS:.cpp=.o)
# 실행 파일 이름 설정
EXEC = main

# 기본 목표 설정
all: $(EXEC)

# 실행 파일 만들기
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# .o 파일 만들기
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# main.o 생성 규칙 추가
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 정리 작업
clean:
	rm -f $(OBJS) $(EXEC)

