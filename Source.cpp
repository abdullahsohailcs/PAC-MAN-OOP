#include "Header.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<array>
#include<cstring>
#include<string>
#include<cmath>
#include<math.h>
#include<Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<cstdlib>

using namespace std;
int stop1 = 0;
int stop2 = 0;
class grid
{
	int** maze;
	int rows;
	int columns;
public:
	grid()
	{
		maze = reading_file();
		rows = row();
		columns = col();
	}

	void setmaze(int** z)
	{
		maze = z;
	}

	int** getmaze()
	{
		return maze;
	}


	int getrows() { return rows; }
	int getcolumns() { return columns; }
	void setrows() { rows = 0; }
	void setcolumns() { columns = 0; }

	virtual void print();
	int** reading_file();
	int row();
	int col();
	~grid();
};

grid::~grid()
{
	/*for (int i = 0; i < 28; i++)
	{
		delete[] maze[i];
	}delete[]maze;*/
	//maze = NULL;
}

void grid::print()
{
	for (int i = 0; i < getrows(); i++)
	{
		for (int j = 0; j < getcolumns(); j++)
		{
			cout << maze[i][j];
		}cout << endl;
	}
}
int** grid::reading_file()
{

	ifstream input_file;
	input_file.open("The Maze Game.txt");
	if (input_file.is_open())
	{

		string first_line1;
		string first_line2;
		string first_line3;
		string second_line1;
		string second_line2;
		string second_line3;

		int rows;
		char x;
		int cols;

		input_file >> first_line1 >> first_line2 >> first_line3 >> rows >> x >> cols >> second_line1 >> second_line2 >> second_line3;

		int** vertical_array = new int* [rows];
		for (int i = 0; i < rows; i++) {
			vertical_array[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				input_file >> vertical_array[i][j];
			}

		}

		return vertical_array;
		input_file.close();
		for (int i = 0; i < rows; i++)
		{
			delete[]vertical_array[i];
		}delete[]vertical_array;
		vertical_array = NULL;
	}
	else
	{
		cout << "ERROR: Unable to open the file. Check file name/location/format. " << endl;
	}
	cout << endl;

	
}

int grid::row()
{
	ifstream input_filer;
	input_filer.open("The Maze Game.txt");
	if (input_filer.is_open())
	{

		string first_line11;
		string first_line21;
		string first_line31;
		string second_line11;
		string second_line21;
		string second_line31;

		int rows1;
		char x1;
		int cols1;

		input_filer >> first_line11 >> first_line21 >> first_line31 >> rows1 >> x1 >> cols1 >> second_line11 >> second_line21 >> second_line31;

		int** vertical_array = new int* [rows1];
		for (int i = 0; i < rows1; i++) {
			vertical_array[i] = new int[cols1];
		}

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				input_filer >> vertical_array[i][j];
			}

		}

		return rows1;
		input_filer.close();
		for (int i = 0; i < rows; i++)
		{
			delete[]vertical_array[i];
		}delete[]vertical_array;
		vertical_array = NULL;
	}
	else
	{
		cout << "ERROR: Unable to open the file. Check file name/location/format. " << endl;
	}
	cout << endl;
}

int grid::col()
{
	ifstream input_filerc;
	input_filerc.open("The Maze Game.txt");
	if (input_filerc.is_open())
	{

		string first_line12;
		string first_line22;
		string first_line32;
		string second_line12;
		string second_line22;
		string second_line32;

		int rows2;
		char x2;
		int cols2;

		input_filerc >> first_line12 >> first_line22 >> first_line32 >> rows2 >> x2 >> cols2 >> second_line12 >> second_line22 >> second_line32;


		int** vertical_array = new int* [rows2];
		for (int i = 0; i < rows2; i++) {
			vertical_array[i] = new int[cols2];
		}

		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				input_filerc >> vertical_array[i][j];
			}

		}

		return cols2;
		input_filerc.close();
		for (int i = 0; i < rows; i++)
		{
			delete[]vertical_array[i];
		}delete[]vertical_array;
		vertical_array = NULL;
	}
	else
	{
		cout << "ERROR: Unable to open the file. Check file name/location/format. " << endl;
	}
	cout << endl;
}

class initial_print :public grid {

