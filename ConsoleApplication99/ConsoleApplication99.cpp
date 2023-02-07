#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>

using namespace std;

class Reservoir
{
private:

	int id;
	int code;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Dop_Info = nullptr;
	char* Tip = nullptr;
	long double area;
	long double volume;

public:

	Reservoir();

	Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info);

	Reservoir(const Reservoir& obj);

	void DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	long double SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	void AutoSearchArea(Reservoir* vodoem, const int countreservoir);

	void SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir);

	long double SearchVolume(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	bool CheckTip(Reservoir* vodoem, int const countreservoir, int _code1, int _code2, int* _idarray1, int* _idarray2);

	void Show_Tip();

	void Show_Reservoir();

	void Show_One_Reservoir();

	~Reservoir();

	//геттеры
	int Getid();
	int Getcode();
	char* GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char* GetDop_Info();
	char* GetTip();
	long double Getarea();
	long double Getvolume();

	//сеттеры
	void Setid(int _id);
	void Setcode(int _code);
	void SetReservoir_Name(char* _Reservoir_Name);
	void Setwidth(double _width);
	void Setlength(double _length);
	void Setdepth(double _depth);
	void SetDop_Info(char* _Dop_Info);
	void SetTip(char* _Tip);
	void Setarea(long double _area);
	void Setvolume(long double _volume);

};


void gotoxy(int, int);

void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();
void MenuFun5();
void MenuFun6();

void ExitOption();
//-----------------------------------------------------------------------------------------------

Reservoir::Reservoir()
{
	id = 0;
	code = 0;
	Reservoir_Name = new char[10] { "Без имени" };
	width = 0;
	length = 0;
	depth = 0;
	Tip = new char[2] { "-" };
	Dop_Info = new char[2] { "-" };
	area = 0;
	volume = 0;
}

Reservoir::Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info)
{
	id = _id;
	code = _code;
	width = _width;
	length = _length;
	depth = _depth;

	Reservoir_Name = new char[strlen(_name) + 1];
	Dop_Info = new char[strlen(_info) + 1];
	Tip = new char[strlen(_tip) + 1];

	strcpy(Reservoir_Name, _name);
	strcpy(Dop_Info, _info);
	strcpy(Tip, _tip);
}

Reservoir::Reservoir(const Reservoir& obj)
{
	id = obj.id;
	code = obj.code;

	Reservoir_Name = new char[strlen(obj.Reservoir_Name + 1)];
	strcpy(Reservoir_Name, obj.Reservoir_Name);

	width = obj.width;
	length = obj.length;
	depth = obj.depth;

	Dop_Info = new char[strlen(obj.Dop_Info + 1)];
	strcpy(Dop_Info, obj.Dop_Info);

	Tip = new char[strlen(obj.Tip + 1)];
	strcpy(Tip, obj.Tip);

	area = obj.area;
	volume = obj.volume;
}

void Reservoir::DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number)
{

	gotoxy(0, 6);
	cout << "YDaleHuE BoDoeMa" << endl;


	int numbertmp = *_number;

	int p_count = 0;

	int delnumber;

	int countdel = 0;

	cout << "BBeDuTe KaDaCTPoBblu HoMeP BoDoeMa Dlya YDaleHuya: ";
	cin >> delnumber;
	cin.ignore();

	for (size_t i = 0; i < *countreservoir; i++)
	{
		if (vodoem[i].code == delnumber)
		{
			(*countreservoir)--;
			countdel++;
		}
	}

	Reservoir* temp = new Reservoir[*countreservoir];

	for (size_t i = 0; i < *countreservoir; i++)
	{
		if (vodoem[p_count].code == delnumber)
		{
			p_count++;
			i--;
		}

		else if (vodoem[p_count].code != delnumber)
		{
			temp[i].id = vodoem[p_count].id;
			temp[i].code = vodoem[p_count].code;
			temp[i].width = vodoem[p_count].width;
			temp[i].length = vodoem[p_count].length;
			temp[i].depth = vodoem[p_count].depth;
			temp[i].area = vodoem[p_count].area;
			temp[i].volume = vodoem[p_count].volume;

			temp[i].Reservoir_Name = new char[strlen(vodoem[p_count].Reservoir_Name) + 1];
			temp[i].Tip = new char[strlen(vodoem[p_count].Tip) + 1];
			temp[i].Dop_Info = new char[strlen(vodoem[p_count].Dop_Info) + 1];

			strcpy(temp[i].Reservoir_Name, vodoem[p_count].Reservoir_Name);
			strcpy(temp[i].Tip, vodoem[p_count].Tip);
			strcpy(temp[i].Dop_Info, vodoem[p_count].Dop_Info);

			p_count++;
		}
	}

	if (countdel)
	{
		cout << "U3MeHeHuya BHeCeHbl" << endl;
	}

	delete[]vodoem;
	vodoem = temp;

	if (!countdel)
	{
		cout << "KaDaCTPoBblu HoMeP HE HauDeH" << endl;
		cout << "HajMu lyubYyu KHoTlKY Dlya Bo3BPaTa K MeHyu";
	}
}

