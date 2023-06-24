run-%:
	g++ --std=c++11 -O2 $*.cpp
	./a.out < input/$*.txt

debug-%:
	g++ -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector $*.cpp
	./a.out < input/$*.txt

gdb-%:
	g++ -g -O2 $*.cpp
	gdb -ex "run < input/$*.txt" ./a.out

valgrind-%:
	g++ -g -O2 $*.cpp
	valgrind --leak-check=full --show-leak-kinds=all ./a.out < input/$*.txt
