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
        next = current->next;   // 다음 노드를 저장
        current->next = previous; // 현재 노드의 next를 이전 노드로 변경
        previous = current;     // 이전 노드를 현재 노드로 변경
        current = next;         // 현재 노드를 다음 노드로 변경
    }

    return previous; // 새로운 head 반환
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

    // 메모리 해제를 위해 리스트의 노드들을 삭제
    while (head != nullptr)
    {
        iList* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}