/*В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из 
трех уровней приоритета (low, normal, high)

Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, 
потом normal, потом low), элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления. 

В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся 
в момент акселерации в очереди увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal.
*/

#include <iostream>
#include "queuewithpriority.h"

using namespace std;

int main()
{

	QueueWithPriority priorities_queue = QueueWithPriority(); //Создание очереди

	QueueElement element_1 = { "Do homework", LOW };
	priorities_queue.PutElementToQueue(element_1);

	QueueElement element_2 = { "Training", HIGH };
	priorities_queue.PutElementToQueue(element_2);

	QueueElement element_3 = { "To eat", NORMAL };
	priorities_queue.PutElementToQueue(element_3);

	QueueElement element_4 = { "Meet friend", HIGH };
	priorities_queue.PutElementToQueue(element_4);

	QueueElement element_5 = { "Go to cinema", NORMAL };
	priorities_queue.PutElementToQueue(element_5);


	// Print queue elements
	cout << "\n" << "My priorities queue: " << endl << endl;
	priorities_queue.print_queue();

	// Getting elements by priority
	cout << "Elements by priority: " << endl;
	QueueElement queue_element_1 = priorities_queue.GetElementFromQueue();
	priorities_queue.print_element(queue_element_1);

	QueueElement queue_element_2 = priorities_queue.GetElementFromQueue();
	priorities_queue.print_element(queue_element_2);

	QueueElement queue_element_3 = priorities_queue.GetElementFromQueue();
	priorities_queue.print_element(queue_element_3);


	// Print queue elements
	cout << "\n" << "My queue before Accelerate: " << endl;
	priorities_queue.print_queue();

	// Accelerate
	priorities_queue.Accelerate();

	// Print queue elements
	cout << "\n" << "My queue after Accelerate: " << endl;
	priorities_queue.print_queue();


}
