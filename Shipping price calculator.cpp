#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>


using namespace std;

char dots = '.';
char space = ' ';
char dash = '-';
char FragileItem;
double itemPrice;
double shipping;

// Setting values to the shipping pricing for the USA
double usaF = 6;
const double usaS = 9;
const double usaT = 12;
const double usaFree = 0;

// Setting values to the shipping pricing for Australia
const double ausF = 10;
const double ausS = 14;
const double ausT = 17;
const double ausFree = 0;

// Setting values to the shipping pricing for Canada
const double canF = 8;
const double canS = 12;
const double canT = 15;
const double canFree = 0;

//Modified version for github
const double marsF = 1000;
const double marsS = 2000;
const double marsT = 3000;
const double marsFree = 0;

const double fragileShipping = 2; // Extra shipping price for fragile items. 

int main()
{
   
    string destination;

    //Displays the welcome massage:
    std::cout << setw(60) << setfill(dots) << dots << endl;
    std::cout << "ITCS 2530 - programming assignment for week # 3" << endl;
    std::cout << setw(60) << setfill(dots) << dots << endl;
    std::cout << setw(60) << setfill(space) << space << endl;

    string userInput;

    //Asks the user to input a product name
    std::cout << "Please enter the item name (no spaces)" << setw(21) << setfill(dots) << dots << ":";
    cin >> userInput;  //Takes the user input

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);  // Makes the user input in uppercase. 

    //Asks the user if the product is fragile
    std::cout << "Is the item fragile? (y = yes/n = no)" << setw(22) << setfill(dots) << dots << ":";
    cin >> FragileItem;     //Takes the user input

    //Asks the user to enter the price of the product
    std::cout << "please enter your order total" << setw(30) << setfill(dots) << dots << ":";
    cin >> itemPrice; //Take the user input

    //Asks the user for shipping destination
    std::cout << "Please enter your destination. (usa/can/aus)" << setw(15) << setfill(dots) << dots << ":";
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper); //Makes the destination in uppercase letters


    string USA = "USA";
    string AUS = "AUS";
    string CAN = "CAN";
    string MARS = "MARS";


    // Setting the if else statements on pricing if the user inputs 'Y'
    
        if (FragileItem == 'y' || FragileItem == 'Y')

        {
            //Calculations based on shipping to the USA
            if (destination == USA)
            {
                if (itemPrice < 50)
                    shipping = usaF + fragileShipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = usaS + fragileShipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = usaT + fragileShipping;
                else
                    shipping = usaFree + fragileShipping;
            }

            //Calculations based on shipping to Canada
            if (destination == CAN)
            {
                if (itemPrice < 50)
                    shipping = canF + fragileShipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = canS + fragileShipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = canT + fragileShipping;
                else
                    shipping = canFree + fragileShipping;
            }
            //Calculations based on shipping to Australia
            if (destination == AUS)
            {
                if (itemPrice < 50)
                    shipping = ausF + fragileShipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = ausS + fragileShipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = ausT + fragileShipping;
                else
                    shipping = ausFree + fragileShipping;
            }
            /////////////////////////////////////////////////////////////////
            //Modified version:
            if (destination == MARS)
            {
                if (itemPrice < 50)
                    shipping = marsF + fragileShipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = marsS + fragileShipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping =  marsT + fragileShipping;
                else
                    shipping = marsFree + fragileShipping;
            }
            //////////////////////////////////////////////////////////////////
        }
            
        
    

    //Setting the if else statements on pricing if the user inputs 'N'
    else if (FragileItem == 'n' || FragileItem == 'N')
    {

    //Calculations based on shipping to the USA
        if (destination == USA)
        {
            if (itemPrice < 50)
                shipping = usaF;
            else if (itemPrice >= 50.01 && itemPrice <= 100)
                shipping = usaS;
            else if (itemPrice >= 100.01 && itemPrice <= 150)
                shipping = usaT;
            else
                shipping = usaFree;
        }

        //Calculations based on shipping to Canada
        if (destination == CAN)
        {
            if (itemPrice < 50)
                shipping = canF;
            else if (itemPrice >= 50.01 && itemPrice <= 100)
                shipping = canS;
            else if (itemPrice >= 100.01 && itemPrice <= 150)
                shipping = canT;
            else
                shipping = canFree;
        }

        //Calculations based on shipping to Australia
        if (destination == AUS)
        {
            if (itemPrice < 50)
                shipping = ausF;
            else if (itemPrice >= 50.01 && itemPrice <= 100)
                shipping = ausS;
            else if (itemPrice >= 100.01 && itemPrice <= 150)
                shipping = ausT;
            else
                shipping = ausFree;
        }

        if (destination == MARS)
        {
            if (itemPrice < 50)
                shipping = marsF;
            else if (itemPrice >= 50.01 && itemPrice <= 100)
                shipping = marsS;
            else if (itemPrice >= 100.01 && itemPrice <= 150)
                shipping = marsT;
            else
                shipping = marsFree;
        }
    }

    //If the user puts something else other than 'y'/'n', the code will stop.
    while (FragileItem == 'y' || FragileItem == 'Y' || FragileItem == 'n' || FragileItem == 'N')
        if (FragileItem != 'y' || FragileItem == 'Y' || FragileItem == 'n' || FragileItem == 'N')
        {
            cout << "Invalid entry, exiting";
            break;
        }


            std::cout << setw(60) << setfill(space) << space << endl;

            std::cout << "Your item is" << setw(30) << setfill(dots) << dots << userInput << endl;  //Prints the product name based on user input
            std::cout << "Your shipping cost is" << setw(21) << setfill(dots) << dots << "$" << shipping << endl;  // Calculates the shipping cost
            std::cout << "You are shipping to" << setw(23) << setfill(dots) << dots << destination << endl;  //Prints the shipping location based on user input
            std::cout << "Your total shipping costs are" << setw(13) << setfill(dots) << dots << "$" << (shipping + itemPrice) << endl; //Calcualtes total price with the shipping and the product price.
            std::cout << setw(60) << setfill(space) << space << endl; 
            std::cout << setw(42) << setfill(dash) << dash << "Thank you!" << endl; //Prints thank you note before exiting.
            
            
}
