# include "iGraphics.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mode=0;



int menu();
void OpenAcc();
void GiveFeedback();
void ShowFeedback();
void gotoxy(int,int);

typedef struct xx{
int day,month,year;
}date;

typedef struct yy{
int Ttype;
date Tdate;
int amount;
}Transaction;

typedef struct zx{
int AccNo, feedback,history;
char AccName[20];
Transaction THistory[100];
date AccOpenDate;
}Teacher;

Teacher Acc[100];
int idx=0,c=0;
FILE *fp;



void iDraw() {
	if(mode==0)
	{

		//iShowBMP(0,0,"home.bmp");
		iSetColor(0,0,100);
		iFilledRectangle(0,0,800,800);
		iSetColor(0,0,200);
		iFilledRectangle(330,450,100,100);
		iSetColor(0,250,0);
		iText(130,640,"-_-STUDENT FEEDBACK MANAGEMENT-_-",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(180,590,"-_-WELCOME TO OUR SYSTEM-_-",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(345,500,"Log In",GLUT_BITMAP_TIMES_ROMAN_24);

}
    if(mode==1)
	{
		iClear();
		iSetColor(0,0,100);
		iFilledRectangle(0,0,800,800);
		iSetColor(0,0,255);
		iFilledRectangle(0,760,60,40);
		iSetColor(0,250,0);
		iText(7,777,"Back",GLUT_BITMAP_TIMES_ROMAN_24);


		iSetColor(0,250,0);
		iText(150,650,"For which subject teacher will you give feedback?",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0,0,255);
        iFilledRectangle(310,500,150,100);
        iSetColor(0,0,210);
        iFilledRectangle(310,400,150,100);
		iSetColor(0,0,170);
		iFilledRectangle(310,300,150,100);
		iSetColor(0,0,130);
		iFilledRectangle(310,200,150,100);
		iSetColor(0,0,90);
		iFilledRectangle(310,100,150,100);

        iSetColor(0,250,0);

        iText(350,550,"CSE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,450,"EEE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,350,"MATH",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,250,"PHYSICS",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,150,"ME",GLUT_BITMAP_TIMES_ROMAN_24);

	}






	if(mode==2)
	{
		iClear();
		iSetColor(0,0,100);
		iFilledRectangle(0,0,800,800);
		//iShowBMP(0,0,"next.bmp");
		iSetColor(0,0,255);
		iFilledRectangle(0,760,60,40);
		iSetColor(0,250,0);
		iText(70,700,"Type",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(7,777,"Back",GLUT_BITMAP_TIMES_ROMAN_24);



		iLine(0,600,800,600);
		iLine(0,500,800,500);
		iLine(0,400,800,400);
		iLine(0,300,800,300);
		iLine(0,200,800,200);
		iLine(0,100,800,100);

		iLine(190,100,190,800);
		iLine(340,100,340,800);
		iLine(490,100,490,800);
		iLine(640,100,640,800);

		iText(200,700,"Excellent",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,700,"Very Good",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500,700,"Good",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,700,"Poor",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(20,550,"Explanation",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,450,"Presentation",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,350,"Summarization",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,250,"Punctuality",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,150,"Information",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
		iFilledRectangle(350,30,130,60);
		iSetColor(0,250,0);
		iText(373,57,"Submit",GLUT_BITMAP_TIMES_ROMAN_24);

	}



	if(mode==5)
	{
		iClear();
		iSetColor(0,0,100);
		iFilledRectangle(0,0,800,800);
		iShowBMP(0,0,"next.bmp");
		iSetColor(0,250,0);
		iText(70,700,"Type",GLUT_BITMAP_TIMES_ROMAN_24);

		iLine(0,600,800,600);
		iLine(0,500,800,500);
		iLine(0,400,800,400);
		iLine(0,300,800,300);
		iLine(0,200,800,200);
		iLine(0,100,800,100);

		iLine(190,100,190,800);
		iLine(340,100,340,800);
		iLine(490,100,490,800);
		iLine(640,100,640,800);

		iText(200,700,"Excellent",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,700,"Very Good",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500,700,"Good",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(650,700,"Poor",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(20,550,"Explanation",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,450,"Presentation",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,350,"Summarization",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,250,"Punctuality",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20,150,"Information",GLUT_BITMAP_TIMES_ROMAN_24);

	}

	if(mode==3)
	{
		iClear();
		iSetColor(0,0,100);
		iFilledRectangle(0,0,800,800);
		iSetColor(0,0,255);
		iFilledRectangle(0,760,60,40);
		iSetColor(0,250,0);
		iText(7,777,"Back",GLUT_BITMAP_TIMES_ROMAN_24);


	}
	/*if(mode==2 && mode!=3)
	{
		iSetColor(0,255,0);
		iFilledRectangle(190,500,150,100);
	}
	if(mode==3 && mode!=2)
	{
		iSetColor(0,255,0);
		iFilledRectangle(340,500,150,100);
	}*/
}


void iMouseMove(int mx, int my)
 {
}



void iMouse(int button, int state, int mx, int my)
{
   	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&mx>=330&&mx<=430&&my>=450&&my<=550 && !(mx<329 && my>551))
	mode=1;


	//if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&mx>=330&&mx<=430&&my>=450&&my<=550)
	//mode=3;




   // if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&mx>=190&&mx<=340&&my>=500&&my<=600)
	//mode=2;

	/*else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !(mx>=190&&mx<=339&&my>=500&&my<=600) && (mx>=341 && mx<=490 && my>=500&&my<=600) && !(mx>=490 && mx<=640 && my>=500&&my<=600) && !(mx>=640 && mx<=800 && my>=500&&my<=600))
    mode=4;*/


	 else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=310 && mx<=460 && my>=500 && my<=600)
		mode=2;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=0 && mx<=60 && my>=760 && my<=800)
		mode=mode-1;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=350 && mx<=480 && my>=30 && my<=90)
        mode=3;

}


void iKeyboard(unsigned char key) {

	}



void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}

}


void OpenAcc(){
    system("cls");
    printf("Enter ID number: ");
    scanf("%d",&Acc[idx].AccNo);
    printf("Enter teacher name: ");
    scanf("%s",Acc[idx].AccName);
    printf("Enter feedback giving date(DD/MM/YYYY): ");
    scanf("%d%d%d",&Acc[idx].AccOpenDate.day,&Acc[idx].AccOpenDate.month,&Acc[idx].AccOpenDate.year);
    fprintf(fp,"%d %s %d %d %d\n",Acc[idx].AccNo,Acc[idx].AccName,Acc[idx].AccOpenDate.day,Acc[idx].AccOpenDate.month,Acc[idx].AccOpenDate.year);
    Acc[idx].feedback=0,Acc[idx].history=0;idx++;
}
void GiveFeedback(){
     system("cls");
    int accn,mon,i,d,m,y;
    printf("Enter ID number: ");
    scanf("%d",&accn);
    printf("Enter feedback(/marks): ");
    scanf("%d",&mon);
    printf("Enter date(DD/MM/YYYY): ");
    scanf("%d%d%d",&d,&m,&y);
    fprintf(fp,"%d %d %d %d %d\n",accn,mon,d,m,y);
    for(i=0;i<idx;i++)
        if(Acc[i].AccNo==accn){
        Acc[i].feedback+=mon;
        Acc[i].THistory[Acc[i].history].Ttype=1;
        Acc[i].THistory[Acc[i].history].amount=mon;
        Acc[i].THistory[Acc[i].history].Tdate.day=d;
        Acc[i].THistory[Acc[i].history].Tdate.month=m;
        Acc[i].THistory[Acc[i].history].Tdate.year=y;
        Acc[i].history++;
        return;
    }
    printf("The account was not found");
}
void ShowFeedback(){
     system("cls");
     int accn,i;
     float feedback;
    printf("Enter ID number: ");
    scanf("%d",&accn);
    for(i=0;i<idx;i++)
    if(Acc[i].AccNo==accn){
    printf("Teacher name : %s\n",Acc[i].AccName);
    printf("The total feedback is %d\n",Acc[i].feedback);
    feedback=(float)Acc[i].feedback/Acc[i].history;
    printf("The average feedback is %f\n",feedback);
    return;
    }
    printf("The ID was not found");
}



int menu(){
system("cls");
int option;
printf("Choose");
puts("0 for opening account");
puts("1 for giving feedback");
puts("4 for showing feedback");
puts("6 for exit");
scanf("%d",&option);
if(option!=6&&option!=4)
fprintf(fp,"%d\n",option);
return option;

}

int main() {

    /*int accn,mon,i,d,m,y,accn1,accn2;
fp=fopen("Account.txt","r");
int type;
while(fscanf(fp,"%d",&type)!=EOF)
{
    switch(type)
    {
    case 0:fscanf(fp,"%d%s%d%d%d",&Acc[idx].AccNo,Acc[idx].AccName,&Acc[idx].AccOpenDate.day,&Acc[idx].AccOpenDate.month,&Acc[idx].AccOpenDate.year);
    Acc[idx].feedback=0;Acc[idx].history=0;idx++;break;
    case 1:
        fscanf(fp,"%d%d%d%d%d",&accn,&mon,&d,&m,&y);
        for(i=0;i<idx;i++)
        if(Acc[i].AccNo==accn){
        Acc[i].feedback+=mon;
        Acc[i].THistory[Acc[i].history].Ttype=1;
        Acc[i].THistory[Acc[i].history].amount=mon;
        Acc[i].THistory[Acc[i].history].Tdate.day=d;
        Acc[i].THistory[Acc[i].history].Tdate.month=m;
        Acc[i].THistory[Acc[i].history].Tdate.year=y;
        Acc[i].history++;
        break;
        }
        break;
}
}
fp=fopen("Account.txt","a");
int option;

do{
    option=menu();
    switch(option){
    case 0:OpenAcc();break;
    case 1:GiveFeedback();break;
    case 4:ShowFeedback();break;
    }

}while(option!=6);
fclose(fp);


*/


    iInitialize(800, 800, "Student Feedback Management");
return 0;
}


