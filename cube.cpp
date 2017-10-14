extern "C" {
#include "cubedefs.h"
}
#include"final.h"
#include<cstdio>
int main(int argc,char** str)
{
	int icolours[54];
	char colours[54],positions[68],moves[60]="",mv[60],in[60];
	getcolour(colours,positions);
	//printf("Successfully identified colours \n");
	vksolve(positions,moves);
	//printf("Solved the cube \n");
	//printf("%s\n",moves);
	colour2num(colours,icolours);
	//printf("Converted the colour to integers \n");
	getmoves(moves,mv);
	//printf("Converted the moves ,about to draw  \n");
	//printf("Printing from cube.cpp\n");
	//printf("%s",moves);
	draw(argc,str,icolours,mv);
	//printf("Completed the program \n");
	return 0;
}
