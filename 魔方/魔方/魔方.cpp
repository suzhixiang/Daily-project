// 魔方.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#ifndef CUBE
#define CUBE

#include<iostream>
using namespace std;
class cube
{
public:
	void RUN();
	cube()
	{
		NUM = 1;
	};
private:
	int NUM;
	char center[6];
	char edge[12][2];
	char vertex[8][3];
	bool input_cube();
	void output_cube();
	void basic_move_R();
	void basic_move_L();
	void basic_move_U();
	void basic_move_D();
	void basic_move_d();
	void basic_move_M_h();
	void basic_move_M_v();
	void basic_move_F();
	void basic_move_B();
	void basic_move_r();
	void basic_move_u();
	void basic_move_f();
	void basic_move_b();
	void basic_move_x();
	void basic_move_y();
	void basic_move_z();
	void R();
	void R2();
	void R_();
	void L();
	void L2();
	void L_();
	void r();
	void r2();
	void r_();
	void F();
	void F2();
	void F_();
	void B();
	void B2();
	void B_();
	void f();
	void f2();
	void f_();
	void U();
	void U2();
	void U_();
	void u();
	void u2();
	void u_();
	void D();
	void D2();
	void D_();
	void M_h();
	void M_h2();
	void M_h_();
	void M_v();
	void M_v2();
	void M_v_();
	void x();
	void x2();
	void x_();
	void y();
	void y2();
	void y_();
	void z();
	void z2();
	void z_();
	void bottom_cross();
	void bottom_vertex();
	void middlelayer();
	void top_cross();
	void top_face();
	void top_vertex();
	void top_edge();
};

bool cube::input_cube()
{
	cout << "输入魔方颜色（蓝色：B，橙色：O，绿色：G，红色：R，白色：W，黄色：Y）：" << endl;
	cout << "注意颜色不要用标点隔开，如果魔方颜色不是这六种，可自行选取字母替代。" << endl;
	cout << "请输入顶面色块（请从左上角起一排一排输入，共9块）：" << endl;
	cin >> vertex[0][0] >> edge[0][0] >> vertex[1][0];
	cin >> edge[3][0] >> center[0] >> edge[1][0];
	cin >> vertex[3][0] >> edge[2][0] >> vertex[2][0];
	cout << "请输入侧面第一层色块（从正面左上角开始逆时针输入，共12块）：" << endl;
	cin >> vertex[3][1] >> edge[2][1] >> vertex[2][2];
	cin >> vertex[2][1] >> edge[1][1] >> vertex[1][2];
	cin >> vertex[1][1] >> edge[0][1] >> vertex[0][2];
	cin >> vertex[0][1] >> edge[3][1] >> vertex[3][2];
	cout << "请输入侧面第二层色块（从正面左起第一个开始逆时针输入，共12块）：" << endl;
	cin >> edge[7][0] >> center[4] >> edge[6][1];
	cin >> edge[6][0] >> center[3] >> edge[5][1];
	cin >> edge[5][0] >> center[2] >> edge[4][1];
	cin >> edge[4][0] >> center[1] >> edge[7][1];
	cout << "请输入侧面第三层色块（从正面左下角开始逆时针输入，共12块）：" << endl;
	cin >> vertex[7][1] >> edge[10][1] >> vertex[6][2];
	cin >> vertex[6][1] >> edge[9][1] >> vertex[5][2];
	cin >> vertex[5][1] >> edge[8][1] >> vertex[4][2];
	cin >> vertex[4][1] >> edge[11][1] >> vertex[7][2];
	cout << "请输入底面色块（将魔方向后翻滚180度，从左上角起一排一排输入，共9块）:" << endl;
	cin >> vertex[7][0] >> edge[10][0] >> vertex[6][0];
	cin >> edge[11][0] >> center[5] >> edge[9][0];
	cin >> vertex[4][0] >> edge[8][0] >> vertex[5][0];
	cout << endl << "请将魔方向前翻滚180度，按回车键开始还原。" << endl;
	while (getchar() != 10)continue;
	return 1;
}