void Reservoir::AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number)
{
	gotoxy(0, 6);
	cout << "DobaBLeHuE BoDoEMa" << endl;

	Reservoir* temp = new Reservoir[*countreservoir + 1];
	char _name, _tip, _info;
	int numbertmp = *_number;

	for (size_t i = 0; i < *countreservoir; i++)
	{
		temp[i].id = vodoem[i].id;
		temp[i].code = vodoem[i].code;
		temp[i].width = vodoem[i].width;
		temp[i].length = vodoem[i].length;
		temp[i].depth = vodoem[i].depth;
		temp[i].area = vodoem[i].area;
		temp[i].volume = vodoem[i].volume;

		temp[i].Reservoir_Name = new char[strlen(vodoem[i].Reservoir_Name) + 1];
		temp[i].Tip = new char[strlen(vodoem[i].Tip) + 1];
		temp[i].Dop_Info = new char[strlen(vodoem[i].Dop_Info) + 1];

		strcpy(temp[i].Reservoir_Name, vodoem[i].Reservoir_Name);
		strcpy(temp[i].Tip, vodoem[i].Tip);
		strcpy(temp[i].Dop_Info, vodoem[i].Dop_Info);
	}

	temp[*countreservoir].id = numbertmp;

	cout << "BBeDuTe KaDaCTPoBblu KoD BoDoeMa: ";
	cin >> temp[*countreservoir].code;
	cin.ignore();

	cout << "BBeDuTe HauMeHoBaHuE BoDoeMa: ";
	char buff[250];
	cin.getline(buff, 250);
	_name = strlen(buff);
	temp[*countreservoir].Reservoir_Name = new char[_name + 1];
	strcpy(temp[*countreservoir].Reservoir_Name, buff);

	cout << "BBeDuTe shuPuHY(km) BoDoeMa: ";
	cin >> temp[*countreservoir].width;
	cin.ignore();

	cout << "BBeDuTe DluHY(km) BoDoeMa: ";
	cin >> temp[*countreservoir].length;
	cin.ignore();

	cout << "BBeDuTe gLYbuHY(m) BoDoeMa: ";
	cin >> temp[*countreservoir].depth;
	cin.ignore();

	cout << "BBeDuTe TuTl BoDoeMa: ";
	cin.getline(buff, 250);
	_tip = strlen(buff);
	temp[*countreservoir].Tip = new char[_tip + 1];
	strcpy(temp[*countreservoir].Tip, buff);

	cout << "BBeDuTe DoTloLHuTeLbHYyu uHfoPMacblyu: ";
	cin.getline(buff, 250);
	_info = strlen(buff);
	temp[*countreservoir].Dop_Info = new char[_info + 1];
	strcpy(temp[*countreservoir].Dop_Info, buff);
	cout << endl;

	(*countreservoir)++;
	(*_number)++;

	delete[]vodoem;

	vodoem = temp;

	cout << "u3MeHeHuya BHeCeHbl\n";
	cout << "HajMu LyubYyu KHoTlKY DLya Bo3BPaTa K MeHyu";
}

long double Reservoir::SearchVolume(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check)
{
	int searchidarray = 0;
	int count = 0;
	long double volume = 0;

	for (size_t i = 0; i < countreservoir; i++)
	{
		if (vodoem[i].code == _code)
		{
			searchidarray = count;
			*_idarray = count;
			(*check)++;
		}
		count++;
	}
	cout << endl;

	if (check++)
	{
		volume = vodoem[searchidarray].Getwidth() * vodoem[searchidarray].Getlength() * (vodoem[searchidarray].Getdepth() / 1000);
		vodoem[searchidarray].Setvolume(volume);
	}

	return volume;
}

