#include <stdio.h>
#include <string.h>
#include "encr_decr.h"

/*!
*  @brief This funtion encrypt the message given by user
*  @author Nikola Petrovic
*  @param *message We are getting the message added by user from this parameter
*/

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
                    /// Napisi ovde nesto o ovom dole
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

