#include<iostream>
using namespace std;
#include<string>
#define  MAX    1000
//联系人结构体
struct person 
{
	//姓名
	string m_name;
	//性别
	int m_sex=0;
	//年龄
	int m_age=0;
	//电话
	string m_phone;
	//家庭住址
	string m_addr;
};

//通讯录结构体
struct addressbooks
{
	//通讯录中保持的联系人数组
	struct person personarray[MAX];

	//通讯录中当前记录联系人个数
	int m_size=0;
};

//添加联系人
void addperson(addressbooks* ads)
{
	//判断通讯录是否已满
	if (ads->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	
	}
	else
	{
		//添加具体联系人
	
		//姓名
		string name;
		cout << "请输入姓名:  " << endl;
		cin >> name;
		ads->personarray[ads->m_size].m_name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				ads->personarray[ads->m_size].m_sex=sex;
				break;
			}
			cout << "输入错误，请重新输入"<<endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄:  " << endl;
		cin >> age;
		//差检查年龄的步骤
		ads->personarray[ads->m_size].m_age = age;
		//电话
		string phone = "无";
		cout << "请输入电话"<<endl;
		cin >> phone;
		ads->personarray[ads->m_size].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址" << endl;
		string address = "无";
		cin >> address;
		ads->personarray[ads->m_size].m_addr = address;
		//更新通讯录人数
		ads->m_size++;
		cout << "添加成功" << endl;
	}
	
	system("pause");
	system("cls");

}

//显示联系人
void showperson(addressbooks* ads)
{
	//判断通讯录中人数是否为0
	if (ads->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "姓名：  " << ads->personarray[i].m_name << "\t";
			cout << "性别：  " << (ads->personarray[i].m_sex == 1 ?"男":"女") << "\t";
			cout << "年龄：  " << ads->personarray[i].m_age << "\t";
			cout << "电话：  " << ads->personarray[i].m_phone << "\t";
			cout << "地址：  " << ads->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}


//检测联系人是否存在
int isexist(addressbooks *ads, string name)
{
	for (int i = 0; i < ads->m_size;i++)
	{
		if (name == ads->personarray[i].m_name)
		{
			return i;//找到，返回这个人在数组中的下标编号
		}
	}
	return -1;//遍历结束都没有找到，返回-1
}


//删除指定联系人
void deleteperson(addressbooks* ads)
{
	cout << "请输入您要删除的联系人" << endl;
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findperson(addressbooks* ads)
{
	cout << "请输入您要找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否在通讯录中
	int ret = isexist(ads, name);
	if (ret != -1)
	{
		cout << "姓名  " << ads->personarray[ret].m_name << "\t";
		cout << "性别  " << (ads->personarray[ret].m_sex==1 ? "男":"女") << "\t";
		cout << "年龄  " << ads->personarray[ret].m_age << "\t";
		cout << "电话  " << ads->personarray[ret].m_phone << "\t";
		cout << "地址  " << ads->personarray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人
void changeperson(addressbooks* ads)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(ads, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		ads->personarray[ret].m_name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				ads->personarray[ads->m_size].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		ads->personarray[ret].m_age;
		//电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		ads->personarray[ret].m_phone=phone;
		//地址
		string address;
		cout << "请输入家庭住址" << endl;
		cin >> address;
		ads->personarray[ret].m_addr;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanperson(addressbooks * ads)
{
	cout << "是否真的需要清空" << endl;
	cout << "1---是" << endl;
	cout << "2---否" << endl;
	int i = 0;
	cin >> i;
	while (true)
	{
		if (i == 1)
		{
			ads->m_size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if (i == 2)
		{
			cout << "取消清空成功" << endl;
			break;
		}
		else cout << "输入错误，请重新输入"<<endl;
	}
	system("pause");
	system("cls");
}

//菜单
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "*************************" << endl;
}



int main()
{
	
	//创建通讯录结构体变量
	addressbooks ads;
	//初始化通讯录中当前人员个数
	ads.m_size = 0;

	int select = 0;
	while(true) {
		//菜单的调用
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addperson(&ads);
			break;
		case 2://显示联系人
			showperson(&ads);
			break;
		case 3://删除联系人
			deleteperson(&ads);
			break;
		case 4://查找联系人
			findperson(&ads);
			break;
		case 5://修改联系人
			changeperson(&ads);
			break;
		case 6://清空联系人
			cleanperson(&ads);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用！" << endl;
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