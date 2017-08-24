# cryptocol
| **C++ Fully Homomorphic Encryption (FHE) of Files &amp; Input**


## Documentation

+ The goal of this assignment was to write a program that encrypts and decrypts txt files.  It should prompt the user for a file name, whether to encrypt or decrypt, and shift amount to use.  It should output both forms of the message to stdout, and ask if the user wants it saved to a file.  if they do, save it
+ What I started with was a program I wrote back when I was working on my first project in Programming 101.  It was called cryptocol, and I had made the main menu loop and the login system (as a bunch of if statements, if username == this... etc.  But I modified the login system VERY much, to store new logins in text files.  I also modified the menu, beefed it up for more available commands, and other things not relevant to the actual assignment.  I wanted the program to have a terminal application feel, and I think I succeeded.
+ After that, I started working on the encryption.  I let the user choose whether to encrypt from a text file or a manually entered string.  I added the append txt function to make sure the file was actually txt, and no other formats would be accepted.  Then they would either enter the string, or see the contents of the file displayed to the screen, and would be asked for their encryption number.  Once entered, the encrypted message would be displayed, and they would be prompted for save.  If they want to save, for a manual input they would be prompted for the filename to save as.  if file input, they would be asked if they want to overwrite the original, and if not, be prompted for a filename to save as.  append txt would then be called again to save it as a txt file.
+ Same thing for decryption, with changes that reflect decryption as opposed to encryption.
+ Added an Easter Egg, which is a very simple game that ends with finding an encrypted note, which can be decrypted for a laugh.  SPOILER ALERT: the encryption number is 19, which is at the end of the encrypted message.
+ I tried to be as thorough as possible for error checking.  The only thing that I still can't figure out is how to make the program stop endlessly looping after entering something other than an integer for a cin >> int.  If there is an easy way to fix this, I would like to know.
+ You will better see how thorough I was by reading my comments/code and actually running the program.  This rather long overview was just skimming the surface.

## Sample STDOUT

```sh
|0111011011100100111011110001001011000101110011111000110101001011010010110101110000101101001|
|110     10011      0100  1101  0111      0011        10010     0011010100010110111010011011|
|11  111000011  101 10000  00  01111  101 1010011  1010111  101  10000    1100   00011 10111|
|01  100101101     1000110    000011      0001111  1010001  111  1101  100111 101 |011 11101|
|01  100111011  10  0011101  1001111  11011101101  1100111  101  1011  011111 101 |111 10100|
|100     10011  110  011101  1100101  10010011101  11100010     011100    1000   01101    11|
|(LoganB.A.Swango--010636621--Project5)00101011010110010100101011010100101110101011111101010|

Access: first run
It appears this might be your first time running the program!  I had to create a new database for you!  Please try again.
Invalid username.  You have 9 attempts remaining. (to register a new account, please type '/register')
Access: first run
Invalid username.  You have 8 attempts remaining. (to register a new account, please type '/register')
Access: /register
Please enter your desired username: admin
Sorry, that username already exists.  Please use another.
Please enter your desired username: Logan
Please enter your desired password: C++
Please confirm your password: C--

Passwords do not match!  Please type more carefully.
Please enter your desired password: C++
Please confirm your password: C++

You have successfully registered a new account, Logan!  You may now login.
Access: Logan
C++
Hi, Logan! This is the Cryptocol HOME directory.  Type '--help' for a list of commands.

Logan@cryptocol : encrypt
Would you like to input a message from a text file?
no way jose!

MANUAL INPUT ENCRYPTION

Enter the string you would like to encrypt:
I will show you fear in a handful of dust. -T.S. Eliot

This message will be encrypted according to an integer (0-25) of your choice.
Please enter that number now: 19
Your message has been encrypted to:
B pbee lahp rhn yxtk bg t atgwyne hy wnlm. -M.L. Xebhm

Would you like to save this to a text file?
y
What would you like to call your new file?
quote
quote.txt was saved successfully.
Returning to main menu...

What would you like to do?
Logan@cryptocol : decrypt
Would you like to input a message from a text file?
yes

FILE INPUT DECRYPTION

Enter the name of the file you want to decrypt:
quote.txt

1 lines in total:

B pbee lahp rhn yxtk bg t atgwyne hy wnlm. -M.L. Xebhm

These lines will be decrypted according to an integer (0-25) of your choice.
Please enter that number now: 19
Your message has been decrypted to:
I will show you fear in a handful of dust. -T.S. Eliot

Would you like to save this to a text file?
y
Would you like to save changes and overwrite the file 'quote.txt'?
y
quote.txt was saved successfully.
Returning to main menu...


What would you like to do?
Logan@cryptocol : logout
Terminating session...
|0111011011100100111011110001001011000101110011111000110101001011010010110101110000101101001|
|110     10011      0100  1101  0111      0011        10010     0011010100010110111010011011|
|11  111000011  101 10000  00  01111  101 1010011  1010111  101  10000    1100   00011 10111|
|01  100101101     1000110    000011      0001111  1010001  111  1101  100111 101 |011 11101|
|01  100111011  10  0011101  1001111  11011101101  1100111  101  1011  011111 101 |111 10100|
|100     10011  110  011101  1100101  10010011101  11100010     011100    1000   01101    11|
|(LoganB.A.Swango--010636621--Project5)00101011010110010100101011010100101110101011111101010|

Access: exit
Your SSH session has been disconnected.
```
