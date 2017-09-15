#include <cs50.h>
#include <stdio.h>
#include <string.h> //for string
#include <ctype.h> // for toupper and isalpha
#include <stdlib.h> //for atoi

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("wrong code");
        return 1;
    }

    string k = argv[1];
    int key = atoi(k) % 26;
    
    printf ("plaintext:");
    string s = get_string();
    int n = strlen(s);
    
    //iterate over each char from string
    printf ("ciphertext: ");
    for (int i = 0; i < n; i++) {
        
        if (isalpha(s[i])) {
            
            if (isupper(s[i])) {
                if (s[i] + key > 90) {
                    char cletter = s[i] + key - 26;
                    printf("%c", cletter);
                } else {
                    char cletter = s[i] + key;
                    printf("%c", cletter);
                } 
            }
                
            if (islower(s[i])) {
                if (s[i] + key > 122) {
                    char cletter = s[i] + key - 26;
                    printf("%c", cletter);
                } else {
                    char cletter = s[i] + key;
                    printf("%c", cletter);    
                } 
            }    
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");    
    return 0;
}
