#ifndef AFETCH_CONFIG_H
#define AFETCH_CONFIG_H

#include "utils.h"

#define COLOR1 MAGENTA
#define COLOR2 WHITE

void (*items[])(void) = { user_and_host, kernel,  shell,  memory, swap, procs,
	                        loads,         desktop, distro, uptime, NULL };

#endif    // !AFETCH_CONFIG_H