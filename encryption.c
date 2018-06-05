#include <stdio.h>
#include <string.h>
#include "encr_decr.h"

/*!
*  @brief This function encrypt the message given by user
*  @author Nikola Petrovic
*  @param *message We are getting the message added by user from this parameter
*/

void encryption(char *message){

    /// This represent an empty string where we are going to put our encrypted message.
    char encrypted_message[100] = "";

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

    /// Shows the position of letter 'a' in encrypted message.
    char letter_for_encryption;

    /// Pointers to given arrays and strings.
    char *row1 = row1_of_letters;
    char *row2 = row2_of_letters;
    char *row3 = row3_of_letters;
    char *ptrMessage = message;
    char *encrypted_msg = encrypted_message;

    printf("\n===Input a letter for encryption.===\nLetter must be from the second row of the keyboard.\nLETTER: ");
    scanf("%c",&letter_for_encryption);
    /// Calculate the distance between 'a' and letter for encryption that is introduced by user.
    while( row2_of_letters[distance] != letter_for_encryption ){
        distance = distance + 1;
    }

    /// Starting from the first character of message.
    for(iterator1 = 0; iterator1 < length_of_message; iterator1++){
    /// Encryption with first row
        is_char_found = 0;
        /// Starting from the first character of the first row.
        for(iterator2 = 0; iterator2 < n1; iterator2++){
            if(*(ptrMessage + iterator1) == *(row1 + iterator2)){
                /// <b>Creating a circular moving for first row</b>
                if( (iterator2 + distance) >= n1 ) {
                    /// If position of a character is greater than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = (iterator2 + distance) - n1;
                    /// In position of character of a given message insert encrypted character.
                    *(encrypted_msg + iterator1) = *(row1 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not greater than the number of characters in a row, inserting of encrypted character is proceed like this.
                    *(encrypted_msg + iterator1) = *(row1 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
    /// Encryption with second row
        if(is_char_found == 0) {
            /// Starting from the first character of the second row.
            for(iterator2 = 0; iterator2 < n2; iterator2++){
            if(*(ptrMessage + iterator1) == *(row2 + iterator2)){
                /// <b>Creating a circular moving for second row</b>
                if( (iterator2 + distance) >= n2 ) {
                    /// If position of a character is greater than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = (iterator2 + distance) - n2;
                    /// In position of character of a given message insert encrypted character.
                    *(encrypted_msg + iterator1) = *(row2 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not greater than the number of characters in a row, inserting of encrypted character is proceed like this.
                    *(encrypted_msg + iterator1) = *(row2 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
    /// Encryption with third row
        if(is_char_found == 0) {
            /// Starting from the first character of the third row.
            for(iterator2 = 0; iterator2 < n3; iterator2++){
            if(*(ptrMessage + iterator1) == *(row3 + iterator2)){
                /// <b>Creating a circular moving for third row</b>
                if( (iterator2 + distance) >= n3 ) {
                    /// If position of a character is greater than the number of characters in a row, position of a that character is calculated with this formula.
                    char_position = (iterator2 + distance) - n3;
                    /// In position of character of a given message insert encrypted character.
                    *(encrypted_msg + iterator1) = *(row3 + char_position);
                    is_char_found = 1;
                } else {
                    /// If position of a character is not greater than the number of characters in a row, inserting of encrypted character is proceed like this.
                    *(encrypted_msg + iterator1) = *(row3 + iterator2 + distance);
                    is_char_found = 1;
                }
            }
        }
        if(is_char_found == 0) {
            /// If character is not found in any of given rows, just insert a character from a given message.
            *(encrypted_msg + iterator1) = *(ptrMessage + iterator1);
                }
            }
        }
    }
    printf("=====ENCRYPTED MESSAGE=====\n%s\n", encrypted_message);
}
