#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include "json.hpp"
using json = nlohmann::json;

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

#include "datas.h"
#include "models.h"
#include "functions.h"

size_t doctorSize = 0;


int main()
{
	srand(time(NULL));
	cout << "Welcome To Doctor Admin System";
	this_thread::sleep_for(chrono::seconds(2));

	Doctor* doctors = nullptr;
	loadDoctorsFromFile(doctors, doctorSize);

	/*while (true)
	{
		int intch = _getch();
		char ch = intch;
		cout << "intch: " << intch << endl;
		cout << "ch: " << ch << endl;

		if (intch == 27)
			break;
	}*/
	int choice = 0;
	while (true)
	{
		system("cls || clear");
		cout << "Add Doctor" << (choice == 0 ? "<<" : "") << endl;
		cout << "Update Doctor" << (choice == 1 ? "<<" : "") << endl;
		cout << "Get Doctors" << (choice == 2 ? "<<" : "") << endl;
		cout << "Get Doctors By Id" << (choice == 3 ? "<<" : "") << endl;
		cout << "Filter Doctors" << (choice == 4 ? "<<" : "") << endl;
		cout << "Delete Doctor" << (choice == 5 ? "<<" : "") << endl;
		cout << "Exit" << (choice == 6 ? "<<" : "") << endl;

		int c = 0;
		switch (c = _getch())
		{
		case KEY_UP:
			if (choice > 0) choice--;
			else choice = 6;
			break;
		case KEY_DOWN:
			if (choice < 6) choice++;
			else choice = 0;
			break;
		case KEY_LEFT:
			break;
		case KEY_RIGHT:
			break;
		case ENTER:
			system("cls || clear");
			switch (choice)
			{
			case 0:
			{
				cout << "Add Doctor" << endl;
				int id;
				cout << "Enter ID: ";
				cin >> id;

				if (idCheck(doctors, id, doctorSize) != -1)
				{
					cout << "There is already a doctor with this ID\nDoctor not added successfully!" << endl;
					break;
				}

				Doctor newDoctor;
				inputDoctorData(newDoctor, id);
				addDoctor(doctors, doctorSize, newDoctor);
				saveDoctorsToFile(doctors, doctorSize);

				cout << "Doctor successfully added" << endl;
				break;
			}
			case 1:
			{
				cout << "Update Doctor" << endl;
				int id;
				cout << "Enter ID: ";
				cin >> id;

				int check = idCheck(doctors, id, doctorSize);

				if (check == -1)
				{
					cout << "Doctor not found\nDoctor not updated successfully!" << endl;
					break;
				}

				Doctor newDoctor;
				inputDoctorData(newDoctor, id);
				updateDoctor(id, newDoctor, doctors, doctorSize, check);
				saveDoctorsToFile(doctors, doctorSize);

				cout << "Doctor updated successfully" << endl;
				break;
			}
			case 2:
			{
				cout << "Doctors: " << endl;
				getDoctors(doctors, doctorSize);
				break;
			}
			case 3:
			{
				int id;
				cout << "Enter Id: ";
				cin >> id;
				cout << "Doctors by ID: " << endl;
				getDoctorById(doctors, doctorSize, id);
				break;
			}
			case 4:
			{
				int fchoice = 0;

				while (true)
				{
					system("cls || clear");

					cout << "Select Filter:\n";
					cout << "By Experience" << (fchoice == 0 ? " <<" : "") << endl;
					cout << "By Specialization" << (fchoice == 1 ? " <<" : "") << endl;

					int c = _getch();
					if (c == KEY_UP)
					{
						if (fchoice > 0) fchoice--;
						else fchoice = 1;
					}
					else if (c == KEY_DOWN)
					{
						if (fchoice < 1) fchoice++;
						else fchoice = 0;
					}
					else if (c == ENTER)
					{
						system("cls || clear");

						if (fchoice == 0)
						{
							cout << "Enter min experience: ";
							cin >> minExp;

							cout << "Enter max experience: ";
							cin >> maxExp;

							filterDoctors(doctors, doctorSize, expFilter);
						}
						else if (fchoice == 1)
						{
							selectedSpec = selectSpecializationWithArrows();

							filterDoctors(doctors, doctorSize, specFilter);
						}
						_getch();
						break;
					}
				}
				break;
			}
			case 5:
			{
				cout << "Delete Doctor" << endl;

				int id;
				cout << "Enter ID: ";
				cin >> id;

				deleteDoctor(id, doctors, doctorSize);
				saveDoctorsToFile(doctors, doctorSize);

				break;
			}
			case 6:
			{
				cout << "Finish";
				return 0;
			}
			default:
			{
				cout << "This choose is not found";
				break;
			}
			}
			_getch();
			break;
		default:
			break;
		}
	}
	return 0;
}