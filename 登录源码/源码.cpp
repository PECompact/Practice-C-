#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;
#include<iostream>
using namespace std;
class Information
{
private:char* Users;//�û���
	   char* Password;//����
	   char* Password1;//�ڶ������������
	   char* users;//��¼ʱ������û���
	   char* password;//��¼ʱ���������
public:
	Information(char* Users = "1234567", char* Password = "zsum")
	{ //���캯��
		this->Users = Users, this->Password = Password;
	}

	~Information() {} //��������

	void deleteusers() {//�û����ظ�ʱɾ����ע��
		Users = "______";
		Password = "______";
	}

	int Login(char* users, char* password) {//��¼
		int b = 1;//���Ƶ�¼�ĳɹ���ʧ��
		for (int o = 0, p = 0; o < strlen(Users) && o < strlen(users) && p < strlen(Password) && p < strlen(password); o++, p++) {
			if ((*(Users + o) == *(users + o)) && (*(Password + p) == *(password + p)))   b = 0;//�ɹ�Ϊ�㣬ʧ��Ϊһ
			else { b = 1; break; }
		}
		return b;
	}

	int setinformation() {//ע��
		int judge1 = 0;
		cout << "�����������û�����";
		Users = (char*)malloc(20 * sizeof(char));
		cin >> Users;
		cout << "�������������룺";
		Password = (char*)malloc(20 * sizeof(char));
		cin >> Password;
		cout << "���ٴ����������õ����룺";
		Password1 = (char*)malloc(20 * sizeof(char));
		cin >> Password1;//�û�����������
		if (strlen(Password) == strlen(Password1))
		{
			int p;
			for (p = 0; p < strlen(Password); p++)
			{
				if (*(Password + p) == *(Password1 + p))  judge1 = judge1 + 1; //�ж���������������Ƿ����
			}
			if (judge1 == p) return 1;
			else return 0;
		}
		else return 0;
	}

	char* getUsers() { return Users; }//�����û������ж�ע����û����Ƿ��ظ�
};

int main() {
	system("color 02");
	Information inf[100];//�û���Ϣ������
	int a = 0;//�û��ĸ���
	int c, e;//����ѡ��
	char* u;//��¼ʱ�û�������
	char* p;//��¼ʱ��������
	int a1, b1;//�����ж�����
	for (int x = 0; x < 100; x++) {
		cout << "��ӭ���빫˾��Ա����ϵͳ�������·������û���֤��" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "1.�û�ע�᣻2.�û���¼:";//����ѡ��
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
				int con = inf[i].setinformation();//�û�ע��
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
							cout << "�û���ע�ᣬ����������" << endl; i--;
							a1 = 1;
							inf[a].deleteusers();
							a--;
							break;
						}
					}
				}
				if (con == 0 && a1 == 0)
				{
					cout << "�����������벻��ͬ������������" << endl;
					i--;
					inf[a].deleteusers();
					a--;
				}
				else if (con == 1 && a1 == 0)  cout << "����ϲע��ɹ���" << endl;
				a = a + 1;//������һ
				cout << "'1'������'2'����" << endl;//�Ƿ����ע��
				cin >> e;
				if (e == 2) { break; }
				else if (e == 1)
				{
					continue;
				}
				else if (e != 1 && e != 2)
				{
					cout << "������Ч" << endl;
					break;
				}
			}
			break;
		}
		case 2: {
			cout << "�������û����� ";
			u = (char*)malloc(20 * sizeof(char));
			cin >> u;
			cout << "���������룺  ";
			p = (char*)malloc(20 * sizeof(char));
			cin >> p;
			for (int z = 0; z <= a; z++)
			{
				b1 = inf[z].Login(u, p);
				if (b1 == 0)
				{
					cout << "��#############��  ��ϲ��¼�ɹ�  !#############��" << endl ;
					cout<<endl;
					cout<<endl;
				}//��¼�ɹ�
			}
			if (b1 == 1) cout << "QwQ   �����˵�¼ʧ��    QwQ" << endl;//��¼ʧ��
			
		}
		default: cout << "��ʽ�������~" << endl;
		}
	}
	return 0;
}

