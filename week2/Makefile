.PHONY: status all * clean

SRCS	:= ${wildcard *.cpp}

CC	:= g++

RM	:= rm -rf

OUT	:= a.out

RUN	:= ./a.out

CFLAGS	:= -Wall -Wextra -Werror

all:	${SRCS}

${SRCS}:
	@echo "Running $@ ..."
	@${CC} ${CFLAGS} $@ -lm
	@${RUN}
	@${RM} ${OUT}
	@echo -e "\n=============================="

clean:
	@${RM} ${OUT}

