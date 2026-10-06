#include <stdio.h>
#include <stdlib.h>
#include "cafe.h"

int main(void) {
	int price_cents = 350;
	int balance_cents = 1000;
	int total_change = 0;
	int prices[] = {350, 275, 400, 125, 500};
	int min;
	int max;
	char name[] = "Orange Juice";

	//test discount
	preview_discount(350, 10); //expect 315
	apply_discount(&price_cents, 10);
	printf("Here is the discount applied: %d\n", price_cents);

	//test charge
	printf("\nCharge OK:\n");
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge 350:\n");
	charge(balance_cents, 350, &balance_cents);
	printf("New Balance: %d\n", balance_cents);
	printf("\nCharge Insufficient Funds:\n");
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge 1000\n");
	printf("Code: %d\n", charge(balance_cents, 1000, &balance_cents));
	printf("New Balance: %d\n", balance_cents);
	printf("\nCharge Balance Negative:\n");
	balance_cents = -5;
	printf("Code: %d\n", charge(balance_cents, 400, &balance_cents));
	printf("New Balance: %d\n", balance_cents);
	printf("\nCharge Cost Negative:\n");
	balance_cents = 650;
	printf("Code %d\n", charge(balance_cents, -10, &balance_cents));
	printf("New Balance: %d\n", balance_cents);

	//test make_change
	printf("\nChange for $10 when cost is $5.50\n");
	if(make_change(1000, 550, &total_change)) {
		printf("Total Change: %d\n", total_change);
	}
	total_change = 0;	//reset for test
	printf("\nChange for paid Cents Negative:\n");
	if(make_change(-4, 550, &total_change)) {
		printf("Total Change: %d\n", total_change);
	}
	printf("Should not print change\n");
	printf("\nChange for negative cost:\n");
	if(make_change(1000, -100, &total_change)) {
		printf("Total Change: %d\n", total_change);
	}
	printf("Should not print change\n");
	printf("\nChange for Paid less than cost:\n");
	if(make_change(100, 200, &total_change)) {
		printf("Total Change: %d\n", total_change);
	}
	printf("Should not print change\n");

	//test price_span
	printf("\nPrice Span OK: Min = 125, Max = 500\n");
	if(price_span(prices, 5, &min, &max)) {
		printf("Min: %d, Max %d\n", min, max);
	}
	printf("\nPrice Span n = 0:\n");
	if(price_span(prices, 0, &min, &max)) {
		printf("Min: %d, Max %d\n", min, max);
	}
	printf("Should not print min/max\n");

	//test print_line
	printf("\nprint_line_item test:\n");
	print_line_item(name, 350);

	return 0;
}