	int** u;
public:
	initial_print() { u = getmaze(); }
	void print();
	void path();
	int** getu() { return u; }
	void setu(int** q) { u = q; }

	~initial_print()
	{
		for (int i = 0; i < 28; i++)
		{
			delete[] u[i];
		}delete[]u;
		u = NULL;
	}
};

void initial_print::print()
{
	grid obj;
	int** a = getu();
	for (int i = 0; i < obj.getrows(); i++)
	{
		for (int j = 0; j < obj.getcolumns(); j++)
		{
			cout << a[i][j];
		}cout << endl;

	}

	delay(10);
	//drawRectangle(0, 20, 1080, 560, 0, 0, 0, 230, 150, 270);
	drawRectangle(0, 20, 1080, 560, 0, 0, 0, 0, 0, 0);

	int y = 0;

	for (int i = 0; i < obj.getrows(); i++)
	{
		y = y + 20;
		int x = 0;
		for (int ii = 0; ii < obj.getcolumns(); ii++)
		{
			x = x + 9;

			if (a[i][ii] == 1 && x <= 1080 && y <= 560)
			{
				drawRectangle(x - 9, y - 20, x, y, 0, 0, 0, 100, 00, 100);

			}
		}
	}
}

void initial_print::path()
{
	grid obj;
	int** a = getu();
	//drawRectangle(0, 20, 1080, 560, 0, 0, 0, 0, 0, 0);

	int y = 0;

	for (int i = 0; i < obj.getrows(); i++)
	{
		y = y + 20;
		int x = 0;
		for (int ii = 0; ii < obj.getcolumns(); ii++)
		{
			x = x + 9;

			if (a[i][ii] == 9)
			{
				drawRectangle(x - 9, y - 20, x, y, 0, 0, 0, 0, 0, 139);
			}
			else if (a[i][ii] == 5)
			{
				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 0, 0, 0);

				drawEllipse(x - 9, y - 15, x - 13, y - 5, 255, 0, 0, 255, 0, 0);

			}
			else if (a[i][ii] == 0)
			{
				drawEllipse(x - 8, y - 13, x - 13, y - 5, 0, 0, 0, 0, 0, 0);
				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 0, 0, 0);
				
				drawEllipse(x - 8, y - 13, x - 13, y - 5, 0, 255, 200, 200, 255, 0);

			}
			else if (a[i][ii] == 2)
			{

				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 255, 255, 0);

			}
			else if (a[i][ii] == 3)
			{
				drawEllipse(x - 8, y - 13, x - 13, y - 5, 0, 0, 0, 0, 0, 0);
				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 0, 0, 0);

			}else if(a[i][ii]==8)
			{
				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 18, 87, 224);

			}
			else if (a[i][ii] == 7)
			{
				drawRectangle(x - 8, y - 18, x + 1, y + 1, 0, 0, 0, 128, 128, 128);

			}
			
		}
        
	}
}

class ghost1 :public initial_print
{
	int** g_maze;
public:
	ghost1();
	int** getghost1();
	void setghost1(int** b);
	virtual void movement1();
	virtual void e1();

	~ghost1();
};

ghost1::ghost1()
{
	g_maze = getmaze();
}

int** ghost1::getghost1()
{
	return g_maze;
}

void ghost1::setghost1(int** b)
{
	g_maze = b;
}

ghost1::~ghost1()
{
	for (int i = 0; i < getrows(); i++)
	{
		delete[] g_maze[i];
	}delete[]g_maze;
	g_maze = NULL;
}

int uu = 0;
int d = 0;
int r = 0;
int l = 0;
int maxi = 11;

