g++ -o ProgramName ProgramName.c `pkg-config opencv --cflags --libs` 
g++ -o cube *.o `pkg-config opencv --cflags --libs` -lglut
9
