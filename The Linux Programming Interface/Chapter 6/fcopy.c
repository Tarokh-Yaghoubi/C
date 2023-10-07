


#include <stdio.h>
#include <unistd.h>

#include <string.h>
#include <sys/types.h>

enum RETURNS {

	SUCCESS,
	ERRLEN,
	ERRFIRSTFILE,
	ERRSECONDFILE,
	ERRWRITEISSUE
};

int
main(int argc, char* argv[])
{


	if (argc != 3 || (strcmp(argv[1], "--help")) == 0)
	{

		fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
		return ERRLEN;
	}

	FILE* source_file = fopen(argv[1], "rb");
	if (source_file == NULL) {

		perror("fopen");
		return ERRFIRSTFILE;
	}

	FILE* destination_file = fopen(argv[2], "wb");
	if (destination_file == NULL) {

		perror("fopen");
		fclose(source_file);
		return ERRSECONDFILE;
	}

	char buffer[100] = {0};
	size_t bytes_read;

	while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {

		size_t bytes_written = fwrite(buffer, 1, bytes_read, destination_file);
		if (bytes_written != bytes_read) {
			perror("fwrite");
			fclose(source_file);
			fclose(destination_file);
			return ERRWRITEISSUE;

		}

	}

	fclose(source_file);
	fclose(destination_file);

	return SUCCESS;
}



