/*************
* Author: Colton Bettinson
* Functions to calculate and cafe transactions.
************/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "cafe.h"

void preview_discount(int price_cents, int percent_off) {
	int cents_off = price_cents * percent_off / 100;
	int discounted_price = price_cents - cents_off;
	printf("Discounted Price: %d cents\n", discount_price);
}

void apply_discount(int *price_cents, int percent_off) {
	if(price_cents != NULL && (percent_off >= 0 && percent_off <=  100)) {
		int cents_off = *price_cents * percent_off / 100;
		*price_cents -= cents_off;
	}
}

int charge(int balance_cents, int cost_cents, int *new_balance) {
	if(new_balance == NULL) {
		return CAFE_ERR_NULL;
	} else if(balance_cents < 0 || cost_cents < 0) {
		return CAFE_ERR_BAD_AMOUNT;
	} else if(cost_cents > balance_cents) {
		return CAFE_ERR_INSUFFICIENT;
	} else {
		*new_balance = balance_cents - cost_cents;
	}
	
	return CAFE_OK;
}

bool make_change(int paid_cents, int cost_cents, int *change_out) {
	if(change_out == NULL) {
		return false;
	} else if(paid_cents < 0 || cost_cents < 0 || paid_cents < cost_cents) {
		return false;
	} 
	*change_out = paid_cents - cost_cents;
	return true;
}

bool price_span(const int prices[], int n, int *min_out, int *max_out) {

	if(n <= 0) {
		return false;
	} else if(min_out == NULL || max_out == NULL) {
		return false;
	}
	
	*min_out = prices[0];
	*max_out = prices[0];
	for(int i = 0; i < n; i++) {
		if(prices[i] < *min_out) {
			*min_out = price[i];
		}

		if(prices[i] > *max_out) {
			*max_out = price[i];
		}
	}
	
	return true;
}

void print_line_item(const char *name, int price_cents) {
	printf("%s: %d cents", &name, price_cents);
}