long double Reservoir::SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check)
{
	int searchidarray = 0;
	int count = 0;
	long double area = 0;

	for (size_t i = 0; i < countreservoir; i++)
	{
		if (vodoem[i].code == _code)
		{
			searchidarray = count;
			*_idarray = count;
			(*check)++;
		}
		count++;
	}
	cout << endl;

	if (check++)
	{
		area = vodoem[searchidarray].Getwidth() * vodoem[searchidarray].Getlength();
		vodoem[searchidarray].Setarea(area);
	}

	return area;
}

void Reservoir::AutoSearchArea(Reservoir* vodoem, const int countreservoir)
{
	long double area = 0;
	for (size_t i = 0; i < countreservoir; i++)
	{
		area = vodoem[i].Getwidth() * vodoem[i].Getlength();
		vodoem[i].Setarea(area);
	}
}

void Reservoir::SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir)
{
	int countsearch = 0;

	for (size_t i = 0; i < countreservoir; i++)
	{
		char* temp = strstr(vodoem[i].Tip, charsearch);

		if (temp)
		{
			countsearch++;

			if (countsearch == 1)
			{
				gotoxy(0, 13);
				cout << "+-------+---------------------------+-----------------+-------------+\n";
				gotoxy(0, 14);
				cout << "|KoD    | HauMeHoBaHuE              | TuTl             | TlLoshaDb, km |\n";
				gotoxy(0, 15);
				cout << "+-------+---------------------------+-----------------+-------------+\n";
			}

			cout << left << "| " << setw(5) << vodoem[i].code << " | " << setw(26);
			vodoem[i].Show_One_Reservoir();

			cout << left << "| " << setw(15) << vodoem[i].Tip << " | " << setw(11) << vodoem[i].area << " | " << endl;
		}

	}

	cout << "+-------+---------------------------+-----------------+-------------+\n";

	if (countsearch < 1)
	{
		cout << "BoDoEMoB Tlo 3aTlPoCY HE HauDeHo" << endl;
		cout << "HajMu LyubYyu KHoTlKY DLya Bo3BPaTa K MeHyu.";
	}

}

bool Reservoir::CheckTip(Reservoir* vodoem, int const countreservoir, int _code1, int _code2, int* _idarray1, int* _idarray2)
{


	for (size_t i = 0; i < countreservoir; i++)
	{
		if (vodoem[i].code == _code1)
			*_idarray1 = i;

		if (vodoem[i].code == _code2)
			*_idarray2 = i;
	}

	if (!strcmp(vodoem[*_idarray1].Tip, vodoem[*_idarray2].Tip))
		return true;

	else
		return false;
}

void Reservoir::Show_Tip()
{
	cout << Tip;
}

void Reservoir::Show_Reservoir()
{
	cout << left << "| " << setw(5) << code << " | " << setw(26) << Reservoir_Name << " | " << setw(10) << width << " | " << setw(9) << length << " | " << setw(10) << depth << " | " << setw(15) << Tip << " | " << setw(47) << Dop_Info << " | " << endl;

}

void Reservoir::Show_One_Reservoir()
{
	cout << Reservoir_Name;
}

Reservoir::~Reservoir()
{
	delete[]Reservoir_Name;
	delete[]Dop_Info;
	delete[]Tip;
}

int Reservoir::Getid()
{
	return id;
}

int Reservoir::Getcode()
{
	return code;
}

char* Reservoir::GetReservoir_Name()
{
	return Reservoir_Name;
}

double Reservoir::Getwidth()
{
	return width;
}

double Reservoir::Getlength()
{
	return length;
}

double Reservoir::Getdepth()
{
	return depth;
}

char* Reservoir::GetDop_Info()
{
	return Dop_Info;
}

char* Reservoir::GetTip()
{
	return Tip;
}

long double Reservoir::Getarea()
{
	return area;
}

long double Reservoir::Getvolume()
{
	return volume;
}

void Reservoir::Setid(int _id)
{
	id = _id;
}

void Reservoir::Setcode(int _code)
{
	code = _code;
}

void Reservoir::SetReservoir_Name(char* _Reservoir_Name)
{
	if (Reservoir_Name)
	{
		delete[] Reservoir_Name;
	}

	Reservoir_Name = new char[strlen(_Reservoir_Name) + 1];
	strcpy(Reservoir_Name, _Reservoir_Name);
}

void Reservoir::Setwidth(double _width)
{
	width = _width;
}

