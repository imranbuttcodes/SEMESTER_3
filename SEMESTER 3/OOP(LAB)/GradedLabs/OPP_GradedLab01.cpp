#include<iostream>
using namespace std;

void regrowChar(char*& arr, int& size, char input) {
	char* new_arr = new char[size + 1];
	for (int i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[size] = input;
	size++;
	delete[] arr;
	arr = new_arr;
}
double calculateAverage(double total, int subjects = 3) {
	return total / subjects;
}
void regrowInt(int*& arr, int& size, int input) {
	int* new_arr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[size] = input;
	size++;
	delete[] arr;
	arr = new_arr;
}


void regrowDouble(double*& arr, int& size, double input) {
	double* new_arr = new double[size + 1];
	for (int i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[size] = input;
	size++;
	delete[] arr;
	arr = new_arr;
}
double* allocateMarks(int n) {
	double* marks = new double[n];
	return marks;
}
void releaseMemory(double*& ptr) {
	delete[] ptr;
	ptr = nullptr;
}
void releaseMemory(char*& ptr) {
	delete[] ptr;
	
}
void applyBonus(double& mark, double bonus) {
	mark += bonus;
}
class Student {
private:
	char name[50]; 
	double* marks;
	int numSubjects = 0;
public:
	void setName(const char* n) {
		int j = 0;
		for (int i = 0; n[i] != '\0'; i++) {
			name[i] = n[i];
			j++;
		}
		name[j] = '\0';
	}
	const char* getName() {
		return name;
	}
	void setMarks(double* m, int n) {
		for (int i = 0; i < n; i++) {
			regrowDouble(marks, numSubjects, m[i]);
		}
	}
	
		void showMarks() {
			for (int i = 0; i < numSubjects; i++) {
				cout << marks[i] << " ";
			}
			cout << endl;
		}
		double* getMarks() {
			return marks;
		}
		int getNumSubjects() {
			return numSubjects;
		}
		void re_releaseMemory() {
			delete[] marks;
		}
		void set_marks_again(double* m) {
		marks = m;
		}
	
};

int main() {
	Student s1;
	char* name = nullptr;
	int name_size = 0;
	cout << "Enter Student Name: ";
	char garbage;
	while (true) {
		cin.get(garbage);
		if (garbage == '\n') {
			break;
		}
		regrowChar(name, name_size, garbage);
	}
	cout << "Marks before bonus: ";
	double* marks = allocateMarks(3);
	marks[0] = 78.0;
	marks[1] = 82.0;
	marks[2] = 69.0;
	s1.setMarks(marks, 3);
	s1.showMarks();
	cout << "Applying 5-point bonus to all subjects..." << endl;
	applyBonus(marks[0], 5);
	applyBonus(marks[1], 5);
	applyBonus(marks[2], 5);
	s1.re_releaseMemory();
	cout << "Updated Marks: ";	
	
	
	s1.set_marks_again(marks);
	s1.showMarks();
	double total = marks[0] + marks[1] + marks[2];

	cout << "Average Marks: " << calculateAverage(total) << endl;
	releaseMemory(marks);
	releaseMemory(name);
	cout << "Memory realesed successfully!" << endl;
}
