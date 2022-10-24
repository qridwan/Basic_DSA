
// *===============================
// Make a system for Restaurant Bill Management.
// *===============================

#include <bits/stdc++.h>
using namespace std;
class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax = 0;
    bool checkCodeIsValid(int code)
    {
        if (code)
        {
            for (int i = 0; i < 12; i++)
            {
                if (this->food_item_codes[i] == code)
                {
                    return true;
                };
            }
        }
        return false;
    };
};

class Customer
{
public:
    int table_no;
    int items_code[12];
    string item_names[12];
    int item_prices[12];
    int items_quantity[12];
    int items = 0;

public:
    Customer(int table_no)
    {
        this->table_no = table_no;
        cout << "table is ready: >>>>>" << table_no << endl;
    };
    void add_cutomer_items(Restaurant *myRestaurant, int item_code[], int item_quantity[], int count)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                if (myRestaurant->food_item_codes[j] == item_code[i])
                {
                    this->item_prices[i] = myRestaurant->food_item_prices[j];
                    this->item_names[i] = myRestaurant->food_item_names[j];
                    break;
                }
            }

            this->items_code[i] = item_code[i];
            this->items_quantity[i] = item_quantity[i];
            items++;
        }
    };

    void calculate_order_price(Restaurant *myRestaurant, int item_code[], int item_quantity[], int count){

    };

    void print_all_orderItems(Restaurant *myRestaurant)
    {
        int totalPrice = 0;
        float tax = 0;
        cout
            << setw(60) << "\n\n_______________________________________________________________________________________________\n\n"
            << "BILL SUMMARRY"
            << "\n\n_______________________________________________________________________________________________\n\n";
        cout
            << left
            << setw(15)
            << "[Item Code]"
            << left
            << setw(25)
            << "[Item Name]"
            << left
            << setw(15)
            << "[Item Price]"
            << left
            << setw(20)
            << "[Item Quantity]"
            << left
            << setw(20)
            << "[Total Price]"
            << left
            << endl
            << endl;
        for (int i = 0; i < this->items; i++)
        {
            totalPrice = totalPrice + (this->items_quantity[i] * this->item_prices[i]);
            cout
                << left
                << setw(15)
                << this->items_code[i]
                << left
                << setw(25)
                << this->item_names[i]
                << left
                << setw(15)
                << this->item_prices[i]
                << left
                << setw(20)
                << this->items_quantity[i]
                << left
                << setw(20)
                << this->items_quantity[i] * this->item_prices[i]
                << left
                << endl;
        }
        tax = totalPrice * (0.05);                               // 5% tax rate
        myRestaurant->total_tax = myRestaurant->total_tax + tax; // adding total tax to Restaurant class;
        setprecision(2);
        cout << left
             << setw(75)
             << "TAX"
             << tax
             << endl;
        cout << "\n_______________________________________________________________________________________________\n";
        cout
            << left
            << setw(75)
            << "NET TOTAL"
            << left
            << totalPrice + tax << " Taka only "
            << left << endl
            << endl;
    }
};

void print_all_items_table(Restaurant *myRestaurent, int item)
{
    cout
        << setw(50) << "\n\n____________________________\n\n"
        << "MAKE BILL"
        << "\n\n____________________________\n\n";
    cout
        << left
        << setw(15)
        << "[Item Code]"
        << left
        << setw(25)
        << "[Item Name]"
        << left
        << setw(25)
        << "[Item Price]"
        << left
        << endl
        << endl;
    for (int i = 0; i < item; i++)
    {
        cout
            << left
            << setw(15)
            << myRestaurent->food_item_codes[i]
            << left
            << setw(25)
            << myRestaurent->food_item_names[i]
            << left
            << setw(25)
            << myRestaurent->food_item_prices[i]
            << left
            << endl;
    }

    cout << endl
         << endl;
};

int main()
{
    Restaurant *myRestaurant = new Restaurant();

    cout << "Restaurant Ready: " << endl;

    cout << "Enter how many items want to add: " << endl;
    int loop; // count for food items
    cin >> loop;

    for (int i = 0; i < loop; i++)
    {
        cout << "Input for food item ==>" << i + 1 << endl;
        cout << "CODE :" << endl;
        cin >> myRestaurant->food_item_codes[i];
        cout << "NAME : " << endl;
        cin.ignore();
        getline(cin, myRestaurant->food_item_names[i]);
        cout << "PRICE : " << endl;
        cin >> myRestaurant->food_item_prices[i];
    };
    print_all_items_table(myRestaurant, loop);
    int table_no, order_count;
    cout << "ENTER TABLE No: " << endl;
    cin >> table_no;
    Customer *customer1 = new Customer(table_no);
    cout << "No of items want to order: " << endl;
    cin >> order_count;
    int quantity[order_count], codes[order_count];

    for (int i = 0; i < order_count; i++)
    {
        bool isValid = false;
        while (!isValid)
        {
            cout << "Enter Item " << i + 1 << " Code: ";
            cin >> codes[i];
            if (!codes[i])
            {
                cout << "wrong code" << endl;
                continue;
            }
            isValid = myRestaurant->checkCodeIsValid(codes[i]);
            if (isValid)
            {
                break;
            }
            else
            {
                cout << "\n Invalid item code, please try again!\n"
                     << endl;
                continue;
            }
        }

        cout
            << "Enter Item " << i + 1 << " Quantity: ";
        cin >> quantity[i];
    }
    customer1->add_cutomer_items(myRestaurant, codes, quantity, order_count);
    customer1->print_all_orderItems(myRestaurant);

    return 0;
}

// *=============================
/*

- Take input of all food_item_codes, food_item_names and food_item_prices. Input is given below

12

170
Chicken Soup 1:2
260
171
Chicken Corn Soup 1:2
200
172
Thai Special Soup 1:2
300
260
Chicken Fried Rice 1:2
250
261
Egg Fried Rice 1:2
230
262
Prawn Fried Rice 1:2
300
310
Beef Mutton Kabab 1:1
150
311
Chicken Grill 1:4
340
450
Chicken Curry 1:3
550
451
Beef Special Curry 1:3
760
452
Chicken Sizzling 1:3
710
453
Beef Sizzling 1:3
970



- After taking input the system will start working. Its showing all food_item_codes  food_item_names and food_item_prices in a decent way.

- now take some inputs. You need to take the table number of the customer, and the number of items the customer has taken as input. After that, take all the item's code and quantity as input.


-  As you know the codes of food items, you need to find which code belongs to which food item. Then you need to show the table number, food item's code, name, price, quantity, and the total price of that food item.


- At last it calculate the tax amount that is 5% of the total amount. And last showing the net total that is the sum of tax and total amount.

- Finally it add this tax amount to the total_tax of the Restaurant class.




*/
//  *=============================
