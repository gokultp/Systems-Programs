#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( void ) {

	int number, pipe;

	if( (mkfifo("arqfifo", 0666 )) < 0 ) {
		perror("Error: mkfifo( ): ");
		return 1;
	}

	printf("Trying to connect to client.\n");
	if( (pipe = open("arqfifo", O_WRONLY )) < 1 ) {
		perror("Error: open( ): ");
		return 1;
	}

	//number = rand() % 100; 
	number = 256;
	printf("Connection succeeded.\n");
	printf("The number is: %d\n", number );

	if( (write( pipe, &number, sizeof( int ) )) < 0 ) {
		perror("Error: write( ): ");
		return 1;
	}

	close( pipe );	
	return 0;
}
