#include <iostream>

using namespace std;

int placechecker(string tempb[], int inpu)

{

	if (tempb[inpu - 1] != "---" && tempb[inpu - 1] != "--- " && tempb[inpu - 1] != " | " && tempb[inpu - 1] != " |")
	{

		return 1;

	}

	else

		return 2;

}



int checker(int xcounter, int ocounter, string pobox[4], string dotsenbox[12])

{

	for (int j = 0; j <= 3; j++)

	{

		if (pobox[j] == "X")

		{

			xcounter++;

		}

		if (pobox[j] == "O")

		{

			ocounter++;

		}

	}

	if (xcounter == 2 && ocounter == 2)

	{

		return 1;

	}

	if (xcounter == 3 && ocounter == 1)

	{

		return 2;

	}

	if (xcounter == 4)

	{

		return 2;

	}

	if (ocounter == 3 && xcounter == 1)

	{

		return 3;

	}

	if (ocounter == 4)

	{

		return 3;

	}

	else

	{

		return 0;

	}

}

void display(int size, string dotnbox[12], string potbox[4])

{

	if (size = 1)//3x3

	{

		cout << " | + " << dotnbox[0] << " + " << dotnbox[1] << " + |" << endl;

		cout << " |" << dotnbox[2] << " " << potbox[0] << " " << dotnbox[3] << " " << potbox[1] << " " << dotnbox[4] << "|" << endl;
		cout << " | + " << dotnbox[5] << " + " << dotnbox[6] << " + |" << endl; cout << " |" << dotnbox[7] << " " << potbox[2] << " " << dotnbox[8] << " "<<potbox[3]<<""<<dotnbox[9]<<"| "<<endl;

		cout << " | + " << dotnbox[10] << "+ " << dotnbox[11] << "+ |" << endl;

	}

}

int main()

