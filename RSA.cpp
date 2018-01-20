#include<iostream>
#include<math.h>
#include<locale>
#include <fstream>
#include <string>

using namespace std;

// gcd
int gcd(int a, int h)
{
	int temp;
	while (1)
	{
		temp = a%h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}

int main()
{
	setlocale(0, "Rus");
	
	double p = 3;
	double q = 7;
	double n = p*q;
	double count;
	double totient = (p - 1)*(q - 1);

	//закрытый ключ
	//e для шифра
	double e = 2;

	//проверка 
	while (e<totient) {
		count = gcd(e, totient);
		if (count == 1)
			break;
		else
			e++;
	}

	//закрытый key
	//d для дешфировки
	double d;

	//k любое
	double k = 2;

	// d*e = 1 + k * totient
	d = (1 + (k*totient)) / e;
	cout << "Введите сообщение(число): ";
	double msg;
	cin >> msg;

	double c = pow(msg, e);
	double m = pow(c, d);
	c = fmod(c, n);
	m = fmod(m, n);

	cout << "Message data = " << msg;
	cout << "\n" << "p = " << p;
	cout << "\n" << "q = " << q;
	cout << "\n" << "n = pq = " << n;
	cout << "\n" << "totient = " << totient;
	cout << "\n" << "e = " << e;
	cout << "\n" << "d = " << d;
	cout << "\n" << "Encrypted data = " << c;
	cout << "\n" << "Original Message sent = " << m;
	system("pause");
	return 0;
}