void cube::output_cube()
{
	cout << "正面：" << endl;
	cout << vertex[3][1] << " " << edge[2][1] << " " << vertex[2][2] << endl;
	cout << edge[7][0] << " " << center[4] << " " << edge[6][1] << endl;
	cout << vertex[7][1] << " " << edge[10][1] << " " << vertex[6][2] << endl;
	cout << "背面：" << endl;
	cout << vertex[1][1] << " " << edge[0][1] << " " << vertex[0][2] << endl;
	cout << edge[5][0] << " " << center[2] << " " << edge[4][1] << endl;
	cout << vertex[5][1] << " " << edge[8][1] << " " << vertex[4][2] << endl;
	cout << "右面：" << endl;
	cout << vertex[2][1] << " " << edge[1][1] << " " << vertex[1][2] << endl;
	cout << edge[6][0] << " " << center[3] << " " << edge[5][1] << endl;
	cout << vertex[6][1] << " " << edge[9][1] << " " << vertex[5][2] << endl;
	cout << "左面" << endl;
	cout << vertex[0][1] << " " << edge[3][1] << " " << vertex[3][2] << endl;
	cout << edge[4][0] << " " << center[1] << " " << edge[7][1] << endl;
	cout << vertex[4][1] << " " << edge[11][1] << " " << vertex[7][2] << endl;
	cout << "顶面：" << endl;
	cout << vertex[0][0] << " " << edge[0][0] << " " << vertex[1][0] << endl;
	cout << edge[3][0] << " " << center[0] << " " << edge[1][0] << endl;
	cout << vertex[3][0] << " " << edge[2][0] << " " << vertex[2][0] << endl;
	cout << "底面：" << endl;
	cout << vertex[7][0] << " " << edge[10][0] << " " << vertex[6][0] << endl;
	cout << edge[11][0] << " " << center[5] << " " << edge[9][0] << endl;
	cout << vertex[4][0] << " " << edge[8][0] << " " << vertex[5][0] << endl;
}

void cube::basic_move_R()
{
	char t1[3] = {};
	for (int i = 0; i<3; i++)
		t1[i] = vertex[1][i];
	vertex[1][0] = vertex[2][2]; vertex[1][1] = vertex[2][0]; vertex[1][2] = vertex[2][1];
	vertex[2][0] = vertex[6][2]; vertex[2][1] = vertex[6][1]; vertex[2][2] = vertex[6][0];
	vertex[6][0] = vertex[5][1]; vertex[6][1] = vertex[5][2]; vertex[6][2] = vertex[5][0];
	vertex[5][0] = t1[1]; vertex[5][1] = t1[0]; vertex[5][2] = t1[2];
	char t2[2] = {};
	t2[0] = edge[1][0]; t2[1] = edge[1][1];
	edge[1][0] = edge[6][1]; edge[1][1] = edge[6][0];
	edge[6][0] = edge[9][1]; edge[6][1] = edge[9][0];
	edge[9][0] = edge[5][0]; edge[9][1] = edge[5][1];
	edge[5][0] = t2[0]; edge[5][1] = t2[1];
}

void cube::basic_move_L()
{
	char t[3] = {};
	t[0] = vertex[3][1]; t[1] = edge[7][0]; t[2] = vertex[7][1];
	vertex[3][1] = vertex[7][0]; edge[7][0] = edge[11][0]; vertex[7][1] = vertex[4][0];
	vertex[7][0] = vertex[4][2]; edge[11][0] = edge[4][1]; vertex[4][0] = vertex[0][2];
	vertex[4][2] = vertex[0][0]; edge[4][1] = edge[3][0]; vertex[0][2] = vertex[3][0];
	vertex[0][0] = t[0]; edge[3][0] = t[1]; vertex[3][0] = t[2];
	t[0] = vertex[0][1]; t[1] = edge[3][1]; t[2] = vertex[3][2];
	vertex[0][1] = vertex[3][2]; edge[3][1] = edge[7][1]; vertex[3][2] = vertex[7][2];
	vertex[3][2] = vertex[7][2]; edge[7][1] = edge[11][1]; vertex[7][2] = vertex[4][1];
	vertex[7][2] = vertex[4][1]; edge[11][1] = edge[4][0]; vertex[4][1] = vertex[0][1];
	vertex[4][1] = t[0]; edge[4][0] = t[1]; vertex[0][1] = t[2];
}

void cube::basic_move_U()
{
	char c1 = vertex[3][1], c2 = vertex[3][2], c3 = edge[3][1], c4 = vertex[3][0], c5 = edge[3][0];
	for (int i = 3; i>0; i--)
	{
		vertex[i][1] = vertex[i - 1][1]; vertex[i][2] = vertex[i - 1][2]; vertex[i][0] = vertex[i - 1][0];
		edge[i][1] = edge[i - 1][1]; edge[i][0] = edge[i - 1][0];
	}
	vertex[0][1] = c1; vertex[0][2] = c2; vertex[0][0] = c4;
	edge[0][1] = c3; edge[0][0] = c5;
}

