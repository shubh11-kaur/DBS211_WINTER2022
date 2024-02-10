//Name: shubhdeep kaur
//Section: NBB
//Id: 172915217
//Email: shubhdeep-kaur2@myseneca.ca

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <occi.h>
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;


struct Payment
{
	int paymentID;
	string residentID;
	string paymentType;
	string amount;
	string paymentDate;
};

//displays the menu
int menu(void);

int findPayment(Connection* conn, int paymentID);
void displayPayment(Connection* conn, struct Payment pay);
void displayAllPayments(Connection* conn);

int main()
{

	Environment* env = nullptr;
	Connection* conn = nullptr;
	Payment pay;
	// User Variables
	string str;
	string usr = "dbs211_231nbb36";
	string pass = "18303769";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Connection is Successful!" << endl;
		cout << "Group - 6 Members: Luckshishaa, Gayatri Sharma, Shubdeep Sidhu" << endl;
		cout << "Individual Work : Shubhdeep Kaur" << endl;
		cout << "Project Assignment 1" << endl;


		int input = 0;

		do {
			input = menu();
			if (input == 1) {
				cout << "\n Entering choice to find Payment";
				int stno;
				cout << "\nEnter Payment ID:";
				cin >> stno;
				if (findPayment(conn, pyno) == 1)
				{
					cout << "\nValid Payment ID\n";
				}
				else
				{
					cout << "\nInvalid Payment ID\n";
				}
			}
			else if (input == 2)
			{
				cout << "\nEntering choice to display a Payment";
				displayPayment(conn, pay);
			}
			else if (input == 3)
			{
				cout << "\nEntering choice to display all Payments";
				displayAllPayments(conn);

			}

		} while (input != 4);

		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);

	}

	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}

//function definitions

//1 int menu(void);

int menu(void)
{
	int input = 0;
	cout << "\n**************************\n";
	cout << "HR MENU\n";
	cout << "**************************\n";
	cout << "\n1. Find Payment";
	cout << "\n2. Payment Report";
	cout << "\n3. Display All Payments";
	cout << "\n4. EXIT\n";
	cout << "\n**************************\n";
	cout << "Enter your choice: ";
	cin >> input;

	return input;

}

//2 int findGuest(Connection* conn, int paymentID);
int findPayment(Connection* conn, int paymentID)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT PAYMENTID, RESIDENTID, PAYMENTTYPE, AMOUNT , PAYMENTDATE FROM PAYMENTS WHERE PAYMENTID = " + to_string(paymentID));
	if (rs->next()) {
		return 1;
	}
	else {
		return 0;
	}

}

//3 void displayGuest(Connection * conn, struct Payment gst);

void displayPayment(Connection* conn, struct Payment pay)
{
	int paymentID;
	bool correctCode = false;
	do {
		cout << "\nEnter PaymentID: ";
		cin >> paymentID;
		if (!cin || findPayment(conn, paymentID) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid PaymentID\n";
		}

		else {
			correctCode = true;
			cout << "\nValid Input" << endl;
			cout << "\nSearch in table..!!" << endl;
			try {
				Statement* stmt2 = conn->createStatement("SELECT PAYMENTID, RESIDENTID, PAYMENTTYPE, AMOUNT , PAYMENTDATE FROM PAYMENTS WHERE PAYMENTID = " + to_string(paymentID));
				ResultSet* rs2 = stmt2->executeQuery();
				while (rs2->next())
				{
					cout << "\n--------------- Payment Information -------------- - " << endl;
					stu.paymentID = rs2->getInt(1);
					stu.residentID = rs2->getString(2);
					stu.paymentType = rs2->getString(3);
					stu.amount = rs2->getString(4);
					stu.paymentDate = rs2->getString(5);
					cout << "\nPayment ID Number: ";
					cout << stu.paymentID;
					cout << "\nResident ID: ";
					cout << stu.residentID;
					cout << "\nPayment Type: ";
					cout << stu.paymentType;
					cout << "\nAmount: ";
					cout << stu.amount;
					cout << "\nPayment Date: ";
					cout << stu.PaymentDate;
				}
				cout << endl;
				conn->terminateStatement(stmt2);
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}

	} while (!correctCode);

}


//4 void displayAllPayments(Connection * conn);

void displayAllPayments(Connection* conn)
{
	try {
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs3 = stmt3->executeQuery("SELECT PAYMENTID, RESIDENTID, PAYMENTTYPE, AMOUNT , PAYMENTDATE FROM PAYMENTS");
		cout << setw(25) << "\n\nPAYMENTID" << setw(20) << "RESIDENTID" << setw(20) << "PAYMENTTYPE" << setw(17) << "AMOUNT" << setw(17) << "PAYMENTDATE" << endl;
		Payment pay2;
		while (rs3->next()) {
			stu2.paymentID = rs3->getInt(1);
			stu2.residentID = rs3->getString(2);
			stu2.paymentType = rs3->getString(3);
			stu2.amount = rs3->getString(4);
			stu2.paymentDate = rs3->getString(5);

			cout << left << setw(25);
			cout << stu2.paymentID;
			cout << left << setw(23);
			cout << stu2.residentID;
			cout << left << setw(18);

			cout << stu2.paymentType;
			cout << left << setw(12);
			cout << stu2.amount;
			cout << left << setw(12);
			cout << stu2.paymentDate;
			cout << left << setw(12);
			cout << endl;
		}
		cout << endl;
		conn->terminateStatement(stmt3);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}