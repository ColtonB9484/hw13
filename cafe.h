#ifndef CAFE_H
#define CAFE_H

/*Error codes*/
#define	CAFE_OK 0
#define	CAFE_ERR_NULL -1
#define CAFE_ERR_BAD_AMOUNT -2
#define CAFE_ERR_INSUFFICIENT -3

void preview_discount(int price_cents, int percent_off);
void apply_discount(int *price_cents, int percent_off);
int charge(int valance_cents, int cost_cents, int *new_balance);
bool make_change(int paid_cents, int cost_cents, int *chang_out);
bool price_span(const int prices[], int n, int *min_out, int *max_out);
void print_line_item(const char *name, int price_cents);

#endif