void cube::basic_move_D()
{
	char c1 = vertex[7][1], c2 = vertex[7][2], c3 = edge[11][1], c4 = vertex[7][0], c5 = edge[11][0];
	for (int i = 7; i>4; i--)
	{
		vertex[i][1] = vertex[i - 1][1]; vertex[i][2] = vertex[i - 1][2]; vertex[i][0] = vertex[i - 1][0];
		edge[i + 4][1] = edge[i + 3][1]; edge[i + 4][0] = edge[i + 3][0];
	}
	vertex[4][1] = c1; vertex[4][2] = c2; vertex[4][0] = c4;
	edge[8][1] = c3; edge[8][0] = c5;
}

void cube::basic_move_M_h()
{
	char c1 = edge[7][0], c2 = edge[7][1], c3 = center[4];
	for (int i = 3; i>0; i--)
	{
		edge[i + 4][0] = edge[i + 3][0];
		edge[i + 4][1] = edge[i + 3][1];
		center[i + 1] = center[i];
	}
	edge[4][0] = c1; edge[4][1] = c2; center[1] = c3;
}

void cube::basic_move_M_v()
{
	char t[3] = {};
	t[0] = edge[2][1]; t[1] = center[4]; t[2] = edge[10][1];
	edge[2][1] = edge[10][0]; center[4] = center[5]; edge[10][1] = edge[8][0];
	edge[10][0] = edge[8][1]; center[5] = center[2]; edge[8][0] = edge[0][1];
	edge[8][1] = edge[0][0]; center[2] = center[0]; edge[0][1] = edge[2][0];
	edge[0][0] = t[0]; center[0] = t[1]; edge[2][0] = t[2];
}

void cube::basic_move_r()
{
	basic_move_R();
	basic_move_M_v();
}

void cube::basic_move_F()
{
	basic_move_x(); basic_move_U();
	basic_move_x(); basic_move_x(); basic_move_x();
}

void cube::basic_move_f()
{
	basic_move_x(); basic_move_u();
	basic_move_x(); basic_move_x(); basic_move_x();
}

void cube::basic_move_B()
{
	basic_move_x(); basic_move_x();
	basic_move_F();
	basic_move_x(); basic_move_x();
}

void cube::basic_move_b()
{
	basic_move_x(); basic_move_x();
	basic_move_f();
	basic_move_x(); basic_move_x();
}

void cube::basic_move_u()
{
	basic_move_U();
	basic_move_M_h();
}

void cube::basic_move_d()
{
	basic_move_D();
	basic_move_M_h();
}

void cube::basic_move_x()
{
	basic_move_M_v();
	basic_move_R();
	basic_move_L();
}

void cube::basic_move_y()
{
	basic_move_U();
	basic_move_M_h();
	basic_move_D();
}

void cube::basic_move_z()
{
	basic_move_f();
	basic_move_B(); basic_move_B(); basic_move_B();
}

void cube::R()
{
	cout << NUM << "." << "将右面向后垂直旋转90度（从右往左看顺时针）" << endl;
	NUM++;
	basic_move_R();
}

void cube::R2()
{
	cout << NUM << "." << "将右面向后垂直旋转180度" << endl;
	NUM++;
	basic_move_R(); basic_move_R();
}

void cube::R_()
{
	cout << NUM << "." << "将右面向前垂直旋转90度（从右往左看逆时针）" << endl;
	NUM++;
	basic_move_R(); basic_move_R(); basic_move_R();
}

void cube::L()
{
	cout << NUM << "." << "将左面向前垂直旋转90度（从左往右看顺时针）" << endl;
	NUM++;
	basic_move_L(); basic_move_L(); basic_move_L();
}

void cube::L2()
{
	cout << NUM << "." << "将左面向后垂直旋转180度" << endl;
	NUM++;
	basic_move_L(); basic_move_L();
}

void cube::L_()
{
	cout << NUM << "." << "将左面向后垂直旋转90度（从左往右看逆时针）" << endl;
	NUM++;
	basic_move_L();
}

void cube::r()
{
	cout << NUM << "." << "将右两层向后垂直旋转90度（从右往左看顺时针）" << endl;
	NUM++;
	basic_move_r();
}

