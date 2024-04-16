# OS
ifeq ($(OS),Windows_NT)
    RM_CMD = del /s /q /f 
    EXE_FILE = prog.exe
else
    RM_CMD = rm -rf   
	EXE_FILE = prog 
endif

CFLAGS =  -Wextra -std=c99

all: $(EXE_FILE)

$(EXE_FILE): main.o temp_api.o 
	gcc $(CFLAGS) -o $(EXE_FILE) main.o temp_api.o

main.o: main.c temp_api.h 
	gcc $(CFLAGS) -c -o main.o main.c

temp_api.o: temp_api.c 
	gcc $(CFLAGS) -c -o temp_api.o temp_api.c

clean: 
	$(RM_CMD) *.o $(EXE_FILE)
