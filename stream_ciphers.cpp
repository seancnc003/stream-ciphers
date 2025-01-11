/*                                                          
        * NAME: Sean_Cuenco

        * Description: This assignment uses rotation and offset
        encyption techniques in order to encrypt and decrypt files

        * Input: the user would input their message/password, 
        the encryption/decryption technique, and the amount 
        to offset or rotate

        * Output: the program would output the message/password
         that is encoded or decoded
*/

#include <iostream>
#include <string>
#include <cctype>   // For std::tolower
#include <limits>   // For std::numeric_limits
#include <cstdlib>  // For exit()

using namespace std;

/**
 * @brief Encrypts or decrypts a message by shifting each character's ASCII value.
 * 
 * @param message The input message to be encrypted or decrypted.
 * @param shift The amount by which to shift each character.
 * @return string The resulting encrypted or decrypted message.
 */
string offset(string message, int shift) {
    string offMessage;

    for(char ch : message) {
        offMessage += static_cast<char>(ch + shift);
    }

    return offMessage;
}

/**
 * @brief Rotates the characters in the string by the specified shift.
 * 
 * @param rotation The input string to rotate.
 * @param shift The number of positions to rotate.
 * @return string The rotated string.
 */
string rotate_string(string rotation, int shift) {
    int len = rotation.length();
    if(len == 0) return rotation;

    // Normalize shift to be within the length of the string
    shift = shift % len;
    if(shift < 0) {
        shift += len; // Handle negative shifts
    }

    // Perform rotation
    string rotated = rotation.substr(len - shift) + rotation.substr(0, len - shift);
    return rotated;
}

/**
 * @brief Prompts the user to enter a message or password.
 * 
 * @return string The user-entered message.
 */
string get_message() {
    string message;
    cout << "Enter your message/password: ";
    getline(cin, message);

    // Ensure the message is not empty
    while(message.empty()) {
        cout << "ERROR: Message cannot be empty. Please enter your message/password: ";
        getline(cin, message);
    }

    return message;
}

/**
 * @brief Prompts the user to choose between encryption and decryption.
 * 
 * @return char The user's choice ('E'/'e' for encrypt, 'D'/'d' for decrypt).
 */
char get_operation() {
    char operation;
    cout << "Do you want to Encrypt (E) or Decrypt (D) your message? ";
    cin >> operation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    // Validate input
    while(tolower(operation) != 'e' && tolower(operation) != 'd') {
        cout << "ERROR: Invalid choice. Please enter 'E' for Encrypt or 'D' for Decrypt: ";
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    return tolower(operation);
}

/**
 * @brief Prompts the user to choose the encryption/decryption technique.
 * 
 * @return char The user's choice ('R'/'r' for rotation, 'O'/'o' for offset).
 */
char get_technique() {
    char technique;
    cout << "Choose the technique - Rotation (R) or Offset (O): ";
    cin >> technique;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    // Validate input
    while(tolower(technique) != 'r' && tolower(technique) != 'o') {
        cout << "ERROR: Invalid technique. Please enter 'R' for Rotation or 'O' for Offset: ";
        cin >> technique;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    return tolower(technique);
}

/**
 * @brief Prompts the user to enter the shift amount and validates it.
 * 
 * @return int The validated shift amount.
 */
int get_shift_amount() {
    int shift;
    cout << "Enter the shift amount (integer): ";
    cin >> shift;

    // Validate input
    while(cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "ERROR: Invalid input. Please enter a valid integer for the shift amount: ";
        cin >> shift;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    return shift;
}

int main() {
    cout << "=== Encryption/Decryption Program ===\n" << endl;

    // Step 1: Get the message from the user
    string message = get_message();

    // Step 2: Get the operation (encrypt/decrypt)
    char operation = get_operation();

    // Step 3: Get the technique (rotation/offset)
    char technique = get_technique();

    // Step 4: Get the shift amount
    int shift = get_shift_amount();

    // Adjust shift for decryption
    if(operation == 'd') {
        shift = -shift;
    }

    string result;

    // Perform the chosen technique
    if(technique == 'o') {
        result = offset(message, shift);
    }
    else if(technique == 'r') {
        result = rotate_string(message, shift);
    }
    else {
        // This should never happen due to earlier validation
        cerr << "ERROR: Unknown technique selected." << endl;
        exit(EXIT_FAILURE);
    }

    // Output the result
    cout << "\n=== Result ===" << endl;
    if(operation == 'e') {
        cout << "Encrypted Message: " << result << endl;
    }
    else {
        cout << "Decrypted Message: " << result << endl;
    }

    cout << "\n=============================" << endl;

    return 0;
}
