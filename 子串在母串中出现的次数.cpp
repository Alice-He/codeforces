#include <stdio.h>
#include <stdlib.h>
#define N 80

int fun(char *str, char *substr)
{//请在这个函数里面修改你的代码
    //printf("%s\n %s\n",str,substr);
	int i, j, k, num = 0;
	for(i = 0; str[i]; i++){
        //printf("%d\n",i);
		for(j = i, k = 0; substr[k] == str[j]&&str[j]; k++,j++)
		{
			if(substr[k+1] == '\0')
			{
				num++;
                //printf("%d\n",j);
			}
		}
    }
	return num;
}
int main()
{
	char str[N], substr[N];
	gets(str);
	gets(substr);
	printf("%d\n", fun(str, substr));
	return 0;
}
