/* Author:              Bango
 * Project:             CRYPTOcol
 * Date of completion:  4/3/13
 * Submitted in partial fulfillment for the requirements
 * of Programming Foundations I, University of Arkansas
 *
 * ABSTRACT: CLI Program written in C++ to render files and user input with Fully Homomorphic Encryption (FHE) and Decryption
 * Since this is my 5th programming project *ever*, the FHE used is a simple substitution 'caesar' cipher
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

//the most important variables in the program.  There are no constants
/*------------------------*/
        string input;   //input string that will feed the main loop
        string output;  //output to the screen after the input is processed and the loop repeats
	string uName;   //the username the user has, each one will be unique (stored in usernames.txt)
        string regName; //the new user's desired username
        string regPass; //the new user's desired password
	string pass;    //the new user's password (stored in passwords.txt)

	int loginCounter = 0;   //makes sure the user is booted if they spam the "server" with false usernames
        int numUsers = 0;       //counts the number of unique usernames, used to recursively check for a username match
        int matchUserToPass = 0;//is used to get the line that the user's password is on, to check for a match
        int burrowNumber = 0;   //counts how many times the user has burrowed

        bool isValid = false;   //switch turned on once a username is recognized
        bool passValid = false; //switch turned on once the password is recognized
        bool boolSwitch = false;//switch turned on once a file to be read is opened, turned off again when it closes

/*----------------------------------------------
 * Function:    Easter Egg
 * Purpose:     Solve the mystery
 *---------------------------------------------*/
void EasterEgg(string input, string uName, string &output, int &burrowNumber) {

    while (burrowNumber < 10) {
                        burrowNumber++;
                        cin.ignore(100,'\n');
                        cin >> input;
                        if (input != "burrow") {
                            cout << "You did not burrow enough!  Returning to main menu.\n__________" << endl;
                            break;
                        }
                    }
                    if (burrowNumber == 10) {
                        cout << "You can stop burrowing now, you are safe.\n\nYou have burrowed your way into an underground cavern.\nYou are thirsty from all the burrowing.  What do you want to do?" << endl;
                        cin.ignore(100,'\n');
                        cin >> input;
                        if (input == "drink") {
                            cout << "You drank some water, which you happened to have.  But this cave is so dark!\nWhat should you use?" << endl;
                            cin.ignore(100,'\n');
                            getline(cin, input);
                            if (input == "light" || input == "flashlight" || input == "lantern" || input == "torch") {
                                cout << "You turned on your " << input << ".  Looking around, you see this cave looks eerily similar to the J.B. Hunt building.\nAfter more searching, you see that it really is the J.B. Hunt building, and that you have burrowed your way 10,000 years into the future!\nYou decide to investigate by going into your old Programming lab room.\nErm... which room was that again?" << endl;
                                cin >> input;
                                if (input == "204" || input == "0204") {
                                    cout << "You find room " << input << ".  It's locked!\nLuckily, you have something that will unlock it after school hours (or after the school has closed and been buried by years of tectonic shifting).\n What do you use?" << endl;
                                    cin.ignore(100,'\n');
                                    getline(cin, input);
                                    if (input == "student id" || input == "student identification" || input == "identification" || input == "id card" || input == "student id card" || input == "student identification card") {
                                        cout << "You used your " << input << ".\nGoing into the room, you are hit with a strong sense of nostalgia.  You see the Macs all lined up, with mice that suck so badly.\nYou look in the trash can and see a crumpled up note.  Do you dare to uncrumple it and read what it says, knowing full well that its contents could shatter your mind and untether your soul from its resting place in your cerebellum?" << endl;
                                        cin >> input;
                                        if (input == "yes" || input == "y") {
                                            cout << "You do so.  The message looks like gibberish.  It reads:\n______\nObobtg,\n\nB tf pkbmbgz rhn pbma xqmkxfx nkzxgvr.  Bm lxxfl matm fr mbfx pbma rhn atl vhfx tgw zhgx, temahnza B whg'm dghp ahp bm atiixgxw.\n\nRhn dghp ahp fnva B ebdx mh unkkhp... pxee, B ptl unkkhpbgz tgw B unkkhpxw mhh ytk.  B yhngw fr ptr bgmh t vtox, pabva B kxtebsxw ptl max C.U. Angm unbewbgz, 10,000 rxtkl bg max ynmnkx!!!  B atox lvkxpxw hnk eboxl ni fr ehox, tgw yhk matm B tihehzbsx lbgvxkxer.  Lahnew px xoxk fxxm tztbg bg tghmaxk ebyx, B ahix mh ytee tl ftwer bg ehox pbma rhn tl B tf kbzam ghp. Xoxg by, bg mabl gxqm ebyx, px tkx uhma fxg.  Tgw, by matm bl max vtlx, B telh ahix matm bg max gxqm ebyx, ztr ftkkbtzx bl exztebsxw.  By ghm, px pbee kng tptr mh tghmaxk vhngmkr paxkx ixhiex whg'm vtkx tuhnm mabgzl ebdx matm.\n\nTgrptr, B pbla rhn max uxlm, fr wxtk.  Rhn pbee ikhutuer gxoxk kxtw mabl, unm by rhn wh, kxfxfuxk:\n\nWH GHM UNKKHP NGWXKZKHNGW!!! Rhn pbee ux mxexihkmxw makhnza litvx tgw mbfx, 10 mahnltgw rxtkl bgmh max ynmnkx!!!\n\nPbma tee ehox,\n\nEhztg U.T. Lptgzh\n\n\n\nI.L. Nlx xgvkrimbhg 19 <<<<<<<<<<<< ?\n______\nYou are clueless as to what this means, but you put it in your folder and call it doom.\n\nKnowing the journey is done, you return to the place from whence you came, with a strong foreboding that your life is about to be changed forever." << endl;
                                            ofstream doom;
                                            doom.open("doom.txt");
                                            if (doom.is_open()) {
                                                doom << "Obobtg,\n\nB tf pkbmbgz rhn pbma xqmkxfx nkzxgvr.  Bm lxxfl matm fr mbfx pbma rhn atl vhfx tgw zhgx, temahnza B whg'm dghp ahp bm atiixgxw.\n\nRhn dghp ahp fnva B ebdx mh unkkhp... pxee, B ptl unkkhpbgz tgw B unkkhpxw mhh ytk.  B yhngw fr ptr bgmh t vtox, pabva B kxtebsxw ptl max C.U. Angm unbewbgz, 10,000 rxtkl bg max ynmnkx!!!  B atox lvkxpxw hnk eboxl ni fr ehox, tgw yhk matm B tihehzbsx lbgvxkxer.  Lahnew px xoxk fxxm tztbg bg tghmaxk ebyx, B ahix mh ytee tl ftwer bg ehox pbma rhn tl B tf kbzam ghp. Tgw px pbee inm hnk fbgwl mhzxmaxk, bg ehox, mh vkxtmx max zkxtmxlm v++ ikhzktf matm atl xoxk, hk pbee xoxk ux pkbmmxg. Tgw px pbee ebox hnm hnk eboxl bg ytfx tgw pxtema, mtdbgz hkwxkl ykhf gh hgx, ngmbe px wbx tm t kbix hew tzx pbma angwkxwl hy vabewkxg mh vtkkr hg hnk exztvr.\n\nTgrptr, B pbla rhn max uxlm, fr wxtk.  Rhn pbee ikhutuer gxoxk kxtw mabl, unm by rhn wh, kxfxfuxk:\n\nWH GHM UNKKHP NGWXKZKHNGW!!! Rhn pbee ux mxexihkmxw makhnza litvx tgw mbfx, 10 mahnltgw rxtkl bgmh max ynmnkx!!!\n\nPbma tee ehox,\n\nEhztg U.T. Lptgzh\n\n\n\nI.L. Nlx xgvkrimbhg 19 <<<<<<<<<<<< ?";
                                                doom.close();
                                                //decrypted with encryption protocol 19
                                            } else {
                                                cout << "Could not open the file to write to it." << endl;
                                            }
                                        } else if (input == "no" || input == "n") {
                                            cout << "You decide that you value your sanity.  You did not read the note, and end up dying of dehydration after 42 hours.\nReturning to main menu...\n__________" << endl;
                                        } else {
                                            cout << "Its a simple yes or no question!  Returning to main menu...\n__________" << endl;
                                        }
                                    } else {
                                        cout << "You needed to use your *student id*!  Returning to main menu...\n__________" << endl;
                                    }
                                } else {
                                    cout << "The lab room number is *204*!  Returning to main menu...\n__________" << endl;
                                }
                            } else {
                                cout << "You needed to use your *light*!  Returning to main menu...\n__________" << endl;
                            }
                        } else {
                            cout << "You needed to *drink*!  Returning to main menu...\n__________" << endl;
                        }
                    }
                    burrowNumber = 0;
                    output = "Hi, " + uName + "! This is the Cryptocol HOME directory.  Type '--help' for a list of commands.";
}

