include config.mk

SRC = main.cpp src/datafeed.cpp src/performancemonitor.cpp src/rollingsharpeengine.cpp

OBJ = ${SRC:.cpp=.o}


all: options main 

options:
	@echo Change in config.mk if needed:
	@echo "Version -> ${VERSION}"
	@echo "CFLAGS = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC = ${CC}"
	@echo "--------------------------"

.cpp.o:
	${CC} -c -o $@ ${CFLAGS} $< 

main: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS} ${LDFLAGS}
clean:
	rm main *.o 
