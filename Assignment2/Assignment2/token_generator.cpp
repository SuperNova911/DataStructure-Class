#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main()
{
	const int N = 100000;
	const int W = 20;

	const char *tableName = "word_length_stat.txt";
	const char *outputName = "tokens.txt";

	FILE *file;
	file = fopen(tableName, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", tableName);
		return 0;
	}

	int size = 0;
	int length;
	double ratio;
	char *word;
	char buffer[128];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		word = strtok(buffer, " ");
		length = atoi(word);
		if (length > W)
		{
			break;
		}

		if (word == NULL)
		{
			cout << "Invaild table format" << endl;
			return 0;
		}
		else
		{
			word = strtok(NULL, " ");
			ratio = atof(word);
			size += (int)(ratio * 1000);
		}
	}
	fclose(file);

	int *table = (int *)malloc(sizeof(int) * size);

	int tableIndex = 0;
	file = fopen(tableName, "r");
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		word = strtok(buffer, " ");
		length = atoi(word);

		if (word == NULL)
		{
			cout << "Invaild table format" << endl;
			return 0;
		}
		else
		{
			word = strtok(NULL, " ");
			ratio = atof(word) * 1000;

			while (ratio > 0)
			{
				table[tableIndex] = length;
				tableIndex++;
				ratio -= 1;
			}
		}
	}
	fclose(file);
	
	srand((size_t)time(NULL));

	remove(outputName);
	file = fopen(outputName, "w");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", outputName);
		return 0;
	}
	unsigned int randomValue;
	for (int index = 0; index < N; index++)
	{
		randomValue = ((rand() << 15) | rand());
		randomValue %= size;

		memset(buffer, 0, sizeof(buffer));
		for (int charIndex = 0; charIndex < table[randomValue]; charIndex++)
		{
			buffer[charIndex] = (rand() % ('z' - 'a' + 1)) + 'a';
		}
		strcat(buffer, "\n");
		fputs(buffer, file);
	}
	fclose(file);

	printf("입력파일 '%s'에 대한 랜덤 token 생성 결과가 '%s'에 저장되었습니다\n", tableName, outputName);

	free(table);
	return 0;
}