#include"public.h"
#include"login.h"

void draw_login(){
	cleardevice();
	setbkcolor(WHITE);
	setcolor(DARKGRAY);
	setlinestyle(0,0,3);
	line(155,200,490,200);
	 line(155,300,490,300);
	 setfillstyle(1,CYAN);
	 bar(210,335,435,405);
	 settextstyle(0,0,3);
	 outtextxy(195,175,"Username");
	 outtextxy(195,280,"Password");
	 setfillstyle(1,DARKGRAY);
	 pieslice(125,170,0,360,10);
	 bar(110,185,140,215);
	 bar(110,270,140,300);
	 ellipse(125,270,0,180,10,20);
	 setcolor(WHITE);
	 outtextxy(300,365,"Go");
	 puthz(192,15,"–£‘∞Õ‚¬ÙøÏµ›œµÕ≥",32,32,DARKGRAY);
	 puthz(288,430,"◊¢≤·",32,32,YELLOW);
	
}

void login(int *page,int *num)
{
	char a[10];
	char b[10];
	int tag=0;
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	draw_login();
	
	 while(1)
	 {
	 	newmouse(&MouseX,&MouseY,&press);
	 	//“∆÷¡’À∫≈ 
	 	if(MouseX>155&&MouseX<490&&MouseY>175&&MouseY<200)
		 {
		 	if(mouse_press(155,175,490,200)==2)
			 {
		 	  MouseS=2; 
			 
			
			 }
	
		
		 	else if(mouse_press(155,175,490,200)==1){
			 
		 		light_login(1);
		 		
		 		a[0]='\0';
		 		Input_Vis(a,155,175,10,WHITE);
		 	 }
		 
			
		  }
		  //“∆÷¡√‹¬Î 
		  else if(MouseX>155&&MouseX<490&&MouseY>275&&MouseY<300){
		  	if(mouse_press(155,275,490,300)==2){
			  	MouseS=2;
			  	
			  }
			  else if(mouse_press(155,275,490,300)==1){
			  	 light_login(2);
				   
				   	b[0]='\0';
				   	Input_Invis(b,155,275,10,WHITE);
			  }
		  }
		  //“∆÷¡µ«¬º
		  else if(MouseX>210&&MouseX<435&&MouseY>335&&MouseY<405){
		  	if(mouse_press(210,335,435,405)==2){
			  	MouseS=1;
			  }
			  else if(mouse_press(210,335,435,405)==1){
			  	
				  if(judge_login(a,b,&num)){
				  	*page=2;
				  }
				  else{
				  	delay(1000);
				  	setfillstyle(1,WHITE);
					bar(550,215,640,480);   
				  }
			  	
			  }
		  	
		  }
		  //“∆÷¡◊¢≤· 
		   else if(MouseX>288&&MouseX<352&&MouseY>430&&MouseY<462){
		   	if(mouse_press(288,430,352,462)==2){
			   	MouseS=1;
			   }
			   else if(mouse_press(288,430,352,462)==1){
			   	MouseS=0;
			   	*page=1; 
			   	break; 
			   }
			   
		   }
		    
		  else
		  MouseS=0;
	
		 
	}
	
	
}
void light_login(int tag){
	clrmous(MouseX,MouseY);
	delay(10);
	if(tag==1){
		setcolor(WHITE);
		setfillstyle(1,WHITE);
		bar(155,175,490,200);     
	} 
	if(tag==2){
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			bar(155,275,490,300);     
		} 
} 

int judge_login(char *a,char *p,int *n){
	int i;
	int l; 
	char x[1000]="ƒ„∫√"; 
	USER *temp=NULL;
	FILE *fp;	
	puthz(15,15,x,16,16,RED); 
	if((fp=fopen(".\\text\\USER.dat","rb+"))==NULL)
	{
		printf("\nError on open file UESR.dat!");
		delay(3000);
		exit(1);
	}
		fseek(fp,0,SEEK_END);
		l=ftell(fp)/sizeof(USER);
		for(i=0;i<l;i++)
		{
			if((temp=(USER*)malloc(sizeof(USER)))==NULL)
			{
				printf("\nMemory not enough!");
				delay(3000);
				exit(1);
			}
			fseek(fp,i*sizeof(USER),SEEK_SET);
			fread(temp,sizeof(USER),1,fp);
			if(strcmp(a,temp->account)==0)
			{         
				if(strcmp(p,temp->password)!=0)
				{
					puthz(550,250,"√‹¬Î¥ÌŒÛ",16,16,RED);
					break;
				}
				else if(strcmp(p,temp->password)==0)
				{   *n=temp->num;
					puthz(550,250,"√‹¬Î’˝»∑",16,16,RED);
					if(temp!=NULL)
					{
						free(temp);
						temp=NULL;
					} 
					if(fclose(fp)!=0)
					{
						printf("\nError on close UESR.dat!");
						delay(3000);
						exit(1);
					}
					return 1;
					//break;
				}
			}
		}
		if(i==l)
		{
			puthz(550,215,"’À∫≈Œ¥◊¢≤·",16,16,RED);
		}
		
		if(temp!=NULL)
		{
			free(temp);
			temp=NULL;
		} 
		if(fclose(fp)!=0)
		{
			printf("\nError on close UESR.dat!");
			delay(3000);
			exit(1);
		}
		return 0;
	}
	
