#include<ctype.h>
#include <graphics.h>//图形模式的初始化 
#include <stdio.h>
#include<math.h>
void main()
{
  void show();
  IMAGE img;//创建空白画纸
  initgraph(1000, 680); // 初始化绘图窗口以下局部代码创建一个尺寸为1000x680 的绘图环境：
  HWND hwnd = GetHWnd(); // 获取绘图窗口句柄
  POINT point;// point 是POINT 定义的结构体
  setfillcolor(WHITE);//填充颜色
  show();
  int x1,y1,a=0,p,color;
  char s[]="保存";
  char seban[]="   ";
  char t[]="填充";
  char c[]="清空";
  char b[]="后退";
  char r[]="恢复";
  outtextxy(255,20,t);//填充面板位置
  outtextxy(10,635,seban);//调色板位置
  outtextxy(315,20,s);//保存面板位置
  outtextxy(375,20,c);// 清空面板位置
  outtextxy(435,20,b);//后退面板位置
  outtextxy(495,20,r);//恢复面板位置
  while(true)
  {
     GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
     ScreenToClient(hwnd, &point); // 将屏幕鼠标指针位置转换为相对当前窗口坐标
     if(GetAsyncKeyState(VK_LBUTTON))// 是一个用来判断函数调用时指定虚拟键的状态，确定用户当前是否按下了键盘上的一个键的函数。这里的键指鼠标左键
	 { 
		 if(point.y<60)
		 {
            setcolor(getpixel(point.x,point.y));//设置颜色(检索到的指定坐标点的像素的RGB颜色值)
            color=getpixel(point.x,point.y);}
            if(point.y<60)
			{
               if(point.x>0&&point.x<=60)// 曲线
                  a=0;
               if(point.x>60&&point.x<=120)// 直线
                  a=1;
               if(point.x>120&&point.x<=180)// 矩形
                  a=2;
               if(point.x>180&&point.x<=240)// 圆
                  a=3;
               if(point.x>240&&point.x<=300)//填充
                  a=4;
               if(point.x>360&&point.x<=420)// 刷新屏幕，重新输出所有
			   {
                  getimage(&img,0,60,1000,620); //可以用来保存左上角与右下角所定义的屏幕上像素图形到指定的内存区域
                  cleardevice();//清除图形屏幕
                  show();
                  outtextxy(375,20,c);
                  outtextxy(315,20,s);
                  outtextxy(255,20,t);
                  outtextxy(10,635,seban);
                  outtextxy(435,20,b);
                  outtextxy(495,20,r);
			   }
               if(point.x>300&&point.x<=360)// 保存
			   {
                  getimage(&img,0,60,1000,620);
                  saveimage("C:\\pictures.jpg");//保存图片
                  HWND hwnd = GetHWnd();//获取窗口句柄
                  MessageBox(hwnd, _T("已保存到C:\\pictures.jpg!"),_T("保存"), MB_OK) ; //消息框（对话框父窗口句柄，欲显示的信息字符串，对话框标题字符串，确定按钮）
			      a=5;
			   }
               if(point.x>420&&point.x<=480)// 后退
                 a=5;
               if(point.x>480&&point.x<=560)// 恢复到文件内容
                 a=6;
			}
            while(1)
			{
               x1=point.x;
               y1=point.y;
               if(a==0) // 曲线
			   {
                  getimage(&img,0,60,1000,620);
                  GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
                  ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
                  line(x1,y1,point.x,point.y);
                  if(!GetAsyncKeyState(VK_LBUTTON))
                    break;
			   }
               if(a==1)// 直线
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
                      ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
                      line(x1,y1,point.x,point.y);
                      break;
				  }
			   }
               if(a==2)// 矩形
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                     getimage(&img,0,60,1000,620);
                     GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
                     ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
                     line(x1,y1,point.x,y1);
                     line(x1,y1,x1,point.y);
                     line(x1,point.y,point.x,point.y);
                     line(point.x,y1,point.x,point.y);
                     break;
				  }
			   }
               
               if(a==3)// 圆
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
                      ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
                      far circle(x1, y1,(int)sqrt((double)(point.x-x1)*(point.x-x1)+(point.y-y1)*(point.y-y1)));
                      break;
				  }
			   }
               if(a==4)//full
			   {
                  if(!GetAsyncKeyState(VK_LBUTTON))
				  {
                      getimage(&img,0,60,1000,620);
                      GetCursorPos(&point); // 获取鼠标指针位置（屏幕坐标）
                      ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
                      setfillcolor(color);
                      setfillstyle(BS_SOLID); //设置填充模式和颜色
					  floodfill(point.x,point.y, getpixel(point.x,point.y),1);// 用指定颜色填充一个密闭区域
                      break;
				  }
			   }
               if(a==5)// 后退
			   { 
				   putimage(0, 60, &img);
                   break;
			   }
               if(a==6)// 文件恢复
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
   setbkmode(TRANSPARENT);//背景模式。透明

   setcolor(BLACK);
   setfillcolor(BLACK);
   setlinestyle(0,2);
   line(0,60,1000,60);//边线
   line(60,0,60,60);
   line(120,0,120,60);
   line(180,0,180,60);
   line(240,0,240,60);
   line(300,0,300,60);
   line(360,0,360,60);
   line(420,0,420,60);
   line(480,0,480,60);
   line(540,0,540,60);
   setlinestyle(0,3);//按钮
   fillcircle(30,30,4);
   line(75,30,105,30);//直线
   rectangle(130,15,170,45);//矩形
   circle(210,30,18);//圆
   setcolor(BLACK);
   setfillcolor(BLACK);
   setfillstyle(BS_SOLID);
   bar(560,5,580,25);//使用对角线坐标画矩形
   setcolor(RED);
   setfillcolor(RED);
   setfillstyle(BS_SOLID);
   bar(560,35,580,55);//使用对角线坐标画矩形
   setcolor(GREEN);
   setfillcolor(GREEN);
   setfillstyle(BS_SOLID);
   bar(590,5,610,25);//使用对角线坐标画矩形
   setcolor(BLUE);
   setfillcolor(BLUE);
   setfillstyle(BS_SOLID);
   bar(590,35,610,55);//使用对角线坐标画矩形
   setcolor(YELLOW);
   setfillcolor(YELLOW);
   setfillstyle(BS_SOLID);
   bar(620,5,640,25);//使用对角线坐标画矩形
   setcolor(BROWN);
   setfillcolor(BROWN);
   setfillstyle(BS_SOLID);
   bar(620,35,640,55);//使用对角线坐标画矩形
   setcolor(CYAN);
   setfillcolor(CYAN);
   setfillstyle(BS_SOLID);
   bar(650,5,670,25);//使用对角线坐标画矩形
   setcolor(MAGENTA);
   setfillcolor(MAGENTA);
   setfillstyle(BS_SOLID);
   bar(650,35,670,55);//调色板输出完成
   setcolor(BLACK);
   setfillcolor(WHITE);
 
}