#include <stdio.h>
#include <stdlib.h>
#include "cafe.h"

int main(void) {
	int price_cents = 350;
	int balance_cents;

	preview_discount(350, 10); //expect 315
	apply_discount(price_cents, 10);
	printf("Here is the discount applied: %d\n", price_cents);
	

	return 0;
}
