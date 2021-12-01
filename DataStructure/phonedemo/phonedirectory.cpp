//
// Created by liaohui on 2021/11/30.
//

#include<iostream>
#include<string.h>
#define len 17
using namespace std;
typedef struct node //create node
{
    char name[8];//define array for name
    char address[20];//define array for address
    char tel[11];//define array for telephone num
    node* next;
}Person;
typedef struct Hash {
    Person* data;
    int count;
    int sizeindex;
}Hash;
bool makeH(Hash* table);
bool insetH(Hash* nametable, Hash* teltable, Person person);
bool searchnameH(Hash* nametable, char name[]);
bool searchtelH(Hash* teltable, char tel[]);
bool searchname(Person* head, char name[]);
bool searchtel(Person* head, char tel[]);
int getnamekey(char name[]) {
    return (name[0] + name[1]) % 17;
}
int gettelkey(char tel[]) {
    return((tel[10] - '0') * 10 + (tel[11] - '0')) % 17;
}
int main() {
    Hash nametable, teltable;
    makeH(&nametable);
    makeH(&teltable);
    Person *person, *head,*p;
    head = NULL;
    int i;
    char name[8], tel[11];
    do {
        cin >> i;
        switch (i) {
            case 0:person = new(Person);
                cin >> person->name >> person->address >> person->tel;
                person->next = NULL;
                insetH(&nametable, &teltable, *person);
                p = head;
                if (p) {
                    while (p->next) {
                        p = p->next;
                    }
                    p->next = person;
                }
                else {
                    head = person;
                }
                break;
            case 1:cin >> name;
                if (!searchname(head, name))
                    cout << "NULL";
                break;
            case 2:cin >> tel;
                if (!searchtel(head, tel))
                    cout << "NULL";
                break;
            case 3:cin >> name;
                if (!searchnameH(&nametable, name))
                    cout << "NULL";
                break;
            case 4:cin >> tel;
                if (!searchtelH(&teltable, tel))
                    cout << "NULL";
                break;
        }
    } while (i != 5);
    return 0;
    delete []nametable.data;
    delete[]teltable.data;
    delete person;
}
bool makeH(Hash* table) {
    table->data = new Person[len];
    if (table->data == NULL)
        return false;
    int i;
    Person* p;
    p = table->data;
    table->count = 0;
    table->sizeindex = len;
    for (i = 0; i < len; i++) {
        memset(p->name, '\0', sizeof(char));
        memset(p->tel, '\0', sizeof(char));
        p++;
    }
    return true;
}
bool insetH(Hash* nametable, Hash* teltable, Person person) {
    int namekey, nk2, telkey, tk2, c;
    Person* n, * t,*s;
    n = nametable->data;
    t = teltable->data;
    namekey = getnamekey(person.name);
    telkey = gettelkey(person.tel);
    c = 0;
    int l = strlen((n + namekey)->name);
    if (l == 0) {
        memcpy(n + namekey, &person, sizeof(person));
        nametable->count++;
        s = n + namekey;
    }
    else {
        nk2 = namekey;
        do {
            c++;
            nk2 = (nk2 + c) % len;
        } while (strlen((n + namekey)->name) != 0 && c < len);
        if (c >= len) {
            cout << "error" << endl;
            return false;
        }
        else {
            memcpy(n + nk2, &person, sizeof(person));
            nametable->count++;
        }
    }
    c = 0;
    l = 0;
    if (l == 0) {
        memcpy(t + telkey, &person, sizeof(person));
        teltable->count++;
    }
    else {
        tk2 = telkey;
        do {
            c++;
            tk2 = (tk2 + c) % len;
        } while (strlen((t + telkey)->tel) != 0 && c < len);
        if (c >= len) {
            cout << "error" << endl;
            return false;
        }
        else {
            memcpy(t + tk2, &person, sizeof(person));
            teltable->count++;
        }
    }
    return true;
}
bool searchnameH(Hash* nametable, char name[]) {
    int key, c;
    Person* p;
    key = getnamekey(name);
    p = nametable->data;
    if (strlen((p + key)->name) == 0)
        return false;
    else if (strcmp((p + key)->name , name)!=0) {
        c = 0;
        do {
            c++;
            key = key + c;
        } while (strcmp((p + key)->name, name) != 0 && c < len);
        if (c >= len)
            return false;
        else {
            cout << (p + key)->name << ' ' << (p + key)->address << ' ' << (p + key)->tel;
            return true;
        }
    }
    else {
        cout << (p + key)->name << ' ' << (p + key)->address << ' ' << (p + key)->tel;
        return true;
    }

}
bool searchtelH(Hash* teltable, char tel[]) {
    int key, c;
    Person* p;
    key = gettelkey(tel);
    p = teltable->data;
    if (strlen((p + key)->tel) == 0)
        return false;
    else if (strcmp((p + key)->tel , tel)!=0) {
        c = 0;
        do {
            c++;
            key = key + c;
        } while (strcmp((p + key)->tel, tel)!=0 && c < len);
        if (c >= len)
            return false;
        else {
            cout << (p + key)->name << ' ' << (p + key)->address << ' ' << (p + key)->tel;
            return true;
        }
    }
    else {
        cout << (p + key)->name << ' ' << (p + key)->address << ' ' << (p + key)->tel;
        return true;
    }
}
bool searchname(Person* head, char name[]) {
    Person* p;
    p = head;
    while (p != NULL && strcmp(p->name , name)!=0) {
        p = p->next;
    }
    if (p == NULL) {
        return false;
    }
    else {
        cout << p->name << ' ' << p->address << ' ' << p->tel;
        return true;
    }
}
bool searchtel(Person* head, char tel[]) {
    Person* p;
    p = head;
    while (p != NULL && strcmp(p->tel, tel) != 0) {
        p = p->next;
    }
    if (p == NULL) {
        return false;
    }
    else {
        cout << p->name << ' ' << p->address << ' ' << p->tel;
        return true;
    }
}
