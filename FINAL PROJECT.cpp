#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Port;
class Ships;
class Containers;
class Accounts;
class Admin;
class Stock;
class Customer;
class Order;
class Payment;
class Cash;
class Credit;


//CLASS BY HAMEEZ
class Admin
{
	public: 
	string userID;
	string userName;
	string userPassword;
	string reg_date;
	string log_status;//valid customer
	
	static double totalprofits;

		Admin()  //default constructor
		{
			cout << "\t\t\tAdmin Details\n\n";
			cout << "\nID: ";
			cin >>userID;
			cout << "PASSWORD: ";
			cin >> userPassword;
			cout << "USERNAME: ";
			cin >> userName;
			cout << "DATE OF REGISTRATION IN DD/MM/YY FORMAT: ";
			cin >> reg_date;
		}
	
		
	bool verifylogin()
	{
		
	if(userID=="12345" && userPassword=="12345")
	{
		return true;
	}
	else
	{
		return false;
	}

	
}
};
double Admin::totalprofits = 0.0;


//CLASS BY ABDULLAH
class Port
{
	public:
		
		string portID;
		string portName;
		string date;
	
		
		Port()
		{
		cout << "\n\n\t\t\tPort Details\n\n";		
		cout << "Enter Port ID: ";
		cin >> portID;
		cout << "Enter Port Name: ";
		cin >> portName;
		cout << "Enter Date in DD/MM/YY: ";
		cin >> date;	
		system("CLS");
		}
		
		int NoOfShips()
		{
			int h;
			cout << "Enter number of ships expected to arrive: ";
			cin >> h;
			
		}
				
};


//CLASS BY ABDULLAH
class Ships : public Port
{
	public:
	
		string shipID;
		int NoOfContainerCarrying;
		double weight;
		string route;
		double dockTime;
		string location;
		double refuel_price;
		double price_by_time;
		double price_by_weight;
		
		static double totaldockprice;
		static int noOfships;
		
	friend class Accounts;
		
		Ships()
		
		:Port(){
			cout << "\n\n\t\t\tShips Details\n\n";
			cout << "\nEnter Ship ID: ";
			cin >> shipID;
			cout << "Enter Number of container carrying goods: ";
			cin >> NoOfContainerCarrying;
			cout << "Enter Weight of containers: ";
			cin >> weight;
			cout << "Enter route of this ship: ";
			cin >> route;
			cout << "Enter estimated Dock time in minutes: ";
			cin >> dockTime;
			cout << "Enter Location of this Ship: ";
			cin >> location;
			system("CLS");
			++noOfships;
		}
		
		void PriceByWeight()
		{
			cout<<"Enter price by weight: $";
			cin>>price_by_weight;
			cout<<"Enter weight: ";
			cin>>weight;
			price_by_weight=price_by_weight*weight;
			cout<<"Price by weight: $"<<price_by_weight << endl;
			Admin::totalprofits+=price_by_weight;
		}
		
		void DockTimePrice()
		{
			cout<<"Enter price by time per minute: $";
			cin>>price_by_time;
			price_by_time=price_by_time*dockTime;
			cout<<"The price for dock time per minute is: $"<<price_by_time << endl;
			totaldockprice+=price_by_time;
			Admin::totalprofits+=totaldockprice;
		
			
		}
		
		bool refuelled()
		{
			char c='a';
			cout << "\nIf ship is refuelled press y: ";
			cin >> c;
			if(c=='y' || c=='Y')
			return true;
			else 
			return false;
			
		}
		
		void refuelledPrice()
		{
			cout<<"Enter price/litre for refuelling: $";
			cin>>refuel_price;
			Admin::totalprofits+=refuel_price;
		}
		
};

int Ships::noOfships=0;
double Ships::totaldockprice=0.0;



//CLASS BY ABDULLAH
class Containers : public Ships
{
	public:
		
		string conID;
		string Goods;
		
		Containers()
		:Ships(){
			cout << "\n\n\t\t\tContainers Details\n\n";
			cout << "\nEnter Container ID: ";
			cin >> conID;
			system("CLS");

			Goods="chips";
			
		}
			
		bool custom_cleared()
		{
			char c;
			cout << "\nIf custom cleared press Y\nElse press anything: ";
			cin >> c;
			
			if(c=='y' || c=='Y')
				return true;
			else 
				return false;	
		}
		
		bool taxpayed()
		{
			string payed;
			
			cout << "\nIf tax is payed type 'yes'\nelse type anything: \n?";
			cin >> payed;
			
			if(payed=="yes" || payed == "Yes")
			return true;
			else 
			return false;
		}
		
};


//CLASS BY SHAYAN
class Customer
{	
	public:
	string custID;
	string custEmail;
	string custPassword;
	string custAddress;
	static int NoOfcust;	
		
