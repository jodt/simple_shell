#include "main.h"
void handler()
{
	write(1, "\n($) ", 5);
	signal(SIGINT, handler);
}
