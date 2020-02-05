#include <iostream>
#include <string>
#include <math.h>

using std::string;

// Creat a struct for storing numbers of items
struct ITEM
{
  int A;
  int B;
  int C;
  int D;
}item;

// Declaring functions
void init_item(); // Initialize the members of struct
void scan_item(string item_str);  // Scan the input string and determine the number of different items
int cal_price();  // Calculate the total price

int main() {
  init_item();  // Initialize the members of struct
  std::cout << "Please enter your items: ";
  string item_str;
  std::cin >> item_str; // Get input string
  int total_price = 0;
  scan_item(item_str);  // Scan the input string and determine the number of different items
  total_price = cal_price();  // Calculate the total price
  std::cout << "The total price of your items is " << total_price;  // Output total price
  return 0;
}

void init_item() {
  item.A = 0; // Set the value of all members to 0
  item.B = 0;
  item.C = 0;
  item.D = 0;
}

void scan_item(string item_str)
{
  for (int i = 0; i < item_str.length(); i++)
  {
    switch(item_str[i]) { // Using for loop and switch to count the number of different items
      case 'A': item.A++;
      break;
      case 'B': item.B++;
      break;
      case 'C': item.C++;
      break;
      case 'D': item.D++;
      break;
      default:
      break;
    }
  }
}

int cal_price()
{
  int price = 0;

  // Calculate the total price before discount
  price = item.A * 50 + item.B * 30 + item.C * 20 + item.D * 10;

  // Consider discounts for item A and B
  if (item.A >= 3) {
    price = price - floor(item.A/3) * 20;
  }
  if (item.B >= 2) {
    price = price - floor(item.B/2) * 23;
  }
  return price;
}