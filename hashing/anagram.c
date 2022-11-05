#include <stdio.h>

int a[52];

int anagram(char* s, char* t)
{
    while(*s != '\0')
    {
        if (*s >= 65 && *s <= 90)
        {
            a[*s - 65]++;
            s++;
        }else if (*s >= 97 && *s <= 122)
        {
            a[*s - 97 + 26]++;
            s++;
        }
    }

    while(*t != '\0')
    {
        if (*t >= 65 && *t <= 90)
        {
            a[*t - 65]--;
            t++;
        }else if (*t >= 97 && *t <= 122)
        {
            a[*s - 97 + 26]--;
            t++;
        }
    }

    int i;
    for(i = 0; i < 26; i++)
    {
        if(a[i])
        {
            return 0;
        }
    }
    return 1;
    
}

int main(int argc, char const *argv[])
{
    char* s1 = "czMdXFabcQc";
    char* s2 = "McFabcdczQX";

    // printf("%d", 'Z');

    if(anagram(s1, s2))
    {
        printf("Given strings are anagram");
    }else
    {
        printf("Given stings are not anagram");
    }
    return 0;
}
