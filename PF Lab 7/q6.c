#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 

int main() {
    char input_str[256];
    char encoded_str[512] = ""; 
    int frequency[256] = {0};   
    int visited[256] = {0};     

    printf("--- Character Frequency Encoder ---\n");
    printf("Enter a string to encode: ");
    scanf("%[^\n]", input_str);

    for (int i = 0; i < strlen(input_str); i++) {
        if (input_str[i] == ' ') {
            continue; 
        }
        frequency[(int)input_str[i]]++;
    }

    int encoded_len = 0;
    for (int i = 0; i < strlen(input_str); i++) {
        char current_char = input_str[i];
        
        if (current_char == ' ' || visited[(int)current_char]) {
            continue;
        }

        encoded_len += sprintf(encoded_str + encoded_len, "%c%d", current_char, frequency[(int)current_char]);
        
        visited[(int)current_char] = 1;
    }

    printf("Encoded Output -> %s\n", encoded_str);

    char encoded_input[512];
    char decoded_str[256] = ""; 
    
    printf("\n--- Character Frequency Decoder ---\n");
    printf("Enter the encoded string to decode: ");
    scanf("%s", encoded_input); 

    int i = 0; 
    int decoded_idx = 0; 

    while (i < strlen(encoded_input)) {
        char char_to_repeat = encoded_input[i];
        i++; 

        char num_buffer[10];
        int num_idx = 0;
        while (i < strlen(encoded_input) && isdigit(encoded_input[i])) {
            num_buffer[num_idx++] = encoded_input[i++];
        }
        num_buffer[num_idx] = '\0'; 

        int count = atoi(num_buffer);

        for (int j = 0; j < count; j++) {
            decoded_str[decoded_idx++] = char_to_repeat;
        }
    }
    decoded_str[decoded_idx] = '\0'; 

    printf("Decoded Output -> %s\n", decoded_str);

    return 0;
}