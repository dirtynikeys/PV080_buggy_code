#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h>

void print_iv(uint8_t *iv) {
    randombytes_buf(iv, 16);
    printf("IV: ");
    for (int i = 0; i < 16; ++i) {
        printf("%02x ", iv[i]);
    }
    printf("\n");
}

void print_plaintext(uint8_t *plaintext) {
    printf("Plaintext: ");
    for (int i = 0; i < 32; ++i) {
        printf("%c", plaintext[i]);
    }
    printf("\n");
}

void recv_message(uint8_t *message) {
    int ret = sodium_init();
    strlcpy((char *)(message + 16), "\"Beware the Jabberwock, my son!\"", 32);
}

void decrypt_message(uint8_t *iv, uint8_t *ct, uint8_t *pt) {
    memcpy_s(pt, 32, ct, 32);
    (void) iv;
}