/*---------------------------------------------------
 * Function:    Date
 * Purpose:     Get the date (code taken from the internet)
 *-------------------------------------------------*/
string Date() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

/*--------------------------------------------------------------
 * Function:    Illicit Log
 * Purpose:     Log people trying to run administrative commands
 *------------------------------------------------------------*/
void IllicitLog(string uName, string date, string input) {

    ofstream log;
    log.open("incidents.txt", ios::app);
    if (log.is_open()) {
        log << "\n" << uName << "\t\t\t" << input << "\t\t\t" << date;
        cout << "This incident has been logged." << endl;
        log.close();
    } else {
        cout << "File does not exist" << endl;
    }
}

/*----------------------------------------------
 * Function:    Append TXT
 * Purpose:     If the user forgot to add '.txt', or made it another file type, change it to a txt file
 *---------------------------------------------*/
void AppendTXT(string &fileName, string txt, int &stringLength) {

    if (((fileName[stringLength-1] != 't') && (fileName[stringLength-2] != 'x') && (fileName[stringLength-3] != 't') && (fileName[stringLength-3] != '.')) || (stringLength <= 4)) {
        if (fileName[stringLength-4] == '.' && stringLength > 4) {
            fileName.erase(stringLength-4, 4);
            stringLength = stringLength - 4;
        }
        fileName = fileName + txt;
        stringLength = stringLength + 4;
    }
}
/*----------------------------------------------
 * Function:    Yes No
 * Purpose:     Convert user input to a boolean value
 *---------------------------------------------*/
bool YesNo(string yesNo) {

    //convert input to boolean
        if ((yesNo == "yes") || (yesNo == "y"))
            return true;
        else
            return false;
}

/*-----------------------------------
 * Function:    Display History
 * Purpose:     Displays user history
 *----------------------------------*/
void DisplayHistory(string file) {

    string command;
    ifstream history;
    history.open(file.c_str());
    if (history.is_open()) {
        //tell them everything theyve ever entered in the main menu
        while (!history.eof()) {
            getline(history, command);
            cout << command << endl;
        }
    } else {
        cout << "Could not access the file " << file << endl;
    }
}

/*----------------------------------------------------------------------------------------------
 * Function:    Get Users
 * Purpose:     So the admin can view number of usernames registered, and output them all if they want
 *---------------------------------------------------------------------------------------------*/
