#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include<time.h>
#define MAX 9
int cow = 0;
int bull = 0;
int num;
int arr1[5] , *arr , *a  ;
char ch[100];
int aor[5];
int aor1[5];
long get_random(int n){
	srand(time(0)); // seed with time
	if(n > MAX) return -1; // we can only generate 9 digit random number
	int a[MAX];
	for(int i = 0; i < MAX; i++) a[i] = i + 1;
	long result = 0;
	for(int i = 0; i < n; i++){
		int pos = (rand()) % (MAX - i); // selecting random position of array withing present
		result = result * 10 + a[pos];
		for(int j = pos; j < MAX - 1; j++) a[j] = a[j + 1]; // removing selected number by shifting left
	}
	return result;
}
int * convertNumberIntoArray(int number) {
    int i = 0;
    int rev[5];
    while(number > 0)
    {
        rev[i++] = number % 10;
        number /= 10;
    }
    for(int j = 0 ; j < 4 ; j++)
    {
        aor[3 - j] = rev[j] ;  
    }
    return aor;
}
int * convert(int number1) {
    int i = 0;
    int rev1[5];
    while(number1 > 0)
    {
        rev1[i++] = number1 % 10;
        number1 /= 10;
    }
    for(int j = 0 ; j < 4 ; j++)
    {
        aor1[3 - j] = rev1[j] ;  
    }
    return aor1;
}
int bullfun(int a[] , int arr[])
{
for(int i = 0 ; i < 4 ; i++)
{
if(a[i] == arr[i])
        bull++;
}
}
int cowfun(int a[] , int arr[])
{
        for(int i = 0 ; i < 4 ; i++)
{
for(int j = 0 ; j < 4 ; j++)
{
        if(a[i] == arr[j])
                cow++;
}
}
}
int main()
{
int onum , choice , rnum;
printf("press 1 to play with pc \npress 2 to play with oponent \npress 3 for exit\n");
scanf("\n%d" , &choice);
switch(choice)
{
	case 1:
	rnum = get_random(4);
	//printf("%d" , rnum);
	a = convert(rnum);
		break;
	case 2:
	printf("enter number for your oponent to guess\n");
	scanf("%d",&onum);
	printf("\e[1;1H\e[2J");
	a = convert(onum);
		break;
	default: 
		printf("thank you\n");
		exit(0);
}	
printf("enter your name to start game\n");
scanf("%s",ch);
printf("ok play now %s \n",ch); 
while(1)
{
scanf("%d",&num);
arr = convertNumberIntoArray(num);
cowfun(a , arr);
bullfun(a , arr);
printf("cow = %d\n" , (cow - bull));
printf("bull = %d\n" , bull);
if(bull == 4)
{
   printf("you win %s\n" ,ch);exit(0);
}
cow = 0;
bull = 0;
}
return 0;
}
