#include "Item.h"
#include <iostream>
using namespace std;

Item::Item()
{
	itemid = 0;
	title = "";
	developer = "";
	released = 0;
	qty = 0;
	price = 0.0;
}

void Item::details(int itemid)
{
	int id = 0;
	cout << "What item id do you select?" << endl;
	cin >> id;
	if (id == itemid)
	{
		return;
	}
}

int Item::quantity(int itemid)
{
	int id = 0;
	cout << "What item do you select?" << endl;
	cin >> id;
	if (id == itemid)
	{
		return qty;
	}
}

void Item::update(int Itemid)
{
	string new_title = "";
	string new_developer = "";
	int new_release = 0;
	int new_qty = 0;
	float new_price = 0.0;

	int id = 0;

	cout << "What item would you like to update (Provide itemid): " << endl;
	cin >> id;

	if (id == itemid)
	{
		cout << "Enter new title " << endl;
		cin >> new_title;
		title = new_title;

		cout << "Enter new developer " << endl;
		cin >> new_developer;
		developer = new_developer;

		cout << "Enter new release date " << endl;
		cin >> new_release;
		released = new_release;

		cout << "Enter new price " << endl;
		cin >> new_price;
		price = new_price;
	}
	return;
}