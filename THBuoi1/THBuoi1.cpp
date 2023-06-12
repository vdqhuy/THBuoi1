#include <iostream>
#include <string>
using namespace std;

void giaiPTBac2(int a, int b, int c) {
	if (a == 0 && b != 0) {
		cout << "Phuong trinh co nghiem x = " << -c / b << endl;
	}
	else if (a != 0 && b == 0) {
		if (-c / a > 0) {
			cout << "Phuong trinh co nghiem x = " << sqrt((double)-c / a) << endl;
		}
		else {
			cout << "Phuong trinh vo nghiem" << endl;
		}
	}
	else if (a == 0 && b == 0) {
		cout << "Phuong trinh vo nghiem" << endl;
	}
	else {
		int denta = b * b - 4 * a * c;
		if (denta < 0) {
			cout << "Phuong trinh vo nghiem" << endl;
		}
		else if (denta == 0) {
			cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
		}
		else {
			cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
			cout << "- x1 = " << (-b + sqrt((double)denta)) / (2 * a) << endl;
			cout << "- x2 = " << (-b - sqrt((double)denta)) / (2 * a) << endl;
		}
	}
}

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void phanTinhThuaSoNguyenTo(int n) {
	if (n < 2 || isPrime(n)) {
		cout << n << endl;
	}
	else {
		cout << 2;
		n /= 2;

		int i = 3;
		while (i <= n) {
			if (n % i == 0) {
				cout << " x " << i;
				n /= i;
				i = 3;
			}
			else {
				i++;
			}
		}
		cout << endl;
	}
}

string decToBin(long n) {
	string kq = "";
	while (n != 0) {
		kq += to_string(n % 2);
		n /= 2;
	}
	reverse(kq.begin(), kq.end());
	return kq;
}

int giaiThuaDeQui(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * giaiThuaDeQui(n - 1);
}

int giaiThuaKoDeQui(int n) {
	int kq = 1;
	do {
		kq *= n;
		if (n == 1)
			break;
	} while (n--);
	return kq;
}

void fibonacci(int n) {
	int f0 = 0;
	int f1 = 1;
	int fn = 1;

	if (n <= 0)
		cout << "n phai la so nguyen duong";
	else if (n == 1) {
		cout << f0;
	}
	else if (n == 2) {
		cout << f0 << " " << f1;
	}
	else if (n == 3) {
		cout << f0 << " " << f1 << " " << fn;
	}
	else {
		cout << f0 << " " << f1 << " " << fn << " ";
		for (int i = 4; i <= n; i++) {
			f0 = f1;
			f1 = fn;
			fn = f0 + f1;
			cout << fn << " ";
		}
	}
	cout << endl;
}

int main() {
	bool stop = false;
	int choice;
	int a, b, c, n;
	while (!stop) {
		cout << "1. Viet chuong trinh C++ giai phuong trinh bac 2: ax2 + bx + c = 0." << endl;
		cout << "2. Viet chuong trinh C++ tim uoc so chung lon nhat (UCLN) va boi so chung nho nhat (BCNN) cua hai so a va b." << endl;
		cout << "3. Viet chuong trinh C++ liet ke tat ca cac so nguyen to nho hon n." << endl;
		cout << "4. Viet chuong trinh C++ liet ke n so nguyen to dau tien." << endl;
		cout << "5. Viet chuong trinh C++ liet ke tat ca cac so nguyen to co 5 chu so." << endl;
		cout << "6. Viet chuong trinh C++ phan tich so nguyen n thanh cac thua so nguyen to. Vi du: 12 = 2 x 2 x 3." << endl;
		cout << "7. Viet mot chuong trinh C++ de chuyen doi so nguyen N sang he co so B (2 <= B <= 32) bat ky." << endl;
		cout << "8. Viet mot chuong trinh C++ tinh giai thua cua mot so bang cach khong su dung de quy va co su dung de quy" << endl;
		cout << "9. Viet mot chuong trinh C++ in ra day so Fibonacci" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "Nhap bai tap (1-9): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> a >> b >> c;
			giaiPTBac2(a, b, c);
			break;
		case 2:
			cin >> a >> b;
			cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << gcd(a, b) << endl;
			cout << "Boi chung nho nhat cua " << a << " va " << b << " la: " << lcm(a, b) << endl;
			break;
		case 3:
			cin >> n;
			for (int i = 2; i < n; i++) {
				if (isPrime(i)) {
					cout << i << " ";
				}
			}
			cout << endl;
			break;
		case 4:
		{
			cin >> n;
			int i = 0, j = 2;
			while (i < n) {
				if (isPrime(j)) {
					cout << j << " ";
					i++;
				}
				j++;
			}
			cout << endl;
			break;
		}
		case 5:
		{
			for (int i = 10000; i < 99999; i++) {
				if (isPrime(i)) {
					cout << i << " ";
				}
			}
			cout << endl;
			break;
		}
		case 6:
			cin >> n;
			phanTinhThuaSoNguyenTo(n);
			break;
		case 7:
		{
			long n;
			cin >> n;
			cout << decToBin(n) << endl;
			break;
		}
		case 8:
			cin >> n;
			cout << "Giai thua de qui: " << giaiThuaDeQui(n) << endl;
			cout << "Giai thua khong de qui: " << giaiThuaKoDeQui(n) << endl;
			break;
		case 9:
			cin >> n;
			fibonacci(n);
			break;
		case 0:
			cout << "Dung chuong trinh" << endl;
			stop = true;
			break;
		default:
			cout << "Khong co lua chon " << choice << endl;
			break;
		}
	}
}