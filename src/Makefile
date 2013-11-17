CC=/usr/bin/gcc
AR=/usr/bin/ar
CP=/bin/cp
MKDIR=/bin/mkdir
RM=/bin/rm

CFLAGS=-g3 -Wall -lm

BUILD_DIR=../build

all: init
	${CC} ${CFLAGS} -I. -c -o ${BUILD_DIR}/gps.o gps.c
	${CC} ${CFLAGS} -I. -c -o ${BUILD_DIR}/serial.o serial.c
	${CC} ${CFLAGS} -I. -c -o ${BUILD_DIR}/nmea.o nmea.c
	${AR} -rsc ${BUILD_DIR}/libgps.a ${BUILD_DIR}/gps.o ${BUILD_DIR}/serial.o ${BUILD_DIR}/nmea.o
	${CP} *.h ${BUILD_DIR}
	@echo
	@echo
	@echo RUN TESTS SHOULD BE A GOOD IDEA...
	@echo
	@echo make tests
	@echo
	@echo

init:
	${MKDIR} -p ${BUILD_DIR}

install:
	ln -s `pwd`/${BUILD_DIR}/libgps.a /usr/lib/libgps.a
	ln -s `pwd`/${BUILD_DIR}/gps.h /usr/include/gps.h

clean:
	${RM} ${BUILD_DIR}/*

