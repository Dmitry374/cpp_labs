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

	// �����������, ������� ������ �������
	QueueWithPriority();

	// ����������
	~QueueWithPriority();

	// �������� � ������� ������� element � ����������� priority
	void PutElementToQueue(const QueueElement& element);

	// �������� ������� �� �������
	// ����� ������ ���������� ������� � ���������� �����������, ������� ���
	// �������� � ������� ������ ������
	QueueElement GetElementFromQueue();

	QueueElement getQueueElement(queue_type &priority_queue);

	// ��������� �����������
	void Accelerate();

	// ������ �������
	void print_queue();

	// ������ �������� �������
	void print_element(const QueueElement& element);

	// ������� ������� � ������ �� ����������
	void UpElementByPriority();

};

