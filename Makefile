RM=/bin/rm
CC=/usr/bin/gcc
OUTPUT_PATH=../build
APP=${OUTPUT_PATH}/app
CFLAGS=-g -Wall -O3
MAKE=/usr/bin/make

all:
	$(MAKE) -C src all

tests: all
	$(MAKE) -C tests all

