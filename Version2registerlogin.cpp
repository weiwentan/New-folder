#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Test comment for git

class UserAuthen
{
	public:
	string username;
	string password;
  	string inputUsername;
    string inputPassword;
    
    // User registration
    void userRegister()
    {
    	ofstream usersFile ("userData.txt");

        if (!usersFile.is_open())
        {
            usersFile.open("userData.txt");
        }

        usersFile << username << " " << password << endl;

        usersFile.close();
    }

    // Initialize user registration
    void userRegisterInterface()
    {
        cout << "Welcome System Administrator" << endl;
		cout << "Please enter a new username: ";
		cin >> username;
		cin.clear();
      	cin.ignore(10000,'\n');

        cout << "Please enter a new password: ";
        cin >> password;
		cin.clear();
      	cin.ignore(10000,'\n');

        userRegister();
    }

    // User login function
    void login()
    {
		cout << endl;
        cout << "Please enter your username: ";
		cin >> inputUsername;
		cin.clear();
      	cin.ignore(10000,'\n');

        cout << "Please enter your password: ";
        cin >> inputPassword;
		cin.clear();
      	cin.ignore(10000,'\n');
		cout << endl;
		
        string userAndPass = inputUsername + " " + inputPassword; // combine username and password pattern
		
        int offset; 
        string line;
		
		
        ifstream usersFile;
        usersFile.open ("userData.txt");


     	bool found = false;
      	if(usersFile.is_open()) 
		{
        	while(getline(usersFile,line) && !found) 
			{
            	if (line.compare(userAndPass) == 0) 
				{ 
                  found = true; //if there is a pattern inside the file that matches the search pattern, found becomes true
              	}
          	}
			
			usersFile.close(); 	//close the file before recursivly opening it again later
		
			if(found) 			//login successful message
			{
			cout << "Login successful" << endl;
			cout << "Welcome " << inputUsername << endl;
			}
		
			else 
			{
			cout << endl;
			cout << "Incorrect Username and/or Password!" << endl;
			cout << "Please register with the system administrator if you do not have an account";
			cout << endl << endl;
			login(); 			//go back to login page
			}	 
      	}
    }

};

// Main program
int main() {
    
    UserAuthen user1;
    ifstream usersFile("userData.txt");
    long begin, end;

    if (usersFile.good())		//ios::good, no error finding the usersFile
    {
        cout << "File userData.txt found!";
		cout << endl;
    }
    
    else 
	{
        user1.userRegisterInterface();
    }


    if(usersFile.is_open())
    {
        begin = usersFile.tellg();
        usersFile.seekg (0, ios::end);

        end = usersFile.tellg();
        usersFile.close();

        if(begin == end)
        {
            user1.userRegister();	//No record found in the database 
        }

        else
        {
        	cout << "Do you want to create user or login?" << endl;
            //user1.login();			//run login function if the data base is not empty
        }
    }
}



