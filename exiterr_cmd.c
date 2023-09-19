#include "main.h"
/**
* exiterr_cmd - Prints custom erro message to standard error
* @prog: Program name
* @prog1: function name
* @count: Command count
* @com: Command entered by user
* @errmsg: string
*
* Return: Void
*
*/

void exiterr_cmd(char *prog, char *prog1, int count, char *com, char *errmsg)
{
	put_string(com);
	put_string(": ");
	_putchar(count);
	put_string(": ");
	put_string(prog);
	put_string(": ");
	put_string(errmsg);
	put_string(prog1);
	_putchar('\n');
}