{

	int detector;

	int checkplace;

	int xcount = 0;

	int ocount = 0;

	int infinite = 12;

	int colorchecker;

	int checkedvalue;

	int superloopchecker;

	string playera;

	string playerb;

	string temp[12];

	string dotsandboxes[12] = { " 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10 "," 11 "," 12 " };

	string boxcheck[4] = { " "," "," "," " };

	int sizeoption = 1;

	cout << "Hello, welcome to Dots and Boxes! Who will be player A today?\n"; cin >> playera;

	cout << "Who will be player B today?\n";

	cin >> playerb;

	display(sizeoption, dotsandboxes, boxcheck);

	int cheky;

	while (infinite > 0)

	{

	aplayerinput:

		cout << playera << ", Where will your line be? (Input your choice in this format : 1,2,3)\n"; int input;
		for (int i = 0; i <= 11; i++)

		{

			temp[i] = dotsandboxes[i];

		}

		cin >> input;

		checkplace = placechecker(temp, input);

		if (checkplace == 2)

		{

			cout << "You can't do that! Try again.\n";

			goto aplayerinput;

		}

		else

			for (int z = 0; z <= 12; z++)

			{

				if (z == 3 || z == 8)

				{

					z = z + 3;

				}

				if (input == z)

				{

					if (z >= 11)

					{

						dotsandboxes[z - 1] = "--- ";

						goto endofturn1;

					}

					else

						dotsandboxes[z - 1] = "---";

					goto endofturn1;

				}

			}

		for (int x = 3; x <= 10; x++)

		{
			if (x == 6)

			{
				x = x + 2;

			}

			if (input == x)

			{
				if (x == 10)

				{

					dotsandboxes[x - 1] = " | "; goto endofturn1;
				}

				else

					dotsandboxes[x - 1] = " | ";

				goto endofturn1;

			}

		}

		if (input != 1 || input != 2 || input != 3 || input != 4 || input != 5 || input != 6 || input != 7 || input != 8 || input != 9 || input != 10 || input != 11 || input != 12)
		{

			cout << "There is no possible line there!\n";

			goto aplayerinput;

		}

	endofturn1:

		colorchecker = 1;

		for (int y = 3; y <= 10; y++)

		{

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "---")

			{

				if (colorchecker = 1)

				{

					if (boxcheck[y - 3] == " ")

					{

						boxcheck[y - 3] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto aplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 3] == " ")

					{

						boxcheck[y - 3] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes);

						if (detector == 1 || detector == 2 || detector == 3)

						{

							goto victory;

						}

						goto bplayerinput;

					}

				}

			}

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "--- ")

			{

				if (colorchecker = 1)

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto aplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto bplayerinput;

					}

				}

			}

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "--- ")

			{

				if (colorchecker = 1)

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3) {

							goto victory;

						}

						goto aplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3) {

							goto victory;

						}

						goto bplayerinput;

					}

				}

			}

		}

		display(sizeoption, dotsandboxes, boxcheck);

		detector = checker(xcount, ocount, boxcheck, dotsandboxes);

	victory:

		if (detector == 1)

		{

			cout << "You have both tied!";

			return 0;

		}

		if (detector == 2)

		{

			cout << playera << ", you have won this game of dots and boxes!\n"; return 0;
		}

		if (detector == 3)

		{

			cout << playerb << ", you have won this game of dots and boxes!\n"; return 0;
		}

	bplayerinput:

		superloopchecker = 0;

		cout << playerb << ", Where will your line be? (Input your choice in this format : 1,2,3)\n"; cin >> input;
		for (int i = 0; i <= 11; i++)

		{

			temp[i] = dotsandboxes[i];

		}

		checkplace = placechecker(temp, input);

		if (checkplace == 2)

		{

			cout << "You can't do that! Try again.\n";

			goto bplayerinput;

		}

		else

			for (int z = 0; z <= 12; z++)

			{

				if (z == 3 || z == 8)

				{

					z = z + 3;

				}

				if (input == z)

				{

					if (z >= 11)

					{

						dotsandboxes[z - 1] = "--- ";

						goto endofturn2;

					}

					else

						dotsandboxes[z - 1] = "---";

					goto endofturn2;

				}

			}

		for (int x = 3; x <= 10; x++)

		{

			if (x == 6)

			{

				x = x + 2;

			}

			if (input == x)

			{

				if (x == 10)

				{

					dotsandboxes[x - 1] = " | ";

					goto endofturn2;

				}

				else

					dotsandboxes[x - 1] = " | ";

				goto endofturn2;

			}

		}

		if (input != 1 || input != 2 || input != 3 || input != 4 || input != 5 || input != 6 || input != 7 || input != 8 || input != 9 || input != 10 || input != 11 || input != 12)
		{

			cout << "There is no possible line there!\n";

			goto bplayerinput;

		}

	endofturn2:

		colorchecker = 2;

		for (int y = 3; y <= 10; y++)

		{

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "---")

			{

				if (colorchecker = 2)

				{

					if (boxcheck[y - 3] == " ")

					{

						boxcheck[y - 3] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto bplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 3] == " ")

					{

						boxcheck[y - 3] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3) {

							goto victory;

						}

						goto aplayerinput;

					}

				}

			}

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "--- ")

			{

				if (colorchecker = 2)

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto bplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3)
						{

							goto victory;

						}

						goto aplayerinput;

					}

				}

			}

			if (dotsandboxes[y - 3] == "---" && dotsandboxes[y - 1] == " | " && dotsandboxes[y] == " | " && dotsandboxes[y + 2] == "--- ")

			{

				if (colorchecker = 2)

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "O";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3) {

							goto victory;

						}

						goto bplayerinput;

					}

				}

				else

				{

					if (boxcheck[y - 6] == " ")

					{

						boxcheck[y - 6] = "X";

						display(sizeoption, dotsandboxes, boxcheck);

						detector = checker(xcount, ocount, boxcheck, dotsandboxes); if (detector == 1 || detector == 2 || detector == 3) {

							goto victory;

						}

						goto aplayerinput;

					}

				}

			}

		}

		display(sizeoption, dotsandboxes, boxcheck);

		detector = checker(xcount, ocount, boxcheck, dotsandboxes);

		if (detector == 1)

		{

			cout << "You have both tied!";

			return 0;

		}

		if (detector == 2)

		{

			cout << playera << ", you have won this game of dots and boxes!\n"; return 0;
		}

		if (detector == 3)

		{

			cout << playerb << ", you have won this game of dots and boxes!\n"; return 0;
		}

	}

}
