#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main (void) {

    string text = get_string("Your Text Here: ");

    int textLength = strlen(text);

    int words = 0;
    int letters = textLength;
    int sentences = 0;

    for (int i = 0; i < textLength; i++) {
        if (text[i] >= ' ' && text[i] <= '@') {
            letters--;
        }
        if (text[i] == ' ') {
            words++;
        }
        if (i == textLength - 1 && text[i] == '.') {
            words++;
        }
        if (text[i] == '.' || text[i] == '?') {
            sentences++;
        }
    }

    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);



    if (grade >= 16) {
        printf("Grade 16+\n");
    }
    else if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %d\n", grade);
    }

}