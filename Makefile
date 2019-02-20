
leibniz_1: leibniz_1.c 
	gcc -o leibniz_1 leibniz_1.c -lm

leibniz_2: leibniz_2.c
	gcc -o leibniz_2 leibniz_2.c -lm -lpthread
	
leibniz_3: leibniz_3.c
	gcc -o leibniz_3 leibniz_3.c -lm
	