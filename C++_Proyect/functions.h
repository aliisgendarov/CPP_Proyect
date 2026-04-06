#pragma 

#pragma region Global Filter Variables
int minExp, maxExp;
Specialization selectedSpec;
#pragma endregion

int idCheck(Doctor* doctors, int id, size_t doctorSize)
{
	for (size_t i = 0; i < doctorSize; i++)
		if (doctors[i].id == id)
			return i;

	return -1;
}

#pragma region CRUD Functions
void addDoctor(Doctor*& doctors, size_t& size, const Doctor& newDoctor)
{
	Doctor* newArr = new Doctor[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = doctors[i];
	}

	newArr[size] = newDoctor;

	delete[] doctors;

	doctors = newArr;
	size++;
}

void updateDoctor(int id, const Doctor& newDoctor, Doctor* doctors, size_t doctorSize, int check)
{
	doctors[check] = newDoctor;

	cout << "Update was successful" << endl;
}

void deleteDoctor(int id, Doctor*& doctors, size_t& size)
{
	int index = idCheck(doctors, id, size);

	if (index == -1)
	{
		cout << "Doctor not found" << endl;
		return;
	}

	Doctor* newArr = new Doctor[size - 1];

	for (size_t i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			newArr[j++] = doctors[i];
		}
	}

	delete[] doctors;
	doctors = newArr;
	size--;

	cout << "Doctor deleted successfully" << endl;
}
#pragma endregion

#pragma region Get Functions
void getDoctors(Doctor* doctors, size_t doctorSize)
{
	for (size_t i = 0; i < doctorSize; i++)
	{
		doctors[i].printInfo();
		cout << endl;
	}
}

void getDoctorById(Doctor* doctors, size_t doctorSize, int id)
{
	int check = idCheck(doctors, id, doctorSize);

	if (check == -1)
	{
		cout << "Doctor not found" << endl;
		return;
	}

	doctors[check].printInfoWithId();
	cout << endl;
}
#pragma endregion

#pragma region Filter Functions
bool expFilter(Doctor d)
{
	return d.experience >= minExp && d.experience <= maxExp;
}

bool specFilter(Doctor d)
{
	return d.specialization == selectedSpec;
}

void filterDoctors(Doctor* doctors, size_t size, bool (*filter)(Doctor))
{
	for (size_t i = 0; i < size; i++)
	{
		if (filter(doctors[i]))
		{
			doctors[i].printInfo();
			cout << endl;
		}
	}
}
#pragma endregion

#pragma region Input Functions
Specialization selectSpecializationWithArrows()
{
	int choice = 0;

	while (true)
	{
		system("cls || clear");

		cout << "Select Specialization:\n";
		cout << "Therapist" << (choice == 0 ? " <<" : "") << endl;
		cout << "Surgeon" << (choice == 1 ? " <<" : "") << endl;
		cout << "Cardiologist" << (choice == 2 ? " <<" : "") << endl;
		cout << "Dentist" << (choice == 3 ? " <<" : "") << endl;

		int c = _getch();

		if (c == KEY_UP)
		{
			if (choice > 0) choice--;
			else choice = 3;
		}
		else if (c == KEY_DOWN)
		{
			if (choice < 3) choice++;
			else choice = 0;
		}
		else if (c == ENTER)
		{
			return (Specialization)choice;
		}
	}
}

void inputDoctorData(Doctor& d, int id)
{

	delete[] d.name;
	delete[] d.surname;
	delete[] d.email;

	d.id = id;

	d.name = new char[15];
	d.surname = new char[30];
	d.email = new char[30];


	cin.ignore();
	cout << "Enter Name: ";
	cin.getline(d.name, 15);

	cout << "Enter Surname: ";
	cin.getline(d.surname, 30);

	d.specialization = selectSpecializationWithArrows();

	cout << "Enter Experience: ";
	cin >> d.experience;

	cout << "Enter Room number: ";
	cin >> d.roomNumber;

	cin.ignore();
	cout << "Enter Email: ";
	cin.getline(d.email, 30);
}
#pragma endregion

#pragma region File Operations
#include <fstream>

void saveDoctorsToFile(Doctor* doctors, size_t size)
{
	json j;

	for (size_t i = 0; i < size; i++)
	{
		j.push_back({
			{"id", doctors[i].id},
			{"name", doctors[i].name},
			{"surname", doctors[i].surname},
			{"specialization", doctors[i].specialization},
			{"experience", doctors[i].experience},
			{"roomNumber", doctors[i].roomNumber},
			{"email", doctors[i].email}
			});
	}

	ofstream file("doctors.json");

	if (!file.is_open())
	{
		cout << "File open error!" << endl;
		return;
	}

	file << j.dump(4);
}

void loadDoctorsFromFile(Doctor*& doctors, size_t& size)
{
	ifstream file("doctors.json");

	if (!file.is_open())
	{
		cout << "File open error!" << endl;
		return;
	}

	json j;
	file >> j;

	size = j.size();
	doctors = new Doctor[size];

	for (size_t i = 0; i < size; i++)
	{
		doctors[i].id = j[i]["id"];

		doctors[i].name = copyStr(j[i]["name"].get<string>().c_str());
		doctors[i].surname = copyStr(j[i]["surname"].get<string>().c_str());
		doctors[i].email = copyStr(j[i]["email"].get<string>().c_str());

		doctors[i].specialization = (Specialization)j[i]["specialization"];
		doctors[i].experience = j[i]["experience"];
		doctors[i].roomNumber = j[i]["roomNumber"];
	}
}
#pragma endregion
