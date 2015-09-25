#include <stdio.h>

int is_letter(char ch)
{
	return (ch >= 'a') && (ch <= 'z');
}

int main()
{
    char *line = NULL;
    char *line_longest = NULL;
    size_t size;
    int length = getline(&line, &size, stdin);
    int longest = -1;

    // const char s[2] = " ";
    // char *token;

    while (length != -1)
    {
    	// token = strtok(line, s);
    	// while( token != NULL )
	    // {
	    //   printf( "%s\n", token );
	    //   token = strtok(NULL, s);
	    // }

    	if (length > longest)
    	{
    		longest = length;
    		line_longest = line;
    		// printf("%s", line);
	     //    printf("characters %d\n", length);
	     //    printf("sizeof %lu\n", sizeof(line));
	     //    printf("\n");
    	}
        length = getline(&line, &size, stdin);
    }
    // printf("\n");
    char word[longest];
    int i;
    int count = 0;
    for(i=0; i<longest; i++)
    {
    	if (is_letter(line_longest[i]))
    	{
    		word[count] = line_longest[i];
    		count++;
    	}
    }
    printf("%s\n", word);
    printf("characters %d\n", count);
    // printf("%s\n", line_longest);
    // printf("characters %d\n", longest);
    // printf("%c%c%c%c\n", line_longest[6], line_longest[6], line_longest[6], line_longest[6]);
    return 0;
}

// int main()
// {
// 	printf("%d\n", is_letter('a'));
// 	printf("%d\n", is_letter('1'));
// 	printf("%d\n", is_letter('z'));
// 	printf("%d\n", is_letter(' '));
// 	printf("%d\n", is_letter('j'));
// 	printf("%d\n", is_letter('-'));
// 	return 0;
// }

