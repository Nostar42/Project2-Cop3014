#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
	public:
		string name;
		double HW[5] = {-1.0,-1.0,-1.0,-1.0,-1.0};
		double Quiz[5] = {-1.0,-1.0,-1.0,-1.0,-1.0};
		double Exam[5] = {-1.0,-1.0,-1.0,-1.0,-1.0};
		Student();
		~Student();
};

Student::Student(){
	cout << "Please Enter Students Name Here (<unnamed> if no student): " << endl;
	cin >> name;
	cout << name << " was successfully added to the gradebook!" << endl;
}

Student::~Student(){
}


int MainMenu();
void addStudent();
void deleteStudent();
void changeGrade();
void gradeWeights();
void changeBook();
void displayAverage();
void report();

const int ClassSize = 5;
Student StudentList[ClassSize];
double HWweight = 0.2;
double Quizweight = 0.3;
double Examweight = 0.5;
string Gradebookname = "<noname>";

int main(){
	MainMenu();
	return 0;
}


int MainMenu(){
	int i = 0;
	cout << endl << "-=| MAIN MENU |=-" << endl;
	cout << "1. Add a student" << endl;
	cout << "2. Remove a student" << endl;
	cout << "3. Change a student's grade" << endl;
	cout << "4. Change group weights" << endl;
	cout << "5. Change the gradebook name" << endl;
	cout << "6. Display class average" << endl;
	cout << "7. Display full report" << endl;
	cout << "0. QUIT" << endl;
	cout << "Enter an action :";
	cin >> i;
	cout << endl << endl;
	switch(i){
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			changeGrade();
			break;
		case 4:
			gradeWeights();
			break;
		case 5:
			changeBook();
			break;
		case 6:
			displayAverage();
			break;
		case 7:
			report();
			break;
		default:
			return 0;
	}
	return i;
}

void addStudent(){
	cout << "-=| Adding Student |=-" << endl;
	cout << " Enter Student Name: ";
	string temp;
	cin >> temp;
	int i=0;
	int j=0;
	while(i != 1){
		if(StudentList[j].name == "<unnamed>"){
			StudentList[j].name = temp;
			i++;
		}
		else{
			j++;
			if(j==5){
				cout << "Could not add " << temp << ", Class is full!" << endl;
				break;
			}			
		}
	}
	MainMenu();
}
void deleteStudent(){
	cout << endl << "-=| Removing Student |=-" << endl;
	for(int i = 0; i < ClassSize; i++){
		if(StudentList[i].name != "<unnamed>"){
			cout << i+1 << ". " << StudentList[i].name << endl;
		}
	}
	if(StudentList[0].name == "<unnamed>" & StudentList[1].name == "<unnamed>" & StudentList[2].name == "<unnamed>" & StudentList[3].name == "<unnamed>" & StudentList[4].name == "<unnamed>"){
		cout << " No students in the class!" << endl;
	}
	else{
		cout << "Enter student to remove: ";
	
		int j;
		string temp;
		cin >> j;
		temp = StudentList[j-1].name;
		cout << temp << " was removed from the class!" << endl;
		StudentList[j-1].name = "<unnamed>";
		for (j; j < ClassSize; j++){
			string temp = "<unnamed>";
			double temp1 = -1;
			
			StudentList[j-1].name = StudentList[j].name;
			StudentList[j].name = temp;	
			
			StudentList[j-1].HW[j-1] = StudentList[j].HW[j];
			StudentList[j].HW[j] = temp1;
			
			StudentList[j-1].Quiz[j-1] = StudentList[j].Quiz[j];
			StudentList[j].Quiz[j] = temp1;
			
			StudentList[j-1].Exam[j-1] = StudentList[j].Exam[j];
			StudentList[j].Exam[j] = temp1;
		}
	}
	
	MainMenu();	
}

