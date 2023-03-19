
build:
	gcc src/Example.c src/Region.c -o Example

leaks:
	g++ src/Example.c src/Region.c \
	-ggdb3 \
	-o example_leaks
	#./example_leaks
	valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind-out.txt \
			./example_leaks
