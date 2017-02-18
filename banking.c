#include <stdio.h>
#include <stdlib.h>
#include "library.h"

/**
 * Driver program
 * Creates a new record and a few
 * transactions.  Calls library
 * functions.
 */

int main(int argc, char** argv){
	Record record;
	record.id = 12345;
	record.name = "Kermit T. Frog";
	record.balance = 1234567.01;
	Transaction transactions[100];
	transactions[0].id = 0;
	transactions[0].date = 1487443558;
	transactions[0].amount = 1234567.01;
	transactions[0].comments = "Starting balance.";
	transactions[1].id = 1;
	transactions[1].date = 1487443590;
	transactions[1].amount = -1828.23;
	transactions[1].comments = "Lillypad Mortgage";
	record.num_transactions = 2;
	record.balance = record.balance + transactions[1].amount;
	record.transactions = transactions;
	print_record(&record);
	return 0;
}
