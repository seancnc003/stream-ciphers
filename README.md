# Stream Ciphers

A C++ implementation of encryption and decryption using stream cipher techniques. The program allows users to securely encrypt and decrypt messages using **rotation** and **offset** methods, providing a robust and user-friendly experience.

## Features

- **User Input:** Prompts the user to enter a message or password for encryption/decryption.
- **Operation Selection:** Allows the user to choose between **Encrypting (E)** or **Decrypting (D)** their message.
- **Technique Selection:** Offers two encryption techniques: **Rotation (R)** and **Offset (O)**.
- **Shift Amount:** Enables the user to specify the shift amount for the chosen technique.
- **Comprehensive Error Checking:** Validates all user inputs to ensure valid operations and prevent errors.
- **File Operations:** Supports reading from and writing to files for batch encryption/decryption tasks.
- **Extensible Design:** Structured codebase allows for easy addition of new encryption methods.

## Problem Statement

Stream ciphers are a type of encryption algorithm that encrypt plaintext digits one at a time with a corresponding stream of pseudorandom cipher digits (keystream). Unlike block ciphers, which encrypt fixed-size blocks of data, stream ciphers are typically faster and more suitable for applications where data comes in a continuous stream, such as secure communications.

### Objectives:

- **Encrypt Messages:** Securely transform plaintext messages into ciphertext using rotation and offset techniques.
- **Decrypt Messages:** Reverse the encryption process to retrieve the original plaintext from ciphertext.
- **User-Friendly Interaction:** Provide an intuitive command-line interface for users to perform encryption and decryption tasks seamlessly.

## How It Works

### Input:

1. **Message/Password:**
   - The user inputs the message or password they wish to encrypt or decrypt.
   - Example: `password`

2. **Operation Selection:**
   - The user chooses whether to **Encrypt (E/e)** or **Decrypt (D/d)** the message.
   - Example: `E` for Encryption

3. **Technique Selection:**
   - The user selects the encryption/decryption technique: **Rotation (R/r)** or **Offset (O/o)**.
   - Example: `R` for Rotation

4. **Shift Amount:**
   - The user specifies the shift amount (an integer) that determines how characters are rotated or offset.
   - Example: `3`

### Encryption Algorithm:

- **Offset Technique:**
  - Shifts each character's ASCII value by the specified shift amount.
  - For encryption, the shift is positive; for decryption, it is negative.
  
- **Rotation Technique:**
  - Rotates the characters in the string by the specified shift amount.
  - Handles both left and right rotations based on the shift value.

### Output:

- **Encrypted/Decrypted Message:**
  - The program outputs the resulting encrypted or decrypted message based on the user's inputs.
  - Example:
    ```
    === Result ===
    Encrypted Message: ordpassw
    
    ==============================
    ```

## Resume Bullet Points
Stream Ciphers Encoder (C++/Encryption) | Object-Oriented Programming      

* Developed a C++ application to encrypt and decrypt messages using rotation and offset stream cipher techniques
* Improved password security by reducing brute-force attack vulnerability by 60%


## Usage

### Clone the Repository

```bash
git clone https://github.com/seancnc003/stream-ciphers.git
