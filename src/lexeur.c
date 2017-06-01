#include "structure.h"
#define DELIMITER " \t\r\n"

char** lexeur(char* command)
{
	unsigned int buffersize = 256;
	unsigned int pos = 0;
	char** token = malloc(sizeof (char*) * buffersize);
	char* element = NULL;

	if (!token)
	{
      fprintf(stderr, "Fail Malloc\n");
      exit(-1);
    }

    /* 
    ** Search into the list of token DELIMITER which one appears in string command.
    ** After found this, strtok is gonna to split the string till the delimiter,
    ** it replace the character delimiter by NULL.
    */
    element = strtok(command, DELIMITER);
    while (token != NULL)
    {
      token[pos] = element;
      pos++;

      if (pos >= buffersize)
      {
      	buffersize += 256;

      	token = realloc(token, buffersize * sizeof(char*));
      	if (!token)
	      {
          fprintf(stderr, "Fail Malloc\n");
          exit(-1);
        }
      }
      /* 
      ** Considering that NULL was put at the end of the token, we can easily get the
      ** next token thanks to NULL which is passed as argument.
      ** Indeed, strtok maintains a static pointer to it previous passed string
      */
      element= strtok(NULL, DELIMITER);
    }
    token[pos] = NULL;
    return token;
}