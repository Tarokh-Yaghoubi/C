// Use fopen to open an existing file or create a new file 
// This call will initialize an object of the type FILE

/* FILE *fopen(const char * filename , const char * mode) */


// use the fclose function to close a file | the fclose function returns zero on success
// fclose shall return EOF if an error exists in the file .
// EOF is a constant defined in the header <stdio.h>

/* simplest function to write individual characters to a stream : fputc() */
// fputc() returns the written character on success , otherwise returns EOF if there is an ERR	


/*

# Use the Following Functions to write a null-terminated string into a stream :

	fputs() -> writes the string 's' to the output stream *fp (returns a non-negative value on success - otherwise EOF)
	fprintf() -> You can also use this function to write a string into a file


*/

// fgetc() -> file get character
// fgets() -> file get string
// fscanf() -> file scan - it stop when it meets a white space
// 
// Example 

#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{

	FILE* fp;
	FILE* fp2;

	int c;

	char fname_1[1024 + 1] = { 0 };
	char fname_2[1024 + 1] = { 0 };

	// printf("argv 1: % s", argv[0]); // command param1 param2 
	// printf("argv 2: % s", argv[1]); 
	// printf("argc : %d", argc);
	/*
	if (argc != 3)
	{
		printf("single or multiple args detected \n");
		return -1;
	}
	*/
	if (argc > 3)
	{
		printf("Multiple arguments detected in STDIN \n");
		return -1;
	}
	else if (argc < 3)
	{
		printf("Less that 2 args entered \n");
		return -2;
	}

	strcpy(fname_1, argv[1]);
	strcpy(fname_2, argv[2]);


	fp = fopen(fname_1, "r");
	fp2 = fopen(fname_2, "w+");

	if (fp != NULL && fp2 != NULL)
	{

		while (!feof(fp))
		{
			c = fgetc(fp);
			fputc(c, fp2);
		}

	}
	else
	{
		printf("couldnt open the file \n");
		
		if (fp != NULL)
			fclose(fp);
		if (fp2 != NULL)
			fclose(fp2);
		
		return -1;
	}
	

	fclose(fp);
	fclose(fp2);

	return 0;
}
