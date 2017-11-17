/*Hieu Ngo
11/8/2017
C program to find possible routes and the shortest one*/
#include <stdio.h>
#include <string.h>
#define SIZE 14
#define SIZE1 30

void distanceData(int [][SIZE]); 		//store the routes' length in a 2D array
void printTab(int [][SIZE]);			//print the table for checking
void takeInput(char [],char []);		//take user's input for begin and destination
int cityToNum(char []);				//convert the city name to the associate number
void validate(int *,int *,char [],char []);			//take input and validate
void findRoute(int [][SIZE],int [SIZE1][SIZE1],int,int,int *); 		//find all the route possible
int main()
{
	int array[SIZE][SIZE] = {0},i=0,j=0,startingPoint = 0,routeNum=0;
	char beginCity[SIZE1],desCity[SIZE1];
	int beginNum, desNum;
	int routeArray[SIZE1][SIZE1];
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			*(*(routeArray+i) + j) = -1;
		}
	} 
	distanceData(array); 						//store the routes' length in a 2D array
	printTab(array);							//print the table for checking
	validate(&beginNum,&desNum,beginCity,desCity);	//take input and validate
	printf("%d %d \n",beginNum,desNum);
	for(i=0;i<SIZE;i++)	
	{
		routeArray[i][0] = beginNum;	
	}
	findRoute(array,routeArray,beginNum,desNum,&startingPoint);
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			printf("%5d ",*(*(routeArray+i) + j));
		}
		printf("\n");
	} 
	return 0;
}
void distanceData(int array[][SIZE]) 		//store the routes' length in a 2D array
{
	array[0][1] =808 ;
	array[0][9] =2060 ; 
	array[1][0] = 808;
	array[1][2] = 414; 
	array[1][8] = 2257;
	array[2][1] = 414; 
	array[2][3] = 272;
	array[2][6] = 1440; 
	array[3][2] = 272;
	array[3][9] = 1780; 
	array[4][8] = 1771;
	array[5][7] = 792; 
	array[6][2] = 1440;
	array[6][7] = 949; 
	array[6][10] = 517;
	array[6][11] = 1614; 
	array[7][5] = 792;
	array[7][6] = 949; 
	array[7][11] = 1217;
	array[8][1] = 2257; 
	array[8][4] = 1771;
	array[8][12] = 811; 
	array[9][0] = 2060;
	array[9][3] = 1780; 
	array[9][10] = 948;
	array[9][13] = 1423; 
	array[10][6] = 517;
	array[10][9] = 948; 
	array[11][6] = 1614;
	array[11][7] = 1217; 
	array[11][12] = 237;
	array[12][8] = 811; 
	array[12][11] = 237;
	array[13][9] = 1423;
}

void printTab(int array[][SIZE])			//print the table for checking
{
	int i=0,j=0;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			printf("%5d ",*(*(array+i) + j));
		}
		printf("\n");
	} 
}

void takeInput(char beginCity[SIZE1],char desCity[SIZE1])	//take user's input for begin and destination
{
	printf("Enter your begining city: ");
	scanf(" %s",beginCity);
	printf("Enter your destination: ");
	scanf(" %s",desCity);
	printf("%s %s\n", beginCity,desCity);
}

int cityToNum(char str[])				//convert the city name to the associate number
{
	int num=-1;
	if(!(strcmp(str,"seattle")))
		num= 0;
	else if(!(strcmp(str,"sanfrancisco")))
		num= 1;
	else if(!(strcmp(str,"losangeles")))
		num= 2;
	else if(!(strcmp(str,"lasvegas")))
		num= 3;
	else if(!(strcmp(str,"phoenix")))
		num= 4;
	else if(!(strcmp(str,"oklahoma")))
		num= 5;
	else if(!(strcmp(str,"dallas")))
		num= 6;
	else if(!(strcmp(str,"miineapolis")))
		num= 7;
	else if(!(strcmp(str,"milwaukee")))
		num= 8;
	else if(!(strcmp(str,"chicago")))
		num= 9;
	else if(!(strcmp(str,"neworleans")))
		num= 10;
	else if(!(strcmp(str,"nyc")))
		num= 11;
	else if(!(strcmp(str,"washingtondc")))
		num= 12;
	else if(!(strcmp(str,"miami")))
		num= 13;
	return num;
}

void validate(int *beginNum,int *desNum,char beginCity[],char desCity[])	//validate the input
{//take input and validate
	do
	{
		if(*desNum ==-1 || *beginNum == -1)
			printf("One of your input is invalid. Enter again.\n");
		takeInput(beginCity,desCity);		//take user's input for begin and destination
		*beginNum = cityToNum(beginCity);	//convert the city name to the associate number
		*desNum = cityToNum(desCity);		//convert the city name to the associate number

	}while(*desNum ==-1 || *beginNum == -1);
	
}
//find all the route possible
//loop 1st time to find route 0,recursively find route 0
//outside loop to check if another route is available
void findRoute(int array[][SIZE],int routeArray[SIZE1][SIZE1],int begin,int destin,int *save) 		
{
	//need a 2D array to store the route we found
	//the route cannot go back to where we have gone
	//once found a new j, compare it to everything inside the array of that route
	//ex: route 0, point 3, check point 0,point 1,point 2.
	static int routeNum = 0;
	int i=0,j=0,isPassedBy=0;
	printf("Recursive: route %d begin %d end %d\n",routeNum,begin,destin);
	for(j=0;j<SIZE;j++)
	{
		//printf("j=%d begin is %d\n",j,begin);				
		for(i=0;i<SIZE;i++)				//check every element in the route
		{
			if(j == routeArray[routeNum+1][i])
				{isPassedBy=1;}
		}
		//printf("isPassed %d\n",isPassedBy);				
		if(array[begin][j] == 0 || isPassedBy)
		{
			isPassedBy=0;
 			continue;
		}
		else 
		{	//start finding the route, this is 1 route
			if(j==destin)		//we got the route, this is end of route
			{
				printf("END Go from %d to %d: %d miles save is %d route is %d \n", begin, destin, array[begin][destin],*save,routeNum);
				//remember j
				(*save)++;			
				routeArray[routeNum+1][*save]= j;
				//(*routeNum)++;
				for(i=0;i< *save;i++)
				{
				routeArray[routeNum+2][i]= routeArray[routeNum+1][i] ;
				}
				(*save)-=2;
				for(i=0;i<SIZE;i++)
				{
					for(j=0;j<SIZE;j++)
					{
						printf("%5d ",*(*(routeArray+i) + j));
					}
					printf("\n");
				} 
				(routeNum)++;
			}
			else //this is not the route, have to find branch from j to find the route
			{
			//this is when u branch a route
				printf("j=%d begin is %d\n",j,begin);
				(*save)++;			
				printf("Go from %d to %d: %d miles save is %d route is %d\n",begin,j,array[begin][j],*save,routeNum);
				//remember j
				routeArray[routeNum+1][*save]= j;
				findRoute(array,routeArray,j,destin,save);
			}
		}
	}
	printf("End recursive: begin %d end %d\n",begin,destin);
}

//loop outside once to find the beginning of the route
//then recursive

