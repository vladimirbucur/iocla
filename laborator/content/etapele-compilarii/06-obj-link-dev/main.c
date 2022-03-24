extern qty;

int main(void)
{
	int price;
	price=set_price(21);
	print_price(price);
	qty=2*price;
	print_quantity(&qty);
	return 0;
}