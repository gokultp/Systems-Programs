#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( void ) {
	
	int number, pipe;

	printf("Trying to connect to server.\n");
	if(( pipe = open("arqfifo", O_RDONLY, 0 )) == -1 ) {
		perror("Error: open( ): ");
		return 1;
	}

	if( (read( pipe, &number, sizeof( int ) )) < 0 ) {
		perror("Erro: read( ): ");
		return 1;
	}
	printf("Connection succeeded.\n");
	printf("The number is: %d\n", number );
	close( pipe );	
	return 0;
}
