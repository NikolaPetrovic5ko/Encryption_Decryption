#include <stdio.h>
#include <string.h>
#include "encr_decr.h"

char encrypted_message[100] = "";

void encryption(char *message){

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

    printf("\n===Input a letter for encryption.===\nLetter must be from the second row of the keyboard.\nLETTER: ");
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
    printf("=====ENCRYPTED MESSAGE=====\n%s\n", encrypted_message);
}
