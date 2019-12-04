#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//My badly named structor
struct Vader
{
	string date, time, inOut;
	double temperature, tempAvgIn, tempAvgOut;
	int humidity, humAvgIn, humAvgOut;
	int moldIn, moldOut;
};

//Linear search
int search(struct Vader arr[], int n, string x)//Search function inside
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].date == x)
			return i;
	}
	return -1;
}

int searchUt(struct Vader arr2[], int m, string x)//Search function outside
{
	for (int i = 0; i < m; i++)
	{
		if (arr2[i].date == x)
			return i;
	}
	return -1;
}

//Swap function
void swap(Vader* xp, Vader* yp)
{
	Vader temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//All my bubble sorts
void bubbleSort(struct Vader arr[], int n)//Average temperature inside
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		 
		for (j = 0; j < n - i - 1; j++)
			if (arr[j].tempAvgIn > arr[j + 1].tempAvgIn)
				swap(&arr[j], &arr[j + 1]);
}
void printArray(struct Vader arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].date << " " <<  arr[i].tempAvgIn << " " << endl;
	cout << endl;
}


void bubbleSortUt(struct Vader arr[], int n)//Average temperature outside
{
	int i, j;
	for (i = 0; i < n - 1; i++)


		for (j = 0; j < n - i - 1; j++)
			if (arr[j].tempAvgOut > arr[j + 1].tempAvgOut)
				swap(&arr[j], &arr[j + 1]);
}
void printArrayUt(struct Vader arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].date << " " << arr[i].tempAvgOut << " " << endl;
	cout << endl;
	
}


void bubbleSortFIn(struct Vader arr[], int n)//Average humidity inside
{
	int i, j;
	for (i = 0; i < n - 1; i++)


		for (j = 0; j < n - i - 1; j++)
			if (arr[j].humAvgIn > arr[j + 1].humAvgIn)
				swap(&arr[j], &arr[j + 1]);
}
void printArrayFIn(struct Vader arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].date << " " << arr[i].humAvgIn << " " << endl;
	cout << endl;
}


void bubbleSortFUt(struct Vader arr[], int n)//Average humidity outside
{
	int i, j;
	for (i = 0; i < n - 1; i++)


		for (j = 0; j < n - i - 1; j++)
			if (arr[j].humAvgOut > arr[j + 1].humAvgOut)
				swap(&arr[j], &arr[j + 1]);
}
void printArrayFUt(struct Vader arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].date << " " << arr[i].humAvgOut << " " << endl;
	cout << endl;
}

void CalcMold(Vader arr[], int n) //Danger for mold inside
{
	double humlimit = 78;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i].tempAvgIn >= 15 && arr[i].tempAvgIn < 50) && (arr[i].humAvgIn >= humlimit)) 
		{
			arr[i].moldIn = (arr[i].humAvgIn - humlimit) / 0.22;
		}
		else if ((arr[i].tempAvgIn >= 0 && arr[i].tempAvgIn < 15) && (arr[i].humAvgIn >= humlimit))
		{
			arr[i].moldIn = ((arr[i].humAvgIn - humlimit) * (arr[i].tempAvgIn / 15)) / 0.22;
		}
		else
		{
			arr[i].moldIn = 0;
		}
	}
}
void PrintMold(Vader arr[], int n) 
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i].date << " " << arr[i].moldIn << " " << endl;
	cout << endl;
}

void CalcMoldUt(Vader arr[], int n) //Danger for mold outside
{
	double humlimit = 78;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i].tempAvgOut >= 15 && arr[i].tempAvgOut < 50) && (arr[i].humAvgOut >= humlimit))
		{
			arr[i].moldOut = (arr[i].humAvgOut - humlimit) / 0.22;
		}
		else if ((arr[i].tempAvgOut >= 0 && arr[i].tempAvgOut < 15) && (arr[i].humAvgOut >= humlimit))
		{
			arr[i].moldOut = ((arr[i].humAvgOut - humlimit) * (arr[i].tempAvgOut / 15)) / 0.22;
		}
		else
		{
			arr[i].moldOut = 0;
		}
		int k, j;
		for (k = 0; k < n - 1; k++)


			for (j = 0; j < n - k - 1; j++)
				if (arr[j].moldOut > arr[j + 1].moldOut)
					swap(&arr[j], &arr[j + 1]);
	}
}
void PrintMoldUt(Vader arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i].date << " " << arr[i].moldOut << " " << endl;
	cout << endl;
}

struct Vader Inne[131];
struct Vader Ute[131];
int InneCounter = 0;
int UteCounter = 0;

