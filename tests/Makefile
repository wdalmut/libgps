CC=/usr/bin/gcc
AR=/usr/bin/ar
CP=/bin/cp
MKDIR=/bin/mkdir
RM=/bin/rm

CFLAGS=-g3 -Wall

BUILD_PATH=../build

all:
	${CC} ${CFLAGS} \
		-o ${BUILD_PATH}/gps_tests all_tests.c ../src/nmea.c nmea_test.c \
		../src/serial.c serial_test.c ../src/gps.c gps_test.c \
		-I../src/ -lm \
		`pkg-config --cflags --libs check`
	 @echo
	 @echo
	 @echo "*****************************************************************"
	 @echo
	./${BUILD_PATH}/gps_tests
	 @echo
	 @echo "*****************************************************************"
	 @echo

