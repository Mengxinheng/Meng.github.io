#include<ctype.h>
#include <graphics.h>//ͼ��ģʽ�ĳ�ʼ�� 
#include <stdio.h>
#include<math.h>
void main()
{
  void show();
  IMAGE img;//�����հ׻�ֽ
  initgraph(1000, 680); // ��ʼ����ͼ�������¾ֲ����봴��һ���ߴ�Ϊ1000x680 �Ļ�ͼ������
  HWND hwnd = GetHWnd(); // ��ȡ��ͼ���ھ��
  POINT point;// point ��POINT ����Ľṹ��
  setfillcolor(WHITE);//�����ɫ
  show();
  int x1,y1,a=0,p,color;
  char s[]="����";
  char seban[]="   ";
  char t[]="���";
  char c[]="���";
  char b[]="����";
  char r[]="�ָ�";
  outtextxy(255,20,t);//������λ��
  outtextxy(10,635,seban);//��ɫ��λ��
  outtextxy(315,20,s);//�������λ��
  outtextxy(375,20,c);// ������λ��
  outtextxy(435,20,b);//�������λ��
  outtextxy(495,20,r);//�ָ����λ��
  while(true)
  {
     GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
     ScreenToClient(hwnd, &point); // ����Ļ���ָ��λ��ת��Ϊ��Ե�ǰ��������
     if(GetAsyncKeyState(VK_LBUTTON))// ��һ�������жϺ�������ʱָ���������״̬��ȷ���û���ǰ�Ƿ����˼����ϵ�һ�����ĺ���������ļ�ָ������
	 { 
		 if(point.y<60)
		 {
            setcolor(getpixel(point.x,point.y));//������ɫ(��������ָ�����������ص�RGB��ɫֵ)
            color=getpixel(point.x,point.y);}
            if(point.y<60)
			{
               if(point.x>0&&point.x<=60)// ����
                  a=0;
               if(point.x>60&&point.x<=120)// ֱ��
                  a=1;
               if(point.x>120&&point.x<=180)// ����
                  a=2;
               if(point.x>180&&point.x<=240)// Բ
                  a=3;
               if(point.x>240&&point.x<=300)//���
                  a=4;
               if(point.x>360&&point.x<=420)// ˢ����Ļ�������������
			   {
                  getimage(&img,0,60,1000,620); //���������������Ͻ������½����������Ļ������ͼ�ε�ָ�����ڴ�����
                  cleardevice();//���ͼ����Ļ
                  show();
                  outtextxy(375,20,c);
                  outtextxy(315,20,s);
                  outtextxy(255,20,t);
                  outtextxy(10,635,seban);
                  outtextxy(435,20,b);
                  outtextxy(495,20,r);
			   }
               if(point.x>300&&point.x<=360)// ����
			   {
                  getimage(&img,0,60,1000,620);
                  saveimage("C:\\pictures.jpg");//����ͼƬ
                  HWND hwnd = GetHWnd();//��ȡ���ھ��
                  MessageBox(hwnd, _T("�ѱ��浽C:\\pictures.jpg!"),_T("����"), MB_OK) ; //��Ϣ�򣨶Ի��򸸴��ھ��������ʾ����Ϣ�ַ������Ի�������ַ�����ȷ����ť��
			      a=5;
			   }
               if(point.x>420&&point.x<=480)// ����
                 a=5;
               if(point.x>480&&point.x<=560)// �ָ����ļ�����
                 a=6;
			}
            while(1)
			{
               x1=point.x;
               y1=point.y;
               if(a==0) // ����
			   {
                  getimage(&img,0,60,1000,620);
                  GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
                  ScreenToClient(hwnd, &point); // �����ָ��λ��ת��Ϊ��������
                  line(x1,y1,point.x,point.y);
                  if(!GetAsyncKeyState(VK_LBUTTON))
                    break;
			   }
               if(a==1)// ֱ��
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
                      ScreenToClient(hwnd, &point); // �����ָ��λ��ת��Ϊ��������
                      line(x1,y1,point.x,point.y);
                      break;
				  }
			   }
               if(a==2)// ����
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                     getimage(&img,0,60,1000,620);
                     GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
                     ScreenToClient(hwnd, &point); // �����ָ��λ��ת��Ϊ��������
                     line(x1,y1,point.x,y1);
                     line(x1,y1,x1,point.y);
                     line(x1,point.y,point.x,point.y);
                     line(point.x,y1,point.x,point.y);
                     break;
				  }
			   }
               
               if(a==3)// Բ
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
                      ScreenToClient(hwnd, &point); // �����ָ��λ��ת��Ϊ��������
                      far circle(x1, y1,(int)sqrt((double)(point.x-x1)*(point.x-x1)+(point.y-y1)*(point.y-y1)));
                      break;
				  }
			   }
               if(a==4)//full
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // ��ȡ���ָ��λ�ã���Ļ���꣩
                      ScreenToClient(hwnd, &point); // �����ָ��λ��ת��Ϊ��������
                      setfillcolor(color);
                      setfillstyle(BS_SOLID); //�������ģʽ����ɫ
					  floodfill(point.x,point.y, getpixel(point.x,point.y),1);// ��ָ����ɫ���һ���ܱ�����
                      break;
				  }
			   }
               if(a==5)// ����
			   { 
				   putimage(0, 60, &img);
                   break;
			   }
               if(a==6)// �ļ��ָ�
			   {
				   loadimage(&img, "C:\\pictures.jpg");
                   putimage(0,0, &img);
                   break;
			   }
			}
         }
     }
 }