void GetUsers() {

    string username;
    string yesNo;
    int lineCounter = 0;

    ifstream listUsers;
    listUsers.open("usernames.txt");
    if (listUsers.is_open()) {
        //ask if they want the users to be output
        cout << "Do you want to list all usernames?" << endl;
            cin.ignore(100,'\n');
            getline(cin, yesNo);
        //convert user input into bool
        bool outputUsers;
        outputUsers = YesNo(yesNo);
        while (!listUsers.eof()) {
            getline(listUsers, username);
            lineCounter++;
            //if they chose to output users, output users
            if (outputUsers)
                cout << username << endl;
        }
        listUsers.close();
        //tell them the number of registered users
        cout << "\n" << lineCounter << " usernames registered. " << endl;
    } else {
      cout << "Couldn't find usernames file." << endl;
    }
}

/*----------------------------------------------
 * Function:    Validate User
 * Purpose:     Make sure the username is valid
 *---------------------------------------------*/
bool ValidateUsername(string matchMe, int &passLine) {

    string lineCompare;
    string nullstring = "";
    ifstream users;
    users.open("usernames.txt");

    if (users.is_open()) {

        //set the line the password is on to 0
        passLine = 0;
        while(!users.eof()) {
            //get the next line, or username, from the list
            getline(users, lineCompare);
            //increment passline.  when the next if statement is true, passline will be the line that the password for the user is on.
            passLine++;
            //if the username matches the one they entered, and is not blank, return true
            if (matchMe == lineCompare && matchMe != nullstring) {
                users.close();
                return true;
                break;//does this need to be here?
            }
        }
    users.close();
    return false;
    //if the login files don't exist, make them, and add the login credentials for the administrator
    } else {
        ofstream makeFile;
        ofstream makePass;
        ofstream makeLog;
        makeFile.open("usernames.txt");
        makePass.open("passwords.txt");
        makeLog.open("incidents.txt");
        if (makeFile.is_open() && makePass.is_open() && makeLog.is_open()) {
            makeFile << "admin";
            makePass << "nimda";
            makeLog << "Incident report\nUsername\t\t\tCommand\t\t\tDate\n";
            makeFile.close();
            makePass.close();
            makeLog.close();
            //if they're trying to register and a database has not yet been created, there is no need for them to know that we are actually making the database
            if (matchMe != "/register")
                cout << "It appears this might be your first time running the program!  I had to create a new database for you!  Please try again." << endl;
            return false;
        } else {
            cout << "Could not make a new login database!" << endl;
        }
    }
}

/*------------------------------------------------------------------
 * Function:    Validate Password
 * Purpose:     Make sure the Password matches the username entered
 *----------------------------------------------------------------*/
bool ValidatePassword(string matchMe, int passLine) {

    string passCompare;
    ifstream passwords;
    passwords.open("passwords.txt");

    if (passwords.is_open()) {
        //give passcompare the user's real password
        for (int i = 0; i < passLine; i++) {
            getline(passwords, passCompare);
        }
        //if the real password matches the entered password, return true
        if (matchMe == passCompare) {
            passwords.close();
            return true;
        } else {
            passwords.close();
            return false;
        }
    } else {
        cout << "Could not open the passwords file.  Please try again later." << endl;
    }
}

/*--------------------------------------------------------------------------------------------------
 * Function:    Register New User
 * Purpose:     Registering a new username and password, making sure the username isn't a duplicate.
 *------------------------------------------------------------------------------------------------*/
void RegisterNewUser() {

    bool flag = false;          //switch that is turned on once the username the user wants is already in the database
    bool isUnique = false;      //switch that is turned on once every username has been checked to not equal requested username
    string confirmPass;         //makes sure the user didn't make any typos in their password

    //while the new username might have/has already been chosen
    while (!isUnique) {
        ofstream users;
        users.open("usernames.txt", ios::app);

        if (users.is_open()) {
                       cout << "Please enter your desired username: ";
                       getline(cin, regName);
                       while (regName == "exit" || regName == "/register") {
                           cout << "Your username can't be the " << regName << " command!  Please choose another." << endl;
                           getline(cin, regName);
                       }

                       string lineCompare;
                       ifstream usernames;
                       usernames.open("usernames.txt");
                       if (usernames.is_open()) {
                           flag = false;
                           //set linecompare to be the username on each line
                           while (!usernames.eof()) {
                               getline(usernames, lineCompare);
                               //if the requested username is a duplicate keep the main while loop going
                               if (lineCompare == regName) {
                                   isUnique = false;
                                   flag = true;
                               }
                           }
                       } else {
                           cout << "Unable to access username registry.  Please try again later.";
                       }
                       usernames.close();
                       if (flag) {
                           cout << "Sorry, that username already exists.  Please use another." << endl;
                       //if there was no flag for duplicate user, add the requested username to the list
                       } else if (!flag) {
                           isUnique = true;
                           users << "\n" << regName;
                       }
                } else {
                    cout << "Unable to access username registry.  Please try again later.";
                }
        users.close();
    }

    ofstream passwords;
    passwords.open("passwords.txt", ios::app);

    if (passwords.is_open()) {
        do {
                   cout << "Please enter your desired password: ";
                   //get the users password for their new username, confirm it, make sure it wont interfere with an exit code,  and add it to the passwords file
                   getline(cin, regPass);
                   cout << "Please confirm your password: ";
                   //confirm the users password
                   getline(cin, confirmPass);
                   //if typo or exit value, tell them whats wrong and let them try again
                   if (regPass != confirmPass) {
                       cout << "\nPasswords do not match!  Please type more carefully." << endl;
                   } else if (regPass == "exit") {
                       cout << "Your password can't be the exit command!  Please choose another..." << endl;
                   }
        } while ((regPass != confirmPass) || (regPass == "exit"));

        //if everything checks out, register them
        if (regPass == confirmPass) {
           passwords << "\n" << regPass;
           cout << "\nYou have successfully registered a new account, " << regName << "!  You may now login." << endl;
        } else {
            cout << "Oops, something went dreadfully wrong!  Please try to register again." << endl;
        }
    }
    passwords.close();
}

