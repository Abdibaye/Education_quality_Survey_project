#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Survey
{
    string Date;
    string Instructor_name;
    string course_name;
    string Department;
    string q_1;
    string q_2;
    string q_3;
    Survey* next;
};

Survey* head = nullptr;
stack<Survey*> survey_stack;

void Instruct_info()
{
    string I_name;
    cin.ignore();

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Instructor name: ";
        getline(cin, I_name);

        string c_name;
        cout << "Enter Course title: ";
        getline(cin, c_name);

        string Dep;
        cout << "Enter Department: ";
        getline(cin, Dep);

        cout << endl;

        Survey* new_Instructor = new Survey;
        new_Instructor->Instructor_name = I_name;
        new_Instructor->course_name = c_name;
        new_Instructor->Department = Dep;
        new_Instructor->next = nullptr;

        survey_stack.push(new_Instructor);

        if (head == nullptr)
        {
            head = new_Instructor;
        }
        else
        {
            Survey* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_Instructor;
        }
    }
}

void Display_Instructor_info()
{
    Survey* temp = head;
    while (temp != nullptr)
    {
        cout << "Instructor name: " << temp->Instructor_name << endl;
        cout << "Course title: " << temp->course_name << endl;
        cout << "Department: " << temp->Department << endl;
        cout << endl;
        temp = temp->next;
    }
}

void survey_question(Survey* instructor)
{
    cout << "Survey Questions for " << instructor->Instructor_name << endl;
    cout << "Clarity of presentation: ";
    getline(cin, instructor->q_1);
    cout << "Interaction opportunities during the lecture: ";
    getline(cin, instructor->q_2);
    cout << "Overall effectiveness of the lecture in aiding your understanding of the subject: ";
    getline(cin, instructor->q_3);
    cout << endl;
}

int main()
{
    string date;

    cout << "EDUCATION QUALITY SURVEY" << endl;
    cout << "First, you have to fill in information for all of your instructors of this semester." << endl;
    cout << "Enter date: ";
    getline(cin, date);
    Instruct_info();
    cout << "Well Done!" << endl;
    cout << endl;
    cout << "You have entered information for the following lectures: " << endl;
    Display_Instructor_info();

    cout << "Please provide survey responses for each lecture: " << endl;
    Survey* temp = head;
    while (temp != nullptr)
    {
        survey_question(temp);
        temp = temp->next;
    }

    return 0;
}