#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string name;
	string surname;
};
struct List
{
	Person person;
	List * next;
};
List * createList(Person person)
{
	List * list = new List;
	list->person = person;
	list->next = 0;
	return list;
}
void printList(List * list)
{
	cout<<list->person.name<<" "<<list->person.surname<<endl;
	if(list->next) printList(list->next);
}
void addListElement(List * list, Person person)
{
	if(!list->next)
	{
		List * new_list = createList(person);
		list->next = new_list;
	}
	else addListElement(list->next, person);
}

List * removeListElement(List * list, string surname, List * previous = 0)
{
    if(list->person.surname == surname)
    {
        if(previous)
        {
        delete previous->next;
        previous->next = list->next;
        }
        else
        {
            List * wsk = list->next;
            delete list;
            return list->next;
        }
    }
    else
    {
        if(list->next) removeListElement(list->next, surname, list);
        else cout<<"Nie ma takiego uzytkownika"<<endl;
    }
    return list;
}
void sort1(List * list)
{
    if((int)list->person.surname[0]>(int)list->next->person.surname[0]) swap(list->person, list->next->person);
    if(list->next->next) sort1(list->next);
}
void sortuj(List * list)
{
    if(list->next->next) sort1(list->next);
    sort1(list);
}
int main(int argc, char **argv)
{
	Person p = {"Jan", "Nowak"};
	Person p2 = {"Ktos", "Inny"};
	Person p3 = {"Jan", "Kowalski"};
	List * l = createList(p);
	addListElement(l, p2);
	addListElement(l, p3);
	printList(l);
	cout<<"=========="<<endl;
	cout<<"Po usunieciu:"<<endl;
	l = removeListElement(l, "Inny");
	printList(l);
	cout<<"=========="<<endl;
	cout<<"Po sortowaniu:"<<endl;
	sortuj(l);
	printList(l);
	return 0;
}

