#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <map>
#include <vector>


using namespace std;


namespace TransactionReport
{
	class Transaction
	{
	private:
		map<string, vector<string> > currencyToHolidayMap;
		string entity;
		string transaction;
		double agreedFx;
		string currency;
		time_t instructionDate;
		time_t instructionSettlementDate;
		double pricePerUnit;
		int numOfUnits;
		double tradeAmount;

	public:
		
		Transaction();
		~Transaction();
		Transaction(string e, string t, double fx, string c, time_t instrdate, double pu, int num);
		void Process();
		bool isTransactionDateHoliday(time_t date);

		//function to find the next working day
		//In scenarios where more than one consecutive holidays are there
		double GetTradeAmount() const { return tradeAmount; };
		time_t GetSettlementDate() const { return instructionSettlementDate; } ;
		string GetCurrency() const { return currency; } ;
		string GetEntity() const { return entity; } ;
		string GetTransactionType() const { return transaction; } ;
		time_t GetInstructionDate() const { return instructionDate; };
		double GetPricePerUnit() const { return pricePerUnit; };
		int GetNumOfUnits() const { return numOfUnits; };
	};

	struct lessThanTradeAmount
	{
		inline bool operator() (const Transaction& tr1, const Transaction& tr2)
		{
			return (tr1.GetTradeAmount() > tr2.GetTradeAmount());
		}
	};

}

#endif //TRANSACTION_H