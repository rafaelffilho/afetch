#ifndef UTILS_H
#define UTILS_H
#include "config.h"

#include <libgen.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <unistd.h>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BLACKBG "\033[40m"
#define REDBG "\033[41m"
#define GREENBG "\033[42m"
#define YELLOWBG "\033[43m"
#define BLUEBG "\033[44m"
#define MAGENTABG "\033[45m"
#define CYANBG "\033[46m"
#define WHITEBG "\033[47m"

#define RESET "\033[0m"

#define initialized(x) (*(int *) (&x) != 0)

struct passwd  _passwd  = { 0 };
struct utsname _utsname = { 0 };
struct sysinfo _sysinfo = { 0 };

void user_and_host();
void kernel();
void uptime();
void shell();
void memory();
void swap();
void procs();
void loads();
void desktop();
void distro();

#endif    // !UTILS_H
