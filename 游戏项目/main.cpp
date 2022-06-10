#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include <stdlib.h>
#include<mmsystem.h>//播放音乐文件库
#include<time.h>//计时器需要的头文件
#pragma comment(lib,"Winmm.lib")
bool Timer(clock_t ms, int id);
int music_kg = 1;
IMAGE diban[2];
IMAGE BJ1;
IMAGE menu_image_bj;
IMAGE menu_image[2];
IMAGE start_image[2];
IMAGE help_image[2];
IMAGE out_image[2];
IMAGE YX_image[2];
IMAGE YXK_image[2];
IMAGE YXG_image[2];
IMAGE caid;
IMAGE caid2;
IMAGE gb_menu[2];
IMAGE back_menu[2];
IMAGE yes_menu[2];
IMAGE no_menu[2];
IMAGE BULL_image[2];
IMAGE zzbj1;
IMAGE zzbj2;
//左
IMAGE jump1_image[3];
IMAGE move1_image[7];
IMAGE jump2_image[3];
IMAGE move2_image[7];
IMAGE stand1_image[4];
IMAGE stand2_image[4];
//右
IMAGE jump1_image2[3];
IMAGE move1_image2[7];
IMAGE jump2_image2[3];
IMAGE move2_image2[7];
IMAGE stand1_image2[4];
IMAGE stand2_image2[4];
//攻击
IMAGE attack1_image[4];
IMAGE attack2_image[4];
IMAGE attack1_image2[4];
IMAGE attack2_image2[4];
//子弹
IMAGE bull[3];
IMAGE bull2[3];//左
IMAGE bull3[3];//右边
IMAGE bull4[3];
//敌人
IMAGE dr_death1;//1左2右
IMAGE dr_death2;
IMAGE dr2_death1;//1左2右
IMAGE dr2_death2;
//左stand
IMAGE dr_stand1[4];//普通
IMAGE dr_stand2[4];
IMAGE dr_2stand1[4];//受击
IMAGE dr_2stand2[4];
//右stand
IMAGE dr2_stand1[4];//普通
IMAGE dr2_stand2[4];
IMAGE dr2_2stand1[4];//受击
IMAGE dr2_2stand2[4];
//界面
IMAGE gg_image;
IMAGE ts1_image;
IMAGE win_image;
IMAGE yes2_image[2];
enum mymenu
{
	start,
	gg,
	ts1,
	win,
	opxx,
	achieve,
	ewnr,
	out,
	home
};
enum mymenu mystate = home;
enum my
{
	bull_num = 5,
	dr1_num = 8
};
struct sbwz
{
	int x=531;
	int y[5]={398,438,480,530,570};
	int n=0;
}ZZSB;
struct zj_init//小骑士
{
	int x;
	int y;
	int init_y;
	int x_self;//记录本身坐标位置(非图片)
	int y_self;
	//给予本身数值
	int high = 95;
	int wight = 55;
	IMAGE* ztai1;//掩码图
	IMAGE* ztai2;//正常图
	int donzuo;
	int live;
	int js;//击杀计数
	int mianxiang = 0;//0左，1右
	int move_pd = 0;//0原地，1右，-1左
	int move_cd = 0;//判定移动距离
	int jump_pd = 0;//0原地，1下，-1上
	int jump_pd2 = 0;//0为初始，非零为进行了2段跳跃
	int gj_pd = 0;//0,不为0时无法移动跳跃
	int gj_pd2 = 0;//0,大于0时空中无法射击
}xqs;
struct dr_init//敌人
{
	int x;
	int y;
	int init_y;
	IMAGE* ztai1;
	IMAGE* ztai2;
	int donzuo;
	int live;
	int mianxiang = 0;
	bool app = false;//true时绘制图片，否则不就行绘制
	int shouji=0;//判断是否受击,0正常,否则算受击
	int xz ;//位移修正值y
	//给予本身数值
	int x_self;
	int y_self;
	int high = 90;
	int wight = 80;
}dr_fly[dr1_num];
void init_image()//图片加载
{
	for (int i = 0; i < 2; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./res/diban%d.png", i);
		loadimage(diban + i, lujin1,250,250);
		sprintf(lujin1, "./res/menu%d.png", i);
		loadimage(menu_image + i, lujin1, 70, 70);
		sprintf(lujin1, "./res/playgame%d.png", i);
		loadimage(start_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./res/help%d.png", i);
		loadimage(help_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./res/exit%d.png", i);
		loadimage(out_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./test/xuanze%d.png", i);
		loadimage(gb_menu + i, lujin1, 222, 57);
		sprintf(lujin1, "./test/yinxiao%d.png", i);
		loadimage(YX_image + i, lujin1, 90, 40);
		sprintf(lujin1, "./test/kai%d.png", i);
		loadimage(YXK_image + i, lujin1, 50, 40);
		sprintf(lujin1, "./test/guan%d.png", i);
		loadimage(YXG_image + i, lujin1, 50, 40);
		sprintf(lujin1, "./test/huidaocaidan%d.png", i);
		loadimage(back_menu + i, lujin1, 180, 40);
		sprintf(lujin1, "./test/bull%d.png", i);
		loadimage(BULL_image + i, lujin1, 65, 20);
		sprintf(lujin1, "./test/shi%d.png", i);
		loadimage(yes_menu + i, lujin1, 45, 40);
		sprintf(lujin1, "./jm/yes%d.png", i);
		loadimage(yes2_image + i, lujin1, 225, 95);
		sprintf(lujin1, "./test/fou%d.png", i);
		loadimage(no_menu + i, lujin1, 45, 40);
	}
	loadimage(&menu_image_bj, "./res/menuunit3.png", 1280, 720);
	loadimage(&BJ1, "./res/BJ1.png", 1280, 720);
	loadimage(&caid, "./test/caidan1.png", 1280, 720);
	loadimage(&caid2, "./test/beijing.png", 1280, 720);
	loadimage(&zzbj1, "./test/zhandoubeijing.png", 1280, 720);
	loadimage(&zzbj2, "./test/114514.png", 300, 50);
	loadimage(&ts1_image, "./jm/ts1.png", 1280, 750);
	loadimage(&gg_image, "./jm/gg.png", 1280, 750);
	loadimage(&win_image, "./jm/win.png", 1280, 750);
	//小骑士动作图片
	for (int i = 0; i < 3; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./jump/jump_%d_0.png", i+1);
		loadimage(jump1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump/jump_%d_1.png", i+1);
		loadimage(jump2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump2/jump_%d_0.png", i + 1);
		loadimage(jump1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump2/jump_%d_1.png", i + 1);
		loadimage(jump2_image2 + i, lujin1, 90, 125);
	}
	for (int i = 0; i < 4; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./zl44/zl%d.png", i + 1);
		loadimage(stand2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl44/zl%d%d.png", i + 1,i+1);
		loadimage(stand1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl22/zl%d.png", i + 1);
		loadimage(stand2_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl22/zl%d%d.png", i + 1, i + 1);
		loadimage(stand1_image2 + i, lujin1, 90, 125);
		//攻击动画特殊处理
		sprintf(lujin1, "./attack/%d 0 1.png", i + 1);
		loadimage(attack1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 0 2.png", i + 1);
		loadimage(attack1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 1 1.png", i + 1);
		loadimage(attack2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 1 2.png", i + 1);
		loadimage(attack2_image2 + i, lujin1, 90, 125);
	}
	for (int i = 0; i < 7; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./move/move_%d_0.png", i + 1);
		loadimage(move1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./move/move_%d_1.png", i + 1);
		loadimage(move2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./move2/move_%d_0.png", i + 1);
		loadimage(move1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./move2/move_%d_1.png", i + 1);
		loadimage(move2_image2 + i, lujin1, 90, 125);
	}
	//子弹
	for (int i = 0; i < 3; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./bull/%d0.png", i + 1);
		loadimage(bull + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull/%d1.png", i + 1);
		loadimage(bull2 + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull2/%d0.png", i + 1);
		loadimage(bull3 + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull2/%d1.png", i + 1);
		loadimage(bull4 + i, lujin1, 175, 30);
	}
	//敌人（飞行1)
	char lujin1[50] = { 0 };
	sprintf(lujin1, "./dr_death/1 0 1.png");
	loadimage(&dr_death1, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 1 1.png");
	loadimage(&dr_death2, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 0 2.png");
	loadimage(&dr2_death1, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 1 2.png");
	loadimage(&dr2_death2, lujin1, 120, 120);
	for (int i = 0; i < 4; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./dr_stand/%d 0 1.png", i + 1);
		loadimage(dr_stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 1.png", i + 1);
		loadimage(dr_stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 1.png", i + 1);
		loadimage(dr_2stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 1 1.png", i + 1);
		loadimage(dr_2stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 2.png", i + 1);
		loadimage(dr2_stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 2.png", i + 1);
		loadimage(dr2_stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 2.png", i + 1);
		loadimage(dr2_2stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 2 1.png", i + 1);
		loadimage(dr2_2stand2 + i, lujin1, 120, 120);
	}
}
struct bull_sx
{
	int x;
	int y;
	bool live = false;
	int mianxiang = 0;//0左，1右
	int donzuo = 0;//子弹动作数字
	int init_x = 0;//发射位置
	int time = 0;//死亡时间
	int high = 30;
	int wight = 170;
}bull_xqs[bull_num];
void createbull()
{
	for (int i = 0; i < bull_num; i++)
	{
		if (!bull_xqs[i].live)
		{
			bull_xqs[i].mianxiang = xqs.mianxiang;
			if (bull_xqs[i].mianxiang == 0)
			{
				bull_xqs[i].x = xqs.x - 155;
				bull_xqs[i].y = xqs.y + 30;
			}
			else
			{
				bull_xqs[i].x = xqs.x + 60;
				bull_xqs[i].y = xqs.y + 30;
			}
			bull_xqs[i].init_x = bull_xqs[i].x;
			bull_xqs[i].live = true;
			bull_xqs[i].time = 0;
			break;
		}
	}
}
void bullmove()//子弹移动
{
	for (int i = 0; i < bull_num; i++)
	{
		if (bull_xqs[i].live&& bull_xqs[i].time==0)
		{
			//没死则移动
			if (bull_xqs[i].mianxiang == 0)
			{
				bull_xqs[i].x -= 30;
				if (bull_xqs[i].x < bull_xqs[i].init_x - 190 && bull_xqs[i].donzuo == 0)
				{
					bull_xqs[i].donzuo = 1;
				}
			}
			else
			{
				bull_xqs[i].x += 30;
				if (bull_xqs[i].x > bull_xqs[i].init_x + 190 && bull_xqs[i].donzuo == 0)
				{
					bull_xqs[i].donzuo = 1;
				}
			}
			if (bull_xqs[i].x < 0 - 175 || bull_xqs[i].x>getwidth() + 175)
			{
				bull_xqs[i].live = false;//出界死亡
			}
		}
	}
}
int fhesc;
void init_all()//大部分初始化
{
	//mystate = start;
	ZZSB.n = 0;
	fhesc = 0;
}
void init_dr_fly()//敌人1初始化
{
	for (int i = 0; i < dr1_num; i++)
	{
		dr_fly[i].x = -120;
		dr_fly[i].y = -120;
		dr_fly[i].ztai1 = dr_stand1;
		dr_fly[i].ztai2 = dr_stand2;
		dr_fly[i].donzuo = 0;
		dr_fly[i].live = 2;
		dr_fly[i].mianxiang = 0;
		dr_fly[i].x_self = dr_fly[i].x + 30;
		dr_fly[i].y_self = dr_fly[i].y + 30;
		dr_fly[i].app = false;
		dr_fly[i].shouji = 0;
		dr_fly[i].init_y = getheight() - 45 - 125;
		dr_fly[i].xz = 5;
	}
}
void init_role()//小骑士初始化
{
	fhesc = 0;
	mciSendString("play BGM_1 repeat", NULL, 0, NULL);     //循环播放音乐
	mciSendString("stop BGM1", NULL, 0, NULL);
	if (music_kg == 0)
	{
		mciSendString("stop BGM_1", NULL, 0, NULL);
	}
	//敌人初始化
	init_dr_fly();
	//小骑士的初始化
	xqs.init_y = getheight() - 45 - 125;
	xqs.y = xqs.init_y;
	xqs.x = getwidth()/2-45;
	xqs.x_self = xqs.x + 30;
	xqs.y_self = xqs.y + 30;
	xqs.donzuo = 0;
	xqs.live = 1;
	xqs.js = 0;
	xqs.ztai1 = stand1_image2;
	xqs.ztai2 = stand2_image2;
	xqs.mianxiang = 1;
	int mianxiang = 0;//0左，1右
	int move_pd = 0;//0原地，1右，-1左
	int move_cd = 0;//判定移动距离
	int jump_pd = 0;//0原地，1下，-1上
	int gj_pd = 0;//0,不为0时无法移动跳跃
	int gj_pd2 = 0;//0,大于0时空中无法射击
	int jump_pd2 = 0;//0为初始，非零为进行了2段跳跃
}
void dr_fly_cj()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == false)
		{
			srand((unsigned)time(NULL));
			int n_dr1 = rand() % 2;//[0,1]
			dr_fly[i].donzuo = 0;
			dr_fly[i].live = 2;
			dr_fly[i].mianxiang = n_dr1;
			dr_fly[i].shouji = 0;
			int dr_y_1 = (rand() % (getheight() - 160 - 260 + 1)) + 260;//[a,b]
			dr_fly[i].y = dr_y_1;//设置高度,从两边飞出
			if (dr_fly[i].mianxiang == 0)
			{
				dr_fly[i].x = -120;
				dr_fly[i].ztai1 = dr2_stand1;
				dr_fly[i].ztai2 = dr2_stand2;
			}
			else
			{
				dr_fly[i].x = getwidth() + 120;
				dr_fly[i].ztai1 = dr_stand1;
				dr_fly[i].ztai2 = dr_stand2;
			}
			dr_fly[i].x_self = dr_fly[i].x + 20;
			dr_fly[i].y_self = dr_fly[i].y + 20;
			dr_fly[i].app = true;
			break;
		}
	}
}
void dr_fly_donzuo()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == true)//判断存活
		{
			if (dr_fly[i].donzuo != -1)//判断死亡动作
			{
				if (Timer(120, 200 + i))
				{
					dr_fly[i].donzuo += 1;
					dr_fly[i].y += dr_fly[i].xz;//修正飞行y轴抖动
					if (dr_fly[i].xz > 0)
					{
						dr_fly[i].xz = -5;
					}
					else
					{
						dr_fly[i].xz = 5;
					}
				}
				if (dr_fly[i].donzuo >= 4)
				{
					dr_fly[i].donzuo = 0;
				}
				//坐标移动
				if (dr_fly[i].mianxiang == 0)
				{
					dr_fly[i].x += 5;
				}
				else
				{
					dr_fly[i].x -= 5;
				}
				//位置修正
				if (dr_fly[i].x < -120 || dr_fly[i].x > getwidth() + 120)
				{
					dr_fly[i].app = false;
				}
			}
			else
			{
				dr_fly[i].y += 35;
				//位置修正,落地死亡
				if (dr_fly[i].y_self> getheight()-dr_fly[i].high)
				{
					dr_fly[i].app = false;
					dr_fly[i].donzuo = 0;
					xqs.js += 1;//增加击杀数
					//结算
					if (xqs.js >= 10)
					{
						mystate = win;
					}
				}
			}
		}
	}
}
void dr1_fly_attack()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == false)
		{
			continue;//如果是死亡单位直接跳过
		}
		//判断小骑士
		if ((xqs.y_self >= dr_fly[i].y_self && xqs.y_self <= dr_fly[i].y_self + dr_fly[i].high)
			|| (dr_fly[i].y_self >= xqs.y_self && dr_fly[i].y_self <= xqs.y_self + xqs.high))
		{
			if ((xqs.x_self >= dr_fly[i].x_self && xqs.x_self <= dr_fly[i].x_self + dr_fly[i].wight)
				|| (dr_fly[i].x_self >= xqs.x_self && dr_fly[i].x_self <= xqs.x_self + xqs.wight))
			{
				if (xqs.live > 0)
				{
					xqs.live -= 1;
					//命中音效
					if (music_kg == 1)
					{
						mciSendString("close attack_self", NULL, 0, NULL);
						mciSendString("open ./sound/attack_self.mp3 alias attack_self", NULL, 0, NULL);
						mciSendString("play attack_self", NULL, 0, NULL);
					}
					//死亡判定
					mystate = gg;
				}
			}
		}
		//判断子弹
		for (int j = 0; j < bull_num; j++)
		{
			if (bull_xqs[j].live == false)
			{
				continue;//如果是死亡单位直接跳过
			}
			if ((bull_xqs[j].y >= dr_fly[i].y_self && bull_xqs[j].y <= dr_fly[i].y_self + dr_fly[i].high)
				||(dr_fly[i].y_self >= bull_xqs[j].y && dr_fly[i].y_self <= bull_xqs[j].y + bull_xqs[j].high))//判断子弹是否在其中y
			{
				if ((bull_xqs[j].x <= dr_fly[i].x_self + dr_fly[i].wight && bull_xqs[j].x >= dr_fly[i].x)//判断子弹是否在其中x
					|| (dr_fly[i].x_self <= bull_xqs[j].x + bull_xqs[j].wight && dr_fly[i].x_self >= bull_xqs[j].x))
				{
					if (bull_xqs[j].donzuo != 2)//不是正在做死亡动作的攻击
					{
						bull_xqs[j].donzuo = 2;
						dr_fly[i].live -= 1;
						bull_xqs[i].time = 10;
						if (dr_fly[i].live != 0)
						{
							dr_fly[i].shouji = 2;//受击判定做动作
							if (dr_fly[i].mianxiang == 0)
							{
								dr_fly[i].ztai1 = dr2_2stand1;
								dr_fly[i].ztai2 = dr2_2stand2;
							}
							else
							{
								dr_fly[i].ztai1 = dr_2stand1;
								dr_fly[i].ztai2 = dr_2stand2;
							}
							//受击后位移
							int pd_1 = bull_xqs[j].x - dr_fly[i].x_self;
							//子弹位置修正
							bull_xqs[j].x = dr_fly[i].x;
							if (pd_1 > 0)//从左边射到右边
							{
								dr_fly[i].x -= 50;
							}
							else
							{
								dr_fly[i].x += 50;
							}
						}
						else//死亡掉落动画
						{
							dr_fly[i].donzuo = -1;
							if (dr_fly[i].mianxiang == 0)
							{
								dr_fly[i].ztai1 = &dr_death1;
								dr_fly[i].ztai2 = &dr_death2;
							}
							else
							{
								dr_fly[i].ztai1 = &dr2_death1;
								dr_fly[i].ztai2 = &dr2_death2;
							}
						}
						//命中音效
						if (music_kg == 1)
						{
							mciSendString("close attack_em", NULL, 0, NULL);
							mciSendString("open ./sound/attack_em.mp3 alias attack_em", NULL, 0, NULL);
							mciSendString("play attack_em", NULL, 0, NULL);
						}
					}
				}
			}
		}
	}
}
void draw_image()//图片绘制
{
	//清屏（图形窗口）    system("cls")；清除控制台
	cleardevice();
	//分割线
	if (mystate==start)
	{
		putimage(0, 0, &BJ1);
		for (int i = 0; i < getwidth();)
		{
			putimage(i, getheight() - 250, diban + 1, NOTSRCERASE);
			putimage(i, getheight() - 250, diban + 0, SRCERASE);
			i += 250;
		}
	}
	/*if (mystate == home)
	{
		putimage(0, 0, &menu_image_bj);
		putimage(540, 280, start_image + 1, NOTSRCERASE);
		putimage(540, 280, start_image + 0, SRCERASE);
		putimage(540, 380, help_image + 1, NOTSRCERASE);
		putimage(540, 380, help_image + 0, SRCERASE);
		putimage(540, 480, out_image + 1, NOTSRCERASE);
		putimage(540, 480, out_image + 0, SRCERASE);
	}*/
	if (mystate == home)
	{
		putimage(0, 0, &caid);
		putimage(ZZSB.x, ZZSB.y[ZZSB.n], gb_menu + 1, NOTSRCERASE);
		putimage(ZZSB.x, ZZSB.y[ZZSB.n], gb_menu + 0, SRCERASE);
	}
	if (mystate == opxx)
	{
		putimage(0, 0, &caid2);
		putimage(520, 320, YX_image + 1, NOTSRCERASE);
		putimage(520, 320, YX_image + 0, SRCERASE);
		putimage(510, 460, back_menu + 1, NOTSRCERASE);
		putimage(510, 460, back_menu + 0, SRCERASE);
		if (music_kg == 1)
		{
			putimage(620, 320, YXK_image + 1, NOTSRCERASE);
			putimage(620, 320, YXK_image + 0, SRCERASE);
		}
		else
		{
			putimage(620, 320, YXG_image + 1, NOTSRCERASE);
			putimage(620, 320, YXG_image + 0, SRCERASE);
		}
	}
	if (mystate == ts1)
	{
		putimage(0, 0, &ts1_image);
		putimage(510, 600, yes2_image + 1, NOTSRCERASE);
		putimage(510, 600, yes2_image + 0, SRCERASE);
	}
	if (mystate == gg)
	{
		putimage(0, 0, &gg_image);
	}
	if (mystate == win)
	{
		putimage(0, 0, &win_image);
	}
	if (mystate == start)
	{
		putimage(0, 0, &zzbj1);
		//小骑士坐标修正
		if (xqs.x < 0)
		{
			xqs.x = 0;
		}
		if (xqs.x > getwidth() - 90)
		{
			xqs.x = getwidth() - 90;
		}
		if (xqs.y > xqs.init_y)
		{
			xqs.y = xqs.init_y;
			xqs.jump_pd = 0;
			xqs.gj_pd2 = 0;
			xqs.jump_pd2 = 0;
			if (xqs.mianxiang == 0)
			{
				xqs.ztai1 = stand1_image;
				xqs.ztai2 = stand2_image;
				xqs.move_pd = 0;
			}
			else
			{
				xqs.ztai1 = stand1_image2;
				xqs.ztai2 = stand2_image2;
				xqs.move_pd = 0;
			}
		}
		//小骑士跳跃，移动
		if (xqs.gj_pd != 0)
		{
			xqs.gj_pd -= 2;
			if (Timer(120, 56))
			{
				xqs.donzuo += 1;
				if (xqs.donzuo == 1)
				{
					//发射音效
					if (music_kg == 1)
					{
						mciSendString("close attack", NULL, 0, NULL);
						mciSendString("open ./sound/attack.mp3 alias attack", NULL, 0, NULL);
						mciSendString("play attack", NULL, 0, NULL);
					}
				}
				if (xqs.donzuo == 2)
				{
					createbull();
				}
				if (xqs.donzuo >= 4)
				{
					xqs.donzuo = 0;
					xqs.gj_pd = 0;
					if (xqs.mianxiang == 0)
					{
						if (xqs.jump_pd != 0)
						{
							xqs.ztai1 = jump1_image;
							xqs.ztai2 = jump2_image;
							xqs.jump_pd = 1;
							xqs.donzuo = 2;
						}
						else
						{
							xqs.ztai1 = stand1_image;
							xqs.ztai2 = stand2_image;
						}
						xqs.move_pd = 0;
					}
					else
					{
						if (xqs.jump_pd != 0)
						{
							xqs.ztai1 = jump1_image2;
							xqs.ztai2 = jump2_image2;
							xqs.jump_pd = 1;
							xqs.donzuo = 2;
						}
						else
						{
							xqs.ztai1 = stand1_image2;
							xqs.ztai2 = stand2_image2;
						}
						xqs.move_pd = 0;
					}
				}
			}
		}
		else
		{
			if (xqs.jump_pd == 0)
			{
				if (Timer(120, 56))
				{
					if (xqs.y == xqs.init_y)
					{
						xqs.donzuo += 1;
					}
					if (xqs.donzuo >= 4 && xqs.move_pd == 0)
					{
						xqs.donzuo = 0;
					}
				}
			}
			if (xqs.jump_pd != 0)
			{
				if (xqs.donzuo != 2)
				{
					xqs.y += 26 * xqs.jump_pd;
				}
				else
				{
					xqs.y += 20 * xqs.jump_pd;
				}
				if (xqs.donzuo == 0)
				{
					if (Timer(30, 11))
					{
						xqs.donzuo = 1;
					}
				}
				if (xqs.y < getheight() - 125 - 45 - 150-xqs.jump_pd2)
				{
					xqs.donzuo = 2;
					xqs.jump_pd = 1;
				}
				xqs.x += 21 * xqs.move_pd;
			}
			else if (xqs.move_cd > 0)
			{
				if (xqs.donzuo >= 7)
				{
					xqs.donzuo = 0;
				}
				xqs.x += 20 * xqs.move_pd;
				xqs.move_cd -= 15;
			}
			else if (xqs.move_cd <= 0 && xqs.jump_pd == 0 && xqs.move_pd != 0)
			{
				xqs.donzuo = 0;
				if (xqs.mianxiang == 0)
				{
					xqs.ztai1 = stand1_image;
					xqs.ztai2 = stand2_image;
					xqs.move_pd = 0;
				}
				else
				{
					xqs.ztai1 = stand1_image2;
					xqs.ztai2 = stand2_image2;
					xqs.move_pd = 0;
				}
				xqs.move_pd = 0;
				xqs.move_cd = 0;
			}
		}
		//小骑士的本身坐标修正
		xqs.x_self = xqs.x + 30;
		xqs.y_self = xqs.y + 30;
		//小骑士绘制
		if (xqs.live > 0)
		{
			putimage(xqs.x, xqs.y, xqs.ztai1 + xqs.donzuo, NOTSRCERASE);
			putimage(xqs.x, xqs.y, xqs.ztai2 + xqs.donzuo, SRCERASE);
		}
		//刷新敌人
		if (Timer(3000, 233))
		{
			dr_fly_cj();
		}
		//敌人绘制
		for (int i = 0; i < dr1_num; i++)
		{
			if (dr_fly[i].app == false)
			{
				continue;
			}
			if (dr_fly[i].shouji == 0)
			{
				if (dr_fly[i].donzuo != -1)
				{
					if (dr_fly[i].mianxiang == 0)
					{
						dr_fly[i].ztai1 = dr2_stand1;
						dr_fly[i].ztai2 = dr2_stand2;
					}
					else
					{
						dr_fly[i].ztai1 = dr_stand1;
						dr_fly[i].ztai2 = dr_stand2;
					}
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1 + dr_fly[i].donzuo, NOTSRCERASE);
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2 + dr_fly[i].donzuo, SRCERASE);
				}
				else
				{
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1+0, NOTSRCERASE);
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2+0, SRCERASE);
				}
			}
			else
			{
				putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1 + dr_fly[i].donzuo, NOTSRCERASE);
				putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2 + dr_fly[i].donzuo, SRCERASE);
				if (Timer(200, 100 + i)&& dr_fly[i].shouji != 0)//复位受击动作
				{
					dr_fly[i].shouji -= 1;
				}
			}
			dr_fly[i].x_self = dr_fly[i].x + 20;
			dr_fly[i].y_self = dr_fly[i].y + 20;
		}
		dr_fly_donzuo();
		dr1_fly_attack();
		//子弹绘制
		for (int i = 0; i < bull_num; i++)
		{
			if (bull_xqs[i].live)
			{
				int nx = bull_xqs[i].donzuo;
				if (bull_xqs[i].mianxiang == 0)
				{
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull + nx, NOTSRCERASE);
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull2 + nx, SRCINVERT);
				}
				else
				{
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull3 + nx, NOTSRCERASE);
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull4 + nx, SRCINVERT);
				}
				if (bull_xqs[i].time > 0&&nx==2)
				{
					if (Timer(100, 40+i))
					{
						bull_xqs[i].time = 0;
					}
				}
				else if ((bull_xqs[i].time == 0 && nx == 2))
				{
					bull_xqs[i].live = false;
					bull_xqs[i].donzuo = 0;
				}
			}
		}
		//返回绘制
		if (fhesc == 1)
		{
			putimage(510, 460, &zzbj2);
			putimage(510, 460, back_menu + 1, NOTSRCERASE);
			putimage(510, 460, back_menu + 0, SRCERASE);
			putimage(690, 460, yes_menu + 1, NOTSRCERASE);
			putimage(690, 460, yes_menu + 0, SRCERASE);
			putimage(735, 460, no_menu + 1, NOTSRCERASE);
			putimage(735, 460, no_menu + 0, SRCERASE);
		}
		//积分器
		settextcolor(RGB(255, 255, 255));
		settextstyle(50, 25, "楷体");
		char fs_1[10];
		sprintf(fs_1, "得分:%d", xqs.js);
		outtextxy(0, 0, fs_1);
	}
}
//鼠标是否在某个矩形区域
bool isInRect(ExMessage* msg, int x, int y, int w, int h)
{
	if (msg->x > x && msg->x <x + w && msg->y >y && msg->y < y + h)
	{
		return true;
	}
	return false;
}
void StartUpScence(ExMessage* msg)//用&取地址也可以
{
	//鼠标左键点击切换场景画面
	if (msg->message == WM_LBUTTONDOWN)//WM_LBUTTONDOWN左键摁下
	{
		if (mystate == home)//判断是否在主菜单
		{
			if (isInRect(msg, 600, 420, 100, 40))//开始游戏
			{
				mystate = ts1;
				init_role();
			}
			else if (isInRect(msg, 600, 460, 100, 40))//选项
			{
				mystate = opxx;
			}
			else if (isInRect(msg, 600, 500, 100, 40))//成就
			{
				//mystate = out;
			}
			else if (isInRect(msg, 600, 540, 100, 40))//额外内容
			{
				//mystate = out;
			}
			else if (isInRect(msg, 600, 580, 100, 40))//退出游戏
			{
				mystate = out;
			}
		}
		else if (mystate == opxx)
		{
			if (isInRect(msg, 520, 320, 150, 40))//开关音效
			{
				if (music_kg == 1)
				{
					music_kg = 0;
					mciSendString("stop BGM1", NULL, 0, NULL);
				}
				else
				{
					music_kg = 1;
					mciSendString("play BGM1 repeat", NULL, 0, NULL);
				}
			}
			if (isInRect(msg, 510, 460, 150, 40))//回到菜单
			{
				mystate = home;
			}
		}
	}
	//提示，gg，win
	if (msg->message == WM_LBUTTONDOWN)
	{
		if (mystate == ts1)
		{
			if (isInRect(msg, 510, 600, 225, 95))//开始游戏
			{
				mystate = start;
				init_role();
			}
		}
		if (mystate == gg || mystate == win)
		{
			mystate = home;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);     //循环播放音乐
			mciSendString("stop BGM_1", NULL, 0, NULL);
			if (music_kg == 0)
			{
				mciSendString("stop BGM1", NULL, 0, NULL);
			}
		}
	}
	//小骑士回到菜单
	if (msg->message == WM_LBUTTONDOWN && fhesc == 1)
	{
		if (isInRect(msg, 690, 460, 50, 40))//返回菜单
		{
			fhesc = 0;
			mystate = home;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);     //循环播放音乐
			mciSendString("stop BGM_1", NULL, 0, NULL);
			if (music_kg == 0)
			{
				mciSendString("stop BGM1", NULL, 0, NULL);
			}
		}
		else if (isInRect(msg, 735, 460, 50, 40))//取消
		{
			fhesc = 0;
		}
	}
}
void gb_sb(ExMessage* msg)
{
	if (isInRect(msg, 600, 420, 100, 40))
	{
		ZZSB.n = 0;
	}
	else if (isInRect(msg, 600, 460, 100, 40))
	{
		ZZSB.n = 1;
	}
	else if (isInRect(msg, 600, 500, 100, 40))
	{
		ZZSB.n = 2;
	}
	else if (isInRect(msg, 600, 540, 100, 40))
	{
		ZZSB.n = 3;
	}
	else if (isInRect(msg, 600, 580, 100, 40))
	{
		ZZSB.n = 4;
	}
}
void gb_key()
{
	//GetAsyncKeyState获取异步按键状态,不会阻塞----VK是虚拟键值virtual key
	static DWORD t1 = 0, t2 = 0;//让他不会一次性摁多次
	if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && t2 - t1 > 120)//上移
	{
		if (ZZSB.n > 0)
		{
			ZZSB.n -= 1;
		}
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && t2 - t1 > 120)//下移
	{
		if (ZZSB.n < 4)
		{
			ZZSB.n += 1;
		}
		t1 = t2;
	}
	//回车进入
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 0) && t2 - t1 > 120)
	{
		mystate = ts1;
		init_role();
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 1) && t2 - t1 > 120)
	{
		mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 2) && t2 - t1 > 120)
	{
		//mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 3) && t2 - t1 > 120)
	{
		//mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 4) && t2 - t1 > 120)
	{
		mystate = out;
		t1 = t2;
	}
	t2 = GetTickCount();
}
void key_xx()
{
	//GetAsyncKeyState获取异步按键状态,不会阻塞----VK是虚拟键值virtual key
	static DWORD t1 = 0, t2 = 0;//让他不会一次性摁多次
	if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('D')|| GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('A')) && t2 - t1 > 200)//切换
	{
		if (music_kg == 1)
		{
			music_kg = 0;
			mciSendString("stop BGM1", NULL, 0, NULL);
		}
		else
		{
			music_kg = 1;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);
		}
		t1 = t2;
	}
	t2 = GetTickCount();
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		mystate = home;
	}
}
void xqs_key()
{
	static DWORD t1 = 0, t2 = 0;//让他不会一次性摁多次
	static DWORD t3 = 0, t4 = 0;
	//ESC
	if (GetAsyncKeyState(VK_ESCAPE) && t2 - t1 > 300)
	{
		t1 = t2;
		if (fhesc == 0)
		{
			fhesc = 1;//等于1弹出返回选单
		}
		else
		{
			fhesc = 0;
		}
	}
	//移动跳跃
	if (xqs.gj_pd == 0&&xqs.live>0)
	{
		//左移动
		if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) && t2 - t1 > 30)
		{

			if (xqs.y == xqs.init_y)//z判断是否跳跃
			{
				xqs.ztai1 = move1_image;
				xqs.ztai2 = move2_image;
				xqs.mianxiang = 0;
			}
			else if (xqs.ztai1 != move1_image)//判断是否重置
			{
				xqs.donzuo = 0;
			}
			xqs.move_pd = -1;
			xqs.move_cd = 20;
			t1 = t2;
		}
		//JUMP跳
		if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('K')) && t4 - t3 > 100)
		{
			if (xqs.mianxiang == 0)//左上跳
			{
				if (xqs.ztai1 != jump1_image)
				{
					xqs.donzuo = 0;
				}
				xqs.ztai1 = jump1_image;
				xqs.ztai2 = jump2_image;
				t3 = t4;
				if (xqs.jump_pd == 0)
				{
					xqs.jump_pd = -1;
				}
			}
			else//右上跳
			{
				if (xqs.ztai1 != jump1_image2)
				{
					xqs.donzuo = 0;
				}
				xqs.ztai1 = jump1_image2;
				xqs.ztai2 = jump2_image2;
				t3 = t4;
				if (xqs.jump_pd == 0)
				{
					xqs.jump_pd = -1;
				}
			}
			if (xqs.jump_pd == 1&&xqs.jump_pd2==1)
			{
				xqs.jump_pd2 = 100;
				xqs.jump_pd = -1;
				xqs.donzuo = 0;
			}
			else if (xqs.jump_pd2 == 0)
			{
				xqs.jump_pd2 = 1;
			}
		}
		//右移动
		if ((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) && t2 - t1 > 30)
		{

			if (xqs.y == xqs.init_y)//z判断是否跳跃
			{
				xqs.ztai1 = move1_image2;
				xqs.ztai2 = move2_image2;
				xqs.mianxiang = 1;
			}
			else if (xqs.ztai1 != move1_image2)//判断是否重置
			{
				xqs.donzuo = 0;
			}
			xqs.move_pd = 1;
			xqs.move_cd = 20;
			t1 = t2;
		}
	}
	//发射子弹
	if (GetAsyncKeyState('J') && xqs.gj_pd==0&&xqs.gj_pd2==0 && xqs.live > 0)
	{
		xqs.gj_pd = 50;
		xqs.donzuo = 0;
		if (xqs.y != xqs.init_y)
		{
			xqs.gj_pd2 = 1;
		}
		if (xqs.mianxiang == 0)
		{
			xqs.ztai1 = attack1_image;
			xqs.ztai2 = attack2_image;
		}
		else
		{
			xqs.ztai1 = attack1_image2;
			xqs.ztai2 = attack2_image2;
		}
	}
	t2 = GetTickCount();
	t4 = GetTickCount();
}
//读取音乐
void music_dq()
{
	mciSendString("open ./sound/1.mp3 alias BGM1", NULL, 0, NULL);
	mciSendString("open ./sound/BGM1.mp3 alias BGM_1", NULL, 0, NULL);
	mciSendString("open ./sound/attack.mp3 alias attack", NULL, 0, NULL);
	mciSendString("open ./sound/attack_em.mp3 alias attack_em", NULL, 0, NULL);
	mciSendString("open ./sound/attack_self.mp3 alias attack_self", NULL, 0, NULL);
}
//定时器
bool Timer(clock_t ms, int id)
{
	static clock_t start[10] = { 0 };
	clock_t end = clock();
	if (end - start[id] >= ms)
	{
		start[id] = end;
		return true;
	}
	return false;
}
int main()
{
	music_dq();
	//open指令打开需要播放的音乐，alias后面制定了前面文件路径的别名，以后想要操作这个文件直接使用这个别名就可以了.
	//如果音乐文件和我们的debug文件夹在同一目录下，就可以像我这样不用写路径，直接音乐名。
	//如果音乐文件不是上面的情况就得写清楚路径。
	//例: D盘下的demo目录有一个叫1.MP3的文件
	//mciSendString("open D:\\demo\\1.mp3 alias bkmusic", NULL, 0, NULL);
	//mciSendString("stop bkmusic", NULL, 0, NULL);		//停止播放音乐
	//mciSendString("close bkmusic", NULL, 0, NULL);		//关闭音乐
	//mciSendString("play BGM1 repeat", NULL, 0, NULL);     //循环播放音乐
	//创建窗口
	initgraph(1280, 720);
	//初始化
	init_all();
	init_image();
	//输出图像
	//draw_image();
	//双缓冲绘图
	mciSendString("play BGM1 repeat", NULL, 0, NULL);     //循环播放音乐
	BeginBatchDraw();
	while (1)
	{
		ExMessage msg;
		//不断获取鼠标消息，如果有消息就返回true，否则返回false
		while (peekmessage(&msg, EM_MOUSE))
		{
			StartUpScence(&msg);
		}
		FlushBatchDraw();//刷新
		if (mystate == out)//检测到退出，跳出循环
		{
			break;
		}
		if (mystate == home)//光标随鼠标移动以及键盘控制
		{
			gb_sb(&msg);
			gb_key();
		}
		if (mystate == start)//小骑士
		{
			xqs_key();
			if (Timer(30,33))
			{
				bullmove();
			}
		}
		if (mystate == opxx)
		{
			key_xx();
		}
		if (Timer(50, 1))
		{
			draw_image();
		}
	}
	EndBatchDraw();
	return 0;
}