	friend class Accounts;
	
	Customer()  //default constructor
	{
		cout << "\n\n\t\t\t\t\tCustomer Details\n\n";
		cout << "\nEnter Customer ID: ";
		cin >> custID;
		cout << "Enter Customer Password: ";
		cin >> custPassword;
		system("CLS");
		
		if(custPassword=="12345" && custID=="12345")
		{
			cout << "\n\t\t\t\t\t\t\tACCESS GRANTED" << endl;
		}
		else
		{
			cout << "\nInvalid ID and Password" << endl;
			exit(1);
		}
		
		cout << "\t\t\tCustomer Details\n\n";
		cout << "Enter Customer Email: ";
		cin >> custEmail;
		cout << "Enter Customer Address: ";
		cin >> custAddress;
					system("CLS");

		++NoOfcust;
	}


	void CustomerDetails()
		{
			cout << "\n\nDISPLAYING CUSTOMER DETAILS:-" << endl;
		cout << "\nCustomer ID: " << custID << endl;
		cout << "\nCustomer EMAIL: " << custEmail << endl;
		cout << "\nCustomer ADDRESS: " << custAddress << endl;	
	}
	

	
	void updatedetails()
	{
		cout << "\nWhat do you want to change?\npress 1 For ID\npress 2 for Email\npress 3 for Address\n?";
		int i;
		cin >>i;
		
		if(i==1)
		{
			cout << "\nEnter new user ID: ";
			cin >> custID;	
		}
		if(i==2)
		{
			cout <<"\nEnter new user Email: ";
			cin >> custEmail;
		}
		if(i==3)
		{
			cout << "\nEnter new user Address: ";
			cin >> custAddress;
		}
		
		cout << "\n\nAccount updated successfully" << endl;
	}
	
	~Customer()
	{
		--NoOfcust;
	}
};
 int Customer::NoOfcust=0;



class Stock; 
//CLASS BY SHAYAN
class Order:public Customer
{
	public:
		
    string OrderID;
	int qty;
	string description;
	string orderdate;
	double taxcharge; // keep it in percent 
//	double total;//inventory
//	double price;
	int i;
	
	public:
		
		Order() //default constructor
		:Customer(){
			system("CLS");
			cout << "\n\n\t\t\tOrder Details\n\n";
			cout<< "Enter Order ID: ";
			cin >> OrderID;
			cout << "Enter Description: ";
		cin >> description;
			cout << "Enter tax percent: ";
			cin >>taxcharge;
						system("CLS");

		}
		
		
		
		void UpdateOrder()
		{
		    char c{'y'};
		    while(c=='y' || c=='Y')
		    {
		    	system("CLS");
		    	cout << "\npress 1 To update Order ID \npress 2 To update order Date\npress 3 To update tax percent\n? " ;
		    	cin >> i;
		    	 
		    	
		    		if(i==1)
		    		{
					
		    			cout << "\nEnter Order ID to update: ";
		    			cin >> OrderID;
		    		}	
		    		else if(i==2)
		    			{
		    				cout << "\nEnter Date to update in DD/MM/YY: ";
		    			cin >> orderdate;

						}		    			
		    		else if(i==3)
		    			{
		    			cout << "\nEnter Tax percentage to update: ";
		    			cin >> taxcharge;
						}
		    			
				
		    	
		    	cout << "\nIf you want to update anything press y/Y: ";
		    	cin >> c;
			}
	}
		
		void calculateTotal();
		
	
		
};


//CLASS BY SHAYAN
class Payment:public Order
{
	public:
		
		double amount;
		string paymentType;
		
		Payment()
		:Order(){
			
		}
};


//CLASS BY SHAYAN
class Cash: public Payment
{
	public:
		char c;
		
		friend class Accounts;
		
		Cash() //DEFAULT CONSTRUCTOR
		:Payment(){
			
			
		}
		
	void cashpayed()
	{
		cout << "if Cash payed press Y \nElse press anything\? ";
		cin >> c;
		
		if(c=='Y' || c=='y')
			cout << "CASH PAYED SUCCESSFULLY"<< endl;
		else 
		{
			cout << "CASH NOT PAYED" << endl;
			exit(1);		
		}
	}
	
};



//CLASS BY SHAYAN
class Credit: public Payment
{
	private: 
	
	int cardNo;
	string cardType;
	string EXPDate;
	int BackNo;
	
	public:
		
	Credit() //default constructor
	:Payment(){
		cout << "\n\n\t\t\tCredit Card Details\n\n";
		cout << "Enter Card number: ";
		cin >> cardNo;
		cout << "Enter card type: ";
		cin >> cardType;
		cout << "Enter Expiry date: ";
		cin >> EXPDate;
		cout  << "Enter Back Number: ";
		cin >> BackNo;
					system("CLS");
		if(PAYAuthorized()==true)
		cout <<cardType <<" Card accepted for payment" << endl;
		else if(PAYAuthorized()==false)
		{
			cout << cardType<<" Card declined" << endl;
			exit(1);
		}
	}
	
