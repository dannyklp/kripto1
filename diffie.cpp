#include<stdio.h>
#include<math.h>
#include <string>
#include <iostream>
#include <locale>
#include <windows.h>
using namespace std;

long long int power(long long int a, long long int b,
                                     long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

string magic(string message, long long int key)
{
	string result;
	for (int i = 0; i < message.size(); i++) {
		result += message[i] ^ key;
	}
	return result;
}

int main()
{
	//SetConsoleCP(65001);
	setlocale(0, "Russian");
    long long int P, G, x, a, y, b, ka, kb;

    P = 23; 
    printf("Значение P: ", P);

    G = 9;
    printf("Значение G: ", G);

   
    a = 4;
    printf("Закрытый ключ для Алисы: ", a);
    x = power(G, a, P); 

    b = 3; 
    printf("Закрытый ключ для Боба: ", b);
    y = power(G, b, P); 

    
  
    ka = power(y, a, P); 
    kb = power(x, b, P); 

    printf("Секретный ключ для Алисы: ", ka);
    printf("Секретный ключ дял Боба: ", kb);

	cout << "Анна: ";
	string mes;
	getline(cin, mes);
	string encrypted = magic(mes, ka);
	cout << endl << "Зашифровано: " << encrypted << endl;
	string dec = magic(encrypted, kb);
	cout << "Расшифровано: " << dec << endl;

	cout << "Боб: ";
	getline(cin, mes);
	encrypted = magic(mes, ka);
	cout << endl << "Зашифровано: " << encrypted << endl;
	dec = magic(encrypted, kb);
	cout << "Расшифровано: " << dec << endl;

	system("pause");
    return 0;
}
