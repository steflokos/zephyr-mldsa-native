#include <stdint.h>
#include <string.h>
#include <zephyr/random/random.h>

void randombytes(uint8_t *out, size_t outlen) { sys_rand_get(out, outlen); }