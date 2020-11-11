#include <stdio.h>

void function(char *source, char *integers, char *nonInteger)
{
	int i = 0, i1 = 0, i2 = 0;

	for( ; source[i] != '\0'; i++)
	{
		if(source[i] >= 48  && source[i] <= 57)
		{
			integers[i1] = source[i];
			i1++;
		}
		else
		{	
			nonInteger[i2] = source[i];
			i2++;
		}
		integers[i1] = '\0';
		nonInteger[i2] = '\0';
	}
}
int main()
{
	char source[] = "Helloworld123123!!!777";
	char integers[256];
	char nonIntegers[256];


	function(source, integers, nonIntegers);
	printf("source:%s\n", source);
	printf("integers:%s\nnonintegers:%s\n", integers, nonIntegers);

	return 0;
}




