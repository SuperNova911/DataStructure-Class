#include "Hash.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	// 크기가 10인 해시테이블 생성
	cout << "크기가 10인 해시테이블 생성" << endl;
	int hashTableSize = 10;
	Hash hash;
	hash.Create(hashTableSize);
	Nptr currentHash;
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	// 해시테이블에 값 삽입
	cout << "해시테이블에 값 삽입" << endl;
	hash.Insert("AAA");
	hash.Insert("AAA");
	hash.Insert("BBB");
	hash.Insert("CCC");
	hash.Insert("CCC");
	hash.Insert("CCC");
	hash.Insert("DDD");
	hash.Insert("EEE");
	hash.Insert("FFF");
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	// 해시테이블에서 값 검색하기
	cout << "해시테이블에서 값 검색하기" << endl;
	Nptr searchResult;
	searchResult = hash.Search("AAA");
	if (searchResult != NULL)
		printf("AAA search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "AAA not found" << endl;

	searchResult = hash.Search("CCC");
	if (searchResult != NULL)
		printf("CCC search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "CCC not found" << endl;

	searchResult = hash.Search("FFF");
	if (searchResult != NULL)
		printf("FFF search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "FFF not found" << endl;

	searchResult = hash.Search("XXX");
	if (searchResult != NULL)
		printf("XXX search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "XXX not found" << endl;
	cout << endl;

	// 해시테이블에 값 업데이트 하기
	cout << "해시테이블에 값 업데이트 하기 (AAA, BBB, GGG, BBB)" << endl;
	hash.Update("AAA");
	hash.Update("BBB");
	hash.Update("GGG");
	hash.Update("BBB");
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	// 해시테이블에서 값 삭제하기
	cout << "해시테이블에서 값 삭제하기 (AAA, BBB, FFF, XXX)" << endl;
	hash.Delete("AAA");
	hash.Delete("BBB");
	hash.Delete("FFF");
	hash.Delete("XXX");
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	const char *OUTPUT = "test_Hash.save";
	// 해시테이블 저장하기
	cout << "해시테이블 저장하기" << endl;
	hash.Save(OUTPUT);
	cout << endl;

	// 해시테이블 불러오기
	Hash newHash;
	newHash.Create(hashTableSize);
	cout << "해시테이블 불러오기 (새로운 해시테이블에 불러옴)" << endl;
	newHash.Open(OUTPUT);
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = newHash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	// Rehash
	cout << "해시테이블 Rehash하기" << endl;

	cout << "기존 해시테이블" << endl;
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	cout << "테이블 크기를 2로 Rehash한 새로운 해시테이블" << endl;
	int newTableSize = 2;
	hash.Rehash(newTableSize);
	for (int index = 0; index < newTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}
	cout << endl;

	cout << "테이블 크기를 7로 Rehash한 새로운 해시테이블" << endl;
	newTableSize = 7;
	hash.Rehash(newTableSize);
	for (int index = 0; index < newTableSize; index++)
	{
		currentHash = hash.table[index];
		while (currentHash != NULL)
		{
			printf("index: %d, count: %d, key: %s\n", index, currentHash->Data.count, currentHash->Data.Key.c_str());
			currentHash = currentHash->next;
		}
	}

	return 0;
}