	bool PAYAuthorized()
	{
		if(cardNo == 654321 && BackNo == 321 )
			return true;
		else 
			return false;
	}
	
	void printreceipt();

};

class Stock;
//CLASS BY ABDULLAH
class Accounts:public Containers
{
	public:
		
		Accounts()
		:Containers()
		{
			
		}
		Accounts(int i)
		{
			
		}
		
		
		void GetNoOfShips()
		{
			cout << "\nNumber of ships currently docked are: "<<  Ships::noOfships << endl;
		}
		
		void showgoods();
	
		
		void profitbydocks()
		{
			cout <<"\nTotal profit by docks is: $"<<Ships::totaldockprice << endl;	
		}
		
		void GetNoofCustomers()
		{
			cout <<"\nNumber Of Customers are: " <<Customer::NoOfcust << endl;
		}
		
		void totalprofits()
		{
			cout << "\ntotal profits: $" << Admin::totalprofits << endl;
		}
};


//CLASS BY ABDULLAH
class Stock:public Accounts
{
	public:
		Stock()
		:Accounts()	{
			
		}
		Stock(int i)
		:Accounts(1)
		{
			
		}
		
		
		friend class Order;
		friend class Accounts;
		
		static double priceperunit;
		static double pricetotal;
		static int qty;
		
		void restock()
		{
			int res;
			
			cout << "\nEnter the stock quantity: " ; 
			cin >> res;
			
			if(res>0)
			qty+=res;
		}
		
		bool Checkstock()
		{
			if(qty>0)
			return true;
			else if(qty==0)
			return false;
		}	
};
double Stock::pricetotal=0.0;
int Stock::qty=5;
double Stock::priceperunit=10.0;


void Order::calculateTotal()
		{
			
			int Qty;
			cout << "\nEnter Quantity you want to purchase: \nStock left: " << Stock::qty << "\n?";
			cin >> Qty;
			//inventory ki price se lo total and price
			Stock::pricetotal=Qty*Stock::priceperunit ;
			Stock::pricetotal+= Stock::pricetotal*taxcharge/100;
			Admin::totalprofits+=Stock::pricetotal;
			Stock::qty-=Qty;
			if(Stock::qty>0)
			cout << "Stock left: " << Stock::qty << endl;
			else if(Stock::qty>=0)
			{
				Stock::qty=0;
				cout << "Stock finished" << endl;
			}
		}

	void Credit::printreceipt()
	{
		system("CLS");
		cout << "Receipt printing for Customer ID: " << custID << endl<< endl;
		cout << "Order ID: " << OrderID << endl;
		cout << "Customer Address: " <<	custAddress << endl;
		cout <<"Quantity: " << 5-Stock::qty << endl;
		cout << "Total is: $" << Stock::pricetotal-(Stock::pricetotal*taxcharge/100)<< endl;
		cout << "Tax: $" << (Stock::pricetotal*taxcharge/100) << endl;
		cout << "Subtotal is: $" << (Stock::pricetotal*taxcharge/100)+Stock::pricetotal << endl;
		
	}

	void Accounts::showgoods()
		{
			cout << "\nCurrently there is only 1 GOOD available: " << Containers::Goods << "\nQuantity: "<< Stock::qty << endl; 
		}


