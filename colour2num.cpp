#include"final.h"
void colour2num(char *colours,int* vikas)
{
	int i=0;
	char c;
	while(colours[i]!='\0')
	{
		switch(colours[i])
		{
			case 'R':
			c=1;
			break;
			case 'G':
			c=2;
			break;
			case 'O':
			c=3;
			break;
			case 'B':
			c=4;
			break;
			case 'Y':
			c=5;
			break;
			case 'W':
			c=6;
			break;
		}
		vikas[i]=c;
		i++;
	}
}



