


#include <stdio.h>

int main(void) {


	FILE* tmpfile_ptr;

	tmpfile_ptr = tmpfile();	// create a temporary file

	if (tmpfile_ptr == NULL)
	{

		perror("Failed to create a temporary file");
		return 1;
	}

	/* write some data to the temporary file ...  */

	fprintf(tmpfile_ptr, "This is a temporary file example.\n");

	// Seek to the beginning of the file


	fseek(tmpfile_ptr, 0, SEEK_SET);

	// Read and print the content of the temporary file


	char buffer[100];

	while(fgets(buffer, sizeof(buffer), tmpfile_ptr) != NULL)
		printf("%s", buffer);


	fclose(tmpfile_ptr);

	return 0;


}


