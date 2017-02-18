#ifndef __H_MY_LIBRARY__
#define __H_MY_LIBRARY__

// Create a data structure to house
// a Transaction.
struct Transaction {
	int id;
	long date;
	float amount;
	char* comments;
};

// Use the typedef keyword to alias
// our data type from "struct Transaction"
// to "Transaction".  This allows us to
// declare a new one with
// Transaction var_name;
// Instead of 
// struct Transaction var_name;
typedef struct Transaction Transaction;

// Similarly, we can create a data
// structure and typedef it at the same time.
typedef struct Record {
	int id;
	char* name;
	float balance;
	int num_transactions;
	Transaction* transactions; 
} Record;

// A function that returns a Transaction*.
Transaction* getTransaction(int id);

// A function that prints a Transaction*.
void print_record(const Record* record);

// A function print all the Transactions from
// an array.
void print_transactions(const Transaction* transactions,int size);

#endif
