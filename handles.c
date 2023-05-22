#include "main.h"

/**
 * hashtag - removes anything after # sign
 * @str: string
 * Return: nothing (# only)
 */
void hashtag(char *str)
{
        int index;

        index = 0;
        while(str[index] != '\0')
        {
                if (str[index] == 35)
                {
                        str[index] = '\0';
                }
                index++;
        }
}                           

