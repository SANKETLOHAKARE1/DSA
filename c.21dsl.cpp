#include <iostream>
#include <process.h>
using namespace std;

class node {
public:
    int appointmentid;
    float starttime, endtime, min, max;
    node *next;
};

class ll {
    node *head;
public:
    ll() {
        head = NULL;
    }

    node* create() {
        int n;
        float st, ed, MAX, MIN;
        node *p, *q;

        cout << "\nCreate appointment linked list:";
        cin >> n;
        cout << "\nTime slot is 10.00 AM to 5.00 PM";
        for (int i = 0; i < n; ++i) {
            cout << "\nEnter your appointment id: ";
            cin >> st;
            cout << "\nEnter start time: ";
            cin >> st;
            cout << "\nEnter end time: ";
            cin >> ed;
            cout << "\nEnter max time: ";
            cin >> MAX;
            cout << "\nEnter min time: ";
            cin >> MIN;

            p = new node;
            p->starttime = st;
            p->endtime = ed;
            p->max = MAX;
            p->min = MIN;
            p->next = NULL;

            if (head == NULL) {
                head = p;
                q = p;
            } else {
                if (p->starttime != q->starttime) {
                    q->next = p;
                    q = p;
                } else {
                    cout << "Enter a different duration.";
                    delete p;
                }
            }
        }
        return head;
    }

    void display(node *head) {
        node *p = head;
        while (p != NULL) {
            cout << "\tStart time: " << p->starttime;
            cout << "\tEnd time: " << p->endtime;
            cout << "\tMax time: " << p->max;
            cout << "\tMin time: " << p->min << endl;
            p = p->next;
        }
    }

    void menu() {
        int ch;
        do {
            cout << "\nEnter option: 1.Create  2.Display  3.Exit: ";
            cin >> ch;

            switch (ch) {
                case 1:
                    head = create();
                    break;
                case 2:
                    display(head);
                    break;
                case 3:
                    exit(0);
            }
        } while (ch != 3);
    }
};

int main() {
    ll l1;
    l1.menu();
    return 0;
}

