/*Hieu Ngo
09/18/2017
lab2 part 3*/

#include <stdlib.h>
#include <stdio.h>
#define CDPLAYERPRICE 275.00
#define	REMOTEPRICE 49.50
#define	TAPERECORDER 185.00
#define	TVPRICE 300.00
#define	VCRPRICE 215.00
#define	TAXRATE 6.25

int main()
{
	//declare variables
	int cdPlayer=0, remote=0, tapeRecorder=0, TV=0, VCR=0;
	float cdPlayerTotal,remoteTotal,tapeTotal,tvTotal,vcrTotal,subTotal,total,tax; 
	//ask users for input 
	printf("How Many CD players Were Sold? ");
	scanf("%d",&cdPlayer);
	printf("How Many Remotes Were Sold? ");
	scanf("%d",&remote);
	printf("How Many Tape Recorders Were Sold? ");
	scanf("%d",&tapeRecorder);
	printf("How Many TVs Were Sold? ");
	scanf("%d",&TV);
	printf("How Many VCRs Were Sold? ");
	scanf("%d",&VCR);
	
	//calculate cost base on user input
	cdPlayerTotal = cdPlayer*CDPLAYERPRICE;
	remoteTotal=remote*REMOTEPRICE;
	tapeTotal=tapeRecorder*TAPERECORDER;
	tvTotal=TV*TVPRICE;	
	vcrTotal=VCR*VCRPRICE;
	subTotal= cdPlayerTotal+remoteTotal+tapeTotal+tvTotal+vcrTotal;
	tax = subTotal * TAXRATE / 100;
	total = subTotal*(100 + TAXRATE) / 100 ;

	//print out final results
	printf("QTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE\n");
	printf("---\t-----------\t----------\t-----------\n");
	printf("%d\tCD Players\t%10.2f\t%10.2f\n",cdPlayer,CDPLAYERPRICE,cdPlayerTotal);	
	printf("%d\tRemotes\t\t%10.2f\t%10.2f\n",remote,REMOTEPRICE,remoteTotal);
	printf("%d\tTape Players\t%10.2f\t%10.2f\n",tapeRecorder,TAPERECORDER,tapeTotal);
	printf("%d\tTV\t\t%10.2f\t%10.2f\n",TV,TVPRICE,tvTotal);
	printf("%d\tVCR\t\t%10.2f\t%10.2f\n",VCR,VCRPRICE,vcrTotal);
	printf("\t\t\t\t-----------\n");
	printf("\t\t\tSUBTOTAL\t%10.2f\n",subTotal);
	printf("\t\t\tTAX\t\t%10.2f\n",tax);
	printf("\t\t\tTOTAL\t\t%10.2f\n",total);
	return 0;
}


