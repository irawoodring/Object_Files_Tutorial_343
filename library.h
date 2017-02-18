#ifndef __H_MY_LIBRARY__
#define __H_MY_LIBRARY__

struct Transaction {
	int id;
	long date;
	float amount;
	char* comments;
};

typedef struct Transaction Transaction;

typedef struct Record {
	int id;
	char* name;
	float balance;
	Transaction** transaction; 
} Record;

Transaction* getTransaction(int id);

#endif
