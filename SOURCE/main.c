#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include "mouse.h"
#include"public.h"

void main(){
 int page=0;
 int num;
 int driver =VGA;
 int mode =VGAHI;

initgraph(&driver, &mode, "C:\\BORLANDC\\BGI");//��d:\\bc31����bc31�İ�װ·��
 cleardevice();

 mouseinit();
 while(1)
 {
 	switch (page) {
 		case 0:
 			login(&page,&num);
 			break;
	 	case 1:
	 		register_(&page);
	 		break;
	 	case 2:
	 		//TODO
	 		break;
	 
 	
 } 
 
 }

getch(); //�����������
closegraph();
 
}
 
