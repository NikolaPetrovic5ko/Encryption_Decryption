#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryption(char *message);
void decryption(char *message);

int main()
{
    char message[100];
    int choice;

    printf("If you want to encrypt message, press 1.\nIf you want to decrypt message, press 2.\n");
    printf("When you do not want to use application anymore, just press 0.\n");
    while(choice != 0){
        printf("\nCHOICE: ");
        scanf("%d", &choice); /*The problem was that the newline I input when reading choice
                                was being taken as input for the next gets(message),
                                and so it was reading an empty string. Because of that I added an artificial
                                getchar after scanf to absorb the newline.*/
        getchar();
        switch(choice){
            case 1:
                printf("\n====Enter message for encryption====\n");
                printf("\nNOTE: First letter must be 'a', than comes white space\nand than you enter your message\n\nMESSAGE: ");
                gets(message);
                encryption(&message[0]);
                break;
            case 2:
                printf("\n====Enter message for decryption====\n\nMESSAGE: ");
                gets(message);
                decryption(&message[0]);
                break;
            default: printf("\nGOODBYE.\n");
        }
    }

    return 0;
}

void encryption(char *message){

    char encrypted_message[100] = "";

    int n1 = 10;
    int n2 = 9;
    int n3 = 7;

    char row1_of_letters[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char row2_of_letters[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char row3_of_letters[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    int iterator1 = 0;
    int iterator2 = 0;
    int char_position;
    int is_char_found;
    int distance;
    int length_of_message = strlen(message);

    char letter_for_encryption;

    char *row1 = row1_of_letters;
    char *row2 = row2_of_letters;
    char *row3 = row3_of_letters;
    char *ptrMessage = message;
    char *encrypted_msg = encrypted_message;

    printf("\n===Input a letter for encryption===\n\nLetter must be from the second row of the keyboard.\n\nLETTER: ");
    scanf("%c",&letter_for_encryption);
    while( row2_of_letters[distance] != letter_for_encryption ){
        distance = distance + 1;
    }
    for(iterator1 = 0; iterator1 < length_of_message; iterator1++){
    ///Encryption with first row
        is_char_found = 0;
        for(iterator2 = 0; iterator2 < n1; iterator2++){
            if(*(ptrMessage + iterator1) == *(row1 + iterator2)){
                if( (iterator2 + distance) >= n1 ) {
                    char_position = (iterator2 + distance) - n1;
                    *(encrypted_msg + iterator1) = *(row1 + char_position);
                    is_char_found = 1;
                } else {
                    *(encrypted_msg + iterator1) = *(row1 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
    ///Encryption with second row
        if(is_char_found == 0) {
            for(iterator2 = 0; iterator2 < n2; iterator2++){
            if(*(ptrMessage + iterator1) == *(row2 + iterator2)){
                if( (iterator2 + distance) >= n2 ) {
                    char_position = (iterator2 + distance) - n2;
                    *(encrypted_msg + iterator1) = *(row2 + char_position);
                    is_char_found = 1;
                } else {
                    *(encrypted_msg + iterator1) = *(row2 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
    ///Encryption with third row
        if(is_char_found == 0) {
                for(iterator2 = 0; iterator2 < n3; iterator2++){
            if(*(ptrMessage + iterator1) == *(row3 + iterator2)){
                if( (iterator2 + distance) >= n3 ) {
                    char_position = (iterator2 + distance) - n3;
                    *(encrypted_msg + iterator1) = *(row3 + char_position);
                    is_char_found = 1;
                } else {
                    *(encrypted_msg + iterator1) = *(row3 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
        if(is_char_found == 0) {
            *(encrypted_msg + iterator1) = *(ptrMessage + iterator1);
                }
            }
        }
    }
    printf("\n=====ENCRYPTED MESSAGE=====\n\n%s\n", encrypted_message);
}

void decryption(char *message){

    char decrypted_message[100] = "";

    int n1 = 10;
    int n2 = 9;
    int n3 = 7;

    char row1_of_letters[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char row2_of_letters[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char row3_of_letters[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    int iterator1 = 0;
    int iterator2 = 0;
    int char_position;
    int is_char_found;
    int distance;
    int length_of_message = strlen(message);

    char letter_for_decryption;

    char *row1 = row1_of_letters;
    char *row2 = row2_of_letters;
    char *row3 = row3_of_letters;
    char *ptrMessage = message;
    char *decrypted_msg = decrypted_message;

    letter_for_decryption = *ptrMessage;
    while( row2_of_letters[distance] != letter_for_decryption ){
        distance = distance + 1;
    }

    for(iterator1 = 0; iterator1 < length_of_message; iterator1++){
    ///Decryption with first row
        is_char_found = 0;
        for(iterator2 = 0; iterator2 < n1; iterator2++){
            if(*(ptrMessage + iterator1) == *(row1 + iterator2)){
                if( (iterator2 - distance) < 0 ) {
                    char_position = n1 - (distance - iterator2);
                    *(decrypted_msg + iterator1) = *(row1 + char_position);
                    is_char_found = 1;
                } else {
                    *(decrypted_msg + iterator1) = *(row1 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
    ///Decryption with second row
        if(is_char_found == 0) {
            for(iterator2 = 0; iterator2 < n2; iterator2++){
            if(*(ptrMessage + iterator1) == *(row2 + iterator2)){
                if( (iterator2 - distance) < 0 ) {
                    char_position = n2 - (distance - iterator2);
                    *(decrypted_msg + iterator1) = *(row2 + char_position);
                    is_char_found = 1;
                } else {
                    *(decrypted_msg + iterator1) = *(row2 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
    ///Decryption with third row
        if(is_char_found == 0) {
                for(iterator2 = 0; iterator2 < n3; iterator2++){
            if(*(ptrMessage + iterator1) == *(row3 + iterator2)){
                if( (iterator2 - distance) < 0 ) {
                    char_position = n3 - (distance - iterator2);
                    *(decrypted_msg + iterator1) = *(row3 + char_position);
                    is_char_found = 1;
                } else {
                    *(decrypted_msg + iterator1) = *(row3 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
        if(is_char_found == 0) {
            *(decrypted_msg + iterator1) = *(ptrMessage + iterator1);
                }
            }
        }
    }
    printf("\n=====DECRYPTED MESSAGE=====\n\n%s\n", decrypted_message);
}
