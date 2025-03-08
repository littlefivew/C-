#include"public.h"
/************************************************************************
FUNCTION:Input_Vis
DESCRIPTION:ʵ�ֿ��ӻ�����
INPUT:�������ݣ���������Ͻ�����x,y���������ƣ��������ɫ
RETURN:��
************************************************************************/
int Input_Vis(char* ip,int x,int y,int lim,int color) //�������ݣ���������Ͻ�����x,y���������ƣ��������ɫ
{                                                      //ע�⣺�����뺯��Ҫ���������Ϊ25
	int i=0;
	int j=0;                                           //��¼������
	char c;                                            //��ȡ�������������
	clrmous(MouseX, MouseY);
	setcolor(LIGHTGRAY);                                   //������ʾ����Ϊ��ɫ
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);             //��������
	setfillstyle(SOLID_FILL,color);                    //���������ɫ���������ɫһ��
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	line(x+10,y+6,x+10,y+20);                          //��������ʾ��꣨�ڸ�����������10�����ص㣬��һ����14�����ص������
	while(bioskey(1))
	{
		i=bioskey(0);
	}
	while(1)
	{
	    c=bioskey(0);                                  //��ȡ������������
		if(j<lim)
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)       //�������ǻ��С��س����ո���˳�
			{
				if(c!='\b')                            //���������˸�
				{   if(c>='0'&&c<='9')
				  { *(ip+j)=c;                         //�������c�������������ַ���ip
					*(ip+j+1)='\0';                    //�����ַ���ip
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //�����꣨ע����ԭ��������ϼ����Ѿ���������ݣ�
					outtextxy(x+8+j*18,y-1,ip+j);      //�����������ʾ������ַ�������ʵ����Ҳ�j*18�����ַ���
					j++;                               //��������һ
					line(x+10+j*18,y+6,x+10+j*18,y+20);//����������ַ����ػ����
				  }
				  else
				  {
					return  1;
				  }
				}
				else if (c=='\b'&&j>0)                 //��������˸�
				{
					bar(x-10+j*18,y+3,x+7+j*18,y+24);  //�����һ�����ַ�
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //������
					j--;                               //��������һ
					line(x+10+j*18,y+6,x+10+j*18,y+20);//����һ������ַ����ػ����
					*(ip+j)='\0';                      //����ַ���ip�������һ�ַ�
					*(ip+j+1)='\0';                    //�����ַ���ip
				}
			}
			else                                       //������뻻�С��س����ո���˳�
			{
				setfillstyle(SOLID_FILL, color);       //������ǰ�������
				bar(x+8+j*18,y+3,x+12+j*18,y+24);      //������
				break;
			}
		}
		else if(j>=lim)                               //����ﵽ��������
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //���๦�ܲ���
			{                                         //��������С��س����ո��˳����˸������ַ����ٴ洢����ʾ
				if(c=='\b'&&j>0)
				{
					bar(x+8+j*18,y+3,x+12+j*18,y+24);
					bar(x-10+j*18,y+3,x+7+j*18,y+24);
					j--;
					line(x+10+j*18,y+6,x+10+j*18,y+20);
					*(ip+j)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x+8+j*18,y+3,x+12+j*18,y+24); 
				break;
			}
		}
	}
	return 2;
}

/************************************************************************
FUNCTION:Input_Invis
DESCRIPTION:ʵ�ֲ����ӻ�����
INPUT:�������ݣ���������Ͻ�����x,y���������ƣ��������ɫ
RETURN:��
************************************************************************/
int Input_Invis(char* ip,int x,int y,int lim,int color)//������Input_Vis������ͬ��������ʾ���ַ��������Ӵ���
{
	int i=0;                                       
	int j=0;                                           //��¼������ 
	char c;                                            //��ȡ�������������
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL,color);                    //���������ʽ
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);             //��������
	setcolor(LIGHTGRAY);                                   //���������ʽ
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	line(x+10,y+6, x+10,y+20);                         //��������ʾ���
	while(bioskey(1))
	{
		i=bioskey(0);
	}
	while(1)
	{
	    c=bioskey(0);                                  //��ȡ������������
		if(j<lim)
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //�������ǻ��С��س����ո���˳�
			{
				
			  
				if(c!='\b')                           //���������˸�
				{   if(c>='0'&&c<='9')
				  { *(ip+j) =c;                        //�������c�������������ַ���ip
					*(ip+j+1) = '\0';                  //�����ַ���ip
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //������
					outtextxy(x+8+j*18,y+4,"*");       //�����������ʾ�ַ���*��
					j++;                               //��������һ
					line(x+10+j*18,y+6,x+10+j*18,y+20);//�ػ����
				  }
					  else
			         {
				       return 1;
			         }
				}
				else if (c=='\b'&&j>0)                 //��������˸�
				{
					bar(x-10+j*18,y+3,x+7+j*18,y+24);  //�����һ�����ַ�
					bar(x+8+j*18,y+3,x+12+j*18,y+24);  //������
					j--;                               //��������һ
					line(x+10+j*18,y+6,x+10+j*18,y+20);//�ػ�
					*(ip+j)='\0';                      //����ַ���ip�������һ�ַ�
					*(ip+j+1)='\0';                    //�����ַ���ip
				}
			}
			else                                       //������뻻�С��س����ո���˳�
			{
				setfillstyle(SOLID_FILL, color);       //������ǰ�������
				bar(x+8+j*18,y+3,x+12+j*18,y+24);      //������
				break;
			}
		}
		else if(j>=lim)                               //����ﵽ��������
		{
			if(c!='\n'&&c!='\r'&&c!=' '&&c!=033)      //���๦�ܲ���
			{                                         //��������С��س����ո��˳����˸������ַ����ٴ洢����ʾ
				if (c=='\b'&&j>0)
				{
					bar(x+8+j*18,y+3,x+12+j*18,y+24);
					bar(x-10+j*18,y+3,x+7+j*18,y+24);
					j--;
					line(x+10+j*18,y+6,x+10+j*18,y+20);
					*(ip+j)='\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x+8+j*18,y+3,x+12+j*18,y+24); 
				break;
			}
		}
	}
	return 2;
}

