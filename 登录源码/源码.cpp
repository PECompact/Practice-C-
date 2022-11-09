#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;
#include<iostream>
using namespace std;
class Information
{
private:char* Users;//用户名
	   char* Password;//密码
	   char* Password1;//第二次输入的密码
	   char* users;//登录时输入的用户名
	   char* password;//登录时输入的密码
public:
	Information(char* Users = "1234567", char* Password = "zsum")
	{ //构造函数
		this->Users = Users, this->Password = Password;
	}

	~Information() {} //析构函数

	void deleteusers() {//用户名重复时删除该注册
		Users = "______";
		Password = "______";
	}

	int Login(char* users, char* password) {//登录
		int b = 1;//控制登录的成功或失败
		for (int o = 0, p = 0; o < strlen(Users) && o < strlen(users) && p < strlen(Password) && p < strlen(password); o++, p++) {
			if ((*(Users + o) == *(users + o)) && (*(Password + p) == *(password + p)))   b = 0;//成功为零，失败为一
			else { b = 1; break; }
		}
		return b;
	}

	int setinformation() {//注册
		int judge1 = 0;
		cout << "请设置您的用户名：";
		Users = (char*)malloc(20 * sizeof(char));
		cin >> Users;
		cout << "请设置您的密码：";
		Password = (char*)malloc(20 * sizeof(char));
		cin >> Password;
		cout << "请再次输入您设置的密码：";
		Password1 = (char*)malloc(20 * sizeof(char));
		cin >> Password1;//用户名密码输入
		if (strlen(Password) == strlen(Password1))
		{
			int p;
			for (p = 0; p < strlen(Password); p++)
			{
				if (*(Password + p) == *(Password1 + p))  judge1 = judge1 + 1; //判断两次输入的密码是否相等
			}
			if (judge1 == p) return 1;
			else return 0;
		}
		else return 0;
	}

	char* getUsers() { return Users; }//返回用户名以判断注册的用户名是否重复
};

int main() {
	system("color 02");
	Information inf[100];//用户信息的数组
	int a = 0;//用户的个数
	int c, e;//功能选择
	char* u;//登录时用户名输入
	char* p;//登录时密码输入
	int a1, b1;//控制判断条件
	for (int x = 0; x < 100; x++) {
		cout << "欢迎进入公司人员管理系统，请在下方进行用户认证。" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "1.用户注册；2.用户登录:";//功能选择
		cout << endl;
		cout << endl;
		cout << endl;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			for (int i = 0; i <= 100; i++)
			{
				int con = inf[i].setinformation();//用户注册
				a1 = 0;
				for (int j = 0; j < a; j++)
				{
					char* f = inf[j].getUsers();
					char* h = inf[a].getUsers();
					if (strlen(f) == strlen(h))
					{
						int judge2 = 0;
						int o;
						for (o = 0; o < strlen(f); o++)
						{
							if (*(f + o) == *(h + o))   judge2 = judge2 + 1;
						}
						if (judge2 == o)
						{
							cout << "用户名注册，请重新输入" << endl; i--;
							a1 = 1;
							inf[a].deleteusers();
							a--;
							break;
						}
					}
				}
				if (con == 0 && a1 == 0)
				{
					cout << "两次输入密码不相同，请重新输入" << endl;
					i--;
					inf[a].deleteusers();
					a--;
				}
				else if (con == 1 && a1 == 0)  cout << "，恭喜注册成功！" << endl;
				a = a + 1;//个数加一
				cout << "'1'继续，'2'返回" << endl;//是否继续注册
				cin >> e;
				if (e == 2) { break; }
				else if (e == 1)
				{
					continue;
				}
				else if (e != 1 && e != 2)
				{
					cout << "输入无效" << endl;
					break;
				}
			}
			break;
		}
		case 2: {
			cout << "请输入用户名： ";
			u = (char*)malloc(20 * sizeof(char));
			cin >> u;
			cout << "请输入密码：  ";
			p = (char*)malloc(20 * sizeof(char));
			cin >> p;
			for (int z = 0; z <= a; z++)
			{
				b1 = inf[z].Login(u, p);
				if (b1 == 0)
				{
					cout << "！#############！  恭喜登录成功  !#############！" << endl ;
					cout<<endl;
					cout<<endl;
				}//登录成功
			}
			if (b1 == 1) cout << "QwQ   出错了登录失败    QwQ" << endl;//登录失败
			
		}
		default: cout << "格式错误，起飞~" << endl;
		}
	}
	return 0;
}

