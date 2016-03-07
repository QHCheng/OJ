#include <iostream>
#include <stdlib.h>

using namespace std;

struct monkey{
	int ID;
	monkey * next;
};

int main()
{
	int n,m;
	monkey * header, * newMonkey, * p, * pre;

	cin >> n >> m;
	if (m <= 0|| m > 300)
	{
		exit(-1);
	}

	//build a circle of monkeys
	p = header = new monkey;
	header->ID = 1;
	header->next = header;
	//add new monkey after p
	for (int i = 2; i <= n; ++i)
	{
		newMonkey = new monkey;
		newMonkey->ID = i;
		newMonkey->next = header;
		p->next = newMonkey;
		p = p->next;
	}

	//elect the boss of monkeys
	pre = p;
	p = header;
	while(p!=pre){
		for (int i = 1; i <= m-1; ++i)
		{
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		p->next = NULL;
		delete p;
		p = pre->next;
	}

	cout << p->ID <<endl;
	// cout<<n<<endl;
	// cout<<m<<endl;
	return 0;
}