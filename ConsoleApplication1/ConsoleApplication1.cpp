#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Brick
{
public:
	Brick(void)
	{
		width = height = 0;
	}

	Brick(int width_brick, int height_brick)
	{
		width = width_brick;
		height = height_brick;
	}

	// конструктор копіювання класу Brick
	// передається посилання на Brick
	Brick (const Brick &ref_Point)
	{
		// копіювання даних з одного об'єкту в інший
		width = ref_Point.width;
		height = ref_Point.height;
	}

	// перевантажений оператор '='
	Brick operator=(Brick cm)
	{
		// доступ за посиланням на клас
		width = cm.width;
		height = cm.height;
		return *this; // повертає об'єкт, що згенерував виклик
	}

	// перевантажений бінарний оператор '+'
	Brick operator+(Brick pt)
	{
		// p - тимчасовий об'єкт, який створюється з допомогою конструктора без параметрів
		Brick p;
		p.width = width + pt.width;
		p.height = height + pt.height;
		return p;
	}

	// перевантажений унарний оператор '-'
	Brick operator-(void)
	{
		Brick p;
		p.width = -width;
		p.height = -height;
		return p;
	}
	
	// методи доступу до членів класу
	void Set_Width(int width_brick)
	{
		width = width_brick;
	}
	void Set_Height(int height_brick)
	{
		height = height_brick;
	}
	int Get_Width() { return width; }
	int Get_Height() { return height; }

private:
	int width;
	int height;
};

class Wall_Brick
{
public:
	Wall_Brick(void)
	{
		width = height = 0;
	}

	Wall_Brick(int width_brick, int height_brick)
	{
		width = width_brick;
		height = height_brick;
	}

	// конструктор копіювання класу Brick
	// передається посилання на Brick
	Wall_Brick(const Wall_Brick& ref_Point)
	{
		// копіювання даних з одного об'єкту в інший
		width = ref_Point.width;
		height = ref_Point.height;
	}

	// перевантажений оператор '='
	Wall_Brick operator=(Wall_Brick cm)
	{
		// доступ за посиланням на клас
		width = cm.width;
		height = cm.height;
		return *this; // повертає об'єкт, що згенерував виклик
	}

	// перевантажений бінарний оператор '+'
	Wall_Brick operator+(Wall_Brick pt)
	{
		// p - тимчасовий об'єкт, який створюється з допомогою конструктора без параметрів
		Wall_Brick p;
		p.width = width + pt.width;
		p.height = height + pt.height;
		return p;
	}

	// перевантажений унарний оператор '-'
	Wall_Brick operator-(void)
	{
		Wall_Brick p;
		p.width = -width;
		p.height = -height;
		return p;
	}

	// методи доступу до членів класу
	void Set_Width(int width_brick)
	{
		width = width_brick;
	}
	void Set_Height(int height_brick)
	{
		height = height_brick;
	}
	int Get_Width() { return width; }
	int Get_Height() { return height; }

private:
	int width;
	int height;
};


