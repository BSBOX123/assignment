CC = g++
CFLAGS = -Wall -c -O2        # 경고, 개별 컴파일, 최적화
DEBUGFLAGS = -Wall -c -g     # 디버깅용 플래그
OBJ = main.o Calculation.o        # 오브젝트 파일 목록
TARGET = mp

# 기본 실행 명령어 (make)
all: $(TARGET)

# 실행 파일 만들기 (링킹)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# 개별 오브젝트 파일 만들기 (컴파일)
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# 디버그 빌드
debug: override CFLAGS = $(DEBUGFLAGS)
debug: clean all

# 정리
clean:
	rm -f $(OBJ) $(TARGET)

