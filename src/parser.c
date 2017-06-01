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

  do 
  {
    printf("42sh> ");
    line = ReadLine();
  }
  while (strcmp(line, "exit"));
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

int main (int argc, char** argv)
{
  struct VarEnv* varenv = malloc(sizeof (struct VarEnv));
	for (int i = 0; i < argc; i++)
  {
    if (!strcmp(argv[i], "--version") || !strcmp(argv[i], "--ver"))
      printf("Version %f\n", varenv->version);
    if (!strcmp(argv[i], "--ast-print"))
      varenv->ast_printer = 1;
    if (!strcmp(argv[i], "--norc"))
      varenv->norc = 1;
    if (!strcmp(argv[i], "-c"))
      printf("option -c\n");
      //Read commands from the command_string operand. Set the value of special
      //parameter 0 (see Special Parameters) from the value of the command_name
      //operand and the positional parameters ($1, $2, and so on) in sequence
      //from the remaining argument operands. No commands shall be read from the 
      //standard input.
  }
  ShLoop();
  return 0;
}