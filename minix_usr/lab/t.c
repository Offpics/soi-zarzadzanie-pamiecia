/* t.c - polecenie t wyswietla liczbe i rozmiary blokow wolnych */
#include <stdio.h>
#include <unistd.h>
#include <lib.h>
                                                                                
PUBLIC int hole_map( void *buffer, size_t nbytes)
{
	message msg; /* message used to pass parameters to a system call */
	msg.m1_i1 = nbytes; /* number of bytes requested from kernel space */

	 /* Data structure that will store requested information about free slots in MM. */
	msg.m1_p1 = (char *)buffer;

	return _syscall(MM, HOLE_MAP, &msg); /* do syscall */
}
                                                                                
int main( void ){
	unsigned int b[1024]; /* array that will store information about MM */
	unsigned int *p, a, l;
	int res; /* number of pairs returned from syscall */

	/* Load info about free slots in MM and get number of pairs. */
	res = hole_map( b, sizeof( b ) ); 
	printf( "[%d]\t", res ); /* print number of pairs */

	/* Print length and address of the holes. */
	p = b;
	while( *p ){
		l = *p++;
		a = *p++;
		printf("%d ", l);
	}
	printf( "\n" );
	return 0;
} 

