#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*Вариант 13
Типы аргументов unsigned int и float.
1. Перестановка элементов массива в обратном порядке.
2. АТД Дек с ограниченным входом. Структура хранения – связанный список*/

template <class Tdata>
void back(Tdata mas[], int n)
{
	int i = n, j;
	Tdata p;
	for (j = 0; j < n; j++, n--)
	{
		p = mas[j];
		mas[j] = mas[n - 1];
		mas[n - 1] = p;
	}
}

template <class Data> class Dec_connect
{
private:
	list <Data> Dec;
public:
	Dec_connect()
	{
	}
	~Dec_connect()
	{
	}
	void del_dec()
	{
		Dec.clear();
	}
	
	void InRight(Data info)
	{
		if (!Dec.empty())
		{
			Dec.push_back(info);
			cout << "Добавлен элемент справа\n";
		}
		else
		{
			Dec.push_front(info);
			cout << "Добавлен первый элемент\n";
		}
	}
	Data OutLeft()
	{
		if (Dec.empty())
		{
			cout << "Дек пуст, возвращен 0\n";
			return 0;
		}
		else
		{
			Data k;
			k = Dec.front();
			Dec.pop_front();
			return k;
		}
	}
	Data OutRight()
	{
		if (Dec.empty())
		{
			cout << "Дек пуст, возвращен 0\n";
			return 0;
		}
		else
		{
			Data k;
			k = Dec.back();
			Dec.pop_back();
			return k;
		}
	}
};

template <class Tdata>
void proverka(Tdata *mas)
{
	int i,n;
	cout << "Введите количество элементов массива:";
	cin >> n;
	mas = new Tdata[n];
	for (i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " элемент:";
		cin >> mas[i];
	}
	back(mas, n);
	cout << "Новый массив: ";
	for (i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	delete[]mas;
}

template <class Tdata>
void Dec(Dec_connect <Tdata> dec)
{
	char menu='0';
	Tdata data;
	do {
		system("CLS");
		cout << "1. Добавить элемент в конец\n";
		cout << "2. Вытащить элемент с левого конца\n";
		cout << "3. Вытащить элемент с правого конца\n";
		cout << "4. Закончить тестирование\n";
		cin >> menu;
		switch (menu)
		{
		case '1':
			system("CLS");
			cout << "Введите число:";
			cin >> data;
			dec.InRight(data);
			break;
		case '2':
			system("CLS");
			cout << dec.OutLeft();
			break;
		case '3':
			system("CLS");
			cout << dec.OutRight();
			break;
		case '4':
			system("CLS");
			dec.del_dec();
			break;
		}
		getchar(); getchar();
	} while (menu != '4');
}

int main()
{
	setlocale(0, "Russian");
	int data, n, i;
	unsigned int *a=NULL;
	float* m=NULL;
	char menu;
	do
	{
		system("CLS");
		cout << "1. Проверить шаблон функции\n";
		cout << "2. Проверить шаблон класса\n";
		cout << "3. Выход\n";
		cin >> menu;
		switch (menu) {
		case '1':
			system("CLS");
			cout << "1. Проверить с unsigned int\n";
			cout << "2. Проверить с float\n";
			cin >> menu;
			switch (menu) {
			case '1':
				proverka(a);
				break;
			case '2':
				proverka(m);
				break;
			}
			getchar(); getchar();
			break;
		case '2':
			system("CLS");
			cout << "1. Создать АТД дек с огр. входом unsigned int\n";
			cout << "2. Создать АТД дек с огр. входом float\n";
			cin >> menu;
			if (menu == '1')
			{
				Dec_connect<unsigned int> dec;
				Dec(dec);
			}
			else if(menu == '2')
			{
				Dec_connect<float> dec;
				Dec(dec);
			}
		}
	} while (menu != '3');
	return 0;
}

