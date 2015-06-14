#include <stdio.h>

int main() {
	int i;
	printf("#drawtiming -o full.jpg  full.txt -p 1000x100 -l 1 -v\n");
	printf("BLANK = 1, LATCH = 0, DATA = 0, CLOCK = 0.\n");
	printf("BLANK = 0.\n");
	for(i = 0;i < 12*2;++i) {
		printf("CLOCK = 0.\n");
		i % 3 ? printf("DATA = 1.\n") : printf("DATA = 0.\n");
		printf("CLOCK = 1.\n");
	}
	printf("CLOCK = 0.\n");
	printf("LATCH = 1.\n");
	printf("LATCH = 0.\n");
	return 0;
}
