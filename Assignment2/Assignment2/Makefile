CC = g++
CFLAGS = 
OBJECT1 = test_shellsort.o shellsort.o
OBJECT2 = test_shellsort_comp.o shellsort.o
OBJECT3 = test_shellsort_sedgewick.o shellsort.o
OBJECT4 = test_sort_comp.o shellsort.o mergesort.o quicksort.o
OBJECT5 = test_countingsort.o countingsort.o
OBJECT6 = BST_word_count.o BST.o
OBJECT7 = BST_word_count_test.o BST.o
OBJECT8 = Hash_word_count_test.o Hash.o
OBJECT9 = token_generator.o
OBJECT10 = Hash_BST_comp.o Hash.o BST.o
OBJECT11 = heap_sort.o Heap.o
OBJECT12 = test_Hash.o Hash.o
OBJECT13 = test_BST.o BST.o

all : test_shellsort test_shellsort_comp test_shellsort_sedgewick test_sort_comp test_countingsort BST_word_count BST_word_count_test Hash_word_count_test token_generator Hash_BST_comp heap_sort test_Hash test_BST

test_shellsort : $(OBJECT1)
	$(CC) -o test_shellsort $(OBJECT1) $(CFLAGS)

test_shellsort_comp : $(OBJECT2)
	$(CC) -o test_shellsort_comp $(OBJECT2) $(CFLAGS)

test_shellsort_sedgewick : $(OBJECT3)
	$(CC) -o test_shellsort_sedgewick $(OBJECT3) $(CFLAGS)

test_sort_comp : $(OBJECT4)
	$(CC) -o test_sort_comp $(OBJECT4) $(CFLAGS)

test_countingsort : $(OBJECT5)
	$(CC) -o test_countingsort $(OBJECT5) $(CFLAGS)

BST_word_count : $(OBJECT6)
	$(CC) -o BST_word_count $(OBJECT6) $(CFLAGS)

BST_word_count_test : $(OBJECT7)
	$(CC) -o BST_word_count_test $(OBJECT7) $(CFLAGS)

Hash_word_count_test : $(OBJECT8)
	$(CC) -o Hash_word_count_test $(OBJECT8) $(CFLAGS)

token_generator : $(OBJECT9)
	$(CC) -o token_generator $(OBJECT9) $(CFLAGS)

Hash_BST_comp : $(OBJECT10)
	$(CC) -o Hash_BST_comp $(OBJECT10) $(CFLAGS)

heap_sort : $(OBJECT11)
	$(CC) -o heap_sort $(OBJECT11) $(CFLAGS)

test_Hash : $(OBJECT12)
	$(CC) -o test_Hash $(OBJECT12) $(CFLAGS)

test_BST : $(OBJECT13)
	$(CC) -o test_BST $(OBJECT13) $(CFLAGS)