void ghost1::movement1()
{
	if (stop1 < 1) {
		//random ghost < -----------------------------------------------------------------
		int random = rand() % maxi;
		if (g_maze[11][56] == 8)
		{
			g_maze[10][56] = 8;
			g_maze[11][56] = 9;
			setu(g_maze);

		}
		else {

			if (random == 0 || random == 1 || random == 2) {
				if (g_maze[10 - uu + d][56 - l + r] == 8 && g_maze[10 - uu - 1 + d][56 - l + r] != 1 && (10 + d - uu - 1) > 0 && g_maze[10 - uu + d - 1][56 - l + r] != 9 && (g_maze[10 - uu - 1 + d][56 - l + r] == 0 || g_maze[10 - uu - 1 + d][56 - l + r] == 3 || g_maze[10 - uu - 1 + d][56 - l + r] == 5))
				{
					int dda = 0;
					dda = g_maze[10 - uu + d - 1][56 - l + r];
					g_maze[10 - uu + d - 1][56 - l + r] = 8;
					g_maze[10 - uu + d][56 - l + r] = dda;

					setu(g_maze);

					uu++;

				}
			}
			else if (random == 3 || random == 4 || random == 5)
			{
				if (g_maze[10 - uu + d][56 - l + r] == 8 && g_maze[10 - uu + 1 + d][56 - l + r] != 1 && (10 - uu - 1 + d) < 28 && g_maze[10 - uu + d + 1][56 - l + r] != 9 && (g_maze[10 - uu + d + 1][56 - l + r] == 0 || g_maze[10 - uu + d + 1][56 - l + r] == 3 || g_maze[10 - uu + d + 1][56 - l + r] == 5))
				{
					int da = g_maze[10 - uu + d + 1][56 - l + r];
					g_maze[10 - uu + d + 1][56 - l + r] = 8;
					g_maze[10 - uu + d][56 - l + r] = da;
					setu(g_maze);

					d++;

				}

			}
			else if (random == 6 || random == 7 || random == 8)
			{
				if (g_maze[10 - uu + d][56 - l + r] == 8 && g_maze[10 - uu + d][56 - l + r + 1] != 1 && (56 - l + r + 1) < 120 && g_maze[10 - uu + d][56 - l + r + 1] != 9 && (g_maze[10 - uu + d][56 - l + r + 1] == 0 || g_maze[10 - uu + d][56 - l + r + 1] == 3 || g_maze[10 - uu + d][56 - l + r + 1] == 5))
				{
					int dd = g_maze[10 - uu + d][56 - l + r + 1];
					g_maze[10 - uu + d][56 - l + r + 1] = 8;
					g_maze[10 - uu + d][56 - l + r] = dd;
					setu(g_maze);

					r++;

				}
			}
			else if (random == 9 || random == 10 || random == 11)
			{
				if (g_maze[10 - uu + d][56 - l + r] == 8 && g_maze[10 - uu + d][56 - l + r - 1] != 1 && (56 - l + r - 1) > 0 && g_maze[10 - uu + d][56 - l + r - 1] != 9 && (g_maze[10 - uu + d][56 - l + r - 1] == 0 || g_maze[10 - uu + d][56 - l + r - 1] == 3 || g_maze[10 - uu + d][56 - l + r - 1] == 5))
				{
					int ddd = 0;
					int dd = g_maze[10 - uu + d][56 - l + r - 1];
					g_maze[10 - uu + d][56 - l + r - 1] = 8;
					g_maze[10 - uu + d][56 - l + r] = ddd;
					setu(g_maze);

					l++;

				}
			}

		}
	}stop1 = stop1 - 100;
}

void ghost1::e1()
{
	g_maze[10 - uu + d][56 - l + r] = 3;
	g_maze[11][56] = 8;
	 uu = 0;
	 d = 0;
	 r = 0;
	 l = 0;
	setu(g_maze);
}

class score :public grid
{
	int scores;
	int** s;
public:
	score() {
		s = getmaze();
		scores = 0;
	}
	void setscores(int g) { scores = g; }
	void sets(int** ll) { s = ll; }
	int getscores() { return scores; }
	int** gets() { return s; }
	int scoring();

	~score()
	{
		for (int i = 0; i < 28; i++)
		{
			delete[] s[i];
		}delete[]s;
		s = NULL;
	}
};

int score::scoring()
{
	int xsc = 0;

	for (int i = 0; i < getrows(); i++)
	{
		for (int ii = 0; ii < getcolumns(); ii++)
		{
			if (s[i][ii] == 3)
			{
				xsc = xsc + 10;
			}
		}
	}

	return xsc;
}

class lifeline
{
	int life;
public:
	lifeline() {
		life = 30;
	}
	int getlife() { return life; }
	void setlife(int g) { life = g; }

	void left() {
		life--;
		 setlife(life);
	}

	~lifeline(){}
};

