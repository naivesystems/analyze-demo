#include <stdint.h>

extern int16_t func_param_without_name(int16_t);

/*      12345678901234567890123456789012******* */
int32_t engine_exhaust_gas_temperature_raw;
int32_t engine_exhaust_gas_temperature_scaled;
int32_t engine_exhaust_gas_temp_raw;
int32_t engine_exhaust_gas_temp_scaled;

static uint32_t x[4] = {1, 2, 3};

void test_octal(void) {
	x[0] = 042;
}

#define START_VALUE 65024u

void test_wrap_around(void) {
	x[0] = START_VALUE + 512u;
}

int main(void) {
	union {
		int i;
		long long j;
	} a = {0};
	a.i = a.j; // test
	return 0;
}
