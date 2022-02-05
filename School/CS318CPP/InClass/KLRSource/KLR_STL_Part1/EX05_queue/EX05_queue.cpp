// queue Demo 
#include <iostream> 
#include <queue> 

using namespace std;

void displayQueue(queue <int> qp)
{
	queue <int> q = qp;
	while (!q.empty())
	{
		cout << ' ' << q.front();
		q.pop();
	}
	cout << '\n';
}

int main()
{
	queue <int> q;
	q.push(10);
	q.push(20);
	q.push(30);

	cout << "q: ";
	displayQueue(q);

	cout << "\nq.size(): " << q.size();
	cout << "\nq.front(): " << q.front();
	cout << "\nq.back(): " << q.back();

	cout << "\nAfter q.pop(): ";
	q.pop();
	displayQueue(q);

	return 0;
}
