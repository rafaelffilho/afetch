#include "config.h"
#include "utils.h"

#include <stdio.h>

int main() {

	int i = 0;
	while (items[i] != NULL) {
		items[i]();
		i -= -1;
	}

	return 0;
}

void memory() {
	if (!initialized(_sysinfo)) sysinfo(&_sysinfo);

	double used  = (_sysinfo.totalram - _sysinfo.freeram) / 1024 / 1024 / 1024.0;
	double total = _sysinfo.totalram / 1024 / 1024 / 1024.0;

	printf(COLOR1 "memory" COLOR2 ": %.2fG/%.2fG\n", used, total);
}

void swap() {
	if (!initialized(_sysinfo)) sysinfo(&_sysinfo);

	double used = (_sysinfo.totalswap - _sysinfo.freeswap) / 1024 / 1024 / 1024.0;
	double total = _sysinfo.totalswap / 1024 / 1024 / 1024.0;

	printf(COLOR1 "swap" COLOR2 ": %.2fG/%.2fG\n", used, total);
}

void shell() {
	if (!initialized(_passwd))
		memcpy(&_passwd, getpwuid(getuid()), sizeof(struct passwd));

	printf(COLOR1 "shell" COLOR2 ": %s\n" RESET, basename(_passwd.pw_shell));
}

void user_and_host() {
	if (!initialized(_passwd))
		memcpy(&_passwd, getpwuid(getuid()), sizeof(struct passwd));
	char host[256];

	gethostname(host, sizeof(host));

	printf(COLOR1 "%s" COLOR2 "@" COLOR1 "%s\n" RESET, _passwd.pw_name, host);
}

void kernel() {
	if (!initialized(_utsname)) uname(&_utsname);

	printf(COLOR1 "kernel" COLOR2 ": %s %s %s\n" RESET, _utsname.sysname,
	       _utsname.release, _utsname.machine);
}

void procs() {
	if (!initialized(_sysinfo)) sysinfo(&_sysinfo);

	printf(COLOR1 "procs" COLOR2 ": %d\n", _sysinfo.procs);
}

void distro() {
	FILE *p = popen("lsb_release -d | sed 's/\\w\\+:\\s\\+//'", "r");

	char sorry[256];

	fscanf(p, "%[^\n]s", sorry);

	printf(COLOR1 "distro" COLOR2 ": %s\n", sorry);
}

void desktop() {
	printf(COLOR1 "desktop" COLOR2 ": %s\n", getenv("XDG_SESSION_DESKTOP"));
}

void loads() {
	if (!initialized(_sysinfo)) sysinfo(&_sysinfo);

	double divisor = (1.0 / _sysinfo.procs) * .01;

	printf(COLOR1 "loads" COLOR2 ": %.2f %.2f %.2f\n",
	       _sysinfo.loads[0] * divisor, _sysinfo.loads[1] * divisor,
	       _sysinfo.loads[2] * divisor);
}

void uptime() {
	if (!initialized(_sysinfo)) sysinfo(&_sysinfo);

	long up      = _sysinfo.uptime;
	long days    = up / 86400;
	long hours   = up / 3600 % 24;
	long minutes = up % 3600 / 60;
	long seconds = up % 60;

	printf(COLOR1 "uptime" COLOR2 ": ");
	if (days) printf("%ldd ", days);
	if (hours) printf("%ldh ", hours);
	if (minutes) printf("%ldm ", minutes);
	printf("%lds\n" RESET, seconds);
}
