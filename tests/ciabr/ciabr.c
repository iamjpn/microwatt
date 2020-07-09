#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "console.h"

#define TEST "Test "
#define PASS "PASS\n"
#define FAIL "FAIL\n"

extern int test_ciabr();
extern int test_ciabr2();

// i < 100
void print_test_number(int i)
{
	puts(TEST);
	putchar(48 + i/10);
	putchar(48 + i%10);
	putchar(':');
}

int main(void)
{
	int fail = 0;

	console_init();

	print_test_number(1);
	if (test_ciabr() != 0) {
		fail = 1;
		puts(FAIL);
	} else
		puts(PASS);

	print_test_number(2);
	if (test_ciabr2() != 0) {
		fail = 1;
		puts(FAIL);
	} else
		puts(PASS);

	return fail;
}
