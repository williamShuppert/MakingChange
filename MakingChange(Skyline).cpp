// MakingChange
// Will Shuppert
// To find the change to give back to the user
// 6/20/19

/* 
 Input list:
 what items to get
 cash given
 name
 run again
*/
/*
How to use:
order what you want
enter name
and cash given to see
how much money you get back in change
*/


#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

struct Item { // info needed for each item
	int count = 0;
	double price = 0;
	string name;
};

struct Menu {
	Item item[22];
	int clearOrder() {
		for (int i = 1;i <= 22;i++) {
			item[i].count = 0;
		}
		return 0;
	}
	void foodNamePrice() { // sets up item names and prices
		item[1].name = "Greek Salad";
		item[1].price = 4.49;
		item[2].name = "Buffalo Chicken Salad";
		item[2].price = 5.99;
		item[3].name = "Garden Salad";
		item[3].price = 3.79;
		item[4].name = "Greek Chicken Wrap";
		item[4].price = 4.39;
		item[5].name = "Buffalo Chicken Wrap";
		item[5].price = 4.39;
		item[6].name = "Classic Chicken Wrap";
		item[6].price = 4.39;
		item[7].name = "Chili Deluxe";
		item[7].price = 6.39;
		item[8].name = "Bean Mix Deluxe";
		item[8].price = 5.99;
		item[9].name = "Vegetarian Black Bean Deluxe";
		item[9].price = 5.99;
		item[10].name = "Chilito";
		item[10].price = 2.09;
		item[11].name = "Chili Cheese Fries";
		item[11].price = 4.99;
		item[12].name = "Fries";
		item[12].price = 1.99;
		item[13].name = "Funnel Cake Fries";
		item[13].price = 5.99;
		item[14].name = "Cheese Coney";
		item[14].price = 2.10;
		item[15].name = "Regular Coney";
		item[15].price = 2.00;
		item[16].name = "Chili Cheese Sandwich";
		item[16].price = 1.75;
		item[17].name = "Regular Chili Sandwich";
		item[17].price = 1.65;
		item[18].name = "3-Way";
		item[18].price = 5.49;
		item[19].name = "4-Way";
		item[19].price = 5.69;
		item[20].name = "5-Way";
		item[20].price = 5.89;
		item[21].name = "Chili Spaghetti";
		item[21].price = 4.69;
		item[22].name = "3-Way Black Beans and Rice";
		item[22].price = 5.49;
	}
	double calcTotal() {
		double total = 0;
		fixed;
		setprecision(2);
		for (int i = 1;i <= 22;i++) {
			total += item[i].price * item[i].count;
		}
		return total;
	}
};

Menu menu;

void border() { // makes the boarder for the menu
	for (int i = 1; i <= 26; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
		cout << "  ";
		if (i != 26) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153);
			cout << "  ";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << endl;
	for (int i = 1; i <= 26; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153);
		cout << "  ";
		if (i != 26) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
			cout << "  ";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << endl;
}