void Reservoir::Setlength(double _length)
{
	length = _length;
}

void Reservoir::Setdepth(double _depth)
{
	depth = _depth;
}

void Reservoir::SetDop_Info(char* _Dop_Info)
{
	if (Dop_Info)
	{
		delete[] Dop_Info;
	}

	Dop_Info = new char[strlen(_Dop_Info) + 1];
	strcpy(Dop_Info, _Dop_Info);
}

void Reservoir::SetTip(char* _Tip)
{
	if (Tip)
	{
		delete[] Tip;
	}

	Tip = new char[strlen(_Tip) + 1];
	strcpy(Tip, _Tip);
}

void Reservoir::Setarea(long double _area)
{
	area = _area;
}

void Reservoir::Setvolume(long double _volume)
{
	volume = _volume;
}



//счетчки количества водоемов в массиве
int countreservoir = 4;

//счетчки количества стран
int countrountry = 1;

//ID водоема в массиве. Служебное свойство
int number = 1;

//Первоначальное заполнение абонентской книги
Reservoir* vodoem = new Reservoir[countreservoir]
{
	{number++, 2201, "Blue Lake", 0.72, 0.45, 50, "Lake", "Nikolaevkskaya area"},
	{number++, 3301, "Dnieper reservoir", 3.5, 170, 8, "reservoir","Dnipropetrovsk region"},
	{number++, 4421, "Sea of ​​Azov", 20, 180, 7.4, "Sea", "Kherson, Zaporozhye and Donetsk regions"},
	{number++, 4478, "Black Sea", 100, 310, 25, "Sea", "Kherson, Nikolaev and Odessa regions"}
};

