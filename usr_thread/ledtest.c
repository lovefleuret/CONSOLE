


#include "ledtest.h"
/*
 * ./ledtest /dev/100ask_led0 on
 * ./ledtest /dev/100ask_led0 off
 */

int fd;
char status;

int led_open(char* file)
{
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		printf("can not open file %s\n", file);
		return -1;
	}
	return fd;
}

void led_on(int fd)
{	
	status = 1;
	write(fd, &status, 1);
}


void led_off(int fd)
{	
	status = 0;
	write(fd, &status, 0);

}

void led_close(int fd)
{
	close(fd);
}




