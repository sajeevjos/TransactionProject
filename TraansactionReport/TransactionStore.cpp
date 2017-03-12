#include "stdafx.h"
#include "TransactionStore.h"
#include <algorithm>
#include <ctime>
#include <map>
#include <sstream>
#include <boost\date_time\posix_time\posix_time.hpp>
#include "DateUtil.h"

using namespace std;
using namespace TransactionReport;
using namespace boost::posix_time;

TransactionStore::TransactionStore()
{

}

TransactionStore::~TransactionStore()
{

}

// Adds transaction to the store
void TransactionStore::addTransaction(Transaction t)
{
	string entity = t.GetEntity();
	//check if the entry for that entity is there in the map.
	if (entityToTransactionsMap.find(entity) != entityToTransactionsMap.end())
	{
		//Take a reference to that vector transactions for that entity.
		vector<Transaction> & vTransactions = entityToTransactionsMap[entity];
		//Add the  given transaction to the vector.
		vTransactions.push_back(t);
	}
	// Scenario where the entity is not in the map.
	else
	{
		//Create a vector
		vector<Transaction> v;
		//Add the transaction
		v.push_back(t);
		// Make a pair of enity and its vector of transactions 
		entityToTransactionsMap.insert(make_pair(entity, v));
	}
}
	

//This function calculates total Incoming money for a particular
//entity and for a specific date.
//The the settlement date is truncated to so that the Hour, Minutes and Seconds is set to zero	
//The same is done for the given date
//This is done to find all the transactions on the same day.
// And all the transactions which are selling are added together
double TransactionStore::totalIncoming(string e, time_t d)
{
	double sum = 0;
	auto v = entityToTransactionsMap[e];
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		//find all the transaction which are of selling
		if (iter->GetTransactionType() == "S")
		{
			Transaction tr = *iter;
			//set the HR, MM and seconds to zero for getting all the trasactions for a day.
			time_t trimt = DateUtil::RemoveHourMinSec(d);
			time_t trtrimt = DateUtil::RemoveHourMinSec(tr.GetSettlementDate());

			//checking the given date and the date of the transaction are the same.
			//After setting the hour, minutes and seconds set to zero.
			if (trtrimt == trimt)
			{
				//Add all the transaction amount for that entity.
				sum += tr.GetTradeAmount();
			}

		}
	}
	return sum;
}

//This function calculates the Total out going Trasaction amount for a given day and entity
double TransactionStore::totalOutGoing(string entity, time_t date)
{
	double sum = 0;
	//Get the vector of transactions for a given entity.
	auto v = entityToTransactionsMap[entity];
	//walk thru the list of transactions to find the transactions on that day
	// which are out going
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		if (iter->GetTransactionType() == "B")
		{
			Transaction tr = *iter;
			// Remove the hour minutes and seconds from the time.
			//for both the settlement time and passed time.
			time_t trimt = DateUtil::RemoveHourMinSec(date);					
			time_t trtrimt = DateUtil::RemoveHourMinSec(tr.GetSettlementDate());
			if (trtrimt == trimt)
			{
				sum += tr.GetTradeAmount();
			}
		}
	}
	return sum;
}

//This function finds the number of transactions for the given entity.
int TransactionStore::GetNumOfTransactions(string entity) const
{
	//check if the entity is already in the map.
	if (entityToTransactionsMap.find(entity) != entityToTransactionsMap.end())
	{
		return entityToTransactionsMap.find(entity)->second.size();
	}
	{
		return 0;
	}
}



