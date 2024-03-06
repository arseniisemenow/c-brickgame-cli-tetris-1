CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS =
LIBRARIES = -lncurses
TEST_FLAGS      := -lcheck -lm -lpthread
GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log

DIST_DIR :=archive

BACKEND := brick_game/tetris/backend/block/block.c \
			brick_game/tetris/backend/board/board.c \
			brick_game/tetris/backend/cell/cell.c \
			brick_game/tetris/backend/collisions_checker/collisions_checker.c \
			brick_game/tetris/backend/game_status/game_status.c \
			brick_game/tetris/backend/parameters/parameters.c \
			brick_game/tetris/backend/player/player_board/player_board.c \
			brick_game/tetris/backend/player/player.c \
			brick_game/tetris/backend/records/records.c \
			brick_game/tetris/backend/backend.c
COMMON :=	brick_game/tetris/common/colors.c
DEBUGGER := brick_game/tetris/debugger/debugger.c
TETRIS :=brick_game/tetris/common/color_handler.c \
			brick_game/tetris/fsm/fsm_matrix.c \
 			brick_game/tetris/tetris/tetris.c \
 			brick_game/tetris/time_handler/time_handler.c



FRONTEND:=gui/cli/frontend.c


OPEN_COMMAND =open
ifeq ($(OS), Linux)
	OPEN_COMMAND=xdg-open
else
	OPEN_COMMAND=open
endif
#OPEN_COMMAND=xdg-open # if Fedora, need to uncomment


all: install run

install: ${BACKEND}  ${COMMON} ${TETRIS} ${FRONTEND}
		$(CC) ${CFLAGS} $(LIBRARIES) $^ -o tetris.out

uninstall:
	@rm -f tetris.out
	@echo "Uninstallation is finished"

run:
	./tetris.out

dvi:
	${OPEN_COMMAND} ../dvi/README.html

dist: clean_dist
	cd ../ && mkdir -p ${DIST_DIR}
	cd ../ && cp -rf src/brick_game ${DIST_DIR}/brick_game
	cd ../ && cp -rf src/gui ${DIST_DIR}/gui
	cd ../ && cp -rf src/Makefile ${DIST_DIR}/
	cd ../ && tar -czvf archive.tar.gz ${DIST_DIR}
	cd ../ && rm -rf ${DIST_DIR}
dist_unpack:
	cd ../ && tar -xzvf archive.tar.gz

test:
	@mkdir -p ../tests/build
	gcc ../tests/main_test.c ${CFLAGS} $(BACKEND) ${COMMON} $(TEST_FLAGS) -o ./test.out
	./test.out

test_valgrind:
	@mkdir -p ../tests/build
	gcc ../tests/main_test.c ${CFLAGS} $(BACKEND) ${COMMON} $(TEST_FLAGS) -o ./test.out
	valgrind ${VALGRIND_FLAGS} ./test.out

gcov_report:
	@mkdir -p report
	gcc ../tests/main_test.c $(BACKEND) ${COMMON} $(TEST_FLAGS) $(GCOV_FLAGS) -o ./gcov_report.out
	./gcov_report.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	${OPEN_COMMAND} ./report/index.html
	make clean_gcov


cppcheck:
	@find .. -type f -name "*.c" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@find .. -type f -name "*.h" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@echo "Cppcheck is finished"

style_check:
	@find .. -type f -name "*.c" -exec clang-format -n -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -n -style=Google {} \;
	@echo "Clang format style check is finished"
style:
	@find .. -type f -name "*.c" -exec clang-format -i -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -i -style=Google {} \;
	@echo "Clang format style apply is finished"

clean: clean_project clean_static_lib clean_log clean_exec clean_obj clean_gcov clean_lcov clean_lcov_report clean_dist
	@echo "Clean finished"

clean_project:
	@find .. -type f -name "*.records" -exec rm {} \;


clean_dist:
	@cd ../ && rm -rf archive
	@cd ../ && rm -rf archive.tar.gz
clean_after_building:
	@rm -rf ${OBJ_DIR}
clean_static_lib:
	@find .. -type f -name "*.a" -exec rm {} \;
clean_log:
	@find .. -type f -name "*.log" -exec rm {} \;
clean_exec:
	@find .. -type f -name "*.out" -exec rm {} \;
clean_obj:
	@find .. -type f -name "*.o" -exec rm {} \;
clean_gcov:
	@find .. -type f -name "*.gcda" -exec rm {} \;
	@find .. -type f -name "*.gcno" -exec rm {} \;
clean_lcov:
	@find .. -type f -name "*.info" -exec rm {} \;
clean_lcov_report:
	@rm -rf report