void cube::r2()
{
	cout << NUM << "." << "将右两层向后垂直旋转180度" << endl;
	NUM++;
	basic_move_r(); basic_move_r();
}

void cube::r_()
{
	cout << NUM << "." << "将右两层向前垂直旋转90度（从右往左看逆时针）" << endl;
	NUM++;
	basic_move_r(); basic_move_r(); basic_move_r();
}

void cube::F()
{
	cout << NUM << "." << "将正面向右垂直旋转90度（从正面看顺时针）" << endl;
	NUM++;
	basic_move_F();
}

void cube::F2()
{
	cout << NUM << "." << "将正面向右垂直旋转180度" << endl;
	NUM++;
	basic_move_F(); basic_move_F();
}

void cube::F_()
{
	cout << NUM << "." << "将正面向左垂直旋转90度（从正面看逆时针）" << endl;
	NUM++;
	basic_move_F(); basic_move_F(); basic_move_F();
}

void cube::f()
{
	cout << NUM << "." << "将前两层向右垂直旋转90度（从正面看顺时针）" << endl;
	NUM++;
	basic_move_f();
}

void cube::f2()
{
	cout << NUM << "." << "将前两层向右垂直旋转180度" << endl;
	NUM++;
	basic_move_f(); basic_move_f();
}

void cube::f_()
{
	cout << NUM << "." << "将前两层向左垂直旋转90度（从正面看逆时针）" << endl;
	NUM++;
	basic_move_f(); basic_move_f(); basic_move_f();
}

void cube::B()
{
	cout << NUM << "." << "将背面向右垂直旋转90度（从正面看顺时针）" << endl;
	NUM++;
	basic_move_B(); basic_move_B(); basic_move_B();
}

void cube::B2()
{
	cout << NUM << "." << "将背面向右垂直旋转180度" << endl;
	NUM++;
	basic_move_B(); basic_move_B();
}

void cube::B_()
{
	cout << NUM << "." << "将背面向左垂直旋转90度（从正面看逆时针）" << endl;
	NUM++;
	basic_move_B();
}

void cube::U()
{
	cout << NUM << "." << "将顶面向左水平旋转90度（从上往下看顺时针）" << endl;
	NUM++;
	basic_move_U();
}

void cube::U2()
{
	cout << NUM << "." << "将顶面向左水平旋转180度" << endl;
	NUM++;
	basic_move_U(); basic_move_U();
}

void cube::U_()
{
	cout << NUM << "." << "将顶面向右水平旋转90度（从上往下看逆时针）" << endl;
	NUM++;
	basic_move_U(); basic_move_U(); basic_move_U();
}

void cube::u()
{
	cout << NUM << "." << "将上两层向左水平旋转90度（从上往下看顺时针）" << endl;
	NUM++;
	basic_move_u();
}

void cube::u2()
{
	cout << NUM << "." << "将上两层向左水平旋转180度" << endl;
	NUM++;
	basic_move_u(); basic_move_u();
}

void cube::u_()
{
	cout << NUM << "." << "将上两层向右水平旋转90度（从上往下看逆时针）" << endl;
	NUM++;
	basic_move_u(); basic_move_u(); basic_move_u();
}

void cube::D()
{
	cout << NUM << "." << "将底面向左水平旋转90度（从上往下看顺时针）" << endl;
	NUM++;
	basic_move_D();
}

void cube::D2()
{
	cout << NUM << "." << "将底面向左水平旋转180度" << endl;
	NUM++;
	basic_move_D(); basic_move_D();
}

void cube::D_()
{
	cout << NUM << "." << "将底面向右水平旋转90度（从上往下看逆时针）" << endl;
	NUM++;
	basic_move_D(); basic_move_D(); basic_move_D();
}

void cube::M_h()
{
	cout << NUM << "." << "将上下方向中间层向左水平旋转90度（从上往下看顺时针）" << endl;
	NUM++;
	basic_move_M_h();
}

void cube::M_h2()
{
	cout << NUM << "." << "将上下方向中间层向左水平旋转180度" << endl;
	NUM++;
	basic_move_M_h(); basic_move_M_h();
}

void cube::M_h_()
{
	cout << NUM << "." << "将上下方向中间层向右水平旋转90度（从上往下看逆时针）" << endl;
	NUM++;
	basic_move_M_h(); basic_move_M_h(); basic_move_M_h();
}

void cube::M_v()
{
	cout << NUM << "." << "将左右方向中间列向后垂直旋转90度（从右往左看顺时针）" << endl;
	NUM++;
	basic_move_M_v();
}

