#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    void searchByTitle(string title) {
        int index= -1 ;
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            if (books[i].title == title) {
                cout << "- " << books[i].title << " by " << books[i].author << endl;
            }
        }

    }
    void searchByAuthor(string author) {
        int index = -1;
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            if (books[i].author== author) {
                cout << "- " << books[i].title << " by " << books[i].author << endl;
            }
        }
    }
};

int main() {
    BookManager manager;
    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. Ư�� ���� �� å ���" << endl; // ���� å ��Ͽ� ������ ���� �� å ��� ���
        cout << "4. Ư�� ���� å ���" << endl; // ���� å ��Ͽ� ������ ���� å ��� ���
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string book_name;
            // 3�� ����: ���� ������ �˻�
            // ���������� ������ Ȯ���մϴ�.
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, book_name); // ���� �Է� (���� ����)
            manager.searchByTitle(book_name);
        }
        else if (choice == 4) {
            string Author;
            // 3�� ����: ���� ������ �˻�
            // ���������� ������ Ȯ���մϴ�.
            cout << "���� �̸�: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, Author); // ���� �Է� (���� ����)
            manager.searchByAuthor(Author);
        }
        else if (choice == 5) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
