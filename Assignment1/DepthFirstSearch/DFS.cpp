#include <iostream>
#include "GenericStack.h"

using namespace std;

int main()
{
	char fileName[] = "sample_graph.txt";
	FILE *stream;
	if (fopen_s(&stream, fileName, "r") != 0)
	{
		cout << "������ �� �� �����ϴ�. FileName: " << fileName << endl;
		return 0;
	}

	StackClass<int> stack = StackClass<int>();

	char *item, *context;
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stream) != NULL)
	{
		item = strtok_s(buffer, " ", &context);

		for (int index = 0; item != NULL; index++)
		{
			 stack.Push(atoi(item));
			item = strtok_s(context, " ", &context);
		}
	}



	return 0;
}