void changeGrade(){
	if(StudentList[0].name == "<unnamed>" & StudentList[1].name == "<unnamed>" & StudentList[2].name == "<unnamed>" & StudentList[3].name == "<unnamed>" & StudentList[4].name == "<unnamed>"){
		cout << " No students in the class!" << endl;
		MainMenu();
	}
	else{
	cout << endl << "-=| CHANGING GRADE |=-" << endl;
	cout << "1. Change a homework grade" << endl;
	cout << "2. Change a quiz grade" << endl;
	cout << "3. Change an exam grade" << endl;
	cout << "What grade would you like to change:";
	int i;
	cin >> i;
	cout << endl;
	

	for(int j = 0; j < ClassSize; j++){
		if(StudentList[j].name != "<unnamed>"){
			cout << j+1 << ". " << StudentList[j].name << endl;
		}
	}
	cout << endl << "Which student's grade would you like to change:";
	int k;
	cin >> k;
	cout << endl;
	
	double grade;
	int p;
	int z;
	int y;
	switch(i){
		
		case 1:
			for(z = 0; z < 5; z++){
				if(StudentList[k-1].HW[z] == -1){
					cout << z+1 <<". <ungraded>" << endl;
				}
				else{
					cout << z+1 << ". " << StudentList[k-1].HW[z] << endl;
				}
			}
			cout << "What grade would you like to update:";
			cin >> p;
			y=0;
			while(y != 1){
			cout << endl << "Enter Grade (-1 for ungraded): ";
			cin >> grade;
			if(grade > 100 || grade < -1){
				continue;
			}
			else{
				y++;
			}
			}
			StudentList[k-1].HW[p-1] = grade;
			cout << StudentList[k-1].name << " homework grade " << i << " was changed to " << StudentList[k-1].HW[p-1] << endl;
		break;
		
		case 2:
			for(z = 0; z < 5; z++){
				if(StudentList[k-1].Quiz[z] == -1){
					cout << z+1 << ". <ungraded>" << endl;
				}
				else{
					cout << z+1 << ". " << StudentList[k-1].Quiz[z] << endl;
				}
			}
			cout << "What grade would you like to update:";
			cin >> p;
			y=0;
			while(y != 1){
			cout << endl << "Enter Grade (-1 for ungraded): ";
			cin >> grade;
			if(grade > 100 || grade < -1){
				continue;
			}
			else{
				y++;
			}
			}
			
			StudentList[k-1].Quiz[p-1] = grade;
			cout << StudentList[k-1].name << " quiz grade " << i << " was changed to " << StudentList[k-1].Quiz[p-1] << endl; 
		break;
		
		case 3:
			for(z = 0; z < 5; z++){
			if(StudentList[k-1].Exam[z] == -1){
				cout << z+1 << ". <ungraded>" << endl;
			}
			else{
					cout << z+1 << ". " << StudentList[k-1].Exam[z] << endl;
				}
			}
			cout << "What grade would you like to update:";
			cin >> p;
			y=0;
			while(y != 1){
			cout << endl << "Enter Grade (-1 for ungraded): ";
			cin >> grade;
			if(grade > 100 || grade < -1){
				continue;
			}
			else{
				y++;
			}
			}
			
			StudentList[k-1].Exam[p-1] = grade;
			cout << StudentList[k-1].name << " exam grade " << p << " was changed to " << StudentList[k-1].Exam[p-1] << endl;
		break;
		
		default:
			MainMenu();
	}
	MainMenu();
	}
}

void gradeWeights(){
	cout << endl << "-=| Enter Weights |=-" << endl <<"(must add up to 1)";
	int i = 0;
	while(i != 1){
	cout << endl << "Enter homework weight:";
	cin >> HWweight;
	cout << endl << "Enter quiz weight:";
	cin >> Quizweight;
	cout << endl << "Enter Exam weight:";
	cin >> Examweight;
	if(HWweight+Quizweight+Examweight == 1){
		i++;
	}
	else{
		cout << endl << "Invalid inputs, try again" << endl;
	}
	}
	MainMenu();
}

void changeBook(){
	cout << endl << "-=| Change gradebook name |=-" << endl;
	cout << "please enter new name for gradebook: ";
	string temp = Gradebookname;
	cin >> Gradebookname;
	cout << endl << "Changed gradebook name from " << temp << " to " << Gradebookname;
	
	MainMenu();
}

