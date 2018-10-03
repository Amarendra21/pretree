#include"treaded.h"
#include<conio.h>
int main()
{
	{
		BST b1;
		cout<< b1.insert(50)<<endl;
		cout<< b1.insert(20)<<endl;
		cout<< b1.insert(80)<<endl;
		cout<< b1.insert(60)<<endl;
		cout<< b1.insert(40)<<endl;
		b1.inOrder();
		b1.preOrder();
		_getch();
		return 0;
	}
}