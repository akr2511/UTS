//Akriz Alam Annaba_2310631170066_2F-Informatika

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Task {
    string name;
    string deadline;
    Task* next;
};

class TaskManager {
private:
    Task* head;

public:
    TaskManager() : head(nullptr) {}

    void addTask(const string& taskName, const string& deadline) {
        Task* newTask = new Task;
        newTask->name = taskName;
        newTask->deadline = deadline;
        newTask->next = nullptr;

        if (head == nullptr) {
            head = newTask;
        } else {
            Task* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newTask;
        }
        cout << "Tugas '" << taskName << "' dengan tenggat waktu '" << deadline << "' berhasil ditambahkan." << endl;
    }

    void removeTask(const string& taskName) {
        if (head == nullptr) {
            cout << "Tidak ada tugas yang tersedia." << endl;
            return;
        }

        Task* current = head;
        Task* prev = nullptr;

        while (current != nullptr) {
            if (current->name == taskName) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Tugas '" << taskName << "' berhasil dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Tugas '" << taskName << "' tidak ditemukan." << endl;
    }

    void displayTasks() {
        if (head == nullptr) {
            cout << "Tidak ada tugas yang tersedia." << endl;
            return;
        }

        Task* current = head;
        cout << "======================================================" << endl;
        cout << setw(30) << "Daftar Tugas" << endl;
        cout << "======================================================" << endl;
        cout << "| No |     Nama Tugas          |   Tenggat Waktu     |" << endl;
        cout << "======================================================" << endl;

        int count = 1;
        while (current != nullptr) {
            cout << "| " << setw(3) << count << " | " << setw(23) << current->name << " | " << setw(19) << current->deadline << " |" << endl;
            current = current->next;
            count++;
        }
        cout << "======================================================" << endl;
    }

    ~TaskManager() {
        Task* current = head;
        Task* nextTask;
        while (current != nullptr) {
            nextTask = current->next;
            delete current;
            current = nextTask;
        }
        head = nullptr;
    }
};

int main() {
    TaskManager taskManager;

    char choice;
    string taskName, deadline;

    do {
        cout << "\n======================================================" << endl;
        cout << "|          Aplikasi Pengelola Tugas                  |" << endl;
        cout << "======================================================" << endl;
        cout << "| Menu:                                              |" << endl;
        cout << "| 1. Tambah Tugas                                    |" << endl;
        cout << "| 2. Hapus Tugas                                     |" << endl;
        cout << "| 3. Tampilkan Semua Tugas                           |" << endl;
        cout << "| 4. Keluar                                          |" << endl;
        cout << "======================================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); // Menghapus karakter newline dari buffer

        switch (choice) {
            case '1':
                cout << "Masukkan nama tugas: ";
                getline(cin, taskName);
                cout << "Masukkan tenggat waktu tugas: ";
                getline(cin, deadline);
                taskManager.addTask(taskName, deadline);
                break;
            case '2':
                cout << "Masukkan nama tugas yang ingin dihapus: ";
                getline(cin, taskName);
                taskManager.removeTask(taskName);
                break;
            case '3':
                taskManager.displayTasks();
                break;
            case '4':
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }
    } while (choice != '4');

    return 0;
}
