
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
    printf("The value of P : %lld\n", P);

    G = 9;
    printf("The value of G : %lld\n\n", G);

   
    a = 4;
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P); 

    b = 3; 
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, P); 

    
  
    ka = power(y, a, P); 
    kb = power(x, b, P); 

    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);

	cout << "Анна: ";
	string mes;
	getline(cin, mes);
	string encrypted = magic(mes, ka);
	cout << endl << "Зашифрованно: " << encrypted << endl;
	string dec = magic(encrypted, kb);
	cout << "Расшифрованно: " << dec << endl;

	cout << "Боб: ";
	getline(cin, mes);
	encrypted = magic(mes, ka);
	cout << endl << "Зашифрованно: " << encrypted << endl;
	dec = magic(encrypted, kb);
	cout << "Расшифрованно: " << dec << endl;

	system("pause");
    return 0;
}