//contents of the map get sorted
//map ==> ( "B" ==> {TransactionAggregation{"foo", "B", 65000.0000), TransactionAggregation{"bar", "B", 33300.0000)})
//    ==> ( "S" ==> {TransactionAggregation{"foo", "S", 88800.0000), TransactionAggregation{"bar", "S", 99900.0000)})
//The list of aggregated Sells and Buys are sorted
void TransactionStore::RankEntitiesOnTrasactions()
{
	for (auto & m : aggregatedTansPerEntityToTrTypeMap)
	{
		vector<TransactionAggregation> & v = m.second;
		vector<TransactionAggregation>::iterator  begin = v.begin();
		vector<TransactionAggregation>::iterator  end = v.end();
		std::sort(begin, end);
	}	
}
//This function calls the Process Transaction in all the methods.
//Then stores the aggregated Sum for an entity in a structure TransactionAggregation
// TransactionAggregation{"foo", "B", 65000.0000)
//And this gets stored in map
//map ==> ( "B" ==> {TransactionAggregation{"foo", "B", 65000.0000), TransactionAggregation{"bar", "B", 33300.0000)})
//    ==> ( "S" ==> {TransactionAggregation{"foo", "S", 88800.0000), TransactionAggregation{"bar", "S", 99900.0000)})
void TransactionStore::ProcessTransactions()
{
	for (auto & ent : entityToTransactionsMap)
	{
		string entity = ent.first;
		auto v = ent.second;
		double sumB = 0;
		double sumS = 0;

		for (auto & tr : v)
		{
			//
			//entityToTotalTansactionsMap
			//Process all entities
			tr.Process();
			if (tr.GetTransactionType() == "B")
			{
				sumB += tr.GetTradeAmount();
			}
			else
			{
				sumS += tr.GetTradeAmount();
			}
		}

		// stroe the all aggregated results in a TransactionAggregation structure
		TransactionAggregation trAggBuy;
		TransactionAggregation trAggSell;
		trAggBuy.entity = entity;
		trAggBuy.totalTransaction = sumB;
		trAggBuy.trasactionType = "B";

		trAggSell.entity = entity;
		trAggSell.trasactionType = "S";
		trAggSell.totalTransaction = sumS;

		// Store that in map
		// "S" ==> Vector of TransactionAggregation
		if (aggregatedTansPerEntityToTrTypeMap.find("S") != aggregatedTansPerEntityToTrTypeMap.end())
		{
			//insert to the existing vector  if the entry for "Sell" already exist
			auto & v = aggregatedTansPerEntityToTrTypeMap["S"];
			v.push_back(trAggSell);
			
		}
		else
		{
			vector<TransactionAggregation> vSell;
			vSell.push_back(trAggSell);
			aggregatedTansPerEntityToTrTypeMap.insert(make_pair("S", vSell));
		}

		// Store that in map
		// "B" ==> Vector of TransactionAggregation
		if (aggregatedTansPerEntityToTrTypeMap.find("B") != aggregatedTansPerEntityToTrTypeMap.end())
		{
			auto & v = aggregatedTansPerEntityToTrTypeMap["B"];
			v.push_back(trAggBuy);

		}
		else
		{
			vector<TransactionAggregation> vBuy;
			vBuy.push_back(trAggBuy);
			aggregatedTansPerEntityToTrTypeMap.insert(make_pair("B", vBuy));
		}

	}	
}

void TransactionStore::ShowRankedTotalIncomingTrans()
{
	for (auto & m : aggregatedTansPerEntityToTrTypeMap)
	{
		vector<TransactionAggregation> & v = m.second;
		if (m.first == "S")
		{
			cout << "==================================================================" << endl;
			cout << "                    Incoming(Sell)  Transactions for entity In descending order    " << m.first << endl;
			for (auto tAgg : v)
			{
				cout << " Aggregation Type: " << tAgg.trasactionType << endl;
				cout << " Total Transaction : " << tAgg.totalTransaction << endl;
				cout << " Entity name : " << tAgg.entity << endl;
			}
			cout << "==================================================================" << endl;
		}
	}
}


void TransactionStore::ShowRankedTotalOutgoingTrans()
{
	for (auto & m : aggregatedTansPerEntityToTrTypeMap)
	{
		vector<TransactionAggregation> & v = m.second;
		if (m.first == "B")
		{
			cout << "==================================================================" << endl;
			cout << "                    OutGoing (Buy)  Transactions for entity In descending order    " << m.first << endl;
			for (auto tAgg : v)
			{
				cout << " Aggregation Type: " << tAgg.trasactionType << endl;
				cout << " Total Transaction : " << tAgg.totalTransaction << endl;
				cout << " Entity name : " << tAgg.entity << endl;
			}
			cout << "==================================================================" << endl;
		}
	}
}