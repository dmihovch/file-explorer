all:
	gcc -o filexp src/main.c src/utils.c src/button.c -lncurses
clean:
	@rm -rf *.o filexp
run: filexp
	./filexp
vg: filexp
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./filexp
fsan:
	gcc -o filexp -g -fsanitize=address src/main.c src/utils.c src/button.c -lncurses