int ui = 0;
int di = 0;
int ri = 0;
int li = 0;
class ghost2 :public ghost1
{
	int** g_maze2;
	int px;
	int py;
public:
	ghost2();
	int** getghost2();
	void setghost2(int** b);
	void movement1();
	void setpx(int g) { px = g; }
	void setpy(int gs) { px = gs; }
	int getpx() { return px; }
	int getpy() { return py; }
	void e1();

	~ghost2();
};

ghost2::ghost2()
{
	px = 0;
	py = 0;
	g_maze2 = getmaze();
}

int** ghost2::getghost2()
{
	return g_maze2;
}

void ghost2::setghost2(int** b)
{
	g_maze2 = b;
}

ghost2::~ghost2()
{
	for (int i = 0; i < getrows(); i++)
	{
		delete[] g_maze2[i];
	}delete[]g_maze2;
	g_maze2 = NULL;
}

int iy = 10;
int ix = 55;
void ghost2::movement1()
{
	if (stop2 < 1) {

		if (g_maze2[11][55] == 7)
		{
			g_maze2[10][55] = 7;
			g_maze2[11][55] = 9;
			setu(g_maze2);



		}
		else
		{

			if ((g_maze2[iy - ui + di - 1][ix + ri - li] != 2 || g_maze2[iy - ui + di - 1][ix + ri - li] == 0 || g_maze2[iy - ui + di - 1][ix + ri - li] == 3 || g_maze2[iy - ui + di - 1][ix + ri - li] == 5) && ((iy - 1 - ui + di) > 0) && (py < (iy - ui + di)) && px != (ix + ri - li) &&(g_maze2[iy - ui + di - 1][ix + ri - li] != 1 && g_maze2[iy - ui + di + 1][ix + ri - li] != 1))
			{
				int q0 = g_maze2[iy - ui + di - 1][ix + ri - li];
				g_maze2[iy - ui + di - 1][ix + ri - li] = 7;
				g_maze2[iy - ui + di][ix + ri - li] = q0;
				setu(g_maze2);
				ui++;
			}
			else if (g_maze2[iy - ui + di + 1][ix + ri - li] != 2 && (g_maze2[iy - ui + di + 1][ix + ri - li] == 0 || g_maze2[iy - ui + di + 1][ix + ri - li] == 3 || g_maze2[iy - ui + di + 1][ix + ri - li] == 5) && ((iy + 1 - ui + di) < 28) && (py > (iy - ui + di)))
			{
				int qz = g_maze2[iy - ui + di + 1][ix + ri - li];
				g_maze2[iy - ui + di + 1][ix + ri - li] = 7;
				g_maze2[iy - ui + di][ix + ri - li] = qz;
				setu(g_maze2);
				di++;
			}
			else if (g_maze2[iy - ui + di][ix + ri - li - 1] != 2 && (g_maze2[iy - ui + di][ix + ri - li - 1] == 0 || g_maze2[iy - ui + di][ix + ri - li - 1] == 3 || g_maze2[iy - ui + di][ix + ri - li - 1] == 5) && (ix + ri - li - 1) > 0 && px < (ix + ri - li))
			{
				int qz1 = g_maze2[iy - ui + di][ix - 1 + ri - li];
				g_maze2[iy - ui + di][ix + ri - li - 1] = 7;
				g_maze2[iy - ui + di][ix + ri - li] = qz1;
				setu(g_maze2);
				li++;
			}
			else if (g_maze2[iy - ui + di][ix + ri - li + 1] != 2 && (g_maze2[iy - ui + di][ix + ri - li + 1] == 0 || g_maze2[iy - ui + di][ix + ri - li + 1] == 3 || g_maze2[iy - ui + di][ix + ri - li + 1] == 5) && (ix + ri - li + 1) < 120 && px > (ix + ri - li))
			{
				int qqa = g_maze2[iy - ui + di][ix + 1 + ri - li];
				g_maze2[iy - ui + di][ix + ri - li + 1] = 7;
				g_maze2[iy - ui + di][ix + ri - li] = qqa;
				setu(g_maze2);
				ri++;
			}
			else {
				if (g_maze2[iy - ui + di + 1][ix + ri - li] != 2 && (g_maze2[iy - ui + di + 1][ix + ri - li] == 0 || g_maze2[iy - ui + di + 1][ix + ri - li] == 3 || g_maze2[iy - ui + di + 1][ix + ri - li] == 5))
				{
					int qlqa = g_maze2[iy - ui + di + 1][ix + ri - li];
					g_maze2[iy - ui + 1 + di][ix + ri - li] = 7;
					g_maze2[iy - ui + di][ix + ri - li] = qlqa;
					setu(g_maze2);
					di++;
				}
			}
		}
	}stop2 = stop2 - 100;
}

