#include "head.h"
void init();// 初始化游戏资源
void init1();//重开初始界面
void Select();//选择角色
void start();//点击前界面
void game();// 游戏进行
void end();//结算
void move(long time);// 移动函数
void Draw();// 绘制函数
void reset();// 重置画布
void put();// 绘制画布
void load();// 加载资源
void drawWall();// 绘制墙
void drawScore(int x, int y, int sc, int dif, int se);// 绘制分数
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);// 根据透明度绘图
bool Die();// 判断猫死亡
bool GetControl();//关闭窗口

int main()
{
	init();// 游戏开局页面
	while (true)
	{
		Select();//选择角色
		start();//点击前界面
		game();// 游戏进行
		end();//结算
		init1();//二次开始
	}
	return 0;
}

void init()//运行开始界面+初始化数值
{
	load();// 加载图形资源
	initgraph(1000, 600);// 界面大小

	srand((unsigned int)time(NULL));// 随机数种子
	Ccolor = 1;//猫色
	clock_t time = clock();// 游戏开始时间
	int i = 0;
	while (true)// 开场动画
	{
		drawAlpha(&bk, 0, 0, &B[i]);//动图
		i++;
		if (i == 4)i = 0;
		drawAlpha(&bk, 60, 50, &TITLE);//贴游戏名
		drawAlpha(&bk, 480, 240, &CAT[Ccolor]);//贴猫
		drawAlpha(&bk, 400, 300, &PLAY[0]);//贴简单
		drawAlpha(&bk, 400, 420, &PLAY[1]);//贴困难
		put();//贴图
		if (MouseHit()) {  // 判断是否有鼠标点击事件
			MOUSEMSG msg = GetMouseMsg();  // 获取鼠标事件
			if (msg.uMsg == WM_LBUTTONDOWN) {  // 判断是否是鼠标左键点击事件
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 400 && mouseX <= 600 && mouseY >= 300 && mouseY <= 400) {//简单模式
					setcolor(GREEN);  // 设置颜色为绿色
					setfillcolor(GREEN);  // 设置填充颜色为绿色
					settextstyle(40, 0, _T("黑体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(30, 400, "您已选择简单模式！");
					pattern = 1;
					Sleep(1000);
					break;  
				}
				else if (mouseX >= 400 && mouseX <= 600 && mouseY >= 420 && mouseY <= 520) {//困难模式
					setcolor(RED);  // 设置颜色为红色
					setfillcolor(RED);  // 设置填充颜色为红色
					settextstyle(40, 0, _T("宋体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(620, 400, "您已选择困难模式！");
					pattern = 2;
					Sleep(1000);
					break;
				}
			}
		}
//		Sleep(50);//动画速度，但会导致界面卡顿
	}
}

void init1()//二次开始界面
{
	Ccolor = 1;//猫色
	clock_t time = clock();// 游戏开始时间
	while (true)// 开场动画
	{
		drawAlpha(&bk, 0, 0, &BK[3]);//动图
		drawAlpha(&bk, 400, 300, &PLAY[0]);//贴简单
		drawAlpha(&bk, 400, 420, &PLAY[1]);//贴困难
		put();//贴图
		if (MouseHit()) {  // 判断是否有鼠标点击事件
			MOUSEMSG msg = GetMouseMsg();  // 获取鼠标事件
			if (msg.uMsg == WM_LBUTTONDOWN) {  // 判断是否是鼠标左键点击事件
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 400 && mouseX <= 600 && mouseY >= 300 && mouseY <= 400) {//简单模式
					setcolor(GREEN);  // 设置颜色为绿色
					setfillcolor(GREEN);  // 设置填充颜色为绿色
					settextstyle(40, 0, _T("黑体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(30, 400, "您已选择简单模式！");
					pattern = 1;
					Sleep(1000);
					break;
				}
				else if (mouseX >= 400 && mouseX <= 600 && mouseY >= 420 && mouseY <= 520) {//困难模式
					setcolor(RED);  // 设置颜色为红色
					setfillcolor(RED);  // 设置填充颜色为红色
					settextstyle(40, 0, _T("宋体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(620, 400, "您已选择困难模式！");
					pattern = 2;
					Sleep(1000);
					break;
				}
			}
		}
		//		Sleep(50);//动画速度，但会导致界面卡顿
	}
}

void Select()//选择角色
{
	Ccolor = 1;//猫色
	clock_t time = clock();// 游戏开始时间
	int i = 0;
	while (true)// 开场动画
	{
		drawAlpha(&bk, 0, 0, &SE[i]);//动图
		i = rand() % 4;
		drawAlpha(&bk, 171, 180, &CAT[1]);//贴猫1
		drawAlpha(&bk, 466, 180, &CAT[5]);//贴猫2
		drawAlpha(&bk, 746, 180, &CAT[8]);//贴猫3
		drawAlpha(&bk, 120, 228, &ENTRY[0]);//贴词条1
		drawAlpha(&bk, 410, 228, &ENTRY[1]);//贴词条2
		drawAlpha(&bk, 695, 228, &ENTRY[2]);//贴词条3

		drawAlpha(&bk, 120, 440, &KEY[0]);//贴按钮1
		drawAlpha(&bk, 415, 440, &KEY[0]);//贴按钮2
		drawAlpha(&bk, 700, 440, &KEY[1]);//贴按钮3

		put();//贴图
		if (MouseHit()) {  // 判断是否有鼠标点击事件
			MOUSEMSG msg = GetMouseMsg();  // 获取鼠标事件
			if (msg.uMsg == WM_LBUTTONDOWN) {  // 判断是否是鼠标左键点击事件
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 120 && mouseX <= 270 && mouseY >= 440 && mouseY <= 515) {//普通猫
					setcolor(GREEN);  // 设置颜色为绿色
					setfillcolor(GREEN);  // 设置填充颜色为绿色
					settextstyle(40, 0, _T("黑体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(50, 400, "您已选择普通猫！");
					g = 6;
					vx = 6;
					if (c[0] >= 4)c[0] -= 4;
					if (c[1] >= 4)c[1] -= 4;
					if (c[2] >= 4)c[2] -= 4;
					if (c[3] >= 4)c[3] -= 4;
					character = 1;
					Sleep(1000);
					break;
				}
				else if (mouseX >= 415 && mouseX <= 565 && mouseY >= 440 && mouseY <= 515) {//狂暴猫
					setcolor(RED);  // 设置颜色为红色
					setfillcolor(RED);  // 设置填充颜色为红色
					settextstyle(40, 0, _T("黑体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(360, 400, "您已选择狂暴猫！");
					g = 7;
					character = 2;
					vx = 10;
					if (c[0] < 4)c[0] += 4;
					if (c[1] < 4)c[1] += 4;
					if (c[2] < 4)c[2] += 4;
					if (c[3] < 4)c[3] += 4;
					Sleep(1000);
					if (pattern == 2) {
						drawAlpha(&bk, 0, 0, &BK[4]);//动图
						put();//贴图
						Sleep(1500);
					}
					break;
				}
				else if (mouseX >= 700 && mouseX <= 850 && mouseY >= 440 && mouseY <= 515) {//神秘猫
					setcolor(RED);  // 设置颜色为红色
					setfillcolor(RED);  // 设置填充颜色为红色
					settextstyle(50, 0, _T("黑体"));  // 设置文本样式
					setbkmode(TRANSPARENT);  // 设置背景透明
					outtextxy(420, 380, "神秘猫将在100分后解锁~");
					Sleep(1500);
				}
			}
		}
		//		Sleep(50);//动画速度，但会导致界面卡顿
	}
}

void start()//第二次点击前
{
	//4面墙
	X[0] = 900 + 30;//前
	X[1] = 900 + 30 + 323;//中前
	X[2] = 900 + 30 + 323 + 323;//中后
	X[3] = 900 + 30 + 323 + 323 + 323;//后

	landX = 0;//点击前地面贴图横坐标
	score = 0;//点击前分数
	y = 250;//游戏开始猫位置
	vy = 0;//下落速度
	if (character == 2)Ccolor = 5;
	clock_t time = clock();//游戏初始时间
	clock_t t = clock();// 开场动画
	background = rand() % 4;//背景
	while (true)
	{
		drawAlpha(&bk, 0, 0, &BK[background]);
		drawAlpha(&bk, 347, 120, &READY);
		drawAlpha(&bk, 0, 0, &TIP);
		drawAlpha(&bk, (int)x, (int)y, &CAT[Ccolor]);
		drawAlpha(&bk, (int)landX, (int)landY, &LAND);
		drawScore(500, 60, score, 13, 26);
		landX -= (clock() - t) * vx / 100;

		t = clock();
		put();
		if (landX < -800)landX = 0;//刷新地面贴图
		if (GetControl())break;
		Sleep(10);
	}
}

void game()// 游戏函数
{
	//毫秒
	startTime = clock();
	long time = clock();
	while (!Die())
	{
		// 移动
		move(clock() - time);
		time = clock();
		if (GetControl()) {//点击
			if (character == 1)vy = -20;// 飞起速度
			else vy = -10;
			if (character == 1) {//角色1颜色编码0-3
				if (pattern == 1) {//简单
					if (Ccolor < 2)Ccolor++;//更换颜色
					else Ccolor = 0;
				}
				else {//困难
					if (Ccolor < 3)Ccolor++;//更换颜色
					else Ccolor = 0;
				}
			}
			else {//角色2颜色编码4-7
				if (pattern == 1) {//简单
					if (Ccolor < 6)Ccolor++;//更换颜色
					else Ccolor = 4;
				}
				else {//困难
					if (Ccolor < 7)Ccolor++;//更换颜色
					else Ccolor = 4;
				}
			}
			}
		Draw();// 绘制
		Sleep(10);
	}
	startTime = clock();
	while (clock() - startTime < 1000);
	vy = -30;
	time = clock();
	drawAlpha(&OVER, 0, 0, &bk);// 备份结算背景
}

void end()// 结束函数
{
	startTime = clock();
	if (score > 0)
	{
		if (score > 1) {
			int i = 2;
			while (true)//最高分动画
			{
				drawAlpha(&bk, 0, 0, &E[i]);
				i++;
				if (i == 6)i = 2;
				put();//贴图
				if (GetControl())break;
				Sleep(50);
			}
		}
		else drawAlpha(&bk, 0, 0, &E[1]);
	}
	else {
		drawAlpha(&bk, 0, 0, &E[0]);
	}
	drawScore(500, 150, score, 16, 16);// 打印当前分
	while (MouseHit()) GetMouseMsg();
	while (_kbhit())_getch();//关闭键
	put();
	while (true)
	{
		if (GetControl())break;
		Sleep(10);
	}
}

void move(long time)// 猫, 地面, 墙移动
{
	y += time * vy / 100;//猫移动速度
	vy += g * time / 100;
	if (y < 0 - 10)y = -10;//防止猫飞出上边界

	landX -= time * vx / 50;//陆地移动速度
	if (landX < -888)landX = 0;//刷新陆地贴图
	
	X[0] -= time * vx / 50;//墙移动速度
	X[1] -= time * vx / 50;
	X[2] -= time * vx / 50;
	X[3] -= time * vx / 50;
	Y[0] = 0;
	Y[1] = 0;
	Y[2] = 0;
	Y[3] = 0;
	if (pattern == 1) {//简单
		if (X[0] < -50)//前墙消失位置
		{
			X[0] = X[1] + 1000;//前墙下一次出现位置
			c[0] = rand() % 3;
			if (character == 2)c[0] += 4;
		}
		if (X[1] < -50)//中前墙消失位置
		{
			X[1] = X[2] + 1000;//中前墙下一次出现位置
			c[1] = rand() % 3;
			if (character == 2)c[1] += 4;
		}
		if (X[2] < -50)//中后墙消失位置
		{
			X[2] = X[3] + 1000;//中后墙下一次出现位置
			c[2] = rand() % 3;
			if (character == 2)c[2] += 4;
		}
		if (X[3] < -50)//后墙消失位置
		{
			X[3] = X[0] + 1000;//后墙下一次出现位置
			c[3] = rand() % 3;
			if (character == 2)c[3] += 4;
		}
	}
	else {//困难
		if (X[0] < -50)//前墙消失位置
		{
			X[0] = X[1] + 1000;//前墙下一次出现位置
			c[0] = rand() % 4;
			if (character == 2)c[0] += 4;
		}
		if (X[1] < -50)//中前墙消失位置
		{
			X[1] = X[2] + 1000;//中前墙下一次出现位置
			c[1] = rand() % 4;
			if (character == 2)c[1] += 4;
		}
		if (X[2] < -50)//中后墙消失位置
		{
			X[2] = X[3] + 1000;//中后墙下一次出现位置
			c[2] = rand() % 4;
			if (character == 2)c[2] += 4;
		}
		if (X[3] < -50)//后墙消失位置
		{
			X[3] = X[0] + 1000;//后墙下一次出现位置
			c[3] = rand() % 4;
			if (character == 2)c[3] += 4;
		}
	}

	if (character == 1)if ((int)(clock() - startTime) > 7250)score = (int)(clock() - startTime - 7250) / 2775 + 1;//第一墙位置(开始计分点)
	if (character == 2)if ((int)(clock() - startTime) > 4300)score = (int)(clock() - startTime - 4300) / 1660 + 1;//第一墙位置(开始计分点)
//	score = (int)(clock() - startTime);
}

bool Die()// 判断死亡
{
	if (y > 450)return true;
	if (x + 40 > X[0] && x - 20 < X[0])if (Ccolor != c[0])return true;
	if (x + 40 > X[1] && x - 20 < X[1])if (Ccolor != c[1])return true;
	if (x + 40 > X[2] && x - 20 < X[2])if (Ccolor != c[2])return true;
	if (x + 40 > X[3] && x - 20 < X[3])if (Ccolor != c[3])return true;
	return false;
}

void reset()
{
	drawAlpha(&bk, 0, 0, &BK[background]);
}

void put()
{
	putimage(0, 0, &bk);
}

void Draw()
{
	drawAlpha(&bk, 0, 0, &BK[background]);//初始背景图
	drawWall();//贴墙
	drawAlpha(&bk, (int)landX, (int)landY, &LAND);//贴地面
	drawAlpha(&bk, (int)x, (int)y, &CAT[Ccolor]);//贴猫
	drawScore(500, 60, score, 13, 26);// 贴分数
	put();// 将背景画到窗口上
}

void drawWall()
{
	// 前
	drawAlpha(&bk, (int)X[0], Y[0], &P[c[0]]);
	// 前中
	drawAlpha(&bk, (int)X[1], Y[1], &P[c[1]]);
	// 后中
	drawAlpha(&bk, (int)X[2], Y[2], &P[c[2]]);
	//后
	drawAlpha(&bk, (int)X[3], Y[3], &P[c[3]]);
}

void drawScore(int x, int y, int sc, int dif, int se)
{
	// 将分数居中显示
	int t = sc;
	int num[8];//8位数位置上的数字
	int length = 0;
	do
	{
		num[length] = t % 10;
		length++;
		t /= 10;
	} while (t != 0);
	int s = x - dif * length;// 计算出起始坐标
	for (int i = length - 1; i >= 0; i--)
	{
		drawAlpha(&bk, s, y, &N[num[i]]);
		s += se;
	}
}

