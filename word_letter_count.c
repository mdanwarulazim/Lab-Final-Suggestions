/***************************************************

Write a C program that counts the letter of each word
of a sentence and displays which word has the maximum
letters.

Sample Input
------------
Enter a sentence: Good Morning Everyone!

Sample Output
------------
Word 1 has 4 letters
Word 2 has 7 letters
Word 3 has 9 letters

Word 3 has the maximum letters: 9

***************************************************/

#include <stdio.h>

void word_compare(char *str){
    char *s = str;

    int word_count=0;

    while (*s!='\0'){
        if (*s=='\n'){
            *s=' ';
        }
        s++;
    }

    s = str;

    int len=0;

    while (*s!=' '){
        len++;
        s++;
    }

    word_count+=1;
    int max = len;
    int max_word_position = word_count;

    printf("Word %d has %d letters\n", word_count, len);

    

    char *i;


    while (*s!='\0'){
        if (*s == ' '){

            i= s+1;
            len = 0;


            while (*i != ' '){
                if (*i=='\0'){
                    printf("\nWord %d has the maximum letters: %d\n", max_word_position, max);
                    return;
                }
                len++;
                i++;
            }

            if (*i == ' '){
                word_count+=1;
                printf("Word %d has %d letters\n", word_count, len);
            }

            if (len >= max){
                max = len;
                max_word_position = word_count;
            }

            s=i;

        }
    }



}
int main(){

    char str[30];
    int count=0;
    int i=0, j, len=0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);


    word_compare(str);

    return 0;
}