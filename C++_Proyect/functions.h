#pragma 

int minExp, maxExp;
Specialization selectedSpec;

void addDoctor(Doctor*& doctors, size_t& size, const Doctor& newDoctor)
{
	cout << "OLD PTR: " << doctors[0].name << endl;
	Doctor* newArr = new Doctor[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = Doctor(
			doctors[i].id,
			copyStr(doctors[i].name),
			copyStr(doctors[i].surname),
			doctors[i].specialization,
			doctors[i].experience,
			doctors[i].roomNumber,
			copyStr(doctors[i].email)
		);
	}
	cout << "NEW PTR: " << newArr[0].name << endl;

	newArr[size] = Doctor(
		newDoctor.id,
		copyStr(newDoctor.name),
		copyStr(newDoctor.surname),
		newDoctor.specialization,
		newDoctor.experience,
		newDoctor.roomNumber,
		copyStr(newDoctor.email)
	);

	delete[] doctors;
	doctors = newArr;
	size++;
}


int idCheck(Doctor* doctors, int id, size_t doctorSize)
{
	for (size_t i = 0; i < doctorSize; i++)
		if (doctors[i].id == id)
			return i;

	return -1;
}

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

void updateDoctor(int id, const Doctor& newDoctor, Doctor* doctors, size_t doctorSize, int check)
{
	delete[] doctors[check].name;
	delete[] doctors[check].surname;
	delete[] doctors[check].email;

	doctors[check].id = newDoctor.id;
	doctors[check].name = copyStr(newDoctor.name);
	doctors[check].surname = copyStr(newDoctor.surname);
	doctors[check].specialization = newDoctor.specialization;
	doctors[check].experience = newDoctor.experience;
	doctors[check].roomNumber = newDoctor.roomNumber;
	doctors[check].email = copyStr(newDoctor.email);

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
			newArr[j++] = Doctor(
				doctors[i].id,
				copyStr(doctors[i].name),
				copyStr(doctors[i].surname),
				doctors[i].specialization,
				doctors[i].experience,
				doctors[i].roomNumber,
				copyStr(doctors[i].email)
			);
		}
	}

	delete[] doctors;
	doctors = newArr;
	size--;

	cout << "Doctor deleted successfully" << endl;
}

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


void inputDoctorData(Doctor& d, int id)
{
	d.id = id;

	d.name = new char[15];
	d.surname = new char[30];
	d.email = new char[30];

	int specChoice;

	cin.ignore();
	cout << "Enter Name: ";
	cin.getline(d.name, 15);

	cout << "Enter Surname: ";
	cin.getline(d.surname, 30);

	cout << "Select Specialization:\n";
	cout << "0 - Therapist\n1 - Surgeon\n2 - Cardiologist\n3 - Dentist\n";
	cin >> specChoice;

	d.specialization = (Specialization)specChoice;

	cout << "Enter Experience: ";
	cin >> d.experience;

	cout << "Enter Room number: ";
	cin >> d.roomNumber;

	cin.ignore();
	cout << "Enter Email: ";
	cin.getline(d.email, 30);
}

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