void ghost2::e1()
{
	g_maze2[iy - ui + di ][ix + ri - li] = 3;
	g_maze2[11][55] = 7;
	ui = 0;
	di = 0;
	ri = 0;
	li = 0;
	setu(g_maze2);
}

class collide :public initial_print, public lifeline
{
	int** co;
public:
	collide();
	void eat_ghost();
	void get_killed();
	int** getco() { return co; }
	void setco(int** vgy) { co = vgy; }

	~collide(){
		for (int i = 0; i < 28; i++)
		{
			delete[] co[i];
		}delete[]co;
		co = NULL;
	}
};

collide::collide()
{
	co = getu();
}

void collide::eat_ghost()
{
	
	//for (int i = 0; i < 10; i++)
	//{
	//	if(o[][])
	//	delay
	//}

}

void collide::get_killed()
{
	
	for (int i = 0; i < 28; i++)
	{
		for (int ii = 0; ii < 120; ii++)
		{
			if (ii>0 && i>0) {
				if ((co[i][ii] == 2) && (co[i + 1][ii] == 7 || co[i + 1][ii] == 8 || co[i - 1][ii] == 7 || co[i - 1][ii] == 8 || co[i][ii + 1] == 7 || co[i][ii + 1] == 8 || co[i][ii - 1] == 7 || co[i][ii - 1] == 8))
				{
					co[i][ii] = 3;
					co[1][2] = 2;
					
					setu(co);
				}
			}
		}
	}
}

