#include <stdio.h>
#include <string.h>
#include "encr_decr.h"

/*!
*  @brief This function decrypt the message given by user
*  @author Nikola Petrovic
*  @param *message We are getting the message added by user from this parameter
*/

void decryption(char *message){

    /// This represent an empty string where we are going to put our decrypted message.
    char decrypted_message[100] = "";

    /// Number of characters in a row. Row is given by number next to 'n'.
    int n1 = 10;
    int n2 = 9;
    int n3 = 7;

    /// Arrays of characters which are located in a given row.
    char row1_of_letters[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char row2_of_letters[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char row3_of_letters[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    int iterator1 = 0;
    int iterator2 = 0;
    int char_position;
    int is_char_found;
    int distance;
    /// Getting a length of message.
    int length_of_message = strlen(message);

    /// Shows the position of letter 'a' in decrypted message.
    char letter_for_decryption;

    /// Pointers to given arrays and strings.
    char *row1 = row1_of_letters;
    char *row2 = row2_of_letters;
    char *row3 = row3_of_letters;
    char *ptrMessage = message;
    char *decrypted_msg = decrypted_message;

    /// Letter for decryption is a first letter of a given message.
    letter_for_decryption = *ptrMessage;
    /// Calculate the distance between 'a' and letter for decryption.
    while( row2_of_letters[distance] != letter_for_decryption ){
        distance = distance + 1;
    }

    /// Starting from the first character of message.
    for(iterator1 = 0; iterator1 < length_of_message; iterator1++){
    /// Decryption with first row
        is_char_found = 0;
        /// Starting from the first character of the first row.
        for(iterator2 = 0; iterator2 < n1; iterator2++){
            if(*(ptrMessage + iterator1) == *(row1 + iterator2)){
                /// <b>Creating a circular moving for first row</b>
                if( (iterator2 - distance) < 0 ) {
                    /// If position of a character is smaller than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = n1 - (distance - iterator2);
                    /// In position of character of a given message insert decrypted character.
                    *(decrypted_msg + iterator1) = *(row1 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not smaller than the number of characters in a row, inserting of decrypted character is proceed like this.
                    *(decrypted_msg + iterator1) = *(row1 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
    /// Decryption with second row
        if(is_char_found == 0) {
            /// Starting from the first character of the second row.
            for(iterator2 = 0; iterator2 < n2; iterator2++){
            if(*(ptrMessage + iterator1) == *(row2 + iterator2)){
                /// <b>Creating a circular moving for second row</b>
                if( (iterator2 - distance) < 0 ) {
                    /// If position of a character is smaller than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = n2 - (distance - iterator2);
                    /// In position of character of a given message insert decrypted character.
                    *(decrypted_msg + iterator1) = *(row2 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not smaller than the number of characters in a row, inserting of decrypted character is proceed like this.
                    *(decrypted_msg + iterator1) = *(row2 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
    /// Decryption with third row
        if(is_char_found == 0) {
            /// Starting from the first character of the third row.
            for(iterator2 = 0; iterator2 < n3; iterator2++){
            if(*(ptrMessage + iterator1) == *(row3 + iterator2)){
                /// <b>Creating a circular moving for third row</b>
                if( (iterator2 - distance) < 0 ) {
                    /// If position of a character is smaller than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = n3 - (distance - iterator2);
                    /// In position of character of a given message insert decrypted character.
                    *(decrypted_msg + iterator1) = *(row3 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not smaller than the number of characters in a row, inserting of decrypted character is proceed like this.
                    *(decrypted_msg + iterator1) = *(row3 + iterator2 - distance);
                    is_char_found = 1;
                }
            }
        }
        if(is_char_found == 0) {
            /// If character is not found in any of given rows, just insert a character from a given message.
            *(decrypted_msg + iterator1) = *(ptrMessage + iterator1);
                }
            }
        }
    }
    printf("\n=====DECRYPTED MESSAGE=====\n\n%s\n", decrypted_message);
}

