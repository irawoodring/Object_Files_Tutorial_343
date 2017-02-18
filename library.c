#include "library.h"

Transaction** transactions;

Transaction* getTransaction(int id){
	return transactions[id];
}
