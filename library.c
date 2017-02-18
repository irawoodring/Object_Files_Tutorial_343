#include <stdio.h>
#include "library.h"

Transaction** transactions;

Transaction* getTransaction(int id){
	return transactions[id];
}

void print_record(const Record* record){
	printf("========== %d ==========\n", record->id);
	printf("*\n*\n");
	printf("* Name: %s\n", record->name);
	printf("* Balance: $%.2f\n", record->balance);
	printf("*\n*\n");
	printf("* Showing %d transactions.\n", record->num_transactions);
	printf("*\n*\n");
	print_transactions(record->transactions, record->num_transactions);
	printf("===========================\n");
}

void print_transactions(const Transaction* transactions, int size){
	for(int i=0; i<size; i++){
		printf("%d:\t\t$%.2f\n", transactions[i].id, transactions[i].amount);
	}
}
