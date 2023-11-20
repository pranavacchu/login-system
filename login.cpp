#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

string generatePassword(int length)
{
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*+";
    const int charsLength = chars.length();

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Ensure at least one of each character type
    string password = "";
    password += chars[rand() % 26];      // Lowercase letter
    password += chars[rand() % 26 + 26]; // Uppercase letter
    password += chars[rand() % 10 + 52]; // Digit
    password += chars[rand() % 12 + 62]; // Special character
    // Generate the remaining characters
    for (int i = 4; i < length; ++i)
    {
        password += chars[rand() % charsLength];
    }
    // Shuffle the password string
    random_shuffle(password.begin(), password.end());
    return password;
}

bool validFirstName(const string &firstName)
{
    return isalpha(firstName[0]) && isupper(firstName[0]);
}

bool validLastName(const string &lastName)
{
    return isalpha(lastName[0]) && isupper(lastName[0]);
}

bool validEmail(const string &email)
{
    size_t atPosition = email.find('@');
    size_t dotPosition = email.find('.');

    return atPosition != string::npos && dotPosition != string::npos &&
           atPosition < dotPosition && email.find(' ') == string::npos;
}

bool validPassword(const string &password)
{
    int digit = 0, uppercase = 0, lowercase = 0, specialChar = 0;

    for (char ch : password)
    {
        if (isdigit(ch))
        {
            digit = 1;
        }
        else if (islower(ch))
        {
            lowercase = 1;
        }
        else if (isupper(ch))
        {
            uppercase = 1;
        }
        else if (ch == '@' || ch == '#' || ch == '_')
        {
            specialChar = 1;
        }
    }

    return password.length() >= 8 && password.length() <= 15 &&
           digit && lowercase && uppercase && specialChar && password.find(' ') == string::npos;
}

void verificationCode()
{
    int code;

    cout << "We have sent a verification code to your email to confirm your account." << endl
         << "Please check your email." << endl;

    cout << "Email message: Your verification code is  ";
    srand(time(0));

    for (int i = 0; i <= 3; i++)
    {
        cout << rand() % 10;
    }
    cout << "\n";

    cout << "Enter the verification code here : \n";
    cin >> code;

    cout << "Your account has been verified." << endl;
}

void newUserRegistration()
{
    string NewRegister, firstName, lastName, email, password;
    int choice, passwordLength;

    cout << "New register?  \n(Note: if you are a new user type Yes, otherwise type No): ";

    cin >> NewRegister; // must be "yes" if he is a new user or "no" if he is not a new user
    cin.ignore();

    if (NewRegister == "Yes" || NewRegister == "yes")
    {
        cout << "First name : ";
        cin >> firstName;
        while (!validFirstName(firstName))
        {
            cout << "Invalid first name. Please try again: ";
            cin >> firstName;
        }

        cout << "Last name : ";
        cin >> lastName;
        while (!validLastName(lastName))
        {
            cout << "Invalid last name. Please try again: ";
            cin >> lastName;
        }

        cout << "Email : ";
        cin >> email;
        while (!validEmail(email))
        {
            cout << "Invalid email address. Please try again: ";
            cin >> email;
        }
        cout << "valid email address \n";

        cout << "Password : \n(Note: your password must be at least one digit, one special character, one uppercase letter, and one lowercase letter) \n";
        cout << "Would you like us to generate a strong password for you? \n(PRESS 1 FOR YES)\n(PRESS 2 FOR NO): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the desired password length (minimum 8 characters): ";
            cin >> passwordLength;
            if (passwordLength < 8)
            {
                cout << "Password length must be at least 8 characters." << endl;
                return;
            }
            password = generatePassword(passwordLength);
            cout << "Generated Password: " << password << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter your password: ";
            cin >> password;
            while (!validPassword(password))
            {
                cout << "Invalid password. Please try again: ";
                cin >> password;
            }
            cout << "valid password";
        }
        verificationCode();
        cout << "Registration completed!" << endl;
    }
    else if (NewRegister == "No" || NewRegister == "no") // have already an account
    {
        string Username, Password;
        cout << endl
             << "     Log in       " << endl
             << endl;
        cout << "Enter your username :" << endl;
        getline(cin, Username);

        cout << "Enter your password :" << endl;
        cin >> Password;

        cout << endl
             << "Login success!" << endl;
    }
}

void loginUser()
{
    string username, password;

    cin.ignore();
    cout << endl
         << "     Log in       " << endl
         << endl;
    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    cin >> password;

    cout << endl
         << "Login success!" << endl;
}

int main()
{
    cout << "Hey.." << endl;
    cout << "WELCOME TO OUR PROGRAM!" << endl;
    cout << "Let's begin the journey :) " << endl
         << endl;

    newUserRegistration();

    return 0;
}