void cube::M_v2()
{
	cout << NUM << "." << "将左右方向中间列向后垂直旋转180度" << endl;
	NUM++;
	basic_move_M_v(); basic_move_M_v();
}

void cube::M_v_()
{
	cout << NUM << "." << "将左右方向中间列向前垂直旋转90度（从右往左看逆时针)" << endl;
	NUM++;
	basic_move_M_v(); basic_move_M_v(); basic_move_M_v();
}
void cube::x()
{
	cout << NUM << "." << "将魔方整体向后垂直翻滚90度（从右往左看顺时针）" << endl;
	NUM++;
	basic_move_x();
}

void cube::x2()
{
	cout << NUM << "." << "将魔方整体向后垂直翻滚180度" << endl;
	NUM++;
	basic_move_x(); basic_move_x();
}

void cube::x_()
{
	cout << NUM << "." << "将魔方整体向前垂直翻滚90度（从右往左看逆时针）" << endl;
	NUM++;
	basic_move_x(); basic_move_x(); basic_move_x();
}

void cube::y()
{
	cout << NUM << "." << "将魔方整体向左水平旋转90度（从上往下看顺时针）" << endl;
	NUM++;
	basic_move_y();
}

void cube::y2()
{
	cout << NUM << "." << "将魔方整体向左水平旋转180度" << endl;
	NUM++;
	basic_move_y(); basic_move_y();
}

void cube::y_()
{
	cout << NUM << "." << "将魔方整体向右旋转90度（从上往下看逆时针）" << endl;
	NUM++;
	basic_move_y(); basic_move_y(); basic_move_y();
}

void cube::z()
{
	cout << NUM << "." << "将魔方整体向右垂直翻滚90度（从正面看顺时针）" << endl;
	NUM++;
	basic_move_z();
}

void cube::z2()
{
	cout << NUM << "." << "将魔方整体向右垂直翻滚180度（从正面看顺时针）" << endl;
	NUM++;
	basic_move_z(); basic_move_z();
}

void cube::z_()
{
	cout << NUM << "." << "将魔方整体向左垂直翻滚90度（从正面看逆时针）" << endl;
	NUM++;
	basic_move_z(); basic_move_z(); basic_move_z();
}

void cube::bottom_cross()
{
	cout << endl << "第一步目的：还原顶面十字" << endl << endl;
	NUM = 1;
	for (int count = 0; count<4; count++)
	{
		int loc; char c1 = center[4], c2 = center[0];
		for (loc = 0; loc<12; loc++)
		{
			if (edge[loc][0] == c1 || edge[loc][0] == c2)
				if (edge[loc][1] == c1 || edge[loc][1] == c2)
					break;
		}
		if (loc >= 0 && loc <= 3)
		{
			if (edge[loc][0] == center[0])
			{
				if (count == 0)
				{
					switch (loc)
					{
					case 0:U2(); break; case 1:U(); break; case 2:break; case 3:U_(); break;
					}
					y(); continue;
				}
				else
					if (loc == 2)
					{
						y(); continue;
					}
			}
			switch (loc)
			{
			case 0:B2(); break; case 1:R2(); break; case 2:F2(); break; case 3:L2(); break;
			}
			count--; continue;
		}
		else if (loc >= 4 && loc <= 7)
		{
			switch (loc)
			{
			case 4:M_h_(); F_(); M_h(); break; case 5:M_h(); F(); M_h_(); break; case 6:F(); break; case 7:F_(); break;
			}
			count--; continue;
		}
		else if (loc >= 8 && loc <= 11)
		{
			if (edge[loc][0] == center[0])
			{
				switch (loc)
				{
				case 8:D2(); break; case 9:D(); break; case 10:break; case 11:D_(); break;
				}
				F2();
			}
			else
			{
				switch (loc)
				{
				case 8:D_(); break; case 9:D2(); break; case 10:D(); break; case 11:; break;
				}
				L_(); F(); L();
			}
		}
		y(); cout << endl; NUM = 1;
	}
	cout << "顶面十字还原成功,按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
}

