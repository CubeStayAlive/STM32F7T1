/*
 * StdioAdapt.c
 *
 *  Created on: 10.05.2017
 *      Author: manni1user
 */

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>

//extern int __io_putchar(int ch) __attribute__((weak));
//extern int __io_getchar(void) __attribute__((weak));
//
//int __io_putchar(int ch)
//{
//	int i = 9;
//	i = i * 3;
//	return (0);
//}
//
//int __sf_putc_r(int ch)
//{
//	int i = 9;
//	i = i * 3;
//	return (0);
//}
//
//int __io_getchar(void)
//{
//	return (EOF);
//}
/*
 write
 Write a character to a file. `libc' subroutines will use this system routine for output to all files, including stdout
 Returns -1 on error or number of bytes sent
 */
int _write(int file, char *ptr, int len)
{
	int n;
	int DR=0;
	int errno;

	switch (file)
	{
	case STDOUT_FILENO: /*stdout*/
		for (n = 0; n < len; n++)
		{
			DR = (*ptr++ & (uint16_t)0x01FF);
		}
		break;
	case STDERR_FILENO: /* stderr */
		for (n = 0; n < len; n++)
		{
			DR = (*ptr++ & (uint16_t)0x01FF);
		}
		break;
	default:
		errno = EBADF;
		errno += DR;
		errno -= DR;
		return -1;
	}
	return len;
}
