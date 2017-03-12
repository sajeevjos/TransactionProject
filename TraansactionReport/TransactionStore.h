#ifndef TRANSACTIONSTORE_H
#define TRANSACTIONSTORE_H

#include<vector>
#include<string>
#include<ctime>
#include<map>
#include "Transaction.h"

using namespace std;

namespace TransactionReport
{
	struct TransactionAggregation
	{
		string entity;
		string trasactionType;
		double totalTransaction;
		bool operator<(const TransactionAggregation &rhs) const { return totalTransaction > rhs.totalTransaction; }
	};

	
	class TransactionStore
	{

	private:
		//Maps entity to a vector of all transactions of that entity
		map <string, vector<Transaction> > entityToTransactionsMap;
		//  MAP of "BUY/SELL" to TransactionAggregation
		map < string, vector <TransactionAggregation> > aggregatedTansPerEntityToTrTypeMap;

	public:
		TransactionStore();
		~TransactionStore();

		//Adds a transaction to the store
		void addTransaction(Transaction t);
		//Calculates the total incoming (sell) transactions on a given day
		double totalIncoming(string entity, time_t date);
		//Calculates the total outgoing (Buy) transactions on a given day
		double totalOutGoing(string entity, time_t date);
		//Gets the zise of the maps, the number of entities which have transactions
		int GetSizeOfMap() const{ return entityToTransactionsMap.size(); };
		//It returns the number of Transactions of an entity
		int GetNumOfTransactions(string entity) const; 
		//Calculates the total transactions for an entity and stores the results in a map
		//aggregatedTansPerEntityToTrTypeMap
		// FOO => ({Foo, Sell, 2225678.00}, {FOO, Buy, 55558889.00})
		
		void ProcessTransactions();
		//Sorts the Aggreated transactions based on the total tradeAmount
		// Input FOO => ({Foo, Sell, 2225678.00}, {FOO, Buy, 55558889.00})
		//output FOO => ({FOO, Buy, 55558889.00}, {Foo, Sell, 2225678.00})
		void RankEntitiesOnTrasactions();
		void ShowRankedTotalOutgoingTrans();
		void ShowRankedTotalIncomingTrans();
	};
}

#endif //TRANSACTIONSTORE_H