int main()
{
	int w = 1080, h = 600;
	getWindowDimensions(w, h);

	cls();
	showConsoleCursor(false);



   cout << setw(50) << " 11       1       11  11111 11     111111 111111 111       111 11111   11111111 111111  " << endl
		<< setw(50) << "  11     1 1     11   11    11     11     11  11 11 1     1 11 11         11    11  11  " << endl
		<< setw(50) << "   11   1   1   11    11111 11     11     11  11 11  1   1  11 11111      11    11  11  " << endl
		<< setw(50) << "    11 1     1 11     11    11     11     11  11 11   1 1   11 11         11    11  11  " << endl
		<< setw(50) << "     11       11      11111 111111 111111 111111 11    1    11 11111      11    111111  " << endl;

  cout << setw(50) << "                                 " << endl
	   << setw(50) << "                                 " << endl
       << setw(50) << "                                 " << endl
	   << setw(50) << "                                 " << endl
	   << setw(50) << "                                 " << endl;


  cout << setw(50) <<"      111111 111111 11111      111        111 111111 111    11 " << endl
	  << setw(50) << "      11  11 11  11 11         1111      1111 11  11 11 1   11 " << endl
	  << setw(50) << "      111111 111111 11    111  11  11   11 11 111111 11  1  11 " << endl
	  << setw(50) << "      11     11  11 11         11   11 11  11 11  11 11   1 11 " << endl
	  << setw(50) << "      11     11  11 11111      11    11    11 11  11 11    111 " << endl;
  cout << setw(50) << "                                                 By Abdullah Sohail(Night)" << endl << endl;



  cout << setw(50) << "                                 " << endl
	  << setw(50) << "                                 " << endl
  << setw(50) << "                                 " << endl
  << setw(50) << "                                 " << endl
	  << setw(50) << "                                 " << endl;


	int xg = 0;
	while (xg == 0) {

		cout << setw(50) <<"    11111  11                       11       "<<endl
			<< setw(50) << "    11    1111              11 11  1111      "<<endl
			<< setw(50) << "    11111  11      111111   111     11       "<<endl
			<< setw(50) << "       11  11  11  11  11   11      11  11   "<<endl
			<< setw(50) << "    11111  111111  11111111 11      111111   " << endl;
		bool played = PlaySound(TEXT("p.wav"), NULL, SND_SYNC);

		cout << setw(50) << "Press 2 to play game." << endl;
		cin >> xg;
	}
	
	gotoxy(0, 0);
	initial_print ip;
	grid g;
	grid* ptr = &ip;
	ptr->print();
	ghost1 g1;
	ghost2 g2;

	ghost1* ptr1 = &g2;

	score sc;
	srand(time(0));
	collide colli;
	int** a = g.getmaze();

	// main event loop

	lifeline ll;
	int up = 0;
	int down = 1;
	int left = 0;
	int right = 2;
	int flag = 0;
	int counter = 0;
	int winwin;
	int s1 = 0;
	int s2 = 0;

	while (true && ll.getlife() != 0)
	{
		ip.path();
		int power = 0;
		int win = 0;


		char c = getKey();

		if (c == 'q')
		{
			break;
		}

		//up
		if (c == 'w')
		{
			if ((a[down - up - 1][right - left] == 0 || a[down - up - 1][right - left] == 3 || a[down - up - 1][right - left] == 5) && down - up - 1 > 0 && right - left > 0)

			{
				int c = 2;
				a[down - up][right - left] = 3;
				a[down - up - 1][right - left] = c;
				a[down - up][right - left] = 3;

				ip.setu(a);
				up++;
				delay(5);
			}
		}


		//down
		if (c == 's')
		{
			if ((a[down - up + 1][right - left] == 0 || a[down - up + 1][right - left] == 3 || a[down - up + 1][right - left] == 5) && down - up < g.getrows() && right - left < g.getcolumns())
			{

				int cq = 2;
				a[down - up][right - left] = 3;

				a[down - up + 1][right - left] = cq;
				a[down - up][right - left] = 3;

				ip.setu(a);
				down++;
				delay(5);
			}

		}

		//right
		if (c == 'd')
		{
			if ((a[down - up][right - left + 1] == 0 || a[down - up][right - left + 1] == 3 || a[down - up][right - left + 1] == 5) && down - up < g.getrows() && right - left < g.getcolumns())
			{

				int cq = 2;
				a[down - up][right - left] = 3;

				a[down - up][right - left + 1] = cq;
				a[down - up][right - left] = 3;

				ip.setu(a);
				right++;
				delay(5);
			}
		}

		//left
		if (c == 'a')
		{
			if ((a[down - up][right - left - 1] == 0 || a[down - up][right - left - 1] == 3 || a[down - up][right - left - 1] == 5) && down - up < g.getrows() && right - left < g.getcolumns())
			{

				int cq = 2;
				a[down - up][right - left] = 3;

				a[down - up][right - left - 1] = cq;
				a[down - up][right - left] = 3;

				ip.setu(a);
				left++;
				delay(5);


			}
		}

		g1.setghost1(a);
		g1.movement1();

		g2.setpy(down - up);
		g2.setpx(right - left);

		g2.setghost2(a);
		ptr1->movement1();

		for (int i = 0; i < g.getrows(); i++)
		{
			for (int ai = 0; ai < g.getcolumns(); ai++)
			{
				if (a[i][ai] == 5) { power++; }
				if (a[i][ai] == 0) { win++; }
			}
		}


		if (power == 0 && flag == 0)
		{
			counter = 1000;
			flag++;

		}
		else if (counter != 0)
		{
			if (a[down - up][right - left] == 2 && (a[down - up + 1][right - left] == 8 || a[down - up - 1][right - left] == 8 || a[down - up][right - left - 1] == 8 || a[down - up][right - left + 1] == 8))
			{
				stop1 = 1000;
				g1.setghost1(a);
				g1.e1();
				stop1--;
				
			}
			if (a[down - up][right - left] == 2 && (a[down - up + 1][right - left] == 7 || a[down - up - 1][right - left] == 7 || a[down - up][right - left - 1] == 7 || a[down - up][right - left + 1] == 7))
			{
				stop2 = 1000;	
				g2.setghost2(a);
				ptr1->e1();
				stop2--;
			}
			flag++;
			counter--;
			s1--;
			s2--;
		}
		else if (a[down - up][right - left] == 2 && (a[down - up + 1][right - left] == 7 || a[down - up + 1][right - left] == 8 || a[down - up - 1][right - left] == 7 || a[down - up - 1][right - left] == 8 || a[down - up][right - left - 1] == 7 || a[down - up][right - left - 1] == 8 || a[down - up][right - left + 1] == 7 || a[down - up][right - left + 1] == 8))
		{

			colli.setco(a);
			colli.get_killed();
			up = 0;
			down = 1;
			left = 0;
			right = 2;
			ll.left();
		}

			s1 = 0;
			s2 = 0;

		winwin = win;
		if (win == 0 && ll.getlife() != 0)
		{
			
			break;
		}

		//score
		sc.sets(a);
		printf("Score: "); cout << sc.scoring(); cout << setw(10) << "Life: " << ll.getlife(); cout << setw(30) << "Super cherry timer: " << counter; printf("\r ");
	}



	cls();
	if (winwin == 0 && ll.getlife() != 0)
	{
		cout << endl;
		cout << "111   111 11111111 11   11    11         11          11  11111111  1111     11        " << endl;
		cout << " 111 111  11    11 11   11     11       11 11       11   11    11  11 11    11        " << endl;
		cout << "   111    11    11 11   11      11     11   11     11    11    11  11  11   11        " << endl;
		cout << "   111    11    11 11   11       11   11     11   11     11    11  11   11  11        " << endl;
		cout << "   111    11    11 11   11        11 11       11 11      11    11  11    11 11        " << endl;
		cout << " 11111111 11111111 1111111         11          11        11111111  11     1111        " << endl;
	}
	if (ll.getlife() == 0)
	{
		cout << endl;
		cout << "111   111 11111111 11   11   11      11111111 1111111 111111     " << endl;
		cout << " 111 111  11    11 11   11   11      11    11 11      11         " << endl;
		cout << "   111    11    11 11   11   11      11    11 11      11         " << endl;
		cout << "   111    11    11 11   11   11      11    11 1111111 111111     " << endl;
		cout << "   111    11    11 11   11   11      11    11      11 11         " << endl;
		cout << " 11111111 11111111 1111111   1111111 11111111 1111111 111111     " << endl;

	}

	cout << endl<<setw(10) << "Your Score: " << sc.scoring() << setw(20)<<"Max Score: 8,180 "<<endl;



	cout << endl;
	cout << "   1111111  11111111 111         111 111111    111111 11       11 111111 111111" << endl;
	cout << "   11   11  11    11 1111      11 11 11        11  11  11     11  11     11  11" << endl;
	cout << "   11       11    11 11 11    11  11 11        11  11   11   11   11     11  11" << endl;
	cout << "   11  111  11111111 11  11  11   11 111111    11  11    11 11    111111 111111" << endl;
	cout << "   11   11  11    11 11   1111    11 11        11  11     111     11     11 1  " << endl;
	cout << "   1111111  11    11 11     1     11 111111    111111      1      111111 11  11" << endl;
	//bool played1 = PlaySound(TEXT("pp.wav"), NULL, SND_SYNC);






	showConsoleCursor(false);

	gotoxy(0, 0);

	for (int i = 0; i < g.getrows(); i++)
	{
		delete[] a[i];
	}delete[]a;
	a = NULL;

	delete[]ptr;
	ptr = NULL;

	delete[]ptr1;
	ptr1 = NULL;
	

	return 0;
}








//class pacman :public grid
//{
//	int** p_maze;
//	char c;
//public:
//	pacman();
//	void setp_maze(int** o);
//	int** getp_maze();
//	void pmovement();
//	void setc(char s) { c = s; }
//	char getc() { return c; }
//
//	~pacman();
//};
//
//void pacman::pmovement()
//{
//
//}
//
//int** pacman::getp_maze()
//{
//	return p_maze;
//}
//
//void pacman::setp_maze(int** o)
//{
//	p_maze = o;
//}
//
//
//pacman::pacman()
//{
//	c = '.';
//	p_maze = getmaze();
//}
//
//pacman::~pacman()
//{
//	for (int i = 0; i < 28; i++)
//	{
//		delete[] p_maze[i];
//	}delete[]p_maze;
//	p_maze = NULL;
//}