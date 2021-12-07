#include "main.h"

/**
 * handler - handler
 */

void handler(void)
{
	write(1, "\n($) ", 5);
	signal(SIGINT, handler);
}
