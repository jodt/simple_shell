#include "main.h"
void handler(void)
{
	write(1, "\n($) ", 5);
	signal(SIGINT, handler);
}
