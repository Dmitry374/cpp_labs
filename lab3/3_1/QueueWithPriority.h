#include <iostream>
#include <deque>
using namespace std;

enum ElementPriority {
	LOW,
	NORMAL,
	HIGH
};

struct QueueElement {
	string name;
	ElementPriority priority;
};

typedef deque<QueueElement> queue_type;

class QueueWithPriority {

public:
	queue_type queue_of_elements;

	queue_type queue_high_elements;
	queue_type queue_normal_elements;
	queue_type queue_low_elements;

	queue_type sorted_queue;

	// Конструктор, создает пустую очередь
	QueueWithPriority();

	// Деструктор
	~QueueWithPriority();

	// Добавить в очередь элемент element с приоритетом priority
	void PutElementToQueue(const QueueElement& element);

	// Получить элемент из очереди
	// метод должен возвращать элемент с наибольшим приоритетом, который был
	// добавлен в очередь раньше других
	QueueElement GetElementFromQueue();

	QueueElement getQueueElement(queue_type &priority_queue);

	// Выполнить акселерацию
	void Accelerate();

	// Печать очереди
	void print_queue();

	// Печать элемента очереди
	void print_element(const QueueElement& element);

	// Поднять элемент в списке по приоритету
	void UpElementByPriority();

};

