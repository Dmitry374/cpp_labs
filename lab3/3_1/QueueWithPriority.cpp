#include "QueueWithPriority.h"
#include <string>

QueueWithPriority::QueueWithPriority() {
	//cout << "\n" << "Initialization" << endl;
}

QueueWithPriority:: ~QueueWithPriority() {
	//cout << "\n" << "Destroy" << endl;
};

queue_type queue_high_elements;
queue_type queue_normal_elements;
queue_type queue_low_elements;

queue_type sorted_queue;

ostream& operator<<(ostream& out, const QueueElement& element) {
	string element_priority;
	switch (element.priority) {
	case LOW: element_priority = "LOW";
		break;
	case NORMAL: element_priority = "NORMAL";
		break;
	case HIGH: element_priority = "HIGH";
		break;
	default: element_priority = "-";
	}
	out << element.name << " - " << element_priority;

	return out;
}

void QueueWithPriority::PutElementToQueue(const QueueElement& element) {
	queue_of_elements.push_back(element);
}

QueueElement QueueWithPriority::GetElementFromQueue() {
	QueueElement queue_element;

	if (!queue_of_elements.empty()) {
		queue_element = queue_of_elements[0];

		UpElementByPriority();

		return getQueueElement(queue_of_elements);
	}
	else {
		cout << "The queue is empty" << endl;
	}

	return queue_element;

}

QueueElement QueueWithPriority::getQueueElement(queue_type &priority_queue) {
	QueueElement element = priority_queue[0];
	priority_queue.pop_front();
	return element;
}

void QueueWithPriority::Accelerate() {
	for (int i = 0; i < queue_of_elements.size(); i++) {
		if (queue_of_elements[i].priority == LOW) {
			queue_of_elements[i].priority = HIGH;
		}
	}

	UpElementByPriority();
}

void QueueWithPriority::UpElementByPriority() {
	sorted_queue.clear();
	queue_high_elements.clear();
	queue_normal_elements.clear();
	queue_low_elements.clear();

	for (int i = 0; i < queue_of_elements.size(); i++) {
		switch (queue_of_elements[i].priority) {
		case HIGH:
			queue_high_elements.push_back(queue_of_elements[i]);
			break;
		case NORMAL:
			queue_normal_elements.push_back(queue_of_elements[i]);
			break;
		case LOW:
			queue_low_elements.push_back(queue_of_elements[i]);
			break;
		default:
			queue_low_elements.push_back(queue_of_elements[i]);
			break;
		}

	}

	sorted_queue.insert(sorted_queue.end(), queue_high_elements.begin(), queue_high_elements.end());
	sorted_queue.insert(sorted_queue.end(), queue_normal_elements.begin(), queue_normal_elements.end());
	sorted_queue.insert(sorted_queue.end(), queue_low_elements.begin(), queue_low_elements.end());

	queue_of_elements = sorted_queue;


}

void QueueWithPriority::print_queue() {
	if (!queue_of_elements.empty()) {
		for (int i = 0; i < queue_of_elements.size(); i++)
			cout << "(" << queue_of_elements[i] << ")" << "\n";
	}
	else {
		cout << "Queue is empty.";
	}
	cout << endl;
}

void QueueWithPriority::print_element(const QueueElement& element) {
	cout << element << endl;
}