void reverse_words()
{
  char input_str[] ="the sky is blue";
  int str_len = strlen(input_str);
  char delimiter = ' ';
  char word_split[100000][10000];
  int k = 0, j, i;
  int num_of_words = 0;

 
  for(i = 0, j  =0 , k = 0; str_len; i++)
  {
   
    if(input_str[i] != delimiter)
    {
      word_split[num_of_words][j] = input_str[i];
      j++;
      k = 0;
    }
    else
    {
      if(k == 0)
      {
        k = 1;
        word_split[num_of_words][j+1] = '\0';
        j = 0;
        num_of_words++;
      }
    }
  }
  word_split[num_of_words][j+1] = '\0';
 
  for(i = num_of_words; i >=0; i--)
  {
    printf("%s ", word_split[i]);
  }
}

int main() {
  char input_arr[] ="the sky is blue";
 // scanf("%s\n", input_arr);
 printf("%s\n", input_arr);
 printf("%c", input_arr[0]);
 
 reverse_words();
 
  return 0;
}