/*--------------------------------
 * Function:    Login System
 * Purpose:     Let the user login
 *-------------------------------*/
void LoginSystem(string &uName, string &pass, string &regPass, string &regName, int &loginCounter) {

        //Splash screen (best viewed in terminal, or black background with white/green text)

	cout << "|0111011011100100111011110001001011000101110011111000110101001011010010110101110000101101001|" << endl;
	cout << "|110     10011      0100  1101  0111      0011        10010     0011010100010110111010011011|" << endl;
	cout << "|11  111000011  101 10000  00  01111  101 1010011  1010111  101  10000    1100   00011 10111|" << endl;
	cout << "|01  100101101     1000110    000011      0001111  1010001  111  1101  100111 101 |011 11101|" << endl;
	cout << "|01  100111011  10  0011101  1001111  11011101101  1100111  101  1011  011111 101 |111 10100|" << endl;
	cout << "|100     10011  110  011101  1100101  10010011101  11100010     011100    1000   01101    11|" << endl;
	cout << "|1000101101110110110100010110110111001000101011010110010100101011010100101110101011111101010|" << endl;
	cout << "\nAccess: ";

        //initial username input
        getline(cin, uName);
        isValid = ValidateUsername(uName, matchUserToPass);

        //looping username input while it stays invalid
	while ((isValid == false) && (uName != "exit") && (loginCounter != 9)) {
            //if they arent trying to register, bump login counter and let them try again
            if (uName != "/register") {
		loginCounter++;
		cout << "Invalid username.  You have " << 10 - loginCounter << " attempts remaining. (to register a new account, please type '/register')" << endl;
            //if theyre trying to register, let them register and try to login
            } else if (uName == "/register") {
                RegisterNewUser();
            }
            cout << "Access: ";
                getline(cin, uName);
                isValid = ValidateUsername(uName, matchUserToPass);
       }

       //let them enter their password, see if it matches to the username (which has already been validated)
       if (isValid && loginCounter < 9) {
           getline(cin, pass);
           passValid = ValidatePassword(pass, matchUserToPass);
       }

       //if the password is not validated and they aren't trying to exit, let them try again
       while ((!passValid) && (pass != "exit") && (isValid)) {
           cout << "Invalid password.  Please type more carefully: ";
                   getline(cin, pass);
                   passValid = ValidatePassword(pass, matchUserToPass);
       }

        //if theyve used all login attempts, kick them off the program
	if ((!isValid) && (loginCounter >= 9) && (pass != "exit") && (uName != "exit")) {
		cout << "You have used all your attempts and still failed to login!  Your IP has been banned from accessing this port." << endl;
        //if theyre trying to exit, let them exit
	} else if ((uName == "exit") || (pass == "exit")) {
		cout << "Your SSH session has been disconnected." << endl;
	}
        //if they are logged in, tell them this.
       if ((loginCounter != 9) && (uName != "exit") && (pass != "exit")) {
          cout << "Hi, " << uName << "! This is the Cryptocol HOME directory.  Type '--help' for a list of commands." << endl;
       }

}

/*-------------------------------------------
 * Function:    Encrypt String
 * Purpose:     Let the user encrypt a string
 *------------------------------------------*/
