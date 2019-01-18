/* w.c - polecenie w przyjmuje jako argument 1 albo 0 */
/* wlaczajac/wylaczajac algorytm worst fit w systemie Minix */
#include <stdlib.h>
#include <unistd.h>
#include <lib.h>

/* Chose algorithm that alloc.c uses.
 * w=0 - first_fit,
 * w=1 - worst_fit.
 */
PUBLIC int worst_fit( int w )
{
	message msg; /* message used to pass parameters to a system call */
	msg.m1_i1 = w; 
	_syscall(MM, WORST_FIT, &msg);
}

int main( int argc, char *argv[] )
{
	if( argc < 2 )
		return 1;
	worst_fit( atoi( argv[1] ) );
	return 0;
}