int main() 
{	
	string day, time, inOut, temperature, humidity;
	ifstream text("tempdata4.txt"); // Txt file

	if (text.is_open()) //If the txt file is open
	{
		int i;
		string NowDate = "";
		string LookDate = "";
		double tempSumIn = 0; // Temperature for Inne
		int humSumIn = 0; // Humidity for Inne
		double tempSumOut = 0; //Temperature for Ute
		int humSumOut = 0; // Humidity for Ute
		int count = 0; // Counter for Inne
		int count2 = 0; // Counter for Ute

		while (!text.eof()) // While not at the end of the txt file
		{	//What I take from the txt file
			getline(text, day, ' ');
			getline(text, time, ',');
			getline(text, inOut, ',');
			getline(text, temperature, ',');
			getline(text, humidity);

			if (day == LookDate && inOut == "Inne") //Only get values from Inne
			{
				tempSumIn += stod(temperature);
				humSumIn += stoi(humidity);
				NowDate = day;

				

				count++; //counter for Inne
				
			}
			else if (day == LookDate && inOut == "Ute") //Only get values from Ute
			{
				tempSumOut += stod(temperature);
				humSumOut += stoi(humidity);
				NowDate = day;

				
				
				count2++; //counter for Ute
				
			}
			else 
			{
				LookDate = day;
				if (count != 0) 
				{
					//Puts day temp and humidity in Inne
					Inne[InneCounter].date = NowDate;
					Inne[InneCounter].tempAvgIn = tempSumIn / count;
					Inne[InneCounter].humAvgIn = humSumIn / count;
					
					InneCounter++;//Puts everything in Inne
					
					tempSumIn = 0;
					humSumIn = 0;
					count = 0;
					LookDate = day;
				}
				if (count2 != 0) 
				{
					//Puts day temp and humidity in Ute
					Ute[UteCounter].date = NowDate;
					Ute[UteCounter].tempAvgOut = tempSumOut / count2;
					Ute[UteCounter].humAvgOut = humSumOut / count2;

					UteCounter++;//Puts everything in Ute
					

					tempSumOut = 0;
					humSumOut = 0;
					count2 = 0;
					LookDate = day;
				}
			}	
		}
		 
		
			string bub;
			cout << "Hello, what do you want to know?" << endl; //The menu
			cout << "=======================================================" << endl;
			cout << "[1]   Average temperatures inside, lowest to highest " << endl;
			cout << "[2]   Average temperatures outside, lowest to highest" << endl;
			cout << "[3]   Average humidity inside, lowest to highest" << endl;
			cout << "[4]   Average humidity outside, lowest to highest" << endl;
			cout << "[5]   Find date inside" << endl;
			cout << "[6]   Find date outside" << endl;
			cout << "[7]   Date Meteorological autumn" << endl;
			cout << "[8]   Date Meteorological winter" << endl;
			cout << "[9]   Danger for mold inside" << endl;
			cout << "[10]  Danger for mold outside, lowest to highest" << endl;
			cout << "[11]  Exit" << endl;
			cout << "=======================================================" << endl;
			cout << endl;
			getline(cin, bub);

			if (bub== "1")
			{
				int n = sizeof(Inne) / sizeof(Inne[0]);
				bubbleSort(Inne, n);
				printArray(Inne, n);
			}
			if (bub == "2")
			{
				int n = sizeof(Ute) / sizeof(Ute[0]);
				bubbleSortUt(Ute, n);
				printArrayUt(Ute, n);
				
			}
			if (bub == "3")
			{
				int n = sizeof(Inne) / sizeof(Inne[0]);
				bubbleSortFIn(Inne, n);
				printArrayFIn(Inne, n);
			}
			if (bub == "4")
			{
				int n = sizeof(Ute) / sizeof(Ute[0]);
				bubbleSortFUt(Ute, n);
				printArrayFUt(Ute, n);
			}
			if (bub == "5")
			{
				Vader arr[131];
				int n = sizeof(Inne) / sizeof(Inne[0]);

				cout << "Enter date" << endl;
				cout << "Please enter it as 'yyyy-mm-dd'" << endl;
				string x;
				getline(cin, x);

				int index = search(Inne, n, x);

				if (index == -1)
				{
					cout << x << " Can't be found " << endl;
				}
				else
				{
					cout << "Average temperature inside: " << x << ": " << Inne[index].tempAvgIn << endl;
				}
			}
			if (bub == "6")
			{

				Vader arr2[131];
				int m = sizeof(Ute) / sizeof(Ute[0]);

				cout << "Enter date" << endl;
				cout << "Please enter it as 'yyyy-mm-dd'" << endl;
				string x;
				getline(cin, x);

				int index = searchUt(Ute, m, x);

				if (index == -1)
				{
					cout << x << " Can't be found " << endl;
					cout << endl;
				}
				else
				{
					cout << "Average temperature outside: " << x << ": " << Ute[index].tempAvgOut << endl;
					cout << endl;
				}
			}
			if (bub == "7")
			{
				int fall = 0;
				for (int i = 0; i < 131; i++) 
				{
					if (Ute[i].tempAvgOut > 0 && Ute[i].tempAvgOut < 10) 
					{
						fall++;
						if (fall == 5) 
						{
							cout << "Meteorological autumn started: " << Ute[i].date << endl;
						}
					}
				}
				cout << endl;
			}
			if (bub == "8")
			{
				int winter = 0;
				for (int i = 0; i < 131; i++)
				{
					if (Ute->tempAvgOut <= 0)
					{
						winter++;
						if (winter == 5)
						{
							cout << "Meteorological winter started: " << Ute[i].date << endl;

						}
					}
					else winter = 0;
				}
				if (winter == 0) 
				{
					cout << "Meteorological winter not found" << endl;
					cout << endl;
				}
			}
			if (bub == "9")
			{
				int n = sizeof(Inne) / sizeof(Inne[0]);
				CalcMold(Inne, n);
				PrintMold(Inne, n);
				cout << "Danger for mold increase with higher numbers" << endl;
			}
			if (bub == "10")
			{
				int n = sizeof(Ute) / sizeof(Ute[0]);
				CalcMoldUt(Ute, n);
				PrintMoldUt(Ute, n);
				cout << "Danger for mold increase with higher numbers" << endl;
			}
		
	}
	
	return 0;
}