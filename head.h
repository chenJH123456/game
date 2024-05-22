#pragma once
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<easyx.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

IMAGE BK[5];// 初始背景图
IMAGE SE[4];// 选择背景图
IMAGE bk;//画板
IMAGE CAT[9];//猫
IMAGE P[8];//障碍物
IMAGE N[10];// 数字
IMAGE LAND;// 地面资源
IMAGE PLAY[2];// 开始键按钮
IMAGE B[4];//开场背景
IMAGE E[6];//结算背景
// 文字
IMAGE READY;//预备
IMAGE TITLE;//标题
IMAGE KEY[2];//选猫按钮
IMAGE ENTRY[3];// 词条表
IMAGE TIP;//提示
IMAGE OVER;// 结束备份图

int background;//rand背景码
int Ccolor;//rand猫颜色码
long startTime = 0;// 游戏初始时间
int score;// 当前得分
int pattern;//简单困难模式
int character;//角色

double g = 6;// 重力加速度(普通猫)
double vx = 8;// 墙移动速度
double vy = 8;// 猫的下落速度(普通猫)
// 猫的当前位置
double y = 960;
const double x = 39.5;

double X[4];// 墙横向坐标
int Y[4];// 墙纵向坐标
int c[4] = { 0,1,2 };//屏幕上4条障碍颜色

// 地面位置
const double landY = 500;
double landX = 0;
const int diff = 333;// 飞行间隔

void load()// 图片
{
	loadimage(&bk, _T("res\\bg_0.png"), 1000, 600);//画板

	loadimage(&B[0], _T("res\\B_1.png"));//开场背景
	loadimage(&B[1], _T("res\\B_2.png"));
	loadimage(&B[2], _T("res\\B_3.png"));
	loadimage(&B[3], _T("res\\B_4.png"));

	loadimage(&BK[0], _T("res\\bg_0.png"));//游戏背景
	loadimage(&BK[1], _T("res\\bg_1.png"));
	loadimage(&BK[2], _T("res\\bg_2.png"));
	loadimage(&BK[3], _T("res\\bg_3.png"));
	loadimage(&BK[4], _T("res\\bg_4.png"));//高难度彩蛋

	loadimage(&SE[0], _T("res\\se1.png"));//选择背景
	loadimage(&SE[1], _T("res\\se2.png"));
	loadimage(&SE[2], _T("res\\se3.png"));
	loadimage(&SE[3], _T("res\\se4.png"));

	loadimage(&ENTRY[0], _T("res\\entry1.png"),150,212);//猫词条表
	loadimage(&ENTRY[1], _T("res\\entry2.png"),150,212);
	loadimage(&ENTRY[2], _T("res\\entry3.png"), 150, 212);

	loadimage(&OVER, _T("res\\bg_0.png"));

	loadimage(&E[0], _T("res\\E_1.png"));//结算背景
	loadimage(&E[1], _T("res\\E_2.png"));
	loadimage(&E[2], _T("res\\E_3.png"));
	loadimage(&E[3], _T("res\\E_4.png"));
	loadimage(&E[4], _T("res\\E_5.png"));
	loadimage(&E[5], _T("res\\E_6.png"));

	loadimage(&CAT[0], _T("res\\cat_1.png"), 48, 48);//蓝
	loadimage(&CAT[1], _T("res\\cat_2.png"), 48, 48);//棕
	loadimage(&CAT[2], _T("res\\cat_3.png"), 48, 48);//绿
	loadimage(&CAT[3], _T("res\\cat_4.png"), 48, 48);//黄

	loadimage(&CAT[4], _T("res\\cat1.png"), 48, 48);//蓝
	loadimage(&CAT[5], _T("res\\cat2.png"), 48, 48);//棕
	loadimage(&CAT[6], _T("res\\cat3.png"), 48, 48);//绿
	loadimage(&CAT[7], _T("res\\cat4.png"), 48, 48);//黄
	loadimage(&CAT[8], _T("res\\cat999.png"), 48, 48);//神秘

	loadimage(&P[0], _T("res\\p1.png"), 16, 600);//蓝
	loadimage(&P[1], _T("res\\p2.png"), 16, 600);//棕
	loadimage(&P[2], _T("res\\p3.png"), 16, 600);//绿
	loadimage(&P[3], _T("res\\p4.png"), 16, 600);//黄
	loadimage(&P[4], _T("res\\p5.png"), 16, 600);//蓝
	loadimage(&P[5], _T("res\\p6.png"), 16, 600);//棕
	loadimage(&P[6], _T("res\\p7.png"), 16, 600);//绿
	loadimage(&P[7], _T("res\\p8.png"), 16, 600);//黄

	loadimage(&N[0], _T("res\\n0.png"));//计数
	loadimage(&N[1], _T("res\\n1.png"));
	loadimage(&N[2], _T("res\\n2.png"));
	loadimage(&N[3], _T("res\\n3.png"));
	loadimage(&N[4], _T("res\\n4.png"));
	loadimage(&N[5], _T("res\\n5.png"));
	loadimage(&N[6], _T("res\\n6.png"));
	loadimage(&N[7], _T("res\\n7.png"));
	loadimage(&N[8], _T("res\\n8.png"));
	loadimage(&N[9], _T("res\\n9.png"));

	loadimage(&LAND, _T("res\\land.png"));//陆地
	loadimage(&PLAY[0], _T("res\\play_key1.png"));//简单模式
	loadimage(&PLAY[1], _T("res\\play_key2.png"));//困难模式
	loadimage(&READY, _T("res\\ready.png"), 332, 89);//ready
	loadimage(&TITLE, _T("res\\title.png"));//标题
	loadimage(&TIP, _T("res\\tip.png"), 334, 260);//提示
	loadimage(&KEY[0], _T("res\\sele_key1.png"), 150, 75);//选猫按钮
	loadimage(&KEY[1], _T("res\\sele_key2.png"), 150, 75);
}

bool GetControl()
{
	bool res = false;
	if (_kbhit())
	{
		char ch = _getch();
		if (ch == ' ')res = true;
	}
	MOUSEMSG msg;
	while (MouseHit())
	{
		msg = GetMouseMsg();
		if (msg.mkLButton)res = true;
	}
	return res;
}

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)// 根据透明度绘图
{
	if (dstimg == NULL)return;
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = dstimg->getwidth();
	int dst_height = dstimg->getheight();

	//// 实现透明贴图  可优化
	for (int iy = 0; iy < src_height; iy++)
	{
		for (int ix = 0; ix < src_width; ix++)
		{
			int srcX = ix + iy * src_width;
			int sa = ((src[srcX] & 0xff000000) >> 24);
			int sr = ((src[srcX] & 0xff0000) >> 16);
			int sg = ((src[srcX] & 0xff00) >> 8);
			int sb = src[srcX] & 0xff;
			if (x + ix >= 0 && x + ix < dst_width
				&& y + iy >= 0 && y + iy < dst_height)
			{
				int dstX = (x + ix) + (y + iy) * dst_width;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				dst[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16) | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8) | (sb * sa / 255 + db * (255 - sa) / 255);//光谱颜色
			}
		}
	}
}
