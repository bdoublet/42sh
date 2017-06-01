#include "structure.h"

void FreeMal(void* ptr1, void* ptr2, void* ptr3)
{
  if (ptr1 != NULL)
    free(ptr1);
  if (ptr2 != NULL)
    free(ptr2);
  if (ptr3 != NULL)
    free(ptr3);
}

void ShLoop(void)
{
  char* line = malloc(sizeof (char) * 256);
  if (!line)
    fprintf(stderr, "Fail Malloc\n");

  do 
  {
    printf("42sh> ");
    line = ReadLine();
  }
  while (strcmp(line, "exit\n"));
  FreeMal(line, NULL, NULL);
}

char* ReadLine(void)
{
  size_t len = 0;
  char* buffer = NULL;
  int error = 0;

  error = getline(&buffer, &len, stdin);
  printf("%s\n", buffer);
  if (error < 0)
    fprintf(stderr, "Error getline function\n");

  return buffer;
}

int cmp_substring(char* comparefrom, char* compareto)
{
  unsigned int i = 0;

  if (!comparefrom || !compareto)
    return -1;

  while (comparefrom[0] == '-')
  {
    comparefrom++;
    i++;
  }
  if (i != 2)
    return 0;

  i = 0;
  while (comparefrom[i] != '\0')
  {
    if (comparefrom[i] != compareto[i])
      return 0;
    i++;
  }
  return 1;
}


int main (int argc, char** argv)
{
  struct VarEnv* varenv = malloc(sizeof (struct VarEnv));
  char* arg = malloc(sizeof (char) * 256);

  if (!arg)
    fprintf(stderr, "Fail Malloc\n");

	for (int i = 1; i < argc; i++)
  {
    if (cmp_substring(argv[i], "version"))
    {
      printf("Version %.1f\n", SH_VERSION);
      return 0;
    }

    if (cmp_substring(argv[i], "ast-print"))
      varenv->ast_printer = 1;
    if (cmp_substring(argv[i], "norc"))
      varenv->norc = 1;
    if (!strcmp(argv[i], "-c"))
    {
      strcpy(argv[i + 1], arg);
      //lexeur(arg);
      return 0;
    }
      //Read commands from the command_string operand. Set the value of special
      //parameter 0 (see Special Parameters) from the value of the command_name
      //operand and the positional parameters ($1, $2, and so on) in sequence
      //from the remaining argument operands. No commands shall be read from the 
      //standard input.
  }
  ShLoop();
  FreeMal(arg, NULL, NULL);
  return 0;
}