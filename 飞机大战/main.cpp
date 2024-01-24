//飞机大战
//EasyX
#include <iostream>
#include <graphics.h>//easyx
using namespace std;

constexpr auto swidth = 600;
constexpr auto sheight = 1100;


bool PointInRect(int x, int y, RECT& r) 
{
	return (r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}


//一个开始界面
void Welcome()
{
	LPCTSTR title = _T("飞机大战");
	LPCTSTR tplay = _T("开始游戏");
	LPCTSTR texit = _T("退出游戏");


	RECT tplayr, texitr;//位置结构体
	BeginBatchDraw();//阻止频闪
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(60, 0, _T("黑体"));
	settextcolor(BLACK);//20-23行负责字体的大小和样式
	outtextxy(swidth / 2-textwidth(title) / 2, sheight / 10, title);//居中显示标题
	
	settextstyle(40, 0, _T("黑体"));//设置位字体大小必须要在 下面27-30行代码前；
	tplayr.left = swidth / 2 - textwidth(tplay) / 2;
	tplayr.right = tplayr.left + textwidth(tplay);
	tplayr.top = sheight / 5*2.5;
	tplayr.bottom = tplayr.top + textheight(tplay);
	outtextxy(tplayr.left, tplayr.top, tplay);//开始游戏  字样的位置
	
	texitr.left = swidth / 2 - textwidth(texit) / 2;
	texitr.right = texitr.left + textwidth(texit);
	texitr.top = sheight / 5*3;
	texitr.bottom = texitr.top + textheight(texit);
	outtextxy(texitr.left, texitr.top, texit);//退出游戏  字样的位置

	EndBatchDraw();//阻止频闪

	while (true) {


		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton) {
			if (PointInRect(mess.x, mess.y, tplayr)) {
				return;
			}
		}
		else if (PointInRect(mess.x, mess.y, texitr)) {
			exit(0);
		}
	}






	
}


int main()
{
	//easyx初始化
	initgraph(swidth, sheight, EW_NOMINIMIZE|EW_SHOWCONSOLE);
	bool is_live = true;
	while (is_live) {

		Welcome();
		//Play
	}

	return 0;
}