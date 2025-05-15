#include <stdlib.h>
#include "utils.h"

/*
 * 1. Receive a message
 * 2. Split it into IV and ciphertext
 * 3. Decrypt the message
 * 4. Print the IV and the plaintext
 */
int main(void) {
    uint8_t message[48];
    uint8_t iv[16];
    uint8_t ciphertext[32];
    uint8_t plaintext[32];
  
    // iv || ciphertext
    recv_message(message);
    
    memcpy_s(iv, sizeof(iv), message, sizeof(iv));
    memcpy_s(ciphertext, sizeof(ciphertext), message + sizeof(iv), sizeof(ciphertext));

    decrypt_message(iv, ciphertext, plaintext);

    print_iv(iv);
    print_plaintext(plaintext);

}