void EncryptString() {

        int stringLength;       //length of the line
        int shift;              //encryption protocol (how I came up with the name cryptocol)
        int lineCounter;        //counts number of lines in a file
        int charNumHolder;      //counts number of characters in a certain slot of a string array
        int countMostChars = 0; //counts the max characters in a string array
        string plaintextMessage;//used to store user input if they are manually inputting a string to en/decrypt
        string fileName;        //user input of the file they wish to open or save to
        string encryptedMessage;//stores a string that will be written/output after en/decryption
        string dataHolder[500]; //array of strings used to store lines in a file (up to 500 lines)
        string txt = ".txt";    //used to add the txt extention to a filename that lacks one
        string dummy;           //the string used in the en/decryption process

        bool fromFile;          //tells whether the user is inputting manually or from a file
        bool toFile;            //tells whether the user wants to save the output to a file
        bool overwrite;         //tells whether the user wants to overwrite the input file
        string yesNo;           //gets y or yes for yes, and anything else for no, used in the function YesNo

        //choose whether to direct input the string or read it in from a file
        cout << "Would you like to input a message from a text file?" << endl;
                cin >> yesNo;
                fromFile = YesNo(yesNo);
        //if they want to read in from file
        if (fromFile) {
            //file input encryption
            cout << "\nFILE INPUT ENCRYPTION\n" << endl;
            cout << "Enter the name of the file you want to encrypt:" << endl;
            cin.ignore(100,'\n');
            //get the file name
            getline(cin, fileName);
            //get the length of the filename
            stringLength = fileName.length();
            //if they did not append the 'txt' container, append it
            AppendTXT(fileName, txt, stringLength);
            //make sure they don't mess up the login files, history files, or incidents file
            //this line is used numerous times.  it checks for usernames.txt, passwords.txt, incidents.txt, or anything that ends in History.txt
            while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                cout << "Error: You can't open the file '" << fileName << "'.  Permission denied. Please open another file: ";
                getline(cin, fileName);
                stringLength = fileName.length();
                AppendTXT(fileName, txt, stringLength);
            }
            //read in the file
            ifstream encrypt;
               encrypt.open(fileName.c_str());
               if (encrypt.is_open()) {
                   lineCounter = 0;
                   boolSwitch = true;
                   //read in the file again to count the lines
                   ifstream getLineNum;
                   getLineNum.open(fileName.c_str());
                   //count the lines
                   if (getLineNum.is_open()) {
                        while (!getLineNum.eof()) {
                            getline(getLineNum, plaintextMessage);
                            lineCounter++;
                        }
                   } else {
                       cout << "Could not open file to count lines." << endl;
                   }
                   getLineNum.close();
                   //output how many lines have been read
                   cout << "\n" << lineCounter << " lines in total:\n" << endl;
                   //store each line of the file in a string array the size of the number of lines
                   string decryptedMessage[lineCounter];
                   int j = 0;
                   while (!(encrypt.eof())) {
                       getline(encrypt, plaintextMessage);
                       decryptedMessage[j] = plaintextMessage;
                       j++;
                   }
                   //print the string array
                   for (int i = 0; i < lineCounter; i++) {
                       dataHolder[i] = decryptedMessage[i];
                       charNumHolder = dataHolder[i].length();
                       if (charNumHolder > countMostChars)
                           countMostChars = charNumHolder;

                       cout << decryptedMessage[i] << endl;
                   }
                   encrypt.close();
               } else {
                   cout << "Could not access the file '" << fileName << "'.  Please try again" << endl;
               }

               if (boolSwitch) {
                    //get shift number
                    if (lineCounter > 0) {
                        cout << "\nThese lines will be encrypted according to an integer (0-25) of your choice.\nPlease enter that number now: ";
                        cin >> shift;
                        //if shift is out of bounds, have them reenter it
                        while (shift < 0 || shift > 25) {
                            cout << "Your number needs to be between 0 and 25.  Please try again: ";
                            cin >> shift;
                        }

                        char lineChars[lineCounter][countMostChars];
                        string dummy;
                        int numChars = countMostChars;
                        //start the encryption, loop for each line of the text file
                        cout << "Your message has been encrypted to:" << endl;
                        for (int i = 0; i < lineCounter; i++) {
                            dummy = dataHolder[i];
                            numChars = dataHolder[i].length();
                            //within each line, test each character to be an alphanumeric character, and if so, shift it. if not, leave it alone
                            for (int j = 0; j < numChars; j++) {
                                if ((dummy[j] >= 65 && dummy[j] <= 90 - shift) || (dummy[j] >= 97 && dummy[j] <= 122 - shift))
                                     lineChars[i][j] = dummy[j] + shift;
                                else if ((dummy[j] > 90 - shift && dummy[j] <= 90) || (dummy[j] > 122 - shift && dummy[j] <= 122))
                                    lineChars[i][j] = (dummy[j] - 26) + shift;
                                else
                                    lineChars[i][j] = dummy[j];
                                //print the new encryption
                                cout << lineChars[i][j];
                            }
                            cout << "\n";
                        }
                        //prompt for save
                        cout << "\nWould you like to save this to a text file?" << endl;
                            cin >> yesNo;
                            toFile = YesNo(yesNo);
                        //prompt to overwrite
                        if (toFile) {
                             cout << "Would you like to save changes and overwrite the file '" << fileName << "'?" << endl;
                                 cin >> yesNo;
                                 overwrite = YesNo(yesNo);
                            //fill the old file with all new data, close it
                            if (overwrite) {
                                ofstream overwrite;
                                overwrite.open(fileName.c_str());
                                if (overwrite.is_open()) {
                                    for (int i = 0; i < lineCounter; i++) {
                                        dummy = dataHolder[i];
                                        numChars = dataHolder[i].length();
                                        for (int j = 0; j < numChars; j++) {
                                             overwrite << lineChars[i][j];
                                        }
                                        overwrite << "\n";
                                    }
                                    overwrite.close();
                                    cout << fileName << " was saved successfully." << endl;
                                } else {
                                    cout << "Could not open the file to overwrite it." << endl;
                                }
                            //ask for a new file name, fill that one with the data, close it
                            } else {
                                cout << "What would you like to call your new file?" << endl;
                                cin.ignore(100,'\n');
                                getline(cin, fileName);
                                stringLength = fileName.length();
                                AppendTXT(fileName, txt, stringLength);
                                //make sure they don't mess up the login files, history files, or incidents file
                                while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                                    cout << "Error: You can't save your file as '" << fileName << "'.  Please choose another name for your file: ";
                                    getline(cin, fileName);
                                    stringLength = fileName.length();
                                    AppendTXT(fileName, txt, stringLength);
                                }
                                ofstream newFile;
                                newFile.open(fileName.c_str());
                                if (newFile.is_open()) {
                                    for (int i = 0; i < lineCounter; i++) {
                                        dummy = dataHolder[i];
                                        numChars = dataHolder[i].length();
                                        for (int j = 0; j < numChars; j++) {
                                            newFile << lineChars[i][j];
                                        }
                                        newFile << "\n";
                                    }
                                    newFile.close();
                                    cout << fileName << " was saved successfully." << endl;
                                } else {
                                    cout << "Could not open the file to save it." << endl;
                                }
                            }
                        } else {
                            cout << "Your encrypted message will not be saved to a file." << endl;
                        }
                        cout << "Returning to main menu...\n";
                        boolSwitch = false;
                    }

               }//end boolswitch if


        //AKA if (!fromFile)
        } else {
            //manual input encryption
            cout << "\nMANUAL INPUT ENCRYPTION\n" << endl;
            cout << "Enter the string you would like to encrypt:" << endl;
            cin.ignore(100,'\n');
            //get the string
            getline(cin, plaintextMessage);
            //get the length of the filename
            stringLength = plaintextMessage.length();
            //get shift number
            if (cin) {
                cout << "\nThis message will be encrypted according to an integer (0-25) of your choice.\nPlease enter that number now: ";
                cin >> shift;
                //if shift is out of bounds, have them reenter it
                while (shift < 0 || shift > 25) {
                    cout << "Your number needs to be between 0 and 25.  Please try again: ";
                    cin >> shift;
                }
                dummy = plaintextMessage;
                plaintextMessage = " ";
                string lineChars[stringLength];
                //start the encryption, loop for each line of the text file
                cout << "Your message has been encrypted to:" << endl;
                //within each line, test each character to be an alphanumeric character, and if so, shift it. if not, leave it alone
                for (int j = 0; j < stringLength; j++) {
                    if ((dummy[j] >= 65 && dummy[j] <= 90 - shift) || (dummy[j] >= 97 && dummy[j] <= 122 - shift))
                        lineChars[j] = dummy[j] + shift;
                    else if ((dummy[j] > 90 - shift && dummy[j] <= 90) || (dummy[j] > 122 - shift && dummy[j] <= 122))
                        lineChars[j] = (dummy[j] - 26) + shift;
                    else
                        lineChars[j] = dummy[j];
                    //print the new encryption
                    cout << lineChars[j];
                    plaintextMessage.replace(j,1,lineChars[j]);
                }
                cout << "\n";
            }
            //prompt for save
            cout << "\nWould you like to save this to a text file?" << endl;
            cin >> yesNo;
            toFile = YesNo(yesNo);
            if (toFile) {
                cout << "What would you like to call your new file?" << endl;
                    cin.ignore(100,'\n');
                    getline(cin, fileName);
                    stringLength = fileName.length();
                    AppendTXT(fileName, txt, stringLength);
                    //make sure they don't mess up the login files, history files, or incidents file
                    while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                        cout << "Error: You can't save your file as '" << fileName << "'.  Please choose another name for your file: ";
                        getline(cin, fileName);
                        stringLength = fileName.length();
                        AppendTXT(fileName, txt, stringLength);
                    }
                    //write en/decrypted user input to a new file
                    ofstream newFile;
                    newFile.open(fileName.c_str());
                    if (newFile.is_open()) {
                        newFile << plaintextMessage;
                        newFile.close();
                        cout << fileName << " was saved successfully." << endl;
                    } else {
                        cout << "Could not open the file to save it." << endl;
                    }
            } else {
                cout << "Your encrypted message will not be saved to a file." << endl;
            }
            cout << "Returning to main menu...\n";
        }

}

