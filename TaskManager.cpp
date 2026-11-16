#include <iostream>
#include <string>
using namespace std;

struct node {
    string data;
    node* next;
    node* prev;
};
    
class Memo {
	
    node* head;
    node* tail;
    int taskCount;
public:
    Memo() { 
	head = NULL; 
	tail = NULL; 
	taskCount = 0; 
	}

    void addTask(string desc) {
        node* new_N1 = new node{desc,NULL,tail};
        if (head == NULL) {
            head = new_N1;
        } 
		else {
            tail->next = new_N1;
        }
        tail = new_N1;
        taskCount++;
    }

    void deleteTask(int taskNumber) {
        if (taskNumber < 1 || taskNumber > taskCount) {
            cout << "Invalid task number.\n";
            return;
        }
        node* current = head;
        for (int i = 1; i < taskNumber; i++) {
            current = current->next;
        }
        if (current->prev !=NULL) 
		    current->prev->next = current->next;
		    
        if (current->next !=NULL) 
		    current->next->prev = current->prev;
		    
        if (current == head) 
		    head = current->next;
		    
        if (current == tail) 
		    tail = current->prev;
		    
        delete current;
        taskCount--;
        cout << "Task deleted.\n";
    }

    void displayTasks() {
        node* current = head;
        int count = 1;
        if (current==NULL) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "Tasks: \n";
        while (current!=NULL) {
            cout << count++ << ". " << current->data << endl;
            current = current->next;
        }
    }

    void reverseDisplay() {
        node* current = tail;
        int count = taskCount;
        if (current==NULL) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "Tasks in reverse: \n";
        while (current !=NULL) {
            cout << count-- << ". " << current->data << endl;
            current = current->prev;
        }
    }

    ~Memo() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void clearScreen() {
    system("CLS");  // ·„”Õ «·‘«‘… ›Ì Windows
}
};

//class TaskQueue {
//
//    Memo memo;
//    
//public:
//    void enqueueTask(const string& desc) {
//        memo.addTask(desc);
//    }
//
//    void dequeueTask() {
//        if (!isEmpty()) {
//            memo.deleteTask(1);
//        } else {
//            cout << "Queue is empty.\n";
//        }
//    }
//
//    void displayQueue() {
//        memo.displayTasks();
//    }
//
//    bool isEmpty() {
//        return isEmpty();
//    }
//};

int main() {
    Memo memo;
    int choice;
    string taskDesc;
    int taskNumber;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a task\n";
        cout << "2. Delete a task\n";
        cout << "3. Display tasks\n";
        cout << "4. Display tasks in reverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        memo.clearScreen();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                memo.addTask(taskDesc);
                break;
            case 2:
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                memo.deleteTask(taskNumber);
                break;
            case 3:
                memo.displayTasks();
                break;
            case 4:
                memo.reverseDisplay();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