void displayAverage(){
	cout << "-=| Class Averages |=-" << endl;
	double HWAverage,QuizAverage,ExamAverage;
	double x = 0;
	double y = 0;
	double z = 0;
	
	for(int i = 0; i < ClassSize; i++){
		for(int j = 0; j < 5; j++){
			if(StudentList[i].HW[j] >= 0){
				HWAverage = (StudentList[i].HW[j] + HWAverage);
				x++;
			}
		}
		for(int j = 0; j < 5; j++){
			if(StudentList[i].Quiz[j] >= 0){
				QuizAverage = (StudentList[i].Quiz[j] + QuizAverage);
				y++;
			}
		}
		for(int j = 0; j < 5; j++){
			if(StudentList[i].Exam[j] >= 0){
				ExamAverage = (StudentList[i].Exam[j] + ExamAverage);
				z++;
			}
		}
	}
	
	HWAverage= (HWAverage/x);
	QuizAverage = (QuizAverage/y);
	ExamAverage = (ExamAverage/z);
	cout << endl << "The Homework Average is: " << HWAverage << "%" << endl;
	cout << "The Quiz Average is: " << QuizAverage << "%" << endl;
	cout << "The Exam Average is: " << ExamAverage << "%" << endl;
	
	MainMenu();
	
}
 void report(){
 	cout << endl << "-=| Gradebook Report |=-" << endl;
 	cout << "Course: "  << Gradebookname << endl << endl;
 	
 	
 	cout << endl << "Student| Homework (" << HWweight*100 << "%)| Quizzes (" << Quizweight*100 << "%)| Exams (" << Examweight*100 << "%)| HW AVG| Quiz Avg| Exam Avg| Final Grade|" << endl;
 	if(StudentList[0].name != "<unnamed>"){
 		cout << endl << StudentList[0].name << endl;
			cout <<"HomeWork Grades|" << StudentList[0].HW[0] << " " << StudentList[0].HW[1] << " " << StudentList[0].HW[2] << " " << StudentList[0].HW[3] << " " << StudentList[0].HW[4] << " " << endl;
			cout <<"Quiz Grades|" << StudentList[0].Quiz[0] << " " << StudentList[0].Quiz[1] << " " << StudentList[0].Quiz[2] << " " << StudentList[0].Quiz[3] << " " << StudentList[0].Quiz[4] << " " << endl;
			cout <<"Exam Grades|" << StudentList[0].Exam[0] << " " << StudentList[0].Exam[1] << " " << StudentList[0].Exam[2] << " " << StudentList[0].Exam[3] << " " << StudentList[0].Exam[4] << " " << endl;
	}
	
	if(StudentList[1].name != "<unnamed>"){
		cout << endl << StudentList[1].name << endl;
			cout <<"HomeWork Grades|" << StudentList[1].HW[0] << " " << StudentList[1].HW[1] << " " << StudentList[1].HW[2] << " " << StudentList[1].HW[3] << " " << StudentList[1].HW[4] << " " << endl;
			cout <<"Quiz Grades|" << StudentList[1].Quiz[0] << " " << StudentList[1].Quiz[1] << " " << StudentList[1].Quiz[2] << " " << StudentList[1].Quiz[3] << " " << StudentList[1].Quiz[4] << " " << endl;
			cout <<"Exam Grades|" << StudentList[1].Exam[0] << " " << StudentList[1].Exam[1] << " " << StudentList[1].Exam[2] << " " << StudentList[1].Exam[3] << " " << StudentList[1].Exam[4] << " " << endl;
		}
		
	if(StudentList[2].name != "<unnamed>"){
		cout << endl << StudentList[2].name << endl;
			cout <<"HomeWork Grades|" << StudentList[2].HW[0] << " " << StudentList[2].HW[1] << " " << StudentList[2].HW[2] << " " << StudentList[2].HW[3] << " " << StudentList[2].HW[4] << " " << endl;
			cout <<"Quiz Grades|" << StudentList[2].Quiz[0] << " " << StudentList[2].Quiz[1] << " " << StudentList[2].Quiz[2] << " " << StudentList[2].Quiz[3] << " " << StudentList[2].Quiz[4] << " " << endl;
			cout <<"Exam Grades|" << StudentList[2].Exam[0] << " " << StudentList[2].Exam[1] << " " << StudentList[2].Exam[2] << " " << StudentList[2].Exam[3] << " " << StudentList[2].Exam[4] << " " << endl;
			}
			
	if(StudentList[3].name != "<unnamed>"){
		cout << endl << StudentList[3].name << endl;
			cout <<"HomeWork Grades|" << StudentList[3].HW[0] << " " << StudentList[3].HW[1] << " " << StudentList[3].HW[2] << " " << StudentList[3].HW[3] << " " << StudentList[3].HW[4] << " " << endl;
			cout <<"Quiz Grades|" << StudentList[3].Quiz[0] << " " << StudentList[3].Quiz[1] << " " << StudentList[3].Quiz[2] << " " << StudentList[3].Quiz[3] << " " << StudentList[3].Quiz[4] << " " << endl;
			cout <<"Exam Grades|" << StudentList[3].Exam[0] << " " << StudentList[3].Exam[1] << " " << StudentList[3].Exam[2] << " " << StudentList[3].Exam[3] << " " << StudentList[3].Exam[4] << " " << endl;
			}
			
	if(StudentList[4].name != "<unnamed>"){
		cout << endl << StudentList[4].name << endl;
			cout <<"HomeWork Grades|" << StudentList[4].HW[0] << " " << StudentList[4].HW[1] << " " << StudentList[4].HW[2] << " " << StudentList[4].HW[3] << " " << StudentList[4].HW[4] << " " <<  endl;
			cout <<"Quiz Grades|" << StudentList[4].Quiz[0] << " " << StudentList[4].Quiz[1] << " " << StudentList[4].Quiz[2] << " " << StudentList[4].Quiz[3] << " " << StudentList[4].Quiz[4] << " " << endl;
			cout <<"Exam Grades|" << StudentList[4].Exam[0] << " " << StudentList[4].Exam[1] << " " << StudentList[4].Exam[2] << " " << StudentList[4].Exam[3] << " " << StudentList[4].Exam[4] << " " << endl;
		}
 	
 	
	 
	 MainMenu();
 }