//-----------------------------------------------------------------------------------------------
string* MenuItems()
{
	string* item = new string[7];
	item[0] = "1. CTluCoK BoDoeMoB";
	item[1] = "2. DobaBleHue BoDoeMa | YDaLeHue BoDoeMa";
	item[2] = "3. PaCcheT ObbeMA BoDoeMa";
	item[3] = "4. OTlPeDeleHue TlLoshaDu";
	item[4] = "5. TlPoBePKa TuTla";
	item[5] = "6. CPaBHeHue TlLoshADu";
	item[6] = "7. BblXoD";

	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{

	gotoxy(1, 6);
	cout << "Список Водоемов\n\n";

	gotoxy(1, 7);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
	gotoxy(1, 8);
	cout << "|KoD    | HauMeHoBaHuE               | shuPuHa, km | DLuHa, km | gLYbuHa, m | TuTl             | DoTloLHuTeLHaya uHfoPMacuya                       |\n";
	gotoxy(1, 9);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";

	for (size_t i = 0; i < countreservoir; i++)
	{
		gotoxy(1, 10 + i);
		vodoem[i].Show_Reservoir();

	}
	cout << " +-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";

	_getch();
}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{

	int choose;
	cout << "1. DobaBuTb BoDoeM" << endl;
	cout << "2. YDaLuTb BoDoeM" << endl;
	cout << "3. BblXoD" << endl;
	cout << "BBeDuTe HoMeP: ";
	cin >> choose;
	cout << endl << endl;
	if (choose == 1)
		vodoem->AddReservoir(vodoem, &countreservoir, &number);

	if (choose == 2)
		vodoem->DeleteReservoir(vodoem, &countreservoir, &number);

	if (choose > 2)
		cout << "BblXoD" << endl;

	_getch();
}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "BBeDuTe KaDaCTPoBblu HoMeP BoDoeMa: ";
	cin >> _code;
	vodoem->SearchVolume(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "ObbeM ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getvolume() << " км3";
	}

	else
		cout << "OshubKa";

	_getch();
}
//-----------------------------------------------------------------------------------------------
void MenuFun4()
{
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "BBeDuTe KaDaCTPoBblu HoMeP BoDoeMa: ";
	cin >> _code;
	vodoem->SearchArea(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "TlLoshaDb ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getarea() << " km";
	}

	else
		cout << "Huchego He HauDeHo";

	_getch();
}
//-----------------------------------------------------------------------------------------------
void MenuFun5()
{

	bool checktip = 0;
	int code1;
	int code2;
	int idarray1 = NULL;
	int idarray2 = NULL;
	int checkcode1 = 0;
	int checkcode2 = 0;

	gotoxy(0, 9);
	cout << "BBeDuTe KaDaCTPoBblu HoMeP 1 BoDoeMa: ";
	cin >> code1;
	cout << "BBeDuTe KaDaCTPoBblu HoMeP 2 BoDoeMa: ";
	cin >> code2;


	//делаем проверку на наличие водоемов в базе данных

	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code1)
		{
			checkcode1++;
		}
	}

	if (checkcode1)
	{
		cout << "1 BoDoeM He HauDeH\n";
	}

	else
	{
		cout << "1 BoDoeM He HauDeH\n";
	}

	for (size_t k = 0; k < countreservoir; k++)
	{
		if (vodoem[k].Getcode() == code2)
		{
			checkcode2++;
		}
	}

	if (checkcode2)
	{
		cout << "2 BoDoeM He HauDeH\n";
	}

	else
	{
		cout << "2 BoDoeM He HauDeH\n";
	}

	if (checkcode1 && checkcode2)
	{

		checktip = vodoem->CheckTip(vodoem, countreservoir, code1, code2, &idarray1, &idarray2);

		if (checktip)
		{
			cout << "BoDoeMbl ";
			vodoem[idarray1].Show_One_Reservoir();
			cout << " u ";
			vodoem[idarray2].Show_One_Reservoir();
			cout << " uMeyuT Obshuu TuTl - ";
			vodoem[idarray1].Show_Tip();
		}

		else
		{
			cout << "Pa3Hblu TuTl" << endl;
			vodoem[idarray1].Show_One_Reservoir();
			cout << " TuTl - ";
			vodoem[idarray1].Show_Tip();
			cout << endl;
			vodoem[idarray2].Show_One_Reservoir();
			cout << " TuTl - ";
			vodoem[idarray2].Show_Tip();
		}
	}

	else
	{
		cout << "OshubKa" << endl;
	}



	_getch();
}
//-----------------------------------------------------------------------------------------------
void MenuFun6()
{
	gotoxy(0, 9);
	cout << "CPaBHeHue TloshaDu" << endl;
	vodoem->AutoSearchArea(vodoem, countreservoir);
	cout << "3aBePsheHo" << endl;
	cin.ignore();
	char charsearch[30] = "";
	cout << "BBeDuTe TuTl BoDoeMa DLya CPaBHeHuYa: ";
	cin.getline(charsearch, 30);

	vodoem->SearchAreaTip(vodoem, charsearch, countreservoir);

	_getch();
}
//-----------------------------------------------------------------------------------------------
void ExitOption()
{
	gotoxy(35, 15);
	delete[]vodoem;
	cout << "BblXojY-}-{-P-}-{-}-?-{-}-{-}-{-?-?-?-?-?-/-/-?-?->->-<->->->->-.-.-.-.-." << endl;
	_getch();
	exit(0);
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}
//-----------------------------------------------------------------------------------------------

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string* MenuItems();

	ChangeCursorStatus(false);
	typedef void (*TMenuOption)();

	int ItemCount = 7;
	int MenuChoice = 1;
	char key;

	TMenuOption* MenuOption = new TMenuOption[ItemCount];
	MenuOption[0] = MenuFun1;
	MenuOption[1] = MenuFun2;
	MenuOption[2] = MenuFun3;
	MenuOption[3] = MenuFun4;
	MenuOption[4] = MenuFun5;
	MenuOption[5] = MenuFun6;
	MenuOption[6] = ExitOption;

	while (1)
	{
		for (int i = 0; i < ItemCount; i++)
		{
			gotoxy(25, 7 + i);
			MenuChoice == i + 1 ? cout << " -> " : cout << "    ";


			cout << MenuItems()[i] << endl;
		}

		key = _getch();

		switch (key)
		{
		case '\r':
			try
			{
				(*MenuOption[MenuChoice - 1])();

			}
			catch (...)
			{
			}


			break;

		case 'P':
			MenuChoice++;
			if (MenuChoice > ItemCount)
				MenuChoice = 1;
			break;

		case 'H':
			MenuChoice--;
			if (MenuChoice < 1)
				MenuChoice = ItemCount;
			break;

		case 27:
			try { (*MenuOption[ItemCount - 1])(); }


			catch (...) {}
			break;
		default:
			if (key >= '1' && key <= char(ItemCount + '0'))

			{
				try { (*MenuOption[int(key) - '0' - 1])(); }

				catch (...) {}
			}
		}
	}

	delete[] MenuOption;
	return 0;


}