void cube::bottom_vertex()
{
	cout << endl << "第二步目的：将顶面四角对齐并将顶面转至底面" << endl << endl;
	NUM = 1;
	for (int count = 0; count<4; count++)
	{
		int loc; char c1 = center[0], c2 = edge[2][1], c3 = edge[1][1];
		for (loc = 0; loc<8; loc++)
		{
			if (vertex[loc][0] == c1 || vertex[loc][0] == c2 || vertex[loc][0] == c3)
				if (vertex[loc][1] == c1 || vertex[loc][1] == c2 || vertex[loc][1] == c3)
					if (vertex[loc][2] == c1 || vertex[loc][2] == c2 || vertex[loc][2] == c3)
						break;
		}
		if (loc >= 0 && loc <= 3)
		{
			if (loc == 2 && vertex[loc][1] == edge[1][1] && vertex[loc][2] == edge[2][1] && vertex[loc][0] == center[0])
			{
				y(); continue;
			}
			else
			{
				switch (loc)
				{
				case 0: {
					if (vertex[0][0] == center[0] || vertex[0][2] == center[0])
					{
						B_(); D_(); B();
					}
					else
					{
						L_(); D(); L();
					}
				}break;
				case 1: {
					if (vertex[1][0] == center[0] || vertex[1][1] == center[0])
					{
						B(); D(); B_();
					}
					else
					{
						R(); D_(); R_();
					}
				}break;
				case 2: {
					if (vertex[2][0] == center[0] || vertex[2][1] == center[0])
					{
						R_(); D(); R();
					}
					else
					{
						F(); D_(); F_();
					}
				}break;
				case 3: {
					if (vertex[3][0] == center[0] || vertex[3][2] == center[0])
					{
						L(); D_(); L_();
					}
					else
					{
						F_(); D(); F();
					}
				}break;
				}
				count--; continue;
			}
		}
		else if (loc >= 4 && loc <= 7)
		{
			if (vertex[loc][0] == center[0])
			{
				switch (loc)
				{
				case 4:D2(); break; case 5:D(); break; case 6:break; case 7:D_(); break;
				}
				F(); D(); F_();
				count--; continue;
			}
			else if (vertex[loc][1] == center[0])
			{
				switch (loc)
				{
				case 4:D2(); break; case 5:D(); break; case 6:break; case 7:D_(); break;
				}
				R_(); D(); R();
			}
			else
			{
				switch (loc)
				{
				case 4:D_(); break; case 5:D2(); break; case 6:D(); break; case 7:break;
				}
				R_(); D_(); R();
			}
		}
		y();
		cout << endl; NUM = 1;
	}
	x2();
	cout << "魔方底层还原成功，按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
}

void cube::middlelayer()
{
	cout << endl << "第三步目的：还原第二层" << endl << endl;
	NUM = 1;
	for (int count = 0; count<4; count++)
	{
		int loc;
		for (loc = 0; loc<7; loc++)
		{
			if (edge[loc][0] == center[4] || edge[loc][0] == center[3])
				if (edge[loc][1] == center[4] || edge[loc][1] == center[3])
					break;
		}
		if (loc >= 0 && loc <= 3)
		{
			if (edge[loc][1] == center[4])
			{
				switch (loc)
				{
				case 0:U_(); break; case 1:U2(); break; case 2:U(); break; case 3:break;
				}
				R(); U_(); R_(); U_(); F_(); U(); F();
			}
			else if (edge[loc][1] = center[3])
			{
				switch (loc)
				{
				case 0:; break; case 1:U_(); break; case 2:U2(); break; case 3:U(); break;
				}
				F_(); U(); F(); U(); R(); U_(); R_();
			}
		}
		else if (loc >= 4 && loc <= 7)
		{
			if (edge[loc][0] == center[3] && edge[loc][1] == center[4] && loc == 6)
			{
				y(); continue;
			}
			switch (loc)
			{
			case 4:y2(); break; case 5:y(); break; case 6:break; case 7:y_(); break;
			}
			int loc1;
			for (loc1 = 0; loc1<4; loc1++)
			{
				if (edge[loc1][0] == center[0] || edge[loc1][1] == center[0])
					break;
			}
			loc1 = (loc1 == 4) ? 2 : loc1;
			switch (loc1)
			{
			case 0:U2(); break; case 1:U(); break; case 2:break; case 3:U_(); break;
			}
			U(); R(); U_(); R_(); U_(); F_(); U(); F();
			switch (loc)
			{
			case 4:y2(); break; case 5:y_(); break; case 6:break; case 7:y(); break;
			}
			count--; continue;
		}
		y();
		cout << endl; NUM = 1;
	}
	cout << "魔方第二层还原成功，按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
}

