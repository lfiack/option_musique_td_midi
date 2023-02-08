/*
 * shell.h
 *
 *  Created on: 8 févr. 2023
 *      Author: laurentf
 */

#ifndef SHELL_SHELL_H_
#define SHELL_SHELL_H_

#include <stdint.h>

#define UART_DEVICE huart1

#define ARGC_MAX 8
#define BUFFER_SIZE 40
#define SHELL_FUNC_LIST_MAX_SIZE 64

void shell_init();
int shell_add(char c, int (* pfunc)(int argc, char ** argv), char * description);
int shell_process(void);

#endif /* SHELL_SHELL_H_ */
