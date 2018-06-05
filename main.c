/**
* @author Nikola Petrovic
* @file main.c
* @bug No bugs
* @mainpage Encryption & Decryption program
* @section This program encrypt & decrypt the given messages
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encr_decr.h"

int main()
{
    /// In this variable we are storing the messages added by user
    char message[100];
    int choice;

    printf("If you want to encrypt message, press 1.\nIf you want to decrypt message, press 2.\n");
    printf("When you do not want to use application anymore, just press 0.\n");
    while(choice != 0){
        printf("\nCHOICE: ");
        scanf("%d", &choice); /*! The problem was that the newline I input when reading choice
                                was being taken as input for the next gets(message),
                                and so it was reading an empty string. Because of that I added an artificial
                                getchar after scanf to absorb the newline. */
        getchar();
        switch(choice){
            case 1:
                /// In this case we encrypt the message given by user
                printf("\n====Enter message for encryption====\n");
                printf("\nNOTE: First letter must be 'a', than comes white space\nand than you enter your message\n\nMESSAGE: ");
                gets(message);
                encryption(&message[0]);
                break;
            case 2:
                /// In this case we decrypt the message given by user
                printf("\n====Enter message for decryption====\n\nMESSAGE: ");
                gets(message);
                decryption(&message[0]);
                break;
            default: printf("\nGOODBYE.\n");
        }
    }

    return 0;
}