void cube::top_cross()
{
	cout << endl << "第四步目的：还原顶面十字" << endl << endl;
	NUM = 1;
	int num = 0;
	for (int i = 0; i<4; i++)
	{
		if (edge[i][0] == center[0])
			num++;
	}
	if (num == 0)
	{
		F(); R(); U(); R_(); U_(); F_(); num = 2;
	}
	if (num == 2)
	{
		int loc[2] = { 0,0 };
		for (int i = 0, j = 0; i<4; i++)
		{
			if (edge[i][0] == center[0])
			{
				loc[j] = i; j++;
			}
		}
		if (loc[1] - loc[0] == 2)
		{
			switch (loc[0])
			{
			case 0:U(); break; case 1:break;
			}
			F(); R(); U(); R_(); U_(); F_();
		}
		else
		{
			switch (loc[0])
			{
			case 0: {
				if (loc[1] == 3)
					U2();
				else
					U();
			}break;
			case 1:break; case 2:U_(); break;
			}
			f(); R(); U(); R_(); U_(); f_();
		}
	}
	cout << "魔方顶层十字还原成功，按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
	NUM = 1;
}

void cube::top_face()
{
	cout << endl << "第五步目的：统一顶面颜色" << endl << endl;
	NUM = 1;
	int num = 0;
	for (int i = 0; i<4; i++)
	{
		if (vertex[i][0] == center[0])
			num++;
	}
	if (num == 0)
	{
		int loc1 = 0, loc2 = 0;
		loc1 = (vertex[0][1] == center[0]) ? 1 : 2;
		loc2 = (vertex[2][1] == center[0]) ? 1 : 2;
		if (loc1 == loc2)
		{
			switch (loc1)
			{
			case 1:U(); break; case 2:break;
			}
			R(); U2(); R_(); U_(); R(); U(); R_(); U_(); R(); U_(); R_();
		}
		else
		{
			switch (loc1)
			{
			case 1: {
				if (vertex[3][1] == center[0])
					U();
			}; break;
			case 2: {
				if (vertex[3][1] == center[0])
					U2();
				else
					U_();
			}break;
			}
			R(); U2(); R2(); U_(); R2(); U_(); R2(); U2(); R();
		}
	}
	else if (num == 1)
	{
		int loc1, loc2;
		for (int i = 0; i<4; i++)
		{
			if (vertex[i][0] != center[0])
				loc1 = (vertex[i][1] == center[0]) ? 1 : 2;
			else
				loc2 = i;
		}
		if (loc1 == 1)
		{
			switch (loc2)
			{
			case 0:U(); break; case 1:break; case 2:U_(); break; case 3:U2(); break;
			}
			R(); U2(); R_(); U_(); R(); U_(); R_();
		}
		else
		{
			switch (loc2)
			{
			case 0:U2(); break; case 1:U(); break; case 2:break; case 3:U_(); break;
			}
			R_(); U2(); R(); U(); R_(); U(); R();
		}
	}
	else if (num == 2)
	{
		int loc[2];
		for (int i = 0, j = 0; i<4; i++)
		{
			if (vertex[i][0] != center[0])
			{
				loc[j] = i; j++;
			}
		}
		if (loc[1] - loc[0] == 2)
		{
			int loc1;
			loc1 = (vertex[loc[0]][1] == center[0]) ? loc[1] : loc[0];
			switch (loc1)
			{
			case 0:U2(); break; case 1:U(); break; case 2:break; case 3:U_(); break;
			}
			F_(); r(); U(); R_(); U_(); r_(); F(); R();
		}
		else
		{
			switch (loc[0])
			{
			case 0: {
				if (loc[1] == 3)
					U_();
				else
					U2();
			}break;
			case 1:U(); break; case 2:break;
			}
			if (vertex[2][1] == center[0])
			{
				U(); r(); U(); R_(); U_(); r_(); F(); R(); F_();
			}
			else
			{
				R(); U(); R_(); U(); R(); U2(); R_(); U(); R(); U2(); R_(); U_(); R(); U_(); R_();
			}
		}
	}
	cout << "魔方顶面颜色统一成功，按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
	NUM = 1;
}

