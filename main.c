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
	int op_code;
	printf("\nCharge Correct:\n");
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge 350:\n");
	op_code = charge(balance_cents,350, &balance_cents);
	if(op_code == 0) {
		printf("Charge OK: ");
		printf("New Balance %d\n", balance_cents);
	} else {
		printf("Charge Failed: Code %d\n", op_code);
	}
	printf("\nCharge Insufficient Funds:\n");
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge 1000\n");
	op_code = charge(balance_cents, 1000, &balance_cents);
	if(op_code == 0) {
		printf("Charge OK: ");
		printf("New Balance %d\n", balance_cents);
	} else {
		printf("Charge Failed: Code %d\n", op_code);
	}
	printf("\nCharge Balance Negative:\n");
	balance_cents = -5;
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge 400\n");
	op_code = charge(balance_cents, 400, &balance_cents);
	if(op_code == 0) {
		printf("Charge OK: ");
		printf("New balance: %d\n", balance_cents);
	} else {
		printf("Charge Failed: Code %d\n", op_code);
	}
	printf("\nCharge Cost Negative:\n");
	balance_cents = 650;
	printf("Starting Balance: %d\n", balance_cents);
	printf("Charge -100\n");
	op_code = charge(balance_cents, -100, &balance_cents);
	if(op_code == 0 ) {
		printf("Charge OK: ");
		printf("New Balance: %d\n", balance_cents);
	} else {
		printf("Charge Failed: Code %d\n", op_code);
	}

	//test make_change
	printf("\nChange for $10 when cost is $5.50\n");
	if(make_change(1000, 550, &total_change)) {
		printf("Total Change: %d\n", total_change);
	} else {
		printf("Charge Failed\n");
	}
	total_change = 0;	//reset for test
	printf("\nChange for paid Cents Negative:\n");
	if(make_change(-4, 550, &total_change)) {
		printf("Total Change: %d\n", total_change);
	} else {
		printf("Charge Failed\n");
	}
	printf("\nChange for negative cost:\n");
	if(make_change(1000, -100, &total_change)) {
		printf("Total Change: %d\n", total_change);
	} else {
		printf("Charge Failed\n");
	}
	printf("\nChange for Paid less than cost:\n");
	if(make_change(100, 200, &total_change)) {
		printf("Total Change: %d\n", total_change);
	} else {
		printf("Charge Failed\n");
	}
	
	//test price_span
	printf("\nPrice Span OK: Min = 125, Max = 500\n");
	if(price_span(prices, 5, &min, &max)) {
		printf("Min: %d, Max %d\n", min, max);
	} else {
		printf("price_span failed:\n");
	}
	printf("\nPrice Span n = 0:\n");
	if(price_span(prices, 0, &min, &max)) {
		printf("Min: %d, Max %d\n", min, max);
	} else {
		printf("price_span failed\n");
	}

	//test print_line
	printf("\nprint_line_item test:\n");
	print_line_item(name, 350);

	return 0;
}
