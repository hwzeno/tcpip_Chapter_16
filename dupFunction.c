/*********************************
    > File Name: dupFunction.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月27日 星期日 13时37分40秒
 ********************************/
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv)
{
	int cfd1, cfd2;
	char str1[] = "Hi\n";
	char str2[] = "It's a nice day\n";

	cfd1 = dup(1);
	cfd2 = dup2(cfd1, 7);
	printf("fd1 = %d, fd2 = %d\n", cfd1, cfd2);
	write(cfd1, str1, sizeof(str1));
	write(cfd2, str2, sizeof(str2));

	close(cfd1);
	close(cfd2);

	write(1, str1, sizeof(str1));
	close(1);
	write(1, str2, sizeof(str2));
	return 0;
}