void showMenu() { // shows the rest of the menu
	border();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 241);
	cout << "                                                  ||                                                  " << endl;
	cout << "       ___________                                ||       ____________________________________       " << endl;
	cout << "      |           |          ___________          ||      |       What We're Famous For!       |      " << endl;
	cout << "      |  Salads   |         |           |         ||      |____________________________________|      " << endl;
	cout << "      |___________|         | Burritos  |         ||                                                  " << endl;
	cout << "                            |___________|         ||       ___________              ___________       " << endl;
	cout << "                                                  ||      |           |            |           |      " << endl;
	cout << "   1) Greek                                       ||      |  Coneys   |            |   Ways    |      " << endl;
	cout << "      $4.49              7) Chili Deluxe          ||      |___________|            |___________|      " << endl;
	cout << "                            $6.39                 ||                                                  " << endl;
	cout << "   2) Buffalo Chicken                             ||                                                  " << endl;
	cout << "      $5.99              8) Bean Mix Deluxe       ||   14) Cheese Coney         18) 3-Way             " << endl;
	cout << "                            $5.99                 ||       $2.10                    $5.49             " << endl;
	cout << "   3) Garden                                      ||                                                  " << endl;
	cout << "      $3.79              9) Vegetarian Black      ||   15) Regular Coney        19) 4-Way             " << endl;
	cout << "                            Bean Deluxe           ||       (Without Cheese)         $5.69             " << endl;
	cout << "       ___________          $5.99                 ||       $2.00                                      " << endl;
	cout << "      |           |                               ||      -----------------     20) 5-Way             " << endl;
	cout << "      |   Wraps   |      10) Chilito              ||                                $5.89             " << endl;
	cout << "      |___________|          $2.09                ||   16) Chili Cheese                               " << endl;
	cout << "                                                  ||       Sandwich             21) Chili Spaghetti   " << endl;
	cout << "                             ___________          ||       $1.75                    $4.69             " << endl;
	cout << "   4) Greek Chicken         |           |         ||                                                  " << endl;
	cout << "      $4.39                 |   Fries   |         ||   17) Regular Chili                              " << endl;
	cout << "                            |___________|         ||       Sandwich                                   " << endl;
	cout << "   5) Buffalo Chicken                             ||       $1.65                                      " << endl;
	cout << "      $4.39                                       ||                                                  " << endl;
	cout << "                         11) Chili Cheese Fries   ||                                                  " << endl;
	cout << "   6) Classic Chicken        $4.99                ||       _____________________________________      " << endl;
	cout << "      $4.39                                       ||      |           Vegetarian Way            |     " << endl;
	cout << "                         12) Fries                ||      |_____________________________________|     " << endl;
	cout << "                             $1.99                ||                                                  " << endl;
	cout << "                                                  ||                                                  " << endl;
	cout << "                         13) Funnel Cake Fries    ||         22) 3-Way Black Beans and Rice           " << endl;
	cout << "                             $5.99                ||           $5.49                                  " << endl;
	cout << "__________________________________________________||__________________________________________________" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "   23) Clear Order                          24) View Items                          0) Finish Order   " << endl;
}

