#include "main.h"

/**
 * handler - handler
 */

void handler(int sig __attribute__((unused)))
{
	write(1, "\n($) ", 5);
	signal(SIGINT, handler);
}
