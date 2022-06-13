#include <iostream>
#include <string>
#include <iomanip>
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

     

    //Asks the user if the product is fragile
    std::cout << "Is the item fragile? (y = yes/n = no)" << setw(22) << setfill(dots) << dots << ":";
    cin >> FragileItem;     //Takes the user input

    switch (FragileItem)
    {
    case 'y':
    case 'Y':
        shipping = shipping + fragileShipping;
        break;

    case 'n':
    case 'N':
        break;
 
    default:
        cout << endl;
        cout << "Invalid entry, exiting"; //The code will break if the user puts anyhting other than Y/N
        return 0;

    }

    

    //Asks the user to enter the price of the product
    std::cout << "please enter your order total" << setw(30) << setfill(dots) << dots << ":";
    cin >> itemPrice; //Take the user input

    //Asks the user for shipping destination
    std::cout << "Please enter your destination. (usa/can/aus)" << setw(15) << setfill(dots) << dots << ":";
    cin >> destination; //Take the user input
    

    
    if (destination == "aus" || destination == "can" || destination == "usa" || destination == "USA" || destination == "CAN" || destination == "AUS") {
        cout << endl;  
    }
    else {
        cout << endl;
        cout << "Invalid entry, exiting";  //If the user puts anything other than usa/aus/can, the code will breeak.
        return 0;
    }





    // Setting the if else statements on pricing if the user inputs 'Y'
    
        if (FragileItem == 'y' || FragileItem == 'Y')  //Setting the if else statements when the user puts 'y'

        {

            if (destination == "USA" || destination == "usa")  ///Setting the if else statements when the user chooses usa for shipping
            {
                if (itemPrice < 50)
                    shipping = usaF + shipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = usaS + shipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = usaT + shipping;
                else
                    shipping = usaFree + shipping;
            }


            else if (destination == "CAN" || destination == "can")  ////Setting the if else statements when the user chooses canada for shipping
            {
                if (itemPrice < 50)
                    shipping = canF + shipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = canS + shipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = canT + shipping;
                else
                    shipping = canFree + shipping;
            }

            else if (destination == "AUS" || destination == "aus")  ////Setting the if else statements when the user chooses australia for shipping
            {
                if (itemPrice < 50)
                    shipping = ausF + shipping;
                else if (itemPrice >= 50.01 && itemPrice <= 100)
                    shipping = ausS + shipping;
                else if (itemPrice >= 100.01 && itemPrice <= 150)
                    shipping = ausT + shipping;
                else
                    shipping = ausFree + shipping;
            }
            


        }
        

       
        
        else if (FragileItem == 'n' || FragileItem == 'N')  ////Setting the if else statements when the user puts 'n'
        {
            if (destination == "USA" || destination == "usa")  //For USA
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

            else if (destination == "CAN" || destination == "can")  //For Canada
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
            else if (destination == "AUS" || destination == "aus")  //For Australia
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
         
        }
       

        


    std::cout << setw(60) << setfill(space) << space << endl;
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);  // Makes the user input in uppercase.
    std::transform(destination.begin(), destination.end(), destination.begin(), ::toupper); //Makes the destination in uppercase letters

    std::cout << "Your item is" << setw(30) << setfill(dots) << dots << userInput << endl;  //Prints the product name in uppercase
    std::cout << "Your shipping cost is" << setw(21) << setfill(dots) << dots << "$" << shipping << endl;  // Prints the shipping cost based on the destination
    std::cout << "You are shipping to" << setw(23) << setfill(dots) << dots << destination << endl;  //Prints the shipping destination
    std::cout << "Your total shipping costs are" << setw(13) << setfill(dots) << dots << "$" << (shipping + itemPrice) << endl; //Prints the total costs for shipping the product
    std::cout << setw(60) << setfill(space) << space << endl;
    std::cout << setw(42) << setfill(dash) << dash << "Thank you!" << endl; //Prints a thank you note before exiting. 
    
}