void show()
{
   far floodfill(1,1,BLUE);
   setbkmode(TRANSPARENT);//����ģʽ��͸��

   setcolor(BLACK);
   setfillcolor(BLACK);
   setlinestyle(0,2);
   line(0,60,1000,60);//����
   line(60,0,60,60);
   line(120,0,120,60);
   line(180,0,180,60);
   line(240,0,240,60);
   line(300,0,300,60);
   line(360,0,360,60);
   line(420,0,420,60);
   line(480,0,480,60);
   line(540,0,540,60);
   setlinestyle(0,3);//��ť
   fillcircle(30,30,4);
   line(75,30,105,30);//ֱ��
   rectangle(130,15,170,45);//����
   circle(210,30,18);//Բ
   setcolor(BLACK);
   setfillcolor(BLACK);
   setfillstyle(BS_SOLID);
   bar(560,5,580,25);//ʹ�öԽ������껭����
   setcolor(RED);
   setfillcolor(RED);
   setfillstyle(BS_SOLID);
   bar(560,35,580,55);//ʹ�öԽ������껭����
   setcolor(GREEN);
   setfillcolor(GREEN);
   setfillstyle(BS_SOLID);
   bar(590,5,610,25);//ʹ�öԽ������껭����
   setcolor(BLUE);
   setfillcolor(BLUE);
   setfillstyle(BS_SOLID);
   bar(590,35,610,55);//ʹ�öԽ������껭����
   setcolor(YELLOW);
   setfillcolor(YELLOW);
   setfillstyle(BS_SOLID);
   bar(620,5,640,25);//ʹ�öԽ������껭����
   setcolor(BROWN);
   setfillcolor(BROWN);
   setfillstyle(BS_SOLID);
   bar(620,35,640,55);//ʹ�öԽ������껭����
   setcolor(CYAN);
   setfillcolor(CYAN);
   setfillstyle(BS_SOLID);
   bar(650,5,670,25);//ʹ�öԽ������껭����
   setcolor(MAGENTA);
   setfillcolor(MAGENTA);
   setfillstyle(BS_SOLID);
   bar(650,35,670,55);//��ɫ��������
   setcolor(BLACK);
   setfillcolor(WHITE);
 
}