//XOR Encryption

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void strip_newline(char* to_strip);
void encrypt_data(FILE* input_file, FILE* output_file, char *key);

int main(int argc, char* argv[])
{
	//Check for valid number of arguments
	if (argc != 3)
	{
		printf("Invalid number of arguments. %d arguments were supplied.\n", argc);
		printf("Usage: %s inputfile outputfile\n", argv[0]); //Usage: ./xortest inputfile outputfile
		exit(0);
	}
	
	FILE* input;
	FILE* output;

	//Open input and output files
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
		

	//Check input file
	if (input == NULL)
	{
		printf("Input file cannot be read.\n");
		exit(0);
	}
		
	//Check output file
	if (output == NULL)
	{
		printf("Output file cannot be written to.\n");
		exit(0);
	}

	//Key strings
	char *key = malloc(MAX_SIZE);

	//Prompt for key
	printf("Passphrase: ");

	//Read in key
	fgets(key, MAX_SIZE, stdin);

	printf("Encrypting %s\n", argv[1]);

	//strip newlines
	strip_newline(key);

	//XOR data and write it to file
	encrypt_data(input, output, key);
	
	printf("Encrypted data written to %s\n", argv[2]);

	//Release memory
	free(key);

	//Close files
	fclose(input);
	fclose(output);

	return 0;

}


void encrypt_data(FILE* input_file, FILE* output_file, char* key)
{
	int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
	int encrypt_byte;
	
	while( (encrypt_byte = fgetc(input_file)) != EOF) //Loop through each byte of file until EOF
	{
		//XOR the data and write it to a file
		fputc(encrypt_byte ^ key[key_count], output_file);

		//Increment key_count and start over if necessary
		key_count++;
		if(key_count == strlen(key))
			key_count = 0;
	}
}

void strip_newline(char* to_strip)
{
	//remove newlines
	if (to_strip[strlen(to_strip) - 1] == '\n')
	{
		to_strip[strlen(to_strip) - 1] = '\0';
	}
}