void cube::top_vertex()
{
	cout << endl << "第六步目的：顶面各角排序" << endl << endl;
	NUM = 1;
	int loc[2] = { -1,-1 }; int num = 0;
x:
	for (int i = 0; i<4; i++)
	{
		if (vertex[i][2] == vertex[(i + 1) % 4][1])
		{
			num++;
			if (num == 1)
			{
				loc[0] = i; loc[1] = (i + 1) % 4;
			}
		}
	}
	if (num == 0)
	{
		x_(); R2(); D2(); R_(); U_(); R(); D2(); R_(); U(); R_(); x();
		goto x;
	}
	else if (num != 4)
	{
		switch (loc[0])
		{
		case 0:U(); break; case 1:break; case 2:U_(); break; case 3:U2(); break;
		}
		x_(); R2(); D2(); R_(); U_(); R(); D2(); R_(); U(); R_(); x();
	}
	int loc1;
	for (loc1 = 1; loc1<5; loc1++)
	{
		if (vertex[3][2] == center[loc1])
			break;
	}
	switch (loc1)
	{
	case 1:break; case 2:U(); break; case 3:U2(); break; case 4:U_(); break;
	}
	cout << "顶面各角排序完成，按回车键继续下一步，输入a显示此时魔方各面情况" << endl;
	NUM = 1;
}

void cube::top_edge()
{
	cout << endl << "第七步目的：对齐顶面各边" << endl << endl;
	NUM = 1;
	int num = 0;
	for (int i = 0; i<3; i++)
	{
		if (edge[i][1] != center[i + 2])
			num++;
	}
	if (edge[3][1] != center[1])
		num++;
	if (num == 3)
	{
		int loc;
		for (loc = 0; loc<3; loc++)
		{
			if (edge[loc][1] == center[loc + 2])
				break;
		}
		if (edge[3][1] == center[0])
			loc = 3;
		switch (loc)
		{
		case 0:break; case 1:y_(); break; case 2:y2(); break; case 3:y(); break;
		}
		if (edge[1][1] == center[4])
		{
			R2(); U(); R(); U(); R_(); U_(); R_(); U_(); R_(); U(); R_();
		}
		else
		{
			R(); U_(); R(); U(); R(); U(); R(); U_(); R_(); U_(); R2();
		}
	}
	else if (num == 4)
	{
		int loc;
		for (loc = 1; loc<5; loc++)
		{
			if (edge[0][1] == center[loc])
				break;
		}
		if (loc == 4)
		{
			M_v2(); U(); M_v2(); U2(); M_v2(); U(); M_v2();
		}
		else
		{
			if (loc == 3)
				U_();
			U(); R_(); U_(); R(); U_(); R(); U(); R(); U_();
			R_(); U(); R(); U(); R2(); U_(); R_(); U();
		}
	}
	int loc1;
	for (loc1 = 1; loc1<5; loc1++)
	{
		if (vertex[3][2] == center[loc1])
			break;
	}
	switch (loc1)
	{
	case 1:break; case 2:U(); break; case 3:U2(); break; case 4:U_(); break;
	}
	cout << "魔方还原成功" << endl;
}

void cube::RUN()
{
	input_cube();
	getchar();
	bottom_cross();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	bottom_vertex();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	middlelayer();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	top_cross();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	top_face();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	top_vertex();
	if (getchar() != 10)
	{
		output_cube();
		while (getchar() != 10)continue;
		cout << endl << "按回车键继续下一步" << endl;
		getchar();
	}
	top_edge();
	output_cube();
}

#endif

#include<Windows.h>
void introductions();
int main()
{
	cube c; char select;
	cout << "欢迎使用魔方还原程序" << endl;
	cout << "查看使用说明请输入a，按回车键直接开始魔方还原。" << endl;
	select = getchar();
	if (select == 'a')
	{
		introductions();
		while (getchar() != 10)continue;
		cout << endl << "按回车键开始魔方还原" << endl;
	}
	while (getchar() != 10)continue;
	c.RUN();
	while (getchar() != 10)continue;
	cout << "谢谢使用" << endl;
	Sleep(1000);
	cout << "按回车键结束" << endl;
	getchar();
	return 0;
}

void introductions()
{
	cout << "使用说明" << endl;
	cout << "1，由于本程序为测试版程序，为了方便纠错，未设定发现魔方输入错误的功能。" << endl;
	cout << "2, 请严格按照程序指示输入和转动，注意正面的位置和转动方向。" << endl;
	cout << "3，魔方各个面的颜色可以用推荐的字母表示，也可以使用自己定义的字母。" << endl;
	cout << "4, 注意每种颜色的只能用一种字母替代，且注意区分大小写。" << endl;
	cout << "5, 此程序已经过超过20种情况的检验，但仍然可能存在错误，如果发现错误，请一定与我联系。" << endl;
}