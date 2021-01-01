#include <stdio.h>
#include <stdint.h>
#include <errno.h>

int
main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("error\n");
    return 1;
  }
  FILE* input = fopen(argv[1], "r");
  if (input == NULL)
    {
      perror(NULL);
      return 1;
    }
  FILE* output = fopen(argv[2], "w");
  if (output == NULL)
    {
      perror(NULL);
      return 1;
    }
  uint8_t buffer[512];
  const size_t buffer_size = 512;
  size_t read_size = 0;
  while ((read_size = fread(buffer, 1, buffer_size, input)) > 0)
    {
      fwrite(buffer, 1, read_size, output);
    }
  fclose(input);
  fclose(output);
  return 0;
}