void skylineLogo() { // skyline logo ascii art
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << R"(

                   ooo OOO OOOO OOOO OOO ooo
               oOO                           OOo
           oOO             l_                    OOo
        oOO                | |               |      OOo
      oOO     o    /\     |[] |          ____H        OOo
    oOO   ___l    [oo]   _| []|   _/|/| |[] []|  /\     OOo
   oOO   |[] |  __|  |__|[]    |_|[][]| |[] []|_[oo]     OOo
  oOO    | []|_|                    []|_|       |  |   ___OOo
 oOO_____|          _          _                   |__|    OOo
 oOO            __ | |        | | o                        OOo
 oOO           (   | |        | |     _  _    _            OOo
 oOO            `. |/_) |   | |/  |  / |/ |  |/            OOo
 oOO          (___)| \_/ \_/|/|__/|_/  |  |_/|__/          OOo
  oOO        ------------- /| --------------------        OOo
   oOO                  ___\|    _  _  _                 OOo
    oOO                / __| |_ (_)| |(_)               OOo
      oOO             | (__| ' \| || || |             OOo
        oOO            \___|_||_|_||_||_|           OOo
           oOO                                   OOo
               oOO                           OOo
                   OOO Ooo oooo oooo ooO OOO
                  
)";
}

void load() { // sets up items and loads skylilne logo
	menu.foodNamePrice();
	menu.clearOrder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 241);
	skylineLogo();

	system("pause");
	system("CLS");
}

int viewItems() {
	float total;

	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
	cout << right << setfill(' ') << setw(50) << " " << endl;
	cout << left << setfill(' ') << setw(50) << "  Your Order" << endl;
	cout << "  " << right << setfill('_') << setw(48) << "  " << endl;
	cout << right << setfill(' ') << setw(50) << " " << endl;
	for (int i = 1; i <= 22; i++) { // shows items ordered so far
		if (menu.item[i].count != 0) { // only shows items that have been ordered
			cout << "  " << left << setfill(' ') << setw(29) << menu.item[i].name << "     x" <<
				setw(3) << menu.item[i].count << "@  $" << right << setw(4) << menu.item[i].price << "  " << endl; // shows info on item thats readable
		}
	}
	cout << right << setw(50) << "   -----  " << endl;
	total = menu.calcTotal();
	cout << fixed << setprecision(2) << "  Sub Total                             $" << setw(7) << total << "  " << endl; // shows current subtotal
	cout << right << setfill(' ') << setw(50) << " " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	system("pause");
	return 0;
}

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	char runAgain; // if user wants to run again inputs y if not n
	int itemNum; // how many items ordered
	int count; // how many items the user wants
	float total; // total cost
	float received; // cash recieved from user
	float remaining; // updated amount of change to give back after each calculation
	float change; // change due
	int bill100; // number of bills/coins to give back
	int bill50;
	int bill20;
	int bill10;
	int bill5;
	int bill1;
	int coin25;
	int coin10;
	int coint5;
	int coin1;
	int penny;
	int quarter;
	int nickle;
	int dime;
	float tax; // how much user is paying for tax
	const float taxRate = .065f; // tax
	load(); // does starting tasks
	do {
		do {
			showMenu(); // displays menu
			cout << endl << " What would you like to eat (Enter Number)? ";
			cin >> itemNum; // user uses menu and inputs what they want
			if (itemNum == 23) {
				menu.clearOrder(); // gets rid of all previous orders
			}
			else if (itemNum == 24) {
				viewItems(); // look at current list of items ordered
			}
			else if (itemNum != 0) {
				cout << endl << " How many would you like? "; // gets how many they would like to order
				cin >> count;
				menu.item[itemNum].count += count; // updates there order
			}
			system("CLS");
		} while (itemNum != 0); // while they are still looking at the menu

		total = menu.calcTotal(); // finds subtotal
		tax = total * taxRate; // find tax
		total = total + tax; // finds total
		char name[20];
		cin.ignore();
		cout << " Name for order: ";
		cin.getline(name, 20); // gets full name for order
		do {
			cout << endl << " The total was $" << fixed << setprecision(2) << total << endl;
			cout << " Enter cash given: $";
			cin >> received;
			system("CLS");
		} while (received <= total); // can only continue if the have enough money to pay

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

		cout << "                                                  " << endl; // displays top of recipt with name
		cout << "  " << left << setfill(' ') << setw(48) << name << endl;
		cout << "  ______________________________________________  " << endl;
		cout << "                                                  " << endl;
		for (int i = 1; i <= 22; i++) { // shows all items ordered, how many, and the cost
			if (menu.item[i].count != 0) {

				string s = menu.item[i].name;
				char *a = new char[s.size() + 1];
				a[s.size()] = 0;
				memcpy(a, s.c_str(), s.size());

				cout << "  " << left << setfill(' ') << setw(29) << a << "     x" << setw(3) << menu.item[i].count << "@  $" << right << setw(4) << menu.item[i].price << "  " << endl;
			}
		}

		cout << "  Tax" << setw(39) << "+  $" << right << setw(4) << tax << "  " << endl; // shows tax
		cout << right << setw(50) << "   -----  " << endl;
		cout << "  Total                                 $" << setw(7) << total << "  " << endl; // shows total
		cout << "  " << right << setfill('_') << setw(46) << "" << "  " << endl;
		cout << right << setfill(' ') << setw(50) << " " << endl;
		cout << "  Total Cash Received                  $" << setfill(' ') << setw(8) << fixed << setprecision(2) << received << "  " << endl; // cash received
		cout << "  Total Purchase Price              -  $" << setfill(' ') << setw(8) << total << "  " << endl;
		cout << right << setw(50) << "--------  " << endl;
		change = received - (total); // find change due
		cout << "  Change Due                           $" << setfill(' ') << setw(8) << change << "  " << endl; // shows change due
		cout << right << setfill(' ') << setw(50) << " " << endl; // create gap
		cout << "  " << right << setfill('_') << setw(46) << "" << "  " << endl;
		cout << right << setfill(' ') << setw(50) << " " << endl;
		/*Find how many bills to give back*/
		bill100 = int(int(change) / 100.0);
		remaining = int(change) - (100.0 * bill100);
		bill50 = int((remaining) / 50.0);
		remaining = remaining - (50.0 * bill50);
		bill20 = int(int(remaining) / 20.0);
		remaining = remaining - (20.0 * bill20);
		bill10 = int(int(remaining) / 10.0);
		remaining = remaining - (10.0 * bill10);
		bill5 = int(int(remaining) / 5.0);
		remaining = remaining - (5.0 * bill5);
		bill1 = int(int(remaining) / 1.0);
		remaining = remaining - (1 * bill1);
		// fix for floating point rounding error I was having
		if (change * 100 > int(change * 100) + .5) {
			remaining = int(ceil(change * 100) - (int(change) * 100)); // using math.h
		}
		else {
			remaining = int(floor(change * 100) - (int(change) * 100));
		}
		// find how many coins to give back
		quarter = int(remaining / 25);
		remaining = remaining - (25 * quarter);
		dime = int(remaining / 10);
		remaining = remaining - (10 * dime);
		nickle = int(remaining / 5);
		remaining = remaining - (5 * nickle);
		penny = int(remaining / 1);
		remaining = remaining - (1 * penny);

		cout << left << setfill(' ') << setw(50) << "  Make Change" << endl;
		cout << right << setfill(' ') << setw(50) << " " << endl;
		cout << // summary of what to give back
			"  $100 Bill   x" << left << setw(5) << bill100 << "$" << setw(29) << 100.0 * bill100 << endl <<
			"  $50 Bill    x" << setw(5) << bill50 << "$" << setw(29) << 50.0 * bill50 << endl <<
			"  $20 Bill    x" << setw(5) << bill20 << "$" << setw(29) << 20.0 * bill20 << endl <<
			"  $10 Bill    x" << setw(5) << bill10 << "$" << setw(29) << 10.0 * bill10 << endl <<
			"  $5 Bill     x" << setw(5) << bill5 << "$" << setw(29) << 5.0 * bill5 << endl <<
			"  $1 Bill     x" << setw(5) << bill1 << "$" << setw(29) << 1.0 * bill1 << endl <<
			"  Quarters    x" << setw(5) << quarter << "$" << setw(29) << .25 * quarter << endl <<
			"  Dimes       x" << setw(5) << dime << "$" << setw(29) << .1 * dime << endl <<
			"  Nickles     x" << setw(5) << nickle << "$" << setw(29) << .05 * nickle << endl <<
			"  Pennies     x" << setw(5) << penny << "$" << setw(29) << .01 * penny << endl;

		cout << right << setfill(' ') << setw(50) << " " << endl;
		cout << "  Thank you " << left << setw(38) << name << endl; // thanks them and ends recipt
		cout << left << setfill(' ') << setw(50) << "  Have a great day!" << endl;
		cout << right << setfill(' ') << setw(50) << " " << endl;
		cout << "  Signature: X__________________________________  " << endl;
		cout << right << setfill(' ') << setw(50) << " " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		do {
			cout << endl << "Do you want to order another meal? (y/n)" << endl; // run agian?
			cin >> runAgain;
		} while (runAgain != 'y' && runAgain != 'Y' && runAgain != 'n' && runAgain != 'N'); // only allows letters y Y n N
		system("CLS");
		menu.clearOrder();
	} while (runAgain == 'y' || runAgain == 'Y');
}
	