int main() {

	string path = "File.txt";
	int width_Wall=0;
	int height_Wall=0;
	int countBricksSort = 0;
	int width_Brick = 0;
	int height_Brick = 0;
	int countBricksList = 0;
	string str;
	int steps = 1;
	ifstream f_in;
	ofstream f_out;
	int sWall = 0;
	int sBricks = 0;
	int press = 0;
	vector <Brick> v_bricks;
	vector <Wall_Brick> v_wall_brick;

	//Manual input
	cout << "Do you want give me data from the file then press 0 or manual then 1." << endl;
	cin >> press;
	if (press==1)
	{
		f_out.open(path, ofstream::out | ofstream::trunc);
		f_out.close();
		f_out.open(path, ofstream::app);
		if (!f_out.is_open())
		{
			cout << "Error";
		}
		else
		{
			string a;
			cin.ignore();
			getline(cin, a);
			f_out << a << endl;

			f_in.open(path);
			if (!f_in.is_open())
			{
				cout << "Error";
			}
			else
			{
				while (!f_in.eof())
				{
					str = "";
					f_in >> str;
					// fill height and width for wall
					if (steps == 1)
					{
						width_Wall = stoi(str);
					}
					else if (steps == 2) {
						height_Wall = stoi(str);
					}
					else
					{
						steps++;
						f_in.close();
					}
					steps++;
				}
			}

			for (int i = 0; i < height_Wall; ++i)
			{
				getline(cin, a);
				f_out << a << endl;
			}
			
			//cin.ignore();
			getline(cin, a);
			f_out << a << endl;

			// get count of bricks
			steps = 0;
			f_in.open(path);
			while (!f_in.eof())
			{
				str = "";
				f_in >> str;
				steps++;
				if (steps == height_Wall + 3)
				{
					countBricksSort = stoi(str);
				}
			}
			f_in.close();
			//////////////////////

			for (int i = 0; i < countBricksSort; ++i)
			{
				getline(cin, a);
				f_out << a << endl;
			}
		}
		f_out.close();
	}
	///////////////


	// get height and width for wall
	f_in.open(path);
	if (!f_in.is_open())
	{
		cout << "Error";
	}
	else
	{
		while (!f_in.eof())
		{
			str = "";
			f_in >> str;
			// fill height and width for wall
			if (steps == 1)
			{
				width_Wall = stoi(str);
				if (width_Wall <= 0)
				{
					cout << "Width of wall can't be less than one." << endl;
				}
			}
			else if(steps ==2){
				height_Wall = stoi(str);
				if (height_Wall <= 0)
				{
					cout << "Height of wall can't be less than one." << endl;
				}
			}
			else 
			{
				steps++;
				f_in.close();
			}
			steps++;			
		}
	}
	/////////////////////////////////

	
	// get Wall
	int** arr_Wall = new int* [height_Wall];
	for (int i = 0; i < height_Wall; i++)
	{
		arr_Wall[i] = new int[width_Wall];
	}
	steps = 0;
	int iArr = 0;
	f_in.open(path);
	while (!f_in.eof())
	{
		str = "";
		f_in >> str;
		steps++;
		if (steps>2 && steps<height_Wall+3)
		{
			for (int i = 0; i < width_Wall; i++)
			{
				arr_Wall[iArr][i] = str[i]-'0';
			}
			iArr++;
		}
	}
	f_in.close();
	//////////////


	// get count of bricks
	steps = 0;
	f_in.open(path);
	while (!f_in.eof())
	{
		str = "";
		f_in >> str;
		steps++;
		if (steps==height_Wall+3)
		{
			countBricksSort = stoi(str);
		}
	}
	f_in.close();
	//////////////////////


	// get bricks
	int a = 1;
	int b = 0;
	steps = 0;
	f_in.open(path);
	while (!f_in.eof())
	{
		str = "";
		f_in >> str;
		steps++;

		if (steps>3+height_Wall && steps< 4 + height_Wall+ countBricksSort*3)
		{
			if (a == 1)
			{
				width_Brick = stoi(str);
				a++;
				b++;
				if (width_Brick <= 0)
				{
					cout << "Width of brick can't be less than one." << endl;
				}
			}
			else if (a == 2)
			{
				height_Brick = stoi(str);
				a++;
				b++;
				if (height_Brick <= 0)
				{
					cout << "Height of brick can't be less than one." << endl;
				}
			}
			else if (a == 3)
			{
				countBricksList = stoi(str);
				a = 1;
				b++;
			}
			if (b%3==0)
			{
				sBricks = sBricks + width_Brick * height_Brick * countBricksList;
				for (int i = 0; i < countBricksList; i++)
				{
					Brick a(width_Brick, height_Brick);
					v_bricks.push_back(a);
				}
				
			}

		}
	}
	f_in.close();
	/////////////


	//check
	for (int i = 0; i < height_Wall; i++)
	{
		for (int j = 0; j < width_Wall; j++)
		{
			sWall+=arr_Wall[i][j];
		}
	}
	if (sWall>sBricks)
	{
		cout << "no" << endl;
	}
	else
	{

		cout << "yes" << endl;
	}
	///////




	//clear memory
	for (int i = 0; i < height_Wall; i++)
	{
		delete[]arr_Wall[i];
	}
	delete[]arr_Wall;
	f_in.close();
	
	
	system("pause");
	return 0;
}