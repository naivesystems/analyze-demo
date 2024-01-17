#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "demo.h"
#include "demo_ctu.h"

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

void use_after_close(void) {
    FILE *fp;
    fp = tmpfile();
    if (fp != NULL) {
        (void) fclose(fp);
    }
    fprintf(fp, "?");
}

void not_release_dynamic_memory(void) {
    void *b = malloc(40);
}

void overrun(int* const a) {
	int* p = &a[4];
	printf("%p", p);
}

void overrun_when_calling_function() {
	int arr[3] = {1, 2, 3};
	int* x = arr;
	overrun(x);
}

void overrun_ctu() {
	int v = 1;
	int* x = &v;
	overrun2(x);
}

int extern_x;

int some_function() {
	if(extern_x > 0) {
		return 1;
	} else {
		return -1;
	}
}

void basic_negative() {
	int buff[1024];
	int x = some_function(); // some_function() might return -1.
	buff[x] = 0; // Defect: buffer underrun at buff[-1]
}

int main(void) {
	union {
		int i;
		long long j;
	} a = {0};
	a.i = a.j; 
	return 0;
}
