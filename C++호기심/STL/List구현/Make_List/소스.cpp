#include <iostream>

using namespace std;

template<typename T>
struct List
{
    List<T>()
        :data(0), next(nullptr)
    {

    };
    List* next;
    T data;
};

typedef List<int> iList;

template<typename T>
void print(List<T>* head)
{
    List<T>* current = head;

    while (current != nullptr)
    {
        cout << current->data << "\n";
        current = current->next;
    }
}

template<typename T>
List<T>* reverse(List<T>* head)
{
    List<T>* current = head;
    List<T>* previous = nullptr;
    List<T>* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;   // ���� ��带 ����
        current->next = previous; // ���� ����� next�� ���� ���� ����
        previous = current;     // ���� ��带 ���� ���� ����
        current = next;         // ���� ��带 ���� ���� ����
    }

    return previous; // ���ο� head ��ȯ
};

int main()
{
    iList* list = new iList();
    iList* head = list;

    for (int i = 0; i < 5; i++)
    {
        list->data = i;
        if (i < 4) {
            list->next = new iList();
            list = list->next;
        }
    }

    cout << "Original list:" << endl;
    print<int>(head);

    head = reverse<int>(head);

    cout << "Reversed list:" << endl;
    print<int>(head);

    // �޸� ������ ���� ����Ʈ�� ������ ����
    while (head != nullptr)
    {
        iList* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}