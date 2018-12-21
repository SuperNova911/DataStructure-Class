CC = g++
CFLAGS = 
OBJECT1 = Trie_Hash_BST_comp.o Trie.o Hash.o BST.o
OBJECT2 = Trie_word_count.o Trie.o Hash.o BST.o
OBJECT3 = Trie_word_count_test.o Trie.o Hash.o BST.o
OBJECT4 = Trie_test.o Trie.o

all : Trie_Hash_BST_comp Trie_word_count Trie_word_count_test Trie_test

Trie_Hash_BST_comp : $(OBJECT1)
	$(CC) -o Trie_Hash_BST_comp $(OBJECT1) $(CFLAGS)

Trie_word_count : $(OBJECT2)
	$(CC) -o Trie_word_count $(OBJECT2) $(CFLAGS)

Trie_word_count_test : $(OBJECT3)
	$(CC) -o Trie_word_count_test $(OBJECT3) $(CFLAGS)

Trie_test : $(OBJECT4)
	$(CC) -o Trie_test $(OBJECT4) $(CFLAGS)