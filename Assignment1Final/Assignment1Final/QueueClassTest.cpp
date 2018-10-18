#include "GenericQueueDL.h"

using namespace std;

int main()
{
	// #### QueueClass<int> ####
	QueueClass<int> queue_int = QueueClass<int>();				// 생성자
	QueueClass<int> queue_int2 = QueueClass<int>(queue_int);	// 비어있는 큐 복사
	// queue_int: { }, queue_int2: { }

	queue_int.Add(1);
	queue_int.Add(2);
	queue_int.Add(3);
	queue_int.Add(4);
	// queue_int: { 1, 2, 3, 4 }

	QueueClass<int> queue_int3 = QueueClass<int>(queue_int);	// 값이 들어있는 큐 복사
	// queue_int: { 1, 2, 3, 4 }

	int data_int = 0;
	queue_int.GetFront(data_int);	// data_int: 1
	queue_int.Remove();				// Remove
	queue_int.GetFront(data_int);	// data_int: 2
	queue_int.Remove();				// Remove
	queue_int.GetFront(data_int);	// data_int: 3
	queue_int.Remove();				// Remove
	// queue_int: { 4 }

	bool isEmpty = false;
	isEmpty = queue_int.IsEmpty();		// queue_int: { 4 }				isEmpty: False
	isEmpty = queue_int2.IsEmpty();		// queue_int2: { }				isEmpty: True
	isEmpty = queue_int3.IsEmpty();		// queue_int3: { 1, 2, 3, 4 }	isEmpty: False

	int queueSize = 0;
	queueSize = queue_int.GetSize();	// queue_int: { 4 }				queueSize: 1
	queueSize = queue_int2.GetSize();	// queue_int2: { }				queueSize: 0
	queueSize = queue_int3.GetSize();	// queue_int3: { 1, 2, 3, 4 }	queueSize: 4



	// #### QueueClass<double> ####
	QueueClass<double> queue_double = QueueClass<double>();					// 생성자
	QueueClass<double> queue_double2 = QueueClass<double>(queue_double);	// 비어있는 큐 복사
	// queue_double: { }, queue_double2: { }

	queue_double.Add(2.5);
	queue_double.Add(5.0);
	queue_double.Add(7.5);
	queue_double.Add(10.0);
	// queue_double: { 2.5, 5.0, 7.5, 10.0 }

	QueueClass<double> queue_double3 = QueueClass<double>(queue_double);	// 값이 들어있는 큐 복사
	// queue_double: { 2.5, 5.0, 7.5, 10.0 }

	double data_double = 0.0;
	queue_double.GetFront(data_double);		// data_double: 2.5
	queue_double.Remove();					// Remove
	queue_double.GetFront(data_double);		// data_double: 5.0
	queue_double.Remove();					// Remove
	queue_double.GetFront(data_double);		// data_double: 7.5
	queue_double.Remove();					// Remove
	// queue_double: { 10.0 }

	isEmpty = false;
	isEmpty = queue_double.IsEmpty();		// queue_double: { 10.0 }					isEmpty: False
	isEmpty = queue_double2.IsEmpty();		// queue_double2: { }						isEmpty: True
	isEmpty = queue_double3.IsEmpty();		// queue_double3: { 2.5, 5.0, 7.5, 10.0 }	isEmpty: False

	queueSize = 0;
	queueSize = queue_double.GetSize();		// queue_double: { 10.0 }					queueSize: 1
	queueSize = queue_double2.GetSize();	// queue_double2: { }						queueSize: 0
	queueSize = queue_double3.GetSize();	// queue_double3: { 2.5, 5.0, 7.5, 10.0 }	queueSize: 4



	// #### QueueClass<string> ####
	QueueClass<string> queue_string = QueueClass<string>();					// 생성자
	QueueClass<string> queue_string2 = QueueClass<string>(queue_string);	// 비어있는 큐 복사
	// queue_string: { }, queue_string2: { }

	queue_string.Add("Aa");
	queue_string.Add("Bb");
	queue_string.Add("Cc");
	queue_string.Add("Dd");
	// queue_string: { Aa, Bb, Cc, Dd }

	QueueClass<string> queue_string3 = QueueClass<string>(queue_string);	// 값이 들어있는 큐 복사
	// queue_string: { Aa, Bb, Cc, Dd }

	string data_string = "";
	queue_string.GetFront(data_string);		// data_string: Aa
	queue_string.Remove();					// Remove
	queue_string.GetFront(data_string);		// data_string: Bb
	queue_string.Remove();					// Remove
	queue_string.GetFront(data_string);		// data_string: Cc
	queue_string.Remove();					// Remove
	// queue_string: { Dd }

	isEmpty = false;
	isEmpty = queue_string.IsEmpty();		// queue_string: { Dd }					isEmpty: False
	isEmpty = queue_string2.IsEmpty();		// queue_string2: { }					isEmpty: True
	isEmpty = queue_string3.IsEmpty();		// queue_string3: { Aa, Bb, Cc, Dd }	isEmpty: False

	queueSize = 0;
	queueSize = queue_string.GetSize();		// queue_string: { Dd }					queueSize: 1
	queueSize = queue_string2.GetSize();	// queue_string2: { }					queueSize: 0
	queueSize = queue_string3.GetSize();	// queue_string3: { Aa, Bb, Cc, Dd }	queueSize: 4

	return 0;
}