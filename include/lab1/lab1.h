#pragma once
#include "stdint.h"
#include "stdio.h"


void xorshift128() {
	uint32_t seed;
	printf("Write seed: ");
	scanf("%u", &seed);
	uint32_t state[4] = { 34635464, 35435455, 38465793, 12535454 };
	state[0] = seed;
	printf("By seed %u was generated 100 numbers:\n", seed);
	for (int i = 0; i < 100; i++) {
		uint32_t t = state[3];
		uint32_t const s = state[0];
		state[3] = state[2];
		state[2] = state[1];
		state[0] = s;
		t ^= t << 11;
		t ^= t >> 8;
		state[0] = t ^ s ^ (s >> 19);
		printf("%u\n", state[0]);
	}
}


void xorshift128_simplified() {
	uint32_t seed;
	printf("Write seed: ");
	scanf("%u", &seed);
	uint32_t state[4] = { 34635464, 35435455, 38465793, 12535454 };
	state[0] = seed;
	printf("By seed %u was generated 100 numbers:\n", seed);
	uint32_t t;
	uint32_t temp;
	int i = 0;
	cycle_start:
		t = state[3];
		uint32_t const s = state[0];
		state[3] = state[2];
		state[2] = state[1];
		state[0] = s;
		temp = t;
		t <<= 11;
		t ^= temp;
		temp = t;
		t >>= 8;
		t ^= temp;
		state[0] = t;
		state[0] ^= s;
		temp = s;
		temp >>= 19;
		state[0] ^= temp;
		printf("%u\n", state[0]);
		i += 1;
		if (i < 100) goto cycle_start;
}