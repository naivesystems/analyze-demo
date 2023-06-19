#include <stdio.h>

#include "demo_ctu.h"

static int y[4] = {1, 2, 3, 4};

/*   12345678901234567890123456789012******* */
void test_wrap_around_with_extremely_long_name(void) {
	y[0] = 512u;
}

void overrun2(int* const a) {
	int* p = &a[3];
	printf("%p", p);
}
