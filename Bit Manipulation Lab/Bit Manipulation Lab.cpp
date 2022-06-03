// Bit Manipulation Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
unsigned int bitField = 149;

void Print(unsigned int x);
void TurnOn(int bit);
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();

int main()
{
	while (true)
	{
		system("cls");
		Print(bitField);
		std::cout << "\n\n";
		const char* menu[] = { "1) TurnOn", "2) TurnOff", "3) Toggle", "4) Negate/Undo", "5) Left Shift", "6) Right Shift", "7) Exit"};
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << menu[i] << ", ";
		}
		std::cout << menu[6] << "\n";
		std::cout << "\nChoose operation: ";
		int p;
		std::cin >> p;
		int bit;
		switch (p)
		{
		case 1:
			std::cout << "Choose bit index: ";
			std::cin >> bit;
			TurnOn(bit);
			break;

		case 2:
			std::cout << "Choose bit index: ";
			std::cin >> bit;
			TurnOff(bit);
			break;

		case 3:
			std::cout << "Choose bit index: ";
			std::cin >> bit;
			Toggle(bit);
			break;

		case 4:
			Negate();
			break;

		case 5:
			LeftShift();
			break;

		case 6:
			RightShift();
			break;
		}
		if (p == 7)
		{
			break;
		}
	}
	//system("pause");

}

void Print(unsigned int x)
{
	//std::cout << "Dec = " << std::dec << x << "\t";
	//std::cout << "Hex = " << std::hex << x << "\t";
	//std::cout << "Bin = " << std::bitset<32>(x) << std::endl;
	int bit[32] = {};
	int n = 1;
	std::cout << "bitField: " << x << "\n\n";
	std::cout << "Bits:";
	for (size_t i = 0; i < 32; i++)
	{
		bit[i] = 0;
	}
	n = 0;
	for (unsigned int max = INT32_MAX + 1; max > 0; max /= 2)
	{
		if (x >= max)
		{
			bit[n] = 1;
			x -= max;
		}
		n++;
	}
	for (size_t i = 0; i < 32; i++)
	{
		if (i % 4 == 0)
		{
			std::cout << " ";
		}
		std::cout << bit[i];
	}
}

void TurnOn(int bit)
{
	bitField = bitField | 1 << bit;
	/*Print(bitField);
	std::cout << "\n\n";*/
}

void TurnOff(int bit)
{
	bitField = bitField & ~(1 << bit);
	Print(bitField);
	std::cout << "\n\n";
}

void Toggle(int bit)
{
	bitField = bitField ^ (1 << bit);
	Print(bitField);
	std::cout << "\n\n";
}

void Negate()
{
	bitField = ~bitField;
	Print(bitField);
	std::cout << "\n\n";
}

void LeftShift()
{
	bitField = bitField << 1;
	Print(bitField);
	std::cout << "\n\n";
}

void RightShift()
{
	bitField = bitField >> 1;
	Print(bitField);
	std::cout << "\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
