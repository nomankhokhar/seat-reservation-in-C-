// Seat Reserved Program
// Noman ALi
// L1F20BSCS0554
#include <iostream>
#include <fstream>
using namespace std;
bool PrintingSeatsChart(char ** seats, int rowSize, int colSize);
bool Reservation(char **seats, int rowSize, int colSize);
bool DelectionASeat(char **seats, int rowSize, int colSize);
bool resertSeatingChart(char **seats, int rowSize, int colSize);

int main()
{
	
	int performFunction = 0;
	char **seats;

	while (true)
	{
		cout << "\n\nPress 1 Print seating chart \nPress 2 Reserve a seat \nPress 3 to cancel a seat \nPress 4 Reset seating chart \nPress 5 Exit program\n\n";
		cin >> performFunction;
		if (performFunction == 1)
		{
			int rowSize = 0;
			int colSize = 0;

			cout << "\nEnter Rows of Plane Seats : \n";
			cin >> rowSize;

			cout << "\nEnter Column of Plane Seats : \n";
			cin >> colSize;
			seats = new char*[rowSize];
			bool status = 0;
			status = PrintingSeatsChart(seats, rowSize, colSize);

			if (status == 1)
			{
				cout << "\n\nAll seat are Printed\n\n";
			}
		}
		else if (performFunction == 2)
		{
			int rowSize = 0;
			int colSize = 0;
			ifstream read;
			read.open("seats.txt");

			char seatsRow[10];

			int length = 0;
			while (read >> seatsRow)
			{
				length = strlen(seatsRow);
				rowSize++;
			}
			colSize = length;
			read.close();

			seats = new char*[rowSize];
			bool status = 0;
			status = Reservation(seats, rowSize, colSize);
			if (status == 1)
			{
				cout << "\nYou Desired Seat is Reserved:\n";
			}
		}
		else if (performFunction == 3)
		{
			int rowSize = 0;
			int colSize = 0;
			ifstream read;
			read.open("seats.txt");

			char seatsRow[10];

			int length = 0;
			while (read >> seatsRow)
			{
				length = strlen(seatsRow);
				rowSize++;
			}
			colSize = length;
			read.close();

			seats = new char*[rowSize];
			bool status = 0;
			status = DelectionASeat(seats, rowSize, colSize);
			if (status == 1)
			{
				cout << "Your Already Reserved Seat is Delete\n";
			}
		}
		else if (performFunction == 4)
		{
			int rowSize = 0;
			int colSize = 0;
			ifstream read;
			read.open("seats.txt");

			char seatsRow[10];

			int length = 0;
			while (read >> seatsRow)
			{
				length = strlen(seatsRow);
				rowSize++;
			}
			colSize = length;
			read.close();

			seats = new char*[rowSize];
			bool status = false;
			status = resertSeatingChart(seats, rowSize, colSize);

			if (status == true)
			{
				cout << "All Seats are Reset!";
			}

		}
		else if (performFunction == 5)
		{
			return 0;
		}
	}
	cout << endl;
	return 0;
}
bool resertSeatingChart(char **seats, int rowSize, int colSize)
{
	bool status = false;
	seats = new char*[rowSize];

	for (int i = 0; i < rowSize; i++)
	{
		seats[i] = new char[colSize];
	}

	ifstream reading;
	reading.open("seats.txt");

	char seatNO;

	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			reading >> seatNO;
			seats[row][col] = seatNO;
		}
	}
	reading.close();
	for (int k = 0; k < rowSize; k++)
	{
		for (int l = 0; l < colSize; l++)
		{
			seats[k][l] = '*';
		}
	}

	char colName = 'A';
	for (int j = 0; j < colSize; j++)
	{
		if (colName == 'A')
		{
			cout << "   " << colName << "  ";
		}
		else
		{
			cout << colName << "  ";
		}
		colName++;
	}

	cout << endl;

	for (int i = 0; i < rowSize; i++)
	{
		cout << i + 1 << "  ";
		for (int k = 0; k < colSize; k++)
		{
			cout << seats[i][k] << "  ";
			status = true;
		}
		cout << endl;
	}

	ofstream write;
	write.open("seats.txt");

	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			write << seats[row][col];
		}
		write << endl;
	}

	write.close();
	return status;
}
bool DelectionASeat(char **seats, int rowSize, int colSize)
{
	int ticket = 0;
	bool status = 0;

	cout << endl << endl << endl;
	cout << "\n\nWhich Type you have a Ticket Type: \nPress 1 for First Class \nPress 2 for Business Class \nPress 3 for Economy Class\n\n";
	cin >> ticket;

	cout << endl;
	if (ticket == 1)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		seats[desireSeatRow - 1][desireSeatCol - 1] = '*';
		status = 1;
		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	else if (ticket == 2)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 2; i < 7; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

		

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		seats[desireSeatRow - 1][desireSeatCol - 1] = '*';
		status = true;
		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	else if (ticket == 3)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 7; i < rowSize; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

		

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		
		seats[desireSeatRow - 1][desireSeatCol - 1] = '*';
		status = true;
		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	return status;
}
bool Reservation(char **seats, int rowSize, int colSize)
{
	int ticket = 0;

	bool status = 0;
	cout << endl << endl << endl;
	cout << "\n\nEnter Ticket Type : \nPress 1 for First Class \nPress 2 for Business Class \nPress 3 for Economy Class\n\n";
	cin >> ticket;

	cout << endl;
	if (ticket == 1)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

	

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		while(seats[desireSeatRow - 1][desireSeatCol - 1] == 'X')
		{
			cout << "\n\nAlert! Your Desire Sead Already Reserved:\n\n";

			cout << "\nPlease Again Enter Desired seat Row : \n";
			cin >> desireSeatRow;
			cout << "\nPlease Again Enter Desired seat Col : \n";
			cin >> desireSeatCol;
		}
		seats[desireSeatRow - 1][desireSeatCol - 1] = 'X';
		status = true;
		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	else if (ticket == 2)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 2; i < 7; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

		

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		while (seats[desireSeatRow - 1][desireSeatCol - 1] == 'X')
		{
			cout << "\n\nAlert! Your Desire Sead Already Reserved:\n\n";

			cout << "\nPlease Again Enter Desired seat Row : \n";
			cin >> desireSeatRow;
			cout << "\nPlease Again Enter Desired seat Col : \n";
			cin >> desireSeatCol;
		}

		seats[desireSeatRow - 1][desireSeatCol - 1] = 'X';
		status = true;
		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	else if (ticket == 3)
	{
		seats = new char*[rowSize];

		for (int i = 0; i < rowSize; i++)
		{
			seats[i] = new char[colSize];
		}

		ifstream reading;
		reading.open("seats.txt");

		char seatNO;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				reading >> seatNO;
				seats[row][col] = seatNO;
			}
		}
		
		reading.close();
		char colName = 'A';
		for (int j = 0; j < colSize; j++)
		{
			if (colName == 'A')
			{
				cout << "   " << colName << "  ";
			}
			else
			{
				cout << colName << "  ";
			}
			colName++;
		}

		cout << endl;

		for (int i = 7; i < rowSize; i++)
		{
			cout << i + 1 << "  ";
			for (int k = 0; k < colSize; k++)
			{
				cout << seats[i][k] << "  ";
			}
			cout << endl;
		}
		int desireSeatRow = 0;

		cout << "\nPlease Enter Desired seat Row : \n";
		cin >> desireSeatRow;

		

		int desireSeatCol = 0;

		cout << "\nPlease Enter Desired seat Col : \n";
		cin >> desireSeatCol;

		while (seats[desireSeatRow - 1][desireSeatCol - 1] == 'X')
		{
			cout << "\n\nAlert! Your Desire Sead Already Reserved:\n\n";

			cout << "\nPlease Again Enter Desired seat Row : \n";
			cin >> desireSeatRow;
			cout << "\nPlease Again Enter Desired seat Col : \n";
			cin >> desireSeatCol;
		}
		seats[desireSeatRow - 1][desireSeatCol - 1] = 'X';
		status = true;

		reading.close();

		ofstream write;
		write.open("seats.txt");

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				write << seats[row][col];
			}
			write << endl;
		}
		write.close();
	}
	return status;
}
	
bool PrintingSeatsChart(char **seats, int rowSize, int colSize)
{
	ofstream write;
	write.open("seats.txt");
	bool status = 0;
	for (int i = 0; i < rowSize; i++)
	{
		seats[i] = new char[colSize];
	}

	for (int k = 0; k < rowSize; k++)
	{
		for (int l = 0; l < colSize; l++)
		{
			seats[k][l] = '*';
			write << seats[k][l];
		}
		write << endl;
	}

	char colName = 'A';
	for (int j = 0; j < colSize; j++)
	{
		if (colName == 'A')
		{
			cout << "   " << colName << "  ";
		}
		else
		{
			cout << colName<<"  ";
		}
		colName++;
	}

	cout << endl;

	for (int i = 0; i < rowSize; i++)
	{
		cout << i + 1 << "  ";
		for (int k = 0; k < colSize; k++)
		{
			cout << seats[i][k] << "  ";
			status = 1;
		}
		cout << endl;
	}
	write.close();
	return status;
}