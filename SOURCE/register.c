#include"public.h"
#include"register.h"
void register_(int *page) {
	char A[10];
	char B[10];
	A[0] = '\0';
	B[0] = '\0';
	clrmous(MouseX, MouseY);
	delay(100);
	save_bk_mou(MouseX, MouseY);
	draw_register();
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		//�����˺�
		if (MouseX > 155 && MouseX < 490 && MouseY > 175 && MouseY < 200) {
			if (mouse_press(155, 175, 490, 200) == 2) {
				MouseS = 2;

			}


			else if (mouse_press(155, 175, 490, 200) == 1) {

				light_login(1);
				A[0] = '\0';
				
				Input_Vis(A, 155, 175, 10, WHITE);
			}


		}
		//��������
		else if (MouseX > 155 && MouseX < 490 && MouseY > 275 && MouseY < 300) {
			if (mouse_press(155, 275, 490, 300) == 2) {
				MouseS = 2;

			} else if (mouse_press(155, 275, 490, 300) == 1) {
				light_login(2);
			B[0] = '\0';
			
				Input_Invis(B, 155, 275, 10, WHITE);
			}
		}
		//����ע��
		else if (MouseX > 210 && MouseX < 435 && MouseY > 335 && MouseY < 405) {
			if (mouse_press(210, 335, 435, 405) == 2) {
				MouseS = 1;
			} 
			else if (mouse_press(210, 335, 435, 405) == 1) {
		
			 if (strlen(A)&&strlen(B)){
			 		MouseS=0;
					data(A,B);
					*page=0;
					break;
				}
				else{
				puthz(550,215,"ע���쳣",16,16,RED);
				delay(1000);
				setfillstyle(1,WHITE);
				bar (550,215,640,250);
				} 
			}

		}
		//�����˳�
		else if (MouseX > 20 && MouseX < 140 && MouseY > 390 && MouseY < 460) {
			if (mouse_press(20,390,140,460) == 2) {
				MouseS = 1;
			} else if (mouse_press(20,390,140,460) == 1) {

				*page = 0;
				break;

			}
		} 
		else {
			MouseS = 0;
		}
	}

}



void draw_register() {
	cleardevice();
	setbkcolor(WHITE);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(155, 200, 490, 200);
	line(155, 300, 490, 300);
	setfillstyle(1, CYAN);
	bar(210, 335, 430, 405);
	setfillstyle(1, YELLOW);
	bar(20, 390, 140, 460);
	settextstyle(0, 0, 3);
	outtextxy(195, 175, "Username");
	outtextxy(195, 280, "Password");
	setfillstyle(1, DARKGRAY);
	pieslice(125, 170, 0, 360, 10);
	bar(110, 185, 140, 215);
	bar(110, 270, 140, 300);
	ellipse(125, 270, 0, 180, 10, 20);
	puthz(48, 409, "�˳�", 32, 32, WHITE);
	puthz(288, 354, "ע��", 32, 32, WHITE);
	puthz(192, 15, "У԰�������ϵͳ", 32, 32, DARKGRAY);

}
void data(char *A,char *B){
	FILE* fp;
	USER* u;
	if((fp=fopen(".\\text\\USER.dat", "rb+" )) == NULL) //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file UserData.dat!");
		delay(3000);
		exit(1);
	}
	if((u=(USER*)malloc(sizeof(USER)))==NULL)                      //����ռ�
	{
		printf("\nMemory not enough!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);  
	strcpy(u->account,A);
	strcpy(u->password,B);
	fwrite(u,sizeof(USER),1,fp);  
	if (u != NULL)                                                 //�ͷ�u
	{
		free(u);
		u = NULL;
	}  
	if (fclose(fp)!=0)                                             //�ر��ļ�
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
}







