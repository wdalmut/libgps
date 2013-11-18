CC=/usr/bin/gcc
AR=/usr/bin/ar
CP=/bin/cp
MKDIR=/bin/mkdir
RM=/bin/rm

CFLAGS=-g3 -Wall

BUILD_PATH=../build
TESTS_BIN=${BUILD_PATH}/all_tests

FILES_LIST= ../src/nmea.c ../src/serial.c ../src/gps.c \
			all_tests.c nmea_test.c gps_test.c serial_test.c helpers.c

all:
	${CC} ${CFLAGS} \
		-o ${TESTS_BIN} ${FILES_LIST} -I../src/ -lm \
		`pkg-config --cflags --libs check`
	@echo
	@echo
	@echo "*****************************************************************"
	@echo
	./${TESTS_BIN}
	@echo
	@echo "*****************************************************************"
	@echo

clean:
	${RM} ${TESTS_BIN}
