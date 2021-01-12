#include <stdio.h>

#define FILENAME "file.txt"

int main() {
	FILE* fp = NULL;
	int count = 0;
	int i = 0;

	fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		return -1;
	}

	// moves file pointer to the end of file
	fseek(fp, 0, SEEK_END);
	
	// get the position of file pointer
	count = ftell(fp);

	while (i < count) {
		i++;
		fseek(fp, -i, SEEK_END);
		printf("%c", fgetc(fp));
	}

	printf("\n");
	fclose(fp);
	fp = NULL;

	return 0;
}