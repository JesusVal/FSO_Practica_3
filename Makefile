
main: leibniz_1.c leibniz_2.c leibniz_3.c leibniz_4.c
	gcc -o leibniz_1 leibniz_1.c -lm
	gcc -o leibniz_2 leibniz_2.c -lm -lpthread
	gcc -o leibniz_3 leibniz_3.c -lm
	gcc -o leibniz_4 leibniz_4.c -lm

l1: leibniz_1.c 
	gcc -o leibniz_1 leibniz_1.c -lm

l2: leibniz_2.c
	gcc -o leibniz_2 leibniz_2.c -lm -lpthread
	
l3: leibniz_3.c
	gcc -o leibniz_3 leibniz_3.c -lm
	
l4: leibniz_4.c
	gcc -o leibniz_4 leibniz_4.c -lm
	