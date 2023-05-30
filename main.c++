#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ClientOrder
{
    string clientOrderID;
    string instrument;
    int side;
    int quantity;
    double price;
};

struct ExchangeOrder
{
    string orderID;
    string clientOrderID;
    string instrument;
    int side;
    string exchangeStatus;
    int quantity;
    double price;
};

ExchangeOrder
ExchangeApp()
{
    ifstream ip("order.csv");

    if (!ip.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string clientOrderID;
    string instrument;
    string sSide;
    string sPrice;
    string sQuantity;

    ClientOrder orderBook[1000];
    int orderBookCount = 0;

    while (ip.good())
    {
        getline(ip, clientOrderID, ',');
        getline(ip, instrument, ',');
        getline(ip, sSide, ',');
        getline(ip, sPrice, ',');
        getline(ip, sQuantity, ',');

        int side = stoi(sSide);
        double price = stod(sPrice);
        int quantity = stoi(sQuantity);

        cout << "client order id: " << clientOrderID << endl;
        cout << "instrument: " << instrument << endl;
        cout << "side: " << side << endl;
        cout << "price: " << price << endl;
        cout << "quantity: " << quantity << endl;

        orderBook[orderBookCount].clientOrderID = clientOrderID;
        orderBook[orderBookCount].instrument = instrument;
        orderBook[orderBookCount].side = side;
        orderBook[orderBookCount].price = price;
        orderBook[orderBookCount].quantity = quantity;

        orderBookCount++;
    }

    int executionCount = 0;
    int numOrder = 1;
    ExchangeOrder exchangeOrderBook[2000];
    for (int i = 0; i <= orderBookCount; i++)
    {

        if (orderBook[i].side == 2)
        {
            exchangeOrderBook[executionCount].orderID = "ord" + to_string(numOrder);
            exchangeOrderBook[executionCount].clientOrderID = orderBook[i].clientOrderID;
            exchangeOrderBook[executionCount].instrument = orderBook[i].instrument;
            exchangeOrderBook[executionCount].side = orderBook[i].side;
            exchangeOrderBook[executionCount].exchangeStatus = "New";
            exchangeOrderBook[executionCount].quantity = orderBook[i].quantity;
            exchangeOrderBook[executionCount].price = orderBook[i].price;
        }
    }
}

int main()
{

    ip.close();
}