PROGRAM_NAME = sensors
# OS
ifeq ($(OS),Windows_NT)
    RM_CMD = del /s /q /f 
    EXE_FILE = $(PROGRAM_NAME).exe
else
    RM_CMD = rm -rf   
	EXE_FILE = $(PROGRAM_NAME) 
endif

GCC = gcc -g -Wall -std=c99

all: $(EXE_FILE)

$(EXE_FILE): main.o temp_api.o file_api.o
	$(GCC) -o $(EXE_FILE) main.o temp_api.o file_api.o

main.o: main.c 
	$(GCC) -c -o main.o main.c

temp_api.o: temp_api.c 
	$(GCC) -c -o temp_api.o temp_api.c

file_api.o: file_api.c 
	$(GCC) -c -o file_api.o file_api.c	

clean: 
	$(RM_CMD) *.o $(EXE_FILE)
	$(RM_CMD) errors.txt
