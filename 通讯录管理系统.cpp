#include<iostream>
using namespace std;
#include<string>
#define  MAX    1000
//��ϵ�˽ṹ��
struct person 
{
	//����
	string m_name;
	//�Ա�
	int m_sex=0;
	//����
	int m_age=0;
	//�绰
	string m_phone;
	//��ͥסַ
	string m_addr;
};

//ͨѶ¼�ṹ��
struct addressbooks
{
	//ͨѶ¼�б��ֵ���ϵ������
	struct person personarray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size=0;
};

//�����ϵ��
void addperson(addressbooks* ads)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (ads->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	
	}
	else
	{
		//��Ӿ�����ϵ��
	
		//����
		string name;
		cout << "����������:  " << endl;
		cin >> name;
		ads->personarray[ads->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				ads->personarray[ads->m_size].m_sex=sex;
				break;
			}
			cout << "�����������������"<<endl;
		}
		//����
		int age = 0;
		cout << "����������:  " << endl;
		cin >> age;
		//��������Ĳ���
		ads->personarray[ads->m_size].m_age = age;
		//�绰
		string phone = "��";
		cout << "������绰"<<endl;
		cin >> phone;
		ads->personarray[ads->m_size].m_phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address = "��";
		cin >> address;
		ads->personarray[ads->m_size].m_addr = address;
		//����ͨѶ¼����
		ads->m_size++;
		cout << "��ӳɹ�" << endl;
	}
	
	system("pause");
	system("cls");

}

//��ʾ��ϵ��
void showperson(addressbooks* ads)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (ads->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "������  " << ads->personarray[i].m_name << "\t";
			cout << "�Ա�  " << (ads->personarray[i].m_sex == 1 ?"��":"Ů") << "\t";
			cout << "���䣺  " << ads->personarray[i].m_age << "\t";
			cout << "�绰��  " << ads->personarray[i].m_phone << "\t";
			cout << "��ַ��  " << ads->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}


//�����ϵ���Ƿ����
int isexist(addressbooks *ads, string name)
{
	for (int i = 0; i < ads->m_size;i++)
	{
		if (name == ads->personarray[i].m_name)
		{
			return i;//�ҵ�������������������е��±���
		}
	}
	return -1;//����������û���ҵ�������-1
}


//ɾ��ָ����ϵ��
void deleteperson(addressbooks* ads)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(ads, name);
	if (ret !=-1)
	{
		for (int j = ret; j < ads->m_size; j++)
		{
			ads->personarray[j] = ads->personarray[j + 1];
		}
		ads->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findperson(addressbooks* ads)
{
	cout << "��������Ҫ�ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ���ͨѶ¼��
	int ret = isexist(ads, name);
	if (ret != -1)
	{
		cout << "����  " << ads->personarray[ret].m_name << "\t";
		cout << "�Ա�  " << (ads->personarray[ret].m_sex==1 ? "��":"Ů") << "\t";
		cout << "����  " << ads->personarray[ret].m_age << "\t";
		cout << "�绰  " << ads->personarray[ret].m_phone << "\t";
		cout << "��ַ  " << ads->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//�޸���ϵ��
void changeperson(addressbooks* ads)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(ads, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		ads->personarray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				ads->personarray[ads->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		ads->personarray[ret].m_age;
		//�绰
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		ads->personarray[ret].m_phone=phone;
		//��ַ
		string address;
		cout << "�������ͥסַ" << endl;
		cin >> address;
		ads->personarray[ret].m_addr;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanperson(addressbooks * ads)
{
	cout << "�Ƿ������Ҫ���" << endl;
	cout << "1---��" << endl;
	cout << "2---��" << endl;
	int i = 0;
	cin >> i;
	while (true)
	{
		if (i == 1)
		{
			ads->m_size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else if (i == 2)
		{
			cout << "ȡ����ճɹ�" << endl;
			break;
		}
		else cout << "�����������������"<<endl;
	}
	system("pause");
	system("cls");
}

//�˵�
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "*************************" << endl;
}



int main()
{
	
	//����ͨѶ¼�ṹ�����
	addressbooks ads;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	ads.m_size = 0;

	int select = 0;
	while(true) {
		//�˵��ĵ���
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&ads);
			break;
		case 2://��ʾ��ϵ��
			showperson(&ads);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&ads);
			break;
		case 4://������ϵ��
			findperson(&ads);
			break;
		case 5://�޸���ϵ��
			changeperson(&ads);
			break;
		case 6://�����ϵ��
			cleanperson(&ads);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}