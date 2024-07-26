#ifndef LEDTEST_H
#define LEDTEST_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int led_open(char* file);
void led_on(int fd);
void led_off(int fd);
void led_close(int fd);



#endif