/*-------------------------------------------
 * Function:    Decrypt String
 * Purpose:     Let the user decrypt a string
 *------------------------------------------*/
void DecryptString() {

        int stringLength;
        int shift;
        int lineCounter;
        int charNumHolder;
        int countMostChars = 0;

        string plaintextMessage;
        string fileName;
        string decryptedMessage;
        string dataHolder[500];
        string txt = ".txt";
        string dummy;

        bool fromFile;
        bool toFile;
        bool overwrite;
        string yesNo;

        //choose whether to direct input the string or read it in from a file
        cout << "Would you like to input a message from a text file?" << endl;
        cin >> yesNo;
        fromFile = YesNo(yesNo);
        //if they want to read in from file
        if (fromFile) {
            //file input encryption
            cout << "\nFILE INPUT DECRYPTION\n" << endl;
            cout << "Enter the name of the file you want to decrypt:" << endl;
            cin.ignore(100,'\n');
            //get the file name
            getline(cin, fileName);
            //get the length of the filename
            stringLength = fileName.length();
            //if they did not append the 'txt' container, append it
            AppendTXT(fileName, txt, stringLength);
            //make sure they don't mess up the login files, history files, or incidents file
            while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                cout << "Error: You can't open the file '" << fileName << "'.  Permission denied.  Please open another file: ";
                getline(cin, fileName);
                stringLength = fileName.length();
                AppendTXT(fileName, txt, stringLength);
            }
            //read in the file
            ifstream decrypt;
            decrypt.open(fileName.c_str());
            if (decrypt.is_open()) {
                lineCounter = 0;
                boolSwitch = true;
                //read in the file again to count the lines
                ifstream getLineNum;
                getLineNum.open(fileName.c_str());
                //count the lines
                if (getLineNum.is_open()) {
                     while (!getLineNum.eof()) {
                         getline(getLineNum, plaintextMessage);
                         lineCounter++;
                     }
                } else {
                    cout << "Could not open file to count lines." << endl;
                }
                getLineNum.close();
                //output how many lines have been read
                cout << "\n" << lineCounter << " lines in total:\n" << endl;
                //store each line of the file in a string array the size of the number of lines
                string decryptedMessage[lineCounter];
                int j = 0;
                while (!(decrypt.eof())) {
                    getline(decrypt, plaintextMessage);
                    decryptedMessage[j] = plaintextMessage;
                    j++;
                }
                //print the string array
                for (int i = 0; i < lineCounter; i++) {
                    dataHolder[i] = decryptedMessage[i];
                    charNumHolder = dataHolder[i].length();
                    if (charNumHolder > countMostChars)
                        countMostChars = charNumHolder;
                    cout << decryptedMessage[i] << endl;
                }
                decrypt.close();
            } else {
                cout << "Could not access the file '" << fileName << "'.  Please try again" << endl;
            }
            if (boolSwitch) {
                 //get shift number
                 if (lineCounter > 0) {
                     cout << "\nThese lines will be decrypted according to an integer (0-25) of your choice.\nPlease enter that number now: ";
                         cin >> shift;
                     //if shift is out of bounds, have them reenter it
                     while (shift < 0 || shift > 25) {
                         cout << "Your number needs to be between 0 and 25.  Please try again: ";
                             cin >> shift;
                     }
                     char lineChars[lineCounter][countMostChars];
                     string dummy;
                     int numChars = countMostChars;
                     //start the encryption, loop for each line of the text file
                     cout << "Your message has been decrypted to:" << endl;
                     for (int i = 0; i < lineCounter; i++) {
                         dummy = dataHolder[i];
                         numChars = dataHolder[i].length();
                         //within each line, test each character to be an alphanumeric character, and if so, shift it. if not, leave it alone
                         for (int j = 0; j < numChars; j++) {
                             if ((dummy[j] >= 65 + shift && dummy[j] <= 90) || (dummy[j] >= 97 + shift && dummy[j] <= 122))
                                  lineChars[i][j] = dummy[j] - shift;
                             else if ((dummy[j] < 65 + shift && dummy[j] >= 65) || (dummy[j] < 97 + shift && dummy[j] >= 97))
                                 lineChars[i][j] = dummy[j] + (26 - shift);
                             else
                                 lineChars[i][j] = dummy[j];
                             //print the new encryption
                             cout << lineChars[i][j];
                         }
                         cout << "\n";
                     }
                     //prompt for save
                     cout << "\nWould you like to save this to a text file?" << endl;
                     cin >> yesNo;
                     toFile = YesNo(yesNo);
                     //prompt to overwrite
                     if (toFile) {
                         cout << "Would you like to save changes and overwrite the file '" << fileName << "'?" << endl;
                             cin >> yesNo;
                             overwrite = YesNo(yesNo);
                         //fill the old file with all new data, close it
                         if (overwrite) {
                             ofstream overwrite;
                             overwrite.open(fileName.c_str());
                             if (overwrite.is_open()) {
                                 for (int i = 0; i < lineCounter; i++) {
                                     dummy = dataHolder[i];
                                     numChars = dataHolder[i].length();
                                     for (int j = 0; j < numChars; j++) {
                                         overwrite << lineChars[i][j];
                                     }
                                     overwrite << "\n";
                                 }
                                 overwrite.close();
                                 cout << fileName << " was saved successfully." << endl;
                             } else {
                                 cout << "Could not open the file to overwrite it." << endl;
                             }
                             //ask for a new file name, fill that one with the data, close it
                         } else {
                             cout << "What would you like to call your new file?" << endl;
                                 cin.ignore(100,'\n');
                                 getline(cin, fileName);
                                 stringLength = fileName.length();
                                 AppendTXT(fileName, txt, stringLength);
                             //make sure they don't mess up the login files, incidents file, or history files
                             while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                                 cout << "Error: You can't save your file as '" << fileName << "'.  Please choose another name for your file: ";
                                     getline(cin, fileName);
                                     stringLength = fileName.length();
                                     AppendTXT(fileName, txt, stringLength);
                             }
                             ofstream newFile;
                             newFile.open(fileName.c_str());
                             if (newFile.is_open()) {
                                 for (int i = 0; i < lineCounter; i++) {
                                     dummy = dataHolder[i];
                                     numChars = dataHolder[i].length();
                                     for (int j = 0; j < numChars; j++) {
                                         newFile << lineChars[i][j];
                                     }
                                     newFile << "\n";
                                 }
                                 newFile.close();
                                 cout << fileName << " was saved successfully." << endl;
                             } else {
                                 cout << "Could not open the file to save it." << endl;
                             }
                         }
                     } else {
                         cout << "Your encrypted message will not be saved to a file." << endl;
                     }
                     cout << "Returning to main menu...\n";
                     boolSwitch = false;
                 }
            }//end boolSwitch if

        } else {
            //manual input decryption
            cout << "\nMANUAL INPUT DECRYPTION\n" << endl;
            cout << "Enter the string you would like to decrypt:" << endl;
            cin.ignore(100,'\n');
            //get the string
            getline(cin, plaintextMessage);
            //get the length of the filename
            stringLength = plaintextMessage.length();
            //get shift number
            if (cin) {
                cout << "\nThis message will be decrypted according to an integer (0-25) of your choice.\nPlease enter that number now: ";
                cin >> shift;
                //if shift is out of bounds, have them reenter it
                while (shift < 0 || shift > 25) {
                    cout << "Your number needs to be between 0 and 25.  Please try again: ";
                        cin >> shift;
                }
                dummy = plaintextMessage;
                plaintextMessage = " ";
                string lineChars[stringLength];
                //start the decryption, loop for each line of the text
                cout << "Your message has been decrypted to:" << endl;
                //within each line, test each character to be an alphanumeric character, and if so, shift it. if not, leave it alone
                for (int j = 0; j < stringLength; j++) {
                    if ((dummy[j] >= 65 + shift && dummy[j] <= 90) || (dummy[j] >= 97 + shift && dummy[j] <= 122))
                         lineChars[j] = dummy[j] - shift;
                    else if ((dummy[j] < 65 + shift && dummy[j] >= 65) || (dummy[j] < 97 + shift && dummy[j] >= 97))
                        lineChars[j] = dummy[j] + (26 - shift);
                    else
                        lineChars[j] = dummy[j];
                    //print the new encryption
                    cout << lineChars[j];
                }
                cout << "\n";
            }
            //prompt for save
            cout << "\nWould you like to save this to a text file?" << endl;
                cin >> yesNo;
                toFile = YesNo(yesNo);
           if (toFile) {
               cout << "What would you like to call your new file?" << endl;
                   cin.ignore(100,'\n');
                   getline(cin, fileName);
                   stringLength = fileName.length();
                   AppendTXT(fileName, txt, stringLength);
               //make sure they don't mess up the login files, history files, or incidents file
               while (fileName == "usernames.txt" || fileName == "passwords.txt" || fileName == "incidents.txt" || (stringLength > 11 && (fileName[stringLength-1] == 't' && fileName[stringLength-2] == 'x' && fileName[stringLength-3] == 't' && fileName[stringLength-4] == '.' && fileName[stringLength-5] == 'y' && fileName[stringLength-6] == 'r' && fileName[stringLength-7] == 'o' && fileName[stringLength-8] == 't' && fileName[stringLength-9] == 's' && fileName[stringLength-10] == 'i' && fileName[stringLength-11] == 'H'))) {
                   cout << "Error: You can't save your file as '" << fileName << "'.  Please choose another name for your file: ";
                       getline(cin, fileName);
                       stringLength = fileName.length();
                       AppendTXT(fileName, txt, stringLength);
               }
               //write en/decrypted user input to a new file
               ofstream newFile;
               newFile.open(fileName.c_str());
               if (newFile.is_open()) {
                   newFile << plaintextMessage;
                   newFile.close();
                   cout << fileName << " was saved successfully." << endl;
               } else {
                   cout << "Could not open the file to save it." << endl;
               }
           } else
               cout << "Your decrypted message will not be saved to a file." << endl;
           cout << "Returning to main menu...\n";
       }

}

/*-----------------------------------
 * Function:    main
 * Purpose:     Be the main function
 *---------------------------------*/
int main() {

    input = "0";
    LoginSystem(uName, pass, regPass, regName, loginCounter);
    string userHistory = uName + "History.txt";

       //while they arent trying to exit, let them do some commands.
	while ((input != "exit") && (input != "quit") && (loginCounter != 9) && (uName != "exit") && (pass != "exit")) {
                //terminal-esque command-line interface
		cout << "\n";
		cout << uName << "@cryptocol : ";
		cin >> input;
                //if they want help, tell them the valid commands
		if (input == "--help") {
                    output = "\nCommand           Description\n______________________________\n--help        --> Gives a list of available commands\nencrypt       --> Allows you to encrypt a message\ndecrypt       --> Allows you to decrypt a Cryptocol encrypted message\nabout         --> Information about Cryptocol\nexit          --> Terminates user session and disconnects\nlogout        --> Terminates user session and returns to access splashscreen\nwhoami        --> Outputs your username\nhistory       --> Tells you every command you have ever entered in the main menu\n\nEaster Egg...... How many times can you 'burrow'?";
		//if they want to encrypt, let them encrypt.
                } else if (input == "encrypt") {
                    EncryptString();
                    output = "\nWhat would you like to do? ";
                //if they want to decrypt, let them decrypt
		} else if (input == "decrypt") {
                    DecryptString();
		    output = "\n\nWhat would you like to do? ";
                //if they want to exit, let them exit
		} else if ((input == "exit") || (input == "quit")) {
		    output = "disconnecting...";
                //if they want to know more about cryptocol, tell them more about cryptocol
		} else if (input == "about") {
		    output = "\nCRYPTOCOL VERSION 1.0.0.1b\n__________________________\nUsed under the WTFPL license. Report bugs or glitches to admin@cryptocol.com\n\nCryptocol, or, more formally, Encryption Multifunction Protocol, is a service currently being publically tested by college students.  The primary function of Cryptocol is to successfully encrypt and decrypt important strings of text to be delivered securely in any fashion, most notably by email or other digital data sharing.  In order for these messages to be received, the sender and the recipient both must have access to\n1) a Cryptocol account\n2) the encryption protocol (number) that is used to encrypt the message\n3) The encrypted message, verbatim, with no typos that hinder the program from performing a successful decryption.\n\nThis program is still to be transferred to beta, even though it is shown as currently in beta testing.";
		//if they want to logout, clear the buffer, log them out and take them back to the login screen, and when they get back, make sure the while loop is still satisfied
                } else if (input == "whoami") {
                    output = uName;
                } else if (input == "logout") {
                    cout << "Terminating session..." << endl;
                    cin.ignore(100,'\n'); //I found this needs to be here for some reason
                    LoginSystem(uName, pass, regPass, regName, loginCounter);
                    userHistory = uName + "History.txt";
                    output = "\nWhat would you like to do?";
                } else if (input == "history") {
                    DisplayHistory(userHistory);
                    output = "\nWhat would you like to do?";
                } else if (input == "burrow") {
                    EasterEgg(input, uName, output, burrowNumber);
                    //if their command is not valid, tell them so and let them try again
                } else if (input == "users") {
                    if (uName == "admin") {
                        GetUsers();
                        output = "\nWhat would you like to do?";
                    } else {
                        cout << "You do not have the required permissions!" << endl;
                        string date = Date();
                        IllicitLog(uName, date, input);
                        output = "\nWhat would you like to do?";
                    }
                } else {
		    output = "Sorry, " + input + " is not recognized by this interface.  Type --help for a list of commands.";
		}

                //output
                //if they exit from the login screen, we don't want any more output from inside the main function
                if (uName != "exit") {
                    cout << output;
                }
                ofstream history;
                history.open(userHistory.c_str(), ios::app);
                if (history.is_open()) {
                    history << "\n" << input;
                    history.close();
                }
	}
        if (isValid && passValid) {
	    cout << "You have successfully disconnected your session." << endl;
        } else if (uName != "exit" && pass != "exit") {
            cout << "You have been disconnected from the server." << endl;
        }

    return 0;
}