//MAIN BY HAMEEZ
int main()
{
	
	Admin obj;
	
	system("CLS");
	if(obj.verifylogin()==true)
	{
		cout << "CORRECT USER ID AND PASSWORD ENTERED :) :)\nYou may continue...." << endl;
		
		//START PROJECT FROM HERE
		
		int i;
		cout << "\nWho are you?\npress 1 for Admin\npress 2 for Customer\n?";
		cin>> i;
		
		while(i==1 || i==2)
		{
		system("CLS");
		if(i==1)
		{
			//ADMIN DATA HAS 
			Stock obj;
			
			system("CLS");
			cout << "Enter the required data: \n" << endl;
			obj.NoOfShips();
			
			cout <<endl;
			obj.PriceByWeight();
			cout << endl;
			obj.DockTimePrice();
			cout << endl;
			
			if(obj.refuelled()==true)
				cout << obj.shipID<< " Refuelled Successfully" << endl;
			else if(obj.refuelled()==false)
				cout << obj.shipID << " Not refuelled successfully" << endl;
				
			cout << endl;
			obj.refuelledPrice();
			
			cout << endl;
			if(obj.custom_cleared()==true)
			cout << obj.conID << " is cleared from the customs" << endl;
			else if(obj.custom_cleared()==false)
			cout << obj.conID << " not cleared from customs" << endl;
			
			cout << endl;
			if(obj.taxpayed()==true)
			cout << obj.conID << "\n\n Tax is payed\nYou may proceed" << endl;
			else if(obj.taxpayed()==false)
			{
			cout << obj.conID << " Tax not paid\nYou may not proceed further " << endl;
			exit(1);
			}
			char q;
			cout << "\npress anything to continue: ";
			cin >> q;
			
			char c='y';
			
		while(c=='y'||c=='Y')
		{
			system("CLS");
			cout << "\t\t\t\t\t\t -:ENTER OPTION NUMBER TO SELECT:- " << endl;
			
			int j;
			cout << "\n1. Number of SHIPS standing at port\n2. Show GOODS\n3. Show total profits by DOCKS\n4. Show total number of CUSTOMERS\n5. Show total PROFITS\n6. Show the number of stocks left\n7. To RESTOCK\n?" ;
			cin >> j;
			
			cout << endl;
			if(j==1)
			{
				 obj.GetNoOfShips() ;
			}
			else if(j==2)
			{
				 obj.showgoods() ;
			}
			else if(j==3)
			{
				 obj.profitbydocks() ;
			}
			else if(j==4)
			{
				obj.GetNoofCustomers();
			}
			else if(j==5)
			{
				obj.totalprofits();
			}
			else if(j==6)
			{
				if(obj.Checkstock()==true)
				cout << "\nStock available: " << obj.qty << endl;
			
				else if(obj.Checkstock()==false)
				{
				cout << "\nStock finished :)" << endl;
				exit(1);
				}
			}
			else if(j==7)
			{
				obj.restock();
			}
			
			
				cout << "\nIf you want to reselect any option press 'y'\nElse press anything to continue further\n?";
				cin >>c;
		}
			
				system("CLS");
				cout << "\nDO you want to end the program?Or want it to continue!!\npress 1 for Admin\npress 2 for Customer\nPress anything to end\n?";
				cin>> i;
			
		}
		
		
		else if(i==2)
		{
			//CUSTOMER MAIN PROGRAM
			int k;
			cout << "\nWhat is you payment method?\npress 1 for CASH\npress 2 for Credit\n?";
			cin >> k;
			system("CLS");
			
			//
			if(k==1)
			{
				// cash details
				Cash obj;
				
				
				cout << "Enter your Order details";
				obj.calculateTotal();
			
				
				
				char c;
					
					cout <<"\nEnter 'Y' if you want to proceed: " ;
				cin >> c;
				
				system("CLS");
				
								
				while(c=='y' || c=='Y')
				{

					cout << "\npress 1 to display Customer Details\npress 2 to update Customer details\npress 3 to Update Order details\npress 4 to place more order\n? ";
				int h;
				cin >> h;
				system("CLS");

				if(h==1)
				{
					obj.CustomerDetails();

				}
				else if(h==2)
				{
					obj.updatedetails();

				}
				else if(h==3)
				{
					obj.UpdateOrder();
				}
				else if(h==4)
				{
					obj.calculateTotal();
				}
				
				cout << "\npress 'Y' to repeat any option\npress anything to proceed\n? ";
				cin >> c;
			}
				
				system("CLS");

				obj.cashpayed();
				cout << "press anything to continue: ";
				cin >> c;
			}
			
			//
			else if(k==2)
			{
				char c;
				// credit details
				Credit obj;
//				double total;
				
				cout << "\nEnter your order details: " << endl;
				obj.calculateTotal();
				
				
				cout <<"Enter 'Y' if you want to proceed: " ;
				cin >> c;
				
				while(c=='y' || c=='Y')
				{
				system("CLS");
				
				cout << "\npress 1 to display Customer Details\npress 2 to update Customer details\npress 3 to Update Order details\npress 4 to place more order\npress 5 to print receipt\n? ";
				int h;
				cin >> h;
				
				if(h==1)
				{
					obj.CustomerDetails();
				}
				else if(h==2)
				{
					obj.updatedetails();
				}
				else if(h==3)
				{
					obj.UpdateOrder();
				}
				else if(h==4)
				{
					obj.calculateTotal();
				}
				else if(h==5)
				{
					obj.printreceipt();
				}
			
				cout << "\nEnter Y if you want to reselect any option\npress anything to continue\n? ";
				cin >> c;
					system("CLS");
			}
				
			}
			
				system("CLS");
				cout << "\nDO you want to end the program?Or want it to continue!!\npress 1 for Admin\npress 2 for Customer\nPress anything to end\n? ";
				cin>> i;
		}
	
}
}
	else if(obj.verifylogin()==false)
	{
		cout << "INVALID USER_ID OR PASSWORD ENTERED ): " << endl;
	}
	

	
}

