#include <stdlib.h>
#include <string.h>

// World's stupidest app

int main(int argc, char *argv[]) {
	char sludgeworm[150] = "alacritty --command nvim ";
	strcat(sludgeworm, argv[1]);
	system(sludgeworm